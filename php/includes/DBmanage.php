<?php
require_once('Game.php');
require_once('User.php');
require_once('Score.php');
require_once('Constants.php');

class DBmanage{

    private $db;
    function connection(){

        $mysqlDsn = "mysql:host=".MYSQL_SERVER_IP.";port=".MYSQL_SERVER_PORT.";dbname=".MYSQL_DB_NAME.";charset=UTF8;";

        try{
        $this->db = new PDO($mysqlDsn, MYSQL_DB_USER, MYSQL_DB_PASSWORD);
        }
        catch(PDOException $e){
            echo 'Connexion échouée : ' . $e->getMessage();
            exit;
        }
        return $this->db;
    }
    public function getDb(){
        return $this->db;
    }
}