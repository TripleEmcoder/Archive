
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
DROP TABLE IF EXISTS `drupal_location_instance`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_location_instance` (
  `nid` int(10) unsigned NOT NULL default '0',
  `vid` int(10) unsigned NOT NULL default '0',
  `uid` int(10) unsigned NOT NULL default '0',
  `genid` varchar(255) NOT NULL default '',
  `lid` int(10) unsigned NOT NULL default '0',
  KEY `nid` (`nid`),
  KEY `vid` (`vid`),
  KEY `uid` (`uid`),
  KEY `genid` (`genid`),
  KEY `lid` (`lid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_location_instance` WRITE;
/*!40000 ALTER TABLE `drupal_location_instance` DISABLE KEYS */;
INSERT INTO `drupal_location_instance` VALUES (1673,2550,0,'cck:field_candidate_home_address:2550',146);
INSERT INTO `drupal_location_instance` VALUES (1672,2548,0,'cck:field_candidate_study_address:2548',145);
INSERT INTO `drupal_location_instance` VALUES (1672,2548,0,'cck:field_candidate_home_address:2548',144);
INSERT INTO `drupal_location_instance` VALUES (1669,2544,0,'cck:field_candidate_home_address:2544',143);
INSERT INTO `drupal_location_instance` VALUES (1665,2536,0,'cck:field_candidate_study_address:2536',139);
INSERT INTO `drupal_location_instance` VALUES (1665,2536,0,'cck:field_candidate_home_address:2536',138);
INSERT INTO `drupal_location_instance` VALUES (1633,2472,0,'cck:field_candidate_home_address:2472',106);
INSERT INTO `drupal_location_instance` VALUES (1632,2470,0,'cck:field_candidate_study_address:2470',105);
INSERT INTO `drupal_location_instance` VALUES (1632,2470,0,'cck:field_candidate_home_address:2470',104);
INSERT INTO `drupal_location_instance` VALUES (1630,2464,0,'cck:field_candidate_home_address:2464',103);
INSERT INTO `drupal_location_instance` VALUES (1629,2459,0,'cck:field_candidate_study_address:2459',102);
INSERT INTO `drupal_location_instance` VALUES (1629,2459,0,'cck:field_candidate_home_address:2459',101);
INSERT INTO `drupal_location_instance` VALUES (1623,2452,0,'cck:field_candidate_study_address:2452',100);
INSERT INTO `drupal_location_instance` VALUES (1623,2452,0,'cck:field_candidate_home_address:2452',99);
INSERT INTO `drupal_location_instance` VALUES (1622,2450,0,'cck:field_candidate_study_address:2450',98);
INSERT INTO `drupal_location_instance` VALUES (1622,2450,0,'cck:field_candidate_home_address:2450',97);
INSERT INTO `drupal_location_instance` VALUES (1621,2448,0,'cck:field_candidate_study_address:2448',96);
INSERT INTO `drupal_location_instance` VALUES (1621,2448,0,'cck:field_candidate_home_address:2448',95);
INSERT INTO `drupal_location_instance` VALUES (1620,2446,0,'cck:field_candidate_home_address:2446',94);
INSERT INTO `drupal_location_instance` VALUES (1619,2444,0,'cck:field_candidate_study_address:2444',93);
INSERT INTO `drupal_location_instance` VALUES (1619,2444,0,'cck:field_candidate_home_address:2444',92);
INSERT INTO `drupal_location_instance` VALUES (1618,2442,0,'cck:field_candidate_study_address:2442',91);
INSERT INTO `drupal_location_instance` VALUES (1618,2442,0,'cck:field_candidate_home_address:2442',90);
INSERT INTO `drupal_location_instance` VALUES (1616,2439,0,'cck:field_candidate_study_address:2439',89);
INSERT INTO `drupal_location_instance` VALUES (1616,2439,0,'cck:field_candidate_home_address:2439',88);
INSERT INTO `drupal_location_instance` VALUES (1615,2437,0,'cck:field_candidate_home_address:2437',87);
INSERT INTO `drupal_location_instance` VALUES (1614,2435,0,'cck:field_candidate_home_address:2435',86);
INSERT INTO `drupal_location_instance` VALUES (1611,2412,0,'cck:field_candidate_study_address:2412',85);
INSERT INTO `drupal_location_instance` VALUES (1611,2412,0,'cck:field_candidate_home_address:2412',84);
INSERT INTO `drupal_location_instance` VALUES (1455,1458,0,'cck:field_company_postal_address:1458',28);
INSERT INTO `drupal_location_instance` VALUES (1453,1456,0,'cck:field_company_postal_address:1456',27);
INSERT INTO `drupal_location_instance` VALUES (1452,1455,0,'cck:field_company_postal_address:1455',26);
INSERT INTO `drupal_location_instance` VALUES (1450,1453,0,'cck:field_company_postal_address:1453',25);
INSERT INTO `drupal_location_instance` VALUES (1446,1449,0,'cck:field_company_postal_address:1449',24);
INSERT INTO `drupal_location_instance` VALUES (1444,1447,0,'cck:field_company_postal_address:1447',23);
INSERT INTO `drupal_location_instance` VALUES (1442,1445,0,'cck:field_company_postal_address:1445',22);
INSERT INTO `drupal_location_instance` VALUES (1440,1443,0,'cck:field_company_postal_address:1443',21);
INSERT INTO `drupal_location_instance` VALUES (1439,1442,0,'cck:field_company_postal_address:1442',20);
INSERT INTO `drupal_location_instance` VALUES (1437,1440,0,'cck:field_company_postal_address:1440',19);
INSERT INTO `drupal_location_instance` VALUES (1434,1437,0,'cck:field_company_postal_address:1437',18);
INSERT INTO `drupal_location_instance` VALUES (1432,1435,0,'cck:field_company_postal_address:1435',17);
INSERT INTO `drupal_location_instance` VALUES (1430,1433,0,'cck:field_company_postal_address:1433',16);
INSERT INTO `drupal_location_instance` VALUES (1426,1429,0,'cck:field_company_postal_address:1429',15);
INSERT INTO `drupal_location_instance` VALUES (1424,1427,0,'cck:field_company_postal_address:1427',14);
INSERT INTO `drupal_location_instance` VALUES (1422,1425,0,'cck:field_company_postal_address:1425',13);
INSERT INTO `drupal_location_instance` VALUES (1418,1421,0,'cck:field_company_postal_address:1421',12);
INSERT INTO `drupal_location_instance` VALUES (1417,1420,0,'cck:field_company_postal_address:1420',11);
INSERT INTO `drupal_location_instance` VALUES (1412,1415,0,'cck:field_company_postal_address:1415',10);
INSERT INTO `drupal_location_instance` VALUES (1410,1413,0,'cck:field_company_postal_address:1413',9);
INSERT INTO `drupal_location_instance` VALUES (1406,1409,0,'cck:field_company_postal_address:1409',8);
INSERT INTO `drupal_location_instance` VALUES (1403,1406,0,'cck:field_company_postal_address:1406',7);
INSERT INTO `drupal_location_instance` VALUES (1400,1403,0,'cck:field_company_postal_address:1403',6);
INSERT INTO `drupal_location_instance` VALUES (1398,1401,0,'cck:field_company_postal_address:1401',5);
INSERT INTO `drupal_location_instance` VALUES (1674,2552,0,'cck:field_candidate_home_address:2552',147);
INSERT INTO `drupal_location_instance` VALUES (1674,2552,0,'cck:field_candidate_study_address:2552',148);
INSERT INTO `drupal_location_instance` VALUES (1675,2554,0,'cck:field_candidate_home_address:2554',149);
INSERT INTO `drupal_location_instance` VALUES (1675,2554,0,'cck:field_candidate_study_address:2554',150);
INSERT INTO `drupal_location_instance` VALUES (1676,2556,0,'cck:field_candidate_home_address:2556',151);
INSERT INTO `drupal_location_instance` VALUES (1676,2556,0,'cck:field_candidate_study_address:2556',152);
INSERT INTO `drupal_location_instance` VALUES (1677,2558,0,'cck:field_candidate_home_address:2558',153);
INSERT INTO `drupal_location_instance` VALUES (1677,2558,0,'cck:field_candidate_study_address:2558',154);
INSERT INTO `drupal_location_instance` VALUES (1678,2560,0,'cck:field_candidate_home_address:2560',155);
INSERT INTO `drupal_location_instance` VALUES (1678,2560,0,'cck:field_candidate_study_address:2560',156);
INSERT INTO `drupal_location_instance` VALUES (1679,2562,0,'cck:field_candidate_home_address:2562',157);
INSERT INTO `drupal_location_instance` VALUES (1680,2564,0,'cck:field_candidate_home_address:2564',158);
INSERT INTO `drupal_location_instance` VALUES (1681,2566,0,'cck:field_candidate_home_address:2566',159);
INSERT INTO `drupal_location_instance` VALUES (1682,2568,0,'cck:field_candidate_home_address:2568',160);
INSERT INTO `drupal_location_instance` VALUES (1682,2568,0,'cck:field_candidate_study_address:2568',161);
INSERT INTO `drupal_location_instance` VALUES (1683,2570,0,'cck:field_candidate_home_address:2570',162);
INSERT INTO `drupal_location_instance` VALUES (1683,2570,0,'cck:field_candidate_study_address:2570',163);
INSERT INTO `drupal_location_instance` VALUES (1684,2572,0,'cck:field_candidate_home_address:2572',164);
INSERT INTO `drupal_location_instance` VALUES (1684,2572,0,'cck:field_candidate_study_address:2572',165);
INSERT INTO `drupal_location_instance` VALUES (1685,2574,0,'cck:field_candidate_home_address:2574',166);
INSERT INTO `drupal_location_instance` VALUES (1686,2576,0,'cck:field_candidate_home_address:2576',167);
INSERT INTO `drupal_location_instance` VALUES (1689,2611,0,'cck:field_candidate_home_address:2611',168);
INSERT INTO `drupal_location_instance` VALUES (1689,2611,0,'cck:field_candidate_study_address:2611',169);
INSERT INTO `drupal_location_instance` VALUES (1691,2615,0,'cck:field_candidate_home_address:2615',170);
INSERT INTO `drupal_location_instance` VALUES (1692,2618,0,'cck:field_candidate_home_address:2618',171);
INSERT INTO `drupal_location_instance` VALUES (1693,2620,0,'cck:field_candidate_home_address:2620',172);
INSERT INTO `drupal_location_instance` VALUES (1693,2620,0,'cck:field_candidate_study_address:2620',173);
INSERT INTO `drupal_location_instance` VALUES (1701,2656,0,'cck:field_candidate_home_address:2656',174);
INSERT INTO `drupal_location_instance` VALUES (1739,2920,0,'cck:field_candidate_home_address:2920',175);
INSERT INTO `drupal_location_instance` VALUES (1739,2920,0,'cck:field_candidate_study_address:2920',176);
INSERT INTO `drupal_location_instance` VALUES (1807,3145,0,'cck:field_candidate_home_address:3145',177);
INSERT INTO `drupal_location_instance` VALUES (1808,3147,0,'cck:field_candidate_home_address:3147',178);
INSERT INTO `drupal_location_instance` VALUES (1809,3153,0,'cck:field_candidate_home_address:3153',179);
INSERT INTO `drupal_location_instance` VALUES (1808,3147,0,'cck:field_candidate_study_address:3147',180);
INSERT INTO `drupal_location_instance` VALUES (1809,3153,0,'cck:field_candidate_study_address:3153',181);
INSERT INTO `drupal_location_instance` VALUES (1807,3145,0,'cck:field_candidate_study_address:3145',182);
INSERT INTO `drupal_location_instance` VALUES (1814,3203,0,'cck:field_candidate_home_address:3203',187);
INSERT INTO `drupal_location_instance` VALUES (1815,3207,0,'cck:field_candidate_home_address:3207',188);
INSERT INTO `drupal_location_instance` VALUES (1815,3207,0,'cck:field_candidate_study_address:3207',189);
INSERT INTO `drupal_location_instance` VALUES (1816,3209,0,'cck:field_candidate_home_address:3209',190);
INSERT INTO `drupal_location_instance` VALUES (1816,3209,0,'cck:field_candidate_study_address:3209',191);
INSERT INTO `drupal_location_instance` VALUES (1818,3212,0,'cck:field_candidate_home_address:3212',192);
INSERT INTO `drupal_location_instance` VALUES (1819,3214,0,'cck:field_candidate_home_address:3214',193);
INSERT INTO `drupal_location_instance` VALUES (1819,3214,0,'cck:field_candidate_study_address:3214',194);
INSERT INTO `drupal_location_instance` VALUES (1820,3216,0,'cck:field_candidate_home_address:3216',195);
INSERT INTO `drupal_location_instance` VALUES (1820,3216,0,'cck:field_candidate_study_address:3216',196);
INSERT INTO `drupal_location_instance` VALUES (1821,3218,0,'cck:field_candidate_home_address:3218',197);
INSERT INTO `drupal_location_instance` VALUES (1821,3218,0,'cck:field_candidate_study_address:3218',198);
INSERT INTO `drupal_location_instance` VALUES (1822,3220,0,'cck:field_candidate_home_address:3220',199);
INSERT INTO `drupal_location_instance` VALUES (1822,3220,0,'cck:field_candidate_study_address:3220',200);
INSERT INTO `drupal_location_instance` VALUES (1824,3223,0,'cck:field_candidate_home_address:3223',201);
INSERT INTO `drupal_location_instance` VALUES (1824,3223,0,'cck:field_candidate_study_address:3223',202);
INSERT INTO `drupal_location_instance` VALUES (1825,3225,0,'cck:field_candidate_home_address:3225',203);
INSERT INTO `drupal_location_instance` VALUES (1826,3227,0,'cck:field_candidate_home_address:3227',204);
INSERT INTO `drupal_location_instance` VALUES (1827,3229,0,'cck:field_candidate_home_address:3229',205);
INSERT INTO `drupal_location_instance` VALUES (1827,3229,0,'cck:field_candidate_study_address:3229',206);
INSERT INTO `drupal_location_instance` VALUES (1828,3231,0,'cck:field_candidate_home_address:3231',207);
INSERT INTO `drupal_location_instance` VALUES (1829,3233,0,'cck:field_candidate_home_address:3233',208);
INSERT INTO `drupal_location_instance` VALUES (1830,3235,0,'cck:field_candidate_home_address:3235',209);
INSERT INTO `drupal_location_instance` VALUES (1830,3235,0,'cck:field_candidate_study_address:3235',210);
INSERT INTO `drupal_location_instance` VALUES (1831,3237,0,'cck:field_candidate_home_address:3237',211);
INSERT INTO `drupal_location_instance` VALUES (1831,3237,0,'cck:field_candidate_study_address:3237',212);
INSERT INTO `drupal_location_instance` VALUES (1832,3239,0,'cck:field_candidate_home_address:3239',213);
INSERT INTO `drupal_location_instance` VALUES (1832,3239,0,'cck:field_candidate_study_address:3239',214);
INSERT INTO `drupal_location_instance` VALUES (1833,3243,0,'cck:field_candidate_home_address:3243',215);
INSERT INTO `drupal_location_instance` VALUES (1833,3243,0,'cck:field_candidate_study_address:3243',216);
INSERT INTO `drupal_location_instance` VALUES (1834,3245,0,'cck:field_candidate_home_address:3245',217);
INSERT INTO `drupal_location_instance` VALUES (1835,3247,0,'cck:field_candidate_home_address:3247',218);
INSERT INTO `drupal_location_instance` VALUES (1836,3249,0,'cck:field_candidate_home_address:3249',219);
INSERT INTO `drupal_location_instance` VALUES (1836,3249,0,'cck:field_candidate_study_address:3249',220);
INSERT INTO `drupal_location_instance` VALUES (1837,3251,0,'cck:field_candidate_home_address:3251',221);
INSERT INTO `drupal_location_instance` VALUES (1837,3251,0,'cck:field_candidate_study_address:3251',222);
INSERT INTO `drupal_location_instance` VALUES (1838,3253,0,'cck:field_candidate_home_address:3253',223);
INSERT INTO `drupal_location_instance` VALUES (1838,3253,0,'cck:field_candidate_study_address:3253',224);
INSERT INTO `drupal_location_instance` VALUES (1839,3255,0,'cck:field_candidate_home_address:3255',225);
INSERT INTO `drupal_location_instance` VALUES (1839,3255,0,'cck:field_candidate_study_address:3255',226);
INSERT INTO `drupal_location_instance` VALUES (1840,3258,0,'cck:field_candidate_home_address:3258',227);
INSERT INTO `drupal_location_instance` VALUES (1840,3258,0,'cck:field_candidate_study_address:3258',228);
INSERT INTO `drupal_location_instance` VALUES (1841,3260,0,'cck:field_candidate_home_address:3260',229);
INSERT INTO `drupal_location_instance` VALUES (1841,3260,0,'cck:field_candidate_study_address:3260',230);
INSERT INTO `drupal_location_instance` VALUES (1842,3262,0,'cck:field_candidate_home_address:3262',231);
INSERT INTO `drupal_location_instance` VALUES (1842,3262,0,'cck:field_candidate_study_address:3262',232);
INSERT INTO `drupal_location_instance` VALUES (1843,3264,0,'cck:field_candidate_home_address:3264',233);
INSERT INTO `drupal_location_instance` VALUES (1844,3266,0,'cck:field_candidate_home_address:3266',234);
INSERT INTO `drupal_location_instance` VALUES (1844,3266,0,'cck:field_candidate_study_address:3266',235);
INSERT INTO `drupal_location_instance` VALUES (1845,3268,0,'cck:field_candidate_home_address:3268',236);
INSERT INTO `drupal_location_instance` VALUES (1845,3268,0,'cck:field_candidate_study_address:3268',237);
INSERT INTO `drupal_location_instance` VALUES (1846,3270,0,'cck:field_candidate_home_address:3270',238);
INSERT INTO `drupal_location_instance` VALUES (1846,3270,0,'cck:field_candidate_study_address:3270',239);
INSERT INTO `drupal_location_instance` VALUES (1847,3272,0,'cck:field_candidate_home_address:3272',240);
INSERT INTO `drupal_location_instance` VALUES (1847,3272,0,'cck:field_candidate_study_address:3272',241);
INSERT INTO `drupal_location_instance` VALUES (1848,3274,0,'cck:field_candidate_home_address:3274',242);
INSERT INTO `drupal_location_instance` VALUES (1848,3274,0,'cck:field_candidate_study_address:3274',243);
INSERT INTO `drupal_location_instance` VALUES (1849,3276,0,'cck:field_candidate_home_address:3276',244);
INSERT INTO `drupal_location_instance` VALUES (1849,3276,0,'cck:field_candidate_study_address:3276',245);
INSERT INTO `drupal_location_instance` VALUES (1850,3278,0,'cck:field_candidate_home_address:3278',246);
INSERT INTO `drupal_location_instance` VALUES (1851,3280,0,'cck:field_candidate_home_address:3280',247);
INSERT INTO `drupal_location_instance` VALUES (1851,3280,0,'cck:field_candidate_study_address:3280',248);
INSERT INTO `drupal_location_instance` VALUES (1852,3282,0,'cck:field_candidate_home_address:3282',249);
INSERT INTO `drupal_location_instance` VALUES (1853,3284,0,'cck:field_candidate_home_address:3284',250);
INSERT INTO `drupal_location_instance` VALUES (1853,3284,0,'cck:field_candidate_study_address:3284',251);
INSERT INTO `drupal_location_instance` VALUES (1854,3286,0,'cck:field_candidate_home_address:3286',252);
INSERT INTO `drupal_location_instance` VALUES (1855,3288,0,'cck:field_candidate_home_address:3288',253);
INSERT INTO `drupal_location_instance` VALUES (1855,3288,0,'cck:field_candidate_study_address:3288',254);
INSERT INTO `drupal_location_instance` VALUES (1856,3290,0,'cck:field_candidate_home_address:3290',255);
INSERT INTO `drupal_location_instance` VALUES (1856,3290,0,'cck:field_candidate_study_address:3290',256);
INSERT INTO `drupal_location_instance` VALUES (1857,3292,0,'cck:field_candidate_home_address:3292',257);
INSERT INTO `drupal_location_instance` VALUES (1857,3292,0,'cck:field_candidate_study_address:3292',258);
INSERT INTO `drupal_location_instance` VALUES (1858,3294,0,'cck:field_candidate_home_address:3294',259);
INSERT INTO `drupal_location_instance` VALUES (1858,3294,0,'cck:field_candidate_study_address:3294',260);
INSERT INTO `drupal_location_instance` VALUES (1859,3296,0,'cck:field_candidate_home_address:3296',261);
INSERT INTO `drupal_location_instance` VALUES (1859,3296,0,'cck:field_candidate_study_address:3296',262);
INSERT INTO `drupal_location_instance` VALUES (1860,3298,0,'cck:field_candidate_home_address:3298',263);
INSERT INTO `drupal_location_instance` VALUES (1860,3298,0,'cck:field_candidate_study_address:3298',264);
INSERT INTO `drupal_location_instance` VALUES (1861,3300,0,'cck:field_candidate_home_address:3300',265);
INSERT INTO `drupal_location_instance` VALUES (1861,3300,0,'cck:field_candidate_study_address:3300',266);
INSERT INTO `drupal_location_instance` VALUES (1862,3302,0,'cck:field_candidate_home_address:3302',267);
INSERT INTO `drupal_location_instance` VALUES (1862,3302,0,'cck:field_candidate_study_address:3302',268);
INSERT INTO `drupal_location_instance` VALUES (1863,3304,0,'cck:field_candidate_home_address:3304',269);
INSERT INTO `drupal_location_instance` VALUES (1864,3306,0,'cck:field_candidate_home_address:3306',270);
INSERT INTO `drupal_location_instance` VALUES (1864,3306,0,'cck:field_candidate_study_address:3306',271);
INSERT INTO `drupal_location_instance` VALUES (1865,3308,0,'cck:field_candidate_home_address:3308',272);
INSERT INTO `drupal_location_instance` VALUES (1865,3308,0,'cck:field_candidate_study_address:3308',273);
INSERT INTO `drupal_location_instance` VALUES (1866,3310,0,'cck:field_candidate_home_address:3310',274);
INSERT INTO `drupal_location_instance` VALUES (1867,3312,0,'cck:field_candidate_home_address:3312',275);
INSERT INTO `drupal_location_instance` VALUES (1867,3312,0,'cck:field_candidate_study_address:3312',276);
INSERT INTO `drupal_location_instance` VALUES (1868,3314,0,'cck:field_candidate_home_address:3314',277);
INSERT INTO `drupal_location_instance` VALUES (1868,3314,0,'cck:field_candidate_study_address:3314',278);
INSERT INTO `drupal_location_instance` VALUES (1869,3316,0,'cck:field_candidate_home_address:3316',279);
INSERT INTO `drupal_location_instance` VALUES (1869,3316,0,'cck:field_candidate_study_address:3316',280);
INSERT INTO `drupal_location_instance` VALUES (1870,3318,0,'cck:field_candidate_home_address:3318',281);
INSERT INTO `drupal_location_instance` VALUES (1870,3318,0,'cck:field_candidate_study_address:3318',282);
INSERT INTO `drupal_location_instance` VALUES (1871,3320,0,'cck:field_candidate_home_address:3320',283);
INSERT INTO `drupal_location_instance` VALUES (1871,3320,0,'cck:field_candidate_study_address:3320',284);
INSERT INTO `drupal_location_instance` VALUES (1872,3322,0,'cck:field_candidate_home_address:3322',285);
INSERT INTO `drupal_location_instance` VALUES (1872,3322,0,'cck:field_candidate_study_address:3322',286);
INSERT INTO `drupal_location_instance` VALUES (1873,3324,0,'cck:field_candidate_home_address:3324',287);
INSERT INTO `drupal_location_instance` VALUES (1874,3326,0,'cck:field_candidate_home_address:3326',288);
INSERT INTO `drupal_location_instance` VALUES (1874,3326,0,'cck:field_candidate_study_address:3326',289);
INSERT INTO `drupal_location_instance` VALUES (1875,3328,0,'cck:field_candidate_home_address:3328',290);
INSERT INTO `drupal_location_instance` VALUES (1875,3328,0,'cck:field_candidate_study_address:3328',291);
INSERT INTO `drupal_location_instance` VALUES (1876,3330,0,'cck:field_candidate_home_address:3330',292);
INSERT INTO `drupal_location_instance` VALUES (1876,3330,0,'cck:field_candidate_study_address:3330',293);
INSERT INTO `drupal_location_instance` VALUES (1877,3332,0,'cck:field_candidate_home_address:3332',294);
INSERT INTO `drupal_location_instance` VALUES (1877,3332,0,'cck:field_candidate_study_address:3332',295);
INSERT INTO `drupal_location_instance` VALUES (1878,3334,0,'cck:field_candidate_home_address:3334',296);
INSERT INTO `drupal_location_instance` VALUES (1878,3334,0,'cck:field_candidate_study_address:3334',297);
INSERT INTO `drupal_location_instance` VALUES (1879,3336,0,'cck:field_candidate_home_address:3336',298);
INSERT INTO `drupal_location_instance` VALUES (1879,3336,0,'cck:field_candidate_study_address:3336',299);
INSERT INTO `drupal_location_instance` VALUES (1880,3338,0,'cck:field_candidate_home_address:3338',300);
INSERT INTO `drupal_location_instance` VALUES (1880,3338,0,'cck:field_candidate_study_address:3338',301);
INSERT INTO `drupal_location_instance` VALUES (1881,3340,0,'cck:field_candidate_home_address:3340',302);
INSERT INTO `drupal_location_instance` VALUES (1881,3340,0,'cck:field_candidate_study_address:3340',303);
INSERT INTO `drupal_location_instance` VALUES (1882,3342,0,'cck:field_candidate_home_address:3342',304);
INSERT INTO `drupal_location_instance` VALUES (1882,3342,0,'cck:field_candidate_study_address:3342',305);
INSERT INTO `drupal_location_instance` VALUES (1883,3344,0,'cck:field_candidate_home_address:3344',306);
INSERT INTO `drupal_location_instance` VALUES (1884,3346,0,'cck:field_candidate_home_address:3346',307);
INSERT INTO `drupal_location_instance` VALUES (1884,3346,0,'cck:field_candidate_study_address:3346',308);
INSERT INTO `drupal_location_instance` VALUES (1885,3348,0,'cck:field_candidate_home_address:3348',309);
INSERT INTO `drupal_location_instance` VALUES (1885,3348,0,'cck:field_candidate_study_address:3348',310);
INSERT INTO `drupal_location_instance` VALUES (1886,3350,0,'cck:field_candidate_home_address:3350',311);
INSERT INTO `drupal_location_instance` VALUES (1886,3350,0,'cck:field_candidate_study_address:3350',312);
INSERT INTO `drupal_location_instance` VALUES (1887,3352,0,'cck:field_candidate_home_address:3352',313);
INSERT INTO `drupal_location_instance` VALUES (1887,3352,0,'cck:field_candidate_study_address:3352',314);
INSERT INTO `drupal_location_instance` VALUES (1888,3354,0,'cck:field_candidate_home_address:3354',315);
INSERT INTO `drupal_location_instance` VALUES (1888,3354,0,'cck:field_candidate_study_address:3354',316);
INSERT INTO `drupal_location_instance` VALUES (1889,3356,0,'cck:field_candidate_home_address:3356',317);
INSERT INTO `drupal_location_instance` VALUES (1889,3356,0,'cck:field_candidate_study_address:3356',318);
INSERT INTO `drupal_location_instance` VALUES (1890,3358,0,'cck:field_candidate_home_address:3358',319);
INSERT INTO `drupal_location_instance` VALUES (1891,3360,0,'cck:field_candidate_home_address:3360',320);
INSERT INTO `drupal_location_instance` VALUES (1892,3362,0,'cck:field_candidate_home_address:3362',321);
INSERT INTO `drupal_location_instance` VALUES (1893,3364,0,'cck:field_candidate_home_address:3364',322);
INSERT INTO `drupal_location_instance` VALUES (1893,3364,0,'cck:field_candidate_study_address:3364',323);
INSERT INTO `drupal_location_instance` VALUES (1894,3366,0,'cck:field_candidate_home_address:3366',324);
INSERT INTO `drupal_location_instance` VALUES (1894,3366,0,'cck:field_candidate_study_address:3366',325);
INSERT INTO `drupal_location_instance` VALUES (1896,3369,0,'cck:field_candidate_home_address:3369',326);
INSERT INTO `drupal_location_instance` VALUES (1896,3369,0,'cck:field_candidate_study_address:3369',327);
INSERT INTO `drupal_location_instance` VALUES (1897,3371,0,'cck:field_candidate_home_address:3371',328);
INSERT INTO `drupal_location_instance` VALUES (1897,3371,0,'cck:field_candidate_study_address:3371',329);
INSERT INTO `drupal_location_instance` VALUES (1898,3373,0,'cck:field_candidate_home_address:3373',330);
INSERT INTO `drupal_location_instance` VALUES (1898,3373,0,'cck:field_candidate_study_address:3373',331);
INSERT INTO `drupal_location_instance` VALUES (1899,3375,0,'cck:field_candidate_home_address:3375',332);
INSERT INTO `drupal_location_instance` VALUES (1899,3375,0,'cck:field_candidate_study_address:3375',333);
INSERT INTO `drupal_location_instance` VALUES (1900,3377,0,'cck:field_candidate_home_address:3377',334);
INSERT INTO `drupal_location_instance` VALUES (1900,3377,0,'cck:field_candidate_study_address:3377',335);
INSERT INTO `drupal_location_instance` VALUES (1901,3379,0,'cck:field_candidate_home_address:3379',336);
INSERT INTO `drupal_location_instance` VALUES (1901,3379,0,'cck:field_candidate_study_address:3379',337);
INSERT INTO `drupal_location_instance` VALUES (1902,3381,0,'cck:field_candidate_home_address:3381',338);
INSERT INTO `drupal_location_instance` VALUES (1902,3381,0,'cck:field_candidate_study_address:3381',339);
INSERT INTO `drupal_location_instance` VALUES (1903,3383,0,'cck:field_candidate_home_address:3383',340);
INSERT INTO `drupal_location_instance` VALUES (1903,3383,0,'cck:field_candidate_study_address:3383',341);
INSERT INTO `drupal_location_instance` VALUES (1904,3385,0,'cck:field_candidate_home_address:3385',342);
INSERT INTO `drupal_location_instance` VALUES (1904,3385,0,'cck:field_candidate_study_address:3385',343);
INSERT INTO `drupal_location_instance` VALUES (1905,3387,0,'cck:field_candidate_home_address:3387',344);
INSERT INTO `drupal_location_instance` VALUES (1906,3389,0,'cck:field_candidate_home_address:3389',345);
INSERT INTO `drupal_location_instance` VALUES (1907,3391,0,'cck:field_candidate_home_address:3391',346);
INSERT INTO `drupal_location_instance` VALUES (1907,3391,0,'cck:field_candidate_study_address:3391',347);
INSERT INTO `drupal_location_instance` VALUES (1908,3393,0,'cck:field_candidate_home_address:3393',348);
INSERT INTO `drupal_location_instance` VALUES (1908,3393,0,'cck:field_candidate_study_address:3393',349);
INSERT INTO `drupal_location_instance` VALUES (1909,3395,0,'cck:field_candidate_home_address:3395',350);
INSERT INTO `drupal_location_instance` VALUES (1910,3397,0,'cck:field_candidate_home_address:3397',351);
INSERT INTO `drupal_location_instance` VALUES (1910,3397,0,'cck:field_candidate_study_address:3397',352);
INSERT INTO `drupal_location_instance` VALUES (1911,3399,0,'cck:field_candidate_home_address:3399',353);
INSERT INTO `drupal_location_instance` VALUES (1911,3399,0,'cck:field_candidate_study_address:3399',354);
INSERT INTO `drupal_location_instance` VALUES (1912,3401,0,'cck:field_candidate_home_address:3401',355);
INSERT INTO `drupal_location_instance` VALUES (1912,3401,0,'cck:field_candidate_study_address:3401',356);
INSERT INTO `drupal_location_instance` VALUES (1913,3403,0,'cck:field_candidate_home_address:3403',357);
INSERT INTO `drupal_location_instance` VALUES (1913,3403,0,'cck:field_candidate_study_address:3403',358);
INSERT INTO `drupal_location_instance` VALUES (1914,3405,0,'cck:field_candidate_home_address:3405',359);
/*!40000 ALTER TABLE `drupal_location_instance` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
