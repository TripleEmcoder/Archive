using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using WatiN.Core;

namespace Cognitis.Forms
{
    public class FieldWrapper
    {
        protected Browser Browser { get; private set; }
        protected IFieldDefinition Field { get; private set; }

        public FieldWrapper(Browser browser, IFieldDefinition field)
        {
            Browser = browser;
            Field = field;
        }

        private string TransformName(int index)
        {
            string template = Field.Name;
            string[] patterns = new[] { "_", "][", "[", "]" };

            foreach (string pattern in patterns)
                template = template.Replace(pattern, "-");

            template = template.Trim('-');

            return string.Format(template, index);
        }

        private string BuildId(int index)
        {
            return string.Format("edit-{0}", TransformName(index));
        }

        private string BuildDivId(int index)
        {
            return string.Format("{0}-wrapper", BuildId(index));
        }

        public Div GetDiv(int index)
        {
            return Browser.Div(div => div.Id == BuildDivId(index));
        }

        public Label GetLabel(int index)
        {
            return GetDiv(index).Label(label => label.For == BuildId(index));
        }

        public string GetTitle(int index)
        {
            Label label = GetLabel(0);

            if (label.Elements.Count > 0)
                return label.Elements[0].TextBefore;

            return label.Text;
        }
    }
}
