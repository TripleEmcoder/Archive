
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
DROP TABLE IF EXISTS `drupal_content_type_general_assembly`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_content_type_general_assembly` (
  `vid` int(10) unsigned NOT NULL default '0',
  `nid` int(10) unsigned NOT NULL default '0',
  `field_general_assembly_number_value` longtext,
  `field_event_datetime_value` datetime default NULL,
  `field_event_datetime_value2` datetime default NULL,
  `field_general_assembly_protocol_fid` int(11) default NULL,
  `field_general_assembly_protocol_list` tinyint(4) default NULL,
  `field_general_assembly_protocol_data` text,
  `field_gnrl_assmbl_tm_elctns_vname` varchar(32) default NULL,
  `field_gnrl_assmbl_tm_elctns_vargs` varchar(255) default NULL,
  `field_gnrl_assmbl_stts_elctns_vname` varchar(32) default NULL,
  `field_gnrl_assmbl_stts_elctns_vargs` varchar(255) default NULL,
  `field_gnrl_assmbl_tm_dschrgs_vname` varchar(32) default NULL,
  `field_gnrl_assmbl_tm_dschrgs_vargs` varchar(255) default NULL,
  PRIMARY KEY  (`vid`),
  KEY `nid` (`nid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_content_type_general_assembly` WRITE;
/*!40000 ALTER TABLE `drupal_content_type_general_assembly` DISABLE KEYS */;
INSERT INTO `drupal_content_type_general_assembly` VALUES (3114,1794,'XXVII','2010-04-28 22:00:00','2010-04-28 22:00:00',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
INSERT INTO `drupal_content_type_general_assembly` VALUES (2800,1716,'XXII','2009-05-13 22:00:00','2009-05-13 22:00:00',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
INSERT INTO `drupal_content_type_general_assembly` VALUES (3105,1790,'XXVIII','2010-05-29 07:30:00','2010-05-29 13:30:00',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
/*!40000 ALTER TABLE `drupal_content_type_general_assembly` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

