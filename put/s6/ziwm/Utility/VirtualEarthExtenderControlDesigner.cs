﻿using System.Web.UI.Design;

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
