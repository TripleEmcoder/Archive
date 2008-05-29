<?
require_once('prolog.php');

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

require_once('epilog.php');

header('Location: koszyk.php');
?>
