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
    //action d'ajouter un theme à la base de données
    connect(controls->getAddTheme(), SIGNAL(clicked()), this, SLOT(slot_addTheme()));
    //action de modifier un thème dans la base de données
    connect(controls->getModifyTheme(), SIGNAL(clicked()), this, SLOT(slot_modifyTheme()));
    //action de supprimer un theme de la base de données
    connect(controls->getDeleteTheme(), SIGNAL(clicked()), this, SLOT(slot_deleteTheme()));

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

bool MainWindow::dbErrorPopup(){

    std::string error = dataBase->getError();

    if(error != ""){
        QErrorMessage *popup = new QErrorMessage();
        popup->setWindowTitle("ERROR");
        popup->showMessage(QString::fromStdString(dataBase->getError()));
        return true;
    }
    else{
        return false;
    }

}

void MainWindow::getThemes(){

    themes = dataBase->getThemes();
    controls->getThemeSelection()->clear();

    if(!dbErrorPopup()){
        for(auto &theme : themes){
            controls->getThemeSelection()->addItem(QString::fromStdString(theme.theme));
        }
    }
}

void MainWindow::slot_connection(){
    
    dataBase = new DataBase(controls->getServerIP()->currentText().toStdString(), controls->getLogin()->currentText().toStdString(), controls->getPassword()->text().toStdString(), "saladeQuiz");

    if(!dbErrorPopup()){
        controls->getAuthenticationWidget()->hide();
        controls->getThemeWidget()->show();
        controls->getLogout()->show();
    }

    getThemes();
}

void MainWindow::slot_logout(){

    dataBase->~DataBase();

    if(!dbErrorPopup()){
        controls->getThemeWritingField()->clear();
        controls->getThemeWidget()->hide();
        controls->getQuestionWidget()->hide();
        controls->getPropositionWidget()->hide();
        controls->getAuthenticationWidget()->show();
        controls->getLogout()->hide();
    }
}

void MainWindow::slot_addTheme(){

    dataBase->addTheme(controls->getThemeWritingField()->toPlainText().toStdString());

    if(!dbErrorPopup()){
        getThemes();
        controls->getThemeWritingField()->clear();
    }
}

void MainWindow::slot_modifyTheme(){

    std::string themeToModify = controls->getThemeSelection()->currentText().toStdString();
    std::string newTheme = controls->getThemeWritingField()->toPlainText().toStdString();

    for(auto &theme : themes){

        if(themeToModify == theme.theme){
            dataBase->modifyTheme(theme.idTheme, newTheme);
            break;
        }
    }
    if(!dbErrorPopup()){
        getThemes();
        controls->getThemeWritingField()->clear();
    }
}

void MainWindow::slot_deleteTheme(){

    std::string themeToDelete = controls->getThemeSelection()->currentText().toStdString();

    for(auto &theme : themes){

        if(themeToDelete == theme.theme){
            dataBase->deleteTheme(theme.idTheme);
            break;
        }
    }
    if(!dbErrorPopup()){
        getThemes();
    }
}


