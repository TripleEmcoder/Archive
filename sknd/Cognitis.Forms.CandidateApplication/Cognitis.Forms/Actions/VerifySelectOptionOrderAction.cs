using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cognitis.Forms
{
    public class VerifySelectOptionOrderAction : ValueValidationAction
    {
        public VerifySelectOptionOrderAction(IValidationAction condition, IValueDefinition value, IValueDefinition previousValue)
            : base(condition, value)
        {
        }
    }
}
