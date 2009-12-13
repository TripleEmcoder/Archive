using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using WatiN.Core;

namespace Cognitis.Forms
{
    public class VerifySelectListPresenceAction : FieldValidationAction
    {
        public VerifySelectListPresenceAction(IValidationAction condition, IFieldDefinition field)
            : base(condition, field)
        {
        }

        public override bool Run(Browser browser)
        {
            return new SelectListFieldWrapper(browser, Field).GetSelectList(0).Exists;
        }
    }
}
