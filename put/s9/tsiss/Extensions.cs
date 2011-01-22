using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using SemWeb;

namespace FactFinder
{
    public static class Extensions
    {
        public static Statement? SelectSingle(this Store store, Statement statement)
        {
            var result = store.Select(statement);
            
            if (result.StatementCount == 0)
                return null;

            return result.Single();
        }
    }
}
