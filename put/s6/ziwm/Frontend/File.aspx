<%@ Page
    Language="C#"
    MasterPageFile="~/Web.master"
    AutoEventWireup="true"
    CodeBehind="File.aspx.cs"
    Inherits="Frontend.FilePage"
    Title="Untitled Page" %>
<%@ Register
    Assembly="Frontend"
    Namespace="Frontend"
    TagPrefix="Frontend" %>
<%@ Register
    TagPrefix="Utility"
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
        ID="ScriptManager"
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
    <Utility:ToggleButtonExtenderControl
        ID="PolylineToggleButtonExtenderControl"
        runat="server"
        TargetControlID="PolylineButton"
        StartText="Start Drawing Polyline"
        StopText="Stop Drawing Polyline" />
    <Utility:ToggleButtonExtenderControl
        ID="PolygonToggleButtonExtenderControl"
        runat="server"
        TargetControlID="PolygonButton"
        StartText="Start Drawing Polygon"
        StopText="Stop Drawing Polygon" />
    <Utility:VirtualEarthExtenderControl
        runat="server"
        TargetControlID="Image"
        ID="ImageVirtualEarthExtenderControl" />
    <Frontend:AnnotationTableExtenderControl
        ID="AnnotationTableExtenderControl"
        runat="server"
        TargetControlID="AnnotationTable" />
    <div
        id="Toolbar"
        runat="server">
        <button
            id="PolylineButton"
            runat="server">
        </button>
        <button
            id="PolygonButton"
            runat="server">
        </button>
    </div>
    <div
        id="Image"
        runat="server">
    </div>
    <table
        id="AnnotationTable"
        runat="server">
    </table>
    <div
        id="AnnotationEditor"
        runat="server">
        <input
            id="AnnotationEditorTitleInput"
            runat="server" />
        <button
            id="AnnotationEditorSaveButton"
            runat="server">
            Save
        </button>
        <button
            id="AnnotationEditorCancelButton"
            runat="server">
            Cancel
        </button>
    </div>
    <script
        type="text/javascript">
            var polylineToggleButtonId = "<%= PolylineButton.ClientID %>"; 
            var polygonToggleButtonId = "<%= PolygonButton.ClientID %>";
            var annotationTableId = "<%= AnnotationTable.ClientID %>";
            var annotationEditorId = "<%= AnnotationEditor.ClientID %>";
            var annotationEditorTitleInputId = "<%= AnnotationEditorTitleInput.ClientID %>";
            var annotationEditorSaveButtonId = "<%= AnnotationEditorSaveButton.ClientID %>";
            var annotationEditorCancelButtonId = "<%= AnnotationEditorCancelButton.ClientID %>";
    </script>
</asp:Content>
