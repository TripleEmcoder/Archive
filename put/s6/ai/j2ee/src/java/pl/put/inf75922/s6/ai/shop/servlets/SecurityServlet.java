/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.put.inf75922.s6.ai.shop.servlets;

import java.io.IOException;
import javax.persistence.EntityManager;
import javax.persistence.NoResultException;
import javax.persistence.Query;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import pl.put.inf75922.s6.ai.shop.SecurityManager;
import pl.put.inf75922.s6.ai.shop.entities.User;

/**
 *
 * @author Marcin
 */
public class SecurityServlet extends ShopServlet {

    /** 
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code> methods.
     * @param request servlet request
     * @param response servlet response
     */
    protected void processRequest(EntityManager manager, HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        try {
            if (request.getRequestURI().contains("Login")) {

                String login = request.getParameter("Login");
                String password = request.getParameter("Password");
                String redirect = request.getParameter("Redirect");

                if (redirect == null) {
                    redirect = request.getHeader("referer");
                }

                if (redirect == null) {
                    redirect = "Cart";
                }

                if (login != null || password != null) {

                    Query query = manager.createNamedQuery("GetUserByLoginAndPassword");
                    query.setParameter("login", login);
                    query.setParameter("password", password);

                    try {
                        User user = (User) query.getSingleResult();
                        SecurityManager.setUser(request.getSession(), manager, user);
                        response.sendRedirect(response.encodeRedirectURL(redirect));
                        return;
                    } catch (NoResultException ex) {
                        request.setAttribute("error", "Bad login and/or password.");
                    }
                }

                request.setAttribute("login", login);
                request.setAttribute("redirect", redirect);

                ServletContext context = this.getServletContext();
                RequestDispatcher dispatcher = context.getRequestDispatcher("/Login.jsp");
                dispatcher.forward(request, response);

            } else if (request.getRequestURI().contains("Logout")) {

                SecurityManager.setUser(request.getSession(), manager, null);
                String redirect = request.getHeader("referer");
                response.sendRedirect(response.encodeRedirectURL(redirect));
            }

        } catch (Exception ex) {
            throw new ServletException(ex);
        }
    }
}
