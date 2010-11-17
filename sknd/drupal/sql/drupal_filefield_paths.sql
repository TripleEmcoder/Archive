
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
DROP TABLE IF EXISTS `drupal_filefield_paths`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_filefield_paths` (
  `type` varchar(32) NOT NULL default '',
  `field` varchar(32) NOT NULL default '',
  `filename` mediumtext NOT NULL,
  `filepath` mediumtext NOT NULL,
  `filealias` mediumtext NOT NULL,
  UNIQUE KEY `type_field` (`type`,`field`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_filefield_paths` WRITE;
/*!40000 ALTER TABLE `drupal_filefield_paths` DISABLE KEYS */;
INSERT INTO `drupal_filefield_paths` VALUES ('public_page','upload','a:4:{s:5:\"value\";s:42:\"[filefield-onlyname].[filefield-extension]\";s:7:\"tolower\";i:1;s:8:\"pathauto\";i:1;s:13:\"transliterate\";i:1;}','a:4:{s:5:\"value\";s:24:\"attachments/[type]/[nid]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:5:{s:5:\"value\";s:57:\"[menupath-raw]/[filefield-onlyname].[filefield-extension]\";s:7:\"tolower\";i:1;s:8:\"pathauto\";i:1;s:13:\"transliterate\";i:1;s:7:\"display\";i:1;}');
INSERT INTO `drupal_filefield_paths` VALUES ('public_page','comment_upload','a:4:{s:5:\"value\";s:42:\"[filefield-onlyname].[filefield-extension]\";s:7:\"tolower\";i:1;s:8:\"pathauto\";i:1;s:13:\"transliterate\";i:1;}','a:4:{s:5:\"value\";s:30:\"attachments/[type]/[nid]/[cid]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:5:{s:5:\"value\";s:80:\"sites/default/files/[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;s:7:\"display\";i:0;}');
INSERT INTO `drupal_filefield_paths` VALUES ('internal_wiki_page','upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','');
INSERT INTO `drupal_filefield_paths` VALUES ('internal_wiki_page','comment_upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','');
INSERT INTO `drupal_filefield_paths` VALUES ('public_story','upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','');
INSERT INTO `drupal_filefield_paths` VALUES ('public_story','comment_upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','');
INSERT INTO `drupal_filefield_paths` VALUES ('profile_coordinator','upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','');
INSERT INTO `drupal_filefield_paths` VALUES ('profile_coordinator','comment_upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','');
INSERT INTO `drupal_filefield_paths` VALUES ('profile_ambassador','upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','');
INSERT INTO `drupal_filefield_paths` VALUES ('profile_ambassador','comment_upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','');
INSERT INTO `drupal_filefield_paths` VALUES ('team','upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:5:{s:5:\"value\";s:80:\"sites/default/files/[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;s:7:\"display\";i:0;}');
INSERT INTO `drupal_filefield_paths` VALUES ('team','comment_upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:5:{s:5:\"value\";s:80:\"sites/default/files/[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;s:7:\"display\";i:0;}');
INSERT INTO `drupal_filefield_paths` VALUES ('function_appointment','upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','');
INSERT INTO `drupal_filefield_paths` VALUES ('function_appointment','comment_upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','');
INSERT INTO `drupal_filefield_paths` VALUES ('function_profile','upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','');
INSERT INTO `drupal_filefield_paths` VALUES ('function_profile','comment_upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','');
INSERT INTO `drupal_filefield_paths` VALUES ('position','upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','');
INSERT INTO `drupal_filefield_paths` VALUES ('position','comment_upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','');
INSERT INTO `drupal_filefield_paths` VALUES ('position_profile','upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:5:{s:5:\"value\";s:80:\"sites/default/files/[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;s:7:\"display\";i:0;}');
INSERT INTO `drupal_filefield_paths` VALUES ('position_profile','comment_upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:5:{s:5:\"value\";s:80:\"sites/default/files/[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;s:7:\"display\";i:0;}');
INSERT INTO `drupal_filefield_paths` VALUES ('team_position','upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:5:{s:5:\"value\";s:80:\"sites/default/files/[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;s:7:\"display\";i:0;}');
INSERT INTO `drupal_filefield_paths` VALUES ('team_position','comment_upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:5:{s:5:\"value\";s:80:\"sites/default/files/[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;s:7:\"display\";i:0;}');
INSERT INTO `drupal_filefield_paths` VALUES ('general_assembly','upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:5:{s:5:\"value\";s:80:\"sites/default/files/[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;s:7:\"display\";i:0;}');
INSERT INTO `drupal_filefield_paths` VALUES ('general_assembly','comment_upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:5:{s:5:\"value\";s:80:\"sites/default/files/[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;s:7:\"display\";i:0;}');
INSERT INTO `drupal_filefield_paths` VALUES ('general_assembly','field_general_assembly_protocol','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:60:\"protocols/[field_general_assembly_number-raw]-walne-zebranie\";s:7:\"tolower\";i:1;s:8:\"pathauto\";i:1;s:13:\"transliterate\";i:1;}','a:5:{s:5:\"value\";s:80:\"sites/default/files/[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;s:7:\"display\";i:0;}');
INSERT INTO `drupal_filefield_paths` VALUES ('simplenews','upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','');
INSERT INTO `drupal_filefield_paths` VALUES ('simplenews','comment_upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','');
INSERT INTO `drupal_filefield_paths` VALUES ('webform','upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:5:{s:5:\"value\";s:80:\"sites/default/files/[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;s:7:\"display\";i:0;}');
INSERT INTO `drupal_filefield_paths` VALUES ('webform','comment_upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:5:{s:5:\"value\";s:80:\"sites/default/files/[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;s:7:\"display\";i:0;}');
INSERT INTO `drupal_filefield_paths` VALUES ('member_application','upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:5:{s:5:\"value\";s:80:\"sites/default/files/[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;s:7:\"display\";i:0;}');
INSERT INTO `drupal_filefield_paths` VALUES ('member_application','comment_upload','a:4:{s:5:\"value\";s:60:\"[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:4:{s:5:\"value\";s:0:\"\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;}','a:5:{s:5:\"value\";s:80:\"sites/default/files/[filefield-onlyname-original].[filefield-extension-original]\";s:7:\"tolower\";i:0;s:8:\"pathauto\";i:0;s:13:\"transliterate\";i:0;s:7:\"display\";i:0;}');
/*!40000 ALTER TABLE `drupal_filefield_paths` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
