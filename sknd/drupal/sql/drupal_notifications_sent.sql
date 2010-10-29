
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
DROP TABLE IF EXISTS `drupal_notifications_sent`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_notifications_sent` (
  `uid` int(11) NOT NULL default '0',
  `send_interval` int(11) NOT NULL default '0',
  `send_method` varchar(50) NOT NULL,
  `sent` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`uid`,`send_interval`,`send_method`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_notifications_sent` WRITE;
/*!40000 ALTER TABLE `drupal_notifications_sent` DISABLE KEYS */;
INSERT INTO `drupal_notifications_sent` VALUES (206,0,'mimemail',1287040845);
INSERT INTO `drupal_notifications_sent` VALUES (188,0,'mimemail',1275737431);
INSERT INTO `drupal_notifications_sent` VALUES (262,0,'mimemail',1269803406);
INSERT INTO `drupal_notifications_sent` VALUES (146,0,'mimemail',1287040844);
INSERT INTO `drupal_notifications_sent` VALUES (198,0,'mimemail',1271260562);
INSERT INTO `drupal_notifications_sent` VALUES (181,0,'mimemail',1275257407);
INSERT INTO `drupal_notifications_sent` VALUES (166,0,'mimemail',1269803405);
INSERT INTO `drupal_notifications_sent` VALUES (202,0,'mimemail',1275257407);
INSERT INTO `drupal_notifications_sent` VALUES (246,0,'mimemail',1272573018);
INSERT INTO `drupal_notifications_sent` VALUES (270,0,'mimemail',1282256417);
INSERT INTO `drupal_notifications_sent` VALUES (292,0,'mimemail',1275079816);
INSERT INTO `drupal_notifications_sent` VALUES (245,0,'mimemail',1272530409);
INSERT INTO `drupal_notifications_sent` VALUES (183,0,'mimemail',1275079816);
INSERT INTO `drupal_notifications_sent` VALUES (298,0,'mimemail',1282256417);
INSERT INTO `drupal_notifications_sent` VALUES (217,0,'mimemail',1275079816);
INSERT INTO `drupal_notifications_sent` VALUES (182,0,'mimemail',1275049216);
INSERT INTO `drupal_notifications_sent` VALUES (161,0,'mimemail',1276024292);
INSERT INTO `drupal_notifications_sent` VALUES (318,0,'mimemail',1282256417);
INSERT INTO `drupal_notifications_sent` VALUES (145,0,'mimemail',1281639650);
/*!40000 ALTER TABLE `drupal_notifications_sent` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

