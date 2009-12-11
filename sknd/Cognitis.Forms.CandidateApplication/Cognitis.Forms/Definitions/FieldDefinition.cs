using System;
using System.Collections.Generic;

namespace Cognitis.Forms
{
    public class FieldDefinition : IFieldDefinition
    {
        public FieldDefinition(string name, string title, string description)
        {
            Name = name;
            Title = title;
            Description = description;
        }

        public string Name { get; private set; }
        public string Title { get; private set; }
        public string Description { get; private set; }

        public IEnumerable<IValidationAction> BuildValidationActions(IValidationAction condition)
        {
            condition = new VerifyFieldPresenceAction(condition, this);
            yield return condition;
            yield return new VerifyFieldTitleAction(condition, this);
        }
    }
}
