using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Web.UI.Design;

namespace Utility
{
    public class VirtualEarthExtenderControlDesigner : ControlDesigner
    {
        public override string GetDesignTimeHtml()
        {
            return CreatePlaceHolderDesignTimeHtml();
        }
    }
}
