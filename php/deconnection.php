<?php
require_once('includes/functions.php');

$token=$_GET['token'];
$content=new User;
$dbh = new DBmanage;

	$dbh->connection();
	$content=loadUserFromToken($token,$dbh->getDb());
  deconnection($content,$dbh->getDb());
  $dbh=NULL;
