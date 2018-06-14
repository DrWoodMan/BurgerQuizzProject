<?php

/**
* \file DBmanage.php
* \author Adrien LEBOURGEOIS - Arthur MESLIN
* \date 15 Juin 2018
* \brief Classe de connexion à la BDD
* \details Permet d'avoir en un seul objet une instanciation de la BDD, isolée des autres fonctions pour éviter tout problème
*/

require_once('Game.php');
require_once('User.php');
require_once('Score.php');
require_once('Constants.php');

class DBmanage{

    private $db;/*!< Instance de PDO. */


    /**
    * \brief Créé l'instance de PDO avec les informations données dans Constants.
    * \return int : l'instance de la PDO nouvellement créé.
    */
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

    /**
    * \brief Retourne l'instance de la PDO.
    * \return PDO : l'instance de la PDO.
    */
    public function getDb(){
        return $this->db;
    }
}
