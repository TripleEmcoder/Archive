using System;
using System.Collections;
using System.Data;
using System.Configuration;
using System.Linq;
using System.Text.RegularExpressions;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.HtmlControls;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Xml.Linq;

namespace Frontend
{
    public class FileContext
    {
        public static FileContext Current
        {
            get
            {
                IDictionary items = HttpContext.Current.Items;

                if (items["FileContext"] == null)
                    items["FileContext"] = new FileContext(HttpContext.Current);

                return (FileContext)items["FileContext"];
            }
        }

        private readonly string path;
        private readonly string key;

        public FileContext(HttpContext http)
        {
            DecodeRefererPath(http.Request.UrlReferrer.PathAndQuery, out path);
            DecodePath(http.Request.Url.PathAndQuery, out key);
        }

        public string Path
        {
            get { return path; }
        }

        public string Key
        {
            get { return key; }
        }

        private static void DecodeRefererPath(string query, out string path)
        {
            path = new SiteMapDataSource().Provider.FindSiteMapNode(query).Key;
        }

        private static void DecodePath(string query, out string key)
        {
            Regex regex = new Regex(@"/(\w)(\d+)\.png", RegexOptions.Compiled);
            Match match = regex.Match(query);
            key = match.Groups[2].Value;
        }
    }
}
