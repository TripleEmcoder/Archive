
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
DROP TABLE IF EXISTS `drupal_webform_submissions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_webform_submissions` (
  `sid` int(10) unsigned NOT NULL auto_increment,
  `nid` int(10) unsigned NOT NULL default '0',
  `uid` int(10) unsigned NOT NULL default '0',
  `submitted` int(11) NOT NULL default '0',
  `remote_addr` varchar(128) default NULL,
  PRIMARY KEY  (`sid`),
  UNIQUE KEY `sid_nid` (`sid`,`nid`)
) ENGINE=MyISAM AUTO_INCREMENT=52 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_webform_submissions` WRITE;
/*!40000 ALTER TABLE `drupal_webform_submissions` DISABLE KEYS */;
INSERT INTO `drupal_webform_submissions` VALUES (2,1718,0,1269214626,'85.221.149.69');
INSERT INTO `drupal_webform_submissions` VALUES (3,1718,0,1269690137,'85.221.149.69');
INSERT INTO `drupal_webform_submissions` VALUES (4,1718,0,1270634514,'217.168.134.162');
INSERT INTO `drupal_webform_submissions` VALUES (5,1718,145,1270674280,'62.21.89.239');
INSERT INTO `drupal_webform_submissions` VALUES (6,1718,0,1270675381,'83.5.94.106');
INSERT INTO `drupal_webform_submissions` VALUES (7,1718,0,1270804065,'79.186.151.5');
INSERT INTO `drupal_webform_submissions` VALUES (8,1718,0,1270804065,'79.186.151.5');
INSERT INTO `drupal_webform_submissions` VALUES (9,1718,0,1270804070,'79.186.151.5');
INSERT INTO `drupal_webform_submissions` VALUES (10,1718,0,1270842437,'79.186.219.31');
INSERT INTO `drupal_webform_submissions` VALUES (11,1718,0,1270913131,'77.65.43.242');
INSERT INTO `drupal_webform_submissions` VALUES (12,1718,0,1271020593,'83.20.238.15');
INSERT INTO `drupal_webform_submissions` VALUES (13,1718,0,1271025937,'77.253.152.133');
INSERT INTO `drupal_webform_submissions` VALUES (14,1718,0,1271154396,'150.254.36.45');
INSERT INTO `drupal_webform_submissions` VALUES (15,1718,0,1271196615,'213.156.117.155');
INSERT INTO `drupal_webform_submissions` VALUES (16,1718,0,1271272341,'79.184.182.56');
INSERT INTO `drupal_webform_submissions` VALUES (17,1718,0,1271331638,'79.173.23.135');
INSERT INTO `drupal_webform_submissions` VALUES (18,1718,0,1271370971,'109.243.224.96');
INSERT INTO `drupal_webform_submissions` VALUES (19,1718,0,1271442385,'83.22.54.107');
INSERT INTO `drupal_webform_submissions` VALUES (20,1718,0,1271507096,'81.210.111.25');
INSERT INTO `drupal_webform_submissions` VALUES (21,1718,0,1271535213,'77.65.98.229');
INSERT INTO `drupal_webform_submissions` VALUES (22,1718,0,1271535287,'85.221.183.228');
INSERT INTO `drupal_webform_submissions` VALUES (23,1718,0,1271536646,'79.184.248.81');
INSERT INTO `drupal_webform_submissions` VALUES (24,1718,0,1271598032,'62.148.83.174');
INSERT INTO `drupal_webform_submissions` VALUES (25,1718,0,1271622570,'77.65.106.4');
INSERT INTO `drupal_webform_submissions` VALUES (26,1718,0,1271623363,'87.99.0.174');
INSERT INTO `drupal_webform_submissions` VALUES (27,1718,0,1271660962,'62.21.42.63');
INSERT INTO `drupal_webform_submissions` VALUES (28,1718,0,1271757780,'150.254.36.45');
INSERT INTO `drupal_webform_submissions` VALUES (29,1718,0,1271768732,'83.20.152.28');
INSERT INTO `drupal_webform_submissions` VALUES (30,1718,0,1271771250,'95.40.255.36');
INSERT INTO `drupal_webform_submissions` VALUES (31,1718,0,1271779168,'62.21.66.32');
INSERT INTO `drupal_webform_submissions` VALUES (32,1718,0,1271780475,'62.21.19.87');
INSERT INTO `drupal_webform_submissions` VALUES (33,1718,0,1271790405,'79.173.0.111');
INSERT INTO `drupal_webform_submissions` VALUES (34,1718,0,1271792786,'77.255.20.86');
INSERT INTO `drupal_webform_submissions` VALUES (35,1718,0,1271798876,'212.67.148.196');
INSERT INTO `drupal_webform_submissions` VALUES (36,1718,0,1271798909,'79.173.17.15');
INSERT INTO `drupal_webform_submissions` VALUES (37,1718,0,1271801895,'95.108.27.80');
INSERT INTO `drupal_webform_submissions` VALUES (38,1718,0,1271862684,'77.65.60.122');
INSERT INTO `drupal_webform_submissions` VALUES (39,1718,0,1271869434,'77.65.39.53');
INSERT INTO `drupal_webform_submissions` VALUES (40,1718,0,1271871548,'193.239.80.25');
INSERT INTO `drupal_webform_submissions` VALUES (41,1718,0,1271874782,'77.65.43.141');
INSERT INTO `drupal_webform_submissions` VALUES (42,1718,0,1271877666,'79.184.33.123');
INSERT INTO `drupal_webform_submissions` VALUES (43,1718,0,1271880482,'62.21.17.183');
INSERT INTO `drupal_webform_submissions` VALUES (44,1718,0,1271883353,'77.255.1.93');
INSERT INTO `drupal_webform_submissions` VALUES (45,1718,0,1271885544,'85.221.163.101');
INSERT INTO `drupal_webform_submissions` VALUES (46,1718,0,1271886256,'83.30.193.96');
INSERT INTO `drupal_webform_submissions` VALUES (47,1718,0,1271886473,'213.156.105.142');
INSERT INTO `drupal_webform_submissions` VALUES (48,1718,0,1271886775,'62.21.12.63');
INSERT INTO `drupal_webform_submissions` VALUES (49,1718,0,1272028939,'62.21.69.114');
INSERT INTO `drupal_webform_submissions` VALUES (50,1718,0,1272273999,'150.254.220.227');
INSERT INTO `drupal_webform_submissions` VALUES (51,1718,0,1272545279,'150.254.36.45');
/*!40000 ALTER TABLE `drupal_webform_submissions` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

