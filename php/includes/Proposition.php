<?php
  class Proposition
  {

    private $idProposition;
    private $proposition;
    private $solution;
    private $idQuestion;


    public function getIdProposition(){
      return $this->idProposition;
    }
    public function getProposition(){
      return $this->proposition;
    }
    public function getSolution(){
      return $this->solution;
    }
    public function getIdQuestion(){
      return $this->idQuestion;
    }


  }
