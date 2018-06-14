<?php
  class Question{

    private $idQuestion;
    private $field1;
    private $field2;
    private $idTheme;


    public function getIdQuestion(){
      return $this->idQuestion;
    }

    public function getField1(){
      return $this->field1;
    }

    public function getField2(){
      return $this->field2;
    }

    public function getIdTheme(){
      return $this->idTheme;
    }
  }
