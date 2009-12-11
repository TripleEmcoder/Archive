using System;
using System.Collections.Generic;

namespace Cognitis.Forms
{
    public interface IFormDefinition : IValidationProvider
    {
        Uri Uri { get; }
        IEnumerable<IElementDefinition> Elements { get; }
    }
}
