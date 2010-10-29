
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
DROP TABLE IF EXISTS `drupal_viewreference`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_viewreference` (
  `view_id` int(10) unsigned NOT NULL default '0',
  `name` varchar(32) NOT NULL default '',
  `position` varchar(64) NOT NULL default '',
  `title` varchar(255) NOT NULL default '',
  PRIMARY KEY  (`view_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_viewreference` WRITE;
/*!40000 ALTER TABLE `drupal_viewreference` DISABLE KEYS */;
INSERT INTO `drupal_viewreference` VALUES (1,'active_users','block_1','Active_users Block');
INSERT INTO `drupal_viewreference` VALUES (2,'comments_recent','page','Comments_recent Page');
INSERT INTO `drupal_viewreference` VALUES (3,'comments_recent','block','Comments_recent Block');
INSERT INTO `drupal_viewreference` VALUES (4,'tracker','page','Tracker Page');
INSERT INTO `drupal_viewreference` VALUES (5,'frontpage','page','Frontpage Page');
INSERT INTO `drupal_viewreference` VALUES (6,'frontpage','feed','Frontpage Feed');
INSERT INTO `drupal_viewreference` VALUES (7,'glossary','page','Glossary Page');
INSERT INTO `drupal_viewreference` VALUES (8,'glossary','attachment','Glossary Attachment');
INSERT INTO `drupal_viewreference` VALUES (9,'archive','page','Archive Page');
INSERT INTO `drupal_viewreference` VALUES (10,'archive','block','Archive Block');
INSERT INTO `drupal_viewreference` VALUES (11,'backlinks','page','Backlinks Page');
INSERT INTO `drupal_viewreference` VALUES (12,'backlinks','block','Backlinks Block');
INSERT INTO `drupal_viewreference` VALUES (13,'popular','page','Popular Popular (page)');
INSERT INTO `drupal_viewreference` VALUES (14,'popular','page_1','Popular Today (page)');
INSERT INTO `drupal_viewreference` VALUES (15,'popular','block','Popular Popular (block)');
INSERT INTO `drupal_viewreference` VALUES (16,'popular','block_1','Popular Today (block)');
INSERT INTO `drupal_viewreference` VALUES (17,'taxonomy_term','page','Taxonomy_term Page');
INSERT INTO `drupal_viewreference` VALUES (18,'taxonomy_term','feed','Taxonomy_term Core feed');
INSERT INTO `drupal_viewreference` VALUES (19,'taxonomy_term','feed_1','Taxonomy_term Views 1 feed');
INSERT INTO `drupal_viewreference` VALUES (20,'location_table','page_1','Location_table Page');
INSERT INTO `drupal_viewreference` VALUES (21,'location_directory','page_1','Location_directory Page');
INSERT INTO `drupal_viewreference` VALUES (22,'user_location_table','page_1','User_location_table Page');
/*!40000 ALTER TABLE `drupal_viewreference` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

