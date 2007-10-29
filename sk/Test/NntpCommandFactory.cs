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

                    Debug.WriteLine(string.Format("Using {0} for {1} command.",
                        type.Name, attribute.Name));
                }
            }
        }

        public static ILineCommand Create(string line)
        {
            string[] parts = line.Split(separators, 2);

            string command = parts[0].ToUpper();
            string parameters = parts[1].TrimStart(separators);

            if (!constructors.ContainsKey(command))
                throw new NotSupportedException();

            return (ILineCommand)constructors[command].Invoke(
                new object[] { command, parameters });
        }
    }
}
