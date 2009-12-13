using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cognitis.Forms
{
    public class ValueDefinition : IValueDefinition 
    {
        public string Name { get; private set; }
        public string Title { get; private set; }

        public ValueDefinition(string name, string title)
        {
            Name = name;
            Title = title;
        }

        public IEnumerable<IValidationAction> BuildValidationActions(IValidationAction condition)
        {
            yield return condition;
        }
    }
}
