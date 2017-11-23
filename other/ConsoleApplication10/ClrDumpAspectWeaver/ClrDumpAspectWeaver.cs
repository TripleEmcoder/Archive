using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using PostSharp.Aspects.Configuration;
using PostSharp.Extensibility;
using PostSharp.Sdk.AspectWeaver;
using PostSharp.Sdk.AspectWeaver.AspectWeavers;

namespace ClrDumpAspectDemo
{
    class ClrDumpAspectWeaver : MethodLevelAspectWeaver
    {
        private static AspectConfigurationAttribute config = new AspectConfigurationAttribute();

        public ClrDumpAspectWeaver()
            :base(config,  MulticastTargets.Method | MulticastTargets.Constructor)
        {
            
        }

        protected override AspectWeaverInstance CreateAspectWeaverInstance(AspectInstanceInfo aspectInstanceInfo)
        {
            return new ClrDumpAspectWeaverInstance(this, aspectInstanceInfo);
        }
    }

     class ClrDumpAspectWeaverInstance : MethodLevelAspectWeaverInstance
    {
         public ClrDumpAspectWeaverInstance(MethodLevelAspectWeaver aspectWeaver, AspectInstanceInfo aspectInstanceInfo) : base(aspectWeaver, aspectInstanceInfo)
         {
         }

         public override void ProvideAspectTransformations(AspectWeaverTransformationAdder adder)
         {
             
         }
    }
}
