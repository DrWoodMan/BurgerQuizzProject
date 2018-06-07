#ifndef GESTIONBDD_H
#define GESTIONBDD_H

#include <vector>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>


typedef struct{

    std::string field1;
    std::string field2;
    
}Question;


class DataBase{

	public :
		DataBase(std::string ip, std::string user, std::string password, std::string baseName);
		~DataBase();

        std::vector <std::string> getThemes();

        void addTheme(std::string theme);
        void addQuestion(unsigned int idTheme, std::string field1, std::string field2);
        void addProposition(unsigned int idQuestion, std::string propositon, unsigned int solution);

        void deleteTheme(std::string theme);
        void deleteQuestion(std::string question);
        void deleteProposition(std::string proposition);



    private :
        sql::Driver* driver;
        sql::Connection* connection;
        sql::PreparedStatement* statement = NULL;
        sql::ResultSet* result = NULL;


};
#endif