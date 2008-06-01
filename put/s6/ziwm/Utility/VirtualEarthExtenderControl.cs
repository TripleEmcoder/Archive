using System.Collections.Generic;
using System.ComponentModel;
using System.Web.UI;
using System.Web.UI.HtmlControls;

[assembly: WebResource("Utility.VirtualEarthApi.js", "application/x-javascript")]
[assembly: WebResource("Utility.VirtualEarthClientControl.js", "application/x-javascript")]

namespace Utility
{
    [TargetControlType(typeof(HtmlGenericControl))]
    [Designer(typeof(VirtualEarthExtenderControlDesigner))]
    public class VirtualEarthExtenderControl : ExtenderControl
    {
        private T GetViewStateValue<T>(string name, T value)
        {
            return ViewState[name] != null ? (T)ViewState[name] : value;
        }

        public double InitialLatitude
        {
            get { return GetViewStateValue<double>("InitialLatitude", 0); }
            set { ViewState["InitialLatitude"] = value; }
        }

        public double InitialLongitude
        {
            get { return GetViewStateValue<double>("InitialLongitude", 0); }
            set { ViewState["InitialLongitude"] = value; }
        }

        public double InitialZoomLevel
        {
            get { return GetViewStateValue<double>("ZoomLevel", 0); }
            set { ViewState["ZoomLevel"] = value; }
        }

        protected override IEnumerable<ScriptDescriptor> GetScriptDescriptors(Control targetControl)
        {
            ScriptControlDescriptor descriptor = new
                ScriptControlDescriptor("Utility.VirtualEarthClientControl", targetControl.ClientID);

            descriptor.AddProperty("initialLatitude", InitialLatitude);
            descriptor.AddProperty("initialLongitude", InitialLongitude);
            descriptor.AddProperty("initialZoomLevel", InitialZoomLevel);

            yield return descriptor;
        }

        protected override IEnumerable<ScriptReference> GetScriptReferences()
        {
            yield return new ScriptReference("Utility.VirtualEarthApi.js", "Utility");
            yield return new ScriptReference("Utility.VirtualEarthClientControl.js", "Utility");
        }
    }
}