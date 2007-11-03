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

        INntpConnection INntpRepository.CreateTransaction()
        {
            return new MemoryConnection();
        }

        INntpArticle INntpRepository.GetArticle(string id)
        {
            if (!articles.ContainsKey(id))
                return null;

            return articles[id];
        }

        INntpGroup INntpRepository.GetGroup(string name)
        {
            if (!groups.ContainsKey(name))
                return null;

            return groups[name];
        }

        IEnumerable<INntpGroup> INntpRepository.GetGroups()
        {
            return groups.Values;
        }

        INntpArticle INntpRepository.CreateArticle()
        {
            return new MemoryArticle(new Random().Next().ToString());
        }

        void INntpRepository.PostArticle(INntpArticle article)
        {
            throw new Exception("The method or operation is not implemented.");
        }
    }
}
