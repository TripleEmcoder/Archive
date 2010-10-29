
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
DROP TABLE IF EXISTS `drupal_seo_group`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_seo_group` (
  `id` tinyint(4) NOT NULL auto_increment,
  `name` varchar(255) NOT NULL default '',
  `description` varchar(255) NOT NULL default '',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=13 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_seo_group` WRITE;
/*!40000 ALTER TABLE `drupal_seo_group` DISABLE KEYS */;
INSERT INTO `drupal_seo_group` VALUES (1,'Page Titles','The single most important thing you can do for on-site SEO.');
INSERT INTO `drupal_seo_group` VALUES (2,'URL paths','The second most important thing you can do.');
INSERT INTO `drupal_seo_group` VALUES (3,'Create Search Engine Accounts','Set yourself up with the search engines.');
INSERT INTO `drupal_seo_group` VALUES (4,'Track your visitors','Know where your visitors are coming from and what they do while visiting your site.');
INSERT INTO `drupal_seo_group` VALUES (5,'Page content','Take control of your page content.');
INSERT INTO `drupal_seo_group` VALUES (6,'Clean code','Well written markup is very important to the search engine spiders.');
INSERT INTO `drupal_seo_group` VALUES (7,'Submit your Site to the search engines.','Now that you\'ve got your site ready for the search engines, tell them about it!');
INSERT INTO `drupal_seo_group` VALUES (8,'Social Media','Using Social news sites, blogs, etc? Consider these:');
INSERT INTO `drupal_seo_group` VALUES (9,'Protect your site from Spam','If your site will get heavy use from visitors creating accounts, commenting and/or creating content then consider these. NOTE: Most sites just need Mollom. The other modules are here in case Mollom does not work for you for some reason.');
INSERT INTO `drupal_seo_group` VALUES (10,'Geographic','');
INSERT INTO `drupal_seo_group` VALUES (11,'Optional (but helpful)','');
INSERT INTO `drupal_seo_group` VALUES (12,'Performance','');
/*!40000 ALTER TABLE `drupal_seo_group` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

