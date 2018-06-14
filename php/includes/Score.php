<?php

/**
* \file Score.php
* \author Adrien LEBOURGEOIS - Arthur MESLIN
* \date 15 Juin 2018
* \brief Classe de structuration d'un Score
* \details Permet d'avoir en un seul objet tout le contenu des informations liées à un Score, que ce soit l'id de la Game, le login du User, le score ou la dernière fois que la partie a été lancée par le joueur
*/

  class Score{

    private $idGame; /*!< Identifiant de la Question. */
    private $login;/*!< Nom du User associé. */
    private $score;/*!< Valeur du Score. */
    private $time;/*!< Dernier moment où la partie à été jouée. */

    /**
    * \brief Retourne le login associé au Score.
    * \return string : le login associé au Score.
    */
    public function getLogin(){
      return $this->login;
    }

    /**
    * \brief Retourne l'Id de la partie associée au Score.
    * \return int : l'Id de la partie associée au Score.
    */
    public function getIdGame(){
      return $this->idGame;
    }

    /**
    * \brief Retourne la valeur du Score.
    * \return int : la valeur du Score.
    */
    public function getScore(){
      return $this->score;
    }

    /**
    * \brief Retourne le dernier moment où le User a joué à la partie.
    * \return string : le dernier moment où le User a joué à la partie.
    */
    public function getTime(){
      return $this->time;
    }

    /**
    * \brief Modifie la valeur du Score.
    * \param[in] int : la nouvelle valeur du Score .
    */
    public function setScore($newScore){
      $this->score=$newScore;
    }

    /**
    * \brief Met à jour la dernière utilisation par le User de la Game associée.
    * \param[in] string : le timestamp de la dernière fois où la Game associée au User a été lancée .
    */
    public function setTime($newTime){
      $this->time=$newTime;
    }
  }
