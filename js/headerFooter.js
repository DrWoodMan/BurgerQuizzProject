'use strict';

winLoad();

function winLoad(){

    var deco_var , part1Url, part2Url, url, chaine, header, myUrl, token;
    var footer, windowHeight, headerHeight, centerHeight, footerHeight;
    url=document.location.href;

    myUrl= url.split('/');

    part1Url = myUrl[3];


    header = '<nav class="navbar navbar-light" style="background-color: #73FF6E; overflow:hidden">'+
				'<span class="navbar-brand">'+
				'<h1>Salade Quiz</h1>'+
				'</span>'+
				'<form class="form-inline">';

        if(part1Url=='' || part1Url=='index.html' ){
          header += '<button onclick=locateToAnywhere("php/register.php") class="btn btn-outline-secondary btn-secondary" type="button" >INSCRIPTION</button>'+
				      '<button onclick=locateToAnywhere("php/connection.php") class="btn btn-outline-secondary btn-secondary" type="button" style="margin-left: 16px">CONNEXION</button>';
        }

        else {
          part2Url = myUrl[4].split('?');
          token=part2Url[1].split('&');


            if(part1Url=='php'&&(part2Url[0]=='user.php' || part2Url[0]=='game.php' || part2Url[0]=='end.php')){



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
                     '<button onclick=locateToAnywhere("deconnection.php?'+token[0]+'") type="button" class="btn btn-default" data-dismiss="modal">Me déconnecter</button>'+

                   '</div>'+

                 '</div>'+

               '</div>'+
             '</div>';
              }
            }

				 header += '</form>'+
				'</nav>';

    $('header').html(header);

  footer = '<nav class="navbar  navbar-light" style="background-color: #73FF6E; position: relative;  ">'+
				'<span class="navbar-text" style="margin: auto;">'+
				'Copyright Salade-Quiz 2018'+
				'</span>'+
				'</nav>';


	$('footer').html(footer);

	windowHeight = $( window ).height();

	headerHeight = $('header').height();

	footerHeight = $('footer').height();

	centerHeight = windowHeight - headerHeight - footerHeight;
	$('#centerPart').css('min-height', centerHeight);
}


function locateToAnywhere(data){
  window.location=data;
}
