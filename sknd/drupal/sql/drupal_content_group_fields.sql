
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
DROP TABLE IF EXISTS `drupal_content_group_fields`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_content_group_fields` (
  `type_name` varchar(32) NOT NULL default '',
  `group_name` varchar(32) NOT NULL default '',
  `field_name` varchar(32) NOT NULL default '',
  PRIMARY KEY  (`type_name`,`group_name`,`field_name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_content_group_fields` WRITE;
/*!40000 ALTER TABLE `drupal_content_group_fields` DISABLE KEYS */;
INSERT INTO `drupal_content_group_fields` VALUES ('application_candidate','group_candidate_language_skills','field_candidate_lang_other_name');
INSERT INTO `drupal_content_group_fields` VALUES ('application_candidate','group_candidate_language_skills','field_candidate_lang_other_skill');
INSERT INTO `drupal_content_group_fields` VALUES ('application_candidate','group_candidate_language_skills','field_candidate_lang_skill_de');
INSERT INTO `drupal_content_group_fields` VALUES ('application_candidate','group_candidate_language_skills','field_candidate_lang_skill_en');
INSERT INTO `drupal_content_group_fields` VALUES ('application_candidate','group_candidate_language_skills','field_candidate_lang_skill_es');
INSERT INTO `drupal_content_group_fields` VALUES ('application_candidate','group_candidate_language_skills','field_candidate_lang_skill_fr');
INSERT INTO `drupal_content_group_fields` VALUES ('application_candidate','group_candidate_language_skills','field_candidate_lang_skill_ru');
INSERT INTO `drupal_content_group_fields` VALUES ('application_candidate','group_candidate_personal_info','field_candidate_birth_date');
INSERT INTO `drupal_content_group_fields` VALUES ('application_candidate','group_candidate_personal_info','field_candidate_email_address');
INSERT INTO `drupal_content_group_fields` VALUES ('application_candidate','group_candidate_personal_info','field_candidate_first_name');
INSERT INTO `drupal_content_group_fields` VALUES ('application_candidate','group_candidate_personal_info','field_candidate_last_name');
INSERT INTO `drupal_content_group_fields` VALUES ('application_candidate','group_candidate_personal_info','field_candidate_phone_number');
INSERT INTO `drupal_content_group_fields` VALUES ('general_assembly','group_discharges','field_gnrl_assmbl_tm_dschrgs');
INSERT INTO `drupal_content_group_fields` VALUES ('general_assembly','group_elections','field_gnrl_assmbl_stts_elctns');
INSERT INTO `drupal_content_group_fields` VALUES ('general_assembly','group_elections','field_gnrl_assmbl_tm_elctns');
INSERT INTO `drupal_content_group_fields` VALUES ('member_application','group_nomination','field_nmntn_general_assembly');
INSERT INTO `drupal_content_group_fields` VALUES ('member_application','group_nomination','field_nomination_status');
INSERT INTO `drupal_content_group_fields` VALUES ('team_position','group_discharge','field_discharge_general_assembly');
INSERT INTO `drupal_content_group_fields` VALUES ('team_position','group_discharge','field_discharge_status');
INSERT INTO `drupal_content_group_fields` VALUES ('team_position','group_election','field_election_general_assembly');
INSERT INTO `drupal_content_group_fields` VALUES ('team_position','group_election','field_election_status');
INSERT INTO `drupal_content_group_fields` VALUES ('team_position','group_person','field_position_user');
INSERT INTO `drupal_content_group_fields` VALUES ('team_position','group_position','field_team_position_function');
INSERT INTO `drupal_content_group_fields` VALUES ('team_position','group_position','field_team_team');
INSERT INTO `drupal_content_group_fields` VALUES ('team_position','group_position','field_team_term');
/*!40000 ALTER TABLE `drupal_content_group_fields` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

