#ifndef GESTIONBDD_H
#define GESTIONBDD_H

#include "includes.hpp"


typedef struct{
    unsigned int idTheme;
    std::string theme;
}Theme;

typedef struct{
    unsigned int idQuestion;
    std::string field1;
    std::string field2;
    unsigned int idTheme;
}Question;

typedef struct{
    unsigned int idProposition;
    std::string proposition;
    unsigned int solution;
}Proposition;

class DataBase{

	public :
		DataBase(std::string ip, std::string user, std::string password, std::string baseName);
		~DataBase();

        sql::Connection *getConnection();
        std::string getError();

        std::vector <Theme> getThemes();
        void addTheme(std::string theme);
        void modifyTheme(Theme theme);
        void deleteTheme(unsigned int idTheme);

        std::vector<Question> getQuestions(unsigned int idTheme);
        void addQuestion(Question question);
        void modifyQuestion(Question question);
        void deleteQuestion(unsigned int idQuestion);
        
        /*
        void addQuestion(unsigned int idTheme, std::string field1, std::string field2);
        void addProposition(unsigned int idQuestion, std::string propositon, unsigned int solution);

        void deleteTheme(std::string theme);
        void deleteQuestion(std::string question);
        void deleteProposition(std::string proposition);
        */



    private :
        sql::Driver *driver;
        sql::Connection *connection = NULL;
        sql::Statement *statement = NULL;
        sql::PreparedStatement *preparedStatement = NULL;
        sql::ResultSet *result = NULL;
        std::string error;

        




};
#endif