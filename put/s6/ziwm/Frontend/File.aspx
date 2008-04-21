<%@ Page
    Language="C#"
    MasterPageFile="~/Web.master"
    AutoEventWireup="true"
    CodeBehind="File.aspx.cs"
    Inherits="Frontend.File"
    Title="Untitled Page" %>

<asp:Content
    ID="HeadContent"
    runat="server"
    ContentPlaceHolderID="HeadContentPlaceHolder">

    <script
        type="text/javascript"
        src="Map.js"></script>

    <script
        type="text/javascript">      
    </script>

</asp:Content>
<asp:Content
    ID="MainContent"
    ContentPlaceHolderID="MainContentPlaceHolder"
    runat="server">
    <asp:SiteMapPath
        ID="SiteMapPath"
        runat="server" />
    <div
        id='myMap'
        style="position: relative;
        width: 400px;
        height: 400px;">
    </div>

    <script
        type="text/javascript">
 var map = new VEMap('myMap');
 map.LoadMap(); 
    </script>

</asp:Content>
