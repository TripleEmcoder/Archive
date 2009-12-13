using System.Collections.Generic;

namespace Cognitis.Forms
{
    public interface IValueFieldDefinition : IFieldDefinition
    {
        IEnumerable<IValueDefinition> Values { get; }
    }
}