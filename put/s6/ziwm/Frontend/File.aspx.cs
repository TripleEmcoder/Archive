using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web;

namespace Frontend
{
    public partial class FilePage : Page
    {
        protected void Page_Load(object sender, System.EventArgs e)
        {
            Title = new SiteMapDataSource().Provider.FindSiteMapNode(HttpContext.Current.Request.Url.PathAndQuery).Title;
        }
    }
}
