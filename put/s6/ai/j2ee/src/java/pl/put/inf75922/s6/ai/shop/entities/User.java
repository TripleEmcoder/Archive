/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.put.inf75922.s6.ai.shop.entities;

import java.io.Serializable;
import java.util.Collection;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.ManyToMany;
import javax.persistence.NamedQueries;
import javax.persistence.Table;

/**
 *
 * @author Marcin
 */
@Entity
@Table(name = "Users")
@NamedQueries({})
public class User implements Serializable {

    private static final long serialVersionUID = 1L;
    @Id
    @Column(name = "Id", nullable = false)
    private Integer id;
    @Column(name = "Login", nullable = false)
    private String login;
    @Column(name = "Password", nullable = false)
    private String password;
    @ManyToMany(mappedBy = "userIdCollection")
    private Collection<Product> productIdCollection;

    public User() {
    }

    public User(Integer id) {
        this.id = id;
    }

    public User(Integer id, String login, String password) {
        this.id = id;
        this.login = login;
        this.password = password;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getLogin() {
        return login;
    }

    public void setLogin(String login) {
        this.login = login;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public Collection<Product> getProductIdCollection() {
        return productIdCollection;
    }

    public void setProductIdCollection(Collection<Product> productIdCollection) {
        this.productIdCollection = productIdCollection;
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
        if (!(object instanceof User)) {
            return false;
        }
        User other = (User) object;
        if ((this.id == null && other.id != null) || (this.id != null && !this.id.equals(other.id))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "pl.put.inf75922.s6.ai.shop.entities.User[id=" + id + "]";
    }
}
