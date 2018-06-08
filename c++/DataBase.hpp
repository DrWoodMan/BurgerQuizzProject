#ifndef GESTIONBDD_H
#define GESTIONBDD_H

#include "includes.hpp"


class DataBase{

	public :
		DataBase(std::string ip, std::string user, std::string password, std::string baseName);
		~DataBase();

        sql::Connection *getConnection();
        std::string getError();
        //std::vector <std::string> getThemes();

        /*
        void addTheme(std::string theme);
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
        sql::ResultSet *result = NULL;
        std::string error;


};
#endif