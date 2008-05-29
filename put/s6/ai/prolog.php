<?php
$query_select_film_count_by_keyword =
    'SELECT COUNT(*) FROM film'
    . ' WHERE title LIKE CONCAT(\'%\', :keyword, \'%\')';

$query_select_film_basics_by_keyword =
    'SELECT film_id, title, release_year FROM film'
    . ' WHERE title LIKE CONCAT(\'%\', :keyword, \'%\')';

$query_select_film_details_by_id =
    'SELECT film_id, title, release_year, description FROM film'
    . ' WHERE film_id = :id';

$query_select_film_categories_by_id =
    'SELECT name FROM category'
    . ' JOIN film_category USING (category_id)'
    . ' WHERE film_id = :id';

$query_select_film_actors_by_id =
    'SELECT first_name, last_name FROM actor'
    . ' JOIN film_actor USING (actor_id)'
    . ' WHERE film_id = :id';
    
$query_select_reservation_count_by_film_id =
	'select count(*) from reservation'
	.' where film_id = :id';

$query_select_reservation_count_by_user =
	'select count(*) from reservation'
	. ' where ip = :ip and browser = :browser';
	
$query_select_film_basics_and_reservation_count_by_3ids = 
	'SELECT film_id, title, release_year, count(ip) AS reservations FROM film'
	. ' LEFT JOIN reservation USING(film_id)'
	. ' WHERE film_id IN (:id0, :id1, :id2)'
	. ' GROUP BY film_id, title, release_year';

$query_insert_reservation = 
	'insert into reservation (film_id, ip, browser, timestamp)'
	. ' values (:id, :ip, :browser, NOW())';

$database_name = 'mysql:host=localhost;dbname=memfis_s6_ai';
$database_user = 'memfis_s6_ai';
$database_password = ',r,god+d7+so';

$database = new PDO($database_name, $database_user, $database_password);
$database->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

function prepare_query($name)
{
	global $database, $$name;
	static $queries = array();
	
	if (!isset($queries[$name]))
		$queries[$name] = $database->prepare($$name);
		
	return $queries[$name];
}

function get_film_count_by_keyword($keyword)
{
	$query = prepare_query('query_select_film_count_by_keyword');
	$query->execute(array(':keyword' => mysql_escape_like_string($keyword)));
	$result = $query->fetchColumn(0);
	$query->closeCursor();
	
	return $result;
}

function get_film_details_by_id($id)
{
	$query = prepare_query('query_select_film_details_by_id');
	$query->execute(array(':id' => $id));
	$result = $query->fetchObject();
	$query->closeCursor();

	return $result;
}

function get_reservation_count_by_film_id($id)
{
	$query = prepare_query('query_select_reservation_count_by_film_id');
	$query->execute(array(':id' => $id));
	$result = $query->fetchColumn(0);
	$query->closeCursor();
	
	return $result;
}

function get_reservation_count_by_user()
{
	$query = prepare_query('query_select_reservation_count_by_user');

	$query->execute(array(
		':ip' => $_SERVER['REMOTE_ADDR'],
		':browser' => $_SERVER['HTTP_USER_AGENT']
	));

	$result = $query->fetchColumn(0);
	$query->closeCursor();

	return $result;	
}

function set_reservation_by_film_id($id)
{
	$query = prepare_query('query_insert_reservation');
	
	$query->execute(array(
		':id' => $id,
		':ip' => $_SERVER['REMOTE_ADDR'],
		':browser' => $_SERVER['HTTP_USER_AGENT']
	));
}

function mysql_escape_like_string($text)
{
	return str_replace(array('\\', '%', '_'), array('\\\\', '\\%', '\\_'), $text);
}


session_start();

if (!is_array($_SESSION['basket']))
	$_SESSION['basket'] = array();
	
$basket = $_SESSION['basket'];
?>
