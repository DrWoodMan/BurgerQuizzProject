
<?php
require_once('includes/functions.php');


$token=$_GET['token'];
$idGame=$_GET['idGame'];
$idQuestion=$_GET['idQuestion'];
$idProposition=$_GET['idProp'];
$time=$_GET['time'];
$content=new User;
$dbh = new DBmanage;
$game= new Game;
$score = new Score;
//on se connecte à la BDD, puis on vérifie si le login fourni est dans la base de données

$dbh->connection();
$content=loadUserFromToken($token,$dbh->getDb());






?>

<html>

	<head>
		<!-- Meta tags -->
		<meta charset="utf-8" />
		<meta name="author" content="Adrien LEBOURGEOIS - Arthur MESLIN" />
		<meta name="viewport" content="width=device-width, initial-scale=1" />

		<!-- Title -->
		<title>Salade Quiz - Partie n° <?php echo $idGame;?></title>

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
      <div class="col-lg-5">
      </div>
      <h4 class =" col-lg-2 " >Partie n°<?php echo $idGame;?></h4>
      <div class="col-lg-3">
      </div>
      <button type="button" class="btn btn-primary" onclick="window.Location='leave.php'">Quitter</button>

    </div>


  	</br>
    </br>
    </br>



    <div class="row" style="margin-left:10px;">
      <div class="col-lg-1">
      </div>
      <h4 class =" col-lg-2 " >Question n°x/X</h4>
    </div>




    <div class="row" style="margin-left:10px;">
      <div class="col-lg-10">
      </div>
      <h4 class =" col-lg-2 " >01:23</h4>
    </div>




    <div class="row" style="margin-left:10px;">
      <div class="col-lg-1">
      </div>
      <h4 class =" col-lg-4 " >Thème: Obichouvine</h4>
    </div>




  	</br>
    </br>
    </br>
    </br>
    </br>
    </br>

    <div class="row" style="margin-left:30px;">
      <div class="col-lg-4">
      </div>
      <h5 class =" col-lg-4 " >Edouard baladur ou un matelas bien dur?</h5>
    </div>

		<form method="post">
    </br>



</br>

<div class="row" >
  <div class="col-lg-4" style="margin-left:80px;">
  </div>

  <p class =" col-lg-3 " >Il a été au sein du gouvernement</p>
</div>

</br>


</br>

<div class="row" >
  <div class="col-lg-2" style="margin-left:20px;">
  </div>

  <button type="submit" class="btn btn-primary" value="1">Edouard baladur</button>
  <div class="col-lg-1"  style="margin-left:80px;">
  </div>
  <button type="submit" class="btn btn-primary" value="2">un matelas bien dur</button>

  <div class="col-lg-1"  style="margin-left:80px;">
  </div>

  <button type="submit" class="btn btn-primary" value="3">Les deux</button>

</div>


    </form>





	<footer>
	</footer>

	</body>



</html>
