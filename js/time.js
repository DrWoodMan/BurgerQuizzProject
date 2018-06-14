//récupération de l'id de la partie dans l'url
var url = window.location.href;
url = url.split('/');
url = url[4];
url = url.split('&');
url = url[1];
url = url.split('=');
var idGame = url[1];

//envoi d'un requête ajax contenant l'id de la partie dans la requête
setInterval(ajaxRequest, 1000, 'GET', '/php/time.php?idGame='+idGame, displayClock);

//récupération de la réponse du serveur et affichage du temps écoulé depuis le début de la partie
function displayClock(ajaxResponse){
  var time;

  time = JSON.parse(ajaxResponse);
  $('#time').html("temps écoulé : " + time.minutes + ":" + time.seconds);
}