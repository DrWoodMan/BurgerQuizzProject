<?php
  class User{

    private $login;
    private $passwordHash;
    private $token;
    private $email;


    public function getLogin(){
      return $this->login;
    }

    public function getPassword(){
      return $this->passwordHash;
    }

    public function getToken(){
      return $this->token;
    }

    public function setToken($newToken){
      $this->token=$newToken;
    }
  }
