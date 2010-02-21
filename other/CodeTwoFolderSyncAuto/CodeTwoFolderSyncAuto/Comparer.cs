using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeTwoFolderSyncAuto
{
    class Comparer : IEqualityComparer<string[]>, IEqualityComparer<KeyValuePair<string[], string[]>>
    {
        private const string separator = @"\";

        public bool Equals(string[] x, string[] y)
        {
            return string.Join(separator, x).Equals(string.Join(separator, y));
        }

        public int GetHashCode(string[] obj)
        {
            return string.Join(separator, obj).GetHashCode();
        }

        public bool Equals(KeyValuePair<string[], string[]> x, KeyValuePair<string[], string[]> y)
        {
            return string.Join(separator, x.Key).Equals(string.Join(separator, y.Key))
                &&  string.Join(separator, x.Value).Equals(string.Join(separator, y.Value));
        }

        public int GetHashCode(KeyValuePair<string[], string[]> obj)
        {
            return (string.Join(separator, obj.Key) + string.Join(separator, obj.Value)).GetHashCode();
        }
    }
}
