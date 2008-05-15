using System.Web;
using System.IO;
using System.Collections.Specialized;

namespace Utility
{
    public class FileSystemSiteMapNode : SiteMapNode
    {
        public FileSystemSiteMapNode(FileSystemSiteMapProvider provider, FileSystemInfo info, string format)
            : base(provider, info.FullName, string.Format(format, info.FullName), info.Name)
        {
        }
    }
    public class DirectorySiteMapNode : FileSystemSiteMapNode
    {
        public DirectorySiteMapNode(FileSystemSiteMapProvider provider, string path, string format)
            : this(provider, new DirectoryInfo(path), format)
        {
        }

        public DirectorySiteMapNode(FileSystemSiteMapProvider provider, DirectoryInfo info, string format)
            : base(provider, info, format)
        {
        }
    }

    public class FileSiteMapNode : FileSystemSiteMapNode
    {
        public FileSiteMapNode(FileSystemSiteMapProvider provider, string path, string format)
            : this(provider, new FileInfo(path), format)
        {
        }

        public FileSiteMapNode(FileSystemSiteMapProvider provider, FileInfo info, string format)
            : base(provider, info, format)
        {
        }
    }

    public class FileSystemSiteMapProvider : SiteMapProvider
    {
        private string rootPath;
        private string fileUrlFormat;
        private string directoryUrlFormat;

        public override void Initialize(string name, NameValueCollection attributes)
        {
            base.Initialize(name, attributes);
            rootPath = attributes["rootPath"];
            fileUrlFormat = "/File.aspx?Path={0}";
            directoryUrlFormat = "/Directory.aspx?Path={0}";
        }

        public override SiteMapNode FindSiteMapNode(string rawUrl)
        {
            string[] parts = (rawUrl + '?').Split('?');
            NameValueCollection parameters = HttpUtility.ParseQueryString(parts[1]);

            if (parts[0] == directoryUrlFormat.Split('?')[0])
                return new DirectorySiteMapNode(this, parameters[0], directoryUrlFormat);
            
            if (parts[0] == fileUrlFormat.Split('?')[0])
                return new FileSiteMapNode(this, parameters[0], fileUrlFormat);

            return null;
        }

        public override SiteMapNodeCollection GetChildNodes(SiteMapNode node)
        {
            SiteMapNodeCollection nodes = new SiteMapNodeCollection();

            if (node is DirectorySiteMapNode)
            {
                DirectoryInfo parent = new DirectoryInfo(node.Key);

                foreach (DirectoryInfo child in parent.GetDirectories())
                    nodes.Add(new DirectorySiteMapNode(this, child, directoryUrlFormat));

                foreach (FileInfo child in parent.GetFiles())
                    nodes.Add(new FileSiteMapNode(this, child, fileUrlFormat));
            }

            return nodes;
        }

        public override SiteMapNode FindSiteMapNodeFromKey(string key)
        {
            if (Directory.Exists(key))
                return new DirectorySiteMapNode(this, key, directoryUrlFormat);

            if (File.Exists(key))
                return new FileSiteMapNode(this, key, fileUrlFormat);

            return null;
        }

        public override SiteMapNode GetParentNode(SiteMapNode node)
        {
            if (node.Key == rootPath)
                return null;

            string parentPath = Path.GetDirectoryName(node.Key);

            return new DirectorySiteMapNode(this, parentPath, directoryUrlFormat);
        }

        protected override SiteMapNode GetRootNodeCore()
        {
            return new DirectorySiteMapNode(this, rootPath, directoryUrlFormat);
        }
    }
}
