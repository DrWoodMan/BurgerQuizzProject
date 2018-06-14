#include "MainWindow.hpp"
#include "controls.cpp"

MainWindow::MainWindow() : QMainWindow(){

    setWindowTitle("Salade Quiz - Administration interface");
    //setWindowIcon(QIcon(QPixmap("salade.jpg")));
    setMinimumWidth(500);
    setMinimumHeight(500);
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
    connect(controls->getQuestionSelection(), SIGNAL(activated(int)), this, SLOT(slot_copyQuestionInWritingFields(int)));
    //action d'ajouter une question à la bdd
    connect(controls->getAddQuestion(), SIGNAL(clicked()), this, SLOT(slot_addQuestion()));
    //action de modifier une question en bdd
    connect(controls->getModifyQuestion(), SIGNAL(clicked()), this, SLOT(slot_modifyQuestion()));
    //action de supprimer une question de la bdd
    connect(controls->getDeleteQuestion(), SIGNAL(clicked()), this, SLOT(slot_deleteQuestion()));
    //action d'aff
    connect(controls->getRelatedPropositions(), SIGNAL(clicked()), this, SLOT(slot_relatedPropositions()));

    connect(controls->getPropositionSelection(), SIGNAL(activated(int)), this, SLOT(slot_copyPropositionInWritingField(int)));

    connect(controls->getAddProposition(), SIGNAL(clicked()), this, SLOT(slot_addProposition()));

    connect(controls->getModifyProposition(), SIGNAL(clicked()), this, SLOT(slot_modifyProposition()));

    connect(controls->getDeleteProposition(), SIGNAL(clicked()), this, SLOT(slot_deleteProposition()));
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
        popup->showMessage(QString::fromStdString(error));
        return true;
    }
    else{
        return false;
    }

}

void MainWindow::getThemes(){

    themes = dataBase->getThemes();
    controls->getThemeSelection()->clear();

    if(!dbErrorPopup() && (themes.size() > 0)){
        controls->getRelatedQuestions()->show();
        for(auto &theme : themes){
            controls->getThemeSelection()->addItem(QString::fromStdString(theme.theme));
        }
    }
    else if(themes.size() == 0){
        controls->getRelatedQuestions()->hide();
    }
}

void MainWindow::getQuestions(){

    questions = dataBase->getQuestions(idSelectedTheme);
    controls->getQuestionSelection()->clear();
    controls->getQuestionWritingField1()->clear();
    controls->getQuestionWritingField2()->clear();

    if(!dbErrorPopup() && (questions.size() > 0)){
        controls->getRelatedPropositions()->show();
        for(auto &question : questions){
            controls->getQuestionSelection()->addItem(QString::fromStdString(question.field1 + ", " + question.field2 + " ou les deux ?"));
        }
    }
    else if(questions.size() == 0){
        controls->getRelatedPropositions()->hide();
    }
}

void MainWindow::getPropositions(){

    propositions = dataBase->getPropositions(idSelectedQuestion);
    controls->getPropositionSelection()->clear();
    controls->getPropositionWritingField()->clear();

    if(!dbErrorPopup()){
        for(auto &proposition : propositions){
            controls->getPropositionSelection()->addItem(QString::fromStdString(proposition.proposition));
        }
    }
}

void MainWindow::slot_connection(){
    
    dataBase = new DataBase(controls->getServerIP()->text().toStdString(), controls->getLogin()->text().toStdString(), controls->getPassword()->text().toStdString(), controls->getDataBaseName()->text().toStdString());

    if(!dbErrorPopup()){
        settings.setValue("serverIP", controls->getServerIP()->text());
        settings.setValue("dataBaseName", controls->getDataBaseName()->text());
        settings.setValue("login", controls->getLogin()->text());
        controls->getAuthenticationWidget()->hide();
        controls->getThemeWidget()->show();
        controls->getLogout()->show();
        getThemes();
    }
    
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

    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Are you sure ?");
    msgBox.setInformativeText("The deleting of this theme will delete all associated content (questions and propositions).");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);

    int choice = msgBox.exec();

    if(choice == QMessageBox::Yes){
        dataBase->deleteTheme(themes[controls->getThemeSelection()->currentIndex()].idTheme);
    }

    if(!dbErrorPopup()){
        getThemes();
        controls->getThemeWritingField()->clear();
    }
}

void MainWindow::slot_relatedQuestions(){

    QString selectedTheme = controls->getThemeSelection()->currentText();
    controls->getSelectedTheme()->setText("Selected theme : " + selectedTheme);

    idSelectedTheme = themes[controls->getThemeSelection()->currentIndex()].idTheme;
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

    dataBase->modifyQuestion(question);

    if(!dbErrorPopup()){
        getQuestions();
        controls->getQuestionWritingField1()->clear();
        controls->getQuestionWritingField2()->clear();
    }
}

void MainWindow::slot_deleteQuestion(){

    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Are you sure ?");
    msgBox.setInformativeText("The deleting of this question will delete all associated content (propositions).");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);

    int choice = msgBox.exec();

    if(choice == QMessageBox::Yes){
        dataBase->deleteQuestion(questions[controls->getQuestionSelection()->currentIndex()].idQuestion);
    }

    if(!dbErrorPopup()){
        getQuestions();
    }
}

void MainWindow::slot_relatedPropositions(){

    QString selectedQuestion = controls->getQuestionSelection()->currentText();
    controls->getSelectedQuestion()->setText("Selected question : " + selectedQuestion);

    unsigned int index  = controls->getQuestionSelection()->currentIndex();

    controls->getTheOne()->setText(QString::fromStdString(questions[index].field1));
    controls->getTheOther()->setText(QString::fromStdString(questions[index].field2));
    
    idSelectedQuestion = questions[index].idQuestion;

    controls->getQuestionPlaceholderLayout()->removeItem(controls->getSelectedThemeLayout());
    controls->getPropositionPlaceholderLayout()->addLayout(controls->getSelectedThemeLayout());

    controls->getQuestionWidget()->hide();
    controls->getPropositionWidget()->show();
    getPropositions();

}

void MainWindow::slot_copyPropositionInWritingField(int index){

    if(index >= 0){
        controls->getPropositionWritingField()->setText(QString::fromStdString(propositions[index].proposition));

        switch(propositions[index].solution){

            case 0:
                controls->getTheOne()->setChecked(true);
                break;

            case 1:
                controls->getTheOther()->setChecked(true);
                break;

            case 2:
                controls->getBoth()->setChecked(true);
                break;
        }
    }
}

void MainWindow::slot_addProposition(){

    Proposition proposition;
    proposition.proposition = controls->getPropositionWritingField()->toPlainText().toStdString();
    proposition.idQuestion = idSelectedQuestion;
    
    if(controls->getTheOne()->isChecked()){
        proposition.solution = 0;
    }
    else if(controls->getTheOther()->isChecked()){
        proposition.solution = 1;
    }
    else if(controls->getBoth()->isChecked()){
        proposition.solution = 2;
    }

    dataBase->addProposition(proposition);

    if(!dbErrorPopup()){
        getPropositions();
        controls->getPropositionWritingField()->clear();
    }
}

void MainWindow::slot_modifyProposition(){

    Proposition proposition;

    proposition.proposition = controls->getPropositionWritingField()->toPlainText().toStdString();
    proposition.idProposition = propositions[controls->getPropositionSelection()->currentIndex()].idProposition;

    
    if(controls->getTheOne()->isChecked()){
        proposition.solution = 0;
    }
    else if(controls->getTheOther()->isChecked()){
        proposition.solution = 1;
    }
    else if(controls->getBoth()->isChecked()){
        proposition.solution = 2;
    }

    dataBase->modifyProposition(proposition);

    if(!dbErrorPopup()){
        getPropositions();
        controls->getPropositionWritingField()->clear();
    }
}

void MainWindow::slot_deleteProposition(){

    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Are you sure ?");
    msgBox.setInformativeText("Delete this proposition.");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);

    int choice = msgBox.exec();

    if(choice == QMessageBox::Yes){
        dataBase->deleteProposition(propositions[controls->getPropositionSelection()->currentIndex()].idProposition);
    }

    if(!dbErrorPopup()){
        getPropositions();
    }
}