
<?php

require_once('includes/functions.php');

$token=$_GET['token'];
$content=new User;
$dbh = new DBmanage;
//on se connecte à la BDD, puis on vérifie si le login fourni est dans la base de données

$dbh->connection();
$content=loadUserFromToken($token,$dbh->getDb());

$globalScore=getScoreForGlobalPodium($dbh->getDb());
$specificScore=getScoreForPersonalList($content[0]->getLogin(), $dbh->getDb());


for($i=0;$i<sizeof($globalScore);$i++){
	$globalScore[$i] = generateGlobalGamesPodium($globalScore, $i, $content);
}

if(sizeof($globalScore)<5){
	for($i=sizeof($globalScore);$i<5;$i++){
		$globalScore[$i]=NULL;
	}
}

for($i=0;$i<sizeof($specificScore);$i++){
	$specificScore[$i] = generatePersonalHistory($specificScore, $i, $content);
}
echo"salut";

if(sizeof($specificScore)<5){
	for($i=sizeof($specificScore);$i<5;$i++){
		$specificScore[$i]=NULL;
	}
}
echo "aled";
	$generate= "<button type='button' class='btn btn-primary' onclick=window.location='generate.php?token=".$content[0]->getToken()."'>C'est parti!</button>";
echo "voici le bouton:";


//var_dump($dbh);
?>

<html>

	<head>
		<!-- Meta tags -->
		<meta charset="utf-8" />
		<meta name="author" content="Adrien LEBOURGEOIS - Arthur MESLIN" />
		<meta name="viewport" content="width=device-width, initial-scale=1" />

		<!-- Title -->
		<title>Salade Quiz - Utilisateur</title>

		<!-- Css Styles -->
		<link href="../css\bootstrap.min.css" rel="stylesheet">

		<!-- Js Scripts -->
		<script src="../js/jquery-3.3.1.min.js" defer></script>
		<script src="../js/bootstrap.min.js" defer></script>
		<script src="../js/headerFooter.js" defer></script>
		<script type="text/javascript" src="../js/js.cookie.js" defer></script>

	</head>





	<body>
		<header>
		</header>

	</br>

    <div class="row" style="margin-left:10px;">
      <div class="col-lg-1">
      </div>
      <h4 class =" col-lg-2 " >Meilleurs scores</h4>

      <div class="col-lg-2">
      </div>
      <h4 class =" col-lg-2 " i>Mon historique</h4>

			<div class="col-lg-2">
			</div>

			<p class =" col-lg-2 " i>Bonjour, <?php echo $content[0]->getLogin();?></p>

    </div>
  	</br>

		<form method="post">



		<div class="container form-group" >


      <!--Première section-->

			<div class="row">


				<div class="col-lg-1">
				</div>

				<div class=" col-lg-2"> <!-- Palmares-->
          <div class="row">
            <div>
							<?php echo $globalScore[0];?>
            </div>
          </div>
        </div>

				<div class="col-lg-2">
				</div>

        <div class=" col-lg-2" style="margin-left:50px;"> <!-- Historique personnel-->
          <div class="row">
            <div>
              <?php echo $specificScore[0];?>
            </div>
          </div>
        </div>
			</div>



    </br>

<!--Deuxième section-->

      <div class="row">

        <div class="col-lg-1">
        </div>

        <div class=" col-lg-2"> <!-- Palmares-->
          <div class="row">
            <div>
							<?php echo $globalScore[1];?>

            </div>
          </div>

        </div>

        <div class="col-lg-2">
        </div>

				<div class=" col-lg-2" style="margin-left:50px;"> <!-- Historique personnel-->
          <div class="row">
            <div>
							<?php echo $specificScore[1];?>

            </div>
          </div>
        </div>

        <div class="col-lg-2">
        </div>
        <h4 class =" col-lg-2 ">Générer une nouvelle partie</h4>
      </div>


    </br>

    <!--Troisième section-->


			<div class="row">

				<div class="col-lg-1">
				</div>

        <div class=" col-lg-2"> <!-- Palmares-->
          <div class="row">
            <div>
							<?php echo $globalScore[2];?>

            </div>
          </div>
        </div>

				<div class="col-lg-2">
				</div>

				<div class=" col-lg-2" style="margin-left:50px;">  <!-- Historique personnel-->
          <div class="row">
            <div>
							<?php echo $specificScore[2];?>

            </div>
          </div>

        </div>
        <div class="col-lg-2" style="margin-left:40px;">
        </div>
				<?php echo $generate; ?>
			</div>


    </br>
    <!--Quatrième section-->


    <div class="row">

      <div class="col-lg-1">
      </div>

      <div class=" col-lg-2"> <!-- Palmares-->
        <div class="row">
          <div>
						<?php echo $globalScore[3];?>

          </div>
        </div>
      </div>

      <div class="col-lg-2">
      </div>

			<div class=" col-lg-2" style="margin-left:50px;">   <!-- Historique personnel-->
        <div class="row">
          <div>
						<?php echo $specificScore[3];?>

          </div>
        </div>
      </div>
    </div>


</br>

<!--Cinquième section-->


    <div class="row">

      <div class="col-lg-1">
      </div>

      <div class=" col-lg-2"> <!-- Palmares-->
        <div class="row">
          <div>
						<?php echo $globalScore[4];?>

          </div>
        </div>
      </div>

      <div class="col-lg-2">
      </div>

			<div class=" col-lg-2" style="margin-left:50px;">  <!-- Historique personnel-->
        <div class="row">
          <div>
						<?php echo $specificScore[4];?>

          </div>
        </div>
      </div>
    </div>

	</div>
</form>





	<footer>
	</footer>

	</body>



</html>
