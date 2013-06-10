using System;
using System.Collections.Generic;
using System.Diagnostics.SymbolStore;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using Microsoft.Samples.Debugging.CorDebug;
using Microsoft.Samples.Debugging.CorDebug.NativeApi;
using Microsoft.Samples.Debugging.CorMetadata.NativeApi;
using Microsoft.Samples.Debugging.MdbgEngine;

namespace MdbgSample
{
    partial class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Running with args: {0}", string.Join(", ", args));

            if (args.Length == 0)
            {
                //RunDebugger("ok");
                RunDebugger("user");
                //RunDebugger("zero");
                //RunDebugger("loop");
            }
            else
            {
                RunDebugee(args[0]);
            }
        }

        private static void RunDebugger(string args)
        {
            Console.WriteLine("Starting debugger for: {0}", args);
            var stop = new ManualResetEvent(false);

            var engine = new MDbgEngine();
            engine.Options.CreateProcessWithNewConsole = true;

            var process = engine.CreateProcess(
                null,
                string.Format("\"{0}\" {1}", Assembly.GetExecutingAssembly().Location, args),
                DebugModeFlag.Default, null);

            process.PostDebugEvent +=
                (sender, e) =>
                {
                    if (e.CallbackType == ManagedCallbackType.OnBreakpoint)
                    {
                        SetBreakPoint(process);

                        Console.WriteLine();
                        Console.WriteLine("--- Can I haz breakpoint? ---");
                        var ce = (CorBreakpointEventArgs)e.CallbackArgs;

                        DumpLocals(process.Threads.Lookup(ce.Thread).CurrentFrame);
                        process.Go();
                    }

                    if (e.CallbackType == ManagedCallbackType.OnException2)
                    {
                        Console.WriteLine();
                        Console.WriteLine("--- Oh noes, exception! ---");
                        var ce = (CorException2EventArgs)e.CallbackArgs;

                        if (ce.EventType == CorDebugExceptionCallbackType.DEBUG_EXCEPTION_FIRST_CHANCE)
                        {
                            //DumpThread(process.Threads.Lookup(ce.Thread));
                            MiniDump(Path.Combine(Directory.GetCurrentDirectory(), "minidump.dmp"), process.CorProcess.Id);
                        }
                    }

                    if (e.CallbackType == ManagedCallbackType.OnProcessExit)
                        stop.Set();
                };

            process.Go();
            stop.WaitOne();
        }

        private static void DumpLocals(MDbgFrame frame)
        {
            var locals = frame.Function.GetActiveLocalVars(frame);

            foreach (var local in locals)
                Console.WriteLine("\t" + DumpValue(local));
        }

        private static void DumpThread(MDbgThread thread)
        {
            foreach (var frame in thread.Frames)
            {
                if (!frame.IsManaged || frame.Function.FullName.StartsWith("System."))
                    break;

                Console.WriteLine("{0}({1})", frame.Function.FullName, DumpArguments(frame));
            }
        }

        private static string DumpArguments(MDbgFrame frame)
        {
            var arguments = frame.Function.GetArguments(frame);
            return string.Join(", ", arguments.Select(DumpValue));
        }

        private static string DumpValue(MDbgValue value)
        {
            return string.Format("{0} = {1}", value.Name, value.GetStringValue(false));
        }

        private static void SetBreakPoint(MDbgProcess process)
        {
            if (process.Breakpoints.Count == 0)
            {
                try
                {
                    var module = process.Modules.Lookup(Assembly.GetExecutingAssembly().Location);
                    var document = module.SymReader.GetDocuments().Single(d => Path.GetFileName(d.URL) == "Program.Debugee.cs");
                    var breakpoint = process.Breakpoints.CreateBreakpoint(document.URL, 77);

                }
                catch (Exception exception)
                {
                    Console.WriteLine(exception);
                }
            }
        }
    }
}
