using System;
using System.Collections.Generic;
using System.Text;

namespace Nntp.Storage.Memory
{
    public class MemoryRepository : INntpRepository
    {
        protected Dictionary<string, INntpArticle> articles;
        protected Dictionary<string, INntpGroup> groups;

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

        public INntpConnection CreateTransaction()
        {
            return new MemoryConnection();
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

        public INntpArticle CreateArticle()
        {
            return new MemoryArticle(new Random().Next().ToString());
        }

        public void PostArticle(INntpArticle article)
        {
            throw new Exception("The method or operation is not implemented.");
        }
    }
}
