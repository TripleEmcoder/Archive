using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cognitis.Forms
{
    public interface IFormDefinitionBuilder
    {
        IEnumerable<IFormDefinition> BuildFormDefinitions(Uri baseUrl);
    }
}
