using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    class NntpSession 
    {
        private ILineConnection connection;

        public NntpSession(ILineConnection connection)
        {
            this.connection = connection;

            connection.LineReceived += OnLineReceived;
            connection.SendLine("200 Service available, posting allowed");
        }

        void OnLineReceived(object sender, LineEventArgs e)
        {
            //parsowanie e.Line
            //jakaú praca
            //connection.SendLine(odpowiedü)
        }
    }
}
