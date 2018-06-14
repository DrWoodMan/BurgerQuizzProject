<?php

/**
* \file Game.php
* \author Adrien LEBOURGEOIS - Arthur MESLIN
* \date 15 Juin 2018
* \brief Classe de structuration d'une partie, une 'Game'
* \details Permet d'avoir en un seul objet tout le contenu des informations liées à une Proposition de la partie, que ce soit la Question ou le Theme
*/


require_once('Question.php');
require_once('Proposition.php');
require_once('Theme.php');
require_once('LinkGameQuestion.php');

  class Game{

    private $question ;/*!< Contenu de la Question où est rendu le User. */
    private $proposition ;/*!< Contenu de la Proposition où est rendu le User. */
    private $theme;/*!< Contenu du Theme associé à la Question où est rendu le User. */


    /**
    * \brief Constructeur de la classe Game
    * \details Instancie dans l'objet Game toutes les données à afficher liées à la progression du joueur, sauf le temps, géré via time.php.
    * \param[in] string : le contenu de la Question où est rendu le User .
    * \param[in] string : le contenu de la Proposition où est rendu le User .
    * \param[in] string : le contenu du Theme associé à la Question où est rendu le User .
    */
    public function __construct($myQuestion, $myProposition, $myTheme){

    	$this->question = $myQuestion;
    	$this->proposition = $myProposition;
    	$this->theme = $myTheme;
    }

    /**
    * \brief Retourne le contenu de la Question où est rendu le User.
    * \return string : le contenu de la Question où est rendu le User.
    */
    public function getQuestion(){
      return $this->question;
    }

    /**
    * \brief Retourne le contenu de la Proposition où est rendu le User.
    * \return string : le contenu de la Proposition où est rendu le User.
    */
    public function getProposition(){
      return $this->proposition;
    }

    /**
    * \brief Retourne le contenu du Theme associé à la Question où est rendu le User.
    * \return string : le contenu du Theme associé à la Question où est rendu le User.
    */
    public function getTheme(){
      return $this->theme;
    }
  }
