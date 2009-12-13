using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using WatiN.Core;

namespace Cognitis.Forms
{
    public class GroupWrapper
    {
        protected Browser Browser { get; private set; }
        protected IGroupDefinition Group { get; private set; }

        public GroupWrapper(Browser browser, IGroupDefinition group)
        {
            Browser = browser;
            Group = group;
        }

        private string TransformName()
        {
            return Group.Name.Replace("_", "-");
        }

        public Element GetFieldset()
        {
            //return Browser.Element(element => element.TagName == "fieldset" && element.ClassName == TransformName());
            return Browser.ElementWithTag("fieldset", Find.ByClass(TransformName()));
        }

        public Element GetLegend()
        {
            return GetFieldset().DomContainer.ElementWithTag("legend", Find.Any);
        }
    }
}
