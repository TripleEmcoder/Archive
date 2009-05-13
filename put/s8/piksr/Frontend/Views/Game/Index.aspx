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
        <% 
            using (Html.BeginForm("Create", "Game"))
            {
        %>
        Nowa gra:<br />
        Nazwa: <input type="text" name="gameTitle" size="20" /><br />
        Gracze: <input type="text"name="maxPlayerCount" size="2" value="2" /><br />
        Rozmiar: <input type="text"name="boardSize" size="2" value="3" /><br />
        Wygrana: <input type="text"name="winningFieldCount" size="2" value="3" /><br />
        <input type="submit" value="Dodaj" />
        <%
            }
        %>
    </p>
    <table>
        <tr>
            <th>
                Nazwa
            </th>
            <th>
                Rozmiar
            </th>
            <th>
                Gracze
            </th>
            <th>
                Wygrana
            </th>
            <th>
                Akcje
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
                <%= game.BoardWidth %>
                x
                <%= game.BoardHeight %>
            </td>
            <td>
                <%= game.PlayerCount %>
                /
                <%= game.MaxPlayerCount %>
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
                        if (game.PlayerCount != game.MaxPlayerCount)
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
