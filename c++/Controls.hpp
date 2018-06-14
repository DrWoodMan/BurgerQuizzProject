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
        QSettings settings;
        QVBoxLayout *mainLayout;

        QCheckBox *fullscreen;
        QPushButton *logout;

        QWidget *authenticationWidget;
        QLineEdit *serverIP;
        QLineEdit *dataBaseName;
        QLineEdit *login;

        QLineEdit *password;
        QCheckBox *showPassword;
        QPushButton *validateConnection;

        QWidget *themeWidget;
        QComboBox *themeSelection;
        QPushButton *deleteTheme;
        QPushButton *relatedQuestions;
        QTextEdit *themeWritingField;
        QPushButton *modifyTheme;
        QPushButton *addTheme;

        QWidget *questionWidget;
        QHBoxLayout *questionPlaceholderLayout;
        QHBoxLayout *selectedThemeLayout;
        QLabel *selectedTheme;
        QComboBox *questionSelection;
        QPushButton *deleteQuestion;
        QPushButton *relatedPropositions;
        QLineEdit *questionWritingField1;
        QLineEdit *questionWritingField2;
        QPushButton *modifyQuestion;
        QPushButton *addQuestion;
        QPushButton *backToThemes;

        QWidget *propositionWidget;
        QHBoxLayout *propositionPlaceholderLayout;
        QLabel *selectedQuestion;
        QComboBox *propositionSelection;
        QPushButton *deleteProposition;
        QTextEdit *propositionWritingField;
        QPushButton *modifyProposition;
        QPushButton *addProposition;
        QPushButton *backToQuestions;
        QRadioButton *theOne;
        QRadioButton *theOther;
        QRadioButton *both;

};
#endif

