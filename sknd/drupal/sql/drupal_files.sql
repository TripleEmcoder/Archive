
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
DROP TABLE IF EXISTS `drupal_files`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_files` (
  `fid` int(10) unsigned NOT NULL auto_increment,
  `uid` int(10) unsigned NOT NULL default '0',
  `filename` varchar(255) NOT NULL default '',
  `filepath` varchar(255) NOT NULL default '',
  `filemime` varchar(255) NOT NULL default '',
  `filesize` int(10) unsigned NOT NULL default '0',
  `status` int(11) NOT NULL default '0',
  `timestamp` int(10) unsigned NOT NULL default '0',
  `origname` varchar(255) NOT NULL default '',
  PRIMARY KEY  (`fid`),
  KEY `uid` (`uid`),
  KEY `status` (`status`),
  KEY `timestamp` (`timestamp`)
) ENGINE=MyISAM AUTO_INCREMENT=367 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_files` WRITE;
/*!40000 ALTER TABLE `drupal_files` DISABLE KEYS */;
INSERT INTO `drupal_files` VALUES (166,152,'Krakowiak Ania.JPG','sites/default/files/krakowiak_ania_154.jpg','image/jpeg',39081,1,1194792670,'Krakowiak Ania.JPG');
INSERT INTO `drupal_files` VALUES (167,152,'Mateusz Frukacz.jpg','sites/default/files/mateusz_frukacz_335.jpg','image/jpeg',3835,1,1204802661,'Mateusz Frukacz.jpg');
INSERT INTO `drupal_files` VALUES (168,152,'Damian Węgrzynowski.jpg','sites/default/files/damian_wgrzynowski_953.jpg','image/jpeg',3785,1,1204802639,'Damian Węgrzynowski.jpg');
INSERT INTO `drupal_files` VALUES (169,152,'Kuba Kessler.jpg','sites/default/files/kuba_kessler_809.jpg','image/jpeg',4280,1,1204802625,'Kuba Kessler.jpg');
INSERT INTO `drupal_files` VALUES (170,152,'Obraz 016.jpg','sites/default/files/obraz_016_131.jpg','image/pjpeg',33743,1,1206138372,'Obraz 016.jpg');
INSERT INTO `drupal_files` VALUES (171,152,'lans.jpg','sites/default/files/lans_137.jpg','image/jpeg',193890,1,1225805104,'lans.jpg');
INSERT INTO `drupal_files` VALUES (172,138,'legia.gif','sites/default/files/legia_110.gif','image/gif',1804,1,1195920425,'legia.gif');
INSERT INTO `drupal_files` VALUES (173,150,'93.jpg','sites/default/files/93_509.jpg','image/jpeg',145462,1,1196412570,'93.jpg');
INSERT INTO `drupal_files` VALUES (174,166,'Gablotki.JPG','sites/default/files/gablotki_176.jpg','image/jpeg',44515,1,1197377838,'Gablotki.JPG');
INSERT INTO `drupal_files` VALUES (175,147,'made by kkuc.jpg','sites/default/files/made_by_kkuc_110.jpg','image/jpeg',45555,1,1197419415,'made by kkuc.jpg');
INSERT INTO `drupal_files` VALUES (176,188,'100_1411.JPG','sites/default/files/100_1411_129.jpg','image/jpeg',221284,1,1198337794,'100_1411.JPG');
INSERT INTO `drupal_files` VALUES (177,159,'Zdjęcie030.jpg','sites/default/files/zdjcie030_430.jpg','image/jpeg',283156,1,1205176359,'Zdjęcie030.jpg');
INSERT INTO `drupal_files` VALUES (178,188,'X-3.jpg','sites/default/files/x_3_515.jpg','image/jpeg',22901,1,1200524978,'X-3.jpg');
INSERT INTO `drupal_files` VALUES (179,188,'X-2.JPG','sites/default/files/x_2_863.jpg','image/jpeg',30831,1,1200524942,'X-2.JPG');
INSERT INTO `drupal_files` VALUES (180,188,'X-1.JPG','sites/default/files/x_1_135.jpg','image/jpeg',20359,1,1200524919,'X-1.JPG');
INSERT INTO `drupal_files` VALUES (181,191,'Obraz 106.jpg','sites/default/files/obraz_106_373.jpg','image/jpeg',113443,1,1202945729,'Obraz 106.jpg');
INSERT INTO `drupal_files` VALUES (182,191,'Obraz 108.jpg','sites/default/files/obraz_108_301.jpg','image/jpeg',81100,1,1202945696,'Obraz 108.jpg');
INSERT INTO `drupal_files` VALUES (183,191,'Obraz 087.jpg','sites/default/files/obraz_087_323.jpg','image/jpeg',48123,1,1202945658,'Obraz 087.jpg');
INSERT INTO `drupal_files` VALUES (184,191,'Obraz 085.jpg','sites/default/files/obraz_085_212.jpg','image/jpeg',52694,1,1202945650,'Obraz 085.jpg');
INSERT INTO `drupal_files` VALUES (185,191,'Bowling Team.JPG','sites/default/files/bowling_team_744.jpg','image/jpeg',166259,1,1203030613,'Bowling Team.JPG');
INSERT INTO `drupal_files` VALUES (186,191,'DSCN9787.JPG','sites/default/files/dscn9787_179.jpg','image/jpeg',144826,1,1203029370,'DSCN9787.JPG');
INSERT INTO `drupal_files` VALUES (187,191,'DSCN9768.JPG','sites/default/files/dscn9768_165.jpg','image/jpeg',177992,1,1203029181,'DSCN9768.JPG');
INSERT INTO `drupal_files` VALUES (188,150,'telegram.jpg','sites/default/files/telegram_130.jpg','image/jpeg',175727,1,1202939385,'telegram.jpg');
INSERT INTO `drupal_files` VALUES (189,150,'plakat_wycinek_na_forum.jpg','sites/default/files/plakat_wycinek_na_forum_173.jpg','image/jpeg',126120,1,1203972653,'plakat_wycinek_na_forum.jpg');
INSERT INTO `drupal_files` VALUES (190,154,'tomek---po-godzinach.jpg','sites/default/files/tomek__po_godzinach_899.jpg','image/jpeg',211714,1,1203980774,'tomek---po-godzinach.jpg');
INSERT INTO `drupal_files` VALUES (191,164,'plan.jpg','sites/default/files/plan_755.jpg','image/jpeg',42000,1,1214590627,'plan.jpg');
INSERT INTO `drupal_files` VALUES (192,164,'3.JPG','sites/default/files/3_160.jpg','image/jpeg',13670,1,1218034361,'3.JPG');
INSERT INTO `drupal_files` VALUES (193,164,'2.JPG','sites/default/files/2_120.jpg','image/jpeg',14110,1,1218034355,'2.JPG');
INSERT INTO `drupal_files` VALUES (194,164,'1.JPG','sites/default/files/1_744.jpg','image/jpeg',8263,1,1218034339,'1.JPG');
INSERT INTO `drupal_files` VALUES (195,154,'forum1.jpg','sites/default/files/forum1_252.jpg','image/jpeg',273870,1,1206119049,'forum1.jpg');
INSERT INTO `drupal_files` VALUES (196,154,'forum2.jpg','sites/default/files/forum2_131.jpg','image/jpeg',251558,1,1206119022,'forum2.jpg');
INSERT INTO `drupal_files` VALUES (197,154,'forum3.jpg','sites/default/files/forum3_200.jpg','image/jpeg',255599,1,1206118987,'forum3.jpg');
INSERT INTO `drupal_files` VALUES (198,154,'forum4.jpg','sites/default/files/forum4_104.jpg','image/jpeg',385170,1,1206118953,'forum4.jpg');
INSERT INTO `drupal_files` VALUES (199,154,'forum5.jpg','sites/default/files/forum5_135.jpg','image/jpeg',290897,1,1206118861,'forum5.jpg');
INSERT INTO `drupal_files` VALUES (200,154,'streetball.jpg','sites/default/files/streetball_996.jpg','image/jpeg',149167,1,1205755811,'streetball.jpg');
INSERT INTO `drupal_files` VALUES (201,154,'Zdjęcie001.jpg','sites/default/files/zdjcie001_197.jpg','image/pjpeg',127560,1,1206719105,'Zdjęcie001.jpg');
INSERT INTO `drupal_files` VALUES (202,159,'herbatka-u-Bartka.jpg','sites/default/files/herbatka_u_bartka_700.jpg','image/jpeg',327643,1,1206139797,'herbatka-u-Bartka.jpg');
INSERT INTO `drupal_files` VALUES (203,144,'plakat.jpg','sites/default/files/plakat_838.jpg','image/pjpeg',251384,1,1208110797,'plakat.jpg');
INSERT INTO `drupal_files` VALUES (204,144,'DSC000041.jpg','sites/default/files/dsc000041_346.jpg','image/jpeg',145923,1,1208362881,'DSC000041.jpg');
INSERT INTO `drupal_files` VALUES (205,218,'skandal4.jpg','sites/default/files/skandal4_192.jpg','image/jpeg',419485,1,1208351406,'skandal4.jpg');
INSERT INTO `drupal_files` VALUES (206,188,'Zastawa.JPG','sites/default/files/zastawa_175.jpg','image/jpeg',75083,1,1208900112,'Zastawa.JPG');
INSERT INTO `drupal_files` VALUES (207,218,'SKaNDalnr55.JPG','sites/default/files/skandalnr55_854.jpg','image/jpeg',192424,1,1208901183,'SKaNDalnr55.JPG');
INSERT INTO `drupal_files` VALUES (208,152,'Patrycja Łucka.jpg','sites/default/files/patrycja_ucka_778.jpg','image/jpeg',33743,1,1209764392,'Patrycja Łucka.jpg');
INSERT INTO `drupal_files` VALUES (209,178,'żubr_482c999b84eb9.jpg','sites/default/files/ubr_482c999b84eb9_153.jpg','image/jpeg',239633,1,1211308223,'żubr_482c999b84eb9.jpg');
INSERT INTO `drupal_files` VALUES (210,134,'08_09_19_Kalendarz_SKND_Kadencja0809_jpg.jpg','sites/default/files/08_09_19_kalendarz_sknd_kadencja0809_jpg_876.jpg','image/jpeg',141515,1,1227650371,'08_09_19_Kalendarz_SKND_Kadencja0809_jpg.jpg');
INSERT INTO `drupal_files` VALUES (211,235,'regulamin gry - bitwa morska.rar','sites/default/files/regulamin_gry__bitwa_morska_141.rar','application/octet-stream',40842,1,1227533096,'regulamin gry - bitwa morska.rar');
INSERT INTO `drupal_files` VALUES (212,164,'dojazd-PMDays.gif','sites/default/files/dojazd_pmdays_107.gif','image/gif',32319,1,1177419621,'dojazd-PMDays.gif');
INSERT INTO `drupal_files` VALUES (213,154,'logo Złap Konsulting.jpg','sites/default/files/logo_zap_konsulting_995.jpg','image/jpeg',113500,1,1188657189,'logo Złap Konsulting.jpg');
INSERT INTO `drupal_files` VALUES (214,163,'zakochani.jpg','sites/default/files/zakochani_189.jpg','image/pjpeg',134564,1,1192656519,'zakochani.jpg');
INSERT INTO `drupal_files` VALUES (215,147,'Referencje Kolaja&amp;Partners_.jpg','sites/default/files/referencje_kolajaandpartners__131.jpg','image/jpeg',120908,1,1195688037,'Referencje Kolaja&amp;Partners_.jpg');
INSERT INTO `drupal_files` VALUES (216,181,'Zostan ambasadorem BCG.rar','sites/default/files/zostan_ambasadorem_bcg_652.rar','application/octet-stream',38448,1,1212497461,'Zostan ambasadorem BCG.rar');
INSERT INTO `drupal_files` VALUES (217,181,'Ambasador McKinsey 2009.rar','sites/default/files/ambasador_mckinsey_2009_970.rar','application/octet-stream',140176,1,1213067203,'Ambasador McKinsey 2009.rar');
INSERT INTO `drupal_files` VALUES (218,154,'rollup_DZD_mini.jpg','sites/default/files/rollup_dzd_mini_190.jpg','image/jpeg',18317,1,1198422913,'rollup_DZD_mini.jpg');
INSERT INTO `drupal_files` VALUES (219,154,'logo_DzPrawem.jpg','sites/default/files/logo_dzprawem_163.jpg','image/jpeg',196387,1,1204192839,'logo_DzPrawem.jpg');
INSERT INTO `drupal_files` VALUES (220,154,'07_12_29_grupowe_lichen_podpisane_resize_pkuc.jpg','sites/default/files/07_12_29_grupowe_lichen_podpisane_resize_pkuc_303.jpg','image/jpeg',196175,1,1198966780,'07_12_29_grupowe_lichen_podpisane_resize_pkuc.jpg');
INSERT INTO `drupal_files` VALUES (221,203,'PP przed.JPG','sites/default/files/pp_przed_201.jpg','image/jpeg',38409,1,1227968711,'PP przed.JPG');
INSERT INTO `drupal_files` VALUES (222,203,'PP po.JPG','sites/default/files/pp_po_767.jpg','image/jpeg',33834,1,1227968744,'PP po.JPG');
INSERT INTO `drupal_files` VALUES (223,203,'gabl ae.jpg','sites/default/files/gabl_ae_792.jpg','image/jpeg',73370,1,1228312725,'gabl ae.jpg');
INSERT INTO `drupal_files` VALUES (224,183,'P1070545.JPG','sites/default/files/p1070545_110.jpg','image/jpeg',76712,1,1229629087,'P1070545.JPG');
INSERT INTO `drupal_files` VALUES (225,183,'P1070553.JPG','sites/default/files/p1070553_103.jpg','image/jpeg',94196,1,1229629036,'P1070553.JPG');
INSERT INTO `drupal_files` VALUES (226,183,'P1070550.JPG','sites/default/files/p1070550_172.jpg','image/jpeg',88977,1,1229629011,'P1070550.JPG');
INSERT INTO `drupal_files` VALUES (227,136,'Ślub2.JPG','sites/default/files/lub2_116.jpg','image/pjpeg',36102,1,1192712780,'Ślub2.JPG');
INSERT INTO `drupal_files` VALUES (228,136,'Ślub1.JPG','sites/default/files/lub1_191.jpg','image/pjpeg',19775,1,1192712758,'Ślub1.JPG');
INSERT INTO `drupal_files` VALUES (229,143,'Tort.png','sites/default/files/tort_189.png','image/x-png',166798,1,1194716950,'Tort.png');
INSERT INTO `drupal_files` VALUES (230,143,'Tort SKND dla Kasi i Kamila.jpg','sites/default/files/tort_sknd_dla_kasi_i_kamila_214.jpg','image/pjpeg',108525,1,1194716916,'Tort SKND dla Kasi i Kamila.jpg');
INSERT INTO `drupal_files` VALUES (231,147,'06_02_17_Feedback sheet - szkolenie_murb.zip','sites/default/files/06_02_17_feedback_sheet__szkolenie_murb_203.zip','application/zip',11679,1,1197107015,'06_02_17_Feedback sheet - szkolenie_murb.zip');
INSERT INTO `drupal_files` VALUES (232,138,'logo-grantow_pkuc.jpg','sites/default/files/logo_grantow_pkuc_180.jpg','image/jpeg',255605,1,1194028537,'logo-grantow_pkuc.jpg');
INSERT INTO `drupal_files` VALUES (233,152,'GG_DzS.JPG','sites/default/files/gg_dzs_191.jpg','image/jpeg',64101,1,1206800307,'GG_DzS.JPG');
INSERT INTO `drupal_files` VALUES (133,135,'dojazd-PMDays.gif','sites/default/files/dojazd_pmdays_107.gif','image/gif',32319,1,1177419621,'dojazd-PMDays.gif');
INSERT INTO `drupal_files` VALUES (134,164,'logo&amp;slogan.jpeg','sites/default/files/logoandslogan_129.jpeg','image/jpeg',31537,1,1176978876,'logo&amp;slogan.jpeg');
INSERT INTO `drupal_files` VALUES (135,154,'twarze.jpeg','sites/default/files/twarze_200.jpeg','image/jpeg',81500,1,1177703864,'twarze.jpeg');
INSERT INTO `drupal_files` VALUES (136,154,'Wakacje z BBC.jpg','sites/default/files/wakacje_z_bbc_356.jpg','image/jpeg',49237,1,1184062799,'Wakacje z BBC.jpg');
INSERT INTO `drupal_files` VALUES (137,154,'logo Złap Konsulting.jpg','sites/default/files/logo_zap_konsulting_995.jpg','image/jpeg',113500,1,1188657189,'logo Złap Konsulting.jpg');
INSERT INTO `drupal_files` VALUES (138,164,'zakochani.jpg','sites/default/files/zakochani_189.jpg','image/pjpeg',134564,1,1192656519,'zakochani.jpg');
INSERT INTO `drupal_files` VALUES (139,147,'made by kkuc.jpg','sites/default/files/made_by_kkuc_159.jpg','image/jpeg',45555,1,1195687695,'made by kkuc.jpg');
INSERT INTO `drupal_files` VALUES (140,147,'Referencje Kolaja&amp;Partners_.jpg','sites/default/files/referencje_kolajaandpartners__131.jpg','image/jpeg',120908,1,1195688037,'Referencje Kolaja&amp;Partners_.jpg');
INSERT INTO `drupal_files` VALUES (141,147,'Zostan ambasadorem BCG.rar','sites/default/files/zostan_ambasadorem_bcg_652.rar','application/octet-stream',38448,1,1212497461,'Zostan ambasadorem BCG.rar');
INSERT INTO `drupal_files` VALUES (142,147,'Ambasador McKinsey 2009.rar','sites/default/files/ambasador_mckinsey_2009_970.rar','application/octet-stream',140176,1,1213067203,'Ambasador McKinsey 2009.rar');
INSERT INTO `drupal_files` VALUES (143,147,'rollup_DZD_mini.jpg','sites/default/files/rollup_dzd_mini_190.jpg','image/jpeg',18317,1,1198422913,'rollup_DZD_mini.jpg');
INSERT INTO `drupal_files` VALUES (144,147,'logo_DzPrawem.jpg','sites/default/files/logo_dzprawem_163.jpg','image/jpeg',196387,1,1204192839,'logo_DzPrawem.jpg');
INSERT INTO `drupal_files` VALUES (145,157,'07_12_29_grupowe_lichen_podpisane_resize_pkuc.jpg','sites/default/files/07_12_29_grupowe_lichen_podpisane_resize_pkuc_303.jpg','image/jpeg',196175,1,1198966780,'07_12_29_grupowe_lichen_podpisane_resize_pkuc.jpg');
INSERT INTO `drupal_files` VALUES (146,150,'skndinno.jpg','sites/default/files/skndinno_930.jpg','image/jpeg',194000,1,1189808148,'skndinno.jpg');
INSERT INTO `drupal_files` VALUES (147,147,'PP przed.JPG','sites/default/files/pp_przed_201.jpg','image/jpeg',38409,1,1227968711,'PP przed.JPG');
INSERT INTO `drupal_files` VALUES (148,147,'PP po.JPG','sites/default/files/pp_po_767.jpg','image/jpeg',33834,1,1227968744,'PP po.JPG');
INSERT INTO `drupal_files` VALUES (149,147,'gabl ae.jpg','sites/default/files/gabl_ae_792.jpg','image/jpeg',73370,1,1228312725,'gabl ae.jpg');
INSERT INTO `drupal_files` VALUES (150,147,'P1070545.JPG','sites/default/files/p1070545_110.jpg','image/jpeg',76712,1,1229629087,'P1070545.JPG');
INSERT INTO `drupal_files` VALUES (151,147,'P1070553.JPG','sites/default/files/p1070553_103.jpg','image/jpeg',94196,1,1229629036,'P1070553.JPG');
INSERT INTO `drupal_files` VALUES (152,147,'P1070550.JPG','sites/default/files/p1070550_172.jpg','image/jpeg',88977,1,1229629011,'P1070550.JPG');
INSERT INTO `drupal_files` VALUES (153,164,'Ślub2.JPG','sites/default/files/lub2_116.jpg','image/pjpeg',36102,1,1192712780,'Ślub2.JPG');
INSERT INTO `drupal_files` VALUES (154,164,'Ślub1.JPG','sites/default/files/lub1_191.jpg','image/pjpeg',19775,1,1192712758,'Ślub1.JPG');
INSERT INTO `drupal_files` VALUES (155,164,'Tort.png','sites/default/files/tort_189.png','image/x-png',166798,1,1194716950,'Tort.png');
INSERT INTO `drupal_files` VALUES (156,164,'Tort SKND dla Kasi i Kamila.jpg','sites/default/files/tort_sknd_dla_kasi_i_kamila_214.jpg','image/pjpeg',108525,1,1194716916,'Tort SKND dla Kasi i Kamila.jpg');
INSERT INTO `drupal_files` VALUES (157,138,'06_02_17_Feedback sheet - szkolenie_murb.zip','sites/default/files/06_02_17_feedback_sheet__szkolenie_murb_203.zip','application/zip',11679,1,1197107015,'06_02_17_Feedback sheet - szkolenie_murb.zip');
INSERT INTO `drupal_files` VALUES (158,138,'logo-grantow_pkuc.jpg','sites/default/files/logo_grantow_pkuc_180.jpg','image/jpeg',255605,1,1194028537,'logo-grantow_pkuc.jpg');
INSERT INTO `drupal_files` VALUES (159,159,'GG_DzS.JPG','sites/default/files/gg_dzs_191.jpg','image/jpeg',64101,1,1206800307,'GG_DzS.JPG');
INSERT INTO `drupal_files` VALUES (160,150,'bomba_przyszlosc.jpg','sites/default/files/bomba_przyszlosc_811.jpg','image/jpeg',107925,1,1194382829,'bomba_przyszlosc.jpg');
INSERT INTO `drupal_files` VALUES (161,152,'Michał Durski.jpg','sites/default/files/micha_durski_283.jpg','image/jpeg',5168,1,1194793531,'Michał Durski.jpg');
INSERT INTO `drupal_files` VALUES (162,152,'Wojtek Walniczek.jpg','sites/default/files/wojtek_walniczek_125.jpg','image/jpeg',6264,1,1194793518,'Wojtek Walniczek.jpg');
INSERT INTO `drupal_files` VALUES (163,152,'Michał Płotnicki.jpg','sites/default/files/micha_potnicki_115.jpg','image/jpeg',30379,1,1194793293,'Michał Płotnicki.jpg');
INSERT INTO `drupal_files` VALUES (164,152,'Patrycja Łucka.jpg','sites/default/files/patrycja_ucka_142.jpg','image/jpeg',70058,1,1194793280,'Patrycja Łucka.jpg');
INSERT INTO `drupal_files` VALUES (165,152,'Beata Kazimierczak.jpg','sites/default/files/beata_kazimierczak_733.jpg','image/jpeg',6653,1,1194793134,'Beata Kazimierczak.jpg');
INSERT INTO `drupal_files` VALUES (239,257,'legia.gif','sites/default/files/legia_110.gif','image/gif',1804,1,1195920425,'legia.gif');
INSERT INTO `drupal_files` VALUES (238,159,'lans.jpg','sites/default/files/lans_137.jpg','image/jpeg',193890,1,1225805104,'lans.jpg');
INSERT INTO `drupal_files` VALUES (234,152,'Mateusz Frukacz.jpg','sites/default/files/mateusz_frukacz_335.jpg','image/jpeg',3835,1,1204802661,'Mateusz Frukacz.jpg');
INSERT INTO `drupal_files` VALUES (235,152,'Damian Węgrzynowski.jpg','sites/default/files/damian_wgrzynowski_953.jpg','image/jpeg',3785,1,1204802639,'Damian Węgrzynowski.jpg');
INSERT INTO `drupal_files` VALUES (236,152,'Kuba Kessler.jpg','sites/default/files/kuba_kessler_809.jpg','image/jpeg',4280,1,1204802625,'Kuba Kessler.jpg');
INSERT INTO `drupal_files` VALUES (237,161,'Obraz 016.jpg','sites/default/files/obraz_016_131.jpg','image/pjpeg',33743,1,1206138372,'Obraz 016.jpg');
INSERT INTO `drupal_files` VALUES (241,147,'Obraz 106.jpg','sites/default/files/obraz_106_373.jpg','image/jpeg',113443,1,1202945729,'Obraz 106.jpg');
INSERT INTO `drupal_files` VALUES (240,147,'Zdjęcie030.jpg','sites/default/files/zdjcie030_430.jpg','image/jpeg',283156,1,1205176359,'Zdjęcie030.jpg');
INSERT INTO `drupal_files` VALUES (242,147,'Obraz 108.jpg','sites/default/files/obraz_108_301.jpg','image/jpeg',81100,1,1202945696,'Obraz 108.jpg');
INSERT INTO `drupal_files` VALUES (243,147,'Obraz 087.jpg','sites/default/files/obraz_087_323.jpg','image/jpeg',48123,1,1202945658,'Obraz 087.jpg');
INSERT INTO `drupal_files` VALUES (244,147,'Obraz 085.jpg','sites/default/files/obraz_085_212.jpg','image/jpeg',52694,1,1202945650,'Obraz 085.jpg');
INSERT INTO `drupal_files` VALUES (245,134,'Bowling Team.JPG','sites/default/files/bowling_team_744.jpg','image/jpeg',166259,1,1203030613,'Bowling Team.JPG');
INSERT INTO `drupal_files` VALUES (246,134,'DSCN9787.JPG','sites/default/files/dscn9787_179.jpg','image/jpeg',144826,1,1203029370,'DSCN9787.JPG');
INSERT INTO `drupal_files` VALUES (247,134,'DSCN9768.JPG','sites/default/files/dscn9768_165.jpg','image/jpeg',177992,1,1203029181,'DSCN9768.JPG');
INSERT INTO `drupal_files` VALUES (248,134,'plan.jpg','sites/default/files/plan_755.jpg','image/jpeg',42000,1,1214590627,'plan.jpg');
INSERT INTO `drupal_files` VALUES (249,134,'3.JPG','sites/default/files/3_160.jpg','image/jpeg',13670,1,1218034361,'3.JPG');
INSERT INTO `drupal_files` VALUES (250,134,'2.JPG','sites/default/files/2_120.jpg','image/jpeg',14110,1,1218034355,'2.JPG');
INSERT INTO `drupal_files` VALUES (251,134,'1.JPG','sites/default/files/1_744.jpg','image/jpeg',8263,1,1218034339,'1.JPG');
INSERT INTO `drupal_files` VALUES (252,154,'forum1.jpg','sites/default/files/forum1_252.jpg','image/jpeg',273870,1,1206119049,'forum1.jpg');
INSERT INTO `drupal_files` VALUES (253,154,'forum2.jpg','sites/default/files/forum2_131.jpg','image/jpeg',251558,1,1206119022,'forum2.jpg');
INSERT INTO `drupal_files` VALUES (254,154,'forum3.jpg','sites/default/files/forum3_200.jpg','image/jpeg',255599,1,1206118987,'forum3.jpg');
INSERT INTO `drupal_files` VALUES (255,154,'forum4.jpg','sites/default/files/forum4_104.jpg','image/jpeg',385170,1,1206118953,'forum4.jpg');
INSERT INTO `drupal_files` VALUES (256,154,'forum5.jpg','sites/default/files/forum5_135.jpg','image/jpeg',290897,1,1206118861,'forum5.jpg');
INSERT INTO `drupal_files` VALUES (257,145,'Zdjęcie001.jpg','sites/default/files/zdjcie001_197.jpg','image/pjpeg',127560,1,1206719105,'Zdjęcie001.jpg');
INSERT INTO `drupal_files` VALUES (258,159,'herbatka-u-Bartka.jpg','sites/default/files/herbatka_u_bartka_700.jpg','image/jpeg',327643,1,1206139797,'herbatka-u-Bartka.jpg');
INSERT INTO `drupal_files` VALUES (259,154,'DSC000041.jpg','sites/default/files/dsc000041_346.jpg','image/jpeg',145923,1,1208362881,'DSC000041.jpg');
INSERT INTO `drupal_files` VALUES (260,152,'Patrycja Łucka.jpg','sites/default/files/patrycja_ucka_778.jpg','image/jpeg',33743,1,1209764392,'Patrycja Łucka.jpg');
INSERT INTO `drupal_files` VALUES (262,206,'thecubes-itguy.jpg','sites/default/files/thecubes-itguy_0.jpg','image/jpeg',55444,1,1232301292,'thecubes-itguy.jpg');
INSERT INTO `drupal_files` VALUES (263,206,'youneedit.gif','sites/default/files/youneedit_0.gif','image/gif',387888,1,1232301751,'youneedit.gif');
INSERT INTO `drupal_files` VALUES (268,206,'09_01_29_Zarzadzanie kontami i zasobami SKND_mbas&mmik_v1.doc','sites/default/files/09_01_29_Zarzadzanie kontami i zasobami SKND_mbas&mmik_v1.doc','application/msword',105431,1,1233269491,'09_01_29_Zarzadzanie kontami i zasobami SKND_mbas&mmik_v1.doc');
INSERT INTO `drupal_files` VALUES (269,206,'09_01_29_Zarzadzanie kontami i zasobami SKND_mbas&mmik_v1.pdf','sites/default/files/09_01_29_Zarzadzanie kontami i zasobami SKND_mbas&mmik_v1.pdf','application/pdf',422445,1,1233269592,'09_01_29_Zarzadzanie kontami i zasobami SKND_mbas&mmik_v1.pdf');
INSERT INTO `drupal_files` VALUES (270,140,'EFS leaflet.pdf','sites/default/files/EFS leaflet.pdf','application/pdf',810982,1,1233487890,'EFS leaflet.pdf');
INSERT INTO `drupal_files` VALUES (304,194,'DSC03815.JPG','sites/default/files/DSC03815.JPG','image/jpeg',884404,1,1238545807,'DSC03815.JPG');
INSERT INTO `drupal_files` VALUES (311,214,'09_04_04_LISTY  MAILINGOWE  SKND_asli.doc','sites/default/files/09_04_04_LISTY  MAILINGOWE  SKND_asli.doc','application/msword',367104,1,1240573387,'09_04_04_LISTY  MAILINGOWE  SKND_asli.doc');
INSERT INTO `drupal_files` VALUES (309,134,'09_04_18_Kalendarz SKND_zmiany od kwietnia.jpg','sites/default/files/09_04_18_Kalendarz SKND_zmiany od kwietnia_0.jpg','image/jpeg',43343,1,1240061245,'09_04_18_Kalendarz SKND_zmiany od kwietnia.jpg');
INSERT INTO `drupal_files` VALUES (312,181,'PL_KNM_2009_formularz.doc','sites/default/files/PL_KNM_2009_formularz.doc','application/msword',115200,1,1240825166,'PL_KNM_2009_formularz.doc');
INSERT INTO `drupal_files` VALUES (316,161,'Ada  Siłakiewicz.JPG','sites/default/files/Ada  Siłakiewicz.JPG','image/jpeg',52011,1,1241721996,'Ada  Siłakiewicz.JPG');
INSERT INTO `drupal_files` VALUES (317,161,'Beata Kazimierczak.jpg','sites/default/files/Beata Kazimierczak.jpg','image/jpeg',30342,1,1241722081,'Beata Kazimierczak.jpg');
INSERT INTO `drupal_files` VALUES (318,161,'Jagoda Podraza.JPG','sites/default/files/Jagoda Podraza.JPG','image/jpeg',3813,1,1241722587,'Jagoda Podraza.JPG');
INSERT INTO `drupal_files` VALUES (320,161,'Marek Stanisławski - 05.2009.JPG','sites/default/files/Marek Stanisławski - 05.2009.JPG','image/jpeg',9064,1,1242507079,'Marek Stanisławski - 05.2009.JPG');
INSERT INTO `drupal_files` VALUES (325,267,'Ogloszenie Ambasador 2010.ppt','sites/default/files/Ogloszenie Ambasador 2010.ppt','application/vnd.ms-powerpoint',1297408,1,1244784736,'Ogloszenie Ambasador 2010.ppt');
INSERT INTO `drupal_files` VALUES (347,206,'cognitis.jpg','sites/default/files/cognitis.jpg','image/jpeg',211059,1,1263071529,'cognitis.jpg');
INSERT INTO `drupal_files` VALUES (354,1,'09_10_11_Baska_Mateusz_Aplikacja_na_Koordynatora_ds_IT_mbas.pdf','sites/default/files/applications/20092010/koordynator-ds-it/mateusz-baska/xxiv-walne-zebranie/09_10_11_Baska_Mateusz_Aplikacja_na_Koordynatora_ds_IT_mbas.pdf','application/pdf',362574,1,1268913558,'09_10_11_Baska_Mateusz_Aplikacja_na_Koordynatora_ds_IT_mbas.pdf');
INSERT INTO `drupal_files` VALUES (360,206,'zasady.gif','sites/default/files/attachments/public_page/1276/zasady_1.gif','image/gif',25380,1,1273247778,'zasady.gif');
INSERT INTO `drupal_files` VALUES (357,146,'ulotka_KWoR.jpg','sites/default/files/ulotka_KWoR_0.jpg','image/jpeg',240016,1,1271254906,'');
INSERT INTO `drupal_files` VALUES (366,277,'A_T__Kearney_Internship____Ad_Template_Aug2010.ppt','sites/default/files/A_T__Kearney_Internship____Ad_Template_Aug2010.ppt','application/vnd.ms-powerpoint',201728,1,1282334765,'');
/*!40000 ALTER TABLE `drupal_files` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

