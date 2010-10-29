
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
DROP TABLE IF EXISTS `drupal_phpbb2drupal_temp_forum`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_phpbb2drupal_temp_forum` (
  `forum_id` smallint(5) unsigned NOT NULL default '0',
  `tid` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`forum_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_phpbb2drupal_temp_forum` WRITE;
/*!40000 ALTER TABLE `drupal_phpbb2drupal_temp_forum` DISABLE KEYS */;
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (1,41);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (2,42);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (3,43);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (28,44);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (24,45);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (5,47);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (6,48);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (7,49);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (8,50);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (9,51);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (10,52);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (11,53);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (12,54);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (13,55);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (22,56);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (25,57);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (29,58);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (30,59);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (32,60);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (16,62);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (17,63);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (18,64);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (20,65);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (21,66);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (26,67);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (27,68);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (33,69);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (34,70);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (14,72);
INSERT INTO `drupal_phpbb2drupal_temp_forum` VALUES (31,73);
/*!40000 ALTER TABLE `drupal_phpbb2drupal_temp_forum` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

