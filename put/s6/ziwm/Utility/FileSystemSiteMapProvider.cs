using System.Collections.Generic;
using System.Collections.Specialized;
using System.IO;
using System.Web;
using System.Diagnostics;
using System.Text.RegularExpressions;

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

        private string EncodePath(string path)
        {
            return HttpUtility.UrlEncode(path.Replace(Path.DirectorySeparatorChar, '/'));
        }

        private string DecodePath(string path)
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
                string path = UnvirtualizePath(virtualPath);

                if (path.StartsWith(provider.RootName))
                {
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

    public class FileSystemSiteMapProvider : SiteMapProvider
    {
        private string rootPath;
        private string rootName;
        private FileSystemSiteMapNodeFactory directoryFactory;
        private FileSystemSiteMapNodeFactory fileFactory;

        public string RootPath
        {
            get { return rootPath; }
        }

        public string RootName
        {
            get { return rootName; }
        }

        public override void Initialize(string name, NameValueCollection attributes)
        {
            base.Initialize(name, attributes);
            rootPath = attributes["rootPath"];
            rootName = attributes["rootName"];

            directoryFactory = new FileSystemSiteMapNodeFactory(this, "/Directory.aspx?Path={0}");
            fileFactory = new FileSystemSiteMapNodeFactory(this, "/File.aspx?Path={0}");
        }

        public override SiteMapNode FindSiteMapNode(string url)
        {
            SiteMapNode node = null;

            if (directoryFactory.TryCreateNodeFromUrl(url, ref node))
                return node;

            if (fileFactory.TryCreateNodeFromUrl(url, ref node))
                return node;

            return null;
        }

        public override SiteMapNodeCollection GetChildNodes(SiteMapNode node)
        {
            SiteMapNodeCollection nodes = new SiteMapNodeCollection();

            if (Directory.Exists(node.Key))
            {
                foreach (string path in Directory.GetDirectories(node.Key))
                    nodes.Add(directoryFactory.CreateNodeFromPath(path));

                foreach (string path in Directory.GetFiles(node.Key))
                    nodes.Add(fileFactory.CreateNodeFromPath(path));
            }

            return nodes;
        }

        public override SiteMapNode FindSiteMapNodeFromKey(string key)
        {
            if (Directory.Exists(key))
                return directoryFactory.CreateNodeFromPath(key);

            if (File.Exists(key))
                return fileFactory.CreateNodeFromPath(key);

            return null;
        }

        public override SiteMapNode GetParentNode(SiteMapNode node)
        {
            return directoryFactory.CreateNodeFromPath(Path.GetDirectoryName(node.Key));
        }

        protected override SiteMapNode GetRootNodeCore()
        {
            return directoryFactory.CreateNodeFromPath(rootPath);
        }
    }
}
