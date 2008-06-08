<%-- 
    Document   : ProductInfo
    Created on : 2008-06-07, 21:44:16
    Author     : Marcin
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Shop - ${product.name}</title>
        <link rel="Stylesheet" href="Style.css">
    </head>
    <body>
        <%@include file="WEB-INF/jspf/Header.jspf" %>
        <div id='content'>
            <h1>${product.name}</h1>
            <table>
                <tr>
                    <th>Category</th>
                    <td>${product.category}</td>
                </tr>
                <tr>
                    <th>Subcategory</th>
                    <td>${product.subcategory}</td>
                </tr>
                <tr>
                    <th>Name</th>
                    <td>${product.name}</td>
                </tr>
                <tr>
                    <th>Price</th>
                    <td>${product.price}</td>
                </tr>
            </table>
            <ul>
            <c:choose>
                <c:when test="${cartName == ''}">
                    <li><a href="Cart?Operation=AddToTemporary&amp;ProductId=${product.id}">Add To Temporary Cart</a></li>
                    <li><a href="Cart?Operation=AddToPernament&amp;ProductId=${product.id}">Add To Pernament Cart</a></li>
                </c:when>
                <c:when test="${cartName == 'temporary'}">
                    <li><a href="Cart?Operation=RemoveFromTemporary&amp;ProductId=${product.id}">Remove From Temporary Cart</a></li>
                    <li><a href="Cart?Operation=AddToPernament&amp;ProductId=${product.id}">Move To Pernament Cart</a></li>
                </c:when>
                <c:when test="${cartName == 'pernament'}">
                    <li><a href="Cart?Operation=AddToTemporary&amp;ProductId=${product.id}">Move To Temporary Cart</a></li>
                    <li><a href="Cart?Operation=RemoveFromPernament&amp;ProductId=${product.id}">Remove From Pernament Cart</a></li>
                </c:when>
            </c:choose>
            </ul>
        </div>
        <%@include file="WEB-INF/jspf/Footer.jspf" %>
    </body>
</html>
