using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using Microsoft.Samples.Debugging.CorDebug;
using Microsoft.Samples.Debugging.MdbgEngine;

namespace ConsoleApplication10
{
    class Program
    {
        static void Main(string[] args)
        {
            var stop = new ManualResetEvent(false);
            var engine = new MDbgEngine();
            var process = engine.CreateProcess(@"c:\users\marcin\documents\visual studio 2010\Projects\ConsoleApplication9\ConsoleApplication9\bin\Release\ConsoleApplication9.exe", "", DebugModeFlag.Default, null);
            process.Go();

process.PostDebugEvent +=
    (sender, e) =>
        {
            if (e.CallbackType == ManagedCallbackType.OnBreakpoint)
                process.Go();

            if (e.CallbackType == ManagedCallbackType.OnException2)
            {
                var e2 = (CorException2EventArgs)e.CallbackArgs;
                //Console.WriteLine(ClrDump.CreateDump(process.CorProcess.Id, @"E:\temp.dmp", (int)MINIDUMP_TYPE.MiniDumpWithFullMemory, 0, IntPtr.Zero));
            }

            if (e.CallbackType == ManagedCallbackType.OnProcessExit)
                stop.Set();
        };

            stop.WaitOne();
        }
    }
}
