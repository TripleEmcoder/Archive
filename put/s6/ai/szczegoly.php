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

if (in_array($id, $basket))
{
?>
<p>Film znajduje się już w <a href='koszyk.php'>koszyku</a>.</p>
<?
}
else if (count($basket)>=3)
{
?>
<p>W <a href='koszyk.php'>koszyku</a> znajudą się już 3 filmy.</p>
<?
}
else
{
	if (isset($_POST['reserve']))
	{
		$basket[] = $id;
?>
<p>Film został dodany do <a href='koszyk.php'>koszyka</a>.</p>
<?		
	}
	else
	{
?>
<form action='' method='post'>
<input type='submit' name='reserve' value='Dodaj do koszyka' />
</form>
<?
	}
}

require_once('stopka.php');
require_once('epilog.php');
?>
