using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using WatiN.Core;

namespace Cognitis.Forms
{
    public class SelectListFieldWrapper : FieldWrapper
    {
        public SelectListFieldWrapper(Browser browser, IFieldDefinition field) 
            : base(browser, field)
        {
        }

        public SelectList GetSelectList(int index)
        {
            return GetDiv(index).SelectList(list => list.GetAttributeValue("name") == Field.Name);
        }
    }
}
