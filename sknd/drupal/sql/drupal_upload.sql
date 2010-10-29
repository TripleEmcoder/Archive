
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
DROP TABLE IF EXISTS `drupal_upload`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_upload` (
  `fid` int(10) unsigned NOT NULL default '0',
  `nid` int(10) unsigned NOT NULL default '0',
  `vid` int(10) unsigned NOT NULL default '0',
  `description` varchar(255) NOT NULL default '',
  `list` tinyint(3) unsigned NOT NULL default '0',
  `weight` tinyint(4) NOT NULL default '0',
  PRIMARY KEY  (`vid`,`fid`),
  KEY `fid` (`fid`),
  KEY `nid` (`nid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_upload` WRITE;
/*!40000 ALTER TABLE `drupal_upload` DISABLE KEYS */;
INSERT INTO `drupal_upload` VALUES (133,623,623,'dojazd-PMDays.gif',1,2);
INSERT INTO `drupal_upload` VALUES (134,676,676,'logo&amp;slogan.jpeg',1,1);
INSERT INTO `drupal_upload` VALUES (145,745,745,'07_12_29_grupowe_lichen_podpisane_resize_pkuc.jpg',1,33);
INSERT INTO `drupal_upload` VALUES (150,771,771,'P1070545.JPG',1,85);
INSERT INTO `drupal_upload` VALUES (149,771,771,'gabl ae.jpg',1,84);
INSERT INTO `drupal_upload` VALUES (148,771,771,'PP po.JPG',1,83);
INSERT INTO `drupal_upload` VALUES (147,771,771,'PP przed.JPG',1,82);
INSERT INTO `drupal_upload` VALUES (146,746,746,'skndinno.jpg',1,8);
INSERT INTO `drupal_upload` VALUES (143,742,742,'rollup_DZD_mini.jpg',1,32);
INSERT INTO `drupal_upload` VALUES (144,742,742,'logo_DzPrawem.jpg',1,48);
INSERT INTO `drupal_upload` VALUES (138,729,729,'zakochani.jpg',1,9);
INSERT INTO `drupal_upload` VALUES (137,719,719,'logo Złap Konsulting.jpg',1,7);
INSERT INTO `drupal_upload` VALUES (136,719,719,'Wakacje z BBC.jpg',1,6);
INSERT INTO `drupal_upload` VALUES (135,685,685,'twarze.jpeg',1,3);
INSERT INTO `drupal_upload` VALUES (142,732,732,'Ambasador McKinsey 2009.rar',1,71);
INSERT INTO `drupal_upload` VALUES (139,730,730,'made by kkuc.jpg',1,23);
INSERT INTO `drupal_upload` VALUES (140,730,730,'Referencje Kolaja&amp;Partners_.jpg',1,24);
INSERT INTO `drupal_upload` VALUES (141,732,732,'Zostan ambasadorem BCG.rar',1,70);
INSERT INTO `drupal_upload` VALUES (164,829,829,'Patrycja Łucka.jpg',1,20);
INSERT INTO `drupal_upload` VALUES (163,829,829,'Michał Płotnicki.jpg',1,19);
INSERT INTO `drupal_upload` VALUES (162,829,829,'Wojtek Walniczek.jpg',1,18);
INSERT INTO `drupal_upload` VALUES (161,829,829,'Michał Durski.jpg',1,17);
INSERT INTO `drupal_upload` VALUES (160,825,825,'bomba_przyszlosc.jpg',1,14);
INSERT INTO `drupal_upload` VALUES (159,817,817,'GG_DzS.JPG',1,62);
INSERT INTO `drupal_upload` VALUES (158,796,796,'logo-grantow_pkuc.jpg',1,13);
INSERT INTO `drupal_upload` VALUES (157,789,789,'06_02_17_Feedback sheet - szkolenie_murb.zip',1,27);
INSERT INTO `drupal_upload` VALUES (151,771,771,'P1070553.JPG',1,86);
INSERT INTO `drupal_upload` VALUES (152,771,771,'P1070550.JPG',1,87);
INSERT INTO `drupal_upload` VALUES (153,772,772,'Ślub2.JPG',1,10);
INSERT INTO `drupal_upload` VALUES (154,772,772,'Ślub1.JPG',1,11);
INSERT INTO `drupal_upload` VALUES (155,772,772,'Tort.png',1,15);
INSERT INTO `drupal_upload` VALUES (156,772,772,'Tort SKND dla Kasi i Kamila.jpg',1,16);
INSERT INTO `drupal_upload` VALUES (171,829,829,'lans.jpg',1,78);
INSERT INTO `drupal_upload` VALUES (170,829,829,'Obraz 016.jpg',1,59);
INSERT INTO `drupal_upload` VALUES (169,829,829,'Kuba Kessler.jpg',1,51);
INSERT INTO `drupal_upload` VALUES (168,829,829,'Damian Węgrzynowski.jpg',1,50);
INSERT INTO `drupal_upload` VALUES (165,829,829,'Beata Kazimierczak.jpg',1,21);
INSERT INTO `drupal_upload` VALUES (166,829,829,'Krakowiak Ania.JPG',1,22);
INSERT INTO `drupal_upload` VALUES (167,829,829,'Mateusz Frukacz.jpg',1,49);
INSERT INTO `drupal_upload` VALUES (177,873,873,'Zdjęcie030.jpg',1,52);
INSERT INTO `drupal_upload` VALUES (176,870,870,'100_1411.JPG',1,31);
INSERT INTO `drupal_upload` VALUES (175,864,864,'made by kkuc.jpg',1,29);
INSERT INTO `drupal_upload` VALUES (174,863,863,'Gablotki.JPG',1,28);
INSERT INTO `drupal_upload` VALUES (173,853,853,'93.jpg',1,26);
INSERT INTO `drupal_upload` VALUES (172,841,841,'legia.gif',1,25);
INSERT INTO `drupal_upload` VALUES (186,895,895,'DSCN9787.JPG',1,43);
INSERT INTO `drupal_upload` VALUES (185,895,895,'Bowling Team.JPG',1,42);
INSERT INTO `drupal_upload` VALUES (178,883,883,'X-3.jpg',1,34);
INSERT INTO `drupal_upload` VALUES (179,883,883,'X-2.JPG',1,35);
INSERT INTO `drupal_upload` VALUES (180,883,883,'X-1.JPG',1,36);
INSERT INTO `drupal_upload` VALUES (181,895,895,'Obraz 106.jpg',1,38);
INSERT INTO `drupal_upload` VALUES (182,895,895,'Obraz 108.jpg',1,39);
INSERT INTO `drupal_upload` VALUES (183,895,895,'Obraz 087.jpg',1,40);
INSERT INTO `drupal_upload` VALUES (184,895,895,'Obraz 085.jpg',1,41);
INSERT INTO `drupal_upload` VALUES (187,895,895,'DSCN9768.JPG',1,45);
INSERT INTO `drupal_upload` VALUES (188,901,901,'telegram.jpg',1,37);
INSERT INTO `drupal_upload` VALUES (189,906,906,'plakat_wycinek_na_forum.jpg',1,46);
INSERT INTO `drupal_upload` VALUES (190,907,907,'tomek---po-godzinach.jpg',1,47);
INSERT INTO `drupal_upload` VALUES (191,908,908,'plan.jpg',1,72);
INSERT INTO `drupal_upload` VALUES (192,908,908,'3.JPG',1,73);
INSERT INTO `drupal_upload` VALUES (193,908,908,'2.JPG',1,74);
INSERT INTO `drupal_upload` VALUES (194,908,908,'1.JPG',1,75);
INSERT INTO `drupal_upload` VALUES (195,911,911,'forum1.jpg',1,54);
INSERT INTO `drupal_upload` VALUES (196,911,911,'forum2.jpg',1,55);
INSERT INTO `drupal_upload` VALUES (197,911,911,'forum3.jpg',1,56);
INSERT INTO `drupal_upload` VALUES (198,911,911,'forum4.jpg',1,57);
INSERT INTO `drupal_upload` VALUES (199,911,911,'forum5.jpg',1,58);
INSERT INTO `drupal_upload` VALUES (200,928,928,'streetball.jpg',1,53);
INSERT INTO `drupal_upload` VALUES (201,928,928,'Zdjęcie001.jpg',1,61);
INSERT INTO `drupal_upload` VALUES (202,929,929,'herbatka-u-Bartka.jpg',1,60);
INSERT INTO `drupal_upload` VALUES (203,958,958,'plakat.jpg',1,63);
INSERT INTO `drupal_upload` VALUES (204,958,958,'DSC000041.jpg',1,65);
INSERT INTO `drupal_upload` VALUES (205,964,964,'skandal4.jpg',1,64);
INSERT INTO `drupal_upload` VALUES (206,970,970,'Zastawa.JPG',1,66);
INSERT INTO `drupal_upload` VALUES (207,971,971,'SKaNDalnr55.JPG',1,67);
INSERT INTO `drupal_upload` VALUES (208,976,976,'Patrycja Łucka.jpg',1,68);
INSERT INTO `drupal_upload` VALUES (209,997,997,'żubr_482c999b84eb9.jpg',1,69);
INSERT INTO `drupal_upload` VALUES (210,1025,1025,'08_09_19_Kalendarz_SKND_Kadencja0809_jpg.jpg',1,-1);
INSERT INTO `drupal_upload` VALUES (211,1070,1070,'regulamin gry - bitwa morska.rar',1,80);
INSERT INTO `drupal_upload` VALUES (262,1107,1107,'thecubes-itguy.jpg',1,0);
INSERT INTO `drupal_upload` VALUES (268,1124,1124,'09_01_29_Zarzadzanie kontami i zasobami SKND_mbas&mmik_v1.doc',1,0);
INSERT INTO `drupal_upload` VALUES (269,1124,1124,'09_01_29_Zarzadzanie kontami i zasobami SKND_mbas&mmik_v1.pdf',1,0);
INSERT INTO `drupal_upload` VALUES (270,1125,1125,'EFS leaflet.pdf',1,0);
INSERT INTO `drupal_upload` VALUES (309,1025,1025,'09_04_18_Kalendarz SKND_zmiany od kwietnia.jpg',1,0);
INSERT INTO `drupal_upload` VALUES (311,1210,1210,'09_04_04_LISTY  MAILINGOWE  SKND_asli.doc',1,0);
INSERT INTO `drupal_upload` VALUES (347,1608,2353,'cognitis.jpg',1,0);
INSERT INTO `drupal_upload` VALUES (366,1806,3144,'A_T__Kearney_Internship____Ad_Template_Aug2010.ppt',1,0);
INSERT INTO `drupal_upload` VALUES (360,1276,3040,'zasady.gif',1,0);
INSERT INTO `drupal_upload` VALUES (357,1741,2948,'ulotka_KWoR.jpg',1,0);
INSERT INTO `drupal_upload` VALUES (360,1276,3041,'zasady.gif',0,0);
INSERT INTO `drupal_upload` VALUES (360,1276,3039,'zasady.gif',1,0);
/*!40000 ALTER TABLE `drupal_upload` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

