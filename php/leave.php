<?php

require_once('includes/functions.php');

$score=new Score;
$idGame=$_GET['idGame'];
$log=$_GET['log'];
$dbh = new DBmanage;
$content=loadUserFromLogin($_POST['login'],$dbh->getDb());

//on se connecte à la BDD, puis on vérifie si le login fourni est dans la base de données

$dbh->connection();

$score=getScoreSpecific($log, $idGame, $dbh->getDb());

$score=setScoreToNull($score, $dbh->getDb());

// on crée un nouveau token que l'on associe à l'utilisateur
$content=createToken($content, $dbh->getDb());

// on renvoie l'utilisateur à la page d'utilisateur

header('Location: http://www.salade-quiz.fr/php/user.php?token='.$content[0]->getToken());
