/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.put.inf75922.s6.ai.shop;

import java.io.*;

import java.net.URLEncoder;
import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;
import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import pl.put.inf75922.s6.ai.shop.entities.User;

/**
 *
 * @author Marcin
 */
public class SecurityFilter implements Filter {

    private FilterConfig filterConfig;

    public void init(FilterConfig filterConfig) {
        this.filterConfig = filterConfig;
    }

    public void destroy() {
    }

    public void doFilter(ServletRequest request, ServletResponse response,
            FilterChain chain)
            throws IOException, ServletException {

        HttpServletRequest _request = (HttpServletRequest) request;
        HttpServletResponse _response = (HttpServletResponse) response;

        EntityManagerFactory factory = Persistence.createEntityManagerFactory("Shop");
        EntityManager manager = factory.createEntityManager();

        User user = SecurityManager.getUser(_request.getSession(), manager);

        if (user == null) {

            String redirect = _request.getRequestURI();

            if (_request.getQueryString() != null) {
                redirect = redirect + "?" + _request.getQueryString();
            }
            _response.sendRedirect(_response.encodeRedirectURL(
                    "Login?Redirect=" + URLEncoder.encode(redirect)));

        } else {
            chain.doFilter(request, response);
        }
    }
}