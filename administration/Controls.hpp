/**
* \file Controls.hpp
* \author Adrien LEBOURGEOIS - Arthur MESLIN
* \date 15 Juin 2018
* \brief Classe de création de l'interface utilisateur
* \details Classe (Q_OBJECT) regroupant les éléments (QWidgets et QLayouts) utilisés pour la création de l'interface utilisateur, les getters associés et des SLOTS de nécessitant pas de traitements particuliers.
*/
#ifndef CONTROLS_HHP
#define CONTROLS_HHP
#include "includes.hpp"

class Controls : public QWidget{

    Q_OBJECT

    public:
        /**
        * \brief Constructeur de la classe Controls. 
        */
        Controls();

        /**
        * \brief Destructeur de la classe Controls. 
        */
        ~Controls();

        /**
        * \brief Getter de la checkboxe de plein écran. 
        * \return Pointeur de QCheckBox.
        */
        QCheckBox *getFullscreen();

        /**
        * \brief Getter du botton "LOGOUT" de déconnexion. 
        * \return Pointeur de QPushButton.
        */
        QPushButton *getLogout();

        /**
        * \brief Getter du widget contenant les widgets d'authentification.
        * \return Pointeur de QWidget.
        */
        QWidget *getAuthenticationWidget();


        /**
        * \brief Getter du champ de saisie de l'IP du serveur. 
        * \return Pointeur de QLineEdit.
        */
        QLineEdit *getServerIP();

        /**
        * \brief Getter du champ de saisie du nom de la base de données. 
        * \return Pointeur de QLineEdit.
        */
        QLineEdit *getDataBaseName();
        /**
        * \brief Getter du champ de saisie de l'identifiant. 
        * \return Pointeur de QLineEdit.
        */
        QLineEdit *getLogin();

        /**
        * \brief Getter du champ de saisie de du mot de passe. 
        * \return Pointeur de QLineEdit.
        */
        QLineEdit *getPassword();

        /**
        * \brief Getter du bouton de validation de connecxion. 
        * \return Pointeur de QPushButton.
        */
        QPushButton *getValidateConnection();

        /**
        * \brief Getter du widget contenant les widgets de la fenêtre des thèmes. 
        * \return Pointeur de QWidget.
        */
        QWidget *getThemeWidget();

        /**
        * \brief Getter du champ de selection d'un thème. 
        * \return Pointeur de QComboBox.
        */
        QComboBox *getThemeSelection();

        /**
        * \brief Getter du champ de saisie des thèmes. 
        * \return Pointeur de QTextEdit.
        */
        QTextEdit *getThemeWritingField();

        /**
        * \brief Getter du bouton d'ajout d'un thème. 
        * \return Pointeur de QPushButton.
        */
        QPushButton *getAddTheme();

        /**
        * \brief Getter de modification d'un thème. 
        * \return Pointeur de QPushButton.
        */
        QPushButton *getModifyTheme();

        /**
        * \brief Getter du bouton de suppression d'un thème. 
        * \return Pointeur de QPushButton.
        */
        QPushButton *getDeleteTheme();

        /**
        * \brief Getter du bouton des questions du thème. 
        * \return Pointeur de QPushButton.
        */
        QPushButton *getRelatedQuestions();

        /**
        * \brief Getter du widget contenant les widgets de la fenêtre des questions. 
        * \return Pointeur de QWidget.
        */
        QWidget *getQuestionWidget();

        /**
        * \brief Getter du label du thème sélectionné. 
        * \return Pointeur de QLabel.
        */
        QLabel *getSelectedTheme();

        /**
        * \brief Getter du layout conteant le label du thème sélectionné. 
        * \return Pointeur de QHBoxLayout.
        */
        QHBoxLayout *getSelectedThemeLayout();

        /**
        * \brief Getter du layout occupant la place dans la fenêtre des questions pour le layout contenant le label du thème sélectionné. 
        * \return Pointeur de QHBoxLayout.
        */
        QHBoxLayout *getQuestionPlaceholderLayout();

        /**
        * \brief Getter du champ de sélection de question. 
        * \return Pointeur de QComboBox.
        */
        QComboBox *getQuestionSelection();

        /**
        * \brief Getter du champ de saisie de la première partie de la question.
        * \return Pointeur de QLineEdit.
        */
        QLineEdit *getQuestionWritingField1();

        /**
        * \brief Getter du champ de saisie de la deuxième partie de la question.
        * \return Pointeur de QLineEdit.
        */
        QLineEdit *getQuestionWritingField2();

        /**
        * \brief Getter du bouton d'ajout d'une question. 
        * \return Pointeur de QPushButton.
        */
        QPushButton *getAddQuestion();

        /**
        * \brief Getter du bouton de modificaton d'une question. 
        * \return Pointeur de QPushButton.
        */
        QPushButton *getModifyQuestion();

        /**
        * \brief Getter du bouton de suppression d'une question. 
        * \return Pointeur de QPushButton.
        */
        QPushButton *getDeleteQuestion();

        /**
        * \brief Getter du bouton des propositions d'une question. 
        * \return Pointeur de QPushButton.
        */
        QPushButton *getRelatedPropositions();

        /**
        * \brief Getter du widget contenant les widgets de la fenêtre des propositions. 
        * \return Pointeur de QWidget.
        */
        QWidget *getPropositionWidget();

        /**
        * \brief Getter du layout occupant la place dans la fenêtre des propositions pour le layout contenant le label du thème sélectionné. 
        * \return Pointeur de QHBoxLayout.
        */
        QHBoxLayout *getPropositionPlaceholderLayout();

        /**
        * \brief Getter de du label de la question selectionnée. 
        * \return Pointeur de QLabel.
        */
        QLabel *getSelectedQuestion();

        /**
        * \brief Getter du champ de selection des propositions. 
        * \return Pointeur de QComboBox.
        */
        QComboBox *getPropositionSelection();

        /**
        * \brief Getter du champ de saisie des propositions. 
        * \return Pointeur de QTextEdit.
        */
        QTextEdit *getPropositionWritingField();

        /**
        * \brief Getter du bouton d'ajout d'une proposition. 
        * \return Pointeur de QPushButton.
        */
        QPushButton *getAddProposition();

        /**
        * \brief Getter du bouton de modification d'une proposition. 
        * \return Pointeur de QPushButton.
        */
        QPushButton *getModifyProposition();

        /**
        * \brief Getter du bouton de suppression d'une proposition. 
        * \return Pointeur de QPushButton..
        */
        QPushButton *getDeleteProposition();

        /**
        * \brief Getter de la checkboxe de la réponse 1. 
        * \return Pointeur de QRadioButton.
        */
        QRadioButton *getTheOne();

        /**
        * \brief Getter de la checkboxe de la réponse 2. 
        * \return Pointeur de QRadioButton.
        */
        QRadioButton *getTheOther();

        /**
        * \brief Getter de la checkboxe de la réponse 3. 
        * \return Pointeur de QRadioButton.
        */
        QRadioButton *getBoth();


    public slots:
        /**
        * \brief SLOT d'affichage du mot de passe.
        * \details Affiche le mot de passe saisi en fonction de l'état de la checkboxe associée.
        * \param[in] int state : état renvoyé par la checkboxe d'affichage du mot de passe.
        */
        void slot_showPassword(int state);

        /**
        * \brief SLOT d'affichage du thème sélectionné dans le champ de saisie de thème.
        * \details Affiche le thème sélectionné dans le champ de saisie en vue de le modifier...
        * \param[in] QString str : du thème sélectionné.
        */
        void slot_copyThemeInWritingField(QString str);

        /**
        * \brief SLOT de retour à la fenêtre des thèmes.
        * \details Effectue la permutation entre le widget des questions et celui des thèmes.
        */
        void slot_backToThemes();

        /**
        * \brief SLOT de retour à la fenêtre des questions.
        * \details Effectue la permutation entre le widget des propositions et celui des questions.<BR> Enlève le layout contenant le thème sélectionné de la fenêtre des propositions pour le replacer dans la fenêtre des questions.
        */
        void slot_backToQuestions();

    private:
        QSettings settings;/*!< Permet l'enregistrement des champs renseignés pour la connexion. */
        QVBoxLayout *mainLayout;/*!< Layout principal. */

        QCheckBox *fullscreen;/*!< Case de mise en plein écran. */
        QPushButton *logout;/*!< Bouton d edéconnexion. */

        QWidget *authenticationWidget;/*!< Widget contenant les widgets d'authentification. */
        QLineEdit *serverIP;/*!< Champ de saisie de l'IP et du port du serveur. */
        QLineEdit *dataBaseName;/*!< Champ de saisie du nom de la base de données. */
        QLineEdit *login;/*!< Champ de saisie de l'utilisateur de la base de données'. */

        QLineEdit *password;/*!< Champ de saisie du mot de passe de la base de données. */
        QCheckBox *showPassword;/*!< Case d'affichage du mot de passe. */
        QPushButton *validateConnection;/*!< Bouton de validation de connexion. */

        QWidget *themeWidget;/*!< Widget contenant les widgets des thèmes. */
        QComboBox *themeSelection;/*!< Menu déroulant de sélection de thème. */
        QPushButton *deleteTheme;/*!< Bouton de suppression de thème. */
        QPushButton *relatedQuestions;/*!< Bouton de questions associées. */
        QTextEdit *themeWritingField;/*!< Champ de saisie de saisie de thème. */
        QPushButton *modifyTheme;/*!< Bouton de modification de thème. */
        QPushButton *addTheme;/*!< Bouton d'ajout de thème. */

        QWidget *questionWidget;/*!< Widget contenant les widgets des questions. */
        QHBoxLayout *questionPlaceholderLayout;
        QHBoxLayout *selectedThemeLayout;
        QLabel *selectedTheme;/*!< Indication du thème sélectionnée. */
        QComboBox *questionSelection;/*!< Menu déroulant de sélection de thème. */
        QPushButton *deleteQuestion;/*!< Bouton de suppression de question. */
        QPushButton *relatedPropositions;/*!< Bouton des propositions associées. */
        QLineEdit *questionWritingField1;/*!< Champ de saisie de la partie 1  de la question. */
        QLineEdit *questionWritingField2;/*!< Champ de saisie de la partie 2  de la question. */
        QPushButton *modifyQuestion;/*!< Bouton de modification de question. */
        QPushButton *addQuestion;/*!< Bouton d'ajout de question. */
        QPushButton *backToThemes;/*!< Bouton de retour aux thèmes. */

        QWidget *propositionWidget;/*!< Widget contenant les widgets des propositions. */
        QHBoxLayout *propositionPlaceholderLayout;
        QLabel *selectedQuestion;/*!< Indication de la question sélectionnée. */
        QComboBox *propositionSelection;/*!< Menu déroulant de sélection de proposition. */
        QPushButton *deleteProposition;/*!< Bouton de suppression de proposition. */
        QTextEdit *propositionWritingField;/*!< Champ de saisie de proposition. */
        QPushButton *modifyProposition;/*!< Bouton de modification de proposition. */
        QPushButton *addProposition;/*!< Bouton d'ajout de proposition. */
        QPushButton *backToQuestions;/*!< Bouton de retour aux questions. */
        QRadioButton *theOne;/*!< Bouton radio de choix de la réponse de la proposition. */
        QRadioButton *theOther;/*!< Bouton radio de choix de la réponse de la proposition. */
        QRadioButton *both;/*!< Bouton radio de choix de la réponse de la proposition. */

};
#endif

