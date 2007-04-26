using System;
using System.Collections.Generic;
using System.Text;

using System.IO;

namespace questions
{
    public class Question
    {
        public string Tag;
        public string Content;
        public List<Answer> Answers;

        public string Identifier
        {
            get { return ClipsTools.MakeIdentifier(Tag); }
        }

        public void ReadProperties(string[] properties)
        {
            Tag = properties[1];
            Content = properties[7].Trim('"');
            Answers = new List<Answer>();
        }

        public void WriteRule(TextWriter output)
        {
            output.WriteLine("(defrule question_{0}", Identifier);
            output.WriteLine("\t(declare (salience -20))");
            output.WriteLine("\t(step \"{0}\")", Tag);
            output.WriteLine("=>");
            output.Write("\t(assert (question \"{0}", Content);

            foreach (Answer answer in Answers)
                output.Write(";{0}", answer.Content);

            output.WriteLine("\"))");
            output.WriteLine(")");
            output.WriteLine();
        }
    }
}
