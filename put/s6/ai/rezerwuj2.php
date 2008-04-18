<?
require_once('prolog.php');

$submit = isset($_POST['reserve']);

if ($submit)
{
	try
	{
		$database->beginTransaction();
	
		foreach ($basket as $id)
		{
			if (get_reservation_count_by_film_id($id) > 0)
				throw new Exception();
				
			set_reservation_by_film_id($id);
		}
	
		$database->commit();
		$basket = array();
	}
	catch(Exception $exception)
	{
		$database->rollback();
	}
}

require_once('epilog.php');

header("Location: koszyk.php");
?>