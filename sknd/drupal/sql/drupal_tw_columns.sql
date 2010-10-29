
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
DROP TABLE IF EXISTS `drupal_tw_columns`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_tw_columns` (
  `twcid` int(10) unsigned NOT NULL auto_increment,
  `twtid` int(10) unsigned NOT NULL,
  `colname` varchar(255) NOT NULL default '',
  `weight` int(11) NOT NULL default '0',
  `primarykey` tinyint(4) NOT NULL default '0',
  `availablefk` tinyint(3) unsigned NOT NULL default '0',
  `secure` tinyint(4) NOT NULL default '0',
  `ignorecol` tinyint(3) unsigned NOT NULL default '0',
  `isempty` tinyint(3) unsigned NOT NULL default '0',
  `coltype` varchar(255) default NULL,
  `minlength` int(11) default NULL,
  `maxlength` int(11) default NULL,
  `minvalue` float default NULL,
  `maxvalue` float default NULL,
  `minstring` varchar(255) default NULL,
  `maxstring` varchar(255) default NULL,
  `comments` mediumtext,
  PRIMARY KEY  (`twcid`),
  UNIQUE KEY `colkey` (`twtid`,`colname`)
) ENGINE=MyISAM AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_tw_columns` WRITE;
/*!40000 ALTER TABLE `drupal_tw_columns` DISABLE KEYS */;
/*!40000 ALTER TABLE `drupal_tw_columns` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

