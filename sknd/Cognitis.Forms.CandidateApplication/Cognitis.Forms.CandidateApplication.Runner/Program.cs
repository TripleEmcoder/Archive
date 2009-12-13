using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using WatiN.Core;
using System.Diagnostics;

namespace Cognitis.Forms.CandidateApplication.Runner
{
    class Program
    {
        [STAThread]
        static void Main(string[] args)
        {
            var baseUri = new Uri("http://www.cognitis.pl/");
            var results = new Dictionary<IValidationAction, bool>();

            foreach (IFormDefinition form in new FormDefinitionBuilder().BuildFormDefinitions(baseUri))
            {
                using(var browser = new IE(form.Uri, true))
                {
                    foreach (IValidationAction action in form.BuildValidationActions(null))
                    {
                        Console.ResetColor();
                        Console.Write(action);
                        Console.Write("\t");

                        Debug.Assert(action.Condition == null || results.ContainsKey(action.Condition));
                        bool skip = action.Condition != null && !results[action.Condition];

                        if (skip)
                        {
                            results[action] = false;
                            Console.ForegroundColor = ConsoleColor.DarkGray;
                            Console.WriteLine("SKIP");
                        }
                        else
                        {
                            results[action] = action.Run(browser);
                            Console.ForegroundColor = results[action] ? ConsoleColor.Green : ConsoleColor.Red;
                            Console.WriteLine(results[action] ? "SUCCESS" : "FAILURE");
                        }
                    }
                }
            }
        }
    }
}
