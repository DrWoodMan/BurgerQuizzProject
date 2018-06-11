winLoad();

function winLoad(){

    var deco_var ;
    var url='h';
    var i=1;
    var add='?';
    var size =document.location.href.length;
    while(document.location.href[i] != '?' &&  i!= size){
      url +=document.location.href[i];
      i++;
    }
    if(url.length != size){
      i=url.length+1;
      while(size > i){

        add +=document.location.href[i];

        i++;
      }
    }



    var header = '<nav class="navbar navbar-light" style="background-color: #73FF6E; overflow:hidden">'+
				'<span class="navbar-brand">'+
				'<h1>Salade Quiz</h1>'+
				'</span>'+
				'<form class="form-inline">';

        if(url=='http://www.salade-quiz.fr/' || url=='http://www.salade-quiz.fr/index.html'){
          header += '<button onclick=locateToAnywhere("php/register.php") class="btn btn-outline-secondary btn-secondary" type="button" >INSCRIPTION</button>'+
				      '<button onclick=locateToAnywhere("php/connection.php") class="btn btn-outline-secondary btn-secondary" type="button" style="margin-left: 16px">CONNEXION</button>';
        }

        else if(url=='http://www.salade-quiz.fr/php/user.php' || url=='http://www.salade-quiz.fr/php/game.php' || url=='http://www.salade-quiz.fr/php/end.php'){



           header += '<button  class="btn btn-outline-secondary btn-secondary" type="button" data-toggle="modal" data-target="#decoModal" >DECONNEXION</button>'+

           //<!-- Modal -->
            '<div id="decoModal" class="modal fade" role="dialog">' +
             '<div class="modal-dialog">'+

               //<!-- Modal content-->
              ' <div class="modal-content">'+
                 '<div class="modal-header">'+
                   '<h4 class="modal-title" style="text-align:center;">Voulez-vous vraiment vous déconnecter?</h4>'+
                   '<button type="button" class="close" data-dismiss="modal">&times;</button>'+

                 '</div>'+
                 '<div class="modal-body" style="text-align:center;">'+
                   '<p>Cette action entraînera une redirection vers l\'écran d\'accueil.</p>'+
                 '</div>'+
                 '<div class="modal-footer" style="text-align:center">'+
                   '<button type="button" class="btn btn-default" data-dismiss="modal">Fermer</button>'+
                   '<button onclick=locateToAnywhere("deconnection.php'+add+'") type="button" class="btn btn-default" data-dismiss="modal">Me déconnecter</button>'+

                 '</div>'+

               '</div>'+

             '</div>'+
           '</div>';
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
