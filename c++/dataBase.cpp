#include "DataBase.hpp"

DataBase::DataBase(std::string url, std::string user, std::string password, std::string baseName){
//toStdString()
    try{
        driver = get_driver_instance();
        connection = driver->connect("tcp://"+url, user, password);
        connection->setSchema(baseName);
        statement = connection->createStatement();
        error = "";
    }
    catch(sql::SQLException &e){
        error += "# ERR: " + std::string(e.what());
        error += "(MySQL error code: " + std::to_string(e.getErrorCode());
        error += ", SQLState: " + e.getSQLState() + " )";
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
        error += "# ERR: " + std::string(e.what());
        error += "(MySQL error code: " + std::to_string(e.getErrorCode());
        error += ", SQLState: " + e.getSQLState() + " )";
    }
}


sql::Connection *DataBase::getConnection(){
    return connection;
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
        error += "# ERR: " + std::string(e.what());
        error += "(MySQL error code: " + std::to_string(e.getErrorCode());
        error += ", SQLState: " + e.getSQLState() + " )";
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
        error += "# ERR: " + std::string(e.what());
        error += "(MySQL error code: " + std::to_string(e.getErrorCode());
        error += ", SQLState: " + e.getSQLState() + " )";
    }
}

void DataBase::deleteTheme(unsigned int idTheme){

    try{
        preparedStatement = connection->prepareStatement("DELETE FROM theme WHERE (?)");
        preparedStatement->setInt(1, idTheme);
        result = preparedStatement->executeQuery();

        error = "";
    }
    catch(sql::SQLException &e){
        error += "# ERR: " + std::string(e.what());
        error += "(MySQL error code: " + std::to_string(e.getErrorCode());
        error += ", SQLState: " + e.getSQLState() + " )";
    }
}

void DataBase::modifyTheme(unsigned int idTheme, std::string theme){

    try{
        preparedStatement = connection->prepareStatement("UPDATE theme SET theme = (?) WHERE idTheme = (?)");
        preparedStatement->setString(1, theme);
        preparedStatement->setInt(2, idTheme);
        result = preparedStatement->executeQuery();

        error = "";
    }
    catch(sql::SQLException &e){
        error += "# ERR: " + std::string(e.what());
        error += "(MySQL error code: " + std::to_string(e.getErrorCode());
        error += ", SQLState: " + e.getSQLState() + " )";
    }
}