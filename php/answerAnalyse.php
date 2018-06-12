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

//on se connecte à la BDD, puis on vérifie si le token fourni est dans la base de données

$dbh->connection();
$content=loadUserFromToken($token,$dbh->getDb());

if($value === $answer){
  $score= getScoreSpecific($content[0]->getLogin(), $idGame , $dbh->getDb());

  print_r($score[0]); // ok


  $score[0]->setScore($score[0]->getScore()+1);
  print_r($score[0]); //ok

  $newScore=$score[0]->getScore();
  print_r($newScore); //ok

  print_r($score[0]->getLogin());
  print_r($score[0]->getIdGame());

  $update=updateScore($score, $newScore, $dbh->getDb());
  print_r($update);
}
$oui='j\'ai pas encore géré cette page';

if($propositionNumber<=PROPOSITION_NUMBER*QUESTION_NUMBER){
  header("Location: http://www.salade-quiz.fr/php/game.php?token=".$token."&idGame=".$idGame."&propositionNumber=".$propositionNumber+1);
}else{
  header("Location: http://www.salade-quiz.fr/php/error.php?idError=".$oui);

}
