
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
DROP TABLE IF EXISTS `drupal_profile_fields`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_profile_fields` (
  `fid` int(11) NOT NULL auto_increment,
  `title` varchar(255) default NULL,
  `name` varchar(128) NOT NULL default '',
  `explanation` text,
  `category` varchar(255) default NULL,
  `page` varchar(255) default NULL,
  `type` varchar(128) default NULL,
  `weight` tinyint(4) NOT NULL default '0',
  `required` tinyint(4) NOT NULL default '0',
  `register` tinyint(4) NOT NULL default '0',
  `visibility` tinyint(4) NOT NULL default '0',
  `autocomplete` tinyint(4) NOT NULL default '0',
  `options` text,
  PRIMARY KEY  (`fid`),
  UNIQUE KEY `name` (`name`),
  KEY `category` (`category`)
) ENGINE=MyISAM AUTO_INCREMENT=14 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_profile_fields` WRITE;
/*!40000 ALTER TABLE `drupal_profile_fields` DISABLE KEYS */;
INSERT INTO `drupal_profile_fields` VALUES (8,'First name','profile_first_name','','Personal information','','textfield',0,1,1,3,0,'');
INSERT INTO `drupal_profile_fields` VALUES (9,'Last name','profile_last_name','','Personal information','','textfield',0,1,1,2,0,'');
INSERT INTO `drupal_profile_fields` VALUES (10,'Smart menus auto-expansion depth','profile_smart_menus_depth','The maximum number of menu levels to which to auto-expand any (sub)menu. Leave blank to accept the default as set by the system administrtor. Use 0 to revert to the static menu behaviour of core.','Smart menus','smart-menus','textfield',0,0,0,1,0,'');
INSERT INTO `drupal_profile_fields` VALUES (11,'Disable Smart menus for tabbed content','profile_smart_menus_tabbed_content','Unless disabled here, your content menus will auto-expand to highlight the menu item belonging to the selected content tab, i.e. Edit, Revisions, Track etc.).','Smart menus','smart-menus','checkbox',0,0,0,1,0,'');
INSERT INTO `drupal_profile_fields` VALUES (12,'Highlight active menu trail','profile_smart_menus_active_trail','Highlight the entire active menu trail, not just the bottom item.','Smart menus','smart-menus','checkbox',0,0,0,1,0,'');
INSERT INTO `drupal_profile_fields` VALUES (13,'Disable Smart tabs','profile_smart_tabs_disable','Unless disabled here, your tabs will have a memory so that upon return to the page the previously selected tabs are again selected for you.','Smart tabs','Smart tabs','checkbox',0,0,0,1,0,'');
/*!40000 ALTER TABLE `drupal_profile_fields` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

