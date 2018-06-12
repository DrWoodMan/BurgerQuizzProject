CREATE TABLE proposition(
    idProposition Int  Auto_increment  NOT NULL,
    proposition   Varchar (200) NOT NULL,
    solution      Int NOT NULL,
    idQuestion    Int NOT NULL,
	PRIMARY KEY ('idProposition')
)
ENGINE=InnoDB;
