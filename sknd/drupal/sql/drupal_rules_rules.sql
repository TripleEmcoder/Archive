
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
DROP TABLE IF EXISTS `drupal_rules_rules`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_rules_rules` (
  `name` varchar(255) NOT NULL default '',
  `data` longblob,
  PRIMARY KEY  (`name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_rules_rules` WRITE;
/*!40000 ALTER TABLE `drupal_rules_rules` DISABLE KEYS */;
INSERT INTO `drupal_rules_rules` VALUES ('rules_example_1','a:8:{s:5:\"#type\";s:4:\"rule\";s:4:\"#set\";s:15:\"event_node_view\";s:6:\"#label\";s:59:\"Example rule: When viewing an unpublished page, publish it.\";s:7:\"#status\";s:6:\"custom\";s:11:\"#categories\";a:1:{i:0;s:7:\"example\";}s:7:\"#active\";i:0;s:11:\"#conditions\";a:2:{i:0;a:4:{s:5:\"#type\";s:9:\"condition\";s:5:\"#name\";s:36:\"rules_condition_content_is_published\";s:9:\"#settings\";a:1:{s:13:\"#argument map\";a:1:{s:4:\"node\";s:4:\"node\";}}s:7:\"#negate\";i:1;}i:1;a:3:{s:5:\"#type\";s:9:\"condition\";s:5:\"#name\";s:31:\"rules_condition_content_is_type\";s:9:\"#settings\";a:2:{s:13:\"#argument map\";a:1:{s:4:\"node\";s:4:\"node\";}s:4:\"type\";a:1:{i:0;s:4:\"page\";}}}}s:8:\"#actions\";a:1:{i:0;a:3:{s:5:\"#type\";s:6:\"action\";s:5:\"#name\";s:30:\"rules_core_node_publish_action\";s:9:\"#settings\";a:2:{s:13:\"#argument map\";a:1:{s:4:\"node\";s:4:\"node\";}s:9:\"auto_save\";b:1;}}}}');
INSERT INTO `drupal_rules_rules` VALUES ('rules_1','a:9:{s:5:\"#type\";s:4:\"rule\";s:4:\"#set\";s:17:\"event_node_insert\";s:6:\"#label\";s:29:\"Process candidate application\";s:7:\"#active\";i:1;s:7:\"#weight\";s:1:\"0\";s:11:\"#categories\";a:0:{}s:7:\"#status\";s:6:\"custom\";s:11:\"#conditions\";a:1:{i:0;a:5:{s:7:\"#weight\";d:0;s:5:\"#info\";a:3:{s:5:\"label\";s:40:\"Created content is Candidate application\";s:9:\"arguments\";a:1:{s:4:\"node\";a:2:{s:4:\"type\";s:4:\"node\";s:5:\"label\";s:7:\"Content\";}}s:6:\"module\";s:4:\"Node\";}s:5:\"#name\";s:31:\"rules_condition_content_is_type\";s:9:\"#settings\";a:2:{s:4:\"type\";a:1:{s:21:\"application_candidate\";s:21:\"application_candidate\";}s:13:\"#argument map\";a:1:{s:4:\"node\";s:4:\"node\";}}s:5:\"#type\";s:9:\"condition\";}}s:8:\"#actions\";a:3:{i:0;a:5:{s:5:\"#type\";s:6:\"action\";s:9:\"#settings\";a:9:{s:2:\"to\";s:40:\"[node:field_candidate_email_address-raw]\";s:2:\"cc\";s:0:\"\";s:2:\"bc\";s:0:\"\";s:4:\"from\";s:21:\"aplikacje@cognitis.pl\";s:7:\"subject\";s:39:\"Potwierdzenie zgłoszenia: [node:title]\";s:12:\"message_html\";s:52:\"<?php\r\nprint node_view(node_load($node->nid));\r\n?>\r\n\";s:17:\"message_plaintext\";s:0:\"\";s:11:\"attachments\";s:0:\"\";s:11:\"#eval input\";a:2:{s:27:\"token_rules_input_evaluator\";a:3:{s:2:\"to\";a:1:{i:0;s:4:\"node\";}s:7:\"subject\";a:1:{i:0;s:4:\"node\";}s:17:\"message_plaintext\";a:1:{i:0;s:4:\"node\";}}s:25:\"rules_input_evaluator_php\";a:1:{s:12:\"message_html\";a:1:{i:0;s:4:\"node\";}}}}s:5:\"#name\";s:26:\"mimemail_rules_action_mail\";s:5:\"#info\";a:3:{s:5:\"label\";s:46:\"Send an HTML mail to an arbitrary mail address\";s:6:\"module\";s:9:\"Mime Mail\";s:10:\"eval input\";a:8:{i:0;s:4:\"from\";i:1;s:2:\"to\";i:2;s:2:\"cc\";i:3;s:2:\"bc\";i:4;s:7:\"subject\";i:5;s:12:\"message_html\";i:6;s:17:\"message_plaintext\";i:7;s:11:\"attachments\";}}s:7:\"#weight\";d:0;}i:1;a:5:{s:7:\"#weight\";d:0;s:5:\"#info\";a:3:{s:5:\"label\";s:46:\"Send an HTML mail to an arbitrary mail address\";s:6:\"module\";s:9:\"Mime Mail\";s:10:\"eval input\";a:8:{i:0;s:4:\"from\";i:1;s:2:\"to\";i:2;s:2:\"cc\";i:3;s:2:\"bc\";i:4;s:7:\"subject\";i:5;s:12:\"message_html\";i:6;s:17:\"message_plaintext\";i:7;s:11:\"attachments\";}}s:5:\"#name\";s:26:\"mimemail_rules_action_mail\";s:9:\"#settings\";a:9:{s:2:\"to\";s:21:\"aplikacje@cognitis.pl\";s:2:\"cc\";s:0:\"\";s:2:\"bc\";s:0:\"\";s:4:\"from\";s:21:\"aplikacje@cognitis.pl\";s:7:\"subject\";s:28:\"Nowa aplikacja: [node:title]\";s:12:\"message_html\";s:54:\"<?php\r\nprint node_view(node_load($node->nid));\r\n?>\r\n\r\n\";s:17:\"message_plaintext\";s:0:\"\";s:11:\"attachments\";s:0:\"\";s:11:\"#eval input\";a:2:{s:27:\"token_rules_input_evaluator\";a:2:{s:2:\"to\";a:1:{i:0;s:4:\"node\";}s:7:\"subject\";a:1:{i:0;s:4:\"node\";}}s:25:\"rules_input_evaluator_php\";a:1:{s:12:\"message_html\";a:1:{i:0;s:4:\"node\";}}}}s:5:\"#type\";s:6:\"action\";}i:2;a:5:{s:5:\"#info\";a:3:{s:5:\"label\";s:13:\"Page redirect\";s:6:\"module\";s:6:\"System\";s:10:\"eval input\";a:3:{i:0;s:4:\"path\";i:1;s:5:\"query\";i:2;s:8:\"fragment\";}}s:5:\"#name\";s:24:\"rules_action_drupal_goto\";s:9:\"#settings\";a:5:{s:4:\"path\";s:44:\"o-nas/dolacz-do-nas/potwierdzenie-zgloszenia\";s:5:\"query\";s:0:\"\";s:8:\"fragment\";s:0:\"\";s:5:\"force\";i:0;s:9:\"immediate\";i:0;}s:5:\"#type\";s:6:\"action\";s:7:\"#weight\";d:10;}}}');
/*!40000 ALTER TABLE `drupal_rules_rules` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

