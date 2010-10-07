<?php
// $Id: views_slideshow_thumbnailhover.theme.inc,v 1.1.2.1.2.15 2010/01/18 01:00:51 redndahead Exp $

/**
 *  @file
 *  Theme & preprocess functions for the Views Slideshow: ThumbnailHover module.
 */

/**
 *  Implement template_preprocess_hook_THEMENAME().
 */
function template_preprocess_views_slideshow_thumbnailhover(&$vars) {
  $options = $vars['options'];
  $base = drupal_get_path('module', 'views_slideshow_thumbnailhover');
  drupal_add_js($base . '/views_slideshow.js', 'module');
  drupal_add_css($base . '/views_slideshow.css', 'module');

  $num_divs = sizeof($vars['rows']);
  $teasers_last = $options['thumbnailhover']['teasers_last'] ? 'true' : 'false';

  $settings = array_merge(
    array(
      'num_divs' => $num_divs,
      'teasers_last' => $teasers_last,
      'id_prefix' => '#views_slideshow_thumbnailhover_main_',
      'div_prefix' => '#views_slideshow_thumbnailhover_div_',
      'id' => $vars['id'],
    ),
    $options['thumbnailhover']
  );

  drupal_add_js(array('viewsSlideshowThumbnailHover' => array('#views_slideshow_thumbnailhover_main_'. $vars['id'] => $settings)), 'setting');
  if ($settings['pager_event'] == 'hoverIntent') {
    if (module_exists('jq')) {
      $loaded_plugins = jq_plugins();
      if (!empty($loaded_plugins['hoverIntent'])) {
        jq_add('hoverIntent');
      }
    }
    if (module_exists('hoverintent')) {
      hoverintent_add();
    }
  }
}


/**
 *  These are the slideshow elements themselves; not actually displayed, but used to give the html to the main element.
 */
function theme_views_slideshow_thumbnailhover_no_display_section($view, $rows, $id, $options, $teaser = TRUE) {
  // Add support for the jQuery Cycle plugin.
  // If we have the jQ module installed, use that to add the Cycle plugin if possible.
  // That allows for version control.
  $js = 0;
  if (module_exists('jq')) {
    $loaded_plugins = jq_plugins();
    if (!empty($loaded_plugins['cycle'])) {
      $js = jq_add('cycle');
    }
  }

  // Otherwise, we'll add the version included with this module.
  if (!$js) {
    drupal_add_js(drupal_get_path('module', 'views_slideshow') .'/js/jquery.cycle.all.min.js', 'module');
  }
  $output = '<div id="views_slideshow_thumbnailhover_teaser_section_' . $id . '" class="views_slideshow_thumbnailhover_teaser_section views_slideshow_teaser_section">' . "\n";
  foreach ($view->result as $count => $node) {
    if ($view->display_handler->uses_fields()) {
      $rendered = '';
      foreach ($options['thumbnailhover']['main_fields'] as $field => $use) {
        $rendered_field = $view->field[$field]->theme($node);
        if (($use !== 0) && !empty($rendered_field)) {
          $rendered .= '<div class="views-field-'. views_css_safe($view->field[$field]->field) .'">';
          $rendered .=  $rendered_field;
          $rendered .= '</div>';
        }
      }
    }
    else {
      $rendered = node_view(node_load($node->nid), $teaser, FALSE, FALSE);
    }
    $output .= theme('views_slideshow_thumbnailhover_no_display_teaser', $rendered, $id, $count);
  }
  $output .= "</div><!--close views_slideshow_thumbnailhover_no_display-->\n\n";
  return $output;
}

/**
 *  The html that will be placed into the element in its turn during its frame.
 */
function theme_views_slideshow_thumbnailhover_no_display_teaser($item, $id, $count) {
  $class = 'views_slideshow_thumbnailhover_slide views_slideshow_slide views-row-' . ($count + 1);
  if ($count) {
    $class = ' views_slideshow_thumbnailhover_hidden';
  }

  if ($count % 2) {
    $class .= ' views-row-even';
  }
  else {
    $class .= ' views-row-odd';
  }
  $output = '  <div id="views_slideshow_thumbnailhover_div_' . $id . '_' . $count . '" class="'. $class .'">' . "\n  ";
  $output .= $item . "\n";
  $output .= '  </div><!--close views_slideshow_thumbnailhover_div_' . $id . '_' . $count . '-->' . "\n\n";
  return $output;
}

/**
 *  These are teasers that may be pointed at with a mouse to change the element directly.
 */
function theme_views_slideshow_thumbnailhover_breakout_teasers($view, $items, $id, $options) {
  $output = '<div id="views_slideshow_thumbnailhover_breakout_teasers_' . $id . '" class="views_slideshow_thumbnailhover_breakout_teasers clear-block">' . "\n";
  if ($view->display_handler->uses_fields()) {
    foreach ($view->result as $count => $node) {
      $rendered_fields = '';
      foreach ($options['thumbnailhover']['breakout_fields'] as $field => $use) {
        $rendered_field = $view->field[$field]->theme($node);
        if (($use !== 0) && !empty($rendered_field)) {
          $rendered_fields .= '<div class="views-field-'. views_css_safe($view->field[$field]->field) .'">';
          $rendered_fields .=  $rendered_field;
          $rendered_fields .= '</div>';
        }
      }
      $output .= theme('views_slideshow_thumbnailhover_breakout_teaser', $rendered_fields, $id, $count);
    }
  }
  else {
    foreach ($items as $count => $item) {
      $output .= theme('views_slideshow_thumbnailhover_breakout_teaser', $item, $id, $count);
    }
  }

  $output .= "</div><!--close views_slideshow_thumbnailhover_breakout_teasers-->\n\n";

  return $output;
}

/**
 *  An individual breakout teaser.
 */
function theme_views_slideshow_thumbnailhover_breakout_teaser($item, $id, $count) {
  $class = 'views_slideshow_thumbnailhover_div_breakout_teaser';
  if (!$count) {
    $class .= ' views_slideshow_thumbnailhover_active_teaser';
  }

  if ($count % 2) {
    $class .= ' views-row-even';
  }
  else {
    $class .= ' views-row-odd';
  }
  $output = '  <div id="views_slideshow_thumbnailhover_div_breakout_teaser_' . $id . '_' . $count . '" class="' . $class . '">' . "\n  ";
  $output .= $item . "\n";
  $output .= '  </div><!--close views_slideshow_thumbnailhover_div_breakout_teaser_' . $id . '_' . $count . '-->' . "\n\n";
  return $output;
}


/**
 * Themed slideshow controls.
 */
function theme_views_slideshow_thumbnailhover_controls($id, $view, $options) {
  $output = '<div class="views_slideshow_thumbnailhover_controls views_slideshow_controls" id="views_slideshow_thumbnailhover_controls_' . $id . '">' . "\n";
  $output .= theme('views_slideshow_thumbnailhover_control_previous', $id, $view, $options);
  $output .= theme('views_slideshow_thumbnailhover_control_pause', $id, $view, $options);
  $output .= theme('views_slideshow_thumbnailhover_control_next', $id, $view, $options);
  $output .= "</div>\n";
  return $output;
}

/**
 * Themed Previous Control
 */
function theme_views_slideshow_thumbnailhover_control_previous($id, $view, $options) {
  return '<a href="#" id="views_slideshow_thumbnailhover_prev_' . $id . '" class="views_slideshow_thumbnailhover_previous views_slideshow_previous">' . t('Previous') . "</a>\n";
}

/**
 * Themed Pause Control
 */
function theme_views_slideshow_thumbnailhover_control_pause($id, $view, $options) {
  return '<a href="#" id="views_slideshow_thumbnailhover_playpause_' . $id . '" class="views_slideshow_thumbnailhover_pause views_slideshow_pause">' . t('Pause') . "</a>\n";
}

/**
 * Themed Next Control
 */
function theme_views_slideshow_thumbnailhover_control_next($id, $view, $options) {
  return '<a href="#" id="views_slideshow_thumbnailhover_next_' . $id . '" class="views_slideshow_thumbnailhover_next views_slideshow_next">' . t('Next') . "</a>\n";
}

function theme_views_slideshow_thumbnailhover_image_count($id, $view, $options) {
  $output = '<div class="views_slideshow_thumbnailhover_image_count views_slideshow_image_count" id="views_slideshow_thumbnailhover_image_count_' . $id . '"><span class="num"></span> ' . t('of') .' <span class="total"></span></div>';
  return $output;
}