#ifndef DATABASE_HHP
#define DATABASE_HHP

#include "includes.hpp"



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

        std::vector<Proposition> getPropositions(unsigned int idQuestion);
        void addProposition(Proposition proposition);
        void modifyProposition(Proposition proposition);
        void deleteProposition(unsigned int idProposition);
        
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