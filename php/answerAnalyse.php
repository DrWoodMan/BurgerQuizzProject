<?php

require_once('includes/functions.php');


$token=$_GET['token'];
$value=$_GET['value'];
$propositionNumber=$_GET['propositionNumber'];
$answer=$_GET['answer'];
$idGame=$_GET['idGame'];

$content=new User;
$dbh = new DBmanage;
$score= new Score;

$newPropositionNumber=$propositionNumber+1;
$limitValue= TOTAL_PROPOSITIONS+1;

//on se connecte à la BDD, puis on vérifie si le token fourni est dans la base de données

$dbh->connection();
$content=loadUserFromToken($token,$dbh->getDb());

if($value === $answer){
  $score= getScoreSpecific($content[0]->getLogin(), $idGame , $dbh->getDb());



  $score[0]->setScore($score[0]->getScore()+1);

  $newScore=$score[0]->getScore();


  updateScore($score, $newScore, $dbh->getDb());
}
$oui="j'ai pas encore géré cette page";

if($propositionNumber<=TOTAL_PROPOSITIONS){
  header("Location: /php/game.php?token=".$token."&idGame=".$idGame."&propositionNumber=".$newPropositionNumber);
}else if($value== 12){
  header("Location: /php/end.php?token=".$token."&idGame=".$idGame);

}
