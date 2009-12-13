using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;

namespace Cognitis.Forms
{
    public class GroupDefinition : IGroupDefinition
    {
        public string Name { get; private set; }
        public string Title { get; private set; }
        public string Description { get; private set; }
        public IEnumerable<IFieldDefinition> Fields { get; private set; }

        public GroupDefinition(string name, string title, string description, IEnumerable<IFieldDefinition> fields)
        {
            Name = name;
            Title = title;
            Description = description;
            Fields = fields;
        }

        public GroupDefinition(string name, string title, string description, params IFieldDefinition[] fields)
            : this(name, title, description, (IEnumerable<IFieldDefinition>)fields)
        {
        }

        public IEnumerable<IValidationAction> BuildValidationActions(IValidationAction condition)
        {
            condition = new VerifyGroupPresenceAction(condition, this);
            yield return condition;
            yield return new VerifyGroupTitleAction(condition, this);

            IFieldDefinition previousField = null;
            IValidationAction fieldCondition = null;

            foreach (IFieldDefinition field in Fields)
            {
                foreach (IValidationAction action in field.BuildValidationActions(condition))
                {
                    if (fieldCondition == null)
                        fieldCondition = action;
                    
                    if (action != condition)
                    yield return action;
                }

                fieldCondition = new VerifyFieldParentAction(fieldCondition, field, this);
                yield return fieldCondition;
                yield return new VerifyFieldOrderAction(fieldCondition, field, previousField);
                
                previousField = field;
                fieldCondition = condition;
            }

            Debug.Assert((previousField == null) == (fieldCondition == null));

            if (previousField != null)
                yield return new VerifyFieldOrderAction(fieldCondition, null, previousField);
        }
    }
}
