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
        <title>ProductInfo - ${product.name}</title>
    </head>
    <body>
        <%@include file="WEB-INF/jspf/Header.jspf" %>
        <h2>${product.name}</h2>
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
        <c:choose>
            <c:when test="${cartName == ''}">
                <a href="Cart?Operation=AddToTemporary&amp;ProductId=${product.id}">Add To Temporary Cart</a>
                <a href="Cart?Operation=AddToPernament&amp;ProductId=${product.id}">Add To Pernament Cart</a>
            </c:when>
            <c:when test="${cartName == 'temporary'}">
                <a href="Cart?Operation=RemoveFromTemporary&amp;ProductId=${product.id}">Remove From Temporary Cart</a>
                <a href="Cart?Operation=AddToPernament&amp;ProductId=${product.id}">Move To Pernament Cart</a>
            </c:when>
            <c:when test="${cartName == 'pernament'}">
                <a href="Cart?Operation=AddToTemporary&amp;ProductId=${product.id}">Move To Temporary Cart</a>
                <a href="Cart?Operation=RemoveFromPernament&amp;ProductId=${product.id}">Remove From Pernament Cart</a>
            </c:when>
        </c:choose>
        <%@include file="WEB-INF/jspf/Footer.jspf" %>
    </body>
</html>
