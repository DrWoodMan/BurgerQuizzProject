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
    //logout->hide();

    
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
    connectionFieldsLayout->addWidget(login);

    //password label
    QHBoxLayout *passwordLabelLayout = new QHBoxLayout;
    QLabel *passwordLabel = new QLabel();
    passwordLabel->setText("Login");
    passwordLabelLayout->addWidget(passwordLabel);
    passwordLabelLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    connectionFieldsLayout->addLayout(passwordLabelLayout);

    //password field
    password = new QLineEdit;
    connectionFieldsLayout->addWidget(password);

}

Controls::~Controls(){}

QCheckBox *Controls::getFullscreen(){
    return fullscreen;
}