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
        ID="PushpinToggleButtonExtenderControl"
        runat="server"
        TargetControlID="PushpinButton"
        StartText="Start Drawing Pushpin"
        StopText="Stop Drawing Pushpin" />
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
        TargetControlID="ImagePanel"
        ID="ImageVirtualEarthExtenderControl" />
    <Frontend:AnnotationListExtenderControl
        ID="AnnotationListExtenderControl"
        runat="server"
        TargetControlID="AnnotationList" />
    <div
        id="ToolbarPanel"
        runat="server">
        <button
            id="PushpinButton"
            runat="server">
        </button>
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
        id="ImagePanel"
        runat="server"
        style="position: relative">
    </div>
    <table
        id="AnnotationList"
        runat="server">
    </table>
    <table
        id="AnnotationEditor"
        runat="server">
        <tr>
            <td>
                Title
            </td>
            <td>
                <input
                    id="AnnotationTitleInput"
                    runat="server" />
            </td>
        </tr>
        <tr>
            <td>
                Description
            </td>
            <td>
                <textarea
                    id="AnnotationDescriptionInput"
                    runat="server" />
            </td>
        </tr>
        <tr>
            <td>
            </td>
            <td>
                <button
                    id="AnnotationSaveButton"
                    runat="server">
                    Save
                </button>
                <button
                    id="AnnotationCancelButton"
                    runat="server">
                    Cancel
                </button>
                &nbsp;&nbsp;
                <button
                    id="AnnotationDeleteButton"
                    runat="server">
                    Delete
                </button>
            </td>
        </tr>
    </table>
    <script
        type="text/javascript">
            var imagePanelId = "<%= ImagePanel.ClientID %>"; 
            var pushpinToggleButtonId = "<%= PushpinButton.ClientID %>"; 
            var polylineToggleButtonId = "<%= PolylineButton.ClientID %>"; 
            var polygonToggleButtonId = "<%= PolygonButton.ClientID %>";
            var annotationListId = "<%= AnnotationList.ClientID %>";
            var annotationEditorId = "<%= AnnotationEditor.ClientID %>";
            var annotationTitleInputId = "<%= AnnotationTitleInput.ClientID %>";
            var annotationDescriptionInputId = "<%= AnnotationDescriptionInput.ClientID %>";
            var annotationSaveButtonId = "<%= AnnotationSaveButton.ClientID %>";
            var annotationCancelButtonId = "<%= AnnotationCancelButton.ClientID %>";
            var annotationDeleteButtonId = "<%= AnnotationDeleteButton.ClientID %>";
    </script>
</asp:Content>
