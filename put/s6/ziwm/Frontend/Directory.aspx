<%@ Page
    Language="C#"
    MasterPageFile="~/Web.master"
    AutoEventWireup="true"
    CodeBehind="Directory.aspx.cs"
    Inherits="Frontend.Directory"
    Title="Untitled Page" %>

<asp:Content
    ID="MainContent"
    ContentPlaceHolderID="MainContentPlaceHolder"
    runat="server">
    <asp:SiteMapPath
        ID="SiteMapPath"
        runat="server" />
    <asp:SiteMapDataSource
        ID="SiteMapDataSource"
        runat="server"
        ShowStartingNode="False"
        StartFromCurrentNode="True" />
    <asp:TreeView
        ID="SiteMapTreeView"
        runat="server"
        DataSourceID="SiteMapDataSource"
        ExpandDepth="0"
        MaxDataBindDepth="0" />
</asp:Content>
