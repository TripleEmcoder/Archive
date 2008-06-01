using System.Collections.Generic;
using System.ComponentModel;
using System.Web.UI;
using System.Web.UI.HtmlControls;

[assembly: WebResource("Utility.ToggleButtonClientControl.js", "application/x-javascript")]

namespace Utility
{
    [TargetControlType(typeof(HtmlButton))]
    [Designer(typeof(ToggleButtonExtenderControlDesigner))]
    public class ToggleButtonExtenderControl : ExtenderControl
    {
        private T GetViewStateValue<T>(string name, T value)
        {
            return ViewState[name] != null ? (T)ViewState[name] : value;
        }

        public string StartText
        {
            get { return GetViewStateValue<string>("StartText", "Start"); }
            set { ViewState["StartText"] = value; }
        }

        public string StopText
        {
            get { return GetViewStateValue<string>("StopText", "Stop"); }
            set { ViewState["StopText"] = value; }
        }

        protected override IEnumerable<ScriptDescriptor> GetScriptDescriptors(Control targetControl)
        {
            ScriptControlDescriptor descriptor = new ScriptControlDescriptor(
                "Utility.ToggleButtonClientControl", targetControl.ClientID);

            descriptor.AddProperty("startText", StartText);
            descriptor.AddProperty("stopText", StopText);

            yield return descriptor;
        }

        protected override IEnumerable<ScriptReference> GetScriptReferences()
        {
            yield return new ScriptReference("Utility.ToggleButtonClientControl.js", "Utility");
        }
    }
}
