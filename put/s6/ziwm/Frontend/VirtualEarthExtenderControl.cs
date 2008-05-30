using System;
using System.Collections.Generic;
using System.Data;
using System.Configuration;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.HtmlControls;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Xml.Linq;

namespace Frontend
{
    [TargetControlType(typeof(Panel))]
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
                 ScriptControlDescriptor("Frontend.VirtualEarthClientControl", targetControl.ClientID);

            descriptor.AddProperty("initialLatitude", InitialLatitude);
            descriptor.AddProperty("initialLongitude", InitialLongitude);
            descriptor.AddProperty("initialZoomLevel", InitialZoomLevel);

            yield return descriptor;
        }

        protected override IEnumerable<ScriptReference> GetScriptReferences()
        {
            yield return new ScriptReference(Page.ResolveClientUrl("~/VirtualEarthApi.js"));
            yield return new ScriptReference(Page.ResolveClientUrl("~/VirtualEarthClientControl.js"));
        }
    }
}
