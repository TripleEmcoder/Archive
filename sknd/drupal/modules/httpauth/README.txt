// $Id: README.txt,v 1.1 2008/04/20 14:49:01 naquah Exp $

INSTALLATION
------------

 1) Copy the httpauth directory into the appropriate modules directory in your
    Drupal installation (recommended: sites/all/modules).

 2) Go to Administer > Site building > Modules and enable the HTTP
    authentication module.

 3) If you know you are not using PHP in CGI or FastCGI mode, you can continue
    with step 4.

     a. To check what mode your PHP is running in, go to Administer >
        Reports > Status report, click the PHP version number, and find the
        Server API row. If this says something like "CGI" or "FastCGI", you
        are running PHP in CGI mode. If you are not, continue with step 4.

     b. In order to make HTTP authentication work when using PHP in CGI mode,
        you will need to add the following lines to the .htaccess file
        located in your Drupal root directory, just below the line that says
        "RewriteEngine On":

        RewriteCond %{HTTP:Authorization} ^Basic
        RewriteCond %{QUERY_STRING} !HTTP_AUTHORIZATION
        RewriteRule ^(.*)$ $1?HTTP_AUTHORIZATION=%{HTTP:Authorization} [L,QSA]

 4) Go to Administer > Site configuration > HTTP authentication and enable
    HTTP authentication to start using the module.
