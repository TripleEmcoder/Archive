
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
DROP TABLE IF EXISTS `drupal_notifications`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_notifications` (
  `sid` int(10) unsigned NOT NULL auto_increment,
  `uid` int(11) NOT NULL,
  `type` varchar(255) default NULL,
  `event_type` varchar(255) default NULL,
  `conditions` int(10) unsigned NOT NULL,
  `send_interval` int(11) default NULL,
  `send_method` varchar(255) NOT NULL,
  `cron` tinyint(3) unsigned NOT NULL default '0',
  `module` varchar(255) default NULL,
  `status` int(11) NOT NULL default '1',
  `destination` varchar(255) default NULL,
  PRIMARY KEY  (`sid`)
) ENGINE=MyISAM AUTO_INCREMENT=160 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_notifications` WRITE;
/*!40000 ALTER TABLE `drupal_notifications` DISABLE KEYS */;
INSERT INTO `drupal_notifications` VALUES (1,206,'nodetype','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (2,206,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (3,188,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (4,262,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (5,206,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (6,206,'nodetype','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (7,146,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (8,146,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (9,206,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (11,206,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (12,146,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (13,146,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (14,188,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (15,146,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (16,146,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (17,146,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (18,262,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (19,262,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (20,292,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (21,166,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (22,206,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (23,198,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (24,188,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (25,188,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (26,206,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (27,181,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (28,181,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (29,181,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (30,181,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (31,188,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (32,206,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (33,188,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (34,206,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (35,206,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (36,277,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (37,188,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (38,217,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (39,146,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (40,146,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (41,146,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (42,146,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (43,146,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (44,322,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (45,206,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (46,322,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (47,146,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (48,146,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (49,146,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (50,146,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (51,146,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (52,232,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (53,232,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (54,232,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (55,232,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (56,232,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (57,146,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (58,188,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (59,146,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (60,134,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (61,134,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (62,202,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (63,202,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (64,202,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (65,202,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (66,202,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (67,202,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (68,202,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (69,181,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (70,181,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (71,181,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (72,181,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (73,246,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (74,246,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (75,246,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (76,318,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (77,270,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (78,246,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (79,270,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (80,292,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (81,245,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (82,206,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (83,146,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (84,206,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (85,206,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (86,206,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (87,206,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (88,206,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (89,146,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (90,146,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (91,202,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (92,202,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (93,202,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (94,202,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (95,202,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (96,202,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (97,202,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (98,202,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (99,202,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (100,202,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (101,202,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (102,202,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (103,202,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (104,146,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (105,183,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (106,217,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (107,298,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (108,298,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (109,298,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (110,298,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (111,298,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (112,217,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (113,292,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (114,206,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (115,206,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (116,202,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (117,202,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (118,202,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (119,182,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (120,206,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (121,206,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (122,181,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (123,181,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (124,181,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (125,181,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (126,181,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (127,181,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (128,181,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (129,181,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (130,181,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (131,181,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (132,181,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (133,181,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (134,262,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (135,214,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (136,198,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (137,146,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (138,145,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (139,188,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (140,188,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (141,161,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (142,277,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (143,206,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (144,298,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (145,298,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (146,298,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (147,270,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (148,318,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (149,298,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (150,316,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (151,145,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (152,298,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (153,298,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (154,181,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (155,277,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (156,277,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (157,145,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (158,145,'thread','node',1,0,'mimemail',1,'notifications',1,'');
INSERT INTO `drupal_notifications` VALUES (159,277,'thread','node',1,0,'mimemail',1,'notifications',1,'');
/*!40000 ALTER TABLE `drupal_notifications` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

