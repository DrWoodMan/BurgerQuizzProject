<?php

require_once('includes/DBmanage.php');


function loadUser($login, $db ){

  $prep_fetch = $db->prepare("SELECT * FROM user WHERE login=:login");
  $prep_fetch->execute(array(':login'=>$login));
  $user = $prep_fetch->fetchAll(PDO::FETCH_CLASS,'User');
  return $user;

}


function createToken($user, $db ){

  //echo $user->getToken();
  $token = base_convert(hash('sha256', time() . mt_rand()), 16, 36);
  $user[0]->setToken($token);
  $update = $db->prepare("UPDATE user SET token=:token WHERE login=:login");
  $update->execute(array(':token'=>$token,':login'=>$user[0]->getLogin()));
  return $user;
}

function checkToken($user, $db ){

  echo"POUIC POUIC POUIC";
  if($user->getToken() != NULL){
    echo"WOUMAAAAAA";
    return true;
  }
  else{
    echo"CAPITAINE, CAPITAIIIINE";
    return false;
  }
}
