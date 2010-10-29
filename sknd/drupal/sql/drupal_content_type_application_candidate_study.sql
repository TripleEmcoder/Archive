
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
DROP TABLE IF EXISTS `drupal_content_type_application_candidate_study`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_content_type_application_candidate_study` (
  `vid` int(10) unsigned NOT NULL default '0',
  `nid` int(10) unsigned NOT NULL default '0',
  `field_candidate_study_major_value` longtext,
  `field_candidate_study_minor_value` longtext,
  `field_candidate_study_degree_value` int(11) default NULL,
  `field_candidate_study_uni_other_value` longtext,
  `field_candidate_study_uni_value` int(11) default NULL,
  `field_candidate_study_mode_value` int(11) default NULL,
  `field_candidate_study_year_value` int(11) default NULL,
  PRIMARY KEY  (`vid`),
  KEY `nid` (`nid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_content_type_application_candidate_study` WRITE;
/*!40000 ALTER TABLE `drupal_content_type_application_candidate_study` DISABLE KEYS */;
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3189,1633,'Informatyka i ekonometria','Ekonometria menedżerska',122,NULL,139,163,177);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3204,1814,'11','22',122,NULL,133,163,177);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3202,1611,'finanse i rachunkowość','nie dotyczy',121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3201,1614,'Międzynarodowe Stosunki Gospodarcze','biznes międzynarodowy',121,NULL,119,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3200,1615,'finanse i rachunkowość','nie dotyczy',121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3199,1616,'Ekonomia','Strategie biznesu i polityka gospodarcza w warunkach globalizacji',121,NULL,119,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3198,1618,'Finanse i rachunkowość',NULL,121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3197,1619,'Zarządzanie',NULL,121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3196,1620,'Automatyka i Zarządzanie','Inteligentne Systemy Inżynierii Produkcji',122,NULL,120,163,177);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3195,1621,'socjologia','badanie rynku',121,NULL,141,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3194,1622,'Międzynarodowe Stosunki Gospodarcze',NULL,121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3193,1623,'FILOLOGIA POLSKA','DZIENNIKARSTWO',122,NULL,133,161,176);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3192,1629,'Finanse i Rachunkowość',NULL,121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3191,1630,'Ekonomia','Ekonomika pracy i zarządzanie kadrami',121,NULL,119,161,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3190,1632,'Logistyka',NULL,129,NULL,120,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3187,1669,'Filozofia','Życie Publiczne',122,NULL,133,163,177);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3186,1672,'Zarządzanie',NULL,121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3185,1673,'Inżynieria Materiałowa','Metale i stopy (praca inżynierska z zakresu nanomateriałów)',129,NULL,120,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3184,1674,'Międzynarodowe stosunki gospodarcze','-',121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3183,1675,'Towaroznawstwo','Menedżer Produktu',129,NULL,119,163,176);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3182,1676,'Międzynarodowe stosunki gospodarcze','-',121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3181,1677,'Matematyka',NULL,121,NULL,133,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3180,1678,'Automatyka i Zarządzanie','Reprogramowalne Systemy Sterowania',129,NULL,120,163,176);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3188,1665,'Europeistyka',NULL,122,NULL,133,163,176);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3179,1679,'Historia','Socjoekonomika',121,NULL,133,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3178,1680,'Historia','Socjoekonomika',121,NULL,133,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3177,1681,'Historia','socjoekonomika',121,NULL,133,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3176,1682,'Ekonomia','Polityka i gospodarka żywnościowa',121,NULL,119,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3175,1683,'Ekonomia','Polityka i gospodarka żywnościowa',121,NULL,119,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3174,1684,'Ekonomia','Polityka i gospodarka żywnościowa',121,NULL,119,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3173,1685,'Finanse i rachunkowość',NULL,121,NULL,119,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3172,1686,'Finanse i rachunkowość',NULL,121,NULL,119,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3171,1689,'Informatyka i Ekonometria','Inżynieria finansowa',121,NULL,119,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3170,1691,'Prawo','Prawo',122,NULL,133,163,176);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3169,1692,'Finanse i Rachunkowość','prawdopodobnie bankowość. decyzja jeszcze nie podjęta',121,'Uniwersytet im. Adama Mickiewicza',119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3168,1693,'prawo',NULL,122,NULL,118,163,176);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3167,1701,'Informatyka i ekonometria','Inżynieria finansowa',121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3166,1739,'Stosunki międzynarodowe','International Bussines ',121,'WSB Poznań',131,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3156,1809,NULL,NULL,122,NULL,120,163,177);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3157,1807,'Logistyka','Logistyka Przedsiębiorstw',129,'Wojskowa Akademia Techniczna im. Jarosława Dąbrowskiego',131,163,176);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3155,1808,'Logistyka','Logistyka Przedsiębiorstw',129,'Wojskowa Akademia Techniczna im. Jarosława Dąbrowskiego',131,163,176);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3208,1815,'Pedagogika','Doradztwo zawodowe',121,'Uniwersytet Warmińsko-Mazurski w Olsztynie',131,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3210,1816,'Kulturoznawstwo','kultura i rynek',121,NULL,133,163,176);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3213,1818,'Muzykologia',NULL,121,'Akademia Muzyczna',133,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3215,1819,'Finanse i Rachunkowość','Inwestycje kapitałowe i strategie finansowe przedsiębiorstw',121,NULL,119,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3217,1820,'Zarządzanie','spec. Consulting gospodarczy',122,NULL,119,163,176);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3219,1821,'Międzynarodowe stosunki gospodarcze','Biznes Międzynarodowy',121,NULL,119,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3221,1822,'informatyka i ekonometria','elektroniczny biznes',121,NULL,119,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3224,1824,'Ekonomia',NULL,121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3226,1825,'Informatyka i ekonometria','Inżynieria finansowa',121,NULL,119,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3228,1826,'Finanse i Rachunkowość','Ubezpieczenia gospodarcze',122,NULL,119,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3230,1827,'ekonomia',NULL,121,NULL,141,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3232,1828,'Elektronika i telekomunikacja','Akustyka',122,NULL,140,163,177);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3234,1829,'Elektronika i telekomunikacja','Akustyka',122,NULL,140,163,177);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3236,1830,'finanse i rachunkowość','rachunkowość i skarbowość',121,NULL,119,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3238,1831,'Finanse i Rachunkowość',NULL,121,NULL,139,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3240,1832,'międzynarodowe stosunki gospodarcze',NULL,121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3244,1833,'Finanse i rachunkowość','Zarządzanie finansami prywatnymi',121,NULL,119,163,176);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3246,1834,'International Business','CEE Markets',122,'Szkoła Główna Handlowa',131,163,177);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3248,1835,'Zarządzanie','Kompetencje interpersonalne Menedżera',122,NULL,139,161,176);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3250,1836,'Finanse i rachunkowość','-',121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3252,1837,'Ekonomia','Menadżerska',121,NULL,141,163,176);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3254,1838,'Finanse i Rachunkowość',NULL,121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3256,1839,'Finanse i Rachunkowość',NULL,121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3259,1840,'Finanse i Rachunkowość',NULL,121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3261,1841,'Skp',NULL,129,'Uniwersytet Wrocławski',140,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3263,1842,'Wydział Gospodarki Międzynarodowej','Biznes Międzynarodowy',121,NULL,119,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3265,1843,'Informatyka',NULL,129,NULL,140,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3267,1844,'Międzynarodowe Stosunki Gospodarcze','Biznes Międzynarodowy',121,NULL,119,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3269,1845,'Informatyka',NULL,129,NULL,120,163,176);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3271,1846,'Międzynarodowe Stosnki Gospodarcze',NULL,121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3273,1847,'Międzynarodowe Stosnki Gospodarcze',NULL,121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3275,1848,'Akustyka','Protetyka słuchu i ochrona przed hałasem',121,NULL,133,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3277,1849,'Administracja',NULL,122,NULL,141,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3279,1850,'Finanse i rachunkowość','Finanse i rachunkowość spółek',122,NULL,139,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3281,1851,'Finanse i Rachunkowość','Globalne Rynki Finansowe',122,NULL,139,163,176);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3283,1852,'Międzynarodowe Stosunki Gospodarcze','biznes międzynarodowy',122,NULL,119,163,176);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3285,1853,'Międzynarodowe stosunki gospodarcze','biznes międzynarodowy',121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3287,1854,'Ekonomia','Publicystyka Ekonomiczna i Public Relations',122,NULL,119,163,177);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3289,1855,'Finanse i Rachunkowość na Wydziale Zarządzania',NULL,121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3291,1856,'Ekonomia','Strategie biznesu i polityka gospodarcza w warunkach globalizacji',121,NULL,119,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3293,1857,'Ekonomia','Strategie biznesu i polityka gospodarcza w warunkach globalizacji',121,NULL,119,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3295,1858,'Ekonomia; stosunki międzynarodowe','Strategie biznesu i polityki gospidarczej w warunkach globalizacji',121,'Uniwersytet im. A.Mickiewicza w Poznaniu',119,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3297,1859,'zarządzanie',NULL,121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3299,1860,'Finanse i rachunkowość',NULL,121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3301,1861,'międzynarodowe stosunki gospodarcze',NULL,121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3303,1862,'prawo',NULL,122,NULL,141,161,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3305,1863,'Inżynieria Materiałowa','Materiały metalowe i tworzywa sztuczne',129,NULL,120,163,176);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3307,1864,'Informatyka i Ekonometria','Cybernetyka ekonomiczna',121,NULL,119,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3309,1865,'Zarządzanie','Techniczno-handlowa',129,NULL,120,163,176);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3311,1866,'Zarządzanie','FiRP',121,NULL,119,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3313,1867,'Finanse i rachunkowość',NULL,122,NULL,119,163,176);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3315,1868,'Finanse i rachunkowość',NULL,122,NULL,119,163,176);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3317,1869,'Miedzynarodowe Stosunki Gospodarcze',NULL,121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3319,1870,'Zarządzanie',NULL,121,'Wyższa Szkoła Komunikacji i Zarządzania',131,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3321,1871,'Zarządzanie i Inżynieria Produkcji',NULL,129,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3323,1872,'Zarządzanie','Techniczno - Handlowa',129,NULL,120,163,176);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3325,1873,'Międzynarodowe Stosunki Gospodarcze','Biznes Międzynarodowy',121,NULL,119,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3327,1874,'Zarządzanie',NULL,121,NULL,140,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3329,1875,'Informatyka i Ekonometria',NULL,121,NULL,139,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3331,1876,'Informatyka i Ekonometria',NULL,121,NULL,139,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3333,1877,'Finanse i Rachunkowość','-',121,'-',141,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3335,1878,'Finanse i Rachunkowość',NULL,121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3337,1879,'Finanse i rachunkowość','brak',121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3339,1880,'Finanse i rachunkowość','brak',121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3341,1881,'Zarządzanie',NULL,121,NULL,133,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3343,1882,'Zarządzanie',NULL,121,NULL,140,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3345,1883,'Finanse i Rachunkowość',NULL,121,NULL,139,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3347,1884,'Międzynarodowe Stosunki Gospodarcze','Studia Europejskie',121,NULL,119,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3349,1885,'Międzynarodowe Stosunki Gospodarcze','Biznes Międzynarodowy',121,NULL,119,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3351,1886,'Międzynarodowe Stosunki Gospodarcze','Biznes Międzynarodowy',121,NULL,119,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3353,1887,'Gospodarka Międzynarodowa',NULL,122,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3355,1888,'Gospodarka Międzynarodowa',NULL,122,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3357,1889,'MIĘDZYNARODOWE STOSUNKI GOSPODARCZE','BIZNES MIĘDZYNARODOWY',121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3359,1890,'Finanse i Rachunkowośc','brak',121,'Wsb Poznań',131,161,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3361,1891,'Ekonomia','brak',121,'Wyższa Szkoła Bankowa',119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3363,1892,'informatyka i ekonometria','e-biznes',121,NULL,119,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3365,1893,'zarządzanie','organizacja i zarządzanie w biznesie',121,NULL,119,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3367,1894,'logistyka',NULL,129,NULL,120,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3370,1896,'TOWAROZNAWSTWO','-',129,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3372,1897,'Mechatronika',NULL,121,NULL,120,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3374,1898,'Zarządzanie i Inżynieria Produkcji ',NULL,129,NULL,139,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3376,1899,'Logistyka',NULL,129,NULL,120,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3378,1900,'Finanse i Rachunkowość','Inwestycje kapitałowe i strategie finansowe przedsiębiorstwa',121,NULL,119,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3380,1901,'Polityka Społeczna',NULL,121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3382,1902,'Międzynarodowe Stosunki Gospodarcze','Studia europejskie',121,NULL,119,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3384,1903,'Finanse i rachunkowość','-',121,NULL,119,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3386,1904,'prawo',NULL,122,NULL,133,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3388,1905,'Finanse i Rachunkowość','Analiza Ekonomiczna',121,'Wyższa Szkoła Bankowa',131,161,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3390,1906,'Ekonomia','Ekonomika Pracy i Zarządzanie Kadrami',121,NULL,119,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3392,1907,'Zarządzanie',NULL,129,NULL,120,163,173);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3394,1908,'Międzynarodowe Stosunki Gospodarcze','Logistyka Międzynarodowa',121,NULL,119,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3396,1909,'Automatyka i Zarządzanie',NULL,129,NULL,120,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3398,1910,'Międzynarodowe Stosunki Gospodarcze','Biznes międzynarodowy',121,NULL,119,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3400,1911,'Management in Business','Psychology of Management',121,'Poznańska Wyższa Szkoła Biznesu',131,163,175);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3402,1912,'Ekonomia',NULL,121,NULL,141,163,174);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3404,1913,'Zarządzanie','Zarządzanie marketingowe',122,NULL,140,163,177);
INSERT INTO `drupal_content_type_application_candidate_study` VALUES (3406,1914,'Ekonomia','Strategie biznesu i politya gospodarcza w warunkach globalizacji',121,NULL,119,163,176);
/*!40000 ALTER TABLE `drupal_content_type_application_candidate_study` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

