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
    <form>
        <input type="text" name="Name" value="${name}">
        <input type="submit" value="Search">            
    </form>
    ${result.productCount}
    <c:if test="${result.productCount > 0}">
    <ul>
        <c:forEach var="product" items="${result.products}">
          <li><a href="ProductInfo?Id=${product.id}">${product.name}</a></li>       
        </c:forEach>
        </ul>        
    </c:if>
    <%@include file="WEB-INF/jspf/Footer.jspf" %>
</body>
</html>
