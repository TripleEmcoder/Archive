<?
require_once('prolog.php');

$query_select_film_details_by_keyword = 
	'SELECT film_id, title, release_year FROM film'
	. ' WHERE film_id = :id';

$id = filter_var($_GET['id'], FILTER_VALIDATE_INT);
$title = '';

require_once('naglowek.php');

$query = $database->prepare($query_select_film_details_by_keyword);
$query->execute(array(':id' => $id));
$film = $query->fetchObject();
var_dump($film);

require_once('stopka.php');
?>
