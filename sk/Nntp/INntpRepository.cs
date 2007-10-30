using System;
using System.Collections.Generic;
using System.Text;

using System.Collections.ObjectModel;

namespace Test
{
    public interface INntpRepository
    {
        INntpArticle GetArticle(string id);
        INntpGroup GetGroup(string name);
        ReadOnlyCollection<INntpGroup> GetGroups();
    }
}
