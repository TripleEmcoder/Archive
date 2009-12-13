using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cognitis.Forms
{
    public class VerifySelectOptionTitleAction : ValueValidationAction
    {
        public VerifySelectOptionTitleAction(IValidationAction condition, IValueDefinition value) 
            : base(condition, value)
        {
        }
    }
}
