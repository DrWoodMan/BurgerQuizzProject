
<?php
require_once('includes/functions.php');

$alert=NULL;

 if(isset($_POST['pwd'])&& isset($_POST['login'])){
	$validation=true;
	$content=new User;
	$dbh = new DBmanage;
	//on se connecte à la BDD, puis on vérifie si le login fourni est dans la base de données
	$dbh->connection();
	$content=loadUserFromLogin($_POST['login'],$dbh->getDb());
  $pwd= encryptionPassword($_POST['pwd'], $dbh->getDb());
  print_r($pwd);


	if(count($content[0]) == NULL){
		$validation=false;

	}else if($content[0]->getPassword() != $pwd){// on vérifie si le mdp associé au login est le bon
		$validation=false;
	}else{
		$content=createToken($content, $dbh->getDb());
		  header('Location: /php/user.php?token='.$content[0]->getToken());


	}

  if($validation == false){
    $alert ="<div class='alert alert-danger' role='alert' style='width: 195px;' >Identifiants incorrects</div>";


  }

	$dbh=NULL;
	$_POST['pwd']=NULL;
}
?>

<html>
	<head>
		<!-- Meta tags -->
		<meta charset="utf-8" />
		<meta name="author" content="Adrien LEBOURGEOIS - Arthur MESLIN" />
		<meta name="viewport" content="width=device-width, initial-scale=1" />

		<!-- Title -->
		<title>Salade Quiz - Connexion</title>

    <!-- Css Styles -->
    <link href="../css\bootstrap.min.css" rel="stylesheet">

    <!-- Js Scripts -->
    <script src="../js/jquery-3.3.1.min.js" defer></script>
    <script src="../js/bootstrap.min.js" defer></script>
    <script src="../js/headerFooter.js" defer></script>
		<script src="../js/hide.js" defer></script>
	</head>
	<body>
		<header>
		</header>

  	</br>

		<div class="row">
			<div class="col-lg-1"></div>
			<h2 class =" col-lg-1 ">Connexion</h2>
		</div>

		</br>
		</br>
		</br>

		<form method="post" action="">

			<div class="container form-group" id="CenterPart">

				<div class="row">

					<div class="col-lg-9">

						<div class="row">
							<div class="col-lg-1"></div>
							<div class=" col-lg-3">
								<label>Pseudonyme</label>
								<input  type="text" placeholder="..." class="form-control" name="login"  value="<?= @$_POST['login'];?>"></input>
							</div>
						</div>

						</br>

						<div class="row">
							<div class="col-lg-1"></div>
								<div class=" col-lg-3">
									<label>Mot de passe</label>
									<input id='pwd' type="password" placeholder="..." class="form-control" name='pwd' value=""></input>
								</div>
							</div>

							</br>

							<div class="row">
								<div class="col-lg-1" style="margin-left:20px;"></div>
								<div><label>Afficher le mot de passe    </label></div>
								<div class=" form-check  col-lg">
									<input id="show-pwd" type="checkbox" class="form-check-input " onclick="hide();"></input>
								</div>
							</div>

							</br>

							<div class="row">
								<div class="col-lg-1"></div>
								<div class="col-lg-2">
									<button type="button" onclick="window.location='../index.html'"class="btn btn-primary">Retour</button>
								</div>
								<div class=" col-lg-1">
									<button type="submit" class="btn btn-primary">Valider</button>
								</div>
								<div class="col-lg-1"></div>
								<div class="col-lg-4"><?php echo($alert);?></div>
							</div>
							<div class="col-lg-2"></div>
						</div>
						<div class="col-lg-3">
							<img src="../resources/salade.jpg" style=" max-width: 125%; max-height: 125%;">
						</div>

					</div>

				</div>

			</div>
		</form>

	<footer>
	</footer>
	</body>
</html>
