using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using WatiN.Core;

namespace Cognitis.Forms
{
    public class VerifyFieldTitleAction : FieldValidationAction
    {
        public VerifyFieldTitleAction(IValidationAction condition, IFieldDefinition field) 
            : base(condition, field)
        {
        }

        public override bool Run(Browser browser)
        {
            return new FieldWrapper(browser, Field).GetTitle(0).Trim() == Field.Title;
        }

        public override string ToString()
        {
            return ToString(new { Field.Name, Field.Title });
        }
    }
}
