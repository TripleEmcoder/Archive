<%@ Page
    Language="C#"
    MasterPageFile="~/Web.master"
    AutoEventWireup="true"
    CodeBehind="Default.aspx.cs"
    Inherits="Frontend.DefaultPage"
    Title="Default" %>

<asp:Content
    ID="MainContent"
    ContentPlaceHolderID="MainContentPlaceHolder"
    runat="server">
    <asp:SiteMapPath
        ID="SiteMapPath"
        runat="server" />
    <asp:SiteMapDataSource
        ID="SiteMapDataSource"
        runat="server" />
    <asp:TreeView
        ID="SiteMapTreeView"
        runat="server"
        DataSourceID="SiteMapDataSource"
        ExpandDepth="1">
    </asp:TreeView>
</asp:Content>
