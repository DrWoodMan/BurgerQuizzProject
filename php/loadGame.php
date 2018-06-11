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
echo($content[0]->getLogin());
if(checkScore($content[0]->getLogin(), $idGame, $dbh->getDb())){ //TODO: envoyer le score existant

  $score=getScoreSpecific($content[0]->getLogin(), $idGame, $dbh->getDb());
  echo $score[0]->getScore();

  updateScore($score, 0 , $dbh->getDb());
}else{
   $score=createScore($content[0]->getLogin(), $idGame, $dbh->getDb());
}
$load= "</br><button type='button'  onclick=window.location='game.php?token=".$token."&idGame=".$idGame."&idQuestion=1&idProp=1'>C'est parti!</button>";
echo $load;

header("Location: http://www.salade-quiz.fr/php/game.php?token=".$token."&idGame=".$idGame."&idQuestion=1&idProp=1");
