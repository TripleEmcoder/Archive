using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cognitis.Forms
{
    public class ValueFieldDefinition : FieldDefinition, IValueFieldDefinition
    {
        public IEnumerable<IValueDefinition> Values { get; private set; }

        public ValueFieldDefinition(string name, string title, string description, IEnumerable<IValueDefinition> values) 
            : base(name, title, description)
        {
            Values = values;
        }

        public ValueFieldDefinition(string name, string title, string description, params IValueDefinition[] values)
            : this(name, title, description, (IEnumerable<IValueDefinition>)values)
        {
        }
    }
}
