
<?php

require_once('DBmanage.php');


function loadUserFromLogin($login, $db ){

  $prep_fetch = $db->prepare("SELECT * FROM user WHERE login=:login");
  $prep_fetch->execute(array(':login'=>$login));
  $user = $prep_fetch->fetchAll(PDO::FETCH_CLASS,'User');
  return $user;

}




function loadUserFromToken($token, $db ){

  $prep_fetch = $db->prepare("SELECT * FROM user WHERE token=:token");
  $prep_fetch->execute(array(':token'=>$token));
  $user = $prep_fetch->fetchAll(PDO::FETCH_CLASS,'User');
  if($user[0]==NULL){
    header('Location: http://www.salade-quiz.fr/php/error.php');
  }
  return $user;

}



function loadGameFromId($id, $db ){

  $prep_fetch = $db->prepare("SELECT * FROM has WHERE id=:id");
  $prep_fetch->execute(array(':id'=>$id));
  $game = $prep_fetch->fetchAll(PDO::FETCH_CLASS,'Game');
  if($game[0]==NULL){
    header('Location: http://www.salade-quiz.fr/php/error.php');
  }
  return $game;

}




function createToken($user, $db ){

  //echo $user->getToken();
  $token = base_convert(hash('sha256', time() . mt_rand()), 16, 36);
  $user[0]->setToken($token);
  $update = $db->prepare("UPDATE user SET token=:token WHERE login=:login");
  $update->execute(array(':token'=>$token,':login'=>$user[0]->getLogin()));
  return $user;
}




function deconnection($user, $db){

  $user[0]->setToken(NULL);
  $update = $db->prepare("UPDATE user SET token=NULL WHERE login=:login");
  $update->execute(array(':login'=>$user[0]->getLogin()));

  header('Location: http://www.salade-quiz.fr');
}




function checkLogin($login, $db, $alert_login){

  $prep_fetch = $db->prepare("SELECT * FROM user WHERE login=:login");
  $prep_fetch->execute(array(':login'=>$login));
  $user = $prep_fetch->fetchAll(PDO::FETCH_CLASS,'User');
  if($user!=NULL){
    $alert_login = "<div class='alert alert-danger' role='alert'> Ce pseudonyme est déjà utilisé, merci d'en choisir un autre </div>";
  }
  return $alert_login;
}




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




function createUser($login, $pwd, $email, $db){


  $insertion = $db->prepare("INSERT INTO user (login, passwordHash, mailAddress ) VALUES (:login, :passwordHash, :mailAddress)");
  $insertion->execute(array(':login'=>$login,':passwordHash'=>$pwd, ':mailAddress'=>$email ));
  $user = loadUserFromLogin($login, $db);
  $user=createToken($user, $db);
  return $user;
}


function getScoreForGlobalPodium($db){

  $prep_fetch = $db->prepare("SELECT * FROM score ORDER BY score DESC LIMIT 5");
  $prep_fetch->execute(array());
  $score = $prep_fetch->fetchAll(PDO::FETCH_CLASS,'Score');
  return $score;

}




function getScoreForPersonalList($login, $db){

  $prep_fetch = $db->prepare("SELECT * FROM score WHERE login=:login ORDER BY timestamp DESC LIMIT 5");
  $prep_fetch->execute(array(':login' =>$login));
  $score = $prep_fetch->fetchAll(PDO::FETCH_CLASS,'Score');
  return $score;

}




function generateGlobalGamesPodium($globalScore, $i, $user){


  $global="<a id='id-user'>". $globalScore[$i]->getLogin()."</a><a> | </a> <a id='score'>". $globalScore[$i]->getScore()." pts</a>
  </br>
  <a id='id-game'>Partie ". $globalScore[$i]->getIdGame()." </a>
  </br>
  <button type='button' class='btn btn-primary' onclick=window.location='game.php?token=".$user[0]->getToken()."&idGame=".$globalScore[$i]->getIdGame()."'>Jouer</button>";

  return $global;
}




function generatePersonalHistory($specificScore, $i, $user){


  $specific="<a id='score' >".$specificScore[$i]->getScore()." pts</a>
  </br>
  <a id='id-game'>Partie ".$specificScore[$i]->getIdGame()."</a>
  </br>
  <button type='button' class='btn btn-primary' onclick=window.location='game.php?token=".$user[0]->getToken()."&idGame=".$specificScore[$i]->getIdGame()."'>Jouer</button>";


  return $specific;
}
