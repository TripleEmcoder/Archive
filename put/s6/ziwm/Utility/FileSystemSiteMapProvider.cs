using System.Collections.Specialized;
using System.IO;
using System.Web;
using System;

namespace Utility
{
    public class FileSystemSiteMapProvider : SiteMapProvider
    {
        private string rootPath;
        private string rootName;
        private IFileSystemSiteMapFilter filter;
        private FileSystemSiteMapNodeFactory directoryFactory;
        private FileSystemSiteMapNodeFactory fileFactory;

        public FileSystemSiteMapProvider()
        {
            filter = new FileSystemSiteMapDefaultFilter();
        }

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
            rootPath = attributes["rootPath"].TrimEnd(Path.DirectorySeparatorChar);
            rootName = attributes["rootName"].TrimEnd(Path.DirectorySeparatorChar);

            if (!string.IsNullOrEmpty(attributes["filter"]))
                filter = (IFileSystemSiteMapFilter)Activator.CreateInstance(Type.GetType(attributes["filter"]));

            string path = HttpContext.Current.Request.ApplicationPath;
            directoryFactory = new FileSystemSiteMapNodeFactory(this, path + "/Directory.aspx?Path={0}");
            fileFactory = new FileSystemSiteMapNodeFactory(this, path + "/File.aspx?Path={0}");
        }

        public override SiteMapNode FindSiteMapNode(string url)
        {
            SiteMapNode node = null;

            if (directoryFactory.TryCreateNodeFromUrl(url, ref node) && filter.ShowDirectory(node.Key))
                return node;

            if (fileFactory.TryCreateNodeFromUrl(url, ref node) && filter.ShowFile(node.Key))
                return node;

            return null;
        }

        public override SiteMapNodeCollection GetChildNodes(SiteMapNode node)
        {
            SiteMapNodeCollection nodes = new SiteMapNodeCollection();

            if (Directory.Exists(node.Key))
            {
                foreach (string path in Directory.GetDirectories(node.Key))
                    if (filter.ShowDirectory(path))
                        nodes.Add(directoryFactory.CreateNodeFromPath(path));

                foreach (string path in Directory.GetFiles(node.Key))
                    if (filter.ShowFile(path))
                        nodes.Add(fileFactory.CreateNodeFromPath(path));
            }

            return nodes;
        }

        public override SiteMapNode FindSiteMapNodeFromKey(string key)
        {
            if (Directory.Exists(key) && filter.ShowDirectory(key))
                return directoryFactory.CreateNodeFromPath(key);

            if (File.Exists(key) && filter.ShowFile(key))
                return fileFactory.CreateNodeFromPath(key);

            return null;
        }

        public override SiteMapNode GetParentNode(SiteMapNode node)
        {
            if (node.Key == rootPath)
                return ParentProvider.GetParentNode(node);

            return directoryFactory.CreateNodeFromPath(Path.GetDirectoryName(node.Key));
        }

        protected override SiteMapNode GetRootNodeCore()
        {
            return directoryFactory.CreateNodeFromPath(rootPath);
        }
    }
}
