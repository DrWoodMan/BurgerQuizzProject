#include "MainWindow.hpp"
#include "includes.hpp"

int main(int argc, char *argv[]) {

    QApplication application(argc, argv);
    MainWindow window;
    return application.exec();
}