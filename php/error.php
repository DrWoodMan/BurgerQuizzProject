<?php
$idError=$_GET['idError'];


$typeError="Page introuvable";
$errorContent="Oh non, il semblerait que votre lien ne soit pas valide!";



switch ($typeError) {

    case 400:
        $typeError="Requête incorrecte";
        break;
    case 403:
        $typeError="Accès interdit";
        break;
    case 404:
        $typeError="Page introuvable";
        break;
    case 500:
        $typeError="Erreur de serveur interne";
        break;
    case 502:
        $typeError="Mauvais intermédiaire";
        break;
    case 503:
        $typeError="Service indisponible";
        break;

}

switch ($idError) {

    case 400:
        $errorContent="Je crois que votre navigateur n'a pas compris votre demande... ";
        break;
    case 403:
        $errorContent="Je pense que vous n'avez rien à faire ici! Certains auraient sanctionné une telle tentative d'intrusion... ";
        break;
    case 404:
        $errorContent="Oh non, il semblerait que votre lien ne soit pas valide!";
        break;
    case 500:
        $errorContent="La ressource que vous demandez est étrangement impossible à charger, nos équipes travaillent à y remédier.";
        break;
    case 502:
        $errorContent="Il s'avère qu'il y a un problème de communications entre certains serveurs... ";
        break;
    case 503:
        $errorContent="La page que vous demandez est surchargée ou en maintenance";
        break;

}

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
        <div class="col-lg-4">
        </div>
        <h4 class =" col-lg-4 " >Erreur <?php echo ($idError." : ".$typeError);?></h4>
      </div>


  	  </br>

		  <form method="post">
      </br>
      </br>
      </br>
      </br>

      <div class="row" >
        <div class="col-lg-3" style="margin-left:120px;">
        </div>

        <p class =" col-lg-4 " style="text-align: center;"><?php echo $errorContent;?> Mais ne vous en faites pas,
          retournez sur la page d'accueil, et mangez un peu de salade pour la route! ;)</p>
        </div>
        </br>
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
