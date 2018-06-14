<?php
  class Score{

    private $idGame;
    private $login;
    private $score;
    private $timestamp;


    public function getLogin(){
      return $this->login;
    }

    public function getIdGame(){
      return $this->idGame;
    }

    public function getScore(){
      return $this->score;
    }

    public function getTimestamp(){
      return $this->timestamp;
    }


    public function setScore($newScore){
      $this->score=$newScore;
    }
    
    public function setTimestamp($newTimestamp){
      $this->timestamp=$newTimestamp;
    }
  }
