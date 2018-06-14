<?php

/**
* \file Theme.php
* \author Adrien LEBOURGEOIS - Arthur MESLIN
* \date 15 Juin 2018
* \brief Classe de structuration d'un Theme
* \details Permet d'avoir en un seul objet tout le contenu des informations liées à un Theme, que ce soit l'id ou le contenu
*/

  class Theme{

    private $idTheme;/*!< Identifiant du Theme. */
    private $theme;/*!< Contenu du Theme. */

    /**
    * \brief Retourne l'Id du Theme .
    * \return int : l'Id du Theme.
    */
    public function getIdTheme(){
      return $this->idTheme;
    }

    /**
    * \brief Retourne le contenu du Theme.
    * \return string : le contenu du Theme.
    */
    public function getTheme(){
      return $this->theme;
    }
  }
