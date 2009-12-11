using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cognitis.Forms
{
    class VerifyFieldPresenceAction : FieldValidationAction
    {
        public VerifyFieldPresenceAction(IValidationAction condition, IFieldDefinition field)
            : base(condition, field)
        {
        }
    }
}
