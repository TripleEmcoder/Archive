<?php
$database_name = 'mysql:host=localhost;dbname=memfis_s6_ai';
$database_user = 'memfis_s6_ai';
$database_password = ',r,god+d7+so';

$database = new PDO($database_name, $database_user, $database_password);

session_start();

if (!is_array($_SESSION['basket']))
	$_SESSION['basket'] = array();
	
$basket = $_SESSION['basket'];
?>