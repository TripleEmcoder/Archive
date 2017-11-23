using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using PostSharp.Aspects;
using PostSharp.Extensibility;

//[assembly: ClrDumpAspectDemo.ClrDumpAspect2]

namespace ClrDumpAspectDemo
{
    [MulticastAttributeUsage(MulticastTargets.Method)]
    [Serializable]
    public class ClrDumpAspect2 : Aspect
    {
        //public override void OnException(MethodExecutionArgs args)
        //{
        //    ClrDump.Dump();
        //    base.OnException(args);
        //}
    }
}
