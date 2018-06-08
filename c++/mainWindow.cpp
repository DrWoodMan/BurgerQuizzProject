#include "MainWindow.hpp"
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
    //action d'initier la connexion avec la base de données
    connect(controls->getValidateConnection(), SIGNAL(clicked()), this, SLOT(slot_connection()));
    //action de rompre la connexion avec la base de données
    connect(controls->getLogout(), SIGNAL(clicked()), this, SLOT(slot_logout()));

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

void MainWindow::slot_connection(){

    dataBase = new DataBase(controls->getServerIP()->currentText().toStdString(), controls->getLogin()->currentText().toStdString(), controls->getPassword()->text().toStdString(), "saladeQuiz");

    if(!dataBase->getConnection()){
        
        QErrorMessage *popup = new QErrorMessage();
        popup->setWindowTitle("ERROR");
        popup->showMessage(QString::fromStdString(dataBase->getError()));
        qDebug() << QString::fromStdString(dataBase->getError());
    }
    else if(dataBase->getConnection()){
        controls->getAuthenticationWidget()->hide();
        controls->getThemeWidget()->show();
        controls->getLogout()->show();
    }
}

void MainWindow::slot_logout(){

    dataBase->~DataBase();
    QErrorMessage *popup = new QErrorMessage();
    popup->setWindowTitle("ERROR");
    popup->showMessage(QString::fromStdString(dataBase->getError()));

    controls->getThemeWidget()->hide();
    controls->getQuestionWidget()->hide();
    controls->getPropositionWidget()->hide();
    controls->getAuthenticationWidget()->show();
    controls->getLogout()->hide();

}