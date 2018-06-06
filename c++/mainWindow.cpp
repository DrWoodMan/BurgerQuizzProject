#include "MainWindow.h"
#include "controls.cpp"

MainWindow::MainWindow() : QMainWindow(){

    setWindowTitle("Salade Quiz - Administration interface");
    //setWindowIcon(QIcon(QPixmap("salade.jpg")));
    setMinimumWidth(400);
    setMinimumHeight(400);
    show();

    controls = new Controls();
    setCentralWidget(controls);

    //action de basculement entre la taille d'origine et le plein écran
    connect(controls->getFullscreen(), SIGNAL(stateChanged(int)), this, SLOT(slot_windowSize(int)));
/*
    //action de création d'une scene de la taille renseignée à l'appui sur le bouton START
    connect(controls->getStartButton(), SIGNAL(clicked()), this, SLOT(slot_startScene()));
    //action de suppression de la scene et de la vue courantes à l'appui sur le bouton STOP
    connect(controls->getStopButton(), SIGNAL(clicked()), this, SLOT(slot_stopScene()));
*/
}

MainWindow::~MainWindow(){}

void MainWindow::slot_windowSize(int state){
    
    switch(state){
        case 0:
        this->showNormal();
        break;

        case 2:
        this->showFullScreen();
        break;
    }
}