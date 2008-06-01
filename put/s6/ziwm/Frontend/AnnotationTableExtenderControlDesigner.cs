using System.Web.UI.Design;

namespace Frontend
{
    public class AnnotationTableExtenderControlDesigner : ControlDesigner
    {
        public override string GetDesignTimeHtml()
        {
            return CreatePlaceHolderDesignTimeHtml();
        }
    }
}
