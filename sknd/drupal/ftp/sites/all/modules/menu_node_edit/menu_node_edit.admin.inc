<?php

// $Id: menu_node_edit.admin.inc,v 1.1 2009/05/08 14:01:36 agentken Exp $

/**
 * @file Allows node editing access based on menu relationships.
 */

/**
 * The menu node edit settings form.
 */
function menu_node_edit_settings_form() {
  $form = array();
  $form['test'] = array('#value' => t('This page controls the settings for the Menu Node Edit module.'));
  $form['tab'] = array(
    '#type' => 'fieldset',
    '#title' => t('User tab'),
    '#collapsible' => TRUE,
  );
  $form['tab']['menu_node_edit_tab'] = array(
    '#title' => t('Add tab to user account page'),
    '#type' => 'checkbox',
    '#default_value' => menu_node_edit_variable('tab'),
    '#description' => t('Check this box to enable a user account tab for users to view content in their assigned editing sections.'),
  );
  $form['tab']['menu_node_edit_tab_title'] = array(
    '#title' => t('Tab title'),
    '#type' => 'textfield',
    '#size' => 40,
    '#maxlength' => 80,
    '#required' => TRUE,
    '#default_value' => menu_node_edit_variable('tab_title'),
    '#description' => t('Set the title for the menu node edit user tab.'),
  );
  $form['tab']['menu_node_edit_per_page'] = array(
    '#title' => t('Items per page'),
    '#type' => 'select',
    '#options' => drupal_map_assoc(array(10, 15, 20, 25, 30, 40, 50)),
    '#default_value' => menu_node_edit_variable('per_page'),
    '#description' => t('Set the number of content items to display per page.'),
  );
  $form['user'] = array(
    '#type' => 'fieldset',
    '#title' => t('User form settings'),
    '#collapsible' => TRUE,
  );
  $form['user']['menu_node_edit_collapsed'] = array(
    '#title' => t('Collapse the \'Section editing\' form element'),
    '#type' => 'checkbox',
    '#default_value' => menu_node_edit_variable('collapsed'),
    '#description' => t('Check this box to collapse (hide) the \'Section editing\' element on the user account editing form.'),
  );
  $form['content'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content settings'),
    '#collapsible' => TRUE,
  );
  $form['content']['menu_node_edit_node_types'] = array(
    '#title' => t('Allow the following content types to be assigned to a section'),
    '#type' => 'checkboxes',
    '#options' => node_get_types('names'),
    '#default_value' => menu_node_edit_variable('node_types'),
    '#description' => t('For the selected content types, editors will be allowed to assign new content to a section.'),
  );
  $form['#submit'][] = 'menu_node_edit_settings_form_submit';
  return system_settings_form($form);
}

/**
 * Rebuild the menus on form submit.
 */
function menu_node_edit_settings_form_submit($form, &$form_state) {
  // Ensure that the variables are set before the menu rebuild.
  if ($form_state['values']['op'] == $form_state['values']['reset']) {
    variable_del('menu_node_edit_tab_title');
  }
  else {
    variable_set('menu_node_edit_tab_title', $form_state['values']['menu_node_edit_tab_title']);
  }
  menu_rebuild();
}
