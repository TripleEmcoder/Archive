<%@ Page
    Language="C#"
    MasterPageFile="~/Web.master"
    AutoEventWireup="true"
    CodeBehind="File.aspx.cs"
    Inherits="Frontend.FilePage"
    Title="Untitled Page" %>
<%@ Register
    TagPrefix="ziwm"
    Namespace="Utility"
    Assembly="Utility" %>
<asp:Content
    ID="HeadContent"
    runat="server"
    ContentPlaceHolderID="HeadContentPlaceHolder">
</asp:Content>
<asp:Content
    ID="MainContent"
    ContentPlaceHolderID="MainContentPlaceHolder"
    runat="server">
    <asp:ScriptManager
        ID="ScriptManager1"
        runat="server"
        ScriptMode="Auto">
        <Scripts>
            <asp:ScriptReference
                Path="~/Web.config.js" />
            <asp:ScriptReference
                Path="~/File.aspx.js" />
        </Scripts>
        <Services>
            <asp:ServiceReference
                Path="~/File.asmx"
                InlineScript="True" />
        </Services>
    </asp:ScriptManager>
    <div
        id="toolbar">
        <button
            id="PolylineButton"
            runat="server">
        </button>
        <ziwm:ToggleButtonExtenderControl
            ID="PolylineToggleButtonExtenderControl"
            runat="server"
            StartText="Start Drawing Polyline"
            StopText="Stop Drawing Polyline"
            TargetControlID="PolylineButton" />
        <button
            id="PolygonButton"
            runat="server">
        </button>
        <ziwm:ToggleButtonExtenderControl
            ID="PolygonToggleButtonExtenderControl"
            runat="server"
            StartText="Start Drawing Polygon"
            StopText="Stop Drawing Polygon"
            TargetControlID="PolygonButton" />
    </div>
    <asp:Panel
        ID="ImagePanel"
        runat="server">
    </asp:Panel>
    <ziwm:VirtualEarthExtenderControl
        runat="server"
        TargetControlID="ImagePanel"
        ID="ImageVirtualEarthExtenderControl" />
    <script
        type="text/javascript">
            var polylineToggleButtonId = "<%= PolylineButton.ClientID %>"; 
            var polygonToggleButtonId = "<%= PolygonButton.ClientID %>"; 
    </script>
</asp:Content>
