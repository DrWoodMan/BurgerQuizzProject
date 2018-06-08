#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "includes.hpp"
#include "Controls.hpp"
#include "DataBase.hpp"

class MainWindow : public QMainWindow {

    Q_OBJECT

    public:
        MainWindow();
        ~MainWindow();

    public slots:
        void slot_windowSize(int state);
        void slot_connection();
        void slot_logout();

    private:
    
        QVBoxLayout *mainLayout;
        //QWidget *previousPage;
        Controls *controls;
        DataBase *dataBase;

    
};
#endif