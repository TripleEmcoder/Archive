
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
DROP TABLE IF EXISTS `drupal_content_field_link`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_content_field_link` (
  `vid` int(10) unsigned NOT NULL default '0',
  `nid` int(10) unsigned NOT NULL default '0',
  `delta` int(10) unsigned NOT NULL default '0',
  `field_link_url` varchar(255) default NULL,
  `field_link_title` varchar(255) default NULL,
  `field_link_attributes` mediumtext,
  PRIMARY KEY  (`vid`,`delta`),
  KEY `nid` (`nid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_content_field_link` WRITE;
/*!40000 ALTER TABLE `drupal_content_field_link` DISABLE KEYS */;
INSERT INTO `drupal_content_field_link` VALUES (4,4,1,'http://cpanel.sknd.cp5.win.pl/','panel',NULL);
INSERT INTO `drupal_content_field_link` VALUES (6,6,0,'http://xname.org/','panel',NULL);
INSERT INTO `drupal_content_field_link` VALUES (19,19,1,'http://freeldap.org/access','panel',NULL);
INSERT INTO `drupal_content_field_link` VALUES (19,19,0,'http://freeldap.org','site',NULL);
INSERT INTO `drupal_content_field_link` VALUES (4,4,0,'http://amm.net.pl/','site',NULL);
INSERT INTO `drupal_content_field_link` VALUES (3,3,0,'http://superhost.pl/','site',NULL);
INSERT INTO `drupal_content_field_link` VALUES (3,3,1,'http://admin.superhost.pl/','panel',NULL);
INSERT INTO `drupal_content_field_link` VALUES (13,13,0,NULL,NULL,NULL);
INSERT INTO `drupal_content_field_link` VALUES (14,14,0,NULL,NULL,NULL);
INSERT INTO `drupal_content_field_link` VALUES (15,15,0,NULL,NULL,NULL);
INSERT INTO `drupal_content_field_link` VALUES (16,16,0,NULL,NULL,NULL);
INSERT INTO `drupal_content_field_link` VALUES (7,7,0,'twisted4life.com','site',NULL);
INSERT INTO `drupal_content_field_link` VALUES (7,7,1,'http://twisted4life.com/dnsadmin.php?Section=login','panel',NULL);
INSERT INTO `drupal_content_field_link` VALUES (20,20,0,NULL,NULL,NULL);
INSERT INTO `drupal_content_field_link` VALUES (21,21,0,NULL,NULL,NULL);
INSERT INTO `drupal_content_field_link` VALUES (1132,1132,0,NULL,NULL,NULL);
INSERT INTO `drupal_content_field_link` VALUES (1133,1133,0,NULL,NULL,NULL);
/*!40000 ALTER TABLE `drupal_content_field_link` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

