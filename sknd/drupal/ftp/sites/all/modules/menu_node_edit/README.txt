// $Id: README.txt,v 1.5 2009/10/28 18:33:15 agentken Exp $

Menu Node Edit
Allows node editing access based on menu relationships.

CONTENTS
--------

1. Introduction
2. Installation
3. Menu Node Edit and Node Access
4. Permissions
4.1 Security Considerations
4.2 Access Check Process
5. Using the Module
5.1 Terminology
5.2 Menu Node Edit Settings
5.3 Creating Sections
5.4 Assigning Users as Section Editors
6. My Sections
6.1 About the My Sections Tab
6.2 Content Lists
6.3 Creating Content in a Section
7. Content Creation and Editing
7.1 Hiding Menu Links
8. Developer Information
8.1 Database Tables
8.2 Tokens


----
1. Introduction

The Menu Node Edit module allows the site's menu system to be used as the sole
organizing principle. It does so by allowing specific menu items to be defined
as 'sections' of a Drupal web site. Individual users can then be assigned as
editors of one or more section.

This structure means that, for small web sites, the menu system can be used as
the sole ordering principle, removing the need for taxonomy or group-based
editing controls.

----
2. Installation

The Menu Node Edit module requires the Menu Node API module. After both modules
have been downloaded and inflated, place them in your modules directory.

Then proceed to the Modules admin page and activate both modules.

After you install the module, you will want to configure its permissions after
reading this document.

----
3. Menu Node Edit and Node Access

The Menu Node Edit module is deliberately _not_ a Drupal node access module. It
does not provide any access controls for the viewing or deleting of content.

Instead of using the {node_access} table to assert permissions, Menu Node Edit
uses hook_menu_alter() to rewrite the access rules for a node's edit page. As a
result, Menu Node Edit can provide flexible controls regarding who can and
cannot edit content within a given site section.

Menu Node Edit should work in harmony with standard Drupal permissions and node
access modules. Please read section 4 for additional details.

----
4. Permissions

The Menu Node Edit module generates four default permissions, plus a special
editing permission for each node type used on your site. The default permissions
are as follows:

  -- 'administer menu node edit'
      Allows users to adjust settings for the Menu Node Edit module.
  -- 'assign menu node edit'
      Allows users to assign other users to site sections
  -- 'publish to my sections'
      Allows users to select a target section for new and edited content.
      This permission is similar to the ability to assign a node to a menu path,
      but with far greater restrictions, based on the user's assigned sections.
  -- 'set menu visibility'
      Allows users to set a menu item to 'hidden'. Doing so prevents the link
      from appearing in site navigation, but keeps the node as part of an
      editing section. Users with the 'administer menu' permission also have
      this ability.
  -- 'view my sections'
      Allows a user to see content overview pages that list all content in her
      assigned sections. This permision only works if the 'add menu node edit
      tab to user account page' setting is active.

In addition to these settings, the module generates the following permission for
each node type on your site:

  -- 'edit any TYPE content in assigned sections'

This permission should be used with care. It allows Menu Node Edit to extend
any other node access permissions for the approved content types. You should 
assign this permission only if you want users to be able to edit certain types
of content if and only if the content is also assigned to one of her sections.

----
4.1 Security Considerations

By design, the Menu Node Edit module gives select users permission to view and
edit content that might normally be denied to them. This may include the ability 
to see and edit content that is 'unpblished' and not visibile to normal users.

Only trusted users and roles should be given any Menu Node Edit permissions.

The module allows users with the 'administer menu node edit' permission the
right to view the 'My sections' content lists of other users. You should use 
this permission to ensure that you are comfortable with the data that the module
exposes to these users.

----
4.2 Access Check Process

When editing access to a node is requested, the following checks take place:

  -- Check for active menu sections.
  -- Check for the user's active sections.
  -- If either are empty, return Node Access rules.
  -- If Node Access returns TRUE, return TRUE.
  -- Check to see if the user can edit the node's content type in her section(s).
  -- If not, return FALSE.
  -- Check the user's allowed sections against this node.
  -- If allowed, return TRUE.
  -- Otherwise, return FALSE.

----
5. Using the Module

The Menu Node Edit module is not designed for all use cases. Please read this
document before using the module.

----
5.1 Terminology

The following terms are used consistently in the documentation and user
interfaces.

  -- Item
  A unique menu item, defined in Drupal's menu system. Typically this is
  a single row from the {menu_links} table.
  -- Node
  A unique piece of site content.
  -- Section
  A menu item (and its children) defined as a content group for editing.
  -- Editor
  A user assigned to one or more sections, with the appropriate permissions.
  
----
5.2 Menu Node Edit Settings

There are two settings available for the module. To adjust these settings, you
must have the 'administer menu node edit' permission.

  -- Add menu node edit tab to user account page
  Enabling this setting adds a 'My Sections' tab to the user page of 
  any user who is assigned to a section and is given the 'view my sections'
  permission. Default: TRUE

  -- Allow the following content types to be assigned to a section
  These settings control how content created by editors will be handled. For
  each node type, you may allow section editors to assign new or existing
  content to one of their sections. If a node type is not selected here, Then
  the section editor will not be able to assign the content to her section.
  Default: TRUE for all content types

Normally, you will not need to adjust these settings.

----
5.3 Creating Sections

To begin using Menu Node Edit, you must first create some sections. To do so,
you must have the 'administer menus' permission. To create a section, go to
the Menu administration page, select a menu, and look at the menu overview
form.

You should see a column marked 'Sections', with a checkbox for each menu item.
You can crate sections in a batch by using this form. Simply select each menu
item that you wish to make a section.

Optionally, you can edit the menu item and select the 'Menu node edit section'
checkbox on the editing form.

Once you have created some sections, you may assign users to be editors of those
sections.

----
5.4 Assigning Users as Section Editors

Now that you have created some sections, you can assign users to be section
editors. A user may be assigned to one or more sections.

To assign section editors, you must have the 'assign menu node edit' permission.

  -- Navigate to a user's account page and click the edit tab.
  -- On the user account form, find the fieldset labelled 'Section editing'.
  -- Check the sections that you wish to allow this user to edit.
  -- Submit the form to save the changes.

This form is also available when creating new users through the Add User admin
interface.

----
6. My Sections

The My Sections tab is a simple overview of content asigned to a user's 
sections. This tab is enabled by default, but may be turned off.

If a user is assigned as a section editor and has the 'view my sections' 
permission, the My Sections tab will appear on his or her account page.

----
6.1. About the My Sections Tab

My Sections displays a paginated overview of all content assigned within each
section that a user can edit. For example, if a user is assigned to edit the 
sections Foo and Bar, this page will show two sub-tabs.

By clicking on a sub-tab, the user can see a list of all content within that 
section, according to the following rules:

  -- The user must have one of the following permissions:
    -- 'administer nodes'
    -- 'edit any TYPE content in assigned sections'
    -- 'edit any TYPE content'
  -- The content must be assigned to the menu section being displayed.
  
Note that content not assigned to the menu system will never be displayed.

----
6.2 Content Lists

Each My Section tab shows a list of content. The list shows the following 
information:

  -- Title
  -- Author name
  -- Content type
  -- Status (published / unpublished)
  -- Edit link
  
Two critical notes here, both related to site security.

  1) It is possible for users to view the information for unpublished content.
  For some sites, this may be a concern. Those sites should be very careful
  about who is given editor access to specific sections.
  
  2) It is possible that a user may not be allowed to edit some content on
  this list _if_ access control permissions are not set correctly, or if a node
  access module trumps the permission 'edit any TYPE content'. If a user has
  the 'edit any TYPE content in assigned sections' permission, all content of
  that type should be editable.

----
6.3 Creating Content in a Section

The module can also help users without the 'administer menu' permission to
post content in the appropriate section.

When viewing a My Sections tab, the user is given a list of all content types 
that he is allowed to create. Clicking on these links will automatically
populate the content creation form with the proper section information.

Note that this only applies to users with the 'publish to my sections'
permission.

----
7. Content Creation and Editing

For users with the 'publish to my sections' permission but not the 'administer
menu' permission, the 'Section' form element is available when editing
content.

The Section form element presents a select list that shows all the section that
a user can edit. This dropdown shows all child items of the assigned section,
allowing the editor to assign the node a place in the menu hierarchy.

The title for the menu item will be created automatically, using the title of
the content node.

There are a handful of circumstances under which the Sections option will
not be visible to an editor. Those are as follows:

  1) If the content type cannot be set to a section (see 5.2)
  2) If the editor is not assigned to any sections.
  3) If the node is already assigned to a menu item that is outside
  any of the editor's sections.

Note that editors are not required to assign content to a section when creating
content. However, once content has been assigned to a section, it may only be
re-assigned. Only users with the 'administer menu' permission may delete
section items.

When content is assigned to a section, a new menu item with weight of zero
(0) will be created at the depth indicated by the selection form.

----
7.1 Hiding Menu Links

In versions 6.x.1.6 and higher, users with the 'set menu visibility' permission
will also be shown a 'Hidden' checkbox when editing content.

Check this box if you wish to add the content to an editing section but do not
want it displayed in site navigation. A menu item may be made visible or
invisible as needed. Hidden menu items still appear in a user's 'My sections'
content lists.

See http://drupal.org/node/517732 for background on this feature.

---
8. Developer Notes

This section is for general notes.

----
8.1 Database Tables

The module creates two tables to store its data:

  {menu_node_edit}
    Stores the menu link ids (mlids) identified as sections for your site.
    This table has one column, mlid (int), and it is a foreign key to
    {menu_links}.mlid.
  
  {menu_node_edit_user}
    Stores the relationship between sections and editors. This table has
    two columns, uid (int) is a foreign key to the {users}.uid, and {mlid}
    (int), which is a foreign key to {menu_node_edit}.mlid and {menu_links}.mlid.

----
8.2 Tokens

The module supports menu-based tokens. It provides a token for the
path to the parent menu item of the node. If there is no parent item,
the token defaults to use the string 'content'.

There are two tokens:

  -- 'menu-parent-path-alias' 
  Path alias of parent menu item. This is a raw path, and has not been
  sanitized. However, using it with pathauto will force the '/' characters
  to be stripped.
  -- 'menu-parent-path-alias-path'
  Path-safe alias of parent menu item. Use this token with pathauto to
  preserve / characters.
  
