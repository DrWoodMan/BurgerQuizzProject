#include "Controls.h"

Controls::Controls() : QWidget(){

    mainLayout = new QVBoxLayout;
    setLayout(mainLayout);

    QHBoxLayout *headerLayout = new QHBoxLayout;
    mainLayout->addLayout(headerLayout);

    fullscreen = new QCheckBox("Fullscreen mode");
    headerLayout->addWidget(fullscreen);
    headerLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    logout = new QPushButton("LOGOUT");
    headerLayout->addWidget(logout);
    logout->hide();

    connect(logout, SIGNAL(clicked()), this, SLOT(slot_logout()));

    
//AUTHENTICATION
    authenticationWidget = new QWidget();
    mainLayout->addWidget(authenticationWidget);

    QHBoxLayout *authenticationBodyLayout = new QHBoxLayout;
    authenticationWidget->setLayout(authenticationBodyLayout);

    authenticationBodyLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    QVBoxLayout *authenticationLayout = new QVBoxLayout();
    authenticationBodyLayout->addLayout(authenticationLayout);
    authenticationBodyLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));


    //title
    QHBoxLayout *authenticationTitleLayout = new QHBoxLayout;
    authenticationLayout->addLayout(authenticationTitleLayout);
    authenticationTitleLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    QLabel *authenticationTitle = new QLabel("DB conection");
    QFont authenticationFont;
    authenticationFont.setPointSize(20);
    authenticationTitle->setFont(authenticationFont);
    authenticationTitleLayout->addWidget(authenticationTitle);
    authenticationTitleLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));

    authenticationLayout->addSpacerItem(new QSpacerItem(0, 70));
    //fields connection general layout
    QVBoxLayout *connectionFieldsLayout = new QVBoxLayout;
    authenticationLayout->addLayout(connectionFieldsLayout);
    
    //server IP label
    QHBoxLayout *serverIPLabelLayout = new QHBoxLayout;
    QLabel *serverIPLabel = new QLabel("Server IP");
    serverIPLabelLayout->addWidget(serverIPLabel);
    serverIPLabelLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    connectionFieldsLayout->addLayout(serverIPLabelLayout);

    //server IP field
    serverIP = new QComboBox;
    serverIP->setEditable(true);
    connectionFieldsLayout->addWidget(serverIP);

    //login label
    QHBoxLayout *loginLabelLayout = new QHBoxLayout;
    QLabel *loginLabel = new QLabel("Login");
    loginLabelLayout->addWidget(loginLabel);
    loginLabelLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    connectionFieldsLayout->addLayout(loginLabelLayout);

    //login field
    login = new QComboBox;
    login->setEditable(true);
    connectionFieldsLayout->addWidget(login);

    //password label
    QHBoxLayout *passwordLabelLayout = new QHBoxLayout;
    QLabel *passwordLabel = new QLabel("Password");
    passwordLabelLayout->addWidget(passwordLabel);
    passwordLabelLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    connectionFieldsLayout->addLayout(passwordLabelLayout);

    //password field
    password = new QLineEdit;
    password->setEchoMode(QLineEdit::Password);
    connectionFieldsLayout->addWidget(password);
    //password->setEchoMode(QLineEdit::Normal);

    //show password
    showPassword = new QCheckBox("Show Password");
    connectionFieldsLayout->addWidget(showPassword);
    connect(showPassword, SIGNAL(stateChanged(int)), this, SLOT(slot_showPassword(int)));

    //validate connection
    QHBoxLayout *validateConnectionLayout = new QHBoxLayout();
    connectionFieldsLayout->addLayout(validateConnectionLayout);
    validateConnection = new QPushButton("VALIDATE");
    validateConnectionLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    validateConnectionLayout->addWidget(validateConnection);
    validateConnectionLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));

    connect(validateConnection, SIGNAL(clicked()), this, SLOT(slot_validateConnection()));

//LOADING
    loadingWidget = new QWidget();
    mainLayout->addWidget(loadingWidget);
    loadingWidget->hide();

    QHBoxLayout *loadingBodyLayout = new QHBoxLayout;
    loadingWidget->setLayout(loadingBodyLayout);

    loadingBodyLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    QVBoxLayout *loadingLayout = new QVBoxLayout();
    loadingBodyLayout->addLayout(loadingLayout);
    loadingBodyLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));

    QMovie *movie = new QMovie("loadingAnimation.gif");
    movie->setScaledSize(QSize(300, 300));
    QLabel *animationLabel = new QLabel();
    animationLabel->setMovie(movie);
    loadingLayout->addWidget(animationLabel);
    movie->start();


    //title
    /*QHBoxLayout *loadingTitleLayout = new QHBoxLayout;
    loadingLayout->addLayout(loadingTitleLayout);
    loadingTitleLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    QLabel *loadingTitle = new QLabel();
    loadingTitle->setText("Loading...");
    QFont loadingFont;
    loadingFont.setPointSize(20);
    loadingTitle->setFont(loadingFont);
    loadingTitleLayout->addWidget(loadingTitle);
    loadingTitleLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));*/



//ERRORS
    errorsWidget = new QWidget();
    mainLayout->addWidget(errorsWidget);
    errorsWidget->hide();

    QVBoxLayout *errorsLayout = new QVBoxLayout;
    errorsWidget->setLayout(errorsLayout);

    QLabel *errorLabel = new QLabel("ERROR");
    QFont errorFont;
    errorFont.setPointSize(30);
    errorLabel->setFont(errorFont);

    QHBoxLayout *errorLabelLayout = new QHBoxLayout();
    errorsLayout->addLayout(errorLabelLayout);
    errorLabelLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    errorLabelLayout->addWidget(errorLabel);
    errorLabelLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));

    QHBoxLayout *errorsSpecificationsLayout = new QHBoxLayout();
    errorsLayout->addLayout(errorsSpecificationsLayout);

    errorsSpecificationsLabel = new QLabel("...");
    errorsSpecificationsLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    errorsSpecificationsLayout->addWidget(errorsSpecificationsLabel);
    errorsSpecificationsLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));


//THEMES

    themeWidget = new QWidget();
    mainLayout->addWidget(themeWidget);
    themeWidget->hide();

    QVBoxLayout *themeMainLayout = new QVBoxLayout;
    themeWidget->setLayout(themeMainLayout);

    //title
    QHBoxLayout *themeTitleLayout = new QHBoxLayout;
    themeMainLayout->addLayout(themeTitleLayout);
    themeTitleLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    QLabel *themeTitle = new QLabel("Themes");
    QFont themeFont;
    themeFont.setPointSize(20);
    themeTitle->setFont(themeFont);
    themeTitleLayout->addWidget(themeTitle);
    themeTitleLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    
    themeMainLayout->addSpacerItem(new QSpacerItem(0, 70));
    QHBoxLayout *themeBodyLayout = new QHBoxLayout();
    themeMainLayout->addLayout(themeBodyLayout);

    //theme selection
    QVBoxLayout *themeSelectionLayout = new QVBoxLayout();
    themeBodyLayout->addLayout(themeSelectionLayout);

    themeSelectionLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));

    themeSelection = new QComboBox();
    themeSelection->setEditable(true);
    themeSelectionLayout->addWidget(themeSelection);

    //theme selection buttons
    QHBoxLayout *buttonsThemeSelectionLayout = new QHBoxLayout();
    themeSelectionLayout->addLayout(buttonsThemeSelectionLayout);

    deleteTheme = new QPushButton("DELETE");
    buttonsThemeSelectionLayout->addWidget(deleteTheme);
    deleteTheme->setMaximumWidth(200);

    relatedQuestions = new QPushButton("QUESTIONS");
    buttonsThemeSelectionLayout->addWidget(relatedQuestions);
    relatedQuestions->setMaximumWidth(200);

    //theme writing
    QVBoxLayout *themeWritingLayout = new QVBoxLayout();
    themeBodyLayout->addLayout(themeWritingLayout);

    themeWritingField = new QTextEdit();
    themeWritingLayout->addWidget(themeWritingField);
    

    //theme writing buttons
    QHBoxLayout *buttonsThemeWritingLayout = new QHBoxLayout();
    themeWritingLayout->addLayout(buttonsThemeWritingLayout);

    modifyTheme = new QPushButton("MODIFY");
    buttonsThemeWritingLayout->addWidget(modifyTheme);
    modifyTheme->setMaximumWidth(200);

    addTheme = new QPushButton("ADD");
    buttonsThemeWritingLayout->addWidget(addTheme);
    addTheme->setMaximumWidth(200);


//QUESTIONS

    questionWidget = new QWidget();
    mainLayout->addWidget(questionWidget);
    questionWidget->hide();

    QVBoxLayout *questionMainLayout = new QVBoxLayout;
    questionWidget->setLayout(questionMainLayout);

    //title
    QHBoxLayout *questionTitleLayout = new QHBoxLayout;
    questionMainLayout->addLayout(questionTitleLayout);
    questionTitleLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    QLabel *questionTitle = new QLabel("Questions");
    QFont questionFont;
    questionFont.setPointSize(20);
    questionTitle->setFont(questionFont);
    questionTitleLayout->addWidget(questionTitle);
    questionTitleLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    
    QHBoxLayout *selectedThemeLayout = new QHBoxLayout();
    questionMainLayout->addLayout(selectedThemeLayout);

    selectedThemeLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    selectedTheme = new QLabel("selected theme");
    selectedThemeLayout->addWidget(selectedTheme);
    selectedThemeLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));

    questionMainLayout->addSpacerItem(new QSpacerItem(0, 70));
    QHBoxLayout *questionBodyLayout = new QHBoxLayout();
    questionMainLayout->addLayout(questionBodyLayout);

    //question selection
    QVBoxLayout *questionSelectionLayout = new QVBoxLayout();
    questionBodyLayout->addLayout(questionSelectionLayout);

    questionSelectionLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));

    questionSelection = new QComboBox();
    questionSelection->setEditable(true);
    questionSelectionLayout->addWidget(questionSelection);

    //question selection buttons
    QHBoxLayout *buttonsQuestionSelectionLayout = new QHBoxLayout();
    questionSelectionLayout->addLayout(buttonsQuestionSelectionLayout);

    deleteQuestion = new QPushButton("DELETE");
    buttonsQuestionSelectionLayout->addWidget(deleteQuestion);
    deleteQuestion->setMaximumWidth(200);

    relatedPropositions = new QPushButton("PROPOSITIONS");
    buttonsQuestionSelectionLayout->addWidget(relatedPropositions);
    relatedPropositions->setMaximumWidth(200);

    //back to theme
    backToTheme = new QPushButton("RETURN");
    questionSelectionLayout->addSpacerItem(new QSpacerItem(0, 200));
    questionSelectionLayout->addWidget(backToTheme);
    backToTheme->setMaximumWidth(200);

    //question writing
    QVBoxLayout *questionWritingLayout = new QVBoxLayout();
    questionBodyLayout->addLayout(questionWritingLayout);

    QHBoxLayout *questionWritingFieldsLayout = new QHBoxLayout();
    questionWritingLayout->addLayout(questionWritingFieldsLayout);

    questionWritingField1 = new QLineEdit();
    questionWritingFieldsLayout->addWidget(questionWritingField1);

    QLabel *comma = new QLabel(",");
    questionWritingFieldsLayout->addWidget(comma);

    questionWritingField2 = new QLineEdit();
    questionWritingFieldsLayout->addWidget(questionWritingField2);

    QLabel * endOfQuestion = new QLabel(" ou les deux ?");
    questionWritingFieldsLayout->addWidget(endOfQuestion);
    

    //question writing buttons
    QHBoxLayout *buttonsQuestionWritingLayout = new QHBoxLayout();
    questionWritingLayout->addLayout(buttonsQuestionWritingLayout);

    modifyQuestion = new QPushButton("MODIFY");
    buttonsQuestionWritingLayout->addWidget(modifyQuestion);
    modifyQuestion->setMaximumWidth(200);

    addQuestion = new QPushButton("ADD");
    buttonsQuestionWritingLayout->addWidget(addQuestion);
    addQuestion->setMaximumWidth(200);

    questionWritingLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));


//PROPOSITION

    propositionWidget = new QWidget();
    mainLayout->addWidget(propositionWidget);
    propositionWidget->hide();

    QVBoxLayout *propositionMainLayout = new QVBoxLayout;
    propositionWidget->setLayout(propositionMainLayout);

    //title
    QHBoxLayout *propositionTitleLayout = new QHBoxLayout;
    propositionMainLayout->addLayout(propositionTitleLayout);
    propositionTitleLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    QLabel *propositionTitle = new QLabel("Propositions");
    QFont propositionFont;
    propositionFont.setPointSize(20);
    propositionTitle->setFont(propositionFont);
    propositionTitleLayout->addWidget(propositionTitle);
    propositionTitleLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    
    questionMainLayout->removeItem(selectedThemeLayout);
    propositionMainLayout->addLayout(selectedThemeLayout);

    QHBoxLayout *selectedQuestionLayout = new QHBoxLayout();
    propositionMainLayout->addLayout(selectedQuestionLayout);

    selectedQuestionLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    selectedQuestion = new QLabel("selected question");
    selectedQuestionLayout->addWidget(selectedQuestion);
    selectedQuestionLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));


    propositionMainLayout->addSpacerItem(new QSpacerItem(0, 70));
    QHBoxLayout *propositionBodyLayout = new QHBoxLayout();
    propositionMainLayout->addLayout(propositionBodyLayout);

    //proposition selection
    QVBoxLayout *propositionSelectionLayout = new QVBoxLayout();
    propositionBodyLayout->addLayout(propositionSelectionLayout);

    propositionSelectionLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));

    propositionSelection = new QComboBox();
    propositionSelection->setEditable(true);
    propositionSelectionLayout->addWidget(propositionSelection);

    //proposition selection buttons
    QHBoxLayout *buttonsPropositionSelectionLayout = new QHBoxLayout();
    propositionSelectionLayout->addLayout(buttonsPropositionSelectionLayout);

    deleteProposition = new QPushButton("DELETE");
    buttonsPropositionSelectionLayout->addWidget(deleteProposition);
    deleteProposition->setMaximumWidth(200);

    //back to question
    backToQuestion = new QPushButton("RETURN");
    propositionSelectionLayout->addSpacerItem(new QSpacerItem(0, 200));
    propositionSelectionLayout->addWidget(backToQuestion);
    backToQuestion  ->setMaximumWidth(200);

    //proposition writing
    QVBoxLayout *propositionWritingLayout = new QVBoxLayout();
    propositionBodyLayout->addLayout(propositionWritingLayout);

    propositionWritingField = new QTextEdit();
    propositionWritingLayout->addWidget(propositionWritingField);

    

    //proposition writing buttons
    QHBoxLayout *buttonsPropositionWritingLayout = new QHBoxLayout();
    propositionWritingLayout->addLayout(buttonsPropositionWritingLayout);

    modifyProposition = new QPushButton("MODIFY");
    buttonsPropositionWritingLayout->addWidget(modifyProposition);
    modifyProposition->setMaximumWidth(200);

    addProposition = new QPushButton("ADD");
    buttonsPropositionWritingLayout->addWidget(addProposition);
    addProposition->setMaximumWidth(200);

    propositionWritingLayout->addSpacerItem(new QSpacerItem(0, 300, QSizePolicy::Expanding, QSizePolicy::Expanding));





    mainLayout->addSpacerItem(new QSpacerItem(6000, 6000, QSizePolicy::Expanding, QSizePolicy::Expanding));

}

Controls::~Controls(){}

QCheckBox *Controls::getFullscreen(){
    return fullscreen;
}

void Controls::setErrorsSpecifications(QString str){
    errorsSpecificationsLabel->setText(str);
}

void Controls::slot_showPassword(int state){

    switch(state){
        case 0:
        password->setEchoMode(QLineEdit::Password);
        break;

        case 2:
        password->setEchoMode(QLineEdit::Normal);
        break;
    }
}

QComboBox *Controls::getServerIP(){

    return serverIP;
}

QComboBox *Controls::getLogin(){

    return login;
}

QLineEdit *Controls::getPassword(){

    return password;
}

void Controls::slot_validateConnection(){

    qDebug()<<"validate Connection";
    authenticationWidget->hide();
    propositionWidget->show();
    logout->show();

}

void Controls::slot_logout(){

    qDebug()<<"logout";
}