<%@ Page
    Language="C#"
    MasterPageFile="~/Web.master"
    AutoEventWireup="true"
    CodeBehind="Directory.aspx.cs"
    Inherits="Frontend.DirectoryPage"
    Title="Untitled Page" %>
<asp:Content
    ID="MainContent"
    ContentPlaceHolderID="MainContentPlaceHolder"
    runat="server">
    <asp:SiteMapDataSource
        ID="SiteMapDataSource"
        runat="server"
        ShowStartingNode="False"
        StartFromCurrentNode="True" />
    <asp:GridView
        ID="GridView1"
        runat="server"
        AutoGenerateColumns="False"
        DataSourceID="SiteMapDataSource"
        CssClass="table">
        <Columns>
            <asp:HyperLinkField
                DataNavigateUrlFields="Url"
                DataTextField="Title"
                HeaderText="Name" />
            <asp:BoundField
                DataField="Description"
                HeaderText="Description"
                ReadOnly="True"
                SortExpression="Description" />
        </Columns>
    </asp:GridView>
</asp:Content>
