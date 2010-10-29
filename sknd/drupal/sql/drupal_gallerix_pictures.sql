
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
DROP TABLE IF EXISTS `drupal_gallerix_pictures`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_gallerix_pictures` (
  `pid` int(11) NOT NULL auto_increment,
  `nid` int(11) NOT NULL default '0',
  `uid` int(11) NOT NULL default '0',
  `path` text NOT NULL,
  `name` text NOT NULL,
  `caption` text NOT NULL,
  `created` int(11) NOT NULL default '0',
  `added` int(11) NOT NULL default '0',
  `sort` int(11) NOT NULL default '0',
  `exif` longtext NOT NULL,
  `iptc` longtext NOT NULL,
  `original_name` text NOT NULL,
  `built` int(11) NOT NULL default '0',
  PRIMARY KEY  (`pid`),
  KEY `nid` (`nid`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_gallerix_pictures` WRITE;
/*!40000 ALTER TABLE `drupal_gallerix_pictures` DISABLE KEYS */;
INSERT INTO `drupal_gallerix_pictures` VALUES (1,18,3,'sites/default/files/gallerix/albums/3/18/original/PA240003.JPG','PA240003.JPG','',1225577139,1225577139,0,'','','PA240003.JPG',0);
/*!40000 ALTER TABLE `drupal_gallerix_pictures` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

