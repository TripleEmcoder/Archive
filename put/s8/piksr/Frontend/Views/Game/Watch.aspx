<%@ Page Title="" Language="C#" MasterPageFile="~/Views/Shared/Site.Master" Inherits="System.Web.Mvc.ViewPage" %>

<%@ Import Namespace="Logic" %>
<asp:Content ID="Content1" ContentPlaceHolderID="TitleContent" runat="server">
    <% Game game = (Game)ViewData["game"]; %>
    <%= game.Title %>
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <% string userNick = (string)ViewData["userNick"]; %>
    <% Game game = (Game)ViewData["game"]; %>

    <script type="text/javascript">

        var userNick = "<%= userNick %>";

        var gameTitle =  "<%= game.Title %>";
        var boardWidth = <%= game.BoardWidth %>;
        var boardHeight = <%= game.BoardHeight %>;
                    
        var fieldSize = 50;
        var lineSize = 2;
        var maxFrequency = 1;
        var backgroundStyle = "white";
        var lineStyle = "black";
        var activeColor = "green";
        var inactiveColor = "red";
        var maxPlayerCount = 8;
        
        var players = new Array();
        
        var playerId = 0;
        var nextEvent = <%= game.NextEvent %>;
        var allowMove = <%= game.AllowMove(userNick) ? "true" : "false" %>;
        var winner = <%= game.Winner != null ? string.Format("\"{0}\"", game.Winner) : "\"\"" %>;
        
        var fields = new Array(); 
        for (var index = 0; index < boardWidth; index++)
            fields[index] = Array();
        
        var images = new Array();
        for (var index = 0; index < maxPlayerCount; index++)
        {
            images[index] = new Image();
            images[index].src = "<%= Url.Content("~/Content/Symbols/") %>" + index + ".png";
        }        
    
        function toX(x, x1, x2) {
            return (x + x1) * lineSize + (x + x2) * fieldSize;
        }
    
        function toY(y, y1, y2) {
            return (y + y1) * lineSize + (y + y2) * fieldSize;
        }
    
        function fromX(x) {
            return Math.floor(x / (lineSize + fieldSize));
        }
        
        function fromY(y) {
            return Math.floor(y / (lineSize + fieldSize));
        }
    
        function getRelativePosition(object, event) {
                        
            var x = event.clientX + (window.pageXOffset || 0);
            var y = event.clientY + (window.pageYOffset || 0);
            
            do
	            x -= object.offsetLeft + parseInt(object.style.borderLeftWidth || 0),
	            y -= object.offsetTop + parseInt(object.style.borderTopWidth || 0);
            while (object = object.offsetParent);
            
            return {x:x, y:y};
        }
    
        function prepareBoard() {
            
            var board = $("#board")[0];
            board.width = boardWidth * fieldSize + (boardWidth - 1) * lineSize;
            board.height = boardHeight * fieldSize + (boardHeight - 1) * lineSize;
            board.style.border = 2*lineSize + "px solid black";
            
            var context = board.getContext("2d");            
            context.fillStyle = backgroundStyle;
            context.fillRect(0, 0, board.width, board.height);
            
            context.fillStyle = lineStyle;   
            
            for (var y = 0; y < boardHeight - 1; y++)
                context.fillRect(0, toY(y, 0, 1), board.width, lineSize);
                
            for (var x = 0; x < boardWidth - 1 ; x++)
                context.fillRect(toX(x, 0, 1), 0, lineSize, board.height);
                
            $("#board").click(function(event) { 
                event = getRelativePosition(board, event);
                makeMove(fromX(event.x), fromY(event.y));
            });
            
            /*
            board.onclick = function(e) { 
                e = getRelativePosition(board, e);
                makeMove(fromX(e.x), fromY(e.y));
            }
            */
            
            updateState(null);
        }
        
        function makeMove(x, y) {
            if (allowMove && fields[x][y] == undefined) {
                postMove(x, y);
            }
        }
        
        function plotMoves(moves) {     
            
            var context = $("#board")[0].getContext("2d");
                      
            for (var index = 0; index < moves.length; index++)
            {
                var when = moves[index].When;
                when = new Date(parseInt(when.substring(6, when.length-2)));
                
                var who = moves[index].Who;
                
                if (players[who] == undefined)
                    players[who] = playerId++;              
                
                var x = moves[index].X;
                var y = moves[index].Y;
                
                fields[x][y] = players[who];                
                
                context.drawImage(images[players[who]], toX(x, 0, 0), toY(y, 0, 0), fieldSize, fieldSize);
                
                $("#history").prepend("<tr><td>" + when + "</td><td>" + who + "</td><td>" + x + "</td><td>" + y + "</td></tr>");
            }
        }
        
         function updateState(data) {
            
            if (data != null)
            {
                plotMoves(data.RecentMoves);
                nextEvent = data.NextEvent;
                allowMove = data.AllowMove;
                $("#playerCount").html(data.PlayerCount);
                winner = data.Winner;
                $("#winner").html(data.Winner);
            }
            
            $("#board").css({ borderColor: allowMove ? activeColor : inactiveColor});
        }
        
        function postMove(x, y) {
            $.post(
                '<%= Url.Action("Move") %>',
                { gameTitle: gameTitle, firstEvent: nextEvent, x: x, y: y },
                function(data) { 
                    updateState(data);
                    if (!allowMove && winner == null)
                        setTimeout(waitMove, 1.0 / maxFrequency * 1000); 
                },
                "json");
        }
        
        function waitMove() {
            $.post(
                '<%= Url.Action("Wait") %>',
                 { gameTitle: gameTitle, firstEvent: nextEvent },
                function(data) { 
                    updateState(data);
                    if (!allowMove && winner == null)
                        setTimeout(waitMove, 1.0 / maxFrequency * 1000); 
                },
                "json");
        }
        
        $(document).ready(prepareBoard);
        $(document).ready(waitMove);
    </script>

    <h2>
        <%= game.Title %>
    </h2>
    <p>
        Gracze: <span id="playerCount">
            <%= game.PlayerCount %></span> /
        <%= game.MaxPlayerCount %></p>
    </p>
    <p>
        Zwyciêzca: <span id="winner">
            <%= game.Winner ?? "brak" %></span>
    </p>
    <table>
        <tr>
            <td valign="top">
                <canvas id="board">
                    </canvas>
            </td>
            <td valign="top">
                <table id="history">
                    <thead>
                        <tr>
                            <th>
                                Kiedy
                            </th>
                            <th>
                                Kto
                            </th>
                            <th>
                                X
                            </th>
                            <th>
                                Y
                            </th>
                        </tr>
                    </thead>
                    <tbody>
                    </tbody>
                </table>
            </td>
        </tr>
    </table>
</asp:Content>
