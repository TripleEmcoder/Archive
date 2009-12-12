$Id: README.txt,v 1.3 2009/08/10 23:33:00 garrettalbright Exp $

Zenify - A module for the Drupal content management system
by Garrett Albright
My Drupal user page:
http://drupal.org/user/191212

This module's project page:
http://drupal.org/project/zenophile

Zenophile is a tiny module which allows themers to very easily create Zen
subthemes without all the tedious file copying and find-and-replacing required
when creating subthemes by hand. With this module, subthemes can be created in a
fraction of the time just by entering information into a single-page form and
clicking "Submit."

Want to spice it up a little? Enter your desired page and sidebar widths, and
Zenophile will add a CSS file to your theme with all the calculations
automatically done - a huge benefit if Zen's negative margin-based layout makes
you cross-eyed. Or maybe you'd like both of your sidebars to be to the left or
right of the main content area - Zenophile can make the adjustments for you with
just a click of the mouse. Creating a new Zen subtheme doesn't get any easier
than this.

Note that this module is only intended to work with the 1.x branch of Zen. Once
the Zen 2.x branch reaches beta status, I will begin the process of tweaking
Zenophile so that it is compatible; however, I'm afraid if I start now, I'll be
aiming at a moving target.

FIFTEEN SECOND HOW-TO:

1. Install this module like any other module.

2. If necessary, go to Administration > Users > Permissions and grant groups the
'create theme with zenophile' permission.

3. Go to Aministration > Site building > Themes and click the "Create Zen
subtheme" tab. Everything on this page should be fairly self-explanatory.

4. When you're done creating themes, you may want to deactivate Zenophile. It
won't stress the server too much if it remains active, but it will take up a
bit of RAM and processor cyclage unnecessarily. If you decide in the future you
want to create another Zen subtheme, simply reactivate the module.


HELP! I CAN'T EDIT THE THEMES!

The files and directories that Zenophile creates will be owned by the user and
group that the web server runs as. If you access the server as a different user
and try to edit the files, you may encounter permissions problems. One way to
resolve this is to make yourself the owner of the files in the theme directory.
If you have shell access, try running this command:

chown -R YourUsername /path/to/theme

You may need to prefix the command with `sudo` to run it as root.

If you don't have shell access, see if you can change ownership of the directory
in an FTP client. Failing that, see if you can give the "group" or "other"
category "write" permissions. How to do this, or even if you will be able to do
this, will all vary depending on what FTP program you're using and what your
user account on the web server allows you to do. If all else fails, consult your
web server's administrator or the technical support crew at your web hosting
company for advice.