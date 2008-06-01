using System.Collections.Generic;
using System.ComponentModel;
using System.Web.UI;
using System.Web.UI.HtmlControls;

[assembly: WebResource("Frontend.AnnotationListClientControl.js", "application/x-javascript")]

namespace Frontend
{
    [TargetControlType(typeof(HtmlTable))]
    [Designer(typeof(AnnotationListExtenderControlDesigner))]
    public class AnnotationListExtenderControl : ExtenderControl
    {
        protected override IEnumerable<ScriptDescriptor> GetScriptDescriptors(Control targetControl)
        {
            ScriptControlDescriptor descriptor = new ScriptControlDescriptor(
                "Frontend.AnnotationListClientControl", targetControl.ClientID);

            yield return descriptor;
        }

        protected override IEnumerable<ScriptReference> GetScriptReferences()
        {
            yield return new ScriptReference("Frontend.AnnotationListClientControl.js", "Frontend");
        }
    }
}
