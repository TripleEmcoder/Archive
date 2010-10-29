
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
DROP TABLE IF EXISTS `drupal_actions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_actions` (
  `aid` varchar(255) NOT NULL default '0',
  `type` varchar(32) NOT NULL default '',
  `callback` varchar(255) NOT NULL default '',
  `parameters` longtext NOT NULL,
  `description` varchar(255) NOT NULL default '0',
  PRIMARY KEY  (`aid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_actions` WRITE;
/*!40000 ALTER TABLE `drupal_actions` DISABLE KEYS */;
INSERT INTO `drupal_actions` VALUES ('comment_unpublish_action','comment','comment_unpublish_action','','Unpublish comment');
INSERT INTO `drupal_actions` VALUES ('node_publish_action','node','node_publish_action','','Publish post');
INSERT INTO `drupal_actions` VALUES ('node_unpublish_action','node','node_unpublish_action','','Unpublish post');
INSERT INTO `drupal_actions` VALUES ('node_make_sticky_action','node','node_make_sticky_action','','Make post sticky');
INSERT INTO `drupal_actions` VALUES ('node_make_unsticky_action','node','node_make_unsticky_action','','Make post unsticky');
INSERT INTO `drupal_actions` VALUES ('node_promote_action','node','node_promote_action','','Promote post to front page');
INSERT INTO `drupal_actions` VALUES ('node_unpromote_action','node','node_unpromote_action','','Remove post from front page');
INSERT INTO `drupal_actions` VALUES ('node_save_action','node','node_save_action','','Save post');
INSERT INTO `drupal_actions` VALUES ('user_block_user_action','user','user_block_user_action','','Block current user');
INSERT INTO `drupal_actions` VALUES ('user_block_ip_action','user','user_block_ip_action','','Ban IP address of current user');
INSERT INTO `drupal_actions` VALUES ('workflow_select_next_state_action','node','workflow_select_next_state_action','','Change workflow state of post to next state');
INSERT INTO `drupal_actions` VALUES ('simplenews_cron_action','simplenews','simplenews_cron_action','','Send pending simplenews newsletters');
INSERT INTO `drupal_actions` VALUES ('backup_migrate_backup_action','system','backup_migrate_backup_action','','Backup the database with the default settings');
INSERT INTO `drupal_actions` VALUES ('views_bulk_operations_delete_node_action','node','views_bulk_operations_delete_node_action','','Delete node');
INSERT INTO `drupal_actions` VALUES ('views_bulk_operations_delete_user_action','user','views_bulk_operations_delete_user_action','','Delete user');
INSERT INTO `drupal_actions` VALUES ('views_bulk_operations_delete_comment_action','comment','views_bulk_operations_delete_comment_action','','Delete comment');
INSERT INTO `drupal_actions` VALUES ('views_bulk_operations_delete_term_action','term','views_bulk_operations_delete_term_action','','Delete term');
INSERT INTO `drupal_actions` VALUES ('views_bulk_operations_ruleset_action_rules_set_1','node','views_bulk_operations_ruleset_action_rules_set_1','','Example: Empty rule set working with content');
INSERT INTO `drupal_actions` VALUES ('comment_publish_action','comment','comment_publish_action','','Publish comment');
/*!40000 ALTER TABLE `drupal_actions` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

