/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package pl.put.inf75922.s6.ai.shop.beans;

import java.util.List;

/**
 *
 * @author Marcin
 */
public class ProductListBean {
    
    private List products;

    public ProductListBean(List products) {
        this.products = products;
    }
    
    public List getProducts() {
        return products;
    }

    public void setProducts(List products) {
        this.products = products;
    }
    
     public int getProductCount() {
        return products.size();
    }
}
