
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
DROP TABLE IF EXISTS `drupal_content_type_company`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_content_type_company` (
  `vid` int(10) unsigned NOT NULL default '0',
  `nid` int(10) unsigned NOT NULL default '0',
  `field_company_name_value` longtext,
  `field_company_contacts_vname` varchar(32) default NULL,
  `field_company_contacts_vargs` varchar(255) default NULL,
  `field_contact_history_value` longtext,
  `field_contact_history_format` int(10) unsigned default NULL,
  `field_company_email_address_email` varchar(255) default NULL,
  `field_company_fax_number_value` longtext,
  `field_company_postal_address_lid` int(10) unsigned default NULL,
  `field_company_phone_number_value` longtext,
  `field_company_www_address_url` varchar(255) default NULL,
  `field_company_www_address_title` varchar(255) default NULL,
  `field_company_www_address_attributes` mediumtext,
  PRIMARY KEY  (`vid`),
  KEY `nid` (`nid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_content_type_company` WRITE;
/*!40000 ALTER TABLE `drupal_content_type_company` DISABLE KEYS */;
INSERT INTO `drupal_content_type_company` VALUES (1401,1398,'Edukacja Prawnicza','<default>',NULL,'ZK 09 - patron medialny, bezproblemowa współpraca',1,NULL,'0-22 33 77 601',5,'0-22 33 77 431','www.edukacjaprawnicza.pl',NULL,NULL);
INSERT INTO `drupal_content_type_company` VALUES (1403,1400,'Eurostudent','<default>',NULL,'*prośba o zamieszczenie info o rekrutacji jes. 08 i wios. 09 - brak odp. i brak info na str.;\r\n* ZK 09 - odmowa odjęcia patronatu - na razie się wstrzymują, ale nie wyklucza to współpracy w przyszłości; należy odzywać się do nich z większym wyprzedzeniem (większym niż 1,5 miesiąca)!',1,'redakcja@feniksmedia.pl',NULL,6,'(12) 263 06 60','http://www.magazyn.eurostudent.pl',NULL,NULL);
INSERT INTO `drupal_content_type_company` VALUES (1406,1403,'Gazeta Wyborcza','<default>',NULL,NULL,NULL,'listy@poznan.agora.pl',NULL,7,NULL,'www.miasta.gazeta.pl/poznan',NULL,NULL);
INSERT INTO `drupal_content_type_company` VALUES (1409,1406,'Głos Wielkopolski','<default>',NULL,'*ZK 09 - prośba objęcia patronatem med. - osoba odpowiedzialna na urlopie, ciągłe odsyłanie, w końcu odmowa - ZK zbyt \"fachowe\", ale chętnie zamieszczą info w gazecie (info niezweryfikowane)',1,NULL,NULL,8,NULL,'http://glos.com',NULL,NULL);
INSERT INTO `drupal_content_type_company` VALUES (1413,1410,'Kariera - Informator','<default>',NULL,'dane proawdopodobnie nieaktualne',1,NULL,NULL,9,NULL,'http://kariera.com.pl',NULL,NULL);
INSERT INTO `drupal_content_type_company` VALUES (1415,1412,'Metro','<default>',NULL,NULL,NULL,NULL,NULL,10,NULL,'http://metro.gazeta.pl',NULL,NULL);
INSERT INTO `drupal_content_type_company` VALUES (1418,1415,'Perspektywy','<default>',NULL,NULL,NULL,'poczta@perspektywy.pl',NULL,0,NULL,'http://perspektywy.pl',NULL,NULL);
INSERT INTO `drupal_content_type_company` VALUES (1420,1417,'StudentNews','<default>',NULL,'istotne informacje o patronacie: http://www.studentnews.pl/serwis.php?s=207&pok=5951',1,'promocja@studentnews.pl',NULL,11,'22 747 07 00','http://studentnews.pl',NULL,NULL);
INSERT INTO `drupal_content_type_company` VALUES (1421,1418,'BrzytwAE','<default>',NULL,'*rekrutacja jesienna 2008 - artykuł zamieszczony, zmieniony, brak odpowiedzi na maile; wywiad z pkuc o konkursie E&Y Financial Challenger, pkuc przekazał kontakt do Karoliny But, tel azmy i nawiązanie współpracy -> \r\n*artykuł o Marketplace na www; należy wysyłać info o wydarzeniach na adres brzytwa@gmail; gazeta wydawana co dwa tygodnie, dostarczanie tesktów do piątku.',1,'k.antoniak@poczta.fm',NULL,12,NULL,'http://www.brzytwae.com.pl',NULL,NULL);
INSERT INTO `drupal_content_type_company` VALUES (1425,1422,'Dlaczego','<default>',NULL,NULL,NULL,NULL,NULL,13,NULL,'http://dlaczego.korba.pl',NULL,NULL);
INSERT INTO `drupal_content_type_company` VALUES (1427,1424,'Motyw','<default>',NULL,NULL,NULL,NULL,NULL,14,NULL,'http://magazynmotyw.pl',NULL,NULL);
INSERT INTO `drupal_content_type_company` VALUES (1429,1426,'Pod Prąd','<default>',NULL,NULL,NULL,NULL,NULL,15,NULL,'http://podprad.pl',NULL,NULL);
INSERT INTO `drupal_content_type_company` VALUES (1433,1430,'Semestr','<default>',NULL,'* Semestr istnieje także w Warszawie i Wrocławiu',1,NULL,'71 320-63-04',16,NULL,'http://poznan.semestr.pl',NULL,NULL);
INSERT INTO `drupal_content_type_company` VALUES (1435,1432,'Żebyś Wiedział','<default>',NULL,'*rekrutacja jesienna 2008 - artykuł o nas',1,NULL,NULL,17,NULL,'http://www.zebyswiedzial.wsb.poznan.pl/',NULL,NULL);
INSERT INTO `drupal_content_type_company` VALUES (1437,1434,'Parkiet','<default>',NULL,NULL,NULL,NULL,NULL,18,NULL,'http://parkiet.com',NULL,NULL);
INSERT INTO `drupal_content_type_company` VALUES (1440,1437,'Puls Biznesu','<default>',NULL,NULL,NULL,NULL,NULL,19,NULL,'www.pb.pl',NULL,NULL);
INSERT INTO `drupal_content_type_company` VALUES (1442,1439,'SMS','<default>',NULL,NULL,NULL,'redakcja@magazynsms.pl',NULL,20,'502499219','http://magazynsms.pl',NULL,NULL);
INSERT INTO `drupal_content_type_company` VALUES (1443,1440,'B.E.S.T.','<default>',NULL,'Gazeta studentów Uniwersytetu Ekonomicznego we Wrocławiu',1,NULL,NULL,21,NULL,'http://best.ae.wroc.pl',NULL,NULL);
INSERT INTO `drupal_content_type_company` VALUES (1445,1442,'Komputer Świat','<default>',NULL,NULL,NULL,NULL,NULL,22,NULL,NULL,NULL,NULL);
INSERT INTO `drupal_content_type_company` VALUES (1447,1444,'CHIP','<default>',NULL,NULL,NULL,NULL,NULL,23,NULL,'http://chip.pl',NULL,NULL);
INSERT INTO `drupal_content_type_company` VALUES (1449,1446,'Gazeta Studencka','<default>',NULL,NULL,NULL,NULL,NULL,24,NULL,'www.studencka.pl',NULL,NULL);
INSERT INTO `drupal_content_type_company` VALUES (1451,1448,'Pryzmat','<default>',NULL,'Wrocław - Politechnika',1,NULL,NULL,0,NULL,'http://pryzmat.pwr.wroc.pl',NULL,NULL);
INSERT INTO `drupal_content_type_company` VALUES (1453,1450,'Głos Uczelni','<default>',NULL,'UMK Toruń',1,NULL,NULL,25,NULL,'http://glos.umk.pl',NULL,NULL);
INSERT INTO `drupal_content_type_company` VALUES (1455,1452,'Życie uniwersyteckie','<default>',NULL,'UAM',1,'redakcja@amu.edu.pl',NULL,26,'61 829 3960, 3961, 3962','http://www.amu.edu.pl/index.php?linkid=159&moz=1',NULL,NULL);
INSERT INTO `drupal_content_type_company` VALUES (1456,1453,'Przegląd Uniwersytecki','<default>',NULL,'Uniwersytet Wrocławski',1,NULL,NULL,27,NULL,NULL,NULL,NULL);
INSERT INTO `drupal_content_type_company` VALUES (1458,1455,'Żak','<default>',NULL,'Wrocław - Politechnika',1,NULL,NULL,28,NULL,'http://www.zak.pwr.wroc.pl/',NULL,NULL);
/*!40000 ALTER TABLE `drupal_content_type_company` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

