using System;
using System.Collections.Generic;
using System.Text;

using System.Diagnostics;
using System.Reflection;

namespace Nntp
{
    //HELP, CAPABILITIES
    internal static class NntpCommandFactory
    {
        static private Dictionary<string, ConstructorInfo> constructors;

        static NntpCommandFactory()
        {
            constructors = new Dictionary<string, ConstructorInfo>();

            Assembly assembly = Assembly.GetExecutingAssembly();

            foreach (Type type in assembly.GetTypes())
            {
                foreach (NntpCommandNameAttribute attribute
                    in type.GetCustomAttributes(typeof(NntpCommandNameAttribute), false))
                {
                    if (constructors.ContainsKey(attribute.Name))
                        throw new Exception();

                    constructors[attribute.Name] = type.GetConstructor(new Type[] { typeof(string) });

                    Debug.WriteLine(string.Format("Registering {0} for {1} command.",
                        type.Name, attribute.Name));
                }
            }
        }

        public static NntpCommand Create(ref string line)
        {
            char[] separators = new char[] { ' ', '\t' };
            string[] parts = line.Split(separators, 2);

            string name = parts[0].ToUpper();
            line = parts.Length == 2 ? parts[1].TrimStart(separators) : "";

            if (!constructors.ContainsKey(name))
                throw new NotSupportedException("Unknown command", new IndexOutOfRangeException());

            return (NntpCommand)constructors[name].Invoke(new object[] { name });
        }
    }
}
