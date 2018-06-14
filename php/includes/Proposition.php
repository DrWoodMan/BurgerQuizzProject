<?php
/**
* \file Proposition.php
* \author Adrien LEBOURGEOIS - Arthur MESLIN
* \date 15 Juin 2018
* \brief Classe de structuration d'une Proposition
* \details Permet d'avoir en un seul objet tout le contenu des informations liées à une Proposition, que ce soit l'id de la Proposition, celui de la Question associée, le contenu ou la solution
*/
  class Proposition{

    private $idProposition;/*!< Id de la Proposition. */
    private $proposition;/*!< Contenu de la Proposition. */
    private $solution;/*!< Valeur de la solution. */
    private $idQuestion;/*!< Id de la Question associée. */

    /**
    * \brief Retourne l'Id de la Proposition.
    * \return int : l'Id de la Proposition.
    */
    public function getIdProposition(){
      return $this->idProposition;
    }

    /**
    * \brief Retourne le contenu de la Proposition.
    * \return string : le contenu de la Proposition.
    */
    public function getProposition(){
      return $this->proposition;
    }

    /**
    * \brief Retourne la valeur de la solution.
    * \return int : la valeur de la solution.
    */
    public function getSolution(){
      return $this->solution;
    }

    /**
    * \brief Retourne l'Id de la Question associée.
    * \return int : l'Id de la Question associée.
    */
    public function getIdQuestion(){
      return $this->idQuestion;
    }
  }
