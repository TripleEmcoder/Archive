<?
require_once('prolog.php');

$id = filter_var($_GET['id'], FILTER_VALIDATE_INT);

$film = get_film_details_by_id($id);

$title = $film->title;

require_once('naglowek.php');
?>
<h2>O filmie</h2>
<table>
<tr>
	<th>Tytuł</th>
	<td><?=$film->title?></td>
</tr>
<tr>
	<th>Rok</th>
	<td><?=$film->release_year?></td>
</tr>
<tr>
	<th>Opis</th>
	<td><?=$film->description?></td>
</tr>
</table>
<h2>Kategorie</h2>
<ul>
<?
$query = prepare_query('query_select_film_categories_by_id');
$query->execute(array(':id' => $id));
while($category = $query->fetchObject())
	print("<li>$category->name</li>\n");
$query->closeCursor();
?>
</ul>
<h2>Obsada</h2>
<ul>
<?
$query = prepare_query('query_select_film_actors_by_id');
$query->execute(array(':id' => $id));
while($actor = $query->fetchObject())
	print("<li>$actor->first_name $actor->last_name</li>\n");
$query->closeCursor();
?>
</ul>
<h2>Rezerwacja</h2>
<?
if (get_reservation_count_by_film_id($id))
{
?>
<p>Film jest już zarezerwowany.</p>
<?
}
else if (in_array($id, $basket))
{
?>
<p>Film znajduje się w <a href='koszyk.php'>koszyku</a>.</p>
<?
}
else if (get_reservation_count_by_user() + count($basket) == 3)
{
?>
<p>Można zarezerwować maksymalnie 3 filmy.</p>
<?
}
else 
{
?>
<form action='dodaj.php?id=<?=$id?>' method='post'>
<input type='submit' name='reserve' value='Dodaj do koszyka' />
</form>
<?
}

require_once('stopka.php');
require_once('epilog.php');
?>
