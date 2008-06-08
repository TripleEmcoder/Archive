/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.put.inf75922.s6.ai.shop;

import java.util.ArrayList;
import java.util.Enumeration;
import java.util.List;
import javax.persistence.EntityManager;
import javax.servlet.http.HttpSession;
import pl.put.inf75922.s6.ai.shop.entities.Product;

/**
 *
 * @author Marcin
 */
public class CartManager {

    public static String findProductCart(HttpSession session, Product product) {

        Enumeration names = session.getAttributeNames();

        while (names.hasMoreElements()) {
            String name = (String) names.nextElement();

            if (name.endsWith("Cart")) {
                ArrayList<Integer> productIds = (ArrayList<Integer>) session.getAttribute(name);

                if (productIds.contains(product.getId())) {
                    return name.replace("Cart", "");
                }
            }
        }

        return "";
    }
    private String name;
    private HttpSession session;
    private ArrayList<Integer> productIds;

    public CartManager(HttpSession session, String name) {
        this.name = name;
        this.session = session;
        productIds = (ArrayList<Integer>) session.getAttribute(name + "Cart");

        if (productIds == null) {
            productIds = new ArrayList<Integer>();
        }

    }

    public List<Product> getProducts(EntityManager manager) {

        ArrayList<Product> products = new ArrayList<Product>();

        for (Integer productId : productIds) {
            products.add(manager.find(Product.class, productId));
        }
        return products;
    }

    public void addProduct(Product product) {
        productIds.add(product.getId());
        session.setAttribute(name + "Cart", productIds);
    }

    public void removeProduct(Product product) {
        productIds.remove(product.getId());
        session.setAttribute(name + "Cart", productIds);
    }
}


