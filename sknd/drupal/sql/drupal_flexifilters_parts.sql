
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
DROP TABLE IF EXISTS `drupal_flexifilters_parts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_flexifilters_parts` (
  `pid` int(10) unsigned NOT NULL auto_increment,
  `fid` int(10) unsigned NOT NULL,
  `parent_pid` int(10) unsigned default NULL,
  `type` tinyint(3) unsigned NOT NULL,
  `class_name` varchar(255) default NULL,
  `settings` longtext NOT NULL,
  PRIMARY KEY  (`pid`),
  KEY `fid` (`fid`)
) ENGINE=MyISAM AUTO_INCREMENT=29 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_flexifilters_parts` WRITE;
/*!40000 ALTER TABLE `drupal_flexifilters_parts` DISABLE KEYS */;
INSERT INTO `drupal_flexifilters_parts` VALUES (1,1,0,2,'','');
INSERT INTO `drupal_flexifilters_parts` VALUES (2,1,1,0,'flexifilter_text_prepend','a:2:{s:4:\"text\";s:9:\"</nowiki>\";s:4:\"step\";s:7:\"process\";}');
INSERT INTO `drupal_flexifilters_parts` VALUES (3,1,1,0,'flexifilter_text_append','a:2:{s:4:\"text\";s:8:\"<nowiki>\";s:4:\"step\";s:7:\"process\";}');
INSERT INTO `drupal_flexifilters_parts` VALUES (4,1,1,0,'flexifilter_chunk_grab','a:6:{s:6:\"starts\";s:9:\"</nowiki>\";s:4:\"ends\";s:8:\"<nowiki>\";s:11:\"pass_limits\";i:0;s:14:\"case_sensitive\";i:0;s:12:\"include_rest\";i:1;s:4:\"step\";s:7:\"process\";}');
INSERT INTO `drupal_flexifilters_parts` VALUES (5,1,4,0,'flexifilter_text_alternation','a:3:{s:4:\"find\";s:4:\"====\";s:7:\"replace\";s:10:\"<h4>\n</h4>\";s:4:\"step\";s:7:\"process\";}');
INSERT INTO `drupal_flexifilters_parts` VALUES (6,1,4,0,'flexifilter_text_alternation','a:3:{s:4:\"find\";s:3:\"===\";s:7:\"replace\";s:10:\"<h3>\n</h3>\";s:4:\"step\";s:7:\"process\";}');
INSERT INTO `drupal_flexifilters_parts` VALUES (7,1,4,0,'flexifilter_text_alternation','a:3:{s:4:\"find\";s:2:\"==\";s:7:\"replace\";s:10:\"<h2>\n</h2>\";s:4:\"step\";s:7:\"process\";}');
INSERT INTO `drupal_flexifilters_parts` VALUES (8,1,4,0,'flexifilter_text_alternation','a:3:{s:4:\"find\";s:3:\"\'\'\'\";s:7:\"replace\";s:18:\"<strong>\n</strong>\";s:4:\"step\";s:7:\"process\";}');
INSERT INTO `drupal_flexifilters_parts` VALUES (9,1,4,0,'flexifilter_text_alternation','a:3:{s:4:\"find\";s:2:\"\'\'\";s:7:\"replace\";s:10:\"<em>\n</em>\";s:4:\"step\";s:7:\"process\";}');
INSERT INTO `drupal_flexifilters_parts` VALUES (10,1,4,0,'flexifilter_chunk_grab','a:6:{s:6:\"starts\";s:2:\"[[\";s:4:\"ends\";s:2:\"]]\";s:11:\"pass_limits\";i:0;s:14:\"case_sensitive\";i:0;s:12:\"include_rest\";i:1;s:4:\"step\";s:7:\"process\";}');
INSERT INTO `drupal_flexifilters_parts` VALUES (11,1,10,0,'flexifilter_control_if','a:0:{}');
INSERT INTO `drupal_flexifilters_parts` VALUES (12,1,11,0,'flexifilter_text_replace','a:3:{s:4:\"find\";s:1:\"~\";s:7:\"replace\";s:2:\"\\~\";s:4:\"step\";s:7:\"process\";}');
INSERT INTO `drupal_flexifilters_parts` VALUES (13,1,11,0,'flexifilter_text_append','a:2:{s:4:\"text\";s:2:\"~~\";s:4:\"step\";s:7:\"process\";}');
INSERT INTO `drupal_flexifilters_parts` VALUES (14,1,11,0,'flexifilter_advanced_append','a:1:{s:4:\"step\";s:7:\"process\";}');
INSERT INTO `drupal_flexifilters_parts` VALUES (15,1,14,0,'flexifilter_text_replace','a:3:{s:4:\"find\";s:2:\"~~\";s:7:\"replace\";s:4:\"</a>\";s:4:\"step\";s:7:\"process\";}');
INSERT INTO `drupal_flexifilters_parts` VALUES (16,1,11,0,'flexifilter_text_replace','a:3:{s:4:\"find\";s:2:\"~~\";s:7:\"replace\";s:2:\"\">\";s:4:\"step\";s:7:\"process\";}');
INSERT INTO `drupal_flexifilters_parts` VALUES (17,1,16,0,'flexifilter_text_replace','a:3:{s:4:\"find\";s:2:\"~~\";s:7:\"replace\";s:4:\"</a>\";s:4:\"step\";s:7:\"process\";}');
INSERT INTO `drupal_flexifilters_parts` VALUES (18,1,11,0,'flexifilter_text_prepend','a:2:{s:4:\"text\";s:38:\"<a href=\"http://en.wikipedia.org/wiki/\";s:4:\"step\";s:7:\"process\";}');
INSERT INTO `drupal_flexifilters_parts` VALUES (19,1,18,0,'flexifilter_text_replace','a:3:{s:4:\"find\";s:2:\"~~\";s:7:\"replace\";s:4:\"</a>\";s:4:\"step\";s:7:\"process\";}');
INSERT INTO `drupal_flexifilters_parts` VALUES (20,1,11,0,'flexifilter_text_replace','a:3:{s:4:\"find\";s:2:\"\\~\";s:7:\"replace\";s:1:\"~\";s:4:\"step\";s:7:\"process\";}');
INSERT INTO `drupal_flexifilters_parts` VALUES (21,1,20,0,'flexifilter_text_replace','a:3:{s:4:\"find\";s:2:\"~~\";s:7:\"replace\";s:4:\"</a>\";s:4:\"step\";s:7:\"process\";}');
INSERT INTO `drupal_flexifilters_parts` VALUES (22,1,11,1,'flexifilter_group_not','a:0:{}');
INSERT INTO `drupal_flexifilters_parts` VALUES (23,1,22,1,'flexifilter_text_search','a:2:{s:4:\"find\";s:1:\"|\";s:8:\"is_regex\";i:0;}');
INSERT INTO `drupal_flexifilters_parts` VALUES (24,1,10,0,'flexifilter_control_if','a:0:{}');
INSERT INTO `drupal_flexifilters_parts` VALUES (25,1,24,0,'flexifilter_text_prepend','a:2:{s:4:\"text\";s:38:\"<a href=\"http://en.wikipedia.org/wiki/\";s:4:\"step\";s:7:\"process\";}');
INSERT INTO `drupal_flexifilters_parts` VALUES (26,1,24,0,'flexifilter_text_replace','a:3:{s:4:\"find\";s:1:\"|\";s:7:\"replace\";s:2:\"\">\";s:4:\"step\";s:7:\"process\";}');
INSERT INTO `drupal_flexifilters_parts` VALUES (27,1,24,0,'flexifilter_text_append','a:2:{s:4:\"text\";s:4:\"</a>\";s:4:\"step\";s:7:\"process\";}');
INSERT INTO `drupal_flexifilters_parts` VALUES (28,1,24,1,'flexifilter_text_search','a:2:{s:4:\"find\";s:1:\"|\";s:8:\"is_regex\";i:0;}');
/*!40000 ALTER TABLE `drupal_flexifilters_parts` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

