#ifndef CONTROLS_H
#define CONTROLS_H

#include <QtWidgets>
#include <QBoxLayout>

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

    private:
        QVBoxLayout *mainLayout;

        QCheckBox *fullscreen;
        QPushButton *logout;

        QPushButton *return;

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
        QComboBox *questionSelection;
        QPushButton *deleteQuestion;
        QPushButton *relatedPropositions;
        QLineEdit *questionField1;
        QLineEdit *questionField2;
        QPushButton *modifyQuestion;
        QPushButton *addQuestion;
        //QWidget *propositionWidget;


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