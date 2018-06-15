/**
* \file MainWindow.hpp
* \author Adrien LEBOURGEOIS - Arthur MESLIN
* \date 15 Juin 2018
* \brief Classe principale.
* \details Classe principale faisant le lien entre la classe Controls et la classe DataBase
*/

#ifndef MAINWINDOW_HHP
#define MAINWINDOW_HHP


#include "includes.hpp"
#include "Controls.hpp"
#include "DataBase.hpp"

class MainWindow : public QMainWindow {

    Q_OBJECT

    public:
        /**
        * \brief Constructeur de la fenêtre principale.
        * \details Constructeur de la fenêtre principale créant les liens entre les contrôles et l'accès à la base de données.
        */
        MainWindow();

        /**
        * \brief Destructeur de la fenêtre principale.
        */        
        ~MainWindow();

        /**
        * \brief Affichage du popup des erreurs.
        * \details Récupère les erreurs de la base de données et les affiche.
        */
        bool dbErrorPopup();

        /**
        * \brief Récupération des thèmes.
        * \details Récupère les thèmes les insère dans le menu déroulant et affiche le bouton des questions.
        */
        void getThemes();

        /**
        * \brief Récupération des questions.
        * \details Récupère les questions les insère dans le menu déroulant et affiche le bouton des propositions.
        */
        void getQuestions();

        /**
        * \brief Récupération des propositions.
        * \details Récupère les propositions et les insère dans le menu déroulant.
        */
        void getPropositions();

    public slots:
        /**
        * \brief SLOT de passage en plein écran.
        * \param[in] int state : état renvoyé par la checkboxe de plein écran.
        */
        void slot_windowSize(int state);

        /**
        * \brief SLOT de connexion.
        * \details Récupères les éléments de connexion saisies, appelle la fonction de connexion de la base de données, affiche le bouton de déconnexion et la fenêtre des thèmes.
        */
        void slot_connection();

        /**
        * \brief SLOT de déconnexion.
        * \details Déconnecte de la base de données affiche la fenêtre de connexion et affiche les erreurs s'l y en a.
        */
        void slot_logout();

        /**
        * \brief SLOT d'ajout de thème.
        * \details Récupère le thème saisi, appelle la fonction d'ajout de thème en base de données et affiche les erreurs s'l y en a.
        */
        void slot_addTheme();

        /**
        * \brief SLOT de modification de thème.
        * \details Modifie le thème sélectionné avec le thème saisi, appelle la fonction de modification de thème en base de données et affiche les erreurs s'l y en a.
        */
        void slot_modifyTheme();

        /**
        * \brief SLOT de suppression de thème.
        * \details Supprime le thème sélectionné, appelle la fonction de suppression de thème en base de données et affiche les erreurs s'l y en a.
        */
        void slot_deleteTheme();

        /**
        * \brief SLOT d'affichage de la fenêtre des questions associées au thème.
        */
        void slot_relatedQuestions();

        /**
        * \brief SLOT d'affichage de la question sélectionnée dans les champs de saisie.
        * \param[in] int index : index de la checkboxe de la question sélectionnée.
        */
        void slot_copyQuestionInWritingFields(int index);

        /**
        * \brief SLOT d'ajout de question.
        * \details Récupère la question saisi, appelle la fonction d'ajout de question en base de données et affiche les erreurs s'l y en a.
        */
        void slot_addQuestion();

        /**
        * \brief SLOT de modification de question.
        * \details Modifie la question sélectionnée avec la question saisie, appelle la fonction de modification de question en base de données et affiche les erreurs s'l y en a.
        */
        void slot_modifyQuestion();

        /**
        * \brief SLOT de suppression de question.
        * \details Supprime la question sélectionné, appelle la fonction de suppression de question en base de données et affiche les erreurs s'l y en a.
        */
        void slot_deleteQuestion();

        /**
        * \brief SLOT d'affichage de la fenêtre des propositions associées à la question.
        */
        void slot_relatedPropositions();

        /**
        * \brief SLOT d'affichage de la proposition sélectionnée dans le champ de saisie.
        * \param[in] int index : index de la checkboxe de la proposition sélectionnée.
        */
        void slot_copyPropositionInWritingField(int index);

        /**
        * \brief SLOT d'ajout de proposition.
        * \details Récupère la proposition saisi, appelle la fonction d'ajout de thème en base de données et affiche les erreurs s'l y en a.
        */
        void slot_addProposition();

        /**
        * \brief SLOT de modification de proposition.
        * \details Modifie la proposition sélectionnée avec la proposition saisie, appelle la fonction de modification de proposition en base de données et affiche les erreurs s'l y en a.
        */
        void slot_modifyProposition();

        /**
        * \brief SLOT de suppression de proposition.
        * \details Supprime la proposition sélectionnée, appelle la fonction de suppression de proposition en base de données et affiche les erreurs s'l y en a.
        */
        void slot_deleteProposition();

    private:
    
        QSettings settings;/*!< Permet l'enregistrement des champs renseignés pour la connexion. */
        QVBoxLayout *mainLayout;/*!< Layout principal de la fenêtre. */
        Controls *controls;/*!< Classe des contrôles. */
        DataBase *dataBase;/*!< *Classe de la base de données. */

        std::vector<Theme> themes;/*!< Vecteur de Theme. */
        unsigned int idSelectedTheme;/*!< id du thème sélectionné. */
        std::vector<Question> questions;/*!< Vecteur de Question. */
        unsigned int idSelectedQuestion;/*!< id de la question sélectionnée. */
        std::vector<Proposition> propositions;/*!< Vecteur de Proposition. */

    
};
#endif
