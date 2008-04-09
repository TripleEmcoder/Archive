<?
require_once('prolog.php');

$query_select_film_basics_by_keyword = 
	'SELECT film_id, title, release_year FROM film'
	. ' WHERE title LIKE CONCAT(\'%\', :keyword, \'%\')';

$keyword = filter_var($_GET['keyword'], FILTER_SANITIZE_STRING);
?>
<html>
<head>
<title></title>
</head>
</body>
<form>
<input type='text' name='keyword' />
<input type='submit' />
</form>
<?
$query = $database->prepare($query_select_film_basics_by_keyword);
$query->execute(array(':keyword' => $keyword));

print("<table>\n");

print("<tr>\n");
print("<th>Tytuł</th>\n");
print("<th>Rok</th>\n");
print("</tr>\n");

while ($film = $query->fetchObject())
{
	print("<tr>\n");
	print("<td><a href='szczegoly.php?id=$film->film_id'>$film->title</a></td>\n");
	print("<td>$film->release_year</td>\n");
	print("</tr>\n");
}

print("</table>");
?>
</body>
</html>
