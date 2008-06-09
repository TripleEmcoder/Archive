<%-- 
    Document   : Login
    Created on : 2008-06-08, 17:32:55
    Author     : Marcin
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page isErrorPage="true" %>
<%@page import="java.io.PrintWriter"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Shop - Error</title>
        <link rel="Stylesheet" href="Style.css">
    </head>
    <body>
        <%@include file="WEB-INF/jspf/Header.jspf" %>
        <div id='content'>
            <h1>Error</h1>
            <p>An error has occured while contacting the database. Please try again later. If the problem persists please contact the site's administrator.</p>
            <pre>
            <% exception.printStackTrace(new PrintWriter(out)); %>
            </pre>
        </div>
        <%@include file="WEB-INF/jspf/Footer.jspf" %>
    </body>
</html>
