<?php

$idError=$_GET['idError'];

// permet une redirection vers les pages d'erreurs avec un url préparé, donnant un affichage correct



switch ($idError) {
    case 400:
        header('Location: /php/error.php?idError=400');
        break;
    case 403:
        header('Location: /php/error.php?idError=403');
        break;
    case 404:
        header('Location: /php/error.php?idError=404');
        break;
    case 500:
        header('Location: /php/error.php?idError=500');
        break;
    case 502:
        header('Location: /php/error.php?idError=502');
        break;
    case 503:
        header('Location: /php/error.php?idError=503');
        break;
}
