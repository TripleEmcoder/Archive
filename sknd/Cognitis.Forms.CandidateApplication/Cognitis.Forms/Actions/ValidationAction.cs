using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using WatiN.Core;

namespace Cognitis.Forms
{
    public class ValidationAction : IValidationAction
    {
        public IValidationAction Condition { get; private set; }

        public ValidationAction(IValidationAction condition)
        {
            Condition = condition;
        }

        public virtual bool Run(Browser browser)
        {
            return false;
        }
    }
}
