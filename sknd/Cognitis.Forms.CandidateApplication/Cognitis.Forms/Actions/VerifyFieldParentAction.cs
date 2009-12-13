using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using WatiN.Core;

namespace Cognitis.Forms
{
    public class VerifyFieldParentAction : FieldValidationAction
    {
        public IGroupDefinition Group { get; private set; }

        public VerifyFieldParentAction(IValidationAction conditionAction, IFieldDefinition field, IGroupDefinition group)
            : base(conditionAction, field)
        {
            Group = group;
        }

        public override bool Run(Browser browser)
        {
            var fieldWrapper = new FieldWrapper(browser, Field);
            var groupWrapper = new GroupWrapper(browser, Group);

            return fieldWrapper.GetDiv(0).Ancestor("fieldset").Equals(groupWrapper.GetFieldset());
        }

        public override string ToString()
        {
            return ToString(new { Field = Field.Name, Group = Group.Name });
        }
    }
}
