using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cognitis.Forms
{
    public class VerifyFieldOrderAction : FieldValidationAction
    {
        public VerifyFieldOrderAction(IValidationAction condition, IFieldDefinition field, IFieldDefinition previousField) 
            : base(condition, field)
        {
        }
    }
}
