using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    class NntpArticle : INntpArticle
    {
        private int number;
        
        public NntpArticle(int number)
        {
            this.number = number;
        }

        public void Dispose()
        {
            throw new Exception("The method or operation is not implemented.");
        }

        public int Number
        {
            get { return number; }
        }

        public string Subject
        {
            get { return number.ToString(); }
        }

        public string From
        {
            get { return number.ToString(); }
        }

        public string Date
        {
            get { return number.ToString(); }
        }

        public string MessageID
        {
            get { return number.ToString(); }
        }

        public string References
        {
            get { return number.ToString(); }
        }

        public int Bytes
        {
            get { return 0; }
        }

        public int Lines
        {
            get { return 0; }
        }

        public string Body
        {
            get { return number.ToString(); }
        }

        //public override string ToString()
        //{
        //    return id;
        //}
    }
}
