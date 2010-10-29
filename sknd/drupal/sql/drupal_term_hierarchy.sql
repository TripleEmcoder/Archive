
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
DROP TABLE IF EXISTS `drupal_term_hierarchy`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_term_hierarchy` (
  `tid` int(10) unsigned NOT NULL default '0',
  `parent` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`tid`,`parent`),
  KEY `parent` (`parent`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_term_hierarchy` WRITE;
/*!40000 ALTER TABLE `drupal_term_hierarchy` DISABLE KEYS */;
INSERT INTO `drupal_term_hierarchy` VALUES (1,0);
INSERT INTO `drupal_term_hierarchy` VALUES (2,0);
INSERT INTO `drupal_term_hierarchy` VALUES (5,0);
INSERT INTO `drupal_term_hierarchy` VALUES (41,71);
INSERT INTO `drupal_term_hierarchy` VALUES (42,71);
INSERT INTO `drupal_term_hierarchy` VALUES (43,71);
INSERT INTO `drupal_term_hierarchy` VALUES (44,71);
INSERT INTO `drupal_term_hierarchy` VALUES (45,71);
INSERT INTO `drupal_term_hierarchy` VALUES (47,71);
INSERT INTO `drupal_term_hierarchy` VALUES (48,71);
INSERT INTO `drupal_term_hierarchy` VALUES (49,71);
INSERT INTO `drupal_term_hierarchy` VALUES (50,71);
INSERT INTO `drupal_term_hierarchy` VALUES (51,71);
INSERT INTO `drupal_term_hierarchy` VALUES (52,71);
INSERT INTO `drupal_term_hierarchy` VALUES (53,71);
INSERT INTO `drupal_term_hierarchy` VALUES (54,71);
INSERT INTO `drupal_term_hierarchy` VALUES (55,71);
INSERT INTO `drupal_term_hierarchy` VALUES (56,71);
INSERT INTO `drupal_term_hierarchy` VALUES (57,71);
INSERT INTO `drupal_term_hierarchy` VALUES (58,71);
INSERT INTO `drupal_term_hierarchy` VALUES (59,71);
INSERT INTO `drupal_term_hierarchy` VALUES (60,71);
INSERT INTO `drupal_term_hierarchy` VALUES (62,71);
INSERT INTO `drupal_term_hierarchy` VALUES (63,71);
INSERT INTO `drupal_term_hierarchy` VALUES (64,71);
INSERT INTO `drupal_term_hierarchy` VALUES (65,71);
INSERT INTO `drupal_term_hierarchy` VALUES (66,71);
INSERT INTO `drupal_term_hierarchy` VALUES (67,71);
INSERT INTO `drupal_term_hierarchy` VALUES (68,71);
INSERT INTO `drupal_term_hierarchy` VALUES (69,71);
INSERT INTO `drupal_term_hierarchy` VALUES (70,71);
INSERT INTO `drupal_term_hierarchy` VALUES (71,0);
INSERT INTO `drupal_term_hierarchy` VALUES (72,71);
INSERT INTO `drupal_term_hierarchy` VALUES (73,71);
INSERT INTO `drupal_term_hierarchy` VALUES (76,182);
INSERT INTO `drupal_term_hierarchy` VALUES (77,182);
INSERT INTO `drupal_term_hierarchy` VALUES (78,183);
INSERT INTO `drupal_term_hierarchy` VALUES (82,0);
INSERT INTO `drupal_term_hierarchy` VALUES (83,0);
INSERT INTO `drupal_term_hierarchy` VALUES (84,0);
INSERT INTO `drupal_term_hierarchy` VALUES (85,0);
INSERT INTO `drupal_term_hierarchy` VALUES (86,85);
INSERT INTO `drupal_term_hierarchy` VALUES (87,85);
INSERT INTO `drupal_term_hierarchy` VALUES (88,85);
INSERT INTO `drupal_term_hierarchy` VALUES (89,85);
INSERT INTO `drupal_term_hierarchy` VALUES (90,0);
INSERT INTO `drupal_term_hierarchy` VALUES (91,0);
INSERT INTO `drupal_term_hierarchy` VALUES (92,87);
INSERT INTO `drupal_term_hierarchy` VALUES (93,87);
INSERT INTO `drupal_term_hierarchy` VALUES (94,87);
INSERT INTO `drupal_term_hierarchy` VALUES (95,87);
INSERT INTO `drupal_term_hierarchy` VALUES (96,87);
INSERT INTO `drupal_term_hierarchy` VALUES (97,86);
INSERT INTO `drupal_term_hierarchy` VALUES (98,86);
INSERT INTO `drupal_term_hierarchy` VALUES (99,86);
INSERT INTO `drupal_term_hierarchy` VALUES (100,86);
INSERT INTO `drupal_term_hierarchy` VALUES (101,86);
INSERT INTO `drupal_term_hierarchy` VALUES (102,86);
INSERT INTO `drupal_term_hierarchy` VALUES (103,88);
INSERT INTO `drupal_term_hierarchy` VALUES (104,88);
INSERT INTO `drupal_term_hierarchy` VALUES (105,88);
INSERT INTO `drupal_term_hierarchy` VALUES (106,88);
INSERT INTO `drupal_term_hierarchy` VALUES (107,88);
INSERT INTO `drupal_term_hierarchy` VALUES (108,89);
INSERT INTO `drupal_term_hierarchy` VALUES (109,89);
INSERT INTO `drupal_term_hierarchy` VALUES (110,89);
INSERT INTO `drupal_term_hierarchy` VALUES (111,89);
INSERT INTO `drupal_term_hierarchy` VALUES (112,89);
INSERT INTO `drupal_term_hierarchy` VALUES (113,85);
INSERT INTO `drupal_term_hierarchy` VALUES (114,113);
INSERT INTO `drupal_term_hierarchy` VALUES (115,113);
INSERT INTO `drupal_term_hierarchy` VALUES (116,113);
INSERT INTO `drupal_term_hierarchy` VALUES (117,113);
INSERT INTO `drupal_term_hierarchy` VALUES (118,134);
INSERT INTO `drupal_term_hierarchy` VALUES (119,118);
INSERT INTO `drupal_term_hierarchy` VALUES (119,136);
INSERT INTO `drupal_term_hierarchy` VALUES (120,118);
INSERT INTO `drupal_term_hierarchy` VALUES (120,136);
INSERT INTO `drupal_term_hierarchy` VALUES (121,158);
INSERT INTO `drupal_term_hierarchy` VALUES (122,158);
INSERT INTO `drupal_term_hierarchy` VALUES (123,0);
INSERT INTO `drupal_term_hierarchy` VALUES (124,0);
INSERT INTO `drupal_term_hierarchy` VALUES (125,0);
INSERT INTO `drupal_term_hierarchy` VALUES (126,0);
INSERT INTO `drupal_term_hierarchy` VALUES (127,0);
INSERT INTO `drupal_term_hierarchy` VALUES (128,0);
INSERT INTO `drupal_term_hierarchy` VALUES (129,158);
INSERT INTO `drupal_term_hierarchy` VALUES (131,134);
INSERT INTO `drupal_term_hierarchy` VALUES (132,71);
INSERT INTO `drupal_term_hierarchy` VALUES (133,118);
INSERT INTO `drupal_term_hierarchy` VALUES (133,136);
INSERT INTO `drupal_term_hierarchy` VALUES (134,0);
INSERT INTO `drupal_term_hierarchy` VALUES (135,0);
INSERT INTO `drupal_term_hierarchy` VALUES (136,135);
INSERT INTO `drupal_term_hierarchy` VALUES (137,134);
INSERT INTO `drupal_term_hierarchy` VALUES (138,135);
INSERT INTO `drupal_term_hierarchy` VALUES (139,137);
INSERT INTO `drupal_term_hierarchy` VALUES (139,138);
INSERT INTO `drupal_term_hierarchy` VALUES (140,137);
INSERT INTO `drupal_term_hierarchy` VALUES (140,138);
INSERT INTO `drupal_term_hierarchy` VALUES (141,137);
INSERT INTO `drupal_term_hierarchy` VALUES (141,138);
INSERT INTO `drupal_term_hierarchy` VALUES (142,155);
INSERT INTO `drupal_term_hierarchy` VALUES (143,155);
INSERT INTO `drupal_term_hierarchy` VALUES (144,155);
INSERT INTO `drupal_term_hierarchy` VALUES (145,155);
INSERT INTO `drupal_term_hierarchy` VALUES (146,155);
INSERT INTO `drupal_term_hierarchy` VALUES (147,155);
INSERT INTO `drupal_term_hierarchy` VALUES (148,155);
INSERT INTO `drupal_term_hierarchy` VALUES (149,155);
INSERT INTO `drupal_term_hierarchy` VALUES (150,155);
INSERT INTO `drupal_term_hierarchy` VALUES (151,155);
INSERT INTO `drupal_term_hierarchy` VALUES (152,155);
INSERT INTO `drupal_term_hierarchy` VALUES (153,155);
INSERT INTO `drupal_term_hierarchy` VALUES (154,71);
INSERT INTO `drupal_term_hierarchy` VALUES (155,0);
INSERT INTO `drupal_term_hierarchy` VALUES (156,0);
INSERT INTO `drupal_term_hierarchy` VALUES (157,0);
INSERT INTO `drupal_term_hierarchy` VALUES (158,0);
INSERT INTO `drupal_term_hierarchy` VALUES (159,0);
INSERT INTO `drupal_term_hierarchy` VALUES (160,0);
INSERT INTO `drupal_term_hierarchy` VALUES (161,157);
INSERT INTO `drupal_term_hierarchy` VALUES (163,157);
INSERT INTO `drupal_term_hierarchy` VALUES (164,169);
INSERT INTO `drupal_term_hierarchy` VALUES (165,169);
INSERT INTO `drupal_term_hierarchy` VALUES (166,169);
INSERT INTO `drupal_term_hierarchy` VALUES (167,169);
INSERT INTO `drupal_term_hierarchy` VALUES (168,169);
INSERT INTO `drupal_term_hierarchy` VALUES (169,0);
INSERT INTO `drupal_term_hierarchy` VALUES (170,0);
INSERT INTO `drupal_term_hierarchy` VALUES (171,0);
INSERT INTO `drupal_term_hierarchy` VALUES (172,0);
INSERT INTO `drupal_term_hierarchy` VALUES (173,171);
INSERT INTO `drupal_term_hierarchy` VALUES (174,171);
INSERT INTO `drupal_term_hierarchy` VALUES (175,171);
INSERT INTO `drupal_term_hierarchy` VALUES (176,171);
INSERT INTO `drupal_term_hierarchy` VALUES (177,171);
INSERT INTO `drupal_term_hierarchy` VALUES (178,0);
INSERT INTO `drupal_term_hierarchy` VALUES (179,0);
INSERT INTO `drupal_term_hierarchy` VALUES (180,0);
INSERT INTO `drupal_term_hierarchy` VALUES (181,182);
INSERT INTO `drupal_term_hierarchy` VALUES (182,0);
INSERT INTO `drupal_term_hierarchy` VALUES (183,0);
INSERT INTO `drupal_term_hierarchy` VALUES (184,182);
INSERT INTO `drupal_term_hierarchy` VALUES (185,0);
INSERT INTO `drupal_term_hierarchy` VALUES (186,185);
INSERT INTO `drupal_term_hierarchy` VALUES (187,0);
INSERT INTO `drupal_term_hierarchy` VALUES (188,187);
INSERT INTO `drupal_term_hierarchy` VALUES (189,187);
INSERT INTO `drupal_term_hierarchy` VALUES (190,187);
INSERT INTO `drupal_term_hierarchy` VALUES (191,0);
INSERT INTO `drupal_term_hierarchy` VALUES (192,191);
INSERT INTO `drupal_term_hierarchy` VALUES (193,191);
INSERT INTO `drupal_term_hierarchy` VALUES (194,191);
INSERT INTO `drupal_term_hierarchy` VALUES (195,0);
INSERT INTO `drupal_term_hierarchy` VALUES (196,195);
INSERT INTO `drupal_term_hierarchy` VALUES (197,195);
INSERT INTO `drupal_term_hierarchy` VALUES (198,0);
INSERT INTO `drupal_term_hierarchy` VALUES (199,198);
INSERT INTO `drupal_term_hierarchy` VALUES (200,198);
INSERT INTO `drupal_term_hierarchy` VALUES (201,0);
INSERT INTO `drupal_term_hierarchy` VALUES (202,201);
INSERT INTO `drupal_term_hierarchy` VALUES (203,201);
INSERT INTO `drupal_term_hierarchy` VALUES (204,201);
INSERT INTO `drupal_term_hierarchy` VALUES (205,0);
INSERT INTO `drupal_term_hierarchy` VALUES (206,0);
INSERT INTO `drupal_term_hierarchy` VALUES (207,0);
INSERT INTO `drupal_term_hierarchy` VALUES (208,0);
INSERT INTO `drupal_term_hierarchy` VALUES (216,222);
INSERT INTO `drupal_term_hierarchy` VALUES (217,222);
INSERT INTO `drupal_term_hierarchy` VALUES (218,222);
INSERT INTO `drupal_term_hierarchy` VALUES (219,222);
INSERT INTO `drupal_term_hierarchy` VALUES (220,222);
INSERT INTO `drupal_term_hierarchy` VALUES (221,222);
INSERT INTO `drupal_term_hierarchy` VALUES (222,0);
/*!40000 ALTER TABLE `drupal_term_hierarchy` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

