
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
DROP TABLE IF EXISTS `drupal_blocks`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_blocks` (
  `bid` int(11) NOT NULL auto_increment,
  `module` varchar(64) NOT NULL default '',
  `delta` varchar(32) NOT NULL default '0',
  `theme` varchar(64) NOT NULL default '',
  `status` tinyint(4) NOT NULL default '0',
  `weight` tinyint(4) NOT NULL default '0',
  `region` varchar(64) NOT NULL default '',
  `custom` tinyint(4) NOT NULL default '0',
  `throttle` tinyint(4) NOT NULL default '0',
  `visibility` tinyint(4) NOT NULL default '0',
  `pages` text NOT NULL,
  `title` varchar(64) NOT NULL default '',
  `cache` tinyint(4) NOT NULL default '1',
  PRIMARY KEY  (`bid`),
  UNIQUE KEY `tmd` (`theme`,`module`,`delta`),
  KEY `list` (`theme`,`status`,`region`,`weight`,`module`)
) ENGINE=MyISAM AUTO_INCREMENT=171 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_blocks` WRITE;
/*!40000 ALTER TABLE `drupal_blocks` DISABLE KEYS */;
INSERT INTO `drupal_blocks` VALUES (1,'user','0','garland',1,-19,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (2,'user','1','garland',1,-18,'left',0,0,0,'','<none>',-1);
INSERT INTO `drupal_blocks` VALUES (3,'system','0','garland',0,-15,'',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (4,'comment','0','garland',0,-12,'',0,0,1,'forum\r\nforum/*','',1);
INSERT INTO `drupal_blocks` VALUES (5,'locale','0','garland',1,-16,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (6,'menu','primary-links','garland',0,-10,'',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (7,'menu','secondary-links','garland',0,4,'',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (8,'node','0','garland',0,6,'',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (9,'poll','0','garland',0,-12,'',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (10,'profile','0','garland',0,-14,'',0,0,0,'','',5);
INSERT INTO `drupal_blocks` VALUES (11,'user','2','garland',0,7,'',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (12,'user','3','garland',1,-18,'right',1,0,0,'<front>','<none>',-1);
INSERT INTO `drupal_blocks` VALUES (13,'i18npoll','0','garland',0,-11,'',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (14,'menu','devel','garland',1,-15,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (15,'privatemsg','privatemsg-menu','garland',0,-9,'',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (16,'forum','0','garland',0,-19,'',0,0,1,'forum\r\nforum/*','',1);
INSERT INTO `drupal_blocks` VALUES (17,'forum','1','garland',0,-18,'',0,0,1,'forum\r\nforum/*','',1);
INSERT INTO `drupal_blocks` VALUES (168,'menu_block','2','garland',0,-2,'',0,0,0,'','<none>',-1);
INSERT INTO `drupal_blocks` VALUES (22,'devel','0','garland',0,5,'',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (23,'devel','2','garland',0,-13,'',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (24,'devel_node_access','0','garland',0,-17,'',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (25,'devel_node_access','1','garland',0,-16,'',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (26,'shoutbox','0','garland',1,-19,'right',1,0,0,'<front>','',1);
INSERT INTO `drupal_blocks` VALUES (27,'masquerade','0','garland',1,-19,'right',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (28,'views','active_users-block_1','garland',1,-17,'right',1,0,0,'<front>','',-1);
INSERT INTO `drupal_blocks` VALUES (29,'statistics','0','garland',0,-7,'',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (30,'author_pane','0','garland',0,-8,'',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (31,'search','0','garland',1,-17,'left',0,0,0,'<front>','',-1);
INSERT INTO `drupal_blocks` VALUES (166,'menu_block','2','zen',0,0,'',0,0,0,'','<none>',-1);
INSERT INTO `drupal_blocks` VALUES (33,'simplenews','91','garland',0,0,'',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (34,'user','0','chameleon',1,-14,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (35,'user','1','chameleon',1,-13,'left',0,0,0,'','<none>',-1);
INSERT INTO `drupal_blocks` VALUES (36,'system','0','chameleon',0,-15,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (37,'comment','0','chameleon',0,-4,'left',0,0,1,'forum\r\nforum/*','',1);
INSERT INTO `drupal_blocks` VALUES (38,'locale','0','chameleon',1,-9,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (39,'menu','primary-links','chameleon',0,-6,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (40,'menu','secondary-links','chameleon',0,0,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (41,'node','0','chameleon',0,3,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (42,'poll','0','chameleon',0,-10,'left',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (43,'profile','0','chameleon',0,-12,'left',0,0,0,'','',5);
INSERT INTO `drupal_blocks` VALUES (44,'user','2','chameleon',0,5,'left',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (45,'user','3','chameleon',1,-11,'left',1,0,0,'<front>','<none>',-1);
INSERT INTO `drupal_blocks` VALUES (46,'i18npoll','0','chameleon',0,-9,'left',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (47,'menu','devel','chameleon',1,-8,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (48,'privatemsg','privatemsg-menu','chameleon',0,-5,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (49,'forum','0','chameleon',0,-14,'left',0,0,1,'forum\r\nforum/*','',1);
INSERT INTO `drupal_blocks` VALUES (50,'forum','1','chameleon',0,-8,'left',0,0,1,'forum\r\nforum/*','',1);
INSERT INTO `drupal_blocks` VALUES (51,'views','comments_recent-block','chameleon',0,-3,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (52,'views','archive-block','chameleon',0,-13,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (53,'views','popular-block','chameleon',0,-7,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (54,'views','popular-block_1','chameleon',0,4,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (55,'devel','0','chameleon',0,2,'left',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (56,'devel','2','chameleon',0,-11,'left',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (57,'devel_node_access','0','chameleon',0,-16,'left',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (58,'devel_node_access','1','chameleon',0,-15,'left',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (59,'shoutbox','0','chameleon',1,-14,'right',1,0,0,'<front>','',1);
INSERT INTO `drupal_blocks` VALUES (60,'masquerade','0','chameleon',1,-16,'right',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (61,'views','active_users-block_1','chameleon',1,-10,'left',1,0,0,'<front>','',-1);
INSERT INTO `drupal_blocks` VALUES (62,'statistics','0','chameleon',0,-1,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (63,'author_pane','0','chameleon',0,-2,'left',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (64,'search','0','chameleon',1,-15,'right',0,0,0,'<front>','',-1);
INSERT INTO `drupal_blocks` VALUES (65,'views','backlinks-block','chameleon',0,1,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (66,'simplenews','91','chameleon',0,0,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (67,'author_pane','0','zen',0,-2,'left',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (68,'comment','0','zen',0,-4,'left',0,0,1,'forum\r\nforum/*','',1);
INSERT INTO `drupal_blocks` VALUES (69,'devel','0','zen',0,2,'left',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (70,'devel','2','zen',0,-11,'left',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (71,'devel_node_access','0','zen',0,-16,'left',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (72,'devel_node_access','1','zen',0,-15,'left',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (73,'forum','0','zen',0,-14,'left',0,0,1,'forum\r\nforum/*','',1);
INSERT INTO `drupal_blocks` VALUES (74,'forum','1','zen',0,-8,'left',0,0,1,'forum\r\nforum/*','',1);
INSERT INTO `drupal_blocks` VALUES (75,'i18npoll','0','zen',0,-9,'left',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (76,'locale','0','zen',1,-9,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (77,'masquerade','0','zen',1,-16,'right',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (78,'menu','devel','zen',1,-8,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (79,'menu','primary-links','zen',0,-6,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (80,'menu','secondary-links','zen',0,0,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (81,'node','0','zen',0,3,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (82,'poll','0','zen',0,-10,'left',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (83,'privatemsg','privatemsg-menu','zen',0,-5,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (84,'profile','0','zen',0,-12,'left',0,0,0,'','',5);
INSERT INTO `drupal_blocks` VALUES (85,'search','0','zen',1,-15,'right',0,0,0,'<front>','',-1);
INSERT INTO `drupal_blocks` VALUES (86,'shoutbox','0','zen',1,-14,'right',1,0,0,'<front>','',1);
INSERT INTO `drupal_blocks` VALUES (87,'simplenews','91','zen',0,0,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (88,'statistics','0','zen',0,-1,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (89,'system','0','zen',0,-15,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (90,'user','0','zen',1,-14,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (91,'user','1','zen',1,-13,'left',0,0,0,'','<none>',-1);
INSERT INTO `drupal_blocks` VALUES (92,'user','2','zen',0,5,'left',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (93,'user','3','zen',1,-11,'left',1,0,0,'<front>','<none>',-1);
INSERT INTO `drupal_blocks` VALUES (94,'views','active_users-block_1','zen',1,-10,'left',1,0,0,'<front>','',-1);
INSERT INTO `drupal_blocks` VALUES (95,'views','archive-block','zen',0,-13,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (96,'views','backlinks-block','zen',0,1,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (97,'views','comments_recent-block','zen',0,-3,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (98,'views','popular-block','zen',0,-7,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (99,'views','popular-block_1','zen',0,4,'left',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (100,'author_pane','0','zen_cognitis',0,-1,'',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (101,'comment','0','zen_cognitis',1,-12,'left',0,0,1,'forum\r\nforum/*','',1);
INSERT INTO `drupal_blocks` VALUES (102,'devel','0','zen_cognitis',0,6,'',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (103,'devel','2','zen_cognitis',0,-6,'',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (104,'devel_node_access','0','zen_cognitis',0,-14,'',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (105,'devel_node_access','1','zen_cognitis',0,-13,'',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (106,'forum','0','zen_cognitis',1,-13,'left',0,0,1,'forum\r\nforum/*','',1);
INSERT INTO `drupal_blocks` VALUES (107,'forum','1','zen_cognitis',1,-14,'left',0,0,1,'forum\r\nforum/*','',1);
INSERT INTO `drupal_blocks` VALUES (108,'i18npoll','0','zen_cognitis',0,-4,'',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (109,'locale','0','zen_cognitis',0,-8,'',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (110,'masquerade','0','zen_cognitis',1,-9,'left',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (111,'menu','devel','zen_cognitis',0,-17,'',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (112,'menu','primary-links','zen_cognitis',0,-3,'',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (113,'menu','secondary-links','zen_cognitis',0,5,'',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (114,'node','0','zen_cognitis',0,7,'',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (115,'poll','0','zen_cognitis',0,-5,'',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (116,'privatemsg','privatemsg-menu','zen_cognitis',0,-2,'',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (117,'profile','0','zen_cognitis',0,-7,'',0,0,0,'','',5);
INSERT INTO `drupal_blocks` VALUES (118,'search','0','zen_cognitis',1,-16,'left',0,0,0,'<front>','',-1);
INSERT INTO `drupal_blocks` VALUES (119,'shoutbox','0','zen_cognitis',0,-15,'',1,0,0,'<front>','',1);
INSERT INTO `drupal_blocks` VALUES (120,'simplenews','91','zen_cognitis',0,-16,'',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (121,'statistics','0','zen_cognitis',0,2,'',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (122,'system','0','zen_cognitis',0,-10,'',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (123,'user','0','zen_cognitis',0,-9,'',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (124,'user','1','zen_cognitis',0,-18,'',0,0,0,'','<none>',-1);
INSERT INTO `drupal_blocks` VALUES (125,'user','2','zen_cognitis',0,8,'',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (126,'user','3','zen_cognitis',1,-11,'left',1,0,0,'<front>','<none>',-1);
INSERT INTO `drupal_blocks` VALUES (127,'views','active_users-block_1','zen_cognitis',1,-10,'left',1,0,0,'<front>','',-1);
INSERT INTO `drupal_blocks` VALUES (156,'simplenews','178','zen_cognitis',1,-15,'left',0,0,0,'<front>\r\nforum\r\nforum/*','',-1);
INSERT INTO `drupal_blocks` VALUES (133,'diff','inline','zen_cognitis',0,4,'',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (134,'menu','menu-footer-links','zen_cognitis',0,-11,'',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (136,'menu_block','1','zen',0,0,'',0,0,0,'<front>','<none>',-1);
INSERT INTO `drupal_blocks` VALUES (137,'menu_block','1','zen_cognitis',1,-19,'left',0,0,0,'<front>','<none>',-1);
INSERT INTO `drupal_blocks` VALUES (138,'menu_block','1','garland',0,3,'',0,0,0,'<front>','<none>',-1);
INSERT INTO `drupal_blocks` VALUES (139,'privatemsg','privatemsg-new','zen_cognitis',0,-12,'',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (144,'brilliant_gallery','0','zen_cognitis',0,3,'',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (167,'menu_block','2','zen_cognitis',1,-18,'left',0,0,0,'','<none>',-1);
INSERT INTO `drupal_blocks` VALUES (146,'menu','menu-footer-links','garland',1,0,'footer',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (147,'brilliant_gallery','0','garland',0,-6,'',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (148,'diff','inline','garland',0,-5,'',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (149,'privatemsg','privatemsg-new','garland',0,-4,'',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (155,'notifications_ui','0','zen_cognitis',0,1,'',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (158,'tableofcontents_block','0','zen_cognitis',1,-17,'left',0,0,0,'<front>','<none>',1);
INSERT INTO `drupal_blocks` VALUES (159,'notifications_ui','0','garland',0,1,'',0,0,0,'','',1);
INSERT INTO `drupal_blocks` VALUES (160,'simplenews','178','garland',0,-1,'',0,0,0,'<front>\r\nforum\r\nforum/*','',-1);
INSERT INTO `drupal_blocks` VALUES (165,'tableofcontents_block','0','garland',0,2,'',0,0,0,'<front>','<none>',1);
INSERT INTO `drupal_blocks` VALUES (169,'menu','admin_menu','garland',0,-3,'',0,0,0,'','',-1);
INSERT INTO `drupal_blocks` VALUES (170,'menu','admin_menu','zen_cognitis',0,0,'',0,0,0,'','',-1);
/*!40000 ALTER TABLE `drupal_blocks` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

