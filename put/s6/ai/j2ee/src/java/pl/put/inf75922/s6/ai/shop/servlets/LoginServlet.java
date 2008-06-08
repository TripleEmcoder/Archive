/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.put.inf75922.s6.ai.shop.servlets;

import java.io.IOException;
import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;
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
public class LoginServlet extends ShopServlet {

    /** 
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code> methods.
     * @param request servlet request
     * @param response servlet response
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        try {
            String login = request.getParameter("Login");
            String password = request.getParameter("Password");

            EntityManagerFactory factory = Persistence.createEntityManagerFactory("Shop");
            EntityManager manager = factory.createEntityManager();

            ServletContext context = this.getServletContext();
            RequestDispatcher dispatcher = context.getRequestDispatcher("/Login.jsp");
            dispatcher.forward(request, response);

        } catch (Exception ex) {
            throw new ServletException(ex);
        }
    }
}
