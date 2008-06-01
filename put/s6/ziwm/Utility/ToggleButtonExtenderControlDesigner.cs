using System.Web.UI.Design;

namespace Utility
{
    public class ToggleButtonExtenderControlDesigner : ControlDesigner
    {
        public override string GetDesignTimeHtml()
        {
            return CreatePlaceHolderDesignTimeHtml();
        }
    }
}
