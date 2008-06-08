/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.put.inf75922.s6.ai.shop.servlets;

import java.io.IOException;
import javax.persistence.EntityManager;
import javax.persistence.Query;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import pl.put.inf75922.s6.ai.shop.beans.ProductListBean;

/**
 *
 * @author Marcin
 */
public class ProductListServlet extends ShopServlet {

    /** 
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code> methods.
     * @param request servlet request
     * @param response servlet response
     */
    protected void processRequest(EntityManager manager, HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        try {
            String name = request.getParameter("Name");

            if (name == null) {
                name = "";
            }
            
            request.setAttribute("name", name);

            Query query = manager.createNamedQuery("GetProductsByNamePattern");
            query.setParameter("pattern", "%" + escapeLike(name) + "%");
            request.setAttribute("result", new ProductListBean(query.getResultList()));

            ServletContext context = this.getServletContext();
            RequestDispatcher dispatcher = context.getRequestDispatcher("/ProductList.jsp");
            dispatcher.forward(request, response);
        } catch (Exception ex) {
            throw new ServletException(ex);
        }
    }

    private String escapeLike(String text) {
        text = text.replace("\\", "\\\\");
        text = text.replace("%", "\\%");
        text = text.replace("_", "\\_");
        return text;
    }
}
