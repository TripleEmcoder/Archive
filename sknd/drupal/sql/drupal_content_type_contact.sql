
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
DROP TABLE IF EXISTS `drupal_content_type_contact`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_content_type_contact` (
  `vid` int(10) unsigned NOT NULL default '0',
  `nid` int(10) unsigned NOT NULL default '0',
  `field_department_name_value` longtext,
  `field_contact_name_value` longtext,
  `field_contact_email_address_email` varchar(255) default NULL,
  `field_contact_phone_number_value` longtext,
  `field_contact_position_value` longtext,
  `field_company_reference_nid` int(10) unsigned default NULL,
  PRIMARY KEY  (`vid`),
  KEY `nid` (`nid`),
  KEY `field_company_reference_nid` (`field_company_reference_nid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_content_type_contact` WRITE;
/*!40000 ALTER TABLE `drupal_content_type_contact` DISABLE KEYS */;
INSERT INTO `drupal_content_type_contact` VALUES (1228,1226,'marketing','Radosław Rakowski','radek@ksks.pl','5555555555555',NULL,1221);
INSERT INTO `drupal_content_type_contact` VALUES (1402,1399,NULL,'Agnieszka Fiutak','agnieszka.fiutak@beck.pl',NULL,'Redaktor naczelna',1398);
INSERT INTO `drupal_content_type_contact` VALUES (1404,1401,NULL,'Dariusz Wajs','redakcja@feniksmedia.pl','257 01 51','Redaktor naczelny',1400);
INSERT INTO `drupal_content_type_contact` VALUES (1405,1402,NULL,'Małgorzata Hinc','malgorzata.hinc@eurostudent.pl','48 (12) 257 32 21; 600 064 705','Patronaty medialne',1400);
INSERT INTO `drupal_content_type_contact` VALUES (1407,1404,'Redakcja','Włodzimierz Bogaczyk','wlodzimierz.bogaczyk@poznan.agora.pl','61 855 22 33','Redaktor',1403);
INSERT INTO `drupal_content_type_contact` VALUES (1408,1405,'Redakcja','Natalia Mazur','natalia.mazur@poznan.agora.pl',NULL,'Szkoły wyższe',1403);
INSERT INTO `drupal_content_type_contact` VALUES (1410,1407,'Redakcja','Adam Pawłowski ','redakcja@glos.com',NULL,'Redaktor',1406);
INSERT INTO `drupal_content_type_contact` VALUES (1411,1408,'Dział Poznań','Bartosz Trzebiatowski ','b.trzebiatowski@glos.com','61 869-42-57 ','Redaktor',1406);
INSERT INTO `drupal_content_type_contact` VALUES (1412,1409,'Redakcja','Anna Burchard',NULL,'618694188','Patronaty medialne',1406);
INSERT INTO `drupal_content_type_contact` VALUES (1414,1411,NULL,'Joanna Kusy','joanna.kusy@kariera.com.pl','12 267 89 00',NULL,1410);
INSERT INTO `drupal_content_type_contact` VALUES (1416,1413,'Edukacja/nauka','Marcelina Szumer','marcelina.szumer@agora.pl','22 555 50 26','Redaktor',1412);
INSERT INTO `drupal_content_type_contact` VALUES (1417,1414,'Poznań','Jacek Bojarski','jacek.bojarski@poznan.agora.pl','61 85 89 270','Redaktor',1412);
INSERT INTO `drupal_content_type_contact` VALUES (1419,1416,'Redakcja','Bianka Siwińska','b.siwinska@perspektywy.pl',NULL,'Redaktor',1415);
INSERT INTO `drupal_content_type_contact` VALUES (1422,1419,'Redakcja','Katarzyna Antoniak','k.antoniak@poczta.fm',NULL,'Redaktor naczelna',1418);
INSERT INTO `drupal_content_type_contact` VALUES (1423,1420,'Redakcja','Karolina But','karolinabut@wp.pl','507981138','Z-ca redaktor naczelnej',1418);
INSERT INTO `drupal_content_type_contact` VALUES (1424,1421,'Marketing','Aleksander Kutnik',NULL,NULL,'Marketingowiec',1418);
INSERT INTO `drupal_content_type_contact` VALUES (1426,1423,'Redakcja','Krzysztof Szczepaniak','redakcja@dlaczego.korba.pl','225722000','Redaktor',1422);
INSERT INTO `drupal_content_type_contact` VALUES (1428,1425,'PR','Grażyna Jancik','gj@feniksmedia.pl','12 263 06 21','PR-owiec',1424);
INSERT INTO `drupal_content_type_contact` VALUES (1430,1427,'Dział Poznań','Joanna Lisiecka','poznan@podprad.pl','663 22 44 62','Redaktor',1426);
INSERT INTO `drupal_content_type_contact` VALUES (1431,1428,'Redakcja','Katarzyna Michałowska','naczelna@podprad.pl','58 710-82-54','Redaktor naczelna',1426);
INSERT INTO `drupal_content_type_contact` VALUES (1432,1429,'Dział Warszawa','Anita Niemczyk','a.niemczyk@podprad.pl','663224480','Redaktor',1426);
INSERT INTO `drupal_content_type_contact` VALUES (1434,1431,'Redakcja','Anna Paluch',NULL,'12 263 06 21','Redaktor',1430);
INSERT INTO `drupal_content_type_contact` VALUES (1436,1433,NULL,'Urszula Gumen-Leonarcik','pelnomocnik2007@o2.pl','692915114',NULL,1432);
INSERT INTO `drupal_content_type_contact` VALUES (1438,1435,'Redakcja','Krzysztof Jedlak','redakcja@parkiet.com','22 46 30 618','Redaktor',1434);
INSERT INTO `drupal_content_type_contact` VALUES (1439,1436,'Reklama','Adrian Grabiński','reklama@parkiet.com.pl','22 46 30 619','Reklama',1434);
INSERT INTO `drupal_content_type_contact` VALUES (1441,1438,'Redakcja','Jacek Ziarno','j.ziarno@pb.pl','223339999','Redaktor naczelny',1437);
INSERT INTO `drupal_content_type_contact` VALUES (1444,1441,'PR','Emilia Miller','best@ue.wroc.pl','71 36 80648','Redaktor',1440);
INSERT INTO `drupal_content_type_contact` VALUES (1446,1443,'Redakcja','Wiesław Małecki','redakcja@komputerswiat.pl','22 232 00 78','Redaktor',1442);
INSERT INTO `drupal_content_type_contact` VALUES (1448,1445,'Redakcja','Michał Adamczyk','michal.adamczyk@chip.pl','22 320 19 00','Redaktor',1444);
INSERT INTO `drupal_content_type_contact` VALUES (1450,1447,'Redakcja','Marcin Wyrwał','redakcja@studencka.pl','22 552 02 29','Redaktor',1446);
INSERT INTO `drupal_content_type_contact` VALUES (1452,1449,'Redakcja','Małgorzata Wieliczko','pryzmat@pwr.wroc.pl','71 320 21 17','Redaktor',1448);
INSERT INTO `drupal_content_type_contact` VALUES (1454,1451,'Redakcja','Winicjusz Schulz','glos-umk@uni.torun.pl',NULL,'Redaktor',1450);
INSERT INTO `drupal_content_type_contact` VALUES (1457,1454,'Redakcja','Kazimiera Dąbrowska','kada@adm.uni.wroc.pl','71 375 20 77, 601 739 097','Redaktor',1453);
INSERT INTO `drupal_content_type_contact` VALUES (1459,1456,'Redakcja','Ewelina Pawlus','zak_pwr@pwr.wroc.pl','71 320 40 89','Redaktor',1455);
/*!40000 ALTER TABLE `drupal_content_type_contact` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

