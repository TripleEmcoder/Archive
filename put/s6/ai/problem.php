<?
require_once('naglowek.php');

$reasons = array(
	'--wybierz powód--',
	'problem z kontem',
	'prośba o sprowadzenie filmu',
	'inne');

$email = filter_var($_POST['email'], FILTER_VALIDATE_EMAIL);
$reason = filter_var($_POST['reason'], FILTER_VALIDATE_INT);
$description = filter_var($_POST['description'], FILTER_SANITIZE_STRING);

if ($email && $reason && $description)
{
?>
<p>Wysłany</p>
<?
}
else
{
?>
<form action='' method='post'>
<input type='text' name='email' value='<?=$_POST['email']?>' />
<select name='reason'>
<?
foreach ($reasons as $key => $name)
{
	$selected = $key == $_POST['reason'] ? ' selected=\'true\'' : '';
	print("<option value='$key'$selected>$name</option>\n");
}
?>
</select>
<textarea name='description'><?=$_POST['description']?></textarea>
<input type='submit' />
</form>
<?
}
require_once('stopka.php');
require_once('epilog.php');
?>
