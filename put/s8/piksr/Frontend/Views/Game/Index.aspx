<%@ Page Language="C#" MasterPageFile="~/Views/Shared/Site.Master" Inherits="System.Web.Mvc.ViewPage" %>

<%@ Import Namespace="Logic" %>
<asp:Content ID="indexTitle" ContentPlaceHolderID="TitleContent" runat="server">
    Index
</asp:Content>
<asp:Content ID="indexContent" ContentPlaceHolderID="MainContent" runat="server">
    <% string userNick = (string)ViewData["userNick"]; %>
    <% IEnumerable<Game> games = (IEnumerable<Game>)ViewData["games"]; %>
    <h2>
        Index
    </h2>
    <p>
        Twój nick:
        <%= userNick %>
    </p>
    <p>
        <% 
            using (Html.BeginForm("Create", "Game"))
            {
        %>
        Nowa gra:
        <%= Html.TextBox("gameTitle") %>
        <input type="submit" value="Dodaj" />
        <%
            }
        %>
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
                        <%= Html.ActionLink("Watch", "Watch", new { gameTitle = game.Title })%>
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
                        <%= Html.ActionLink("Play", "Play", new { gameTitle = game.Title }) %>
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
