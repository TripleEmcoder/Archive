using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    class NntpRepository : INntpRepository
    {
        public INntpArticle GetArticle(string id)
        {
            return new NntpArticle(2121896);
        }

        public INntpGroup GetGroup(string name)
        {
            return new NntpGroup();
        }

        public INntpGroup[] GetGroups()
        {
            return new INntpGroup[] { new NntpGroup() };
        }
    }
}
