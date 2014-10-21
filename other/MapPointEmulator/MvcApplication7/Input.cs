using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using GoogleMapsApi.Entities.Geocoding.Response;

namespace MvcApplication7
{
    public static class InputExtensions
    {
        public static Result GetType(this IEnumerable<Result> results, string type)
        {
            if (results == null)
                return null;

            return results.FirstOrDefault(r => r.Types.Contains(type));
    }

        public static string GetComponent(this Result result, string type)
        {
            if (result == null)
                return null;

            if (type == "formatted_address")
                return result.FormattedAddress;

            var component = result.AddressComponents.FirstOrDefault(c => c.Types.Contains(type));

            if (component == null)
                return null;

            return component.LongName;
        }

        public static IEnumerable<T> WhereNot<T>(this IEnumerable<T> source, Func<T, bool> predicate)
        {
            return source.Where(i => !predicate(i));
        }

        public static string JoinNotEmpty(this IEnumerable<string> source, string separator)
        {
            return string.Join(separator, source.WhereNot(string.IsNullOrEmpty));
        }
    }
}