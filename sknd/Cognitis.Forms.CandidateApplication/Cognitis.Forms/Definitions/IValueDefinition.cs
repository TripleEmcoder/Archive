using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cognitis.Forms
{
    public interface IValueDefinition : IValidationProvider
    {
        string Name { get; }
        string Title { get; }
    }
}
