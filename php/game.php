<?php
  require_once('includes/functions.php');

  $token = $_GET['token'];
  $idGame = $_GET['idGame'];
  $propositionNumber = $_GET['propositionNumber'];


  $content = new User;
  $dbh = new DBmanage;

  $substract = null;

  //on se connecte à la BDD, puis on vérifie si le token fourni est dans la base de données
  $dbh->connection();
  $content = loadUserFromToken($token, $dbh->getDb());

  for($i = 1; $i <= QUESTION_NUMBER; $i++){
    if($propositionNumber <= TOTAL_PROPOSITIONS){

      if($propositionNumber > PROPOSITION_NUMBER * ($i - 1) && $propositionNumber <= PROPOSITION_NUMBER * $i){

        $substract = $propositionNumber - (PROPOSITION_NUMBER * ($i - 1));
        $game = getAllInformationsOfTheProposition($idGame, $i - 1, $substract - 1, $dbh->getDb());
      }
    }
    else{
      header('Location: /php/answerAnalyse.php?token='.$content[0]->getToken()."&value=12&propositionNumber=".$propositionNumber."&answer=noAnswer&idGame=".$idGame);
    }
  }

  $leave = "<button type='button' class='btn btn-primary' onclick=window.location='leave.php?idGame=".$idGame."&token=".$content[0]->getToken()."'>Quitter</button>";

  $answer1 = "<button type='button' class='btn btn-primary' value='0' onclick=window.location='answerAnalyse.php?token=".$content[0]->getToken()."&value=0&propositionNumber=".$propositionNumber."&answer=".$game->getProposition()->getSolution()."&idGame=".$idGame."'> ".ucfirst($game->getQuestion()->getField1())."</button>";

  $answer2 = "<button type='button' class='btn btn-primary' value='1' onclick=window.location='answerAnalyse.php?token=".$content[0]->getToken()."&value=1&propositionNumber=".$propositionNumber."&answer=".$game->getProposition()->getSolution()."&idGame=".$idGame."'>".ucfirst($game->getQuestion()->getField2())."</button>";

  $answer3 = "<button type='button' class='btn btn-primary' value='2' onclick=window.location='answerAnalyse.php?token=".$content[0]->getToken()."&value=2&propositionNumber=".$propositionNumber."&answer=".$game->getProposition()->getSolution()."&idGame=".$idGame."'> Les deux </button>";

?>

<html>
	<head>
		<!-- Meta tags -->
		<meta charset="utf-8" />
		<meta name="author" content="Adrien LEBOURGEOIS - Arthur MESLIN" />
		<meta name="viewport" content="width=device-width, initial-scale=1" />

		<!-- Title -->
		<title>Salade Quiz - Partie n° <?php echo $idGame; ?></title>

    <!-- Css Styles -->
    <link href="../css\bootstrap.min.css" rel="stylesheet">

    <!-- Js Scripts -->
    <script src="../js/jquery-3.3.1.min.js" defer></script>
    <script src="../js/bootstrap.min.js" defer></script>
    <script src="../js/headerFooter.js" defer></script>
    <script src="../js/ajax.js" defer></script>
    <script src="../js/time.js" defer></script>

	</head>

	<body>
		<header>
    </header>

    </br>

    <div class="row" style="margin-left:10px;">
      <div class="col-lg-5"></div>
      <h4 class =" col-lg-2 " >Partie n°<?php echo $idGame; ?></h4>
      <div class="col-lg-3"></div>
				<?php echo $leave; ?>
    </div>

  	</br>
    </br>
    </br>

    <div class="row" style="margin-left:10px;">
      <div class="col-lg-1"></div>
      <h4 class =" col-lg-2 " >Question n°<?php echo ($propositionNumber . "/" . TOTAL_PROPOSITIONS); ?></h4>
    </div>

    <div class="row" style="margin-left:10px;">
      <div class="col-lg-9"></div>
      <h4 class =" col-lg-3 " id="time"></h4>
    </div>

    <div class="row" style="margin-left:10px;">
      <div class="col-lg-1"></div>
      <h4 class =" col-lg-4 " >Thème: <?php echo $game->getTheme()->getTheme(); ?></h4>
    </div>

  	</br>
    </br>

    <div class="row" style="margin-left:30px;">
      <div class="col-lg-4"></div>
      <h5 class =" col-lg-4 " ><?php echo (ucfirst($game->getQuestion()->getField1()) . ", " . $game->getQuestion()->getField2() . ", ou les deux?"); ?></h5>
    </div>

    <form method="post">

      </br>
      </br>

      <div class="row" >
        <div class="col-lg-4"></div>
        <div class ="col-lg-4" ><?php echo (ucfirst($game->getProposition()->getProposition())); ?></div>
        <div class="col-lg-4"></div>
      </div>

      </br>
      </br>

      <div class="row" style="margin-left: 3vw;">
        <div class="col-lg-3"></div>

        <div class="col-lg-2">
          <?php echo $answer1; ?>
        </div>

        <div class="col-lg-2">
            <?php echo $answer2; ?>
        </div>

        <div class="col-lg-2" >
          <?php echo $answer3; ?>
        </div>

        <div class="col-lg-3"></div>
      </div>

    </form>

	  <footer>
	  </footer>
	</body>
</html>
