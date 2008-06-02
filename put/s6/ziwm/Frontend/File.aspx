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
        StartText="Start Pushpin"
        StopText="Stop Pushpin" />
    <Utility:ToggleButtonExtenderControl
        ID="PolylineToggleButtonExtenderControl"
        runat="server"
        TargetControlID="PolylineButton"
        StartText="Start Polyline"
        StopText="Stop Polyline" />
    <Utility:ToggleButtonExtenderControl
        ID="PolygonToggleButtonExtenderControl"
        runat="server"
        TargetControlID="PolygonButton"
        StartText="Start Polygon"
        StopText="Stop Polygon" />
    <Utility:VirtualEarthExtenderControl
        runat="server"
        TargetControlID="ImagePanel"
        ID="ImageVirtualEarthExtenderControl" />
    <Frontend:AnnotationListExtenderControl
        ID="AnnotationListExtenderControl"
        runat="server"
        TargetControlID="AnnotationList" />
    <table
        class="layout">
        <tr>
            <td
                style="width: 350px;">
                <h2>
                    Tools
                </h2>
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
                <h2>
                    Annotations
                </h2>
                <table
                    id="AnnotationList"
                    runat="server"
                    class="table"
                    style="display: none">
                </table>
                <table
                    id="AnnotationEditor"
                    runat="server"
                    style="display: none">
                    <tr>
                        <td>
                            Title
                        </td>
                        <td>
                            <input
                                id="AnnotationTitleInput"
                                runat="server"
                                width="40" />
                        </td>
                    </tr>
                    <tr>
                        <td>
                            Description
                        </td>
                        <td>
                            <textarea
                                id="AnnotationDescriptionInput"
                                runat="server"
                                cols="25"
                                rows="10" />
                        </td>
                    </tr>
                    <tr>
                        <td>
                        </td>
                        <td>
                            <button
                                id="AnnotationSaveButton"
                                runat="server">
                                <img
                                    src="Images/Save.png" /><br />
                                Save
                            </button>
                            <button
                                id="AnnotationCancelButton"
                                runat="server">
                                <img
                                    src="Images/Cancel.png" /><br />
                                Cancel
                            </button>
                            <button
                                id="AnnotationDeleteButton"
                                runat="server">
                                <img
                                    src="Images/Delete.png" /><br />
                                Delete
                            </button>
                        </td>
                    </tr>
                </table>
            </td>
            <td>
                <h2>
                    Image
                </h2>
                <div
                    id="ImagePanel"
                    runat="server"
                    class="map">
                </div>
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
