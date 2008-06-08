/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.put.inf75922.s6.ai.shop.servlets;

import java.io.IOException;
import javax.persistence.EntityManager;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import pl.put.inf75922.s6.ai.shop.CartManager;
import pl.put.inf75922.s6.ai.shop.beans.ProductListBean;
import pl.put.inf75922.s6.ai.shop.entities.Product;

/**
 *
 * @author Marcin
 */
public class CartServlet extends ShopServlet {

    /** 
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code> methods.
     * @param request servlet request
     * @param response servlet response
     */
    protected void processRequest(EntityManager manager, HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        try {
            String operation = request.getParameter("Operation");
            
            CartManager temporaryCart = new CartManager(request.getSession(), "temporary");
            CartManager pernamentCart = new CartManager(request.getSession(), "pernament");

            if (operation != null && !operation.equals("Show")) {
                int productId = Integer.parseInt(request.getParameter("ProductId"));
                Product product = manager.getReference(Product.class, productId);

                if (operation.equals("AddToTemporary")) {
                    pernamentCart.removeProduct(product);
                    temporaryCart.addProduct(product);
                } else if (operation.equals("RemoveFromTemporary")) {
                    temporaryCart.removeProduct(product);
                } else if (operation.equals("AddToPernament")) {
                    temporaryCart.removeProduct(product);
                    pernamentCart.addProduct(product);
                } else if (operation.equals("RemoveFromPernament")) {
                    pernamentCart.removeProduct(product);
                }

                response.sendRedirect(response.encodeRedirectURL("Cart"));
                return;
            }

            request.setAttribute("temporaryCart", new ProductListBean(temporaryCart.getProducts(manager)));
            request.setAttribute("pernamentCart", new ProductListBean(pernamentCart.getProducts(manager)));

            ServletContext context = this.getServletContext();
            RequestDispatcher dispatcher = context.getRequestDispatcher("/Cart.jsp");
            dispatcher.forward(request, response);

        } catch (Exception ex) {
            throw new ServletException(ex);
        }
    }
}
