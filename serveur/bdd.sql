#------------------------------------------------------------
#        Script MySQL.
#------------------------------------------------------------

DROP TABLE IF EXISTS score;
DROP TABLE IF EXISTS has;
DROP TABLE IF EXISTS game;
DROP TABLE IF EXISTS proposition;
DROP TABLE IF EXISTS question;
DROP TABLE IF EXISTS theme;
DROP TABLE IF EXISTS user;

USE saladeQuiz;

CREATE TABLE user(
    login        Varchar (50) NOT NULL,
    passwordHash Varchar (32) NOT NULL,
    token        Varchar (50) NOT NULL,
     mailAddress  Varchar (50) NOT NULL,
	CONSTRAINT user_PK PRIMARY KEY (login)
)
ENGINE=InnoDB;


CREATE TABLE theme(
    idTheme Int  Auto_increment  NOT NULL,
    theme   Varchar (50) NOT NULL,
    CONSTRAINT theme_PK PRIMARY KEY (idTheme)
)
ENGINE=InnoDB;


CREATE TABLE question(
    idQuestion Int  Auto_increment  NOT NULL,
    field1     Varchar (50) NOT NULL,
    field2     Varchar (50) NOT NULL,
    idTheme    Int NOT NULL,
    CONSTRAINT question_PK PRIMARY KEY (idQuestion),
    CONSTRAINT question_theme_FK FOREIGN KEY (idTheme) REFERENCES theme(idTheme)
)
ENGINE=InnoDB;


CREATE TABLE proposition(
    idProposition Int  Auto_increment  NOT NULL,
    proposition   Varchar (50) NOT NULL,
    solution      Int NOT NULL,
    idQuestion    Int NOT NULL,
    CONSTRAINT proposition_PK PRIMARY KEY (idProposition),
    CONSTRAINT proposition_question_FK FOREIGN KEY (idQuestion) REFERENCES question(idQuestion)
)
ENGINE=InnoDB;


CREATE TABLE game(
    idGame Int  Auto_increment  NOT NULL,
	CONSTRAINT game_PK PRIMARY KEY (idGame)
)
ENGINE=InnoDB;


CREATE TABLE has(
    idGame     Int NOT NULL,
    idQuestion Int NOT NULL,
    CONSTRAINT has_PK PRIMARY KEY (idGame,idQuestion),
	CONSTRAINT has_game_FK FOREIGN KEY (idGame) REFERENCES game(idGame),
	CONSTRAINT has_question0_FK FOREIGN KEY (idQuestion) REFERENCES question(idQuestion)
)
ENGINE=InnoDB;


CREATE TABLE score(
    idGame Int NOT NULL,
    login  Varchar (50) NOT NULL,
    score  Int NOT NULL,
    timestamp TIMESTAMP NOT NULL,
    CONSTRAINT score_PK PRIMARY KEY (idGame,login),
	CONSTRAINT score_game_FK FOREIGN KEY (idGame) REFERENCES game(idGame),
	CONSTRAINT score_user0_FK FOREIGN KEY (login) REFERENCES user(login)
)
ENGINE=InnoDB;

