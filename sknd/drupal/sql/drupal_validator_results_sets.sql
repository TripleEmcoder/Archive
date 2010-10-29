
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
DROP TABLE IF EXISTS `drupal_validator_results_sets`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_validator_results_sets` (
  `rsid` int(10) unsigned NOT NULL auto_increment,
  `date` int(10) unsigned NOT NULL,
  `config` text NOT NULL,
  `global_validate` tinyint(3) unsigned NOT NULL,
  PRIMARY KEY  (`rsid`)
) ENGINE=MyISAM AUTO_INCREMENT=10 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_validator_results_sets` WRITE;
/*!40000 ALTER TABLE `drupal_validator_results_sets` DISABLE KEYS */;
INSERT INTO `drupal_validator_results_sets` VALUES (1,1255344370,'a:2:{s:17:\"validate_elements\";a:2:{s:4:\"node\";s:4:\"node\";s:4:\"view\";i:0;}s:13:\"content_types\";a:15:{s:11:\"public_page\";s:11:\"public_page\";s:18:\"profile_ambassador\";i:0;s:21:\"application_candidate\";i:0;s:30:\"application_candidate_language\";i:0;s:27:\"application_candidate_study\";i:0;s:7:\"company\";i:0;s:7:\"contact\";i:0;s:19:\"profile_coordinator\";i:0;s:5:\"forum\";i:0;s:18:\"internal_wiki_page\";i:0;s:10:\"simplenews\";i:0;s:4:\"page\";i:0;s:4:\"poll\";i:0;s:12:\"public_story\";i:0;s:7:\"service\";i:0;}}',0);
INSERT INTO `drupal_validator_results_sets` VALUES (2,1255344585,'a:2:{s:17:\"validate_elements\";a:2:{s:4:\"node\";s:4:\"node\";s:4:\"view\";i:0;}s:13:\"content_types\";a:15:{s:11:\"public_page\";s:11:\"public_page\";s:18:\"profile_ambassador\";i:0;s:21:\"application_candidate\";i:0;s:30:\"application_candidate_language\";i:0;s:27:\"application_candidate_study\";i:0;s:7:\"company\";i:0;s:7:\"contact\";i:0;s:19:\"profile_coordinator\";i:0;s:5:\"forum\";i:0;s:18:\"internal_wiki_page\";i:0;s:10:\"simplenews\";i:0;s:4:\"page\";i:0;s:4:\"poll\";i:0;s:12:\"public_story\";i:0;s:7:\"service\";i:0;}}',0);
INSERT INTO `drupal_validator_results_sets` VALUES (3,1255344873,'a:2:{s:17:\"validate_elements\";a:2:{s:4:\"node\";s:4:\"node\";s:4:\"view\";i:0;}s:13:\"content_types\";a:15:{s:11:\"public_page\";s:11:\"public_page\";s:18:\"profile_ambassador\";i:0;s:21:\"application_candidate\";i:0;s:30:\"application_candidate_language\";i:0;s:27:\"application_candidate_study\";i:0;s:7:\"company\";i:0;s:7:\"contact\";i:0;s:19:\"profile_coordinator\";i:0;s:5:\"forum\";i:0;s:18:\"internal_wiki_page\";i:0;s:10:\"simplenews\";i:0;s:4:\"page\";i:0;s:4:\"poll\";i:0;s:12:\"public_story\";i:0;s:7:\"service\";i:0;}}',0);
INSERT INTO `drupal_validator_results_sets` VALUES (4,1255345454,'a:2:{s:17:\"validate_elements\";a:2:{s:4:\"node\";s:4:\"node\";s:4:\"view\";i:0;}s:13:\"content_types\";a:15:{s:11:\"public_page\";s:11:\"public_page\";s:18:\"profile_ambassador\";i:0;s:21:\"application_candidate\";i:0;s:30:\"application_candidate_language\";i:0;s:27:\"application_candidate_study\";i:0;s:7:\"company\";i:0;s:7:\"contact\";i:0;s:19:\"profile_coordinator\";i:0;s:5:\"forum\";i:0;s:18:\"internal_wiki_page\";i:0;s:10:\"simplenews\";i:0;s:4:\"page\";i:0;s:4:\"poll\";i:0;s:12:\"public_story\";i:0;s:7:\"service\";i:0;}}',0);
INSERT INTO `drupal_validator_results_sets` VALUES (5,1255347880,'a:2:{s:17:\"validate_elements\";a:2:{s:4:\"node\";s:4:\"node\";s:4:\"view\";i:0;}s:13:\"content_types\";a:15:{s:11:\"public_page\";s:11:\"public_page\";s:18:\"profile_ambassador\";i:0;s:21:\"application_candidate\";i:0;s:30:\"application_candidate_language\";i:0;s:27:\"application_candidate_study\";i:0;s:7:\"company\";i:0;s:7:\"contact\";i:0;s:19:\"profile_coordinator\";i:0;s:5:\"forum\";i:0;s:18:\"internal_wiki_page\";i:0;s:10:\"simplenews\";i:0;s:4:\"page\";i:0;s:4:\"poll\";i:0;s:12:\"public_story\";i:0;s:7:\"service\";i:0;}}',0);
INSERT INTO `drupal_validator_results_sets` VALUES (6,1255349472,'a:2:{s:17:\"validate_elements\";a:2:{s:4:\"node\";s:4:\"node\";s:4:\"view\";i:0;}s:13:\"content_types\";a:15:{s:11:\"public_page\";s:11:\"public_page\";s:18:\"profile_ambassador\";i:0;s:21:\"application_candidate\";i:0;s:30:\"application_candidate_language\";i:0;s:27:\"application_candidate_study\";i:0;s:7:\"company\";i:0;s:7:\"contact\";i:0;s:19:\"profile_coordinator\";i:0;s:5:\"forum\";i:0;s:18:\"internal_wiki_page\";i:0;s:10:\"simplenews\";i:0;s:4:\"page\";i:0;s:4:\"poll\";i:0;s:12:\"public_story\";i:0;s:7:\"service\";i:0;}}',1);
INSERT INTO `drupal_validator_results_sets` VALUES (7,1255349681,'a:2:{s:17:\"validate_elements\";a:2:{s:4:\"node\";s:4:\"node\";s:4:\"view\";i:0;}s:13:\"content_types\";a:15:{s:11:\"public_page\";s:11:\"public_page\";s:18:\"profile_ambassador\";i:0;s:21:\"application_candidate\";i:0;s:30:\"application_candidate_language\";i:0;s:27:\"application_candidate_study\";i:0;s:7:\"company\";i:0;s:7:\"contact\";i:0;s:19:\"profile_coordinator\";i:0;s:5:\"forum\";i:0;s:18:\"internal_wiki_page\";i:0;s:10:\"simplenews\";i:0;s:4:\"page\";i:0;s:4:\"poll\";i:0;s:12:\"public_story\";i:0;s:7:\"service\";i:0;}}',0);
INSERT INTO `drupal_validator_results_sets` VALUES (8,1255350961,'a:2:{s:17:\"validate_elements\";a:2:{s:4:\"node\";s:4:\"node\";s:4:\"view\";i:0;}s:13:\"content_types\";a:15:{s:11:\"public_page\";s:11:\"public_page\";s:18:\"profile_ambassador\";i:0;s:21:\"application_candidate\";i:0;s:30:\"application_candidate_language\";i:0;s:27:\"application_candidate_study\";i:0;s:7:\"company\";i:0;s:7:\"contact\";i:0;s:19:\"profile_coordinator\";i:0;s:5:\"forum\";i:0;s:18:\"internal_wiki_page\";i:0;s:10:\"simplenews\";i:0;s:4:\"page\";i:0;s:4:\"poll\";i:0;s:12:\"public_story\";i:0;s:7:\"service\";i:0;}}',0);
INSERT INTO `drupal_validator_results_sets` VALUES (9,1255372304,'a:2:{s:17:\"validate_elements\";a:2:{s:4:\"node\";s:4:\"node\";s:4:\"view\";i:0;}s:13:\"content_types\";a:15:{s:11:\"public_page\";s:11:\"public_page\";s:18:\"profile_ambassador\";i:0;s:21:\"application_candidate\";i:0;s:30:\"application_candidate_language\";i:0;s:27:\"application_candidate_study\";i:0;s:7:\"company\";i:0;s:7:\"contact\";i:0;s:19:\"profile_coordinator\";i:0;s:5:\"forum\";i:0;s:18:\"internal_wiki_page\";i:0;s:10:\"simplenews\";i:0;s:4:\"page\";i:0;s:4:\"poll\";i:0;s:12:\"public_story\";i:0;s:7:\"service\";i:0;}}',0);
/*!40000 ALTER TABLE `drupal_validator_results_sets` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

