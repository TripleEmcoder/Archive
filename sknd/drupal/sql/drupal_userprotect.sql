
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
DROP TABLE IF EXISTS `drupal_userprotect`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_userprotect` (
  `uid` int(11) NOT NULL default '0',
  `up_name` smallint(6) NOT NULL default '0',
  `up_mail` smallint(6) NOT NULL default '0',
  `up_pass` smallint(6) NOT NULL default '0',
  `up_status` smallint(6) NOT NULL default '0',
  `up_roles` smallint(6) NOT NULL default '0',
  `up_delete` smallint(6) NOT NULL default '0',
  `up_edit` smallint(6) NOT NULL default '0',
  `up_type` char(20) NOT NULL default '',
  `up_openid` smallint(6) NOT NULL default '0',
  UNIQUE KEY `uid_up_type` (`uid`,`up_type`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_userprotect` WRITE;
/*!40000 ALTER TABLE `drupal_userprotect` DISABLE KEYS */;
INSERT INTO `drupal_userprotect` VALUES (0,0,0,0,0,0,1,1,'user',1);
INSERT INTO `drupal_userprotect` VALUES (1,0,0,0,0,0,1,1,'user',1);
INSERT INTO `drupal_userprotect` VALUES (1,1,1,1,1,1,1,1,'admin',1);
/*!40000 ALTER TABLE `drupal_userprotect` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

