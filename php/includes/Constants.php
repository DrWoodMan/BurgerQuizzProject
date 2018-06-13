<?php

define('MYSQL_SERVER_IP', "127.0.0.1");
define('MYSQL_SERVER_PORT', "3306");
define('MYSQL_DB_NAME', "saladeQuiz");
define('MYSQL_DB_USER', 'saladeQuiz');
define('MYSQL_DB_PASSWORD','saladeQuiz');


define('QUESTION_NUMBER', 3);// on définit ici la constante permettant de réguler la quantité de questions dans une partie

define('PROPOSITION_NUMBER', 3);// on définit ici la constante permettant de réguler la quantité de propositions affectées à une question dans une partie

define('TOTAL_PROPOSITIONS', QUESTION_NUMBER*PROPOSITION_NUMBER);// on définit ici la constante permettant d'obtenir, avec un code plus léger, le nombre total de propositions

 ?>