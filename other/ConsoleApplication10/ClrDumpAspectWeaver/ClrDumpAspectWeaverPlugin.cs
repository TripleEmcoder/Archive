using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using PostSharp.Sdk.AspectWeaver;

namespace ClrDumpAspectDemo
{
    class ClrDumpAspectWeaverPlugin : AspectWeaverPlugIn
    {
        public ClrDumpAspectWeaverPlugin(int priority) : base(priority)
        {
        }

        protected override void Initialize()
        {
            base.Initialize();
            BindAspectWeaver<ClrDumpAspect2, ClrDumpAspectWeaver>();
        }
    }
}
