using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace Nntp.Storage.Memory
{
    public class MemoryConnection : INntpConnection
    {
        private MemoryRepository repository;

        public MemoryConnection(MemoryRepository repository)
        {
            this.repository = repository;
            Monitor.Enter(repository);
        }

        public void Dispose()
        {
            Monitor.Exit(repository);
        }

        INntpArticle INntpConnection.GetArticle(string id)
        {
            if (!repository.articles.ContainsKey(id))
                return null;

            return repository.articles[id];
        }

        INntpGroup INntpConnection.GetGroup(string name)
        {
            if (!repository.groups.ContainsKey(name))
                return null;

            return repository.groups[name];
        }

        IEnumerable<INntpGroup> INntpConnection.GetGroups()
        {
            return repository.groups.Values;
        }

        INntpArticle INntpConnection.CreateArticle()
        {
            return new MemoryArticle(new Random().Next().ToString());
        }

        void INntpConnection.PostArticle(INntpArticle article)
        {
            throw new Exception("The method or operation is not implemented.");
        }
    }
}
