using System;
using System.Web;

namespace Frontend
{
    public class Global : HttpApplication
    {
        protected void Application_Start(object sender, EventArgs e)
        {
            string path = string.Format("{0};{1}",
                Environment.GetEnvironmentVariable("PATH"),
                AppDomain.CurrentDomain.RelativeSearchPath);

            Environment.SetEnvironmentVariable("PATH", path, EnvironmentVariableTarget.Process);
        }

        protected void Session_Start(object sender, EventArgs e)
        {
        }

        protected void Application_BeginRequest(object sender, EventArgs e)
        {
        }

        protected void Application_AuthenticateRequest(object sender, EventArgs e)
        {
        }

        protected void Application_Error(object sender, EventArgs e)
        {
        }

        protected void Session_End(object sender, EventArgs e)
        {
        }

        protected void Application_End(object sender, EventArgs e)
        {
        }
    }
}