<?php
// $Id: revision_deletion.admin.inc,v 1.1.2.1 2009/08/18 01:10:11 nancyw Exp $

/**
 * @file
 * Node Revision Deletion admin page.
 */

define('REV_DEL_PERM', 'mass delete revisions');

/**
 * Settings form.
 */
function revision_deletion_settings() {
  drupal_add_css(drupal_get_path('module', 'revision_deletion') .'/revision_deletion.css');
  $yesno = array(1 => t('Yes'), 0 => t('No'));

  $frequency = array(0 => t('Manual'));
  $frequency += drupal_map_assoc(array(86400, 604800, 1209600, 2419200, 4838400), 'format_interval');

  $age = drupal_map_assoc(array(900, 1800, 3600, 86400, 604800, 2419200, 4838400, 9676800, 15724800, 31449600), 'format_interval');

  $form['rev_del'] = array(
    '#type' => 'fieldset',
    '#title' => t('Revision Mass Deletion Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    );

  // Set node types to be deleted. If not set yet, defaults to revision-enabled types.
  $default_types = variable_get('revision_delete', array());
  $set_default = empty($default_types);
  $node_types = node_get_types('names');
  foreach ($node_types as $type => $name) {
    $options = variable_get("node_options_$type", array());
    if (in_array('revision', $options)) {
      $node_types[$type] = '<strong>'. $name .'</strong>';
      if ($set_default) {
        $default_types[$type] = $type;
      }
    }
  }
  $form['rev_del']['revision_delete'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content types'),
    '#default_value' => $default_types,
    '#multiple' => TRUE,
    '#required' => TRUE,
    '#options' => $node_types,
    '#description' => t('Select which content types are subject to revision deletion. Types in <strong>bold</strong> have revisions enabled by default. Multiple types may be selected.'),
    '#prefix' => '<div class="revision-deletion-options">',
    '#suffix' => '</div>',
    );

  // Set revision frequency interval.
  $form['rev_del']['revision_delete_freq'] = array(
    '#type' => 'radios',
    '#title' => t('Automatic deletion interval'),
    '#default_value' => variable_get('revision_delete_freq', 0),
    '#options' => $frequency,
    '#size' => 6,
    '#description' => t('Frequency of the scheduled mass revision deleton. Select "Manual" to disable the automatic deletion.'),
    '#prefix' => '<div class="revision-deletion-options">',
    '#suffix' => '</div>',
    );

  // Set revision age for deletion.
  $form['rev_del']['revision_delete_age'] = array(
    '#type' => 'radios',
    '#title' => t('Revision Age'),
    '#default_value' => variable_get('revision_delete_age', 2419200),
    '#options' => $age,
    '#description' => t('Age of revisions that should be deleted.'),
    '#prefix' => '<div class="revision-deletion-options">',
    '#suffix' => '</div>',
    );

  // Settings for "list revisions".
  $form['list'] = array(
    '#type' => 'fieldset',
    '#title' => t('List revisions settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#description' => t('These options are used when the user selects "list revisions" to show all revisions.'),
    );

  // Take over core list function.
  $takeover = variable_get('revision_delete_list_takeover', 0);
  $form['takeover_before'] = array('#type' => 'value', '#value' => $takeover);
  $form['list']['revision_delete_list_takeover'] = array(
    '#type' => 'radios',
    '#title' => t('Take over revisions list'),
    '#options' => $yesno,
    '#default_value' => $takeover,
    '#description' => t('This determines whether or not you wish to replace the core revisions list function.'),
    '#prefix' => '<div class="container-inline">',
    '#suffix' => '</div>',
    );

  // How many revisions to show in list.
  $form['list']['revision_delete_list_limit'] = array(
    '#type' => 'textfield',
    '#size' => 6,
    '#title' => t('How many to show in revision list'),
    '#default_value' => variable_get('revision_delete_list_limit', 25),
    '#description' => t('This is the number of versions that will show on each page.'),
    '#prefix' => '<div class="container-inline">',
    '#suffix' => '</div>',
    );

    // Show conditional labels.
  $form['list']['revision_delete_list_show_conditional'] = array(
    '#type' => 'radios',
    '#title' => t('Show conditional labels'),
    '#options' => $yesno,
    '#default_value' => variable_get('revision_delete_list_show_conditional', 1),
    '#description' => t('Should the conditional labels (e.g "current" or "last for date") be shown? CSS classes are also set so those rows can be styled differently.'),
    '#prefix' => '<div class="container-inline">',
    '#suffix' => '</div>',
    );

  // Keep original.
  $form['list']['revision_delete_list_keep_original'] = array(
    '#type' => 'radios',
    '#title' => t('Keep original'),
    '#options' => $yesno,
    '#default_value' => variable_get('revision_delete_list_keep_original', 0),
    '#description' => t('Should the original version be unchecked?'),
    '#prefix' => '<div class="container-inline">',
    '#suffix' => '</div>',
    );

  // Keep last per date.
  $form['list']['revision_delete_list_keep_date_last'] = array(
    '#type' => 'radios',
    '#title' => t('Keep last revison per date'),
    '#options' => $yesno,
    '#default_value' => variable_get('revision_delete_list_keep_date_last', 0),
    '#description' => t('Should the last version for a date be unchecked? This probably should not be used at the same time as "Keep original" above.'),
    '#prefix' => '<div class="container-inline">',
    '#suffix' => '</div>',
    );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
    '#submit' => array('revision_deletion_settings_submit'),
    );

  $form['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset to defaults'),
    '#submit' => array('revision_deletion_settings_reset'),
    );

  return $form;
}

/**
 * Settings form reset.
 */
function revision_deletion_settings_reset($form, &$form_state) {
  variable_del('revision_delete');
  variable_del('revision_delete_freq');
  variable_del('revision_delete_age');
  variable_del('revision_delete_list_takeover');
  variable_del('revision_delete_list_limit');
  variable_del('revision_delete_list_show_conditional');
  variable_del('revision_delete_list_keep_original');
  variable_del('revision_delete_list_keep_date_last');
  cache_clear_all();
  drupal_set_message(t('Configuration options have been reset to defaults.'));
}

/**
 * Settings form submission.
 */
function revision_deletion_settings_submit($form, &$form_state) {
  variable_set('revision_delete', array_filter($form_state['values']['revision_delete']));
  variable_set('revision_delete_freq', $form_state['values']['revision_delete_freq']);
  variable_set('revision_delete_age', $form_state['values']['revision_delete_age']);
  variable_set('revision_delete_list_takeover', $form_state['values']['revision_delete_list_takeover']);
  variable_set('revision_delete_list_limit', $form_state['values']['revision_delete_list_limit']);
  variable_set('revision_delete_list_show_conditional', $form_state['values']['revision_delete_list_show_conditional']);
  variable_set('revision_delete_list_keep_original', $form_state['values']['revision_delete_list_keep_original']);
  variable_set('revision_delete_list_keep_date_last', $form_state['values']['revision_delete_list_keep_date_last']);

  // If the take over option has changed, rebuild the menu.
  if ($form_state['values']['takeover_before'] == $form_state['values']['revision_delete_list_takeover']) {
    menu_rebuild();
  }

  drupal_set_message(t('Configuration options have been saved.'));
}
