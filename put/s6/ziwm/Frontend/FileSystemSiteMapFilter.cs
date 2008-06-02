using System;
using System.Data;
using System.Configuration;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.HtmlControls;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Xml.Linq;
using Utility;

namespace Frontend
{
    public class FileSystemSiteMapFilter : IFileSystemSiteMapFilter
    {
        public bool ShowFile(string path)
        {
            if (path.EndsWith(".ptiff"))
                return true;

            return false;
        }

        public bool ShowDirectory(string path)
        {
            return true;
        }
    }
}
