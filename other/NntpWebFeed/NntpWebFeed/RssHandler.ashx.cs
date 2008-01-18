using System;
using System.Data;
using System.Web;
using System.Collections;

using System.Xml;

using NntpClientLib;

namespace NntpWebFeed
{
    public class RssHandler : IHttpHandler
    {
        public void ProcessRequest(HttpContext context)
        {
            string[] path = context.Request.Path.Split('/');
            string server = path[1];
            string group = path[2];
            int days = int.Parse(context.Request.QueryString["days"]);

            using (Rfc977NntpClientWithExtensions nntp = new Rfc977NntpClientWithExtensions())
            {
                nntp.Connect(server);
                nntp.SelectNewsgroup(group);

                using (XmlWriter rss = XmlWriter.Create(context.Response.Output))
                {
                    rss.WriteStartDocument();
                    rss.WriteStartElement("rss");
                    rss.WriteAttributeString("version", "2.0");
                    {
                        rss.WriteStartElement("channel");
                        rss.WriteElementString("title", "aa");

                        ArticleBodyTextCollection body = new ArticleBodyTextCollection();
                        ArticleHeadersDictionary headers = new ArticleHeadersDictionary();
                        nntp.RetrieveArticle(nntp.CurrentGroup.LastArticleId, headers, body);                        
                        
                        while(true)
                        {
                            DateTime date = DateTime.Parse(headers["Date"][0]);
                            
                            if (DateTime.Now - date > TimeSpan.FromDays(days))
                                break;

                            rss.WriteStartElement("item");
                            rss.WriteElementString("title", headers["Subject"][0]);
                            rss.WriteElementString("description", body[0]);
                            rss.WriteEndElement();
                            
                            ArticleResponseIds ids = nntp.SetPreviousArticle();
                            
                            if (ids == null)
                                break;

                            headers.Clear();
                            body.Clear();
                            nntp.RetrieveArticle(headers, body);
                        }

                        rss.WriteEndElement();
                    }
                    rss.WriteEndElement();
                    rss.WriteEndDocument();
                }
            }
        }

        public bool IsReusable
        {
            get { return true; }
        }
    }
}
