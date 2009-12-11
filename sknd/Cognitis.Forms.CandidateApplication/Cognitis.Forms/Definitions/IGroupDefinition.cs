using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cognitis.Forms
{
    public interface IGroupDefinition : IElementDefinition
    {
        string Name { get; }
        string Title { get; }
        IEnumerable<IFieldDefinition> Fields { get; }
    }
}
