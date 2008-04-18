<?
require_once('prolog.php');

$submit = isset($_GET['keyword']);
$keyword = filter_var($_GET['keyword'], FILTER_SANITIZE_STRING);
$title = 'Wyszukiwarka';

require_once('naglowek.php');
?>
<h2>Nazwa</h2>
<form action=''>
<p>
	<input type='text' name='keyword' />
	<input type='submit' value='Szukaj' />
</p>
</form>
<?
if ($submit)
{
	$count = get_film_count_by_keyword($keyword);
?>
<h2>Wyniki</h2>
<p>Znaleziono <?=$count?> film(y/ów).</p>	 
<?
	if ($count > 0)
	{
?>
<table>
<tr>
	<th>Tytuł</th>
	<th>Rok</th>
</tr>
<?
		$query = prepare_query('query_select_film_basics_by_keyword');
		$query->execute(array(':keyword' => $keyword));
		
		while ($film = $query->fetchObject())
		{
			print("<tr>\n");
			print("<td><a href='szczegoly.php?id=$film->film_id'>$film->title</a></td>\n");
			print("<td>$film->release_year</td>\n");
			print("</tr>\n");
		}
		
		$query->closeCursor();
?>
</table>
<?
	}
}
require_once('stopka.php');
require_once('epilog.php');
?>
