
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
DROP TABLE IF EXISTS `drupal_blocks_roles`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_blocks_roles` (
  `module` varchar(64) NOT NULL default '',
  `delta` varchar(32) NOT NULL default '',
  `rid` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`module`,`delta`,`rid`),
  KEY `rid` (`rid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_blocks_roles` WRITE;
/*!40000 ALTER TABLE `drupal_blocks_roles` DISABLE KEYS */;
INSERT INTO `drupal_blocks_roles` VALUES ('comment','0',2);
INSERT INTO `drupal_blocks_roles` VALUES ('ddblock','1',3);
INSERT INTO `drupal_blocks_roles` VALUES ('ddblock','2',3);
INSERT INTO `drupal_blocks_roles` VALUES ('devel_node_access','0',1);
INSERT INTO `drupal_blocks_roles` VALUES ('devel_node_access','0',2);
INSERT INTO `drupal_blocks_roles` VALUES ('devel_node_access','1',1);
INSERT INTO `drupal_blocks_roles` VALUES ('devel_node_access','1',2);
INSERT INTO `drupal_blocks_roles` VALUES ('forum','0',2);
INSERT INTO `drupal_blocks_roles` VALUES ('forum','1',2);
INSERT INTO `drupal_blocks_roles` VALUES ('locale','0',1);
INSERT INTO `drupal_blocks_roles` VALUES ('locale','0',2);
INSERT INTO `drupal_blocks_roles` VALUES ('menu','devel',3);
INSERT INTO `drupal_blocks_roles` VALUES ('search','0',2);
INSERT INTO `drupal_blocks_roles` VALUES ('shoutbox','0',2);
INSERT INTO `drupal_blocks_roles` VALUES ('simplenews','91',1);
INSERT INTO `drupal_blocks_roles` VALUES ('simplenews','91',2);
INSERT INTO `drupal_blocks_roles` VALUES ('tableofcontents_block','0',2);
INSERT INTO `drupal_blocks_roles` VALUES ('user','1',2);
INSERT INTO `drupal_blocks_roles` VALUES ('user','3',2);
INSERT INTO `drupal_blocks_roles` VALUES ('views','active_users-block_1',2);
/*!40000 ALTER TABLE `drupal_blocks_roles` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

