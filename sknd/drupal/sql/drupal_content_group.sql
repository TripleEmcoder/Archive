
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
DROP TABLE IF EXISTS `drupal_content_group`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_content_group` (
  `type_name` varchar(32) NOT NULL default '',
  `group_name` varchar(32) NOT NULL default '',
  `label` varchar(255) NOT NULL default '',
  `settings` mediumtext NOT NULL,
  `weight` int(11) NOT NULL default '0',
  `group_type` varchar(32) NOT NULL default 'standard',
  PRIMARY KEY  (`type_name`,`group_name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_content_group` WRITE;
/*!40000 ALTER TABLE `drupal_content_group` DISABLE KEYS */;
INSERT INTO `drupal_content_group` VALUES ('application_candidate','group_candidate_personal_info','Personal information','a:2:{s:4:\"form\";a:2:{s:5:\"style\";s:8:\"fieldset\";s:11:\"description\";s:0:\"\";}s:7:\"display\";a:10:{s:11:\"description\";s:0:\"\";s:5:\"label\";s:5:\"above\";s:6:\"teaser\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:4:\"full\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:4;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:2;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:3;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:11:\"email_plain\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:10:\"email_html\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:5:\"token\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}}}',4,'standard');
INSERT INTO `drupal_content_group` VALUES ('application_candidate','group_candidate_language_skills','Foreign language skills','a:2:{s:4:\"form\";a:2:{s:5:\"style\";s:8:\"fieldset\";s:11:\"description\";s:23:\"Foreign language skills\";}s:7:\"display\";a:10:{s:11:\"description\";s:0:\"\";s:6:\"teaser\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:4:\"full\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:4;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:2;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:3;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:11:\"email_plain\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:10:\"email_html\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:5:\"token\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:5:\"label\";s:5:\"above\";}}',16,'standard');
INSERT INTO `drupal_content_group` VALUES ('team_position','group_election','Election','a:2:{s:4:\"form\";a:2:{s:5:\"style\";s:8:\"fieldset\";s:11:\"description\";s:0:\"\";}s:7:\"display\";a:10:{s:11:\"description\";s:0:\"\";s:5:\"label\";s:5:\"above\";s:6:\"teaser\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:4:\"full\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:4;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:2;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:3;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:11:\"email_plain\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:10:\"email_html\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:5:\"token\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}}}',6,'standard');
INSERT INTO `drupal_content_group` VALUES ('team_position','group_position','Position','a:2:{s:4:\"form\";a:2:{s:5:\"style\";s:8:\"fieldset\";s:11:\"description\";s:0:\"\";}s:7:\"display\";a:10:{s:11:\"description\";s:0:\"\";s:5:\"label\";s:5:\"above\";s:6:\"teaser\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:4:\"full\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:4;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:2;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:3;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:11:\"email_plain\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:10:\"email_html\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:5:\"token\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}}}',3,'standard');
INSERT INTO `drupal_content_group` VALUES ('team_position','group_person','Person','a:2:{s:4:\"form\";a:2:{s:5:\"style\";s:8:\"fieldset\";s:11:\"description\";s:0:\"\";}s:7:\"display\";a:10:{s:11:\"description\";s:0:\"\";s:5:\"label\";s:5:\"above\";s:6:\"teaser\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:4:\"full\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:4;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:2;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:3;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:11:\"email_plain\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:10:\"email_html\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:5:\"token\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}}}',4,'standard');
INSERT INTO `drupal_content_group` VALUES ('general_assembly','group_elections','Elections','a:2:{s:4:\"form\";a:2:{s:5:\"style\";s:8:\"fieldset\";s:11:\"description\";s:0:\"\";}s:7:\"display\";a:10:{s:11:\"description\";s:0:\"\";s:5:\"label\";s:5:\"above\";s:6:\"teaser\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:4:\"full\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:4;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:2;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:3;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:11:\"email_plain\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:10:\"email_html\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:5:\"token\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}}}',7,'standard');
INSERT INTO `drupal_content_group` VALUES ('team_position','group_discharge','Discharge','a:2:{s:4:\"form\";a:2:{s:5:\"style\";s:8:\"fieldset\";s:11:\"description\";s:0:\"\";}s:7:\"display\";a:10:{s:11:\"description\";s:0:\"\";s:5:\"label\";s:5:\"above\";s:6:\"teaser\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:4:\"full\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:4;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:2;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:3;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:11:\"email_plain\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:10:\"email_html\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:5:\"token\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}}}',13,'standard');
INSERT INTO `drupal_content_group` VALUES ('general_assembly','group_discharges','Discharges','a:2:{s:4:\"form\";a:2:{s:5:\"style\";s:8:\"fieldset\";s:11:\"description\";s:0:\"\";}s:7:\"display\";a:10:{s:11:\"description\";s:0:\"\";s:5:\"label\";s:5:\"above\";s:6:\"teaser\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:4:\"full\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:4;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:2;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:3;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:11:\"email_plain\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:10:\"email_html\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:5:\"token\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}}}',8,'standard');
INSERT INTO `drupal_content_group` VALUES ('member_application','group_nomination','Nomination','a:2:{s:4:\"form\";a:2:{s:5:\"style\";s:8:\"fieldset\";s:11:\"description\";s:0:\"\";}s:7:\"display\";a:10:{s:11:\"description\";s:0:\"\";s:5:\"label\";s:5:\"above\";s:6:\"teaser\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:4:\"full\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:4;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:2;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}i:3;a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:11:\"email_plain\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:10:\"email_html\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}s:5:\"token\";a:2:{s:6:\"format\";s:8:\"fieldset\";s:7:\"exclude\";i:0;}}}',35,'standard');
/*!40000 ALTER TABLE `drupal_content_group` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

