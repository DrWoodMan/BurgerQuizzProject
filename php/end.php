<?php

  require_once('includes/functions.php');

  $token=$_GET['token'];
  $idGame=$_GET['idGame'];

  $content=new User;
  $dbh = new DBmanage;
  $score= new Score;

  //on se connecte à la BDD, puis on vérifie si le token fourni est dans la base de données
  $dbh->connection();
  $content=loadUserFromToken($token, $dbh->getDb());
  $score= getScoreSpecific($content[0]->getLogin(), $idGame, $dbh->getDb());
  $userScore= round($score[0]->getScore()*TOTAL_PROPOSITIONS/(/*TODO: timestamp*3    /*/ 2),0);

  updateScore($score, $userScore, $dbh->getDb() );

  $content=createToken($content, $dbh->getDb());
  $return="<button type='button' class='btn btn-primary' onclick=window.location='user.php?token=".$content[0]->getToken()."'>Retour à l'écran de séléction</button>";

?>

<html>
	<head>
		<!-- Meta tags -->
		<meta charset="utf-8" />
		<meta name="author" content="Adrien LEBOURGEOIS - Arthur MESLIN" />
		<meta name="viewport" content="width=device-width, initial-scale=1" />

		<!-- Title -->
		<title>Salade Quiz - Fin de la partie <?php echo $idGame;?> </title>

    <!-- Css Styles -->
    <link href="../css\bootstrap.min.css" rel="stylesheet">

    <!-- Js Scripts -->
    <script src="../js/jquery-3.3.1.min.js" defer></script>
    <script src="../js/bootstrap.min.js" defer></script>
    <script src="../js/headerFooter.js" defer></script>
	</head>
	<body>
		<header>
    </header>
    
    </br>

    <div class="row" style="margin-left:10px;">
      <div class="col-lg-5"></div>
      <h4 class =" col-lg-2 " >Jeu n°<?php echo $idGame; ?></h4>
    </div>

  	</br>
    
		<form method="post">

      </br>
      </br>
      </br>
      </br>
      </br>
      </br>
      </br>

      <div class="row" >
        <div class="col-lg-4" style="margin-left:60px;"></div>
        <p class =" col-lg-3 " >Vous avez eu <?php echo($score[0]->getScore()." bonnes réponses sur ".TOTAL_PROPOSITIONS); ?> </p>
      </div>

      </br>

      <div class="row" >
        <div class="col-lg-5" style="margin-left:50px;"></div>
        <h5 class =" col-lg-3 " >Score: <?php echo ($userScore);?> </h5>
      </div>

      </br>
      </br>

      <div class="row" >
        <div class="col-lg-4" style="margin-left:105px;"></div>
	      <?php echo $return; ?>
      </div>

    </form>
	  <footer>
	  </footer>
	</body>
</html>
