/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.put.inf75922.s6.ai.shop.servlets;

import java.io.IOException;
import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import pl.put.inf75922.s6.ai.shop.SecurityManager;
import pl.put.inf75922.s6.ai.shop.entities.User;

/**
 *
 * @author Marcin
 */
public abstract class ShopServlet extends HttpServlet {

    /**
     *
     * Handles the HTTP <code>GET</code> method.
     * @param request servlet request
     * @param response servlet response
     */
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     *
     * Handles the HTTP <code>POST</code> method.
     * @param request servlet request
     * @param response servlet response
     */
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     *
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code> methods.
     * @param request servlet request
     * @param response servlet response
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
        EntityManagerFactory factory = Persistence.createEntityManagerFactory("Shop");
        EntityManager manager = factory.createEntityManager();
        User user = SecurityManager.getUser(request.getSession(), manager);
        request.setAttribute("user", user);

        processRequest(manager, request, response);
    }

    protected abstract void processRequest(EntityManager manager, HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException;
}
