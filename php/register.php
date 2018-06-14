<?php

	require_once('includes/functions.php');

	$alert_login=NULL;
	$alert_pwd=NULL;
	$alert_email=NULL;

	if(isset($_POST['pwd'])&& isset($_POST['login']) && isset($_POST['confirm-pwd']) && isset($_POST['email'])){
		$dbh = new DBmanage;
		//on se connecte à la BDD, puis on vérifie si le login fourni est dans la base de données
		$dbh->connection();

		if( !preg_match("#^([a-zA-Z0-9'àâéèêôùûçÀÂÉÈÔÙÛÇ[:blank:]-]{1,30})$#", $_POST['login']) && !preg_match("#^$#", $_POST['login']) ){
			$_POST['login']=NULL;
			$alert_login = "<div class='alert alert-danger' role='alert'> Le pseudonyme doit être composé uniquement de lettres et de chiffres</div>";
		}

		$alert_login= checkLogin($_POST['login'],$dbh->getDb(), $alert_login);

		if (preg_match("#^$#", $_POST['pwd']) || $_POST['pwd']!=$_POST['confirm-pwd'] || strlen($_POST['pwd'])<5 || strlen($_POST['pwd'])>100) {

			$alert_pwd ="<div class='alert alert-danger' role='alert'> Le mot de passe n'est pas identique lors de la réécriture ou comporte trop peu de caractères, il doit avoir au moins 6 caractères </div>";
		}

		$alert_email=checkEmail($_POST['email'], $dbh->getDb());

		if($alert_email==NULL && $alert_pwd==NULL && $alert_login==NULL){
			$pwd=encryptionPassword($_POST['pwd'], $dbh->getDb());
			$content=createUser($_POST['login'], $pwd, $_POST['email'], $dbh->getDb());
			header('Location: /php/user.php?token='.$content[0]->getToken());
		}
	}
	$dbh=NULL;
?>


<html>
	<head>
		<!-- Meta tags -->
		<meta charset="utf-8" />
		<meta name="author" content="Adrien LEBOURGEOIS - Arthur MESLIN" />
		<meta name="viewport" content="width=device-width, initial-scale=1" />

		<!-- Title -->
		<title>Salade Quiz - Inscription</title>

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

	<form id="centerPart" method="post" action="">
		</br>

		<div class="container form-group" >
			<div class="row">
				<div class="col-lg-1"></div>
				<h2 class =" col-lg-1 ">Inscription</h2>
			</div>

		</br>
		</br>
		</br>

			<div class="row">
				<div class="col-lg-1"></div>
				<div class=" col-lg-3">
					<label>Pseudonyme</label>
					<input name="login" type="text" placeholder="..." class="form-control"value="<?= @$_POST['login'];?>"></input>
				</div>

				<div class="col-lg-3">
					<?php echo $alert_login;?>
				</div>

				<div class="col-lg-3">
					<label>Mot de passe</label>
					<input id='pwd' name="pwd" type="password" placeholder="..." class="form-control"></input>
				</div>
			</div>

			</br>

			<div class="row">
				<div class="col-lg-5" ></div>
				<div class="col-lg-4" style="padding-left:195px;">
					<label>Afficher le mot de passe</label>
				</div>
				<div class=" form-check  col-lg-1">
					<div class="row" >
						<input id="show-pwd" type="checkbox" class="form-check-input " onchange="hide()" ></input>
					</div>
				</div>
				<div class=" col-lg-3"></div>
			</div>

			</br>

			<div class="row">
				<div class="col-lg-7"></div>
				<div class=" col-lg-3">
					<?php echo $alert_pwd;?>
				</div>
			</div>

			</br>

			<div class="row">
				<div class="col-lg-1"></div>

				<div class=" col-lg-3">
					<label>Email</label>
					<input name="email" type="email" placeholder="..." class="form-control" value="<?= @$_POST['email'];?>"></input>
				</div>

				<div class="col-lg-3">
					<?php echo $alert_email;?>
				</div>

				<div class="col-lg-3">
					<label>Confirmer le mot de passe</label>
					<input id='confirm-pwd'name="confirm-pwd" type="password" placeholder="..." class="form-control"></input>
				</div>
			</div>

			</br>

			<div class="row">
				<div class="col-lg-3"></div>
				<div class="col-lg-4">
					<button type="button" onclick="window.location='../index.html'"class="btn btn-primary">Retour</button>
				</div>
				<div class=" col-lg-4">
					<button type="submit" class="btn btn-primary">Valider</button>
				</div>
			</div>
		</div>
	</form>
	<footer>
	</footer>
	</body>
</html>
