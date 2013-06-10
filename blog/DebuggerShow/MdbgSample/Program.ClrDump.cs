using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace MdbgSample
{
    partial class Program
    {
        [Flags]
        enum MINIDUMP_TYPE
        {
            MiniDumpNormal = 0x00000000,
            MiniDumpWithDataSegs = 0x00000001,
            MiniDumpWithFullMemory = 0x00000002,
            MiniDumpWithHandleData = 0x00000004,
            MiniDumpFilterMemory = 0x00000008,
            MiniDumpScanMemory = 0x00000010,
            MiniDumpWithUnloadedModules = 0x00000020,
            MiniDumpWithIndirectlyReferencedMemory = 0x00000040,
            MiniDumpFilterModulePaths = 0x00000080,
            MiniDumpWithProcessThreadData = 0x00000100,
            MiniDumpWithPrivateReadWriteMemory = 0x00000200,
            MiniDumpWithoutOptionalData = 0x00000400,
            MiniDumpWithFullMemoryInfo = 0x00000800,
            MiniDumpWithThreadInfo = 0x00001000,
            MiniDumpWithCodeSegs = 0x00002000,
            MiniDumpWithoutManagedState = 0x00004000,
        };

        [DllImport("clrdump.dll", CharSet = CharSet.Unicode, SetLastError = true)]
        private static extern Int32 CreateDump(Int32 ProcessId, string FileName, Int32 DumpType, Int32 ExcThreadId, IntPtr ExtPtrs);

        public static void MiniDump(string path, int pid)
        {
            CreateDump(pid, path, (Int32)MINIDUMP_TYPE.MiniDumpWithFullMemory, 0, IntPtr.Zero);
        }
    }
}
