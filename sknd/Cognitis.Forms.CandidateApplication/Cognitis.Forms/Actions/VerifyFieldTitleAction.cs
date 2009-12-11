using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cognitis.Forms
{
    class VerifyFieldTitleAction : FieldValidationAction
    {
        public VerifyFieldTitleAction(IValidationAction condition, IFieldDefinition field) 
            : base(condition, field)
        {
        }
    }
}
