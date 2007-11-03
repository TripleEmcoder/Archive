using System;
using System.Collections.Generic;
using System.Text;

using System.Diagnostics;
using System.Reflection;

namespace Nntp
{
    [NntpCommandName("CAPABILITIES")]
    [NntpCapabilityName("VERSION 2")]
    public class NntpCapabilitiesCommand : NntpCommand
    {
        static Dictionary<string, bool> capabilities;

        static NntpCapabilitiesCommand()
        {
            capabilities = new Dictionary<string, bool>();

            Assembly assembly = Assembly.GetExecutingAssembly();

            foreach (Type type in assembly.GetTypes())
            {
                foreach (NntpCapabilityNameAttribute attribute
                    in type.GetCustomAttributes(typeof(NntpCapabilityNameAttribute), false))
                {
                    capabilities[attribute.Name] = true;

                    Debug.WriteLine(string.Format("Providing {0} with {1}.",
                       attribute.Name, type.Name));
                }
            }
        }

        public NntpCapabilitiesCommand(string name)
            : base(name)
        {
        }

        public override void Execute(NntpSession session)
        {
            session.Connection.SendLine("101 Capability list follows");

            foreach (KeyValuePair<string, bool> capability in capabilities)
                if (capability.Value)
                    session.Connection.SendLine(capability.Key);

            session.Connection.SendLine(".");
        }
    }
}
