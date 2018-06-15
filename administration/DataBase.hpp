/**
* \file DataBase.hpp
* \author Adrien LEBOURGEOIS - Arthur MESLIN
* \date 15 Juin 2018
* \brief Classe d'accès à la base de données
* \details Classe d'accès à la base de données utilisant MySQL Connector/C++
*/
#ifndef DATABASE_HHP
#define DATABASE_HHP

#include "includes.hpp"



class DataBase{

	public :
        /**
        * \brief Constructeur de la classe DataBase.
        * \details Initialise la connexion avec la base de données.
        * \param[in] std::string ip : adresse ip:port du serveur où se trouve la base de données.
        * \param[in] std::string user : identifiant de l'utilisateur de la base de données.
        * \param[in] std::string password : mot de passe associé à l'utilisateur de la base de données.
        * \param[in] std::string baseName : nom de le base de données utilisée.
        */
		DataBase(std::string ip, std::string user, std::string password, std::string baseName);

        /**
        * \brief Destructeur de la classe DataBase.
        * \details Romp la connexion avec la base de données.
        */
		~DataBase();

        /**
        * \brief Gère les erreurs de MySQL.
        * \details Extrait les erreurs fournies par MySQL et les place dans la std::string \e error.
        * \param[in] sql::SQLException &e : erreur renvoyée par MySQL.
        */
        void exception(sql::SQLException &e);

        /**
        * \brief Retourne la chaine contenant les erreurs.
        * \return std::string.
        */
        std::string getError();

        /**
        * \brief Retourne les thèmes.
        * \details Récupère les thèmes en base de données, les place des des structs Theme et renvoi un std::vector<Theme>.
        * \return std::vector<Theme> : vecteur de Theme.
        */
        std::vector <Theme> getThemes();

        /**
        * \brief Ajoute un thème à la base de données.
        * \param[in] std::string theme : nom du thème à ajouter à la base de données.
        */
        void addTheme(std::string theme);

        /**
        * \brief Modifie un thème en base de données.
        * \param[in] Theme theme : thème à modifier.
        */
        void modifyTheme(Theme theme);

        /**
        * \brief Supprime un thème en base de données.
        * \details Supprime le thème ainsi que les questions, propositions et parties associées.
        * \param[in] "unsigned int" idTheme : id en base de données du thème à supprimer.
        */
        void deleteTheme(unsigned int idTheme);

        /**
        * \brief Retourne les questions.
        * \details Récupère les questions en base de données, les place des des structs Question et renvoi un std::vector<Question>.
        * \param[in] "unsigned int" idTheme : id du theme correspondant.
        * \return std::vector<Question> : vecteur de Question.
        */
        std::vector<Question> getQuestions(unsigned int idTheme);

        /**
        * \brief Ajoute une question à la base de données.
        * \param[in] Question question : struct Question contenant la question.
        */
        void addQuestion(Question question);

        /**
        * \brief Modifie une question en base de données.
        * \param[in] Question question : question à modifier.
        */
        void modifyQuestion(Question question);

        /**
        * \brief Supprime une question en base de données.
        * \details Supprime la question ainsi que les propositions associées et parties associées.
        * \param[in] "unsigned int" idQuestion: id en base de de données de la question à supprimer.
        */
        void deleteQuestion(unsigned int idQuestion);

        /**
        * \brief Retourne les proposition.
        * \details Récupère les propositions en base de données, les place des des structs Proposition et renvoi un std::vector<Proposition>.
        * \param[in] "unsigned int" idQuestion : id de la question correspondante.
        * \return std::vector<Proposition> : vecteur de Proposition.
        */
        std::vector<Proposition> getPropositions(unsigned int idQuestion);

        /**
        * \brief Ajoute une proposition à la base de données.
        * \param[in] Proposition : struct Proposition contenant la proposition.
        */
        void addProposition(Proposition proposition);

        /**
        * \brief Modifie une proposition en base de données.
        * \param[in] Proposition proposition : proposition à modifier.
        */
        void modifyProposition(Proposition proposition);

        /**
        * \brief Supprime une proposition en base de données.
        * \details Supprime une proposition ainsi que les parties l'utilisant.
        * \param[in] unsigned int idProposition: id en base de de données de la proposition à supprimer.
        */
        void deleteProposition(unsigned int idProposition);

    private :
        sql::Driver *driver;
        sql::Connection *connection = NULL;
        sql::Statement *statement = NULL;
        sql::PreparedStatement *preparedStatement = NULL;
        sql::ResultSet *result = NULL;
        std::string error;
};
#endif