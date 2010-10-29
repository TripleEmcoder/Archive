
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
DROP TABLE IF EXISTS `drupal_comment_upload`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_comment_upload` (
  `fid` int(10) unsigned NOT NULL default '0',
  `nid` int(10) unsigned NOT NULL default '0',
  `cid` int(10) unsigned NOT NULL default '0',
  `description` varchar(255) NOT NULL default '',
  `list` tinyint(3) unsigned NOT NULL default '0',
  `weight` tinyint(4) NOT NULL default '0',
  PRIMARY KEY  (`fid`),
  KEY `cid_fid` (`cid`,`fid`),
  KEY `nid` (`nid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_comment_upload` WRITE;
/*!40000 ALTER TABLE `drupal_comment_upload` DISABLE KEYS */;
INSERT INTO `drupal_comment_upload` VALUES (212,623,2391,'dojazd-PMDays.gif',1,2);
INSERT INTO `drupal_comment_upload` VALUES (213,719,2705,'logo Złap Konsulting.jpg',1,7);
INSERT INTO `drupal_comment_upload` VALUES (214,729,2738,'zakochani.jpg',1,9);
INSERT INTO `drupal_comment_upload` VALUES (215,730,2741,'Referencje Kolaja&amp;Partners_.jpg',1,24);
INSERT INTO `drupal_comment_upload` VALUES (216,732,2744,'Zostan ambasadorem BCG.rar',1,70);
INSERT INTO `drupal_comment_upload` VALUES (217,732,2745,'Ambasador McKinsey 2009.rar',1,71);
INSERT INTO `drupal_comment_upload` VALUES (218,742,2797,'rollup_DZD_mini.jpg',1,32);
INSERT INTO `drupal_comment_upload` VALUES (219,742,2803,'logo_DzPrawem.jpg',1,48);
INSERT INTO `drupal_comment_upload` VALUES (222,771,2912,'PP po.JPG',1,83);
INSERT INTO `drupal_comment_upload` VALUES (221,771,2911,'PP przed.JPG',1,82);
INSERT INTO `drupal_comment_upload` VALUES (220,745,2835,'07_12_29_grupowe_lichen_podpisane_resize_pkuc.jpg',1,33);
INSERT INTO `drupal_comment_upload` VALUES (230,772,2934,'Tort SKND dla Kasi i Kamila.jpg',1,16);
INSERT INTO `drupal_comment_upload` VALUES (223,771,2915,'gabl ae.jpg',1,84);
INSERT INTO `drupal_comment_upload` VALUES (224,771,2922,'P1070545.JPG',1,85);
INSERT INTO `drupal_comment_upload` VALUES (225,771,2922,'P1070553.JPG',1,86);
INSERT INTO `drupal_comment_upload` VALUES (226,771,2922,'P1070550.JPG',1,87);
INSERT INTO `drupal_comment_upload` VALUES (227,772,2932,'Ślub2.JPG',1,10);
INSERT INTO `drupal_comment_upload` VALUES (228,772,2932,'Ślub1.JPG',1,11);
INSERT INTO `drupal_comment_upload` VALUES (229,772,2934,'Tort.png',1,15);
INSERT INTO `drupal_comment_upload` VALUES (231,789,2965,'06_02_17_Feedback sheet - szkolenie_murb.zip',1,27);
INSERT INTO `drupal_comment_upload` VALUES (235,829,3157,'Damian Węgrzynowski.jpg',1,50);
INSERT INTO `drupal_comment_upload` VALUES (234,829,3157,'Mateusz Frukacz.jpg',1,49);
INSERT INTO `drupal_comment_upload` VALUES (233,817,3106,'GG_DzS.JPG',1,62);
INSERT INTO `drupal_comment_upload` VALUES (232,796,3009,'logo-grantow_pkuc.jpg',1,13);
INSERT INTO `drupal_comment_upload` VALUES (241,895,3447,'Obraz 106.jpg',1,38);
INSERT INTO `drupal_comment_upload` VALUES (240,873,3389,'Zdjęcie030.jpg',1,52);
INSERT INTO `drupal_comment_upload` VALUES (239,841,3223,'legia.gif',1,25);
INSERT INTO `drupal_comment_upload` VALUES (238,829,3175,'lans.jpg',1,78);
INSERT INTO `drupal_comment_upload` VALUES (237,829,3159,'Obraz 016.jpg',1,59);
INSERT INTO `drupal_comment_upload` VALUES (236,829,3157,'Kuba Kessler.jpg',1,51);
INSERT INTO `drupal_comment_upload` VALUES (244,895,3447,'Obraz 085.jpg',1,41);
INSERT INTO `drupal_comment_upload` VALUES (242,895,3447,'Obraz 108.jpg',1,39);
INSERT INTO `drupal_comment_upload` VALUES (243,895,3447,'Obraz 087.jpg',1,40);
INSERT INTO `drupal_comment_upload` VALUES (245,895,3449,'Bowling Team.JPG',1,42);
INSERT INTO `drupal_comment_upload` VALUES (246,895,3449,'DSCN9787.JPG',1,43);
INSERT INTO `drupal_comment_upload` VALUES (247,895,3449,'DSCN9768.JPG',1,45);
INSERT INTO `drupal_comment_upload` VALUES (248,908,3509,'plan.jpg',1,72);
INSERT INTO `drupal_comment_upload` VALUES (249,908,3510,'3.JPG',1,73);
INSERT INTO `drupal_comment_upload` VALUES (250,908,3510,'2.JPG',1,74);
INSERT INTO `drupal_comment_upload` VALUES (251,908,3510,'1.JPG',1,75);
INSERT INTO `drupal_comment_upload` VALUES (252,911,3531,'forum1.jpg',1,54);
INSERT INTO `drupal_comment_upload` VALUES (253,911,3531,'forum2.jpg',1,55);
INSERT INTO `drupal_comment_upload` VALUES (254,911,3531,'forum3.jpg',1,56);
INSERT INTO `drupal_comment_upload` VALUES (255,911,3531,'forum4.jpg',1,57);
INSERT INTO `drupal_comment_upload` VALUES (256,911,3531,'forum5.jpg',1,58);
INSERT INTO `drupal_comment_upload` VALUES (257,928,3644,'Zdjęcie001.jpg',1,61);
INSERT INTO `drupal_comment_upload` VALUES (258,929,3651,'herbatka-u-Bartka.jpg',1,60);
INSERT INTO `drupal_comment_upload` VALUES (259,958,3823,'DSC000041.jpg',1,65);
INSERT INTO `drupal_comment_upload` VALUES (260,976,3895,'Patrycja Łucka.jpg',1,68);
INSERT INTO `drupal_comment_upload` VALUES (263,1107,4228,'youneedit.gif',1,0);
INSERT INTO `drupal_comment_upload` VALUES (304,1083,4433,'DSC03815.JPG',1,0);
INSERT INTO `drupal_comment_upload` VALUES (312,1169,4517,'PL_KNM_2009_formularz.doc',1,0);
INSERT INTO `drupal_comment_upload` VALUES (316,829,4528,'Ada  Siłakiewicz.JPG',1,0);
INSERT INTO `drupal_comment_upload` VALUES (317,829,4528,'Beata Kazimierczak.jpg',1,0);
INSERT INTO `drupal_comment_upload` VALUES (318,829,4528,'Jagoda Podraza.JPG',1,0);
INSERT INTO `drupal_comment_upload` VALUES (320,1047,4542,'Marek Stanisławski - 05.2009.JPG',1,0);
INSERT INTO `drupal_comment_upload` VALUES (325,732,4567,'Ogloszenie Ambasador 2010.ppt',1,0);
/*!40000 ALTER TABLE `drupal_comment_upload` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

