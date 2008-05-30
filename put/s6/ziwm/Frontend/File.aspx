<%@ Page
    Language="C#"
    MasterPageFile="~/Web.master"
    AutoEventWireup="true"
    CodeBehind="File.aspx.cs"
    Inherits="Frontend.FilePage"
    Title="Untitled Page" %>
<%@ Register
    TagPrefix="ziwm"
    Namespace="Frontend"
    Assembly="Frontend" %>
<asp:Content
    ID="HeadContent"
    runat="server"
    ContentPlaceHolderID="HeadContentPlaceHolder">
    <script
        type="text/javascript"
        src="Web.config.js"></script>
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
    <div
        id="toolbar">
        <button
            id="drawPolylineButton"
            type="button">?</button>
        <button
            id="drawPolygonButton"
            type="button">?</button>
    </div>
    <asp:Panel ID="ImagePanel" runat="server">
    </asp:Panel>
    <ziwm:VirtualEarthExtenderControl runat="server" TargetControlID="ImagePanel" ID="ImageVirtualEarthExtenderControl" />
</asp:Content>
