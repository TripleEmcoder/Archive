<%@ Page Title="" Language="C#" MasterPageFile="~/Views/Shared/Site.Master" Inherits="System.Web.Mvc.ViewPage" %>

<%@ Import Namespace="Logic" %>
<asp:Content ID="Content1" ContentPlaceHolderID="TitleContent" runat="server">
    <% Game game = (Game)ViewData["game"]; %>
    Watch:
    <%= game.Title %>
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <% string userNick = (string)ViewData["userNick"]; %>
    <% Game game = (Game)ViewData["game"]; %>

    <script type="text/javascript">

        var userNick = "<%= userNick %>";

        var game = {
            title: "<%= game.Title %>",
            boardWidth: <%= game.BoardWidth %>,
            boardHeight: <%= game.BoardHeight %>
        };
        
        var players = new Array();
        var playerId = 0;
    
        var fieldSize = 100;
        var lineSize = 5;
        var maxFrequency = 1;
        var backgroundStyle = "pink";
        var lineStyle = "black";
    
        var maxPlayerCount = 9;
        
        var images = new Array();
        for (var index = 0; index < maxPlayerCount; index++)
        {
            images[index] = new Image();
            images[index].src = "<%= Url.Content("~/Content/Symbols/") %>" + index + ".png";
        }
        
    
        function getX(x, x1, x2) {
            return (x + x1) * lineSize + (x + x2) * fieldSize;
        }
    
        function getY(y, y1, y2) {
            return (y + y1) * lineSize + (y + y2) * fieldSize;
        }
    
        function prepareBoard() {
            
            var board = $("#board")[0];
            board.width = game.boardWidth * fieldSize + (game.boardWidth - 1) * lineSize;
            board.height = game.boardHeight * fieldSize + (game.boardHeight - 1) * lineSize;
            
            var context = board.getContext("2d");            
            context.fillStyle = backgroundStyle;
            context.fillRect(0, 0, board.width, board.height);
            
            context.fillStyle = lineStyle;   
            
            for (var y = 0; y < game.boardHeight - 1; y++)
                context.fillRect(0, getY(y, 0, 1), board.width, lineSize);
                
            for (var x = 0; x < game.boardWidth - 1 ; x++)
                context.fillRect(getX(x, 0, 1), 0, lineSize, board.height);
        }
        
        function plotMove(data) {     
            
            var context = $("#board")[0].getContext("2d");
                      
            for (var index = 0; index < data.moves.length; index++)
            {
                context.textAlign = "center";
                context.textBaseline = "middle";
                 
                var userNick = data.moves[index].UserNick;
                
                if (players[userNick] == undefined)
                    players[userNick] = playerId++;              
                
                var x = getX(data.moves[index].X, 0, 0);
                var y = getY(data.moves[index].Y, 0, 0);                    
                context.drawImage(images[players[userNick]], x, y, fieldSize, fieldSize);
            }
            
            setTimeout(function() { waitMove(data.firstIndex + data.moves.length); }, 1.0 / maxFrequency * 1000);
        }
        
        function waitMove(firstIndex) {
            $.post('<%= Url.Action("WaitMove") %>', { gameTitle: game.title, firstIndex: firstIndex }, plotMove, "json");
        }
        
        $(document).ready(prepareBoard);
        $(document).ready(function() { waitMove(0); });
    </script>

    <h2>
        Watch:
        <%= game.Title %>
    </h2>
    <canvas id="board">
    </canvas>
</asp:Content>
