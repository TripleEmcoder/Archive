using System;
using System.Collections.Generic;
using System.Text;

namespace questions
{
    public class Question
    {
        public string Tag;
        public string Content;

        public void ReadProperties(string[] properties)
        {
            Tag = properties[1];
            Content = properties[7].Trim('"');
        }
    }
}
