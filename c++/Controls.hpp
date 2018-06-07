#ifndef CONTROLS_H
#define CONTROLS_H

#include "includes.hpp"

class Controls : public QWidget{

    Q_OBJECT

    public:
        Controls();
        ~Controls();

        QCheckBox *getFullscreen();
        void setErrorsSpecifications(QString str);

        QComboBox *getServerIP();
        QComboBox *getLogin();
        QLineEdit *getPassword();


    public slots:
        void slot_logout();
        void slot_showPassword(int state);
        void slot_validateConnection();
        void slot_relatedQuestions();
        void slot_backToThemes();
        void slot_relatedPropositions();
        void slot_backToQuestions();

    private:
        QVBoxLayout *mainLayout;

        QCheckBox *fullscreen;
        QPushButton *logout;


        QWidget *loadingWidget;

        QWidget *errorsWidget;
        QLabel *errorsSpecificationsLabel;

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

