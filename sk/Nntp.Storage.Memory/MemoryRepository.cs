using System;
using System.Collections.Generic;
using System.Text;

namespace Nntp.Storage.Memory
{
    public class MemoryRepository : INntpRepository
    {
        internal Dictionary<string, INntpArticle> articles;
        internal Dictionary<string, INntpGroup> groups;

        public MemoryRepository(IEnumerable<INntpArticle> articles, IEnumerable<INntpGroup> groups)
        {
            this.articles = new Dictionary<string, INntpArticle>();

            foreach (INntpArticle article in articles)
                this.articles[article.MessageID] = article;

            this.groups = new Dictionary<string, INntpGroup>();

            foreach (INntpGroup group in groups)
                this.groups[group.Name] = group;
        }

        public void Dispose()
        {
        }

        INntpConnection INntpRepository.CreateConnection()
        {
            return new MemoryConnection(this);
        }
    }
}
