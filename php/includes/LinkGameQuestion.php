<?php
  class LinkGameQuestion
  {

    private $idGame;
    private $idQuestion;
    private $idProposition;
    private $questionOrder;
    private $propositionOrder;


    public function getIdGame(){
      return $this->idGame;
    }
    public function getIdQuestion(){
      return $this->idQuestion;
    }
    public function getIdProposition(){
      return $this->idProposition;
    }
    public function getQuestionOrder(){
      return $this->questionOrder;
    }
    public function getPropositionOrder(){
      return $this->propositionOrder;
    }

  }
