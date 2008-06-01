using System.Collections.Generic;
using System.ComponentModel;
using System.Web.UI;
using System.Web.UI.HtmlControls;

[assembly: WebResource("Frontend.AnnotationTableClientControl.js", "application/x-javascript")]

namespace Frontend
{
    [TargetControlType(typeof(HtmlTable))]
    [Designer(typeof(AnnotationTableExtenderControlDesigner))]
    public class AnnotationTableExtenderControl : ExtenderControl
    {
        protected override IEnumerable<ScriptDescriptor> GetScriptDescriptors(Control targetControl)
        {
            ScriptControlDescriptor descriptor = new ScriptControlDescriptor(
                "Frontend.AnnotationTableClientControl", targetControl.ClientID);

            yield return descriptor;
        }

        protected override IEnumerable<ScriptReference> GetScriptReferences()
        {
            yield return new ScriptReference("Frontend.AnnotationTableClientControl.js", "Frontend");
        }
    }
}
