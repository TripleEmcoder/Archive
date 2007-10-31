using System;
using System.Collections.Generic;
using System.Text;

using System.Collections.ObjectModel;

namespace Nntp.Storage
{
    public interface INntpRepository : IDisposable
    {
        INntpArticle GetArticle(string id);
        INntpGroup GetGroup(string name);
        IEnumerable<INntpGroup> GetGroups();
    }
}
