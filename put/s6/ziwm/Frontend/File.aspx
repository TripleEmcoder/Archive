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
            ID="DrawPolylineButton"
            runat="server">
        </button>
        <button
            ID="DrawPolygonButton"
            runat="server">
        </button>
        <button id="drawPolylineButton"></button>
        <ziwm:ToggleButtonExtenderControl ID="DrawPolylineButtonExtenderControl" 
            runat="server" StartText="start" StopText="stop" TargetControlID="DrawPolylineButton" />
    </div>
    <asp:Panel ID="ImagePanel" runat="server">
    </asp:Panel>
    <ziwm:VirtualEarthExtenderControl runat="server" TargetControlID="ImagePanel" ID="ImageVirtualEarthExtenderControl" />
    <script type="text/javascript">   
    function pageLoad() 
    {      
       var drawPolylineButton = $find("<%= DrawPolylineButton.ClientID %>");
       drawPolylineButton.add_start(function(){alert("start");});
       drawPolylineButton.add_stop(function(){alert("stop");});
    }   
</script> 
</asp:Content>
