<?php
error_reporting(E_ALL);
include('includes/bootstrap.inc');
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

mail('koordynator-ds-it@sknd.org.pl', 'sknd.org.pl', 'Test');
mail('koordynator-ds-it@cognitis.pl', 'cognitis.pl', 'Test');
//mail('marcin.mikolajczak@hotmail.com', 'hotmail.com', 'Test');
mail('marcin.mikolajczak@sknd.org.pl', 'sknd.org.pl', 'Test');
mail('marcin.mikolajczak@cognitis.pl', 'cognitis.pl', 'Test');

die('Done.');

$to = 'marcin.mikolajczak@hotmail.com';

function example_mail($key, &$message, $params) {
var_dump($params);
switch($key) {
case 'notice':
var_dump($params);
$message['subject'] = 'Test z PHP: drupal_mail()';
$message['body'][] = "Prosze zignorowac.\n\nPozdrawiam,\nMarcin";
break;
}
}

$headers['from'] = 'www@cognitis.pl';

var_dump(drupal_get_messages());

//var_dump(mail($to, 'Test z PHP: mail()', "Prosze zignorowac.\n\nPozdrawiam,\nMarcin"));
//var_dump(drupal_mail('example', 'notice', 'marcin.mikolajczak@hotmail.com', NULL, 'www@cognitis.pl'));
var_dump(mimemail('www@cognitis.pl', $to, 'Test z PHP: mimemail()', "Prosze zignorowac.\n\nPozdrawiam,\nMarcin", $headers));

var_dump(drupal_get_messages());
?>