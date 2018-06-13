<?php


require_once('includes/functions.php');

$token=$_GET['token'];
$idGame=$_GET['idGame'];
$content=new User;
$dbh = new DBmanage;
$score=new Score;
//on se connecte à la BDD, puis on vérifie si le token fourni est dans la base de données

$dbh->connection();
$content=loadUserFromToken($token,$dbh->getDb());
if(checkScore($content[0]->getLogin(), $idGame, $dbh->getDb())){

  $score=getScoreSpecific($content[0]->getLogin(), $idGame, $dbh->getDb());

  updateScore($score, 0 , $dbh->getDb());
}else{
   $score=createScore($content[0]->getLogin(), $idGame, $dbh->getDb());
}


header("Location: /php/game.php?token=".$token."&idGame=".$idGame."&propositionNumber=1");
