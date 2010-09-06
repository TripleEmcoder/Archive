<?php

// $Id: menu_node_edit.page.inc,v 1.2 2009/10/15 22:21:55 agentken Exp $

/**
 * @file Allows node editing access based on menu relationships.
 */

/**
 * Page callback for user tab 'My Sections'.
 *
 * @param $account
 *   The user account being viewed.
 * @param $plid
 *   The parent id of the menu item, optional.
 * @return
 *   Themed HTML.
 */
function menu_node_edit_page($account, $plid = NULL) {
  global $user;
  drupal_add_css(drupal_get_path('module', 'menu_node_edit') .'/menu_node_edit.css');
  $limit = menu_node_edit_variable('per_page');
  // Set the page title.
  drupal_set_title(check_plain(menu_node_edit_variable('tab_title') .' -- '. $account->name));
  $pages = menu_node_edit_get_pages($account);
  if (empty($pages)) {
    return drupal_not_found();
  }
  if (count($pages) == 1 || empty($plid) || !array_key_exists($plid, $pages)) {
    $plid = key($pages);
  }

  // Now start the output.
  $output = '';

  // Flag to admins.
  if (user_access('administer menu node edit') && $account->uid != $user->uid) {
    drupal_set_message(t('You are viewing this page as an administrator. The access rules you see below apply to %user. Use this page to check the accuracy of your access control settings.', array('%user' => $account->name)), 'warning', FALSE);
  }
  // Table setup.
  $header = array(t('Title'), t('Author'), t('Type'), t('Status'), t('Operations'));
  // Query for the data.
  $types = menu_node_edit_user_node_types();
  if (empty($types)) {
    return t('You do not have sufficient permissions to edit any content in this section.');
  }
  $in = '';
  foreach ($types as $type) {
    $in .= "'". check_plain($type) ."', ";
  }
  $depth = db_result(db_query("SELECT depth FROM {menu_links} WHERE mlid = %d", $plid));
  $result = pager_query("SELECT mn.mlid, mn.nid, ml.link_path, ml.depth FROM {menu_links} ml INNER JOIN {menu_node} mn ON ml.mlid = mn.mlid INNER JOIN {node} n ON n.nid = mn.nid WHERE n.type IN (". trim($in, ' ,') .") AND %s = %d ORDER BY ml.p1 ASC, ml.p2 ASC, ml.p3 ASC, ml.p4 ASC, ml.p5 ASC, ml.p6 ASC, ml.p7 ASC, ml.p8 ASC, ml.p8 ASC", $limit, 0, NULL, 'ml.p'. $depth, $plid);
  $rows = array();
  while ($data = db_fetch_object($result)) {
    $row = array();
    $node = node_load($data->nid);
    // Add a depth marker to the output link
    $node->link = l($node->title, "node/$node->nid");
    $node->link = str_repeat('-', $data->depth) .' '. $node->link;
    $row[] = $node->link;
    $row[] = check_plain(db_result(db_query("SELECT name FROM {users} WHERE uid = %d", $node->uid)));
    $row[] = check_plain(node_get_types('name', $node->type));
    // Set the status string.
    $status = t('Unpublished');
    if ($node->status <> 0) {
      $status = t('Published');
    }
    $row[] = $status;
    $access = menu_node_edit_check($node, $account);
    $edit = '';
    if ($access) {
      $edit = l(t('edit'), 'node/'. $node->nid .'/edit');
    }
    $row[] = $edit;
    $rows[] = $row;
  }
  // Get the content creation links, if any.
  $links = menu_node_edit_user_create_content($plid, $account);
  if ($links) {
    $output .= '<div id="menu-access-create">'. $links .'</div>';
  }
  $output .= '<h2>'. check_plain(db_result(db_query("SELECT link_title FROM {menu_links} WHERE mlid = %d", $plid))) .'</h2>';
  $output .= '<p>'. t('The table below shows the content assigned to this section. <em>You may not be able to edit all content.</em> Ask your site administrator if you have questions about this page.') .'</p>';
  if ($links) {
    $output .= '<p>'. t('You may use the links to the right to create new content in this section.') .'</p>';
  }
  $output .= theme('table', $header, $rows);
  $output .= theme('pager', array(), $limit);
  
  return $output;
}

/**
 * Get the edit pages for a user account.
 *
 * @param $account
 *   The user account being checked.
 * @return
 *   An array of pages relevant to this user.
 */
function menu_node_edit_get_pages($account) {
  static $pages = array();
  if (isset($pages[$account->uid])) {
    return $pages[$account->uid];
  }
  $parents = $account->menu_node_edit;
  $pages = array();
  foreach ($parents as $parent) {
    $result = db_query("SELECT link_title FROM {menu_links} WHERE mlid = %d ORDER BY link_title", $parent);
    while ($data = db_fetch_object($result)) {
      $pages[$account->uid][$parent] = $data->link_title;
    }
  }
  return $pages[$account->uid];
}

/**
 * Get the node types that this user can create..
 *
 * @param $plid
 *   The parent menu item (i.e. the section) we are looking at.
 * @param $account
 *   The user account being checked.
 * @return
 *   HTML links to create content in this section.
 */
function menu_node_edit_user_create_content($plid, $account = NULL) {
  $allowed = array();
  $types = node_get_types();
  $options = array('query' => array('section' => $plid));
  foreach ($types as $type => $value) {
    if (user_access('administer nodes') || user_access('create '. $type .' content', $account)) {
      $allowed[] = l(t('Create new !type', array('!type' => $value->name)), 'node/add/'. str_replace('_', '-', $type), $options);
    }
  }
  if (empty($allowed)) {
    return;
  }
  return theme('item_list', $allowed, t('Create content'));
}
