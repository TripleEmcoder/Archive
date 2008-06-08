<%-- 
    Document   : ProductList
    Created on : 2008-06-07, 21:44:23
    Author     : Marcin
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Shop - Products for '${name}'</title>
        <link rel="Stylesheet" href="Style.css">
    </head>
    <body>
        <%@include file="WEB-INF/jspf/Header.jspf" %>
        <div id='content'>
            <h1>Search</h1>
            
            <form action="" method="get">
                <p>
                    <input type="text" name="Name" value="${name}">
                    <input type="submit" value="Search">
                </p>
            </form>            
            
            <p>${result.productCount} product(s) found.</p>
            
            <c:if test="${result.productCount > 0}">
                <table>
                    <tr>
                        <th>Name</th>
                        <th></th>
                    </tr>
                    <c:forEach var="product" items="${result.products}">
                        <tr>
                            <td>${product.name}</td>
                            <td><a href="ProductInfo?Id=${product.id}">Details</a></td>
                        </tr>
                    </c:forEach>
                </table>
            </c:if>
        </div>
        <%@include file="WEB-INF/jspf/Footer.jspf" %>
    </body>
</html>
