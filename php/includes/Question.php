<?php
/**
* \file Questions.php
* \author Adrien LEBOURGEOIS - Arthur MESLIN
* \date 15 Juin 2018
* \brief Classe de structuration d'une Question
* \details Permet d'avoir en un seul objet tout le contenu des informations liées à une Question, que ce soit l'id de la Question, celui du Theme associé, ou les deux parties du contenu
*/
  class Question{

    private $idQuestion;/*!< Id de la Question. */
    private $field1;/*!< Premier champ du contenu de la Question. */
    private $field2;/*!< Deuxième champ du contenu de la Question. */
    private $idTheme;/*!< Id du Theme associé. */

    /**
    * \brief Retourne l'Id de la Question.
    * \return int : l'Id de la Question.
    */
    public function getIdQuestion(){
      return $this->idQuestion;
    }

    /**
    * \brief Retourne le premier champ du contenu de la Question.
    * \return string : le premier champ du contenu de la Question.
    */
    public function getField1(){
      return $this->field1;
    }

    /**
    * \brief Retourne le deuxième champ du contenu de la Question.
    * \return string : le deuxième champ du contenu de la Question.
    */
    public function getField2(){
      return $this->field2;
    }

    /**
    * \brief Retourne l'Id du Theme associé à la Question.
    * \return int : l'Id du Theme associé à la Question.
    */
    public function getIdTheme(){
      return $this->idTheme;
    }
  }
