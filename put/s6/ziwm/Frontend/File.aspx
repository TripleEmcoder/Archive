<%@ Page
    Language="C#"
    MasterPageFile="~/Web.master"
    AutoEventWireup="true"
    CodeBehind="File.aspx.cs"
    Inherits="Frontend.FilePage"
    Title="Untitled Page" %>
<asp:Content
    ID="HeadContent"
    runat="server"
    ContentPlaceHolderID="HeadContentPlaceHolder">
    <script
        type="text/javascript"
        src="Web.config.js"></script>
<%--    <script
        type="text/javascript"
        src="VirtualEarth.js"></script>--%>
    <script
        type="text/javascript"
        src="File.aspx.js"></script>
</asp:Content>
<asp:Content
    ID="MainContent"
    ContentPlaceHolderID="MainContentPlaceHolder"
    runat="server">
    <asp:ScriptManager
        ID="ScriptManager1"
        runat="server"
        ScriptMode="Auto">
        <Services>
            <asp:ServiceReference
                Path="~/File.asmx" InlineScript="True" />
        </Services>
    </asp:ScriptManager>
    <script type="text/javascript">
    Frontend.FileWebService.AddOrUpdateAnnotation(new Frontend.Annotation(), function(result){alert(result); Frontend.FileWebService.GetAnnotations(function(result){alert(result)}, function(result){alert(result)});}, function(result){alert(result)});

    </script>
    <div
        id="toolbar">
        <button
            id="drawPolylineButton"
            type="button">?</button>
        <button
            id="drawPolygonButton"
            type="button">?</button>
    </div>
    <div
        id="map">
    </div>
</asp:Content>
