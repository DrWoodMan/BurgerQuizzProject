#include "DataBase.hpp"

DataBase::DataBase(std::string url, std::string user, std::string password, std::string baseName){

    try{
        driver = get_driver_instance();
        connection = driver->connect("tcp://"+url, user, password);
        connection->setSchema(baseName);
        statement = connection->createStatement();
        error = "";
    }
    catch(sql::SQLException &e){
        exception(e);
    }
}

DataBase::~DataBase(){

    try{
        delete result;
        delete statement;
        delete preparedStatement;
        delete connection;

        error = "";
    }
    catch(sql::SQLException &e){
        exception(e);
    }
}

void DataBase::exception(sql::SQLException &e){
    error += "# ERR: " + std::string(e.what());
    error += "(MySQL error code: " + std::to_string(e.getErrorCode());
    error += ", SQLState: " + e.getSQLState() + " )"; 
}

std::string DataBase::getError(){
    return error;
}

std::vector<Theme> DataBase::getThemes(){

    std::vector <Theme> themes;
    try{
        preparedStatement = connection->prepareStatement("SELECT * FROM theme");
        result = preparedStatement->executeQuery();

        while(result->next()){
            Theme tempTheme;
            tempTheme.idTheme = result->getInt(1);
            tempTheme.theme = result->getString(2);
            themes.push_back(tempTheme);
        }

        error = "";
    }
    catch(sql::SQLException &e){
        exception(e);
    }
    return themes;
}

void DataBase::addTheme(std::string theme){

    try{
        preparedStatement = connection->prepareStatement("INSERT INTO theme(theme) VALUES (?)");
        preparedStatement->setString(1, theme);
        result = preparedStatement->executeQuery();

        error = "";
    }
    catch(sql::SQLException &e){
        exception(e);
    }
}

void DataBase::modifyTheme(Theme theme){

    try{
        preparedStatement = connection->prepareStatement("UPDATE theme SET theme = (?) WHERE idTheme = (?)");
        preparedStatement->setString(1, theme.theme);
        preparedStatement->setInt(2, theme.idTheme);
        result = preparedStatement->executeQuery();

        error = "";
    }
    catch(sql::SQLException &e){
        exception(e);
    }
}

void DataBase::deleteTheme(unsigned int idTheme){

    try{
        preparedStatement = connection->prepareStatement("DELETE FROM proposition WHERE idQuestion IN (SELECT idQuestion FROM question WHERE idTheme = (?))");
        preparedStatement->setInt(1, idTheme);
        result = preparedStatement->executeQuery();

        preparedStatement = connection->prepareStatement("DELETE FROM question WHERE idTheme = (?)");
        preparedStatement->setInt(1, idTheme);
        result = preparedStatement->executeQuery();

        preparedStatement = connection->prepareStatement("DELETE FROM theme WHERE idTheme = (?)");
        preparedStatement->setInt(1, idTheme);
        result = preparedStatement->executeQuery();

        error = "";
    }
    catch(sql::SQLException &e){
        exception(e);
    }
}


std::vector<Question> DataBase::getQuestions(unsigned int idTheme){

    std::vector <Question> questions;
    try{
        preparedStatement = connection->prepareStatement("SELECT idQuestion, field1, field2 FROM question WHERE idTheme = (?)");
        preparedStatement->setInt(1, idTheme);
        result = preparedStatement->executeQuery();

        while(result->next()){
            Question tempQuestion;
            tempQuestion.idQuestion = result->getInt(1);
            tempQuestion.field1 = result->getString(2);
            tempQuestion.field2 = result->getString(3);
            questions.push_back(tempQuestion);
        }

        error = "";
    }
    catch(sql::SQLException &e){
        exception(e);
    }
    return questions;
}

void DataBase::addQuestion(Question question){

    try{
        preparedStatement = connection->prepareStatement("INSERT INTO question(field1, field2, idtheme) VALUES (?, ?, ?)");
        preparedStatement->setString(1, question.field1);
        preparedStatement->setString(2, question.field2);
        preparedStatement->setInt(3, question.idTheme);
        result = preparedStatement->executeQuery();

        error = "";
    }
    catch(sql::SQLException &e){
        exception(e);
    }
}

void DataBase::modifyQuestion(Question question){

    try{
        preparedStatement = connection->prepareStatement("UPDATE question SET field1 = (?), field2 = (?) WHERE idQuestion = (?)");
        preparedStatement->setString(1, question.field1);
        preparedStatement->setString(2, question.field2);
        preparedStatement->setInt(3, question.idQuestion);
        result = preparedStatement->executeQuery();

        error = "";
    }
    catch(sql::SQLException &e){
        exception(e);
    }
}

void DataBase::deleteQuestion(unsigned int idQuestion){

    try{
        preparedStatement = connection->prepareStatement("DELETE FROM proposition WHERE idQuestion = (?)");
        preparedStatement->setInt(1, idQuestion);
        result = preparedStatement->executeQuery();

        preparedStatement = connection->prepareStatement("DELETE FROM question WHERE idQuestion = (?)");
        preparedStatement->setInt(1, idQuestion);
        result = preparedStatement->executeQuery();

        error = "";
    }
    catch(sql::SQLException &e){
        exception(e);
    }
}

std::vector<Proposition> DataBase::getPropositions(unsigned int idQuestion){

    std::vector <Proposition> propositions;
    try{
        preparedStatement = connection->prepareStatement("SELECT idProposition, proposition, solution FROM proposition WHERE idquestion = (?)");
        preparedStatement->setInt(1, idQuestion);
        result = preparedStatement->executeQuery();

        while(result->next()){
            Proposition tempProposition;
            tempProposition.idProposition = result->getInt(1);
            tempProposition.proposition = result->getString(2);
            tempProposition.solution = result->getInt(3);
            propositions.push_back(tempProposition);
        }

        error = "";
    }
    catch(sql::SQLException &e){
        exception(e);
    }
    return propositions;
}

void DataBase::addProposition(Proposition proposition){

    try{
        preparedStatement = connection->prepareStatement("INSERT INTO proposition(proposition, solution, idQuestion) VALUES (?, ?, ?)");
        preparedStatement->setString(1, proposition.proposition);
        preparedStatement->setInt(2, proposition.solution);
        preparedStatement->setInt(3, proposition.idQuestion);
        result = preparedStatement->executeQuery();

        error = "";
    }
    catch(sql::SQLException &e){
        exception(e);
    }
}

void DataBase::modifyProposition(Proposition proposition){

    try{
        preparedStatement = connection->prepareStatement("UPDATE proposition SET proposition = (?), solution = (?) WHERE idProposition = (?)");
        preparedStatement->setString(1, proposition.proposition);
        preparedStatement->setInt(2, proposition.solution);
        preparedStatement->setInt(3, proposition.idProposition);
        result = preparedStatement->executeQuery();

        error = "";
    }
    catch(sql::SQLException &e){
        exception(e);
    }
}

void DataBase::deleteProposition(unsigned int idProposition){

    try{
        preparedStatement = connection->prepareStatement("DELETE FROM proposition WHERE idProposition = (?)");
        preparedStatement->setInt(1, idProposition);
        result = preparedStatement->executeQuery();

        error = "";
    }
    catch(sql::SQLException &e){
        exception(e);
    }
}