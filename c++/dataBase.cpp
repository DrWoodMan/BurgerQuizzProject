#include "DataBase.hpp"

DataBase::DataBase(std::string url, std::string user, std::string password, std::string baseName){

//toStdString()
    try{
        driver = get_driver_instance();
        connection = driver->connect("tcp://"+url, user, password);
        connection->setSchema(baseName);

        statement = connection->createStatement();
        //statement->executeQuery();
        std::cout<<"connection OK"<<std::endl;
    }
    catch(sql::SQLException &e){
        error = "";
        error += "# ERR: " + std::string(e.what());
        error += "(MySQL error code: " + std::to_string(e.getErrorCode());
        error += ", SQLState: " + e.getSQLState() + " )";
    }
}

DataBase::~DataBase(){

    try{
        delete result;
        delete statement;
        delete connection;
    }
    catch(sql::SQLException &e){
        error = "";
        error += "# ERR: " + std::string(e.what());
        error += "(MySQL error code: " + std::to_string(e.getErrorCode());
        error += ", SQLState: " + e.getSQLState() + " )";
    }
    std::cout<<"DECONNEXION"<<std::endl;
}

 sql::Connection *DataBase::getConnection(){
     return connection;
 }

 std::string DataBase::getError(){
     return error;
 }