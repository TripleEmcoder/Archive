using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Utility
{
    public class FileSystemSiteMapDefaultFilter : IFileSystemSiteMapFilter
    {
        public bool ShowFile(string path)
        {
            return true;
        }

        public bool ShowDirectory(string path)
        {
            return true;
        }
    }
}
