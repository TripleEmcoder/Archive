using System;
using System.Collections.Generic;
using System.Text;

using System.IO;

namespace questions
{
    public class Answer
    {
        public string Content;
        public Question Source;
        public Question Destination;

        public string Identifier
        {
            get { return ClipsTools.MakeIdentifier(Content); }
        }

        public void ReadProperties(string[] properties, Dictionary<string, Question> questions)
        {
            Content = properties[4 + 2 * int.Parse(properties[3])].Trim('"');
            Source = questions[properties[1]];
            Destination = questions[properties[2]];
            Source.Answers.Add(this);
        }

        public void WriteRule(TextWriter output)
        {
            output.WriteLine("(defrule answer_{0}_{1}", Source.Identifier, Identifier);
            output.WriteLine("\t(declare (salience -20))");
            output.WriteLine("\t?i <- (step \"{0}\")", Source.Tag);
            output.WriteLine("\t?j <- (answer \"{0}\")", Content);
            output.WriteLine("=>");
            output.WriteLine("\t(retract ?i)");
            output.WriteLine("\t(retract ?j)");
            output.WriteLine("\t(assert (step \"{0}\"))", Destination.Tag);
            output.WriteLine(")");
            output.WriteLine();
        }
    }
}
