
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
DROP TABLE IF EXISTS `drupal_views_view`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_views_view` (
  `vid` int(10) unsigned NOT NULL auto_increment,
  `name` varchar(32) NOT NULL default '',
  `description` varchar(255) default '',
  `tag` varchar(255) default '',
  `view_php` blob,
  `base_table` varchar(64) NOT NULL default '',
  `is_cacheable` tinyint(4) default '0',
  PRIMARY KEY  (`vid`),
  UNIQUE KEY `name` (`name`)
) ENGINE=MyISAM AUTO_INCREMENT=24 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_views_view` WRITE;
/*!40000 ALTER TABLE `drupal_views_view` DISABLE KEYS */;
INSERT INTO `drupal_views_view` VALUES (2,'services','','','','node',0);
INSERT INTO `drupal_views_view` VALUES (4,'active_users','','','','users',0);
INSERT INTO `drupal_views_view` VALUES (13,'users_in_role','','','','users',0);
INSERT INTO `drupal_views_view` VALUES (7,'company_contacts','','','','node',0);
INSERT INTO `drupal_views_view` VALUES (8,'companies','','','','node',0);
INSERT INTO `drupal_views_view` VALUES (9,'frontpage_stories','','','','node',0);
INSERT INTO `drupal_views_view` VALUES (10,'candidate_applications','','','','node',0);
INSERT INTO `drupal_views_view` VALUES (11,'users_by_role','','','','users',0);
INSERT INTO `drupal_views_view` VALUES (12,'empty_nodes','','','','node',0);
INSERT INTO `drupal_views_view` VALUES (17,'general_assembly_tm_dschrgs','','','','node',0);
INSERT INTO `drupal_views_view` VALUES (18,'general_assembly_tm_elctns','','','','node',0);
INSERT INTO `drupal_views_view` VALUES (22,'general_assemblies_table','','','','node',0);
INSERT INTO `drupal_views_view` VALUES (20,'position_profiles_by_term','','','','node',0);
INSERT INTO `drupal_views_view` VALUES (21,'position_profiles_by_user','','','','node',0);
INSERT INTO `drupal_views_view` VALUES (23,'general_assemblies_lookup','','','','node',0);
/*!40000 ALTER TABLE `drupal_views_view` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

