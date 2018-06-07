#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "includes.hpp"
#include "Controls.hpp"

class MainWindow : public QMainWindow {

    Q_OBJECT

    public:
        MainWindow();
        ~MainWindow();

    public slots:
        void slot_windowSize(int state);

    private:
    
        //QWidget *mainWidget;
        QVBoxLayout *mainLayout;
        Controls *controls;
    
};
#endif