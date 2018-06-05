
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
		<script type="text/javascript" src="../js/js.cookie.js" defer></script>

	</head>





	<body>
		<header>
		</header>




		<form id="centerPart">
		</br>

		<div class="container form-group" >

			<div class="row">
				<div class="col-lg-1">
				</div>
				<h2 class =" col-lg-1 ">Inscription</h2>


			</div>
		</br>
		</br>
		</br>

			<div class="row">

				<div class="col-lg-1">
				</div>

				<div class=" col-lg-3">
					<label>Pseudonyme</label>
					<input name="choix" type="text" placeholder="..." class="form-control"></input>
				</div>

				<div class="col-lg-3">
				</div>

				<div class="col-lg-3">
					<label>Mot de passe</label>
					<input id='pwd' name="choix" type="password" placeholder="..." class="form-control"></input>

				</div>

			</div>

			</br>

			<div class="row">
				<div class="col-lg-8">
				</div>
				<div >
					<label>Afficher le mot de passe    </label>
				</div>
				<div class=" form-check  col-lg-1">
					<input id="show-pwd" type="checkbox" class="form-check-input " onchange="hide()"></input>
				</div>
			</div>

			</br>

			<div class="row">

				<div class="col-lg-1">
				</div>

				<div class=" col-lg-3">
					<label>Email</label>
					<input name="choix" type="email" placeholder="..." class="form-control" ></input>

				</div>

				<div class="col-lg-3">
				</div>

				<div class="col-lg-3">
					<label>Confirmer le mot de passe</label>
					<input id='confirm-pwd'name="choix" type="password" placeholder="..." class="form-control"></input>
				</div>

			</div>
		</br>

			<div class="row">

				<div class="col-lg-3">
				</div>
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
