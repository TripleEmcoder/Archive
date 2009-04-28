<%@ Page Language="C#" MasterPageFile="~/Views/Shared/Site.Master" Inherits="System.Web.Mvc.ViewPage" %>

<%@ Import Namespace="Logic" %>
<asp:Content ID="indexTitle" ContentPlaceHolderID="TitleContent" runat="server">
    Home Page
</asp:Content>
<asp:Content ID="indexContent" ContentPlaceHolderID="MainContent" runat="server">
    <% string userNick = (string)ViewData["userNick"]; %>
    <% IEnumerable<Game> games = (IEnumerable<Game>)ViewData["games"]; %>
    <h2>
        <%= Html.Encode(ViewData["Message"]) %></h2>
    <p>
        To learn more about ASP.NET MVC visit <a href="http://asp.net/mvc" title="ASP.NET MVC Website">
            http://asp.net/mvc</a>.
    </p>
    <table>
        <tr>
            <th>
                Name
            </th>
            <th>
                Actions
            </th>
        </tr>
        <%
            foreach (Game game in games)
            {
        %>
        <tr>
            <td>
                <%= game.Title %>
            </td>
            <td>
                <ul>
                    <% 
                        if (game.CanJoin(userNick))
                        {
                    %>
                    <li>
                        <%= Html.ActionLink("View", "View", new { gameTitle = game.Title }) %>
                    </li>
                    <% 
                        if (!game.IsFull)
                        {
                    %>
                    <li>
                        <%= Html.ActionLink("Join", "Join", new { gameTitle = game.Title })%>
                    </li>
                    <%
                        }
                    %>
                    <%
                        }
                        else
                        {
                    %>
                    <li>
                        <%= Html.ActionLink("Play", "View", new { gameTitle = game.Title }) %>
                    </li>
                    <li>
                        <%= Html.ActionLink("Exit", "Exit", new { gameTitle = game.Title }) %>
                    </li>
                    <%
                        }
                    %>
                </ul>
            </td>
        </tr>
        <%
            }
        %>
    </table>
</asp:Content>
