using System;
using System.Collections.Generic;
using System.Text;

namespace Nntp.Storage.Database
{
    public class DatabaseRepository : INntpRepository
    {
        public void Dispose()
        {
        }

        INntpConnection INntpRepository.CreateConnection()
        {
            return new DatabaseConnection();
        }
    }
}
