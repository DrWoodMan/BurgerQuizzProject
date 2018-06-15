
<?php

/**
* \file functions.php
* \author Adrien LEBOURGEOIS - Arthur MESLIN
* \date 15 Juin 2018
* \brief Fichier regroupant toutes les fonctions nécéssaires au bon fonctionnement du site
* \details Contient les fonctions de chargement depuis la BDD, de modification de la BDD, et de toute autre action se retrouvant à plusieurs endroits du site
*/



require_once('DBmanage.php');




/**
* \brief Retourne les informations de l'utilisateur stocké dans un objet User.
* \param[in] string $login: le login de l'utilisateur .
* \param[in] PDO $db: l'instance de la PDO .
* \return User $user : Un objet User contenant les informations de l'utilisateur.
*/
function loadUserFromLogin($login, $db ){

  $prep_fetch = $db->prepare("SELECT * FROM user WHERE login=:login");
  $prep_fetch->execute(array(':login'=>$login));
  $user = $prep_fetch->fetchAll(PDO::FETCH_CLASS,'User');
  return $user;

}



/**
* \brief Retourne les informations de l'utilisateur stocké dans un objet User.
* \param[in] string $token: le token associé à l'utilisateur .
* \param[in] PDO $db: l'instance de la PDO .
* \return User $user : Un objet User contenant les informations de l'utilisateur.
*/
function loadUserFromToken($token, $db ){

  $prep_fetch = $db->prepare("SELECT * FROM user WHERE token=:token");
  $prep_fetch->execute(array(':token'=>$token));
  $user = $prep_fetch->fetchAll(PDO::FETCH_CLASS,'User');
  if(!isset($user)){
    header('Location: /php/error.php?idError=403');
  }
  return $user;

}



/**
* \brief Modifie dans la BDD et sur l'objet contenant les informations de l'utilisateur le token permettant de naviguer dans le site.
* \param[in] User $user: les informations de l'utilisateur .
* \param[in] PDO $db: l'instance de la PDO .
* \return User $user : Un objet User contenant les informations mises à jour de l'utilisateur.
*/
function createToken($user, $db ){

  $token = base_convert(hash('sha256', time() . mt_rand()), 16, 36);
  $user[0]->setToken($token);
  $update = $db->prepare("UPDATE user SET token=:token WHERE login=:login");
  $update->execute(array(':token'=>$token,':login'=>$user[0]->getLogin()));
  return $user;
}



/**
* \brief Retourne le hash du mot de passe de l'utilisateur.
* \param[in] string $pwd: le mot de passe en clair de l'utilisateur .
* \param[in] PDO $db: l'instance de la PDO .
* \return string $pwdHash : le mot de passe crypté de l'utilisateur.
*/
function encryptionPassword($pwd, $db ){

  $pwdHash = base_convert(hash('sha256', $pwd ), 16, 36);
  return $pwdHash;
}



/**
* \brief Supprime le token de la BDD et redirige vers l'index du site.
* \param[in] User $user: les informations de l'utilisateur .
* \param[in] PDO $db: l'instance de la PDO .
*/
function deconnection($user, $db){

  $user[0]->setToken(NULL);
  $update = $db->prepare("UPDATE user SET token=NULL WHERE login=:login");
  $update->execute(array(':login'=>$user[0]->getLogin()));

  header('Location: ..');
}



/**
* \brief Vérification de la présence ou non du login entré par l'utilisateur dans la BDD.
* \param[in] string $login: le login de l'utilisateur .
* \param[in] PDO $db: l'instance de la PDO .
* \return string $alert_login : Une alerte qui empêche la création d'un compte utilisateur si le login est déjà dans la BDD.
*/
function checkLogin($login, $db){

  $alert_login=NULL;
  $prep_fetch = $db->prepare("SELECT * FROM user WHERE login=:login");
  $prep_fetch->execute(array(':login'=>$login));
  $user = $prep_fetch->fetchAll(PDO::FETCH_CLASS,'User');
  if($user!=NULL){
    $alert_login = "<div class='alert alert-danger' role='alert'> Ce pseudonyme est déjà utilisé, merci d'en choisir un autre </div>";
  }
  return $alert_login;
}



/**
* \brief Vérification de la présence de l'adresse mail ou non entrée par l'utilisateur dans la BDD.
* \param[in] string $email: l'adresse mail de l'utilisateur .
* \param[in] PDO $db: l'instance de la PDO .
* \return string $alert_mail : Une alerte qui empêche la création d'un compte utilisateur si l'adresse mail est déjà dans la BDD.
*/
function checkEmail($email, $db){
  $alert_mail=NULL;
  $prep_fetch = $db->prepare("SELECT * FROM user WHERE mailAddress=:email");
  $prep_fetch->execute(array(':email'=>$email));
  $user = $prep_fetch->fetchAll(PDO::FETCH_CLASS,'User');
  if($user!=NULL){
    $alert_mail = "<div class='alert alert-danger' role='alert'> Cette adresse mail est déjà utilisée, merci d'en choisir une autre </div>";
  }
  return $alert_mail;
}



/**
* \brief Création dans la BDD et en local d'un compte utilisateur.
* \param[in] string $login: le login de l'utilisateur .
* \param[in] string $pwd: le mot de passe hashé de l'utilisateur .
* \param[in] string $email: l'adresse mail de l'utilisateur .
* \param[in] PDO $db: l'instance de la PDO .
* \return User $user : Un objet User contenant les informations de l'utilisateur nouvellement créé.
*/
function createUser($login, $pwd, $email, $db){

  $insertion = $db->prepare("INSERT INTO user (login, passwordHash, mailAddress ) VALUES (:login, :passwordHash, :mailAddress)");
  $insertion->execute(array(':login'=>$login,':passwordHash'=>$pwd, ':mailAddress'=>$email ));
  $user = loadUserFromLogin($login, $db);
  $user=createToken($user, $db);
  return $user;
}



/**
* \brief Sélection des 5 meilleurs scores de la table Score de la BDD.
* \param[in] PDO $db: l'instance de la PDO .
* \return Score $score : Un tableau contenant les informations des 5 meilleures parties stockées dans la BDD.
*/
function getScoreForGlobalPodium($db){

  $prep_fetch = $db->prepare("SELECT * FROM score ORDER BY score DESC LIMIT 5");
  $prep_fetch->execute(array());
  $score = $prep_fetch->fetchAll(PDO::FETCH_CLASS,'Score');
  return $score;

}



/**
* \brief Sélection des scores de la table Score de la BDD, étant liés aux 5 dernières parties jouées par l'utilisateur.
* \param[in] string $login: le login de l'utilisateur .
* \param[in] PDO $db: l'instance de la PDO .
* \return Score $score : Un tableau contenant les informations des scores stockés dans la BDD étant liés aux 5 dernières parties jouées par l'utilisateur.
*/
function getScoreForPersonalList($login, $db){

  $prep_fetch = $db->prepare("SELECT * FROM score WHERE login=:login ORDER BY time DESC LIMIT 5");
  $prep_fetch->execute(array(':login' =>$login));
  $score = $prep_fetch->fetchAll(PDO::FETCH_CLASS,'Score');
  return $score;

}



/**
* \brief Génération automatique de chaque div de la section "Palmarès" contenant le nom de l'utilisateur correspondant, l'un des 5 meilleurs score de la BDD, l'Id de la partie où il a réussi à marquer ce score, et un bouton permettant à l'utilisateur connecté de tenter sa chance sur cette partie .
* \param[in] string $globalScore: un tableau contenant les informations du Palmarès .
* \param[in] string $i: le rang de la partie dans la BDD .
* \param[in] User $user: les informations de l'utilisateur .
* \return string $global : le HTML d'affichage des informations de la partie au rang $i dans la BDD.
*/
function generateGlobalGamesPodium($globalScore, $i, $user){


  $global="<a id='id-user'>". $globalScore[$i]->getLogin()."</a><a> | </a> <a id='score'>". $globalScore[$i]->getScore()." pts</a>
  </br>
  <a id='id-game'>Partie n°". $globalScore[$i]->getIdGame()." </a>
  </br>
  <button type='button' class='btn btn-primary' onclick=window.location='loadGame.php?token=".$user[0]->getToken()."&idGame=".$globalScore[$i]->getIdGame()."'>Jouer</button>";

  return $global;
}



/**
* \brief Génération automatique de chaque div de la section "Palmarès" contenant le nom de l'utilisateur correspondant, l'un des 5 meilleurs score de la BDD, l'Id de la partie où il a réussi à marquer ce score, et un bouton permettant à l'utilisateur connecté de tenter sa chance sur cette partie .
* \param[in] string $specificScore: un tableau contenant les informations de la section "Mon historique" .
* \param[in] string $i: le rang de la partie de l'utilisateur dans la BDD .
* \param[in] User $user: les informations de l'utilisateur .
* \return string $specific : le HTML d'affichage des informations de la partie au rang $i pour l'utilisateur.
*/
function generatePersonalHistory($specificScore, $i, $user){

  $specific="<a id='score' >".$specificScore[$i]->getScore()." pts</a>
  </br>
  <a id='id-game'>Partie n°".$specificScore[$i]->getIdGame()."</a>
  </br>
  <button type='button' class='btn btn-primary' onclick=window.location='loadGame.php?token=".$user[0]->getToken()."&idGame=".$specificScore[$i]->getIdGame()."'>Jouer</button>";
  return $specific;
}





function getScoreSpecific($login, $idGame, $db){

  $prep_fetch = $db->prepare("SELECT * FROM score WHERE login=:login AND idGame=:idGame");
  $prep_fetch->execute(array(':login' =>$login, ':idGame' => $idGame));
  $score = $prep_fetch->fetchAll(PDO::FETCH_CLASS,'Score');
  return $score;

}




function checkScore($login, $idGame, $db){

  $prep_fetch = $db->prepare("SELECT * FROM score WHERE login=:login AND idGame=:idGame");
  $prep_fetch->execute(array(':login'=>$login, ':idGame' => $idGame));
  $score = $prep_fetch->fetchAll(PDO::FETCH_CLASS,'Score');
  if(isset($score[0])){
    echo("partie déja jouée par l'utilisateur");
    return true;
  }
  echo("partie jamais jouée par l'utilisateur");
  return false;

}




function createScore($login, $idGame, $db){


  $insertion = $db->prepare("INSERT INTO score (idGame, login, score, time ) VALUES (:idGame, :login, :score, :time)");
  $insertion->execute(array(':idGame'=>$idGame,':login'=>$login, ':score'=>0 , ':time'=>time() ));
  $score = new Score;
  $score = $insertion->fetchAll(PDO::FETCH_CLASS,'Score');
  return $score;
}




function updateScore($score, $newScore, $db ){


  $update = $db->prepare("UPDATE score SET score=:score  WHERE login=:login AND  idGame=:idGame");
  $update->execute(array(':score' => $newScore, ':login'=>$score[0]->getLogin(), ':idGame' => $score[0]->getIdGame()));

}


function updateTime($score, $db ){


  $update = $db->prepare("UPDATE score SET  time=:time WHERE login=:login AND  idGame=:idGame");
  $update->execute(array(':login'=>$score[0]->getLogin(), ':idGame' => $score[0]->getIdGame(), ':time' => time()));

}


function selectRandomQuestions($db){

  $myRequest = "SELECT * FROM question  ORDER BY RAND() LIMIT ". QUESTION_NUMBER;
  $prep_fetch = $db->prepare($myRequest);
  $prep_fetch->execute(array());
  $questions = $prep_fetch->fetchAll(PDO::FETCH_CLASS,'Question');
  return $questions;

}






function createNewGame($db){

  $insertion = $db->prepare("INSERT INTO game(idGame) VALUES (NULL)");
  $insertion->execute();
  $prep_fetch = $db->prepare("SELECT * FROM game  ORDER BY idGame DESC LIMIT 1");
  $prep_fetch->execute();
  $newId = $prep_fetch->fetchAll();

  return $newId[0];

}




function selectRandomPropositions($i , $db){

  $myRequest="SELECT * FROM proposition WHERE idQuestion =:idQuestion  ORDER BY RAND() LIMIT ".PROPOSITION_NUMBER;
  $prep_fetch = $db->prepare($myRequest);
  $prep_fetch->execute(array(':idQuestion'=> $i));
  $propositions = $prep_fetch->fetchAll(PDO::FETCH_CLASS,'Proposition');
  return $propositions;

}




function associatePropositionsWithGame($idGame, $idQuestion, $idProposition ,$i ,$j ,$db){

  $insertion = $db->prepare("INSERT INTO has (idGame, idQuestion, idProposition, questionOrder, propositionOrder )
                                VALUES (:idGame, :idQuestion, :idProposition, :questionOrder, :propositionOrder)");
  $insertion->execute(array(':idGame'=>$idGame,':idQuestion'=>$idQuestion, 'idProposition'=>$idProposition, ':questionOrder' => $i, ':propositionOrder'=>$j));
  $LinkGameQuestion = $insertion->fetchAll(PDO::FETCH_CLASS,'LinkGameQuestion');
  return $LinkGameQuestion;
}





function getAllInformationsOfTheProposition($idGame, $i, $j , $db){

  $link=selectTargetedLinks($idGame, $i, $j , $db);
  $question=selectTargetedQuestions($link[0]->getIdQuestion(), $db);
  $proposition=selectTargetedPropositions($link[0]->getIdProposition(),$db);
  $theme= selectTargetedTheme($question[0]->getIdTheme(), $db);

  $content=new Game($question[0],$proposition[0],$theme[0]);
  return $content;
}





function selectTargetedLinks($idGame, $i, $j , $db){


  $prep_fetch = $db->prepare("SELECT * FROM has WHERE idGame =:idGame AND questionOrder=:questionOrder AND propositionOrder=:propositionOrder");
  $prep_fetch->execute(array(':idGame'=> $idGame, ':questionOrder'=>$i , ':propositionOrder'=>$j));
  $link = $prep_fetch->fetchAll(PDO::FETCH_CLASS,'LinkGameQuestion');

  return $link;

}



function selectTargetedQuestions($idQuestion, $db){


  $prep_fetch = $db->prepare("SELECT * FROM question  WHERE idQuestion=:idQuestion");
  $prep_fetch->execute(array(':idQuestion'=>$idQuestion));
  $questions = $prep_fetch->fetchAll(PDO::FETCH_CLASS,'Question');
  return $questions;

}




function selectTargetedPropositions($idProposition, $db){


  $prep_fetch = $db->prepare("SELECT * FROM proposition  WHERE idProposition=:idProposition");
  $prep_fetch->execute(array(':idProposition'=>$idProposition));
  $propositions = $prep_fetch->fetchAll(PDO::FETCH_CLASS,'Proposition');
  return $propositions;

}





function selectTargetedTheme($idTheme, $db){


  $prep_fetch = $db->prepare("SELECT * FROM theme  WHERE idTheme=:idTheme");
  $prep_fetch->execute(array(':idTheme'=>$idTheme));
  $themes = $prep_fetch->fetchAll(PDO::FETCH_CLASS,'Theme');
  return $themes;

}
