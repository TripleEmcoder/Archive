
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
DROP TABLE IF EXISTS `drupal_vocabulary_node_types`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_vocabulary_node_types` (
  `vid` int(10) unsigned NOT NULL default '0',
  `type` varchar(32) NOT NULL default '',
  PRIMARY KEY  (`type`,`vid`),
  KEY `vid` (`vid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_vocabulary_node_types` WRITE;
/*!40000 ALTER TABLE `drupal_vocabulary_node_types` DISABLE KEYS */;
INSERT INTO `drupal_vocabulary_node_types` VALUES (12,'application_candidate');
INSERT INTO `drupal_vocabulary_node_types` VALUES (14,'application_candidate');
INSERT INTO `drupal_vocabulary_node_types` VALUES (9,'application_candidate_study');
INSERT INTO `drupal_vocabulary_node_types` VALUES (10,'application_candidate_study');
INSERT INTO `drupal_vocabulary_node_types` VALUES (13,'application_candidate_study');
INSERT INTO `drupal_vocabulary_node_types` VALUES (15,'application_candidate_study');
INSERT INTO `drupal_vocabulary_node_types` VALUES (7,'company');
INSERT INTO `drupal_vocabulary_node_types` VALUES (3,'forum');
INSERT INTO `drupal_vocabulary_node_types` VALUES (17,'member_application');
INSERT INTO `drupal_vocabulary_node_types` VALUES (18,'member_application');
INSERT INTO `drupal_vocabulary_node_types` VALUES (3,'poll');
INSERT INTO `drupal_vocabulary_node_types` VALUES (1,'service');
INSERT INTO `drupal_vocabulary_node_types` VALUES (8,'simplenews');
INSERT INTO `drupal_vocabulary_node_types` VALUES (5,'team');
INSERT INTO `drupal_vocabulary_node_types` VALUES (16,'team');
INSERT INTO `drupal_vocabulary_node_types` VALUES (4,'team_position');
INSERT INTO `drupal_vocabulary_node_types` VALUES (5,'team_position');
INSERT INTO `drupal_vocabulary_node_types` VALUES (16,'team_position');
INSERT INTO `drupal_vocabulary_node_types` VALUES (17,'team_position');
/*!40000 ALTER TABLE `drupal_vocabulary_node_types` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

