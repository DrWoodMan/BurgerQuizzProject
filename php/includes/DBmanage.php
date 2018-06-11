<?php

require_once('includes/Game.php');
require_once('includes/User.php');
require_once('includes/Score.php');





class DBmanage{

  private $db;

  function connection()
  {
    $mysqlServerIp = "127.0.0.1";
    $mysqlServerPort = "3306";
    $mysqlDbName = "saladeQuiz";
    $mysqlDbCharset = "UTF8";
    $mysqlDsn = "mysql:host=".$mysqlServerIp.";port=".$mysqlServerPort.";dbname=".$mysqlDbName.";charset=".$mysqlDbCharset.";";
    $myUserDb =  'saladeQuiz' ;
    $myPwdDb = 'saladeQuiz' ;
    try {
      $this->db = new PDO($mysqlDsn, $myUserDb, $myPwdDb);
      } catch (PDOException $e) {
        echo 'Connexion échouée : ' . $e->getMessage();
        exit;
      }
    return $this->db;
    }


    public function getDb(){
      return $this->db;
    }

}
