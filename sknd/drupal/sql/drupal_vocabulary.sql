
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
DROP TABLE IF EXISTS `drupal_vocabulary`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_vocabulary` (
  `vid` int(10) unsigned NOT NULL auto_increment,
  `name` varchar(255) NOT NULL default '',
  `description` longtext,
  `help` varchar(255) NOT NULL default '',
  `relations` tinyint(3) unsigned NOT NULL default '0',
  `hierarchy` tinyint(3) unsigned NOT NULL default '0',
  `multiple` tinyint(3) unsigned NOT NULL default '0',
  `required` tinyint(3) unsigned NOT NULL default '0',
  `tags` tinyint(3) unsigned NOT NULL default '0',
  `module` varchar(255) NOT NULL default '',
  `weight` tinyint(4) NOT NULL default '0',
  `language` varchar(12) NOT NULL default '',
  PRIMARY KEY  (`vid`),
  KEY `list` (`weight`,`name`)
) ENGINE=MyISAM AUTO_INCREMENT=19 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_vocabulary` WRITE;
/*!40000 ALTER TABLE `drupal_vocabulary` DISABLE KEYS */;
INSERT INTO `drupal_vocabulary` VALUES (1,'Services','','',1,1,1,1,0,'taxonomy',-8,'');
INSERT INTO `drupal_vocabulary` VALUES (8,'Newsletters','','',1,0,0,1,0,'simplenews',-9,'');
INSERT INTO `drupal_vocabulary` VALUES (3,'Forums','','',1,1,0,0,0,'forum',-10,'');
INSERT INTO `drupal_vocabulary` VALUES (4,'Position functions','','',1,0,0,1,0,'taxonomy',3,'');
INSERT INTO `drupal_vocabulary` VALUES (5,'Terms','','',1,1,0,1,0,'taxonomy',1,'');
INSERT INTO `drupal_vocabulary` VALUES (7,'Company branches','','',1,0,0,1,0,'taxonomy',0,'');
INSERT INTO `drupal_vocabulary` VALUES (9,'Universities','','',1,2,0,1,0,'taxonomy',-7,'');
INSERT INTO `drupal_vocabulary` VALUES (10,'Degrees','','',1,1,0,1,0,'taxonomy',-5,'');
INSERT INTO `drupal_vocabulary` VALUES (11,'Language skills','','',1,0,0,0,0,'taxonomy',-2,'');
INSERT INTO `drupal_vocabulary` VALUES (12,'Candidate referral channels','','',1,1,0,1,0,'taxonomy',-1,'');
INSERT INTO `drupal_vocabulary` VALUES (13,'Study modes','','',1,0,0,1,0,'taxonomy',-6,'');
INSERT INTO `drupal_vocabulary` VALUES (14,'Study results','','',1,0,0,1,0,'taxonomy',-3,'');
INSERT INTO `drupal_vocabulary` VALUES (15,'Study years','','',1,1,0,1,0,'taxonomy',-4,'');
INSERT INTO `drupal_vocabulary` VALUES (16,'Teams','','',1,1,0,1,0,'taxonomy',2,'');
INSERT INTO `drupal_vocabulary` VALUES (17,'General assembly statuses','','',1,1,0,1,0,'taxonomy',4,'');
INSERT INTO `drupal_vocabulary` VALUES (18,'Member statuses','','',1,1,0,1,0,'taxonomy',0,'');
/*!40000 ALTER TABLE `drupal_vocabulary` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

