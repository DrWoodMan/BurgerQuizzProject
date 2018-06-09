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

        bool dbErrorPopup();
        void getThemes();

    public slots:
        void slot_windowSize(int state);
        void slot_connection();
        void slot_logout();
        void slot_addTheme();
        void slot_modifyTheme();
        void slot_deleteTheme();

    private:
    
        QVBoxLayout *mainLayout;
        //QWidget *previousPage;
        Controls *controls;
        DataBase *dataBase;

        std::vector<Theme> themes;

    
};
#endif