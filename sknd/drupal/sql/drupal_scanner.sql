
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
DROP TABLE IF EXISTS `drupal_scanner`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_scanner` (
  `undo_id` int(11) NOT NULL auto_increment,
  `undo_data` longtext NOT NULL,
  `undone` tinyint(4) NOT NULL,
  `searched` varchar(256) NOT NULL,
  `replaced` varchar(256) NOT NULL,
  `count` int(11) NOT NULL,
  `time` int(11) NOT NULL,
  PRIMARY KEY  (`undo_id`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_scanner` WRITE;
/*!40000 ALTER TABLE `drupal_scanner` DISABLE KEYS */;
INSERT INTO `drupal_scanner` VALUES (1,'a:47:{i:1276;a:2:{s:7:\"old_vid\";s:4:\"1955\";s:7:\"new_vid\";s:4:\"1994\";}i:1284;a:2:{s:7:\"old_vid\";s:4:\"1957\";s:7:\"new_vid\";s:4:\"1995\";}i:1286;a:2:{s:7:\"old_vid\";s:4:\"1958\";s:7:\"new_vid\";s:4:\"1996\";}i:1287;a:2:{s:7:\"old_vid\";s:4:\"1959\";s:7:\"new_vid\";s:4:\"1997\";}i:1291;a:2:{s:7:\"old_vid\";s:4:\"1787\";s:7:\"new_vid\";s:4:\"1998\";}i:1301;a:2:{s:7:\"old_vid\";s:4:\"1793\";s:7:\"new_vid\";s:4:\"1999\";}i:1306;a:2:{s:7:\"old_vid\";s:4:\"1797\";s:7:\"new_vid\";s:4:\"2000\";}i:1307;a:2:{s:7:\"old_vid\";s:4:\"1798\";s:7:\"new_vid\";s:4:\"2001\";}i:1308;a:2:{s:7:\"old_vid\";s:4:\"1799\";s:7:\"new_vid\";s:4:\"2002\";}i:1309;a:2:{s:7:\"old_vid\";s:4:\"1800\";s:7:\"new_vid\";s:4:\"2003\";}i:1311;a:2:{s:7:\"old_vid\";s:4:\"1801\";s:7:\"new_vid\";s:4:\"2004\";}i:1313;a:2:{s:7:\"old_vid\";s:4:\"1803\";s:7:\"new_vid\";s:4:\"2005\";}i:1314;a:2:{s:7:\"old_vid\";s:4:\"1804\";s:7:\"new_vid\";s:4:\"2006\";}i:1315;a:2:{s:7:\"old_vid\";s:4:\"1805\";s:7:\"new_vid\";s:4:\"2007\";}i:1317;a:2:{s:7:\"old_vid\";s:4:\"1807\";s:7:\"new_vid\";s:4:\"2008\";}i:1318;a:2:{s:7:\"old_vid\";s:4:\"1808\";s:7:\"new_vid\";s:4:\"2009\";}i:1320;a:2:{s:7:\"old_vid\";s:4:\"1810\";s:7:\"new_vid\";s:4:\"2010\";}i:1322;a:2:{s:7:\"old_vid\";s:4:\"1811\";s:7:\"new_vid\";s:4:\"2011\";}i:1328;a:2:{s:7:\"old_vid\";s:4:\"1817\";s:7:\"new_vid\";s:4:\"2012\";}i:1329;a:2:{s:7:\"old_vid\";s:4:\"1818\";s:7:\"new_vid\";s:4:\"2013\";}i:1331;a:2:{s:7:\"old_vid\";s:4:\"1819\";s:7:\"new_vid\";s:4:\"2014\";}i:1332;a:2:{s:7:\"old_vid\";s:4:\"1820\";s:7:\"new_vid\";s:4:\"2015\";}i:1334;a:2:{s:7:\"old_vid\";s:4:\"1821\";s:7:\"new_vid\";s:4:\"2016\";}i:1335;a:2:{s:7:\"old_vid\";s:4:\"1822\";s:7:\"new_vid\";s:4:\"2017\";}i:1336;a:2:{s:7:\"old_vid\";s:4:\"1823\";s:7:\"new_vid\";s:4:\"2018\";}i:1337;a:2:{s:7:\"old_vid\";s:4:\"1824\";s:7:\"new_vid\";s:4:\"2019\";}i:1338;a:2:{s:7:\"old_vid\";s:4:\"1942\";s:7:\"new_vid\";s:4:\"2020\";}i:1339;a:2:{s:7:\"old_vid\";s:4:\"1826\";s:7:\"new_vid\";s:4:\"2021\";}i:1340;a:2:{s:7:\"old_vid\";s:4:\"1827\";s:7:\"new_vid\";s:4:\"2022\";}i:1341;a:2:{s:7:\"old_vid\";s:4:\"1828\";s:7:\"new_vid\";s:4:\"2023\";}i:1345;a:2:{s:7:\"old_vid\";s:4:\"1831\";s:7:\"new_vid\";s:4:\"2024\";}i:1352;a:2:{s:7:\"old_vid\";s:4:\"1889\";s:7:\"new_vid\";s:4:\"2025\";}i:1359;a:2:{s:7:\"old_vid\";s:4:\"1845\";s:7:\"new_vid\";s:4:\"2026\";}i:1368;a:2:{s:7:\"old_vid\";s:4:\"1964\";s:7:\"new_vid\";s:4:\"2027\";}i:1370;a:2:{s:7:\"old_vid\";s:4:\"1965\";s:7:\"new_vid\";s:4:\"2028\";}i:1372;a:2:{s:7:\"old_vid\";s:4:\"1857\";s:7:\"new_vid\";s:4:\"2029\";}i:1477;a:2:{s:7:\"old_vid\";s:4:\"1873\";s:7:\"new_vid\";s:4:\"2030\";}i:1546;a:2:{s:7:\"old_vid\";s:4:\"1990\";s:7:\"new_vid\";s:4:\"2032\";}i:1545;a:2:{s:7:\"old_vid\";s:4:\"1989\";s:7:\"new_vid\";s:4:\"2033\";}i:1544;a:2:{s:7:\"old_vid\";s:4:\"1991\";s:7:\"new_vid\";s:4:\"2034\";}i:1542;a:2:{s:7:\"old_vid\";s:4:\"1984\";s:7:\"new_vid\";s:4:\"2035\";}i:1543;a:2:{s:7:\"old_vid\";s:4:\"1987\";s:7:\"new_vid\";s:4:\"2036\";}i:1488;a:2:{s:7:\"old_vid\";s:4:\"1972\";s:7:\"new_vid\";s:4:\"2037\";}i:1491;a:2:{s:7:\"old_vid\";s:4:\"1974\";s:7:\"new_vid\";s:4:\"2038\";}i:1479;a:2:{s:7:\"old_vid\";s:4:\"1993\";s:7:\"new_vid\";s:4:\"2039\";}i:1481;a:2:{s:7:\"old_vid\";s:4:\"1866\";s:7:\"new_vid\";s:4:\"2040\";}i:1484;a:2:{s:7:\"old_vid\";s:4:\"1992\";s:7:\"new_vid\";s:4:\"2041\";}}',0,'SKND','Cognitis',47,1255282932);
INSERT INTO `drupal_scanner` VALUES (2,'a:2:{i:1546;a:2:{s:7:\"old_vid\";s:4:\"2080\";s:7:\"new_vid\";s:4:\"2096\";}i:1545;a:2:{s:7:\"old_vid\";s:4:\"2081\";s:7:\"new_vid\";s:4:\"2097\";}}',0,'emph','em',2,1255342514);
/*!40000 ALTER TABLE `drupal_scanner` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

