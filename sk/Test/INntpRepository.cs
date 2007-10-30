using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    interface INntpRepository
    {
        INntpArticle GetArticle(string id);
        INntpGroup GetGroup(string name);
        INntpGroup[] GetGroups();
    }
}
