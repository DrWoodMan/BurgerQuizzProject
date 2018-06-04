
<?php?>

<html>

	<head>
		<!-- Meta tags -->
		<meta charset="utf-8" />
		<meta name="author" content="Adrien LEBOURGEOIS - Arthur MESLIN" />
		<meta name="viewport" content="width=device-width, initial-scale=1" />

		<!-- Title -->
		<title>Salade Quiz - Connexion</title>

		<!-- Css Styles -->
		<link href="css/style.css" rel="stylesheet" type="text/css" />
		<link href="css/bootstrap.min.css" rel="stylesheet" type="text/css" />
		<link href="css/bootstrap-theme.min.css" rel="stylesheet" type="text/css" />
    <link rel="shortcut icon" href="resources/favicon.ico"  type="image/x-icon"/>
    <link rel="icon" href="resources/favicon.ico"  type="image/x-icon"/>

		<!-- Js Scripts -->
		<script src="js/jquery.min.js" defer></script>
		<script src="js/bootstrap.min.js" defer></script>

		<script type="text/javascript" src="js/js.cookie.js" defer></script>
	</head>





	<body>
		<div id="header">


		</div>


		<div class="row">
			<div class="col-lg-1">
			</div>
			<h2 class =" col-lg-1 ">Connexion</h2>


		</div>
	</br>
	</br>
	</br>
		<form>

		<div class="container form-group" id="CenterPart">
      <div class="row">
      <div class="col-lg-9">
			<div class="row">

				<div class="col-lg-1">
				</div>

				<div class=" col-lg-3">
					<label>Pseudonyme</label>
					<input name="choix" type="text" placeholder="..." class="form-control"></input>
				</div>

			</div>

			</br>


			<div class="row">

				<div class="col-lg-1">
				</div>

				<div class=" col-lg-3">
					<label>Mot de passe</label>
					<input name="choix" type="password" placeholder="..." class="form-control" ></input>

				</div>

			</div>
		</br>



    <div class="row">
      <div class="col-lg-1" style="margin-left:20px;">
      </div>
      <div >
        <label>Afficher le mot de passe    </label>
      </div>
      <div class=" form-check  col-lg">
        <input id="show-pwd" type="checkbox" class="form-check-input "></input>
      </div>
    </div>


  </br>
			<div class="row">

				<div class="col-lg-1">
				</div>
				<div class="col-lg-2">
					<button type="button" onclick="window.location='index.html'"class="btn btn-primary">Retour</button>
				</div>
				<div class=" col-lg-1">
					<button type="submit" class="btn btn-primary">Valider</button>
				</div>
			</div>
	</div>
</form>

<div class="col-sm">
  <img src="resources/salade.jpg" style=" max-width: 125%; max-height: 125%;">
</div>
</div>
</div>




	<div id="footer">

	</div>

	</body>



</html>
