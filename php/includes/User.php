<?php

/**
* \file User.php
* \author Adrien LEBOURGEOIS - Arthur MESLIN
* \date 15 Juin 2018
* \brief Classe de structuration d'un User
* \details Permet d'avoir en un seul objet tout le contenu des informations liées à un User: mot de passe, login, token, mail
*/

  class User{

    private $login;/*!< Nom du User. */
    private $passwordHash;/*!< Mot de passe hashé. */
    private $token;/*!< Token associé au User, pour ne pas avoir à retourner le mot de passe. */
    private $email;/*!< Adresse mail associé au User. */

    /**
    * \brief Retourne le login de l'utilisateur stocké dans un objet User.
    * \return string : le login de l'utilisateur.
    */
    public function getLogin(){
      return $this->login;
    }

    /**
    * \brief Retourne le mot de passe de l'utilisateur stocké dans un objet User.
    * \return string : le mot de passe de l'utilisateur.
    */
    public function getPassword(){
      return $this->passwordHash;
    }

    /**
    * \brief Retourne le token de l'utilisateur stocké dans un objet User.
    * \return string : le token de l'utilisateur.
    */
    public function getToken(){
      return $this->token;
    }

    /**
    * \brief Modifie le token de l'utilisateur stocké dans un objet User.
    * \param[in] string : le nouveau token de l'utilisateur .
    */
    public function setToken($newToken){
      $this->token=$newToken;
    }
  }
