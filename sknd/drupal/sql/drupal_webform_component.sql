
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
DROP TABLE IF EXISTS `drupal_webform_component`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_webform_component` (
  `nid` int(10) unsigned NOT NULL default '0',
  `cid` smallint(5) unsigned NOT NULL default '0',
  `pid` smallint(5) unsigned NOT NULL default '0',
  `form_key` varchar(128) default NULL,
  `name` varchar(255) default NULL,
  `type` varchar(16) default NULL,
  `value` text NOT NULL,
  `extra` text NOT NULL,
  `mandatory` tinyint(4) NOT NULL default '0',
  `email` tinyint(4) NOT NULL default '0',
  `weight` smallint(6) NOT NULL default '0',
  PRIMARY KEY  (`nid`,`cid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_webform_component` WRITE;
/*!40000 ALTER TABLE `drupal_webform_component` DISABLE KEYS */;
INSERT INTO `drupal_webform_component` VALUES (1718,17,13,'jakie_sa_twoje_oczekiwania_wobec_konkursu','Jakie są twoje oczekiwania wobec konkursu?','textarea','','a:6:{s:9:\"resizable\";i:1;s:8:\"disabled\";i:0;s:4:\"cols\";s:0:\"\";s:4:\"rows\";s:0:\"\";s:11:\"description\";s:0:\"\";s:10:\"attributes\";a:0:{}}',0,1,20);
INSERT INTO `drupal_webform_component` VALUES (1718,15,13,'czy_znales_kojarzyles_stowarzyszenie_cognitis_zanim_wziales_udzial_w_konkursie_nieslabosredniodobrzebardzo_dobrze','Czy znałeś, kojarzyłeś Stowarzyszenie Cognitis zanim wziąłeś udział w Konkursie? (nie/słabo/średnio/dobrze/bardzo dobrze)','textfield','','a:7:{s:8:\"disabled\";i:0;s:5:\"width\";s:0:\"\";s:9:\"maxlength\";s:0:\"\";s:12:\"field_prefix\";s:0:\"\";s:12:\"field_suffix\";s:0:\"\";s:11:\"description\";s:0:\"\";s:10:\"attributes\";a:0:{}}',0,1,18);
INSERT INTO `drupal_webform_component` VALUES (1718,16,13,'jesli_sredniodobrzebardzo_dobrze_to_z_jakiego_projektunp_zlap_konsulting','Jeśli średnio/dobrze/bardzo dobrze ,to z jakiego projektu?(np. Złap Konsulting)','textfield','','a:7:{s:8:\"disabled\";i:0;s:5:\"width\";s:0:\"\";s:9:\"maxlength\";s:0:\"\";s:12:\"field_prefix\";s:0:\"\";s:12:\"field_suffix\";s:0:\"\";s:11:\"description\";s:0:\"\";s:10:\"attributes\";a:0:{}}',0,1,19);
INSERT INTO `drupal_webform_component` VALUES (1718,14,13,'skad_sie_dowiedziales_o_konkursie__plakatulotka_strona_internetowa_cognitis_strona_internetowa_kpmg_zajecia_na_uczelni','Skąd się dowiedziałeś o konkursie? (plakat/ulotka/ strona internetowa Cognitis/ strona internetowa KPMG/ zajęcia na uczelni','textfield','','a:7:{s:8:\"disabled\";i:0;s:5:\"width\";s:0:\"\";s:9:\"maxlength\";s:0:\"\";s:12:\"field_prefix\";s:0:\"\";s:12:\"field_suffix\";s:0:\"\";s:11:\"description\";s:0:\"\";s:10:\"attributes\";a:0:{}}',0,1,17);
INSERT INTO `drupal_webform_component` VALUES (1718,13,0,'informacje_dodatkowe_nie_brane_pod_uwage_przy_kwalifikacji_do_dalszego_etapu','Informacje dodatkowe, nie brane pod uwagę przy kwalifikacji do dalszego etapu','fieldset','','a:3:{s:11:\"collapsible\";i:0;s:9:\"collapsed\";i:0;s:11:\"description\";s:0:\"\";}',0,1,13);
INSERT INTO `drupal_webform_component` VALUES (1718,12,0,'odatkowe_informacje_o_sobienp_erasmus_odbyte_szkolenia_nietuzinkowe_osiagniecia_niezwyczajne_informacje','Dodatkowe informacje o sobie (np. Erasmus, odbyte szkolenia, nietuzinkowe osiągnięcia, niezwyczajne informacje)','textarea','','a:6:{s:9:\"resizable\";i:1;s:8:\"disabled\";i:0;s:4:\"cols\";s:0:\"\";s:4:\"rows\";s:0:\"\";s:11:\"description\";s:0:\"\";s:10:\"attributes\";a:0:{}}',0,1,12);
INSERT INTO `drupal_webform_component` VALUES (1718,9,0,'certyfikaty_jezykowe','Certyfikaty językowe','textarea','','a:6:{s:9:\"resizable\";i:1;s:8:\"disabled\";i:0;s:4:\"cols\";s:0:\"\";s:4:\"rows\";s:0:\"\";s:11:\"description\";s:0:\"\";s:10:\"attributes\";a:0:{}}',1,1,9);
INSERT INTO `drupal_webform_component` VALUES (1718,10,0,'zainteresowania','Zainteresowania','textarea','','a:6:{s:9:\"resizable\";i:1;s:8:\"disabled\";i:0;s:4:\"cols\";s:0:\"\";s:4:\"rows\";s:0:\"\";s:11:\"description\";s:0:\"\";s:10:\"attributes\";a:0:{}}',1,1,10);
INSERT INTO `drupal_webform_component` VALUES (1718,11,0,'11trzy_cechy_osobowosci_ktore_twoim_zdaniem_najlepiej_cie_opisuja','Trzy cechy osobowości, które Twoim zdaniem najlepiej Cię opisują','textfield','','a:7:{s:8:\"disabled\";i:0;s:5:\"width\";s:0:\"\";s:9:\"maxlength\";s:0:\"\";s:12:\"field_prefix\";s:0:\"\";s:12:\"field_suffix\";s:0:\"\";s:11:\"description\";s:0:\"\";s:10:\"attributes\";a:0:{}}',1,1,11);
INSERT INTO `drupal_webform_component` VALUES (1718,6,0,'7doswiadczenie_zawodowe_odbyte_praktyki','Doświadczenie zawodowe (odbyte praktyki):','textarea','','a:6:{s:9:\"resizable\";i:1;s:8:\"disabled\";i:0;s:4:\"cols\";s:0:\"\";s:4:\"rows\";s:0:\"\";s:11:\"description\";s:0:\"\";s:10:\"attributes\";a:0:{}}',1,1,7);
INSERT INTO `drupal_webform_component` VALUES (1718,7,0,'8czlonkostwo_w_organizacjach_studenckichkolach_naukowych','Członkostwo w organizacjach studenckich/kołach naukowych','textarea','','a:6:{s:9:\"resizable\";i:1;s:8:\"disabled\";i:0;s:4:\"cols\";s:0:\"\";s:4:\"rows\";s:0:\"\";s:11:\"description\";s:0:\"\";s:10:\"attributes\";a:0:{}}',1,1,8);
INSERT INTO `drupal_webform_component` VALUES (1718,8,0,'nazwa_uczelnikierunkurok_studiow','Nazwa uczelni/kierunku/rok studiów','textarea','','a:6:{s:9:\"resizable\";i:1;s:8:\"disabled\";i:0;s:4:\"cols\";s:0:\"\";s:4:\"rows\";s:0:\"\";s:11:\"description\";s:0:\"\";s:10:\"attributes\";a:0:{}}',1,1,6);
INSERT INTO `drupal_webform_component` VALUES (1718,18,0,'data_urodzenia','Data urodzenia','date','','a:6:{s:8:\"timezone\";s:4:\"site\";s:22:\"check_daylight_savings\";i:0;s:10:\"year_start\";s:4:\"1900\";s:8:\"year_end\";s:4:\"2050\";s:14:\"year_textfield\";i:1;s:11:\"description\";s:0:\"\";}',1,1,4);
INSERT INTO `drupal_webform_component` VALUES (1718,4,0,'narodowosc','Narodowość','textfield','','a:7:{s:8:\"disabled\";i:0;s:5:\"width\";s:0:\"\";s:9:\"maxlength\";s:0:\"\";s:12:\"field_prefix\";s:0:\"\";s:12:\"field_suffix\";s:0:\"\";s:11:\"description\";s:0:\"\";s:10:\"attributes\";a:0:{}}',1,1,5);
INSERT INTO `drupal_webform_component` VALUES (1718,2,0,'numer_telefonu','Numer telefonu','textfield','','a:7:{s:8:\"disabled\";i:0;s:5:\"width\";s:0:\"\";s:9:\"maxlength\";s:0:\"\";s:12:\"field_prefix\";s:0:\"\";s:12:\"field_suffix\";s:0:\"\";s:11:\"description\";s:0:\"\";s:10:\"attributes\";a:0:{}}',1,1,2);
INSERT INTO `drupal_webform_component` VALUES (1718,3,0,'adres_e_mail','Adres e-mail','email','%useremail','a:5:{s:5:\"email\";i:3;s:8:\"disabled\";i:0;s:5:\"width\";s:0:\"\";s:11:\"description\";s:0:\"\";s:10:\"attributes\";a:0:{}}',1,1,3);
INSERT INTO `drupal_webform_component` VALUES (1718,1,0,'imie_i_nazwisko','Imię i nazwisko','textfield','','a:7:{s:8:\"disabled\";i:0;s:5:\"width\";s:0:\"\";s:9:\"maxlength\";s:0:\"\";s:12:\"field_prefix\";s:0:\"\";s:12:\"field_suffix\";s:0:\"\";s:11:\"description\";s:0:\"\";s:10:\"attributes\";a:0:{}}',1,1,1);
/*!40000 ALTER TABLE `drupal_webform_component` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

