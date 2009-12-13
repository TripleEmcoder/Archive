using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using WatiN.Core;

namespace Cognitis.Forms
{
    public class VerifyFieldPresenceAction : FieldValidationAction
    {
        public VerifyFieldPresenceAction(IValidationAction condition, IFieldDefinition field)
            : base(condition, field)
        {
        }

        public override bool Run(Browser browser)
        {
            return new FieldWrapper(browser, Field).GetDiv(0).Exists;
        }

        public override string ToString()
        {
            return ToString(new { Field.Name });
        }
    }
}
