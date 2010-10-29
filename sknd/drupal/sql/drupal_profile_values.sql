
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
DROP TABLE IF EXISTS `drupal_profile_values`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_profile_values` (
  `fid` int(10) unsigned NOT NULL default '0',
  `uid` int(10) unsigned NOT NULL default '0',
  `value` text,
  PRIMARY KEY  (`uid`,`fid`),
  KEY `fid` (`fid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_profile_values` WRITE;
/*!40000 ALTER TABLE `drupal_profile_values` DISABLE KEYS */;
INSERT INTO `drupal_profile_values` VALUES (8,206,'Marcin');
INSERT INTO `drupal_profile_values` VALUES (9,206,'Mikołajczak');
INSERT INTO `drupal_profile_values` VALUES (8,178,'Jakub');
INSERT INTO `drupal_profile_values` VALUES (9,178,'Brzozowski');
INSERT INTO `drupal_profile_values` VALUES (8,325,'Karolina');
INSERT INTO `drupal_profile_values` VALUES (9,202,'Siłakiewicz');
INSERT INTO `drupal_profile_values` VALUES (8,133,'Marek');
INSERT INTO `drupal_profile_values` VALUES (9,133,'Nadra');
INSERT INTO `drupal_profile_values` VALUES (8,134,'Aleksadnra');
INSERT INTO `drupal_profile_values` VALUES (9,134,'Dettlaff');
INSERT INTO `drupal_profile_values` VALUES (8,146,'Agata');
INSERT INTO `drupal_profile_values` VALUES (9,146,'Zabiega');
INSERT INTO `drupal_profile_values` VALUES (8,227,'Paweł');
INSERT INTO `drupal_profile_values` VALUES (9,227,'Elbanowski');
INSERT INTO `drupal_profile_values` VALUES (8,166,'Bartosz');
INSERT INTO `drupal_profile_values` VALUES (9,166,'Szablewski');
INSERT INTO `drupal_profile_values` VALUES (8,261,'Wojciech');
INSERT INTO `drupal_profile_values` VALUES (9,261,'Biniecki');
INSERT INTO `drupal_profile_values` VALUES (8,233,'Piotr');
INSERT INTO `drupal_profile_values` VALUES (9,233,'Krzoska');
INSERT INTO `drupal_profile_values` VALUES (8,201,'Ewelina');
INSERT INTO `drupal_profile_values` VALUES (9,201,'Siudowska');
INSERT INTO `drupal_profile_values` VALUES (8,140,'Alicja');
INSERT INTO `drupal_profile_values` VALUES (9,140,'Staniuk');
INSERT INTO `drupal_profile_values` VALUES (8,142,'Anna');
INSERT INTO `drupal_profile_values` VALUES (9,142,'Pomin');
INSERT INTO `drupal_profile_values` VALUES (8,181,'Mateusz');
INSERT INTO `drupal_profile_values` VALUES (9,181,'Matłoka');
INSERT INTO `drupal_profile_values` VALUES (8,199,'Alicja');
INSERT INTO `drupal_profile_values` VALUES (9,199,'Głowacka');
INSERT INTO `drupal_profile_values` VALUES (8,152,'Magdalena');
INSERT INTO `drupal_profile_values` VALUES (9,152,'Przeździak');
INSERT INTO `drupal_profile_values` VALUES (8,217,'Aleksandra');
INSERT INTO `drupal_profile_values` VALUES (9,217,'Szymańska');
INSERT INTO `drupal_profile_values` VALUES (8,161,'Patrycja');
INSERT INTO `drupal_profile_values` VALUES (9,161,'Łucka');
INSERT INTO `drupal_profile_values` VALUES (8,262,'Marcin');
INSERT INTO `drupal_profile_values` VALUES (9,262,'Kaczmarek');
INSERT INTO `drupal_profile_values` VALUES (8,198,'Aleksandra');
INSERT INTO `drupal_profile_values` VALUES (9,198,'Dudkowiak');
INSERT INTO `drupal_profile_values` VALUES (8,182,'Dawid');
INSERT INTO `drupal_profile_values` VALUES (9,182,'Trojanowski');
INSERT INTO `drupal_profile_values` VALUES (8,143,'Mateusz');
INSERT INTO `drupal_profile_values` VALUES (9,143,'Łakomy');
INSERT INTO `drupal_profile_values` VALUES (8,237,'Tomasz');
INSERT INTO `drupal_profile_values` VALUES (9,237,'Karbowiak');
INSERT INTO `drupal_profile_values` VALUES (8,189,'Marcin ');
INSERT INTO `drupal_profile_values` VALUES (9,189,'Waligóra');
INSERT INTO `drupal_profile_values` VALUES (8,145,'Leszek');
INSERT INTO `drupal_profile_values` VALUES (9,145,'Bogucki');
INSERT INTO `drupal_profile_values` VALUES (8,158,'Maria');
INSERT INTO `drupal_profile_values` VALUES (9,158,'Urbanek');
INSERT INTO `drupal_profile_values` VALUES (8,247,'Mateusz');
INSERT INTO `drupal_profile_values` VALUES (9,247,'Bąska');
INSERT INTO `drupal_profile_values` VALUES (8,269,'Agnieszka');
INSERT INTO `drupal_profile_values` VALUES (9,269,'Waliszewska');
INSERT INTO `drupal_profile_values` VALUES (8,230,'Jakub');
INSERT INTO `drupal_profile_values` VALUES (9,230,'Sędziak');
INSERT INTO `drupal_profile_values` VALUES (8,265,'Katarzyna');
INSERT INTO `drupal_profile_values` VALUES (9,265,'Adamiak');
INSERT INTO `drupal_profile_values` VALUES (8,232,'Ewelina');
INSERT INTO `drupal_profile_values` VALUES (9,232,'Anbild');
INSERT INTO `drupal_profile_values` VALUES (8,151,'Piotr');
INSERT INTO `drupal_profile_values` VALUES (9,151,'Kwiotek');
INSERT INTO `drupal_profile_values` VALUES (8,164,'Tomasz P.');
INSERT INTO `drupal_profile_values` VALUES (9,164,'Antoszek');
INSERT INTO `drupal_profile_values` VALUES (8,270,'');
INSERT INTO `drupal_profile_values` VALUES (9,270,'');
INSERT INTO `drupal_profile_values` VALUES (8,271,'');
INSERT INTO `drupal_profile_values` VALUES (9,271,'');
INSERT INTO `drupal_profile_values` VALUES (8,273,'');
INSERT INTO `drupal_profile_values` VALUES (9,273,'');
INSERT INTO `drupal_profile_values` VALUES (8,274,'');
INSERT INTO `drupal_profile_values` VALUES (9,274,'');
INSERT INTO `drupal_profile_values` VALUES (8,275,'Michał');
INSERT INTO `drupal_profile_values` VALUES (9,275,'Ciołek');
INSERT INTO `drupal_profile_values` VALUES (8,276,'Krzysztof ');
INSERT INTO `drupal_profile_values` VALUES (9,276,'Wróblewski');
INSERT INTO `drupal_profile_values` VALUES (8,277,'');
INSERT INTO `drupal_profile_values` VALUES (9,277,'');
INSERT INTO `drupal_profile_values` VALUES (8,278,'');
INSERT INTO `drupal_profile_values` VALUES (9,278,'');
INSERT INTO `drupal_profile_values` VALUES (8,279,'');
INSERT INTO `drupal_profile_values` VALUES (9,279,'');
INSERT INTO `drupal_profile_values` VALUES (8,280,'Filip');
INSERT INTO `drupal_profile_values` VALUES (9,280,'Dominiak');
INSERT INTO `drupal_profile_values` VALUES (8,281,'Karolina');
INSERT INTO `drupal_profile_values` VALUES (9,281,'Lenarczyk');
INSERT INTO `drupal_profile_values` VALUES (8,282,'');
INSERT INTO `drupal_profile_values` VALUES (9,282,'');
INSERT INTO `drupal_profile_values` VALUES (8,283,'');
INSERT INTO `drupal_profile_values` VALUES (9,283,'');
INSERT INTO `drupal_profile_values` VALUES (8,284,'Aleksandra');
INSERT INTO `drupal_profile_values` VALUES (9,284,'Berlinska');
INSERT INTO `drupal_profile_values` VALUES (8,285,'');
INSERT INTO `drupal_profile_values` VALUES (9,285,'');
INSERT INTO `drupal_profile_values` VALUES (8,286,'');
INSERT INTO `drupal_profile_values` VALUES (9,286,'');
INSERT INTO `drupal_profile_values` VALUES (8,287,'Bartosz');
INSERT INTO `drupal_profile_values` VALUES (9,287,'Stosik');
INSERT INTO `drupal_profile_values` VALUES (8,288,'');
INSERT INTO `drupal_profile_values` VALUES (9,288,'');
INSERT INTO `drupal_profile_values` VALUES (8,289,'');
INSERT INTO `drupal_profile_values` VALUES (9,289,'');
INSERT INTO `drupal_profile_values` VALUES (8,290,'');
INSERT INTO `drupal_profile_values` VALUES (9,290,'');
INSERT INTO `drupal_profile_values` VALUES (8,291,'');
INSERT INTO `drupal_profile_values` VALUES (9,291,'');
INSERT INTO `drupal_profile_values` VALUES (8,292,'');
INSERT INTO `drupal_profile_values` VALUES (9,292,'');
INSERT INTO `drupal_profile_values` VALUES (8,293,'');
INSERT INTO `drupal_profile_values` VALUES (9,293,'');
INSERT INTO `drupal_profile_values` VALUES (8,294,'');
INSERT INTO `drupal_profile_values` VALUES (9,294,'');
INSERT INTO `drupal_profile_values` VALUES (8,295,'Wojtek');
INSERT INTO `drupal_profile_values` VALUES (9,295,'Orchowski');
INSERT INTO `drupal_profile_values` VALUES (8,296,'');
INSERT INTO `drupal_profile_values` VALUES (9,296,'');
INSERT INTO `drupal_profile_values` VALUES (8,297,'');
INSERT INTO `drupal_profile_values` VALUES (9,297,'');
INSERT INTO `drupal_profile_values` VALUES (8,298,'Wojciech');
INSERT INTO `drupal_profile_values` VALUES (9,298,'Dudziak');
INSERT INTO `drupal_profile_values` VALUES (8,299,'');
INSERT INTO `drupal_profile_values` VALUES (9,299,'');
INSERT INTO `drupal_profile_values` VALUES (8,300,'');
INSERT INTO `drupal_profile_values` VALUES (9,300,'');
INSERT INTO `drupal_profile_values` VALUES (8,301,'');
INSERT INTO `drupal_profile_values` VALUES (9,301,'');
INSERT INTO `drupal_profile_values` VALUES (8,302,'Sandra');
INSERT INTO `drupal_profile_values` VALUES (9,302,'Gali');
INSERT INTO `drupal_profile_values` VALUES (8,303,'Szymon');
INSERT INTO `drupal_profile_values` VALUES (9,303,'Jordan');
INSERT INTO `drupal_profile_values` VALUES (8,304,'');
INSERT INTO `drupal_profile_values` VALUES (9,304,'');
INSERT INTO `drupal_profile_values` VALUES (8,305,'');
INSERT INTO `drupal_profile_values` VALUES (9,305,'');
INSERT INTO `drupal_profile_values` VALUES (8,306,'');
INSERT INTO `drupal_profile_values` VALUES (9,306,'');
INSERT INTO `drupal_profile_values` VALUES (8,307,'');
INSERT INTO `drupal_profile_values` VALUES (9,307,'');
INSERT INTO `drupal_profile_values` VALUES (8,308,'');
INSERT INTO `drupal_profile_values` VALUES (9,308,'');
INSERT INTO `drupal_profile_values` VALUES (8,309,'');
INSERT INTO `drupal_profile_values` VALUES (9,309,'');
INSERT INTO `drupal_profile_values` VALUES (8,310,'');
INSERT INTO `drupal_profile_values` VALUES (9,310,'');
INSERT INTO `drupal_profile_values` VALUES (8,311,'');
INSERT INTO `drupal_profile_values` VALUES (9,311,'');
INSERT INTO `drupal_profile_values` VALUES (8,312,'');
INSERT INTO `drupal_profile_values` VALUES (9,312,'');
INSERT INTO `drupal_profile_values` VALUES (8,313,'');
INSERT INTO `drupal_profile_values` VALUES (9,313,'');
INSERT INTO `drupal_profile_values` VALUES (8,314,'Karolina');
INSERT INTO `drupal_profile_values` VALUES (9,314,'Sroka');
INSERT INTO `drupal_profile_values` VALUES (8,315,'');
INSERT INTO `drupal_profile_values` VALUES (9,315,'');
INSERT INTO `drupal_profile_values` VALUES (8,316,'');
INSERT INTO `drupal_profile_values` VALUES (9,316,'');
INSERT INTO `drupal_profile_values` VALUES (8,183,'Maciej');
INSERT INTO `drupal_profile_values` VALUES (9,183,'Popkowski');
INSERT INTO `drupal_profile_values` VALUES (8,188,'Kamil');
INSERT INTO `drupal_profile_values` VALUES (9,188,'Puk');
INSERT INTO `drupal_profile_values` VALUES (8,241,'Joanna ');
INSERT INTO `drupal_profile_values` VALUES (9,241,'Kalinowska');
INSERT INTO `drupal_profile_values` VALUES (8,144,'Natalia');
INSERT INTO `drupal_profile_values` VALUES (9,144,'Słocińska');
INSERT INTO `drupal_profile_values` VALUES (8,214,'Anna');
INSERT INTO `drupal_profile_values` VALUES (9,214,'Śliwińska');
INSERT INTO `drupal_profile_values` VALUES (8,236,'Patrycja');
INSERT INTO `drupal_profile_values` VALUES (9,236,'Ziemblińska');
INSERT INTO `drupal_profile_values` VALUES (8,157,'Zbyszek ');
INSERT INTO `drupal_profile_values` VALUES (9,157,'Jędrzejczyk');
INSERT INTO `drupal_profile_values` VALUES (8,159,'Bartosz');
INSERT INTO `drupal_profile_values` VALUES (9,159,'Kobus');
INSERT INTO `drupal_profile_values` VALUES (8,209,'Anna');
INSERT INTO `drupal_profile_values` VALUES (9,209,'Konopelko');
INSERT INTO `drupal_profile_values` VALUES (8,264,'Katarzyna');
INSERT INTO `drupal_profile_values` VALUES (9,264,'Szatkowska');
INSERT INTO `drupal_profile_values` VALUES (8,266,'Monika');
INSERT INTO `drupal_profile_values` VALUES (9,266,'Klebusz');
INSERT INTO `drupal_profile_values` VALUES (8,184,'Piotr');
INSERT INTO `drupal_profile_values` VALUES (9,184,'Mieszała');
INSERT INTO `drupal_profile_values` VALUES (8,167,'Beata');
INSERT INTO `drupal_profile_values` VALUES (9,167,'Kazimierczak');
INSERT INTO `drupal_profile_values` VALUES (8,194,'Wojciech');
INSERT INTO `drupal_profile_values` VALUES (9,194,'Goraczniak');
INSERT INTO `drupal_profile_values` VALUES (8,228,'Julian');
INSERT INTO `drupal_profile_values` VALUES (9,228,'Dabrowski');
INSERT INTO `drupal_profile_values` VALUES (8,246,'Aleksandra');
INSERT INTO `drupal_profile_values` VALUES (9,246,'Kowalczuk');
INSERT INTO `drupal_profile_values` VALUES (8,272,'Natalia');
INSERT INTO `drupal_profile_values` VALUES (9,272,'Szpera');
INSERT INTO `drupal_profile_values` VALUES (8,317,'');
INSERT INTO `drupal_profile_values` VALUES (9,317,'');
INSERT INTO `drupal_profile_values` VALUES (8,318,'Radosław');
INSERT INTO `drupal_profile_values` VALUES (9,318,'Małek');
INSERT INTO `drupal_profile_values` VALUES (8,319,'Jeremiasz');
INSERT INTO `drupal_profile_values` VALUES (9,319,'Koper');
INSERT INTO `drupal_profile_values` VALUES (8,320,'Karolina');
INSERT INTO `drupal_profile_values` VALUES (9,320,'Lubiejewska');
INSERT INTO `drupal_profile_values` VALUES (8,321,'');
INSERT INTO `drupal_profile_values` VALUES (9,321,'');
INSERT INTO `drupal_profile_values` VALUES (8,322,'Piotr');
INSERT INTO `drupal_profile_values` VALUES (9,322,'Krużyński');
INSERT INTO `drupal_profile_values` VALUES (8,323,'');
INSERT INTO `drupal_profile_values` VALUES (9,323,'');
INSERT INTO `drupal_profile_values` VALUES (8,324,'');
INSERT INTO `drupal_profile_values` VALUES (9,324,'');
INSERT INTO `drupal_profile_values` VALUES (8,326,'');
INSERT INTO `drupal_profile_values` VALUES (9,326,'');
INSERT INTO `drupal_profile_values` VALUES (8,238,'Jędrzej');
INSERT INTO `drupal_profile_values` VALUES (9,238,'Jakubowski');
INSERT INTO `drupal_profile_values` VALUES (8,203,'Agnieszka');
INSERT INTO `drupal_profile_values` VALUES (9,203,'Zmysłowska');
INSERT INTO `drupal_profile_values` VALUES (10,206,'');
INSERT INTO `drupal_profile_values` VALUES (11,206,'0');
INSERT INTO `drupal_profile_values` VALUES (12,206,'0');
INSERT INTO `drupal_profile_values` VALUES (13,206,'0');
INSERT INTO `drupal_profile_values` VALUES (10,280,'');
INSERT INTO `drupal_profile_values` VALUES (11,280,'0');
INSERT INTO `drupal_profile_values` VALUES (12,280,'0');
INSERT INTO `drupal_profile_values` VALUES (13,280,'0');
INSERT INTO `drupal_profile_values` VALUES (10,281,'');
INSERT INTO `drupal_profile_values` VALUES (11,281,'0');
INSERT INTO `drupal_profile_values` VALUES (12,281,'0');
INSERT INTO `drupal_profile_values` VALUES (13,281,'0');
INSERT INTO `drupal_profile_values` VALUES (10,247,'');
INSERT INTO `drupal_profile_values` VALUES (11,247,'0');
INSERT INTO `drupal_profile_values` VALUES (12,247,'0');
INSERT INTO `drupal_profile_values` VALUES (13,247,'0');
INSERT INTO `drupal_profile_values` VALUES (10,201,'');
INSERT INTO `drupal_profile_values` VALUES (11,201,'0');
INSERT INTO `drupal_profile_values` VALUES (12,201,'0');
INSERT INTO `drupal_profile_values` VALUES (13,201,'0');
INSERT INTO `drupal_profile_values` VALUES (10,188,'');
INSERT INTO `drupal_profile_values` VALUES (11,188,'0');
INSERT INTO `drupal_profile_values` VALUES (12,188,'0');
INSERT INTO `drupal_profile_values` VALUES (13,188,'0');
INSERT INTO `drupal_profile_values` VALUES (10,181,'');
INSERT INTO `drupal_profile_values` VALUES (11,181,'0');
INSERT INTO `drupal_profile_values` VALUES (12,181,'0');
INSERT INTO `drupal_profile_values` VALUES (13,181,'0');
INSERT INTO `drupal_profile_values` VALUES (10,319,'');
INSERT INTO `drupal_profile_values` VALUES (11,319,'0');
INSERT INTO `drupal_profile_values` VALUES (12,319,'0');
INSERT INTO `drupal_profile_values` VALUES (13,319,'0');
INSERT INTO `drupal_profile_values` VALUES (10,320,'');
INSERT INTO `drupal_profile_values` VALUES (11,320,'0');
INSERT INTO `drupal_profile_values` VALUES (12,320,'0');
INSERT INTO `drupal_profile_values` VALUES (13,320,'0');
INSERT INTO `drupal_profile_values` VALUES (8,202,'Ada');
INSERT INTO `drupal_profile_values` VALUES (10,202,'');
INSERT INTO `drupal_profile_values` VALUES (11,202,'0');
INSERT INTO `drupal_profile_values` VALUES (12,202,'0');
INSERT INTO `drupal_profile_values` VALUES (13,202,'0');
INSERT INTO `drupal_profile_values` VALUES (9,325,'Marciniec');
INSERT INTO `drupal_profile_values` VALUES (10,325,'');
INSERT INTO `drupal_profile_values` VALUES (11,325,'0');
INSERT INTO `drupal_profile_values` VALUES (12,325,'0');
INSERT INTO `drupal_profile_values` VALUES (13,325,'0');
INSERT INTO `drupal_profile_values` VALUES (10,295,'');
INSERT INTO `drupal_profile_values` VALUES (11,295,'0');
INSERT INTO `drupal_profile_values` VALUES (12,295,'0');
INSERT INTO `drupal_profile_values` VALUES (13,295,'0');
INSERT INTO `drupal_profile_values` VALUES (8,245,'Katarzyna');
INSERT INTO `drupal_profile_values` VALUES (9,245,'Zabłocka');
INSERT INTO `drupal_profile_values` VALUES (10,245,'');
INSERT INTO `drupal_profile_values` VALUES (11,245,'0');
INSERT INTO `drupal_profile_values` VALUES (12,245,'0');
INSERT INTO `drupal_profile_values` VALUES (13,245,'0');
INSERT INTO `drupal_profile_values` VALUES (10,318,'');
INSERT INTO `drupal_profile_values` VALUES (11,318,'0');
INSERT INTO `drupal_profile_values` VALUES (12,318,'0');
INSERT INTO `drupal_profile_values` VALUES (13,318,'0');
INSERT INTO `drupal_profile_values` VALUES (10,298,'');
INSERT INTO `drupal_profile_values` VALUES (11,298,'0');
INSERT INTO `drupal_profile_values` VALUES (12,298,'0');
INSERT INTO `drupal_profile_values` VALUES (13,298,'0');
INSERT INTO `drupal_profile_values` VALUES (10,246,'');
INSERT INTO `drupal_profile_values` VALUES (11,246,'0');
INSERT INTO `drupal_profile_values` VALUES (12,246,'0');
INSERT INTO `drupal_profile_values` VALUES (13,246,'0');
/*!40000 ALTER TABLE `drupal_profile_values` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

