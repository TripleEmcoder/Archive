using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;

namespace Cognitis.Forms
{
    public class SelectListFieldDefinition : ValueFieldDefinition
    {
        public SelectListFieldDefinition(string name, string title, string description, IEnumerable<IValueDefinition> values)
            : base(name, title, description, values)
        {
        }

        public SelectListFieldDefinition(string name, string title, string description, params IValueDefinition[] values)
            : base(name, title, description, values)
        {
        }

        public override IEnumerable<IValidationAction> BuildValidationActions(IValidationAction condition)
        {
            IValidationAction fieldCondition = null;

            foreach (IValidationAction action in base.BuildValidationActions(condition))
            {
                if (fieldCondition == null)
                    fieldCondition = action;

                yield return action;
            }

            Debug.Assert(fieldCondition != null);

            fieldCondition = new VerifySelectListPresenceAction(fieldCondition, this);
            yield return fieldCondition;

            IValueDefinition previousValue = null;
            IValidationAction valueCondition = null;

            foreach (IValueDefinition value in Values)
            {
                foreach (IValidationAction action in value.BuildValidationActions(fieldCondition))
                {
                    if (valueCondition == null)
                        valueCondition = action;

                    yield return action;
                }

                valueCondition = new VerifySelectOptionPresenceAction(valueCondition, value);
                yield return valueCondition;
                yield return new VerifySelectOptionTitleAction(valueCondition, value);
                yield return new VerifySelectOptionParentAction(valueCondition, value, this);
                yield return new VerifySelectOptionOrderAction(valueCondition, value, previousValue);

                previousValue = value;
                valueCondition = fieldCondition;
            }

            Debug.Assert((previousValue == null) == (valueCondition == null));

            // ReSharper disable ConditionIsAlwaysTrueOrFalse
            if (previousValue != null)
                yield return new VerifySelectOptionOrderAction(fieldCondition, null, previousValue);
            // ReSharper restore ConditionIsAlwaysTrueOrFalse
        }
    }
}
