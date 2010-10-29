
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
DROP TABLE IF EXISTS `drupal_simplenews_statistics_opens`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_simplenews_statistics_opens` (
  `email` varchar(255) NOT NULL default '0',
  `nid` int(11) NOT NULL default '0',
  `opens` int(10) unsigned NOT NULL default '0',
  `timestamp` int(10) unsigned NOT NULL default '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_simplenews_statistics_opens` WRITE;
/*!40000 ALTER TABLE `drupal_simplenews_statistics_opens` DISABLE KEYS */;
INSERT INTO `drupal_simplenews_statistics_opens` VALUES ('p.siedlarek@onet.eu',1720,1,1269301774);
INSERT INTO `drupal_simplenews_statistics_opens` VALUES ('micha67@wp.pl',1720,1,1269349095);
INSERT INTO `drupal_simplenews_statistics_opens` VALUES ('lufcik5@wp.pl',1720,1,1269359498);
INSERT INTO `drupal_simplenews_statistics_opens` VALUES ('lucy182@o2.pl',1720,1,1269381510);
INSERT INTO `drupal_simplenews_statistics_opens` VALUES ('meggie115@wp.pl',1720,1,1269459139);
INSERT INTO `drupal_simplenews_statistics_opens` VALUES ('meg_1@wp.pl',1720,1,1269463510);
INSERT INTO `drupal_simplenews_statistics_opens` VALUES ('oladett@wp.pl',1741,2,1271271710);
INSERT INTO `drupal_simplenews_statistics_opens` VALUES ('07gosienka@wp.pl',1741,1,1271620204);
/*!40000 ALTER TABLE `drupal_simplenews_statistics_opens` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

