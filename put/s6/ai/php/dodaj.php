<?
require_once('prolog.php');

$submit = isset($_POST['reserve']);
$id = filter_var($_GET['id'], FILTER_VALIDATE_INT);

function is_reservation_allowed($id)
{
	return get_reservation_count_by_film_id($id) == 0
		&& get_reservation_count_by_user() + count($basket) < 3;
}

if ($submit && $id && is_reservation_allowed($id))
		$basket[] = $id;

require_once('epilog.php');

header("Location: szczegoly.php?id=$id");
?>