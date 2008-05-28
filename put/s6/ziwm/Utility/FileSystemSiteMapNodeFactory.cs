using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Web;

namespace Utility
{
    public class FileSystemSiteMapNodeFactory
    {
        private readonly FileSystemSiteMapProvider provider;
        private readonly string format;

        public FileSystemSiteMapNodeFactory(FileSystemSiteMapProvider provider, string format)
        {
            this.provider = provider;
            this.format = format;
        }

        private string VirtualizePath(string path)
        {
            Debug.Assert(path.StartsWith(provider.RootPath));
            return Regex.Replace(path, "^" + Regex.Escape(provider.RootPath), provider.RootName);
        }

        private string UnvirtualizePath(string path)
        {
            Debug.Assert(path.StartsWith(provider.RootName));
            return Regex.Replace(path, "^" + Regex.Escape(provider.RootName), provider.RootPath);
        }

        private static string EncodePath(string path)
        {
            return HttpUtility.UrlEncode(path.Replace(Path.DirectorySeparatorChar, '/'));
        }

        private static string DecodePath(string path)
        {
            return HttpUtility.UrlDecode(path).Replace('/', Path.DirectorySeparatorChar);
        }

        public bool TryCreateNodeFromUrl(string url, ref SiteMapNode node)
        {
            Regex regex = new Regex(format.Replace("?", @"\?").Replace("{0}", "(.+)"));
            Match match = regex.Match(url);

            if (match.Groups.Count == 2)
            {
                string encodedPath = match.Groups[1].Value;
                string virtualPath = DecodePath(encodedPath);

                if (virtualPath.StartsWith(provider.RootName))
                {
                    string path = UnvirtualizePath(virtualPath);

                    node = new SiteMapNode(provider,
                        path, string.Format(format, encodedPath), Path.GetFileName(virtualPath));

                    return true;
                }
            }

            return false;
        }

        public SiteMapNode CreateNodeFromPath(string path)
        {
            Debug.Assert(Directory.Exists(path) || File.Exists(path));

            string virtualPath = VirtualizePath(path);
            string encodedPath = EncodePath(virtualPath);

            return new SiteMapNode(provider,
                path, string.Format(format, encodedPath), Path.GetFileName(virtualPath));
        }
    }
}
