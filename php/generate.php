<?php
require_once('includes/functions.php');

$token=$_GET['token'];
$content=new User;
$dbh = new DBmanage;
$score=new Score;
$questions= new Question;
$link = new LinkGameQuestion;
$propositions = new Proposition;

//on se connecte à la BDD, puis on vérifie si le token fourni est dans la base de données
$dbh->connection();
$content=loadUserFromToken($token,$dbh->getDb());
$questions=selectRandomQuestions($dbh->getDb()); // on fait une selection de 3 questions aléatoires
$idGame=createNewGame($dbh->getDb()); // on instancie une nouvelle partie dans la base de données

for($i=0; $i<sizeof($questions) ;$i++){ // on affecte chaque question choisie aléatoirement à la partie nouvellement créé, et on y associe 5 propositions aléatoires
  $propositions= selectRandomPropositions($questions[$i]->getIdQuestion(), $dbh->getDb());

  for($j=0; $j<sizeof($propositions); $j++){
      $test =AssociatePropositionsWithGame($idGame[0], $questions[$i]->getIdQuestion() , $propositions[$j]->getIdProposition() ,$i , $j,$dbh->getDb());
      var_dump($test);
  }
}

$score=createScore($content[0]->getLogin(), $idGame[0], $dbh->getDb()); // On crée un score associé à la nouvelle partie et au joueur
header("Location: /php/game.php?token=".$token."&idGame=".$idGame[0]."&propositionNumber=1");