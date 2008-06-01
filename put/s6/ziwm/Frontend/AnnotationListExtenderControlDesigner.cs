using System.Web.UI.Design;

namespace Frontend
{
    public class AnnotationListExtenderControlDesigner : ControlDesigner
    {
        public override string GetDesignTimeHtml()
        {
            return CreatePlaceHolderDesignTimeHtml();
        }
    }
}
