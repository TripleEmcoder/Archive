using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using PostSharp.Aspects;

//[assembly: ClrDumpAspectDemo.ClrDumpAspect]

namespace ClrDumpAspectDemo
{
[Serializable]
class ClrDumpAspect : OnExceptionAspect
{
    public override void OnException(MethodExecutionArgs args)
    {
        ClrDump.Dump();
        base.OnException(args);
    }
}
}
