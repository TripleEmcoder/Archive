using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cognitis.Forms
{
    public interface IElementDefinition : IValidationProvider
    {
        string Name { get; }
        string Title { get; }
        string Description { get; }
    }
}
