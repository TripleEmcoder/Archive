
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
DROP TABLE IF EXISTS `drupal_seo_checklist`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_seo_checklist` (
  `id` tinyint(4) NOT NULL auto_increment,
  `group_id` tinyint(4) NOT NULL default '0',
  `name` varchar(255) NOT NULL default '',
  `module` varchar(255) NOT NULL default '',
  `download` varchar(255) NOT NULL default '',
  `enable` varchar(255) NOT NULL default '',
  `configure` varchar(255) NOT NULL default '',
  `order_id` tinyint(4) NOT NULL default '0',
  `completed` int(10) unsigned NOT NULL default '0',
  `uid` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=57 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_seo_checklist` WRITE;
/*!40000 ALTER TABLE `drupal_seo_checklist` DISABLE KEYS */;
INSERT INTO `drupal_seo_checklist` VALUES (1,1,'Page Title Module','page_title','http://drupal.org/project/page_title','admin/build/modules','admin/content/page_title',2,1265459532,0);
INSERT INTO `drupal_seo_checklist` VALUES (2,2,'Clean URLs - Activate (Usually automatic. Please double-check!)','','','','admin/settings/clean-urls',1,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (5,2,'Pathauto Module','pathauto','http://drupal.org/project/pathauto','admin/build/modules','admin/build/path/pathauto',2,1265459532,0);
INSERT INTO `drupal_seo_checklist` VALUES (6,2,'Global Redirect Module','globalredirect','http://drupal.org/project/globalredirect','admin/build/modules','',3,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (7,3,'Get a Google Account - You\'ll need this for several of the steps that follow - <a href=\'https://www.google.com/accounts/NewAccount\'>https://www.google.com/accounts/NewAccount</a>','','','','',1,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (8,3,'Get a Yahoo Account - You\'ll need this for steps that follow - <a href=\'http://www.yahoo.com/r/m7\'>http://www.yahoo.com/r/m7</a>','','','','',2,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (44,3,'Get a Windows Live ID - You will need this for steps that follow - <a href=\"https://signup.live.com/\">https://signup.live.com/</a>','','','','',2,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (9,4,'Google Analytics Module','googleanalytics','http://drupal.org/project/google_analytics','admin/build/modules','admin/settings/googleanalytics',1,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (10,4,'Sign in to your Google Analytics Account - <a href=\'http://www.google.com/analytics\'>http://www.google.com/analytics</a>','','','','',2,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (11,4,'Create an Analytics for your website','','','','',3,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (12,4,'Paste Google Analytics code into Google Analytics Module','','','','',4,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (13,4,'Authenticate your site with Google Analytics','','','','',5,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (15,5,'Meta Tags Module (AKA Nodewords)','nodewords','http://drupal.org/project/nodewords','admin/build/modules','admin/content/nodewords',2,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (16,5,'Scheduler Module','scheduler','http://drupal.org/project/scheduler','admin/build/modules','admin/settings/scheduler',3,1265459532,0);
INSERT INTO `drupal_seo_checklist` VALUES (17,5,'HTML Purifier Module','htmlpurifier','http://drupal.org/project/htmlpurifier','admin/build/modules','admin/settings/filters/1',4,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (45,5,'<a href=\'/sites/all/modules/htmlpurifier/INSTALL.txt\'>READ THE INSTALL INSTRUCTIONS!</a> then Download HTML Purifier. You will need\n  3.1.0rc1 or later. - <a href=\'http://htmlpurifier.org/\'>http://htmlpurifier.org/</a>','','','','',5,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (18,5,'Search 404 Module','search404','http://drupal.org/project/search404','admin/build/modules','admin/settings/search404',5,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (19,6,'Validate your site - <a href=\'http://validator.w3.org/\'>http://validator.w3.org/</a>','','','','',1,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (20,6,'Check your links - <a href=\'http://validator.w3.org/checklink\'>http://validator.w3.org/checklink</a>','','','','',2,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (21,7,'XML Sitemap Module','xmlsitemap','http://drupal.org/project/xmlsitemap','admin/build/modules','admin/settings/xmlsitemap',1,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (46,7,'Site Map Module - a plain text sitemap','site_map','http://drupal.org/project/site_map','admin/build/modules','admin/settings/sitemap',3,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (22,7,'Login to Google Webmaster Tools - <a href=\'http://www.google.com/webmasters/tools\'>http://www.google.com/webmasters/tools</a>','','','','',5,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (23,7,'Authenticate your site with Google','','','','',7,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (24,7,'Submit your XML Sitemap to Google - <a href=\'http://www.google.com/webmasters/sitemaps/\'>http://www.google.com/webmasters/sitemaps/</a>','','','','',9,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (25,7,'Login to Yahoo Site Explorer Account - <a href=\'https://siteexplorer.search.yahoo.com/\'>https://siteexplorer.search.yahoo.com/</a>','','','','',11,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (26,7,'Authenticate your site with Yahoo','','','','',13,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (27,7,'Submit your XML Sitemap to Yahoo - <a href=\'https://siteexplorer.search.yahoo.com/submit\'>https://siteexplorer.search.yahoo.com/submit</a>','','','','',15,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (43,7,'Authenticate your site with Bing','','','','',19,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (42,7,'Login to Bing - <a href=\"http://www.bing.com/webmaster/\">http://www.bing.com/webmaster/</a>','','','','',17,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (28,7,'Submit your XML Sitemap to Bing - <a href=\"http://www.bing.com/webmaster/WebmasterAddSitesPage.aspx\">http://webmaster.live.com/webmaster/WebmasterAddSitesPage.aspx</a>','','','','',21,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (29,7,'If appropriate, submit your company to Google Local Business Center - <a href=\"https://www.google.com/local/add/login\">https://www.google.com/local/add/login</a>','','','','',23,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (30,8,'Digg This Module','diggthis','http://drupal.org/project/diggthis','admin/build/modules','admin/settings/diggthis',1,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (31,8,'Service Links Module','service_links','http://drupal.org/project/service_links','admin/build/modules','admin/settings/service_links',2,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (32,8,'Trackback Module','trackback','http://drupal.org/project/trackback','admin/build/modules','admin/settings/trackback',3,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (33,9,'Captcha Module','captcha','http://drupal.org/project/captcha','admin/build/modules','admin/user/captcha',2,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (34,9,'Akismet Module','akismet','http://drupal.org/project/akismet','admin/build/modules','admin/settings/akismet',3,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (36,9,'Spam Module','spam','http://drupal.org/project/spam','admin/build/modules','admin/settings/spam',4,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (38,2,'Path Redirect Module','path_redirect','http://drupal.org/project/path_redirect','admin/build/modules','',4,1265459532,0);
INSERT INTO `drupal_seo_checklist` VALUES (39,9,'HIGHLY RECOMMENDED: Mollom Module','mollom','http://drupal.org/project/mollom','admin/build/modules','admin/settings/mollom',1,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (41,1,'Token (required for other modules to function)','token','http://drupal.org/project/token','admin/build/modules','',1,1265459532,0);
INSERT INTO `drupal_seo_checklist` VALUES (40,9,'HIGHLY RECOMMENDED: Sign up for Mollom\'s free service and get Mollom code - <a href=\'http://mollom.com/user/register\'> http://mollom.com/user/register</a>','','','','',0,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (47,7,'Site Verification Module','site_verify','http://drupal.org/project/site_verify','admin/build/modules','',0,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (50,10,'hCard Module','hcard','http://drupal.org/project/hcard','admin/build/modules','',1,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (51,10,'Use the Meta Tags module to add geo meta tags to your site.','','','','',2,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (52,11,'Vertical Tabs Module','vertical_tabs','http://drupal.org/project/vertical_tabs','admin/build/modules','',1,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (53,11,'Administration Menu','admin_menu','http://drupal.org/project/admin_menu','admin/build/modules','',2,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (54,12,'Turn on Drupal\'s built in caching.','','','','admin/settings/performance/default',1,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (55,12,'Boost Module','boost','http://drupal.org/project/boost','admin/build/modules','admin/settings/performance/boost',2,0,0);
INSERT INTO `drupal_seo_checklist` VALUES (56,12,'Authcache Module','authcache','http://drupal.org/project/authcache','admin/build/modules','',3,0,0);
/*!40000 ALTER TABLE `drupal_seo_checklist` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

