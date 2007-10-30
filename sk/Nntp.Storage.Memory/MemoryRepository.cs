using System;
using System.Collections.Generic;
using System.Text;

using System.Collections.ObjectModel;

namespace Test
{
    public class MemoryRepository : INntpRepository
    {
        protected Dictionary<string, INntpArticle> articles;
        protected Dictionary<string, INntpGroup> groups;

        public MemoryRepository(ReadOnlyCollection<INntpArticle> articles, ReadOnlyCollection<INntpGroup> groups)
        {
            this.articles = new Dictionary<string, INntpArticle>();

            foreach (INntpArticle article in articles)
                this.articles[article.ID] = article;

            this.groups = new Dictionary<string, INntpGroup>();

            foreach (INntpGroup group in groups)
                this.groups[group.Name] = group;
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

        public ReadOnlyCollection<INntpGroup> GetGroups()
        {
            return new List<INntpGroup>(groups.Values).AsReadOnly();
        }
    }
}
