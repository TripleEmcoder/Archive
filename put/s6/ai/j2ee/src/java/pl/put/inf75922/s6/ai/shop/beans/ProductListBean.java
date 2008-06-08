/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.put.inf75922.s6.ai.shop.beans;

import java.math.BigDecimal;
import java.util.Collection;
import pl.put.inf75922.s6.ai.shop.entities.Product;

/**
 *
 * @author Marcin
 */
public class ProductListBean {

    private Collection<Product> products;

    public ProductListBean(Collection<Product> products) {
        this.products = products;
    }

    public Collection<Product> getProducts() {
        return products;
    }

    public void setProducts(Collection<Product> products) {
        this.products = products;
    }

    public int getProductCount() {
        return products.size();
    }

    public BigDecimal getProductValue() {

        BigDecimal value = new BigDecimal(0);

        for (Product product : products) {
            value = value.add(product.getPrice());
        }

        return value;
    }
}
