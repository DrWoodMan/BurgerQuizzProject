-- phpMyAdmin SQL Dump
-- version 4.5.4.1deb2ubuntu2
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Jun 15, 2018 at 01:44 PM
-- Server version: 5.7.22-0ubuntu0.16.04.1
-- PHP Version: 7.0.30-0ubuntu0.16.04.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `saladeQuiz`
--

-- --------------------------------------------------------

--
-- Table structure for table `game`
--

CREATE TABLE `game` (
  `idGame` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `game`
--

INSERT INTO `game` (`idGame`) VALUES
(1),
(2),
(3),
(4),
(5),
(6),
(7),
(8),
(9);

-- --------------------------------------------------------

--
-- Table structure for table `has`
--

CREATE TABLE `has` (
  `idGame` int(11) NOT NULL,
  `idQuestion` int(11) NOT NULL,
  `idProposition` int(11) NOT NULL,
  `questionOrder` int(11) NOT NULL,
  `propositionOrder` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `has`
--

INSERT INTO `has` (`idGame`, `idQuestion`, `idProposition`, `questionOrder`, `propositionOrder`) VALUES
(3, 2, 13, 1, 1),
(3, 2, 15, 1, 0),
(3, 2, 16, 1, 2),
(3, 4, 25, 0, 1),
(3, 4, 26, 0, 2),
(3, 4, 28, 0, 0),
(3, 5, 33, 2, 1),
(3, 5, 36, 2, 2),
(3, 5, 39, 2, 0),
(4, 2, 9, 0, 1),
(4, 2, 10, 0, 2),
(4, 2, 15, 0, 0),
(4, 3, 22, 1, 2),
(4, 3, 23, 1, 1),
(4, 3, 24, 1, 0),
(4, 4, 27, 2, 2),
(4, 4, 29, 2, 0),
(4, 4, 31, 2, 1),
(5, 1, 1, 0, 0),
(5, 1, 2, 0, 1),
(5, 1, 5, 0, 2),
(5, 4, 25, 2, 0),
(5, 4, 29, 2, 2),
(5, 4, 31, 2, 1),
(5, 5, 33, 1, 1),
(5, 5, 37, 1, 0),
(5, 5, 40, 1, 2),
(6, 1, 5, 2, 1),
(6, 1, 6, 2, 2),
(6, 1, 8, 2, 0),
(6, 4, 25, 1, 2),
(6, 4, 27, 1, 0),
(6, 4, 28, 1, 1),
(6, 5, 33, 0, 0),
(6, 5, 34, 0, 2),
(6, 5, 40, 0, 1),
(7, 3, 18, 0, 2),
(7, 3, 19, 0, 1),
(7, 3, 21, 0, 0),
(7, 4, 29, 2, 1),
(7, 4, 30, 2, 2),
(7, 4, 31, 2, 0),
(7, 5, 33, 1, 2),
(7, 5, 37, 1, 0),
(7, 5, 38, 1, 1),
(8, 2, 11, 0, 0),
(8, 2, 13, 0, 1),
(8, 2, 16, 0, 2),
(8, 3, 18, 1, 0),
(8, 3, 21, 1, 2),
(8, 3, 23, 1, 1),
(8, 4, 27, 2, 0),
(8, 4, 30, 2, 2),
(8, 4, 32, 2, 1),
(9, 2, 9, 0, 0),
(9, 2, 10, 0, 1),
(9, 2, 13, 0, 2),
(9, 3, 17, 1, 1),
(9, 3, 22, 1, 2),
(9, 3, 23, 1, 0),
(9, 6, 43, 2, 2),
(9, 6, 44, 2, 0),
(9, 6, 45, 2, 1);

-- --------------------------------------------------------

--
-- Table structure for table `proposition`
--

CREATE TABLE `proposition` (
  `idProposition` int(11) NOT NULL,
  `proposition` varchar(200) NOT NULL,
  `solution` int(11) NOT NULL,
  `idQuestion` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `proposition`
--

INSERT INTO `proposition` (`idProposition`, `proposition`, `solution`, `idQuestion`) VALUES
(1, 'il peut voler', 2, 1),
(2, 'on peut le rouler', 2, 1),
(3, 'a été ministre de la ville', 0, 1),
(4, 'Ses ancêtres remontent à -500 avant JC', 1, 1),
(5, 'il y a beaucoup de contrefaçons', 1, 1),
(6, 's\'entretient de façon journalière avec un aspirateur', 1, 1),
(7, 'A une époque, j\'ai vomi dessus', 1, 1),
(8, 'Matricule 265-449G', 0, 1),
(9, 'est visible à plusieurs reprises dans le fim "Les Visiteurs"', 2, 2),
(10, 'est présent dans "Da Vinci Code"', 2, 2),
(11, 'a traversé les âges', 2, 2),
(12, 'peut aller dans l\'eau et en ressortir', 0, 2),
(13, 'vient d\'Espagne', 0, 2),
(14, 'est présent dans une publicité Toyota', 0, 2),
(15, 'est proche de Christian Clavier', 0, 2),
(16, 'a fait la guerre', 1, 2),
(17, 'a fait partie du gouvernement', 0, 3),
(18, 'peut être mis en examen', 0, 3),
(19, 'la cour de Cassation est son dernier ressort', 0, 3),
(20, 'a été en possession de notre argent', 2, 3),
(21, 'est accusé de nombreux maux', 2, 3),
(22, 'a été présent dans la vie de nombreuses personnes', 2, 3),
(23, 'on peut le voir tous les soirs', 1, 3),
(24, 'peut être source d\'examens', 1, 3),
(25, 'ne travaille pas le jeudi après-midi', 1, 4),
(26, 'le dub est le repère de ses étudiants', 1, 4),
(27, 'a son propre BDE', 2, 4),
(28, 'est mieux que l\'Isen Nantes', 2, 4),
(29, 's\'est fait battre à un tournoi de "hacking" par l\'Isen Nantes', 2, 4),
(30, 'tous les élèves se connaissent rapidement', 0, 4),
(31, 'un enseignant l\'a quitté pour se consacrer à sa passion', 0, 4),
(32, 'a des viennoiseries à tous les petit-déjeuners organisés par des clubs', 0, 4),
(33, 'peut se trouver au milieu de Brest', 0, 5),
(34, 'on ne mange pas son contenu', 0, 5),
(35, 'n\'a pas de pieds', 1, 5),
(36, 'peut être mélodieux', 1, 5),
(37, 'est proche de la mer', 2, 5),
(38, 'peut être associée aux pompiers', 2, 5),
(39, 'est source d\'enseignements', 2, 5),
(40, 'a demandé à ce que ce projet soit réalisé', 0, 5),
(41, 'son fils sauvera la galaxie', 0, 6),
(42, 'padmé meurt par sa faute', 0, 6),
(43, 'il peut être avec Chucky', 1, 6),
(44, 'il est parfois mauvais', 1, 6),
(45, 'il commence bien et finit mal', 2, 6),
(46, 'il peut, en fonction du film, avoir une main coupée', 2, 6),
(47, 'il a l\'air amical', 2, 7),
(48, 'des générations le suivent', 2, 7),
(49, 'il se mange', 1, 7),
(50, 'il a du chocolat', 1, 7),
(51, 'il a un sabre laser', 0, 7),
(52, 'il utilise la force', 0, 7);

-- --------------------------------------------------------

--
-- Table structure for table `question`
--

CREATE TABLE `question` (
  `idQuestion` int(11) NOT NULL,
  `field1` varchar(50) NOT NULL,
  `field2` varchar(50) NOT NULL,
  `idTheme` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `question`
--

INSERT INTO `question` (`idQuestion`, `field1`, `field2`, `idTheme`) VALUES
(1, 'bernard tapie', 'un tapis', 1),
(2, 'jean reno', 'une renault', 1),
(3, 'edouard baladur', 'un matelas bien dur', 1),
(4, 'isen Rennes', 'isen Brest', 2),
(5, 'l\'Isen', 'une sirène', 2),
(6, 'anakin Skywalker', 'un film d\'horreur', 3),
(7, 'kenobi', 'un Kinder Pingui', 3);

-- --------------------------------------------------------

--
-- Table structure for table `score`
--

CREATE TABLE `score` (
  `idGame` int(11) NOT NULL,
  `login` varchar(50) NOT NULL,
  `score` int(11) NOT NULL,
  `time` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `score`
--

INSERT INTO `score` (`idGame`, `login`, `score`, `time`) VALUES
(1, 'bernard', 0, 1528967504),
(2, 'bernard', 0, 1528995100),
(3, 'bernard', 1, 1528997398),
(4, 'bernard', 32, 1528997510),
(5, 'bernard', 48, 1529058940),
(8, 'bernard', 24, 1529057730),
(9, 'bernard', 0, 1529061987);

-- --------------------------------------------------------

--
-- Table structure for table `theme`
--

CREATE TABLE `theme` (
  `idTheme` int(11) NOT NULL,
  `theme` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `theme`
--

INSERT INTO `theme` (`idTheme`, `theme`) VALUES
(2, 'Isen'),
(1, 'People'),
(3, 'Star wars');

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

CREATE TABLE `user` (
  `login` varchar(50) NOT NULL,
  `passwordHash` varchar(50) NOT NULL,
  `token` varchar(50) DEFAULT NULL,
  `mailAddress` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `user`
--

INSERT INTO `user` (`login`, `passwordHash`, `token`, `mailAddress`) VALUES
('bernard', '5j8vm8f7kbgg4ss4w4gcg48wswkgwookggowk4swggocgosk40', NULL, 'aled@oeuh.oui');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `game`
--
ALTER TABLE `game`
  ADD PRIMARY KEY (`idGame`);

--
-- Indexes for table `has`
--
ALTER TABLE `has`
  ADD PRIMARY KEY (`idGame`,`idQuestion`,`idProposition`),
  ADD KEY `has_question_FK` (`idQuestion`),
  ADD KEY `has_proposition1_FK` (`idProposition`);

--
-- Indexes for table `proposition`
--
ALTER TABLE `proposition`
  ADD PRIMARY KEY (`idProposition`),
  ADD UNIQUE KEY `uniquePropositionPerQuestion` (`proposition`,`idQuestion`),
  ADD KEY `proposition_question_FK` (`idQuestion`);

--
-- Indexes for table `question`
--
ALTER TABLE `question`
  ADD PRIMARY KEY (`idQuestion`),
  ADD UNIQUE KEY `uniqueQuestion` (`field1`,`field2`),
  ADD KEY `question_theme_FK` (`idTheme`);

--
-- Indexes for table `score`
--
ALTER TABLE `score`
  ADD PRIMARY KEY (`idGame`,`login`),
  ADD KEY `score_user0_FK` (`login`);

--
-- Indexes for table `theme`
--
ALTER TABLE `theme`
  ADD PRIMARY KEY (`idTheme`),
  ADD UNIQUE KEY `theme` (`theme`);

--
-- Indexes for table `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`login`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `game`
--
ALTER TABLE `game`
  MODIFY `idGame` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;
--
-- AUTO_INCREMENT for table `proposition`
--
ALTER TABLE `proposition`
  MODIFY `idProposition` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=53;
--
-- AUTO_INCREMENT for table `question`
--
ALTER TABLE `question`
  MODIFY `idQuestion` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;
--
-- AUTO_INCREMENT for table `theme`
--
ALTER TABLE `theme`
  MODIFY `idTheme` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
--
-- Constraints for dumped tables
--

--
-- Constraints for table `has`
--
ALTER TABLE `has`
  ADD CONSTRAINT `has_game0_FK` FOREIGN KEY (`idGame`) REFERENCES `game` (`idGame`),
  ADD CONSTRAINT `has_proposition1_FK` FOREIGN KEY (`idProposition`) REFERENCES `proposition` (`idProposition`),
  ADD CONSTRAINT `has_question_FK` FOREIGN KEY (`idQuestion`) REFERENCES `question` (`idQuestion`);

--
-- Constraints for table `proposition`
--
ALTER TABLE `proposition`
  ADD CONSTRAINT `proposition_question_FK` FOREIGN KEY (`idQuestion`) REFERENCES `question` (`idQuestion`);

--
-- Constraints for table `question`
--
ALTER TABLE `question`
  ADD CONSTRAINT `question_theme_FK` FOREIGN KEY (`idTheme`) REFERENCES `theme` (`idTheme`);

--
-- Constraints for table `score`
--
ALTER TABLE `score`
  ADD CONSTRAINT `score_game_FK` FOREIGN KEY (`idGame`) REFERENCES `game` (`idGame`),
  ADD CONSTRAINT `score_user0_FK` FOREIGN KEY (`login`) REFERENCES `user` (`login`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
