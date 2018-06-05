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


    public slots:


    private:
        QVBoxLayout *mainLayout;

        QWidget *authenticationWidget;
        //QWidget *errorsWidget;
        //QWidget *loadingWidget;
        //QWidget *themeWidget;
        //QWidget *questionWidget;
        //QWidget *propositionWidget;

        QCheckBox *fullscreen;
        QPushButton *logout;

        QComboBox *serverIP;
        QComboBox *login;
        QLineEdit *password;
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