<?php

/**
* \file LinkGameQuestion.php
* \author Adrien LEBOURGEOIS - Arthur MESLIN
* \date 15 Juin 2018
* \brief Classe de récupération des liens et ordres des données d'une partie
* \details Permet d'avoir en un seul objet les id de chaque élément nécessaire à l'affichage d'une Proposition, ainsi que l'ordre des Question et des Proposition
*/

  class LinkGameQuestion{

    private $idGame;/*!< Id de la Game lancée. */
    private $idQuestion;/*!< Id de la Question où est rendu l'User. */
    private $idProposition;/*!< Id de la Proposition où est rendu le User. */
    private $questionOrder;/*!< Placement de la Question dans la Game (si elle apparaît en première position, deuxième, ...). */
    private $propositionOrder;/*!< Placement de la Proposition dans la Question (si elle apparaît en première position, deuxième, ...). */


    /**
    * \brief Retourne l'Id de la Game lancée.
    * \return int : l'Id de la Game lancée.
    */
    public function getIdGame(){
      return $this->idGame;
    }

    /**
    * \brief Retourne l'Id de la Question où est rendu l'User.
    * \return int : l'Id de la Question où est rendu l'User.
    */
    public function getIdQuestion(){
      return $this->idQuestion;
    }

    /**
    * \brief Retourne l'Id de la Proposition où est rendu le User.
    * \return int : l'Id de la Proposition où est rendu le Usern.
    */
    public function getIdProposition(){
      return $this->idProposition;
    }

    /**
    * \brief Retourne le placement de la Question dans la Game (si elle apparaît en première position, deuxième, ...).
    * \return int : le placement de la Question dans la Game (si elle apparaît en première position, deuxième, ...).
    */
    public function getQuestionOrder(){
      return $this->questionOrder;
    }

    /**
    * \brief Retourne le placement de la Proposition dans la Question (si elle apparaît en première position, deuxième, ...).
    * \return int : le placement de la Proposition dans la Question (si elle apparaît en première position, deuxième, ...).
    */
    public function getPropositionOrder(){
      return $this->propositionOrder;
    }
  }
