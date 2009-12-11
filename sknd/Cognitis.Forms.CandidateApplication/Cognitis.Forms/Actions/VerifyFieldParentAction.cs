using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cognitis.Forms
{
    class VerifyFieldParentAction : FieldValidationAction
    {
        public VerifyFieldParentAction(IValidationAction conditionAction, IFieldDefinition field, IGroupDefinition group)
            : base(conditionAction, field)
        {
        }
    }
}
