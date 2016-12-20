CREATE DATABASE  IF NOT EXISTS `overwatch_counter_guide` /*!40100 DEFAULT CHARACTER SET utf8mb4 */;
USE `overwatch_counter_guide`;
-- MySQL dump 10.13  Distrib 5.7.12, for osx10.9 (x86_64)
--
-- Host: 127.0.0.1    Database: overwatch_counter_guide
-- ------------------------------------------------------
-- Server version	5.6.31

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Counters`
--

DROP TABLE IF EXISTS `Counters`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Counters` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `heroId0` int(11) NOT NULL,
  `heroId1` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  KEY `heroId0_idx` (`heroId0`),
  KEY `heroId1_idx` (`heroId1`),
  CONSTRAINT `heroId0` FOREIGN KEY (`heroId0`) REFERENCES `Heroes` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `heroId1` FOREIGN KEY (`heroId1`) REFERENCES `Heroes` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=116 DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Counters`
--

LOCK TABLES `Counters` WRITE;
/*!40000 ALTER TABLE `Counters` DISABLE KEYS */;
INSERT INTO `Counters` VALUES (8,1,22),(9,2,3),(10,2,4),(11,2,6),(12,2,9),(13,2,14),(14,2,16),(15,2,18),(16,2,20),(17,2,21),(18,3,4),(19,3,6),(20,3,9),(21,3,10),(22,3,11),(23,3,14),(24,3,17),(25,3,18),(26,3,20),(35,2,1),(36,4,1),(37,5,3),(38,6,5),(39,6,7),(40,6,8),(41,6,14),(42,6,17),(43,6,21),(44,6,22),(45,7,2),(46,7,13),(47,7,14),(48,7,15),(49,7,16),(50,8,2),(51,8,3),(52,8,7),(53,8,9),(54,8,11),(55,8,17),(56,8,18),(57,8,21),(58,9,7),(59,9,10),(60,9,11),(61,9,20),(62,10,1),(63,10,5),(64,10,6),(65,10,13),(66,10,16),(67,10,18),(68,11,1),(69,11,6),(70,12,2),(71,12,3),(72,12,7),(73,12,9),(74,12,10),(75,12,11),(76,12,17),(77,12,21),(78,13,8),(79,13,12),(80,13,15),(81,14,5),(82,14,11),(83,15,1),(84,15,3),(85,15,5),(86,15,6),(87,15,14),(88,15,20),(89,16,1),(90,16,8),(91,16,12),(92,16,20),(93,17,1),(94,17,20),(95,20,1),(96,20,13),(97,20,14),(98,21,13),(99,21,16),(100,22,1),(101,22,4),(102,22,5),(103,1,7),(104,1,8),(105,1,19),(107,4,10),(108,4,14),(109,4,15),(110,4,16),(111,4,18),(112,4,17),(113,4,20),(114,4,22),(115,5,6);
/*!40000 ALTER TABLE `Counters` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Heroes`
--

DROP TABLE IF EXISTS `Heroes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Heroes` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(45) NOT NULL,
  `roleId` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  KEY `role_id_idx` (`roleId`),
  CONSTRAINT `role_id` FOREIGN KEY (`roleId`) REFERENCES `Roles` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=23 DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Heroes`
--

LOCK TABLES `Heroes` WRITE;
/*!40000 ALTER TABLE `Heroes` DISABLE KEYS */;
INSERT INTO `Heroes` VALUES (1,'Genji',1),(2,'McCree',1),(3,'Pharah',1),(4,'Reaper',1),(5,'Soldier 76',1),(6,'Tracer',1),(7,'Bastion',2),(8,'Hanzo',2),(9,'Junkrat',2),(10,'Mei',2),(11,'Torbjörn',2),(12,'Widowmaker',2),(13,'D.Va',3),(14,'Reinhardt',3),(15,'Roadhog',3),(16,'Winston',3),(17,'Zarya',3),(18,'Lucio',4),(19,'Mercy',4),(20,'Symmetra',4),(21,'Zenyatta',4),(22,'Ana',4);
/*!40000 ALTER TABLE `Heroes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Roles`
--

DROP TABLE IF EXISTS `Roles`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Roles` (
  `id` int(11) NOT NULL,
  `name` varchar(45) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Roles`
--

LOCK TABLES `Roles` WRITE;
/*!40000 ALTER TABLE `Roles` DISABLE KEYS */;
INSERT INTO `Roles` VALUES (1,'Attack'),(2,'Defense'),(3,'Tank'),(4,'Support');
/*!40000 ALTER TABLE `Roles` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-12-19 23:18:34
