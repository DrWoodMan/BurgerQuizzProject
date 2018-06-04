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

    var footer = '<nav class="navbar  navbar-light" style="background-color: #73FF6E; position: relative; bottom: 0px; ">'+
				'<span class="navbar-text" style="margin: auto;">'+
				'Copyright Salade-Quiz 2018'+
				'</span>'+
				'</nav>';


    $('footer').html(footer);
}


