
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
DROP TABLE IF EXISTS `drupal_content_type_team_position`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_content_type_team_position` (
  `vid` int(10) unsigned NOT NULL default '0',
  `nid` int(10) unsigned NOT NULL default '0',
  `field_team_position_function_value` int(11) default NULL,
  `field_position_user_uid` int(10) unsigned default NULL,
  `field_discharge_status_value` int(11) default NULL,
  `field_election_status_value` int(11) default NULL,
  `field_election_general_assembly_nid` int(10) unsigned default NULL,
  `field_discharge_general_assembly_nid` int(10) unsigned default NULL,
  PRIMARY KEY  (`vid`),
  KEY `nid` (`nid`),
  KEY `field_position_user_uid` (`field_position_user_uid`),
  KEY `field_election_general_assembly_nid` (`field_election_general_assembly_nid`),
  KEY `field_discharge_general_assembly_nid` (`field_discharge_general_assembly_nid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_content_type_team_position` WRITE;
/*!40000 ALTER TABLE `drupal_content_type_team_position` DISABLE KEYS */;
INSERT INTO `drupal_content_type_team_position` VALUES (2796,1713,184,146,192,189,1716,1790);
INSERT INTO `drupal_content_type_team_position` VALUES (2801,1717,184,247,NULL,NULL,NULL,NULL);
INSERT INTO `drupal_content_type_team_position` VALUES (3119,1795,184,206,192,189,1794,NULL);
INSERT INTO `drupal_content_type_team_position` VALUES (3122,1797,77,232,192,189,1794,NULL);
/*!40000 ALTER TABLE `drupal_content_type_team_position` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

