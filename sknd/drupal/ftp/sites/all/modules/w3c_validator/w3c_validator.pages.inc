<?php
// $Id: w3c_validator.pages.inc,v 1.1.2.2 2009/10/05 10:33:38 pl2 Exp $

/**
 * @file
 * Page callbacks for the w3c validator module.
 */

/**
 * Module settings.
 *
 * @param string $form_state
 * @return void
 */
function w3c_validator_admin_settings($form_state) {
  $form = array();

  $form['w3c_validator_api_endpoint_uri'] = array(
    '#type' => 'textfield',
    '#title' => t('W3C Validator API endpoint URI'),
    '#description' => t('URI of the validator script where API call will be targeted. You could use http://validator.w3.org/check althought its not recommended.'),
    '#default_value' => variable_get('w3c_validator_api_endpoint_uri', ''),
    );

  return system_settings_form($form);
}

/**
 * Page callback to validate an URI.
 *
 * @return void
 */
function w3c_validator_validate_uri_page() {
  // In case we get the parameter in the url we make the processing without
  // submitting the form
  // We also see the $_GET['output] parameter in case it its used as a backend
  if (!empty($_GET['uri'])) {
    $uri = urldecode($_GET['uri']);
    if ($result = _w3c_validator_validate_uri($uri)) {
      switch ($_GET['output']) {
        case 'json':
          print drupal_json($result);
          return;
        default:
          _w3c_validator_set_validation_result($result);
      }
    }
  }

  $endpoint = variable_get('w3c_validator_api_endpoint_uri', '');
  if (empty($endpoint)) {
    drupal_set_message(t("W3C validator hasn't been configured yet."), 'warning');
    if (user_access('administer w3c_validator')) {
      return t('Endpoint must be set before you can use it. Configure W3C Validator at the <a href="!url">settings page</a>', array('!url' => url('admin/settings/w3c_validator')));
    }
    return '';
  }

  // Process the form and store the result using _w3c_validator_set_validation_result
  $uri_form = drupal_get_form('w3c_validator_validate_uri_form');

  $output = '';
  $output .= $uri_form;

  if ($result = _w3c_validator_get_validation_result()) {
    // General result info
    $headers = array('', '');
    $rows = array();

    $rows[] = array(t('URI'), l($result['uri'], $result['uri'], array('attributes' => array('target' => '_new'))));
    $rows[] = array(t('Validation result'), $result['validity'] == 'true' ? t('Valid'): t('Not valid'));

    $endpoint = variable_get('w3c_validator_api_endpoint_uri', '');
    $check_url = $endpoint . '?uri='. urlencode($result['uri']);

    $rows[] = array(t('Validator results'), l($check_url, $check_url, array('attributes' => array('target' => '_new'))));
    $rows[] = array(t('Doctype'), $result['doctype']);

    $output .= '<h2>'. t('Results') .'</h2>';
    $output .= theme('table', $headers, $rows);

    // Errors
    $headers = array(t('Line'), t('Col'), t('Message'));
    $rows = array();

    $output .= '<h2>' . t('Errors') .'</h2>';

    if (is_array($result['errors']) && !empty($result['errors'])) {
      foreach ($result['errors'] as $error) {
        $rows[] = array(
          check_plain($error['line']),
          check_plain($error['col']),
          check_plain($error['message']),
          );
      }
      $output .= theme('table', $headers, $rows);
    }
    else {
      $output .= t('No errors');
    }

    // Warnings
    $headers = array(t('Line'), t('Col'), t('Message'));
    $rows = array();

    $output .= '<h2>' . t('Warnings') .'</h2>';

    if (is_array($result['warnings']) && !empty($result['warnings'])) {
      foreach ($result['warnings'] as $warning) {
        $rows[] = array(
          check_plain($warning['line']),
          check_plain($warning['col']),
          check_plain($warning['message']),
          );
      }
      $output .= theme('table', $headers, $rows);
    }
    else {
      $output .= t('No warnings');
    }
  }

  return $output;
}

/**
 * Form where you enter a uri to validate.
 *
 * @param string $form_state
 * @return void
 */
function w3c_validator_validate_uri_form($form_state) {
  $form = array('#redirect' => FALSE);

  $form['uri'] = array(
    '#type' => 'textfield',
    '#title' => t('URI of the page to validate'),
    '#description' => t('Location (URL) of the webpage that you want to send to the W3C validator.'),
    '#required' => TRUE,
    );

  $form['validate'] = array(
    '#type' => 'submit',
    '#value' => t('Validate'),
  );

  return $form;
}

/**
 * Validate the uri and store the result.
 *
 * @param string $form
 * @param string $form_state
 * @return void
 */
function w3c_validator_validate_uri_form_submit($form, &$form_state) {
  $uri = $form_state['values']['uri'];

  $result = _w3c_validator_validate_uri($uri);

  _w3c_validator_set_validation_result($result);
}
