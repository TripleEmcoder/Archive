using System;
using System.Collections.Generic;
using System.Text;

namespace questions
{
    class Answer
    {
        public string Content;
        public Question Source;
        public Question Destination;

        public void ReadProperties(string[] properties, Dictionary<string, Question> questions)
        {
            Content = properties[4 + 2 * int.Parse(properties[3])].Trim('"');
            Source = questions[properties[1]];
            Destination = questions[properties[2]];
        }
    }
}
