/**
* \file dataStructs.hpp
* \author Adrien LEBOURGEOIS - Arthur MESLIN
* \date 15 Juin 2018
* \details Structures utilisées pour les échanges avec la base de données.
* \brief Définit les structures Theme, Question et Proposition.
*/
#ifndef DATASTRUCTS_HPP
#define DATASTRUCTS_HPP

/** \struct Theme */
/**
* \details Structure utilisée pour les envois et réceptions de thèmes avec la base de données.
*/
typedef struct{
    unsigned int idTheme;/*!< Identifiant du thème. */
    std::string theme;/*!< Thème */
}Theme;

/** \struct Question */
/**
* \details Structure utilisée pour les envois et réceptions de questions avec la base de données.
*/
typedef struct{
    unsigned int idQuestion;/*!< Identifiant de la question. */
    std::string field1;/*!< Première partie de la question. */
    std::string field2;/*!< Deuxième partie de la question. */
    unsigned int idTheme;/*!< Identifiant du thème auquel apartient la question */
}Question;

/** \struct Proposition */
/**
* \details Structure utilisée pour les envois et réceptions de propositions avec la base de données.
*/
typedef struct{
    unsigned int idProposition;/*!< Identifiant de la proposition. */
    std::string proposition;/*!< Proposition. */
    unsigned int solution;/*!< Solution. */
    unsigned int idQuestion;/*!< Identifiant de la question à laquelle appartient la proposition */
}Proposition;

#endif