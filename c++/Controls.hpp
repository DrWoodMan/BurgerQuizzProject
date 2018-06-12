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
        * \brief Getter de la QCheckBoxe de plein écran. 
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
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Un pointeur de QCheckBox.
        */
        QComboBox *getServerIP();

        /**
        * \brief Getter du champ de saisie de l'IP du serveur. 
        * \return Pointeur de QComboBox.
        */
        QComboBox *getLogin();

        /**
        * \brief Getter du champ de saisie de l'identifiant. 
        * \return Pointeur de QComboBox.
        */
        QLineEdit *getPassword();

        /**
        * \brief Getter du champ de saisie de du mot de passe. 
        * \return Pointeur de QLineEdit.
        */
        QPushButton *getValidateConnection();

        /**
        * \brief Getter du bouton de validation de connecxion. 
        * \return Pointeur de QPushButton.
        */
        QWidget *getThemeWidget();

        /**
        * \brief Getter du widget contenant les widgets de la fenêtre des thèmes. 
        * \return Pointeur de QWidget.
        */
        QComboBox *getThemeSelection();

        /**
        * \brief Getter du champ de selection d'un thème. 
        * \return Pointeur de QComboBox.
        */
        QTextEdit *getThemeWritingField();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Pointeur de QCheckBox.
        */
        QPushButton *getAddTheme();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Pointeur de QPushButton.
        */
        QPushButton *getModifyTheme();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Pointeur de QPushButton.
        */
        QPushButton *getDeleteTheme();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Pointeur de QPushButton.
        */
        QPushButton *getRelatedQuestions();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Pointeur de QPushButton.
        */
        QWidget *getQuestionWidget();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Pointeur de QCheckBox.
        */
        QLabel *getSelectedTheme();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Pointeur de QCheckBox.
        */
        QHBoxLayout *getSelectedThemeLayout();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Pointeur de QCheckBox.
        */
        QHBoxLayout *getQuestionPlaceholderLayout();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Pointeur de QCheckBox.
        */
        QComboBox *getQuestionSelection();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Ppointeur de QCheckBox.
        */
        QLineEdit *getQuestionWritingField1();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Pointeur de QCheckBox.
        */
        QLineEdit *getQuestionWritingField2();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Pointeur de QCheckBox.
        */
        QPushButton *getAddQuestion();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Pointeur de QPushButton.
        */
        QPushButton *getModifyQuestion();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Pointeur de QPushButton.
        */
        QPushButton *getDeleteQuestion();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Pointeur de QPushButton.
        */
        QPushButton *getRelatedPropositions();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Pointeur de QPushButton.
        */
        QWidget *getPropositionWidget();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Pointeur de QCheckBox.
        */
        QHBoxLayout *getPropositionPlaceholderLayout();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Pointeur de QCheckBox.
        */
        QLabel *getSelectedQuestion();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Pointeur de QCheckBox.
        */
        QComboBox *getPropositionSelection();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Pointeur de QCheckBox.
        */
        QTextEdit *getPropositionWritingField();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Pointeur de QCheckBox.
        */
        QPushButton *getAddProposition();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Pointeur de QPushButton.
        */
        QPushButton *getModifyProposition();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Pointeur de QPushButton..
        */
        QPushButton *getDeleteProposition();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Pointeur de QRadioButton.
        */
        QRadioButton *getTheOne();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Pointeur de QRadioButton.
        */
        QRadioButton *getTheOther();

        /**
        * \brief Getter de la QCheckBoxe de plein écran. 
        * \return Pointeur de QRadioButton.
        */
        QRadioButton *getBoth();


    public slots:
        void slot_showPassword(int state);
        void slot_copyThemeInWritingField(QString str);
        void slot_backToThemes();
        void slot_backToQuestions();

    private:
        QSettings settings;
        QVBoxLayout *mainLayout;

        QCheckBox *fullscreen;
        QPushButton *logout;

        QWidget *authenticationWidget;
        QComboBox *serverIP;
        QComboBox *login;
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

