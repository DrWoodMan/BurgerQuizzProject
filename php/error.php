<?php
  $idError=$_GET['idError'];
 ?>

<html>
	<head>
		<!-- Meta tags -->
		<meta charset="utf-8" />
		<meta name="author" content="Adrien LEBOURGEOIS - Arthur MESLIN" />
		<meta name="viewport" content="width=device-width, initial-scale=1" />

		<!-- Title -->
		<title>Salade Quiz - Erreur <?php echo $idError; ?></title>

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

    <div id="centerPart">
      <div class="row" style="margin-left:80px;">
        <div class="col-lg-4"></div>
        <h4 class =" col-lg-4 " >Erreur <?php echo $idError;?>: Page introuvable</h4>
      </div>

  	  </br>

      <form method="post">

        </br>
        </br>
        </br>
        </br>

        <div class="row" >
          <div class="col-lg-3" style="margin-left:120px;"></div>
          <p class =" col-lg-4 " style="text-align: center;">Oh non, il semblerait que votre lien ne soit pas valide! Mais ne vous en faites pas, retournez sur la page d'accueil, et mangez un peu de salade pour la route! ;)</p>
        </div>

        </br>
        </br>

        <div class="row" >
          <div class="col-lg-5" style="margin-left:80px;"></div>
          <button type="button" class="btn btn-primary" onclick=locateToAnywhere("..")>Retour</button>
        </div>

      </form>
    </div>
	  <footer>
	  </footer>
	</body>
</html>
