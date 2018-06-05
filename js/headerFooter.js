winLoad();

function winLoad(){


    var header = '<nav class="navbar navbar-light" style="background-color: #73FF6E; overflow:hidden">'+
				'<span class="navbar-brand">'+
				'<h1>Salade Quiz</h1>'+
				'</span>'+
				'<form class="form-inline">';

        if(document.location.href=='http://www.salade-quiz.fr/' || document.location.href=='http://www.salade-quiz.fr/index.html'){
          header += '<button onclick=locateToAnywhere("php/register.php") class="btn btn-outline-secondary btn-secondary" type="button" >INSCRIPTION</button>'+
				      '<button onclick=locateToAnywhere("php/connection.php") class="btn btn-outline-secondary btn-secondary" type="button" style="margin-left: 16px">CONNEXION</button>';
        }

        else if(document.location.href=='http://www.salade-quiz.fr/php/user.php' || document.location.href=='http://www.salade-quiz.fr/php/game.php' || document.location.href=='http://www.salade-quiz.fr/php/end.php'){
           header += '<button onclick=locateToAnywhere("..") class="btn btn-outline-secondary btn-secondary" type="button" >DECONNEXION</button>';
        }

				 header += '</form>'+
				'</nav>';

    $('header').html(header);

    var footer = '<nav class="navbar  navbar-light" style="background-color: #73FF6E; position: relative;  ">'+
				'<span class="navbar-text" style="margin: auto;">'+
				'Copyright Salade-Quiz 2018'+
				'</span>'+
				'</nav>';


	$('footer').html(footer);

	var windowHeight = $( window ).height();

	var headerHeight = $('header').height();

	var footerHeight = $('footer').height();

	var centerHeight = windowHeight - headerHeight - footerHeight;
	$('#centerPart').css('min-height', centerHeight);
}
/*
function windowHeight(){
	var w = window;
	var	d = document;
	var	e = d.documentElement;
	var	g = d.getElementsByTagName('body')[0];
	var	y = parseInt(w.innerHeight || e.clientHeight || g.clientHeight);

	if(isNaN(y)){
		return 0;
	}

	return y;
}
*/

function locateToAnywhere(data){
  window.location=data;
}
