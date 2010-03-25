<?php
// $Id: tableofcontents.admin.inc,v 1.1.2.13 2010/03/01 07:44:50 alexiswilke Exp $

/**
 * @file
 * Include the different setup (administration forms) for the
 * table of contents module.
 */


/**
 * Return the form used for the filter settings.
 *
 * @param $format
 *   The currently selected input format.
 */
function _tableofcontents_settings($format) {
  $form['tableofcontents'] = array(
    '#type' => 'fieldset',
    '#title' => t('Table of Contents'),
    '#collapsible' => TRUE,
    '#description' => t('This filter adds a table of contents referencing headers found in a node. If no headers are defined in the node content, then no table of content is added (whether or not a [toc ...] is defined.)'),
  );

  $form['tableofcontents']['tableofcontents_hide_table_' . $format] = array(
    '#title' => t('Hide the table of contents tags'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('tableofcontents_hide_table_' . $format, FALSE),
  );

  $form['tableofcontents']['tableofcontents_automatic_' . $format] = array(
    '#title' => t('Whether an automatic table of content should be added'),
    '#type' => 'select',
    '#options' => array(
      0 => t('Do not automatically add a table of content'),
      1 => t('If no [toc ...], automatically add one at the top of the page'),
      2 => t('If no [toc ...], automatically add one at the bottom of the page'),
    ),
    '#default_value' => variable_get('tableofcontents_automatic_' . $format, 0),
    '#description' => t('Please, note that there is a minimum limit (see below) that needs to be reached for the table of content to be added.'),
  );

  $form['tableofcontents']['tableofcontents_min_limit_' . $format] = array(
    '#title' => t('Number of headers before an automatic table of content is added'),
    '#type' => 'textfield',
    '#size' => 10,
    '#default_value' => variable_get('tableofcontents_min_limit_' . $format, 5),
    '#description' => t('When no [toc ...] is defined and the automatic feature is turned on, a table of contents will automatically be added only if at least that many headers are present.'),
  );

  //$form['tableofcontents']['tableofcontents_tag_' . $format] = array(
  //  '#title' => t('Select the tag to support'),
  //  '#type' => 'select',
  //  '#multiple' => FALSE,
  //  '#options' => array(
  //    'comment' => "&lt;!-- tableofcontents ... --&gt;",
  //    'toc' => "[toc ...]",
  //    'tableofcontents' => "[tableofcontents ...]",
  //  ),
  //  '#default_value' => variable_get('tableofcontents_tag_' . $format, 'toc'),
  //);

  $form['tableofcontents']['tableofcontents_allow_override_' . $format] = array(
    '#title' => t('Allow users to override the settings within the table of contents tag itself'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('tableofcontents_allow_override_' . $format, TRUE),
  );

  $form['tableofcontents']['tableofcontents_remove_teaser_' . $format] = array(
    '#title' => t('Remove Table of Contents tags from teasers'),
    '#type' => 'checkbox',
    '#default_value' => variable_get("tableofcontents_remove_teaser_$format", TRUE),
    '#description' => t('If this setting is changed, each node may need to be re-edited to reflect the new setting. This will also cause every node with a Table of Contents to have a split teaser. If you have many nodes, the <a href="@retease">Retease module</a> can help to do this automatically, except if you also want to use the automatic table of content feature which requires the addition of [toc hide:1] in your teaser.', array('@retease' => url('http://drupal.org/project/retease'))),
  );

  $form['tableofcontents']['tableofcontents_title_' . $format] = array(
    '#title' => t('Table of Contents Title'),
    '#type' => 'textfield',
    '#size' => 64,
    '#maxlength' => 1024,
    '#default_value' => variable_get('tableofcontents_title_' . $format, t('Table of Contents')),
    '#description' => t('Enter a default title for each Table of Contents. This will be translated for each individual page.'),
  );

  $form['tableofcontents']['tableofcontents_list_type_' . $format] = array(
    '#title' => t('List Type'),
    '#type' => 'radios',
    '#options' => array(
      'ol' => t('Ordered list'),
      'ul' => t('Unordered list'),
    ),
    '#default_value' => variable_get('tableofcontents_list_type_' . $format, 'ol'),
  );

  $options = array(
      1 => "H1",
      2 => "H2",
      3 => "H3",
      4 => "H4",
      5 => "H5",
      6 => "H6",
  );
  $form['tableofcontents']['tableofcontents_minlevel_' . $format] = array(
    '#title' => t('Minimum heading level'),
    '#type' => 'select',
    '#multiple' => FALSE,
    '#options' => $options,
    '#default_value' => variable_get('tableofcontents_minlevel_' . $format, 2),
  );

  $form['tableofcontents']['tableofcontents_maxlevel_' . $format] = array(
    '#title' => t('Maximum heading level'),
    '#type' => 'select',
    '#multiple' => FALSE,
    '#options' => $options,
    '#default_value' => variable_get('tableofcontents_maxlevel_' . $format, 3),
  );

  $form['tableofcontents']['tableofcontents_attachments_' . $format] = array(
    '#title' => t('Show attachments in the table of contents'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('tableofcontents_attachments_' . $format, FALSE),
  );

  if (module_exists('comment')) {
    $form['tableofcontents']['tableofcontents_comments_' . $format] = array(
      '#title' => t('Add the comments to the table of contents'),
      '#type' => 'checkbox',
      '#default_value' => variable_get('tableofcontents_comments_' . $format, FALSE),
    );

    $form['tableofcontents']['tableofcontents_comments_level_' . $format] = array(
      '#title' => t('Select header level at which comments start'),
      '#type' => 'select',
      '#options' => $options,
      '#default_value' => variable_get('tableofcontents_comments_level_' . $format, 3),
    );
  }

  $form['tableofcontents']['tableofcontents_hide_show_' . $format] = array(
    '#title' => t('Include link to hide/show table of contents'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('tableofcontents_hide_show_' . $format, TRUE),
  );

  $form['tableofcontents']['tableofcontents_collapsed_' . $format] = array(
    '#title' => t('Start with the table of content collapsed'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('tableofcontents_collapsed_' . $format, FALSE),
  );

  $form['tableofcontents']['tableofcontents_back_to_top_' . $format] = array(
    '#title' => t('Back to top label'),
    '#type' => 'textfield',
    '#size' => 35,
    '#default_value' => variable_get('tableofcontents_back_to_top_' . $format, ''),
    '#description' => t('The message to display at the top or bottom of each paragraph with a link back to the table of contents. Leave empty to avoid this link.'),
  );

  $form['tableofcontents']['tableofcontents_back_to_top_location_' . $format] = array(
    '#title' => t('Back to top location'),
    '#type' => 'select',
    '#options' => array(
      'header' => t('Under the headers'),
      'bottom' => t('At the bottom of the paragraph'),
    ),
    '#default_value' => variable_get('tableofcontents_back_to_top_location_' . $format, 'bottom'),
  );

  $form['tableofcontents']['tableofcontents_back_to_top_anchor_' . $format] = array(
    '#title' => t('Back to top anchor'),
    '#type' => 'textfield',
    '#size' => 35,
    '#default_value' => variable_get('tableofcontents_back_to_top_anchor_' . $format, 'toc'),
    '#description' => t('Specify the name of the anchor where you want the Back to top links to go. The default is <em>toc</em> which is the table of contents. Other anchor often used are <em>header, page, screen, wrapper</em>.'),
  );

  $form['tableofcontents']['tableofcontents_scroll_back_to_top_' . $format] = array(
    '#title' => t('Scroll back to the table of contents'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('tableofcontents_scroll_back_to_top_' . $format, FALSE),
    '#description' => t('Use the local scroll with jquery to scroll back to the table of contents.'),
  );

  $form['tableofcontents']['tableofcontents_numbering_' . $format] = array(
    '#title' => t('Numbering method'),
    '#type' => 'select',
    '#options' => array(
      0 => t('No number'),
      1 => t('Numbers 1., 2., 3. (like <ol>)'),
      2 => t('Sub-numbers 1., 1.1, 1.2, 2., 2.1, 2.2, etc.'),
      3 => t('Sub-numbers with zero 1.0, 1.1, 1.2, 2.0, 2.1, 2.2, etc.'),
    ),
    '#default_value' => variable_get('tableofcontents_numbering_' . $format, 0),
    '#description' => t('Select the type of numbering.'),
  );

  $form['tableofcontents']['tableofcontents_number_headers_' . $format] = array(
    '#title' => t('Add the number to the headers'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('tableofcontents_number_headers_' . $format, FALSE),
    '#description' => t('Also add the numbers shown in the table of contents to the headers.'),
  );

  $form['tableofcontents']['tableofcontents_number_mode_' . $format] = array(
    '#title' => t('Numbering mode'),
    '#type' => 'select',
    '#options' => array(
      0 => t('Decimal (1, 2, 3...)'),
      1 => t('Roman (I, II, III, ...)'),
      2 => t('Roman (i, ii, iii, ...)'),
      3 => t('Letters (A, B, C, ...)'),
      4 => t('Letters (a, b, c, ...)'),
      5 => t('Hexadecimal (0x00, 0x01, 0x02, ...)'),
    ),
    '#default_value' => variable_get('tableofcontents_number_mode_' . $format, 0),
    '#description' => t('Select decimal, roman, or letters.'),
  );

  $form['tableofcontents']['tableofcontents_number_start_letter_' . $format] = array(
    '#title' => t('Numbering prefix'),
    '#type' => 'textfield',
    '#size' => 10,
    '#default_value' => variable_get('tableofcontents_number_start_letter_' . $format, ''),
    '#description' => t('The characters added at the start. Often used for an opening parenthesis.'),
  );

  $form['tableofcontents']['tableofcontents_number_separator_' . $format] = array(
    '#title' => t('Numbering separator'),
    '#type' => 'textfield',
    '#size' => 10,
    '#default_value' => variable_get('tableofcontents_number_separator_' . $format, '.'),
    '#description' => t('The characters added between each number.'),
  );

  $form['tableofcontents']['tableofcontents_number_end_letter_' . $format] = array(
    '#title' => t('Numbering suffix'),
    '#type' => 'textfield',
    '#size' => 10,
    '#default_value' => variable_get('tableofcontents_number_end_letter_' . $format, '.'),
    '#description' => t('The characters added at the end. Often used for a closing parenthesis.'),
  );

  return $form;
}

/**
 * This function makes sure that the table of content is hidden in the teaser
 * if so requested by the user.
 *
 * @param[in] $node The node which teaser will be tweaked
 */
function _tableofcontents_hide_in_teaser(&$node) {
  // node got a teaser?
  if (!$node->teaser) {
    return;
  }

  // node uses our filter?
  $filters = filter_list_format($node->format);
  if (!isset($filters['tableofcontents/0'])) {
    return;
  }

  // any [toc ...] tag in the teaser?
  $new_teaser = preg_replace('%(<!--\s*tableofcontents([^>]*)-->|\[\[TOC.*?\]\]|(<(div|p)(\s+[^>]*)?>\s*)?\[toc.*?\](\s*</(div|p)>)?)%', '', $node->teaser);
  if ($node->teaser == $new_teaser) {
    // okay, no [toc ...], but maybe we need to hide the table of content?
    if (!variable_get('tableofcontents_automatic_' . $node->format, 0)) {
      return;
    }
  }

  if (strpos($node->body, '<!--break-->') !== FALSE) {
    // We've specified the split, but the teaser is shown in full
    // view. So, we now have to convert it so that the table of
    // content is hidden in the teaser.
    $body = preg_replace('/(.*)<!--break-->/s', '<!--break-->$1', $node->body);
    if ($body != $node->body) {
      $node->body = $body;
      drupal_set_message(t("The content you saved contains a table of contents. A separate summary (teaser) has been automatically created without the table of contents at the top. If you make any further changes, be sure to check the summary field to see if your changes apply there as well."));
    }
  }
  else {
    // This is the case where no teaser was specified by the user.
    // We add an explicit split teaser.
    $node->body = '<!--break-->' . $node->body;
    drupal_set_message(t("The summary (teaser) was automatically split from the body as site settings does not allow table of contents in summaries. If you make any further changes, be sure to check the summary field to see if your changes apply there as well."));
  }

  // Remove toc from teasers.
  $node->teaser = $new_teaser . '<div>[toc hidden:1]</div>';
}

/**
 * Add a field so users can ask the TOC to be generated in a
 * node without the use of the filter [toc].
 */
function _tableofcontents_node_form_alter(&$form) {
  $nid = $form['nid']['#value'];
  if ($nid) {
    $node = node_load($nid);
    $toc_automatic = variable_get('tableofcontents_nodetype_toc_automatic_' . $node->type, 0);
  }
  else {
    $node = (object)array(
      'tableofcontents_toc_automatic' => 0,
    );
    $toc_automatic = variable_get('tableofcontents_nodetype_toc_automatic_' . $form['type']['#value'], 0);
  }
  if ($toc_automatic == 99) {
    $options = array(
      0 => 'No table of contents',
      1 => 'Add the table at the top',
      2 => 'Add the table at the bottom',
    );
    $form['tableofcontents_toc_automatic'] = array(
      '#title' => t('Add a table of content to this node'),
      '#type' => 'select',
      '#options' => $options,
      '#default_value' => $node->tableofcontents_toc_automatic,
      '#description' => t('Select where you want the table of content, or no table.<br/><small>Note that the filter automatic feature takes precedence.</small>'),
    );
  }
}

/**
 * Add a field to the node type so one can define the automatic
 * table of content type on a per type basis.
 */
function _tableofcontents_nodetype_form_alter(&$form) {
  $options = array(
     0 => 'No table of contents',
     1 => 'Add the table at the top',
     2 => 'Add the table at the bottom',
    99 => 'Let user choose on node add/edit',
  );
  $form['submission']['tableofcontents_toc_automatic'] = array(
    '#type' => 'select',
    '#title' => t('Choose where the automatic table of contents is shown'),
    '#options' => $options,
    '#default_value' => variable_get('tableofcontents_nodetype_toc_automatic_' . $form['#node_type']->type, 0),
    '#description' => t('Select whether the table of content should be shown or not on this type of node.'),
  );
  $form['#submit'][] = '_tableofcontents_nodetype_form_alter_submit';
}

/**
 * Save the user selection.
 */
function _tableofcontents_nodetype_form_alter_submit($form, &$form_state) {
  variable_set('tableofcontents_nodetype_toc_automatic_' . $form['#node_type']->type, $form_state['values']['tableofcontents_toc_automatic']);
}

// vim: ts=2 sw=2 et syntax=php
