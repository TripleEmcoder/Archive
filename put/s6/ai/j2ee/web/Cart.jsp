<%-- 
    Document   : ProductList
    Created on : 2008-06-07, 21:44:23
    Author     : Marcin
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Strict//EN" "http://www.w3.org/TR/html4/strict.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>ProductList - ${name}</title>
    </head>
    <body>
        <%@include file="WEB-INF/jspf/Header.jspf" %>
        <h2>Temporary Cart</h2>
        ${temporaryCart.productCount}
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
                            
                        </td>
                    </tr>
                </c:forEach>
            </table>      
        </c:if>
        
        <h2>Pernament Cart</h2>
        ${pernamentCart.productCount}
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
                            
                        </td>
                    </tr>
                </c:forEach>
            </table>      
        </c:if>

        <%@include file="WEB-INF/jspf/Footer.jspf" %>
    </body>
</html>
