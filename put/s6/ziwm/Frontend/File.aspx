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
        src="Web.config.js"></script>

    <script
        type="text/javascript"
        src="VirtualEarth.js"></script>

    <script
        type="text/javascript"
        src="File.aspx.js"></script>

</asp:Content>
<asp:Content
    ID="MainContent"
    ContentPlaceHolderID="MainContentPlaceHolder"
    runat="server">
    <asp:SiteMapPath
        ID="SiteMapPath"
        runat="server" />
    <div
        id='map'
        style="position: relative;
        width: 600px;
        height: 600px; top: 0px; left: 0px;">
    </div>
    <input type="button" id="drawPolylineButton" />
    <input type="button" id="drawPolygonButton" />
</asp:Content>
