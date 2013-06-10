using System;
using System.Diagnostics;
using System.IO;
using System.Runtime.InteropServices;
using System.Text;

namespace Intro
{
    partial class Program
    {
        // ReSharper disable InconsistentNaming
        private enum MsiInstallState
        {
            NOTUSED = -7,  // component disabled
            BADCONFIG = -6,  // configuration data corrupt
            INCOMPLETE = -5,  // installation suspended or in progress
            SOURCEABSENT = -4,  // run from source, source is unavailable
            MOREDATA = -3,  // return buffer overflow
            INVALIDARG = -2,  // invalid function argument
            UNKNOWN = -1,  // unrecognized product or feature
            BROKEN = 0,  // broken
            ADVERTISED = 1,  // advertised feature
            REMOVED = 1,  // component being removed (action state, not settable)
            ABSENT = 2,  // uninstalled (or action state absent but clients remain)
            LOCAL = 3,  // installed on local drive
            SOURCE = 4,  // run from source, CD or net
            DEFAULT = 5,  // use default, local or source
        }
        // ReSharper restore InconsistentNaming

        [DllImport("msi.dll", CharSet = CharSet.Auto)]
        extern static private MsiInstallState MsiLocateComponent(string szComponent, [MarshalAs(UnmanagedType.LPTStr)] StringBuilder lpPathBuf, ref uint pcchBuf);

        //http://support.microsoft.com/kb/234788
        private static void RunPowerPoint()
        {
            var path = new StringBuilder(248);
            var size = (uint)path.Capacity;

            if (MsiLocateComponent("{E72E0D20-0D63-438B-BC71-92AB9F9E8B54}", path, ref size) == MsiInstallState.LOCAL)
            {
                var pptx = Path.Combine(Directory.GetCurrentDirectory(), @"..\..\..\DebuggerShow.pptx");

                Process.Start(new ProcessStartInfo
                    {
                        FileName = path.ToString(),
                        Arguments = "/S \"" + pptx + "\""
                    });
            }
            else
            {
                Console.WriteLine("PowerPoint 2010 32-bit not found");
            }

        }
    }
}
