
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
DROP TABLE IF EXISTS `drupal_filters`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_filters` (
  `fid` int(11) NOT NULL auto_increment,
  `format` int(11) NOT NULL default '0',
  `module` varchar(64) NOT NULL default '',
  `delta` tinyint(4) NOT NULL default '0',
  `weight` tinyint(4) NOT NULL default '0',
  PRIMARY KEY  (`fid`),
  UNIQUE KEY `fmd` (`format`,`module`,`delta`),
  KEY `list` (`format`,`weight`,`module`,`delta`)
) ENGINE=MyISAM AUTO_INCREMENT=55 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_filters` WRITE;
/*!40000 ALTER TABLE `drupal_filters` DISABLE KEYS */;
INSERT INTO `drupal_filters` VALUES (16,1,'filter',0,1);
INSERT INTO `drupal_filters` VALUES (41,2,'insert_node',0,10);
INSERT INTO `drupal_filters` VALUES (15,1,'filter',3,10);
INSERT INTO `drupal_filters` VALUES (14,1,'brilliant_gallery',0,10);
INSERT INTO `drupal_filters` VALUES (13,3,'php',0,0);
INSERT INTO `drupal_filters` VALUES (17,1,'filter',1,2);
INSERT INTO `drupal_filters` VALUES (18,1,'filter',2,0);
INSERT INTO `drupal_filters` VALUES (19,1,'insert_view',0,10);
INSERT INTO `drupal_filters` VALUES (49,4,'bbcode',0,10);
INSERT INTO `drupal_filters` VALUES (39,2,'filter',3,10);
INSERT INTO `drupal_filters` VALUES (40,2,'inline',0,10);
INSERT INTO `drupal_filters` VALUES (38,2,'brilliant_gallery',0,10);
INSERT INTO `drupal_filters` VALUES (42,2,'filter',1,1);
INSERT INTO `drupal_filters` VALUES (43,2,'filter',2,0);
INSERT INTO `drupal_filters` VALUES (44,2,'insert_view',0,10);
INSERT INTO `drupal_filters` VALUES (45,6,'messaging',1,0);
INSERT INTO `drupal_filters` VALUES (46,6,'filter',1,-1);
INSERT INTO `drupal_filters` VALUES (54,5,'insert_view',0,-9);
INSERT INTO `drupal_filters` VALUES (53,5,'pearwiki_filter',0,-10);
/*!40000 ALTER TABLE `drupal_filters` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

