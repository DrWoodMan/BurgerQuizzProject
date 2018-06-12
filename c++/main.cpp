#include "MainWindow.hpp"
#include "includes.hpp"

int main(int argc, char *argv[]) {
    
    QCoreApplication::setOrganizationName("ISEN");
    QCoreApplication::setOrganizationDomain("www.salade-quiz.fr");
    QCoreApplication::setApplicationName("Salade-Quiz Administrator");
    
    QApplication application(argc, argv);
    MainWindow window;
    return application.exec();
}