/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.put.inf75922.s6.ai.shop.entities;

import java.io.Serializable;
import java.math.BigDecimal;
import java.util.Collection;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.JoinTable;
import javax.persistence.ManyToMany;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;
import javax.persistence.Table;

/**
 *
 * @author Marcin
 */
@Entity
@Table(name = "Products")
@NamedQueries({
    @NamedQuery(name = "GetProductsByNamePattern", query = "from Product p where p.name like :pattern")
})
public class Product implements Serializable {

    private static final long serialVersionUID = 1L;
    @Id
    @Column(name = "Id", nullable = false)
    private Integer id;
    @Column(name = "Name", nullable = false)
    private String name;
    @Column(name = "Subcategory", nullable = false)
    private String subcategory;
    @Column(name = "Category", nullable = false)
    private String category;
    @Column(name = "Price", nullable = false)
    private BigDecimal price;
    @JoinTable(name = "Deposits", joinColumns = {@JoinColumn(name = "ProductId", referencedColumnName = "Id")}, inverseJoinColumns = {@JoinColumn(name = "UserId", referencedColumnName = "Id")})
    @ManyToMany
    private Collection<User> users;

    public Product() {
    }

    public Product(Integer id) {
        this.id = id;
    }

    public Product(Integer id, String name, String subcategory, String category, BigDecimal price) {
        this.id = id;
        this.name = name;
        this.subcategory = subcategory;
        this.category = category;
        this.price = price;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSubcategory() {
        return subcategory;
    }

    public void setSubcategory(String subcategory) {
        this.subcategory = subcategory;
    }

    public String getCategory() {
        return category;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    public BigDecimal getPrice() {
        return price;
    }

    public void setPrice(BigDecimal price) {
        this.price = price;
    }

    public Collection<User> getUsers() {
        return users;
    }

    public void setUsers(Collection<User> users) {
        this.users = users;
    }

    @Override
    public int hashCode() {
        int hash = 0;
        hash += (id != null ? id.hashCode() : 0);
        return hash;
    }

    @Override
    public boolean equals(Object object) {
        // TODO: Warning - this method won't work in the case the id fields are not set
        if (!(object instanceof Product)) {
            return false;
        }
        Product other = (Product) object;
        if ((this.id == null && other.id != null) || (this.id != null && !this.id.equals(other.id))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "pl.put.inf75922.s6.ai.shop.entities.Product[id=" + id + "]";
    }
}
