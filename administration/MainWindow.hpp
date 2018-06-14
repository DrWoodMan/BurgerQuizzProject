/**
* \file MainWindow.hpp
* \author Adrien LEBOURGEOIS - Arthur MESLIN
* \date 15 Juin 2018
* \brief Classe principale.
* \details Classe principale faisant le lien entre la classe Controls et la classe DataBase
*/

#ifndef MAINWINDOW_HHP
#define MAINWINDOW_HHP


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
        void getQuestions();
        void getPropositions();

    public slots:
        void slot_windowSize(int state);
        void slot_connection();
        void slot_logout();
        void slot_addTheme();
        void slot_modifyTheme();
        void slot_deleteTheme();
        void slot_relatedQuestions();

        void slot_copyQuestionInWritingFields(int index);
        void slot_addQuestion();
        void slot_modifyQuestion();
        void slot_deleteQuestion();
        void slot_relatedPropositions();

        void slot_copyPropositionInWritingField(int index);
        void slot_addProposition();
        void slot_modifyProposition();
        void slot_deleteProposition();

    private:
    
        QSettings settings;
        QVBoxLayout *mainLayout;
        Controls *controls;
        DataBase *dataBase;

        std::vector<Theme> themes;
        unsigned int idSelectedTheme;
        std::vector<Question> questions;
        unsigned int idSelectedQuestion;
        std::vector<Proposition> propositions;

    
};
#endif
