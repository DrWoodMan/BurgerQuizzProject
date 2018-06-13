<?php

header('Content-Type: text/plain; charset=utf-8');
header('Cache-control: no-store, no-cache, must-revalidate');
header('Pragma: no-cache');

$date = getdate(time() - /*timestamp de début de partie*/);

$data = array("minutes" => $date['minutes'], "seconds" => $date['seconds']);

$data = array($data);
$json = json_encode($data);
echo $json;

exit;
?>
