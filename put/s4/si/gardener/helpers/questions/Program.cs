using System;
using System.Collections.Generic;
using System.Text;

using System.IO;
using System.Text.RegularExpressions;
using System.Diagnostics;

namespace questions
{
    class Program
    {
        static void Main(string[] args)
        {
            Dictionary<string, Question> questions
                = new Dictionary<string, Question>();

            List<Answer> answers = new List<Answer>();

            using (StreamReader input = new StreamReader(args[0]))
            {
                string query = "{0}(?=(?:[^{1}]*{1}[^{1}]*{1})*(?![^{1}]*{1}))";

                Regex splitter = new Regex(
                    String.Format(query, Regex.Escape(" "), Regex.Escape("\"")));

                while (!input.EndOfStream)
                {
                    string[] properties = splitter.Split(input.ReadLine());

                    if (properties[0] == "node")
                    {
                        Question question = new Question();
                        question.ReadProperties(properties);
                        questions[question.Tag] = question;
                    }

                    if (properties[0] == "edge")
                    {
                        Answer answer = new Answer();
                        answer.ReadProperties(properties, questions);
                        answers.Add(answer);
                    }
                }
            }

            using (StreamWriter output = new StreamWriter(args[1]))
            {
                foreach (Question question in questions.Values)
                    question.WriteRule(output);

                foreach (Answer answer in answers)
                    answer.WriteRule(output);
            }
        }
    }
}
