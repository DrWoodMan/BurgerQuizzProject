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

    QHBoxLayout *bodyLayout = new QHBoxLayout;
    authenticationWidget->setLayout(bodyLayout);

    bodyLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    QVBoxLayout *authenticationLayout = new QVBoxLayout();
    bodyLayout->addLayout(authenticationLayout);
    bodyLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));


    //title
    QHBoxLayout *titleLayout = new QHBoxLayout;
    authenticationLayout->addLayout(titleLayout);
    titleLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    QLabel *title = new QLabel();
    title->setText("DB conection");
    QFont font;
    font.setPointSize(20);
    title->setFont(font);
    titleLayout->addWidget(title);
    titleLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));

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

    mainLayout->addSpacerItem(new QSpacerItem(6000, 6000, QSizePolicy::Expanding, QSizePolicy::Expanding));

}

Controls::~Controls(){}

QCheckBox *Controls::getFullscreen(){
    return fullscreen;
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

void Controls::slot_validateConnection(){

    qDebug()<<"validate Connection";

}

void Controls::slot_logout(){

    qDebug()<<"logout";
}