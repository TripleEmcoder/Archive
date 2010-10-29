
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
DROP TABLE IF EXISTS `drupal_messaging_message_parts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_messaging_message_parts` (
  `type` varchar(100) NOT NULL default '',
  `method` varchar(50) NOT NULL default '',
  `msgkey` varchar(100) NOT NULL default '',
  `module` varchar(255) NOT NULL default '',
  `message` longtext NOT NULL,
  KEY `type` (`type`),
  KEY `method` (`method`),
  KEY `msgkey` (`msgkey`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_messaging_message_parts` WRITE;
/*!40000 ALTER TABLE `drupal_messaging_message_parts` DISABLE KEYS */;
INSERT INTO `drupal_messaging_message_parts` VALUES ('notifications-event-node','default','subject','','Update for [type-name]: [title]');
INSERT INTO `drupal_messaging_message_parts` VALUES ('notifications-event-node','default','main','','[node-body]');
INSERT INTO `drupal_messaging_message_parts` VALUES ('notifications-event-node','default','digest','','[title]\r\nRead more [node-url]');
INSERT INTO `drupal_messaging_message_parts` VALUES ('notifications-event-node-insert','default','subject','','New [type-name]: [title]');
INSERT INTO `drupal_messaging_message_parts` VALUES ('notifications-event-node-insert','default','main','','[node-body]\r\n\r\nSee at [node-url]');
INSERT INTO `drupal_messaging_message_parts` VALUES ('notifications-event-node-insert','default','digest','','[title]\r\nRead more [node-url]');
INSERT INTO `drupal_messaging_message_parts` VALUES ('notifications-event-node-update','default','subject','','Update for [type-name]: [title]');
INSERT INTO `drupal_messaging_message_parts` VALUES ('notifications-event-node-update','default','main','','[node-body]\r\n\r\nSee at [node-url]');
INSERT INTO `drupal_messaging_message_parts` VALUES ('notifications-event-node-update','default','digest','','[title]\r\nRead more [node-url]');
INSERT INTO `drupal_messaging_message_parts` VALUES ('notifications-event-node-comment','default','subject','','Comment for [type-name]: [title]');
INSERT INTO `drupal_messaging_message_parts` VALUES ('notifications-event-node-comment','default','main','','Comment by [comment-author-name]: [comment-title]\r\n\r\n[comment-body]\r\n\r\nSee at [comment-url]');
INSERT INTO `drupal_messaging_message_parts` VALUES ('notifications-event-node-comment','default','digest','','New Comment on [title] by [comment-author-name] titled [comment-title]\r\nRead more [comment-url]');
INSERT INTO `drupal_messaging_message_parts` VALUES ('notifications-event','default','subject','','Event notification for [user] from [site-name]');
INSERT INTO `drupal_messaging_message_parts` VALUES ('notifications-event','default','header','','Greetings [realname],');
INSERT INTO `drupal_messaging_message_parts` VALUES ('notifications-event','default','main','','A item to which you are subscribed has been updated');
INSERT INTO `drupal_messaging_message_parts` VALUES ('notifications-event','default','footer','','This is an automatic message from [site-name]\r\nTo manage your subscriptions, browse to [subscriptions-manage]\r\nYou can unsubscribe at [unsubscribe-url]');
INSERT INTO `drupal_messaging_message_parts` VALUES ('notifications-digest','default','subject','','[site-name] subscription update for [user]');
INSERT INTO `drupal_messaging_message_parts` VALUES ('notifications-digest','default','header','','Greetings, [realname].\r\n\r\nThese are your messages');
INSERT INTO `drupal_messaging_message_parts` VALUES ('notifications-digest','default','main','','A [type] has been updated: [title]\r\n\r\n[event_list]');
INSERT INTO `drupal_messaging_message_parts` VALUES ('notifications-digest','default','closing','','...');
INSERT INTO `drupal_messaging_message_parts` VALUES ('notifications-digest','default','footer','','This is an automatic message from [site-name]\r\nTo manage your subscriptions, browse to [subscriptions-manage]');
/*!40000 ALTER TABLE `drupal_messaging_message_parts` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

