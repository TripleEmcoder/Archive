using System;
using System.Collections.Generic;
using System.Text;

namespace Nntp
{
    [NntpCommandName("HELP")]
    [NntpCapabilityName("VERSION 2")]
    public class NntpHelpCommand : NntpCommand
    {
        public NntpHelpCommand(string name)
            : base(name)
        {
        }

        public override void Execute(NntpSession session)
        {
            session.Connection.SendLine("100 Help text follows");
            session.Connection.SendLine(".NET NNTP Server - Sieci Komputerowe 2007");
            session.Connection.SendLine("Autorzy: Bartosz Kukawka, Marcin Miko³ajczak");
            session.Connection.SendLine("");
            session.Connection.SendLine("Serwer implementuje komendy zgodnie z wytycznymi RFC 3977.");
            session.Connection.SendLine("Artyku³y przechowywane s¹ w SQL Server 2005 przy pomocy NHibernate.");
            session.Connection.SendLine(".");
        }
    }
}
