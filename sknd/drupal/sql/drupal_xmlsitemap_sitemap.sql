
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
DROP TABLE IF EXISTS `drupal_xmlsitemap_sitemap`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_xmlsitemap_sitemap` (
  `smid` int(10) unsigned NOT NULL auto_increment,
  `context_hash` varchar(32) NOT NULL default '',
  `context` text NOT NULL,
  `updated` int(10) unsigned NOT NULL default '0',
  `links` int(10) unsigned NOT NULL default '0',
  `chunks` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`smid`),
  UNIQUE KEY `context_hash` (`context_hash`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_xmlsitemap_sitemap` WRITE;
/*!40000 ALTER TABLE `drupal_xmlsitemap_sitemap` DISABLE KEYS */;
INSERT INTO `drupal_xmlsitemap_sitemap` VALUES (1,'4917f966d56c2ea0f67ec14b1f80cd79','a:1:{s:8:\"language\";s:2:\"pl\";}',1287040806,178,1);
INSERT INTO `drupal_xmlsitemap_sitemap` VALUES (2,'9328df3f6ea742e69c5cbfc15734102f','a:1:{s:8:\"language\";s:2:\"en\";}',1287040806,15,1);
/*!40000 ALTER TABLE `drupal_xmlsitemap_sitemap` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

