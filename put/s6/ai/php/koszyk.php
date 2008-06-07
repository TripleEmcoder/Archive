<?
require_once('prolog.php');

$title = 'Koszyk';

require_once('naglowek.php');
?>
<div id='wyniki'>
<?
if (count($basket) == 0)
{
?>
<p>Pusty</p>
<?
}
else
{
	$query = $database->prepare($query_select_film_basics_and_reservation_count_by_3ids);

	for ($i = 0; $i < 3; $i++)
		$parameters[':id'.$i] = isset($basket[$i]) ? $basket[$i] : 0;

	$query->execute($parameters);
?>
<form action='usun.php' method='post'>
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
		print("<td><input type='submit' name='removes[$film->film_id]' value='Usuń z koszyka'>\n");

		if ($film->reservations > 0 )
				print("<td class='error'>Film jest już zarezerwowany.</td>\n");
				
		print("</tr>\n");
	}
?>
</table>
</form>
<form action='rezerwuj.php' method='post'>
<p><input type='submit' name='reserve' value='Rezerwuj koszyk'></p>
</form>
<?
}
?>
</div>
<?
require_once('stopka.php');
require_once('epilog.php');
?>
