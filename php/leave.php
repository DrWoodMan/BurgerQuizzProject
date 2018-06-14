<?php

require_once('includes/functions.php');

$score=new Score;
$idGame=$_GET['idGame'];
$token=$_GET['token'];
$dbh = new DBmanage;
$dbh->connection();
$content=new User;
//on se connecte à la BDD, puis on vérifie si le token fourni est dans la base de données

$content=loadUserFromToken($token,$dbh->getDb());


$score=getScoreSpecific($content[0]->getLogin(), $idGame, $dbh->getDb());

$score=updateScore($score, 0, $dbh->getDb());

// on crée un nouveau token que l'on associe à l'utilisateur
$content=createToken($content, $dbh->getDb());

// on renvoie l'utilisateur à la page d'utilisateur

header('Location: /php/user.php?token='.$content[0]->getToken());
