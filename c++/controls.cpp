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
    QLabel *authenticationTitle = new QLabel();
    authenticationTitle->setText("DB conection");
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
    QLabel *serverIPLabel = new QLabel();
    serverIPLabel->setText("Server IP");
    serverIPLabelLayout->addWidget(serverIPLabel);
    serverIPLabelLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    connectionFieldsLayout->addLayout(serverIPLabelLayout);

    //server IP field
    serverIP = new QComboBox;
    serverIP->setEditable(true);
    connectionFieldsLayout->addWidget(serverIP);

    //login label
    QHBoxLayout *loginLabelLayout = new QHBoxLayout;
    QLabel *loginLabel = new QLabel();
    loginLabel->setText("Login");
    loginLabelLayout->addWidget(loginLabel);
    loginLabelLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    connectionFieldsLayout->addLayout(loginLabelLayout);

    //login field
    login = new QComboBox;
    login->setEditable(true);
    connectionFieldsLayout->addWidget(login);

    //password label
    QHBoxLayout *passwordLabelLayout = new QHBoxLayout;
    QLabel *passwordLabel = new QLabel();
    passwordLabel->setText("Password");
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

    QLabel *errorLabel = new QLabel();
    errorLabel->setText("ERROR");
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

    errorsSpecificationsLabel = new QLabel();
    errorsSpecificationsLabel->setText("...");
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
    QLabel *themeTitle = new QLabel();
    themeTitle->setText("Themes");
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
    QHBoxLayout *buttonsSelectionLayout = new QHBoxLayout();
    themeSelectionLayout->addLayout(buttonsSelectionLayout);

    deleteTheme = new QPushButton("DELETE");
    buttonsSelectionLayout->addWidget(deleteTheme);
    deleteTheme->setMaximumWidth(200);

    relatedQuestions = new QPushButton("QUESTIONS");
    buttonsSelectionLayout->addWidget(relatedQuestions);
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

    QVBoxLayout *themeMainLayout = new QVBoxLayout;
    themeWidget->setLayout(themeMainLayout);

    //title
    QHBoxLayout *questionTitleLayout = new QHBoxLayout;
    questionMainLayout->addLayout(questionTitleLayout);
    questionTitleLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    QLabel *questionTitle = new QLabel();
    questionTitle->setText("Questions");
    QFont themeFont;
    questionFont.setPointSize(20);
    questionTitle->setFont(questionFont);
    questionTitleLayout->addWidget(questionTitle);
    questionTitleLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    
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
    QHBoxLayout *buttonsSelectionLayout = new QHBoxLayout();
    themeSelectionLayout->addLayout(buttonsSelectionLayout);

    deleteTheme = new QPushButton("DELETE");
    buttonsSelectionLayout->addWidget(deleteTheme);
    deleteTheme->setMaximumWidth(200);

    relatedQuestions = new QPushButton("QUESTIONS");
    buttonsSelectionLayout->addWidget(relatedQuestions);
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



    //QVBoxLayout *themeLayout = new QVBoxLayout();
    //themeBodyLayout->addLayout(themeLayout);
    //themeBodyLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));




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
    themeWidget->show();

}

void Controls::slot_logout(){

    qDebug()<<"logout";
}