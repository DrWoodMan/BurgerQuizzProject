DataBase::DataBase(std::string url, std::string user, std::string password, std::string baseName,){

//toStdString()
    try{
        driver = get_driver_instance();
        connection = driver->connect("tcp://"+url, user, password);
        connection->setSchema(baseName);

        statement = connection->prepareStatement();
        statement->executeQuery();
    }
    catch(sql::SQLException &e){
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__<< ") on line " <<__LINE__<< std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << "(MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }
}

DataBase::~GestionBDD(){

    try{
        delete result;
        delete statement;
        delete connection;
    }
    catch(sql::SQLException &e){
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__<< ") on line " <<__LINE__<< std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << "(MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }
}