<?
require_once('prolog.php');

$query_select_film_basics_by_3ids = 
	'SELECT film_id, title, release_year FROM film'
	. ' WHERE film_id IN (:id0, :id1, :id2)';

$title = '';

require_once('naglowek.php');
?>
<div id='wyniki'>
<?
if (is_array($_POST['removes']))
{
	//ponizsza linijka jest 100% recepta na segfault
	//$removes = filter_var_array(array_keys($_POST['removes']), FILTER_VALIDATE_INT);
	
	$removes = array_keys($_POST['removes']);
	$removes = filter_var_array($removes, FILTER_VALIDATE_INT);

 	foreach ($removes as $remove)
	{
		$remove = array_search($remove, $basket);

		if ($remove !== false && isset($basket[$remove]))
			unset($basket[$remove]);
	}
	
	$basket = array_values($basket);
}

if (count($basket) == 0)
{
?>
<p>Pusty</p>
<?
}
else
{
	$query = $database->prepare($query_select_film_basics_by_3ids);

	for ($i = 0; $i < 3; $i++)
		$parameters[':id'.$i] = isset($basket[$i]) ? $basket[$i] : 0;

	$query->execute($parameters);
?>
<form action='' method='post'>
<table>
	<tr>
		<th>Tytuł</th>
		<th>Rok</th>
	</tr>
<?
	while ($film = $query->fetchObject())
	{
		print("<tr>\n");
		print("<td><a href='szczegoly.php?id=$film->film_id'>$film->title</a></td>\n");
		print("<td>$film->release_year</td>\n");
		print("<td><input type='submit' name='removes[$film->film_id]' value='Usuń z koszyka' />\n");
		print("</tr>\n");
	}
}
?>
</table>
</form>
</div>
<?
require_once('stopka.php');
require_once('epilog.php');
?>
