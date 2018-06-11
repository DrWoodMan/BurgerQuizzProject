<?php
echo "coucou ma biche";


$token=$_GET['token'];




$load= "</br><button type='button'  onclick=window.location='game.php?token=".$token."&idGame=2'>C'est parti!</button>";
echo $load;
