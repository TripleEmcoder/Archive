
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
DROP TABLE IF EXISTS `drupal_node_type`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_node_type` (
  `type` varchar(32) NOT NULL default '',
  `name` varchar(255) NOT NULL default '',
  `module` varchar(255) NOT NULL default '',
  `description` mediumtext NOT NULL,
  `help` mediumtext NOT NULL,
  `has_title` tinyint(3) unsigned NOT NULL default '0',
  `title_label` varchar(255) NOT NULL default '',
  `has_body` tinyint(3) unsigned NOT NULL default '0',
  `body_label` varchar(255) NOT NULL default '',
  `min_word_count` smallint(5) unsigned NOT NULL default '0',
  `custom` tinyint(4) NOT NULL default '0',
  `modified` tinyint(4) NOT NULL default '0',
  `locked` tinyint(4) NOT NULL default '0',
  `orig_type` varchar(255) NOT NULL default '',
  PRIMARY KEY  (`type`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_node_type` WRITE;
/*!40000 ALTER TABLE `drupal_node_type` DISABLE KEYS */;
INSERT INTO `drupal_node_type` VALUES ('poll','Poll','poll','A <em>poll</em> is a question with a set of possible responses. A <em>poll</em>, once created, automatically provides a simple running count of the number of votes received for each response.','',1,'Question',0,'',0,0,1,1,'poll');
INSERT INTO `drupal_node_type` VALUES ('service','Service','node','','',1,'Title',1,'Comment',0,1,1,0,'');
INSERT INTO `drupal_node_type` VALUES ('forum','Forum topic','forum','A <em>forum topic</em> is the initial post to a new discussion thread within a forum.','',1,'Subject',1,'Body',0,0,1,1,'forum');
INSERT INTO `drupal_node_type` VALUES ('contact','Contact','node','','',1,'Title',0,'',0,1,1,0,'');
INSERT INTO `drupal_node_type` VALUES ('company','Company','node','','',1,'Title',0,'',0,1,1,0,'');
INSERT INTO `drupal_node_type` VALUES ('team','Team','node','','',1,'Name',0,'',0,1,1,0,'');
INSERT INTO `drupal_node_type` VALUES ('position_profile','Position profile','node','','',1,'Title',0,'',0,1,1,0,'');
INSERT INTO `drupal_node_type` VALUES ('simplenews','Newsletter issue','node','A newsletter issue to be sent to subscribed email addresses.','',1,'Title',1,'Body',0,1,1,0,'simplenews');
INSERT INTO `drupal_node_type` VALUES ('internal_wiki_page','Internal wiki page','node','','',1,'Title',1,'Body',0,1,1,0,'');
INSERT INTO `drupal_node_type` VALUES ('public_page','Public page','node','','',1,'Title',1,'Body',0,1,1,0,'');
INSERT INTO `drupal_node_type` VALUES ('application_candidate','Candidate application','node','','',1,'Title',0,'',0,1,1,0,'');
INSERT INTO `drupal_node_type` VALUES ('application_candidate_study','Candidate application study','node','','',1,'Title',0,'',0,1,1,0,'');
INSERT INTO `drupal_node_type` VALUES ('application_candidate_language','Candidate application language','node','','',1,'Title',1,'Body',0,1,1,0,'');
INSERT INTO `drupal_node_type` VALUES ('public_story','Public story','node','','',1,'Title',1,'Body',0,1,1,0,'');
INSERT INTO `drupal_node_type` VALUES ('internal_page','Internal page','node','','',1,'Title',1,'Body',0,1,1,0,'');
INSERT INTO `drupal_node_type` VALUES ('team_position','Team position','node','','',1,'Title',0,'',0,1,1,0,'');
INSERT INTO `drupal_node_type` VALUES ('general_assembly','General assembly','node','','',1,'Title',0,'',0,1,1,0,'');
INSERT INTO `drupal_node_type` VALUES ('webform','Webform','webform','Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.','',1,'Title',1,'Body',0,0,1,1,'webform');
INSERT INTO `drupal_node_type` VALUES ('member_application','Member application','node','','',1,'Title',0,'',0,1,1,0,'');
/*!40000 ALTER TABLE `drupal_node_type` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

