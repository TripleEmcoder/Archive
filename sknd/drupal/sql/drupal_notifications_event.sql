
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
DROP TABLE IF EXISTS `drupal_notifications_event`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_notifications_event` (
  `eid` int(10) unsigned NOT NULL auto_increment,
  `module` varchar(255) default NULL,
  `type` varchar(255) default NULL,
  `action` varchar(255) default NULL,
  `oid` int(10) unsigned NOT NULL default '0',
  `language` varchar(255) default NULL,
  `uid` int(11) default NULL,
  `params` text,
  `created` int(10) unsigned NOT NULL default '0',
  `counter` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`eid`)
) ENGINE=MyISAM AUTO_INCREMENT=818 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_notifications_event` WRITE;
/*!40000 ALTER TABLE `drupal_notifications_event` DISABLE KEYS */;
INSERT INTO `drupal_notifications_event` VALUES (734,'node','node','update',1788,NULL,181,'a:1:{s:3:\"nid\";s:4:\"1788\";}',1286229731,4294967291);
INSERT INTO `drupal_notifications_event` VALUES (735,'node','node','update',1788,NULL,181,'a:1:{s:3:\"nid\";s:4:\"1788\";}',1286229837,4294967291);
INSERT INTO `drupal_notifications_event` VALUES (743,'node','node','update',1788,NULL,245,'a:1:{s:3:\"nid\";s:4:\"1788\";}',1286313406,4294967291);
INSERT INTO `drupal_notifications_event` VALUES (798,'node','node','insert',1895,NULL,277,'a:1:{s:3:\"nid\";s:4:\"1895\";}',1286921847,4294967291);
/*!40000 ALTER TABLE `drupal_notifications_event` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

