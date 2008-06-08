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
        <title>Shop - Cart</title>
        <link rel="Stylesheet" href="Style.css">
    </head>
    <body>
        <%@include file="WEB-INF/jspf/Header.jspf" %>
        <div id='content'>
            <h1>Cart</h1>
            <h2>Temporary</h2>
            ${temporaryCart.productCount} item(s) in cart, worth in total ${temporaryCart.productValue}.
            <c:if test="${temporaryCart.productCount > 0}">
                <table>
                    <tr>
                        <th>Name</th>
                        <th></th>
                    </tr>
                    <c:forEach var="product" items="${temporaryCart.products}">
                        <tr>
                            <td>
                                <a href="ProductInfo?Id=${product.id}">${product.name}</a>
                            </td>
                            <td>
                                <ul>
                                    <li><a href="Cart?Operation=RemoveFromTemporary&amp;ProductId=${product.id}">Remove From Temporary Cart</a></li>
                                    <li><a href="Cart?Operation=AddToPernament&amp;ProductId=${product.id}">Move To Pernament Cart</a></li>
                                </ul>
                            </td>
                        </tr>
                    </c:forEach>
                </table>      
            </c:if>
            
            <h2>Pernament</h2>
            ${pernamentCart.productCount} item(s) in cart, worth in total ${pernamentCart.productValue}.
            <c:if test="${pernamentCart.productCount > 0}">
                <table>
                    <tr>
                        <th>Name</th>
                        <th></th>
                    </tr>
                    <c:forEach var="product" items="${pernamentCart.products}">
                        <tr>
                            <td>
                                <a href="ProductInfo?Id=${product.id}">${product.name}</a>
                            </td>
                            <td>
                                <ul>
                                    <li><a href="Cart?Operation=AddToTemporary&amp;ProductId=${product.id}">Move To Temporary Cart</a></li>
                                    <li><a href="Cart?Operation=RemoveFromPernament&amp;ProductId=${product.id}">Remove From Pernament Cart</a></li>
                                </ul>
                            </td>
                        </tr>
                    </c:forEach>
                </table>      
            </c:if>
        </div>
        <%@include file="WEB-INF/jspf/Footer.jspf" %>
    </body>
</html>
