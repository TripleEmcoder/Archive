using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cognitis.Forms
{
    public class VerifySelectOptionParentAction : ValueValidationAction
    {
        public VerifySelectOptionParentAction(IValidationAction condition, IValueDefinition value, IFieldDefinition field)
            : base(condition, value)
        {
        }
    }
}
