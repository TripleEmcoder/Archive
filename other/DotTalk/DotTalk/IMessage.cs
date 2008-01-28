using System;
using System.Collections.Generic;
using System.Text;

namespace DotTalk
{
    public interface IMessage
    {
        ISender Sender
        {
            get;
            set;
        }

        IRecipient Recipient
        {
            get;
            set;
        }

        int Sent
        {
            get;
            set;
        }

        int Received
        {
            get;
            set;
        }
    }
}
