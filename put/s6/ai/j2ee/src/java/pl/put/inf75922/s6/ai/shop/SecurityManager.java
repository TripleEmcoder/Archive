/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.put.inf75922.s6.ai.shop;

import java.util.Enumeration;
import javax.persistence.EntityManager;
import javax.persistence.EntityTransaction;
import javax.servlet.http.HttpSession;
import pl.put.inf75922.s6.ai.shop.entities.User;

/**
 *
 * @author Marcin
 */
public class SecurityManager {

    public static User getUser(HttpSession session, EntityManager manager) {
        Object userId = session.getAttribute("userId");

        if (userId == null) {
            return null;
        }

        return manager.getReference(User.class, userId);
    }

    public static void setUser(HttpSession session, EntityManager manager, User newUser) {

        User oldUser = getUser(session, manager);
        
        if (oldUser != null) {
            manager.getTransaction().begin();
            CartManager pernamentCart = new CartManager(session, "pernament");
            oldUser.getProducts().clear();
            oldUser.getProducts().addAll(pernamentCart.getProducts(manager));
            manager.getTransaction().commit();
        }
        
        Enumeration names = session.getAttributeNames();

        while (names.hasMoreElements()) {
            session.removeAttribute((String)names.nextElement());
        }
        
        if (newUser != null) {          

            session.setAttribute("userId", newUser.getId());

            CartManager pernamentCart = new CartManager(session, "pernament");
            pernamentCart.setProducts(newUser.getProducts());
        }
    }
}


