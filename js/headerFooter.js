winLoad();

function winLoad(){

    var header = '<nav class="navbar navbar-light" style="background-color: #73FF6E; overflow:hidden">'+
				'<span class="navbar-brand">'+
				'<h1>Salade Quiz</h1>'+
				'</span>'+
				'<form class="form-inline">'+
				'<button href="#" class="btn btn-outline-secondary btn-secondary" type="button" >INSCRIPTION</button>'+
				'<button href="#" class="btn btn-outline-secondary btn-secondary" type="button" style="margin-left: 16px">CONNEXION</button>'+
				'</form>'+
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

