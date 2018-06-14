<?php
require_once('includes/DBmanage.php');
header('Content-Type: text/plain; charset=utf-8');
header('Cache-control: no-store, no-cache, must-revalidate');
header('Pragma: no-cache');

$db = new DBmanage;

$db->connection();
$dbCo = $db->getDb();

$idGame = $_GET['idGame'];

//récupération en base de donnée de la date de début de la partie sous forme de timestamp
$query = $dbCo->prepare("SELECT time FROM score WHERE idGame =:idGame");
$query->execute(array(':idGame'=>$idGame));
$result = $query->fetchAll();
$startGameTime = $result[0];
$startGameTime = $startGameTime['time'];

//calcul de la différence avec la date actuelle
$timeDifference = time() - $startGameTime;

//mise sous forme de minutes et secondes
$time = getdate($timeDifference);
$data = array("minutes" => $time['minutes'], "seconds" => $time['seconds']);

//envoi au client
$json = json_encode($data);
echo $json;

exit;
?>
