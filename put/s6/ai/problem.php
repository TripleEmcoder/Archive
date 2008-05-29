<?
require_once('prolog.php');

$reasons = array(
	'--wybierz powód--',
	'problem z kontem',
	'prośba o sprowadzenie filmu',
	'inne');

$submit = isset($_POST['submit']);
$email = filter_var($_POST['email'], FILTER_VALIDATE_EMAIL);
$reason = filter_var($_POST['reason'], FILTER_VALIDATE_INT);
$description = filter_var($_POST['description'], FILTER_SANITIZE_STRING);

$title = 'Problem';

require_once('naglowek.php');

if ($submit && $email && $reason && $description)
{
?>
<p>Wiadomość wysłana. Dziękujemy.</p>
<p>E-mail: <?=$email?></p>
<p>Powód: <?=$reasons[$reason]?></p>
<p>Opis: <?=$description?></p>
<?
}
else
{
?>
<script type='text/javascript'>
function setErrorDisplay(element, display)
{
	document.getElementById(element.id +'_error').style.display = display ? 'block' : 'none';
}

function validateEmail(element)
{
	var regex = /^[a-zA-Z0-9\.\_\-\+]+@([a-zA-Z0-9\_\-]+\.)+[a-zA-Z]{2,}$/;
	var valid = regex.test(element.value);
	setErrorDisplay(element, !valid);
	return valid;
}

function validateReason(element)
{
	var valid = element.selectedIndex != 0;
	setErrorDisplay(element, !valid);
	return valid;
}

function validateDescription(element)
{
	var valid = element.value != '';
	setErrorDisplay(element, !valid);
	return valid;
}

function validateProblem(form)
{
	var email = validateEmail(form.elements['email']);
	var reason = validateReason(form.elements['reason']);
	var description = validateDescription(form.elements['description']);
	
	return email && reason && description;
}

function updateLimit(element)
{
	element.value = element.value.substring(0, 50);
	document.getElementById(element.id + '_limit').innerHTML = 50 - element.value.length;
}
</script>
<form action='' method='post' onsubmit='return validateProblem(this)'>

<h2>E-mail</h2>
<p><input id='email' name='email' type='text' onblur='validateEmail(this)' value='<?=$_POST['email']?>'></p>
<div id='email_error' class='error' style='display: <?=$submit && !$email ? 'block' : 'none'?>'>Niepoprawny adres e-mail.</div>

<h2>Powód</h2>
<p><select id='reason' name='reason' onblur='validateReason(this)'>
<?
foreach ($reasons as $key => $name)
{
	$selected = $key == $_POST['reason'] ? ' selected=\'selected\'' : '';
	print("<option value='$key'$selected>$name</option>\n");
}
?>
</select></p>
<div id='reason_error' class='error' style='display: <?=$submit && !$reason ? 'block' : 'none'?>'>Nie wybrano powódu.</div>

<h2>Opis</h2>
<p><textarea id='description' name='description' onblur='validateDescription(this)' onkeypress='updateLimit(this)' onkeyup='updateLimit(this)' rows='10' cols='30'><?=$_POST['description']?></textarea></p>
<div id='description_error' class='error' style='display: <?=$submit && !$description ? 'block' : 'none'?>'>Nie opisano problemu.</div>
<div id='description_hint' class='hint'>Pozostało <span id='description_limit'></span>&nbsp;znaków.</div>

<p><input type='submit' name='submit' value='Wyślij'></p>
</form>
<script type='text/javascript'>
updateLimit(document.getElementById('description'));
</script>
<?
}
require_once('stopka.php');
require_once('epilog.php');
?>
