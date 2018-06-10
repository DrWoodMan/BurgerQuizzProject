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
    //action d'initier la connexion avec la base de données et d'afficher les themes
    connect(controls->getValidateConnection(), SIGNAL(clicked()), this, SLOT(slot_connection()));
    //action de rompre la connexion avec la base de données
    connect(controls->getLogout(), SIGNAL(clicked()), this, SLOT(slot_logout()));
    //action d'ajouter un theme à la base de données
    connect(controls->getAddTheme(), SIGNAL(clicked()), this, SLOT(slot_addTheme()));
    //action de modifier un thème dans la base de données
    connect(controls->getModifyTheme(), SIGNAL(clicked()), this, SLOT(slot_modifyTheme()));
    //action de supprimer un theme de la base de données
    connect(controls->getDeleteTheme(), SIGNAL(clicked()), this, SLOT(slot_deleteTheme()));
    //action d'afficher la page des questions avec les questions du thème selectionné
    connect(controls->getRelatedQuestions(), SIGNAL(clicked()), this, SLOT(slot_relatedQuestions()));
    //actin d'afficher la question selctionnée dans les champs de modification
    connect(controls->getQuestionSelection(), SIGNAL(currentIndexChanged(int)), this, SLOT(slot_copyQuestionInWritingFields(int)));
    //action d'ajouter une question à la bdd
    connect(controls->getAddQuestion(), SIGNAL(clicked()), this, SLOT(slot_addQuestion()));

    connect(controls->getModifyQuestion(), SIGNAL(clicked()), this, SLOT(slot_modifyQuestion()));

    connect(controls->getDeleteQuestion(), SIGNAL(clicked()), this, SLOT(slot_deleteQuestion()));

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

void MainWindow::getQuestions(){

    questions = dataBase->getQuestions(idSelectedTheme);
    controls->getQuestionSelection()->clear();
    controls->getQuestionWritingField1()->clear();
    controls->getQuestionWritingField2()->clear();

    if(!dbErrorPopup()){
        for(auto &question : questions){
            controls->getQuestionSelection()->addItem(QString::fromStdString(question.field1 + ", " + question.field2 + " ou les deux ?"));
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

    Theme theme;
    theme.theme = controls->getThemeWritingField()->toPlainText().toStdString();
    theme.idTheme = themes[controls->getThemeSelection()->currentIndex()].idTheme;

    dataBase->modifyTheme(theme);

    if(!dbErrorPopup()){
        getThemes();
        controls->getThemeWritingField()->clear();
    }
}

void MainWindow::slot_deleteTheme(){

    dataBase->deleteTheme(themes[controls->getThemeSelection()->currentIndex()].idTheme);

    if(!dbErrorPopup()){
        getThemes();
    }
}

void MainWindow::slot_relatedQuestions(){

    QString qSelectedTheme = controls->getThemeSelection()->currentText();
    controls->getSelectedTheme()->setText("Selected theme : " + qSelectedTheme);

    idSelectedTheme = themes[controls->getThemeSelection()->currentIndex()].idTheme;
    qDebug() << idSelectedTheme;
    controls->getThemeWidget()->hide();
    controls->getQuestionWidget()->show();
    getQuestions();
}

void MainWindow::slot_copyQuestionInWritingFields(int index){

    if(index >= 0){
        controls->getQuestionWritingField1()->setText(QString::fromStdString(questions[index].field1));
        controls->getQuestionWritingField2()->setText(QString::fromStdString(questions[index].field2));
    }
}

void MainWindow::slot_addQuestion(){

    Question question;
    question.field1 = controls->getQuestionWritingField1()->text().toStdString();
    question.field2 = controls->getQuestionWritingField2()->text().toStdString();
    question.idTheme = idSelectedTheme;

    dataBase->addQuestion(question);

    if(!dbErrorPopup()){
        getQuestions();
        controls->getQuestionWritingField1()->clear();
        controls->getQuestionWritingField2()->clear();
    }
}

void MainWindow::slot_modifyQuestion(){

    Question question;

    question.field1 = controls->getQuestionWritingField1()->text().toStdString();
    question.field2 = controls->getQuestionWritingField2()->text().toStdString();

    question.idQuestion = questions[controls->getQuestionSelection()->currentIndex()].idQuestion;
    question.idTheme = idSelectedTheme;


    dataBase->modifyQuestion(question);

    if(!dbErrorPopup()){
        getQuestions();
        controls->getQuestionWritingField1()->clear();
        controls->getQuestionWritingField2()->clear();
    }
}

void MainWindow::slot_deleteQuestion(){

    dataBase->deleteQuestion(questions[controls->getQuestionSelection()->currentIndex()].idQuestion);

    if(!dbErrorPopup()){
        getQuestions();
    }
}
/*
void MainWindow::slot_relatedQuestions(){

    QString qSelectedTheme = controls->getThemeSelection()->currentText();

    controls->getSelectedTheme()->setText("Selected theme : " + qSelectedTheme);
    std::string selectedTheme = qSelectedTheme.toStdString();

    for(auto &theme : themes){

        if(selectedTheme == theme.theme){
            controls->getThemeWidget()->hide();
            controls->getQuestionWidget()->show();
            idSelectedTheme = theme.idTheme;
            getQuestions();
        }
    }
}
*/

