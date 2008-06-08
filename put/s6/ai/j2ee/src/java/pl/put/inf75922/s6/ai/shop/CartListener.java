/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.put.inf75922.s6.ai.shop;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;
import javax.servlet.http.HttpSessionEvent;
import javax.servlet.http.HttpSessionListener;

/**
 * Web application lifecycle listener.
 * @author Marcin
 */
public class CartListener implements HttpSessionListener {

    public void sessionCreated(HttpSessionEvent arg0) {
    }

    public void sessionDestroyed(HttpSessionEvent arg0) {
        EntityManagerFactory factory = Persistence.createEntityManagerFactory("Shop");
        EntityManager manager = factory.createEntityManager();
        SecurityManager.setUser(arg0.getSession(), manager, null);
    }
}