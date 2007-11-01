using System;
using System.Collections.Generic;
using System.Text;

using System.Collections.ObjectModel;

namespace Nntp.Storage.Memory
{
    public class MemoryRepository : INntpRepository
    {
        protected Dictionary<string, INntpArticle> articles;
        protected Dictionary<string, INntpGroup> groups;

        public MemoryRepository(ReadOnlyCollection<INntpArticle> articles, ReadOnlyCollection<INntpGroup> groups)
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

        public INntpTransaction CreateTransaction()
        {
            return new MemoryTransaction();
        }

        public INntpArticle GetArticle(string id)
        {
            if (!articles.ContainsKey(id))
                return null;

            return articles[id];
        }

        public INntpGroup GetGroup(string name)
        {
            if (!groups.ContainsKey(name))
                return null;

            return groups[name];
        }

        public IEnumerable<INntpGroup> GetGroups()
        {
            return groups.Values;
        }
    }
}
