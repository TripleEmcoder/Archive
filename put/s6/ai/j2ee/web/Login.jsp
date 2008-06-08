<%-- 
    Document   : Login
    Created on : 2008-06-08, 17:32:55
    Author     : Marcin
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Shop - Login</title>
        <link rel="Stylesheet" href="Style.css">
    </head>
    <body>
        <%@include file="WEB-INF/jspf/Header.jspf" %>
        <div id='content'>
            <h1>Login</h1>
            <c:if test="${error != null}">
                <p>${error}</p>
            </c:if>
            <form action="" method="post">
                
                <table>
                    <tr>
                        <th>Login</th>
                        <td><input type="text" name="Login" value="${login}"></td>
                    </tr>
                    <tr>
                        <th>Password</th>
                        <td><input type="password" name="Password"></td>
                    </tr>   
                    <tr>
                        <th></th>
                        <td>
                            <input type="hidden" name="Redirect" value="${redirect}">
                            <input type="submit" value="Submit">
                        </td>
                    </tr>
                </table>
            </form>
        </div>
        <%@include file="WEB-INF/jspf/Footer.jspf" %>
    </body>
</html>
