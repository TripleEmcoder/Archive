using System;
using System.Collections.Generic;
using System.Text;

using System.Diagnostics;
using System.Reflection;

namespace Test
{
    static class NntpCommandFactory
    {
        static private char[] separators;
        static private Dictionary<string, ConstructorInfo> constructors;

        static NntpCommandFactory()
        {
            separators = new char[] { ' ', '\t' };
            constructors = new Dictionary<string, ConstructorInfo>();

            Assembly assembly = Assembly.GetExecutingAssembly();

            foreach (Type type in assembly.GetTypes())
            {
                foreach (NntpCommandNameAttribute attribute
                    in type.GetCustomAttributes(typeof(NntpCommandNameAttribute), false))
                {
                    constructors[attribute.Name] = type.GetConstructor(
                        new Type[] { typeof(string), typeof(string) });

                    Debug.WriteLine(string.Format("Registering {0} for {1} command.",
                        type.Name, attribute.Name));
                }
            }
        }

        public static NntpCommand Create(string line)
        {
            string[] parts = line.Split(separators, 2);

            string name = parts[0].ToUpper();
            string parameters = parts.Length == 2 ? parts[1].TrimStart(separators) : null;

            if (!constructors.ContainsKey(name))
                throw new NotSupportedException("Unknown command");

            return (NntpCommand)constructors[name].Invoke(
                new object[] { name, parameters });
        }
    }
}
