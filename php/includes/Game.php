<?php
require_once('Question.php');
require_once('Proposition.php');
require_once('Theme.php');
require_once('LinkGameQuestion.php');

  class Game{

    private $question ;
    private $proposition ;
    private $theme;


    public function __construct($myQuestion, $myProposition, $myTheme){

    	$this->question = $myQuestion;
    	$this->proposition = $myProposition;
    	$this->theme = $myTheme;
    }

    public function getQuestion(){
      return $this->question;
    }

    public function getProposition(){
      return $this->proposition;
    }

    public function getTheme(){
      return $this->theme;
    }
  }
