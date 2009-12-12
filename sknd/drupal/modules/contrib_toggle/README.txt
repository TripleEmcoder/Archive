// $Id$

CONTRIB TOGGLE FUNCTIONS:
When upgrading between Drupal core versions (e.g. 6.9 to 6.10) it is recommended that all non-core modules ("contrib modules") are deactivated first. When you have modules with multiple dependencies, this is a needlessly time-consuming and fiddly process. The Contrib Toggle module provides a simple button on the module configuration page (/admin/build/modules) to mark all contrib modules for deactivation, reducing this process a simple two-click exercise. Click the "Disable Contrib" button, then click "Save Configuration" to actually disable the modules. Contrib toggle automatically disables itself in this process.
 
Contrib Toggle also provides a easier mechanism for activating and deactivating modules with dependencies. When this module is active, all modules on the module admin page can be activated and deactivated. Activating a module will also activate any other modules it depends on. Deactivating a module will also deactivate any modules that depend on it. (Core-required modules are excluded.)
 
Warning: Disabling all contrib modules may disable key functionality of your site or undermine security provisions beyond those built into Drupal core that you have added using contributed modules. Disabling all contrib modules should therefore only be done when your site is in maintenance mode or if you are sure you know what you are doing.


INSTALLATION:
1) Download the module:
http://drupal.org/project/contrib_toggle

2) If you do not already have it installed, download the required jQuery plugins module (6.x-1.7 or later):
http://drupal.org/project/jquery_plugin

3) Upload the module folder(s) to your modules directory (usually /sites/all/modules).

4) Go to admin/build/modules and enable the Contrib Toggle module from the Administration group.