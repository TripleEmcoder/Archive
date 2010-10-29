
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
-- Not dumping tablespaces as no INFORMATION_SCHEMA.FILES table on this server
--
DROP TABLE IF EXISTS `drupal_role`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_role` (
  `rid` int(10) unsigned NOT NULL auto_increment,
  `name` varchar(64) NOT NULL default '',
  PRIMARY KEY  (`rid`),
  UNIQUE KEY `name` (`name`)
) ENGINE=MyISAM AUTO_INCREMENT=22 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_role` WRITE;
/*!40000 ALTER TABLE `drupal_role` DISABLE KEYS */;
INSERT INTO `drupal_role` VALUES (1,'anonymous user');
INSERT INTO `drupal_role` VALUES (2,'authenticated user');
INSERT INTO `drupal_role` VALUES (3,'Administrator');
INSERT INTO `drupal_role` VALUES (5,'Członek');
INSERT INTO `drupal_role` VALUES (6,'Kandydat');
INSERT INTO `drupal_role` VALUES (7,'Alumn');
INSERT INTO `drupal_role` VALUES (8,'Koordynator ds. PR');
INSERT INTO `drupal_role` VALUES (9,'Opiekun stron i aktualności');
INSERT INTO `drupal_role` VALUES (10,'Opiekun bazy mediów');
INSERT INTO `drupal_role` VALUES (11,'Opiekun newsletterów');
INSERT INTO `drupal_role` VALUES (12,'Opiekun forum');
INSERT INTO `drupal_role` VALUES (13,'Opiekun rekrutacji');
INSERT INTO `drupal_role` VALUES (14,'Wiceprezes ds. Rekrutacji');
INSERT INTO `drupal_role` VALUES (15,'Prezes');
INSERT INTO `drupal_role` VALUES (16,'Koordynator ds. IT');
INSERT INTO `drupal_role` VALUES (17,'Opiekun kont użytkowników');
INSERT INTO `drupal_role` VALUES (18,'Opiekun sekcji menu');
INSERT INTO `drupal_role` VALUES (19,'Opiekun Walnych Zebrań');
INSERT INTO `drupal_role` VALUES (20,'Koordynator ds. Jakości');
INSERT INTO `drupal_role` VALUES (21,'Opiekun tłumaczeń');
/*!40000 ALTER TABLE `drupal_role` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

