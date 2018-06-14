<?php

/**
* \file Constants.php
* \author Adrien LEBOURGEOIS - Arthur MESLIN
* \date 15 Juin 2018
* \brief Fichier stockant des données nécessaires au bon fonctionnement du site
*/

define('MYSQL_SERVER_IP', "127.0.0.1");/*!< IP du serveur. */
define('MYSQL_SERVER_PORT', "3306");/*!< Port du serveur. */
define('MYSQL_DB_NAME', "saladeQuiz");/*!< Nom de la BDD. */
define('MYSQL_DB_USER', 'saladeQuiz');/*!< Login de l'utilisateur de la BDD  . */
define('MYSQL_DB_PASSWORD','saladeQuiz');/*!< Mot de passe de l'utilisateur de la BDD. */


define('QUESTION_NUMBER', 3);/*!< Nombre de Question par partie. */

define('PROPOSITION_NUMBER', 3);/*!< Nombre de Proposition par Question. */

define('TOTAL_PROPOSITIONS', QUESTION_NUMBER*PROPOSITION_NUMBER);/*!< Nombre total de Proposition durant la partie, la 'Game'. */
