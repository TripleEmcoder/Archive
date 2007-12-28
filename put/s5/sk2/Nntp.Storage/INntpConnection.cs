using System;
using System.Collections.Generic;
using System.Text;

namespace Nntp.Storage
{
    public interface INntpConnection : IDisposable
    {
        INntpArticle GetArticle(string id);
        INntpGroup GetGroup(string name);
        IEnumerable<INntpGroup> GetGroups();
        INntpArticle CreateArticle();
        void PostArticle(INntpArticle article);
    }
}
