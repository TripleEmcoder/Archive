/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.put.inf75922.s6.ai.shop;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Enumeration;
import java.util.HashSet;
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
                HashSet productIds = (HashSet) session.getAttribute(name);

                if (productIds.contains(product.getId())) {
                    return name.replace("Cart", "");
                }
            }
        }

        return "";
    }
    private String name;
    private HttpSession session;

    public CartManager(HttpSession session, String name) {
        this.name = name;
        this.session = session;
    }

    public Collection<Product> getProducts(EntityManager manager) {

        HashSet productIds = loadProducts();
        ArrayList<Product> products = new ArrayList<Product>();

        for (Object productId : productIds) {
            products.add(manager.getReference(Product.class, productId));
        }

        return products;
    }

    public void setProducts(Collection<Product> products) {
        
        HashSet productIds = new HashSet();

        for (Product product : products) {
            productIds.add(product.getId());
        }
        
        saveProducts(productIds);
    }

    public void addProduct(Product product) {
        HashSet productIds = loadProducts();
        productIds.add(product.getId());
        saveProducts(productIds);
    }

    public void removeProduct(Product product) {
        HashSet productIds = loadProducts();
        productIds.remove(product.getId());
        saveProducts(productIds);
    }

    private HashSet loadProducts() {
        HashSet productIds = (HashSet) session.getAttribute(name + "Cart");

        if (productIds == null) {
            productIds = new HashSet();
        }
        
        return productIds;
    }

    private void saveProducts(HashSet productIds) {
        session.setAttribute(name + "Cart", productIds);
    }
}


