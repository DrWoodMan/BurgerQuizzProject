#ifndef CONTROLS_H
#define CONTROLS_H

#include "includes.hpp"

class Controls : public QWidget{

    Q_OBJECT

    public:
        Controls();
        ~Controls();

        QCheckBox *getFullscreen();
        QPushButton *getLogout();
        QWidget *getLoadingWidget();
        
        QWidget *getAuthenticationWidget();
        QComboBox *getServerIP();
        QComboBox *getLogin();
        QLineEdit *getPassword();
        QPushButton *getValidateConnection();

        QWidget *getThemeWidget();
        QComboBox *getThemeSelection();
        QTextEdit *getThemeWritingField();
        QPushButton *getAddTheme();
        QPushButton *getModifyTheme();
        QPushButton *getDeleteTheme();
        QPushButton *getRelatedQuestions();

        QWidget *getQuestionWidget();
        QLabel *getSelectedTheme();
        QHBoxLayout *getSelectedThemeLayout();
        QHBoxLayout *getQuestionPlaceholderLayout();
        QComboBox *getQuestionSelection();
        QLineEdit *getQuestionWritingField1();
        QLineEdit *getQuestionWritingField2();
        QPushButton *getAddQuestion();
        QPushButton *getModifyQuestion();
        QPushButton *getDeleteQuestion();
        QPushButton *getRelatedPropositions();

        QWidget *getPropositionWidget();
        QHBoxLayout *getPropositionPlaceholderLayout();
        QLabel *getSelectedQuestion();
        QComboBox *getPropositionSelection();
        QTextEdit *getPropositionWritingField();
        QPushButton *getAddProposition();
        QPushButton *getModifyProposition();
        QPushButton *getDeleteProposition();
        QRadioButton *getTheOne();
        QRadioButton *getTheOther();
        QRadioButton *getBoth();


    public slots:
        void slot_showPassword(int state);
        void slot_copyThemeInWritingField(QString str);
        void slot_backToThemes();
        //void slot_copyPropositionInWritingField(QString str);
        void slot_backToQuestions();

    private:
        QSettings settings;
        QVBoxLayout *mainLayout;

        QCheckBox *fullscreen;
        QPushButton *logout;

        QWidget *loadingWidget;

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



/*
        QSpinBox *worldSizeX;
        QSpinBox *worldSizeY;
        QSpinBox *animalsNumber;
        QDoubleSpinBox *predatorsProportion;
        QSpinBox *startHealthPoints;
        QPushButton *startButton;
        QPushButton *quitButton;

        QLabel *turnNumber;
        QLabel *lionsNumber;
        QLabel *boarsNumber;
        QLabel *killedBoarsNumber; 
        QSlider *speedSlider;
        QLabel *turnsPerSecNumber;
        QPushButton *stopButton;
*/
};
#endif

