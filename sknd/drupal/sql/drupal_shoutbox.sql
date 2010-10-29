
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
DROP TABLE IF EXISTS `drupal_shoutbox`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_shoutbox` (
  `shout_id` int(10) unsigned NOT NULL auto_increment,
  `uid` int(10) unsigned NOT NULL default '0',
  `nick` varchar(32) NOT NULL,
  `shout` varchar(255) NOT NULL,
  `url` varchar(100) NOT NULL,
  `moderate` int(11) NOT NULL default '0',
  `created` int(11) NOT NULL default '0',
  `changed` int(11) NOT NULL default '0',
  `hostname` varchar(255) NOT NULL,
  `sid` varchar(64) NOT NULL default '',
  PRIMARY KEY  (`shout_id`)
) ENGINE=MyISAM AUTO_INCREMENT=78 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_shoutbox` WRITE;
/*!40000 ALTER TABLE `drupal_shoutbox` DISABLE KEYS */;
INSERT INTO `drupal_shoutbox` VALUES (4,206,'marcin.mikolajczak','Mówisz, masz ;-)','',0,1232315339,1232315339,'','06a10f59b359f493f0d68533e37bb922');
INSERT INTO `drupal_shoutbox` VALUES (3,178,'jakub.brzozowski','Maria, Masz shout boxa ;P','',0,1232314635,1232314635,'','156bb50314e07ba457b3515b1950f084');
INSERT INTO `drupal_shoutbox` VALUES (5,208,'michal.staniuk','Fajne to nowe forum:D','',0,1232317069,1232317069,'','575d8f0cbbf505562d8d5a70b30cdebc');
INSERT INTO `drupal_shoutbox` VALUES (6,206,'marcin.mikolajczak','Załadowalem taki jeden dodatek, myslę że teraz jest lepiej :-)','',0,1232317433,1232317433,'','638ae93694d1b98cfc04c943a4fa4b17');
INSERT INTO `drupal_shoutbox` VALUES (7,228,'julian.dabrowski','Bardzo funkcjonalnie. Oby tak dalej!','',0,1232317734,1232317734,'','ec07b5ec40676af73d8943f71f757ef3');
INSERT INTO `drupal_shoutbox` VALUES (8,158,'maria.urbanek','mam shout boxa!!!:)','',0,1232320146,1232320146,'','978124cf90dbfdc32bfa9acfde728d87');
INSERT INTO `drupal_shoutbox` VALUES (9,158,'maria.urbanek','Enter Messagethx','',0,1232320151,1232320151,'','978124cf90dbfdc32bfa9acfde728d87');
INSERT INTO `drupal_shoutbox` VALUES (10,158,'maria.urbanek','haha ale najpierw trzeba usunąć enter message :D','',0,1232320169,1232320169,'','978124cf90dbfdc32bfa9acfde728d87');
INSERT INTO `drupal_shoutbox` VALUES (11,206,'marcin.mikolajczak','mi samo znika jak klikam ;-)','',0,1232320519,1232320519,'','638ae93694d1b98cfc04c943a4fa4b17');
INSERT INTO `drupal_shoutbox` VALUES (12,158,'maria.urbanek','a mi raz nie znikło;)','',0,1232321884,1232321884,'','978124cf90dbfdc32bfa9acfde728d87');
INSERT INTO `drupal_shoutbox` VALUES (13,181,'mateusz.matloka','bo Cię nie lubi ;) mi znika na zawołanie','',0,1232328365,1232328365,'','b1cef3f55f275d60ca0c9e329b210887');
INSERT INTO `drupal_shoutbox` VALUES (14,158,'maria.urbanek','teraz też mi już znika:P ','',0,1232399111,1232399111,'','978124cf90dbfdc32bfa9acfde728d87');
INSERT INTO `drupal_shoutbox` VALUES (15,214,'anna.sliwinska','he ???','',0,1232527781,1232527781,'','29f21a2809d2e4d6082cea88ba22c11b');
INSERT INTO `drupal_shoutbox` VALUES (16,145,'leszek.bogucki','wracamy do zielonego forum, przy tym można usnąć:P','',0,1232623879,1232623879,'','7dd0cdf1686ddf9051d69bb192ac97e2');
INSERT INTO `drupal_shoutbox` VALUES (17,154,'piotr.kucharczyk','co jest takiego fajnego w tym forum?','',0,1232720234,1232720234,'','a2258d1f5aadbaadd67ecf1eb69603e1');
INSERT INTO `drupal_shoutbox` VALUES (18,164,'tomasz.antoszek','zimne.forum.pewnie.mniej.zawodne.pozdrawiam.nieniebiesko.zielono','',0,1232846291,1232846291,'','3a4fe1006729967538110f18173f5972');
INSERT INTO `drupal_shoutbox` VALUES (19,152,'magdalena.przezdziak','nadamy mu troche kolorku i będzie oki :)','',0,1232995001,1232995001,'','5f1dc70b90d03d50c8556a02d2862fe4');
INSERT INTO `drupal_shoutbox` VALUES (20,246,'aleksandra.kowalczuk','czy tu mozna wpisac podsumowanie ze spotkania zespołu???? (zagubiona Ola)','',0,1234036032,1234036032,'','123a295ae6db33e243402d86476d763d');
INSERT INTO `drupal_shoutbox` VALUES (21,246,'aleksandra.kowalczuk','juz znalazłam^^\' kto to widział umieszczać forum \"pod spodem\"? XD','',0,1234091943,1234091943,'','123a295ae6db33e243402d86476d763d');
INSERT INTO `drupal_shoutbox` VALUES (22,206,'marcin.mikolajczak','jest pod spodem żeby zachęcić do przeczytania innych postów przed odpowiedzią ;-)','',0,1234111125,1234111125,'','2d6f11680204227047052e30245ba3a0');
INSERT INTO `drupal_shoutbox` VALUES (23,163,'maciej.hojszyk','gdzie.te.niezimne.kolorki? :)','',0,1236726050,1236726050,'','ff5a9cb56c64946ab3bf211ea02ab619');
INSERT INTO `drupal_shoutbox` VALUES (24,158,'maria.urbanek','Rozumiem że nasze forum jest jak Gmail.... wciąż w wersji beta :D','',0,1237018757,1237018757,'','9e8d9a654d3113cee9d68d201d6ac8f4');
INSERT INTO `drupal_shoutbox` VALUES (25,233,'piotr.krzoska','Czy to forum ma w ogóle opcję wyszukiwania?','',0,1237742076,1237742076,'','b2f3a2495cf1684de7d9eb57ba894889');
INSERT INTO `drupal_shoutbox` VALUES (26,158,'maria.urbanek','Marcin, a pobaw się kolorami co? może seledyn? łososiowy? albo sraczkowaty? idzie wiosna - poszalejmy:D','',0,1237913233,1237913233,'','aa4aa14046e5bb7f4b3bd6ebfb53f0a8');
INSERT INTO `drupal_shoutbox` VALUES (27,178,'jakub.brzozowski','Widzę zmiany :)','',0,1238334691,1238334691,'','8bfc1e2a01d5db07c26a59d47cc467e8');
INSERT INTO `drupal_shoutbox` VALUES (28,206,'marcin.mikolajczak','Włączylem wyszukiwanie. Ale kolorkami (sorry) to ja nie mam czasu się bawić.','',0,1238336577,1238336667,'','74bb2f76689f5c80b0a7ebd07cdcb8f5');
INSERT INTO `drupal_shoutbox` VALUES (30,206,'marcin.mikolajczak','Forum powinno chodzić szybciej.','',0,1240348282,1240348282,'','325f7c58314eb05922876b3b922c66c8');
INSERT INTO `drupal_shoutbox` VALUES (31,134,'aleksandra.dettlaff','faktycznie chodzi szybciej:)','',0,1240442316,1240442316,'','416775631d59ed6f39e29dd06c9f4993');
INSERT INTO `drupal_shoutbox` VALUES (32,203,'agnieszka.zmyslowska','Śmiga, nawet bym rzekła ;) Marcin, jesteś wielki!','',0,1240509087,1240509087,'','729fa387bda32dfbfbc77e1558b760c3');
INSERT INTO `drupal_shoutbox` VALUES (33,188,'kamil.puk','Gratuluję wszystkim nowym członkom nowym :) !','',0,1241014628,1241014628,'','b1dda1760e0e36e16df3c3f43b4be974');
INSERT INTO `drupal_shoutbox` VALUES (34,206,'marcin.mikolajczak','Jeśli pisaliście coś na forum między 2009-05-03 18:00 a 2009-05-06 16:30 to sprawdźcie czy nadal jest.','',0,1241620049,1241620049,'','a8526d774602ca70aa6c5839685f7f75');
INSERT INTO `drupal_shoutbox` VALUES (35,158,'maria.urbanek','co to za linki na górze strony?','',0,1243288601,1243288601,'','09f56fd1ed6a7706e50e2a4e265e450d');
INSERT INTO `drupal_shoutbox` VALUES (36,203,'agnieszka.zmyslowska','Robi się nasza nowa strona www - wszyscy zaakceptowali nowy layout forum, więc www też będzie w takim :P','',0,1243357113,1243365969,'','b509a37c68cbe180d319a4026adec9fe');
INSERT INTO `drupal_shoutbox` VALUES (37,178,'jakub.brzozowski','Kiedy nowy layout będzie \"w użyciu\"?','',0,1243412310,1243412310,'','c22e21faddd4cad0fcfeee2ca7ccdf56');
INSERT INTO `drupal_shoutbox` VALUES (38,203,'agnieszka.zmyslowska','jak będzie gotowy i jak przekopiowana na Drupala będzie cała nasza strona.','',0,1243453094,1243453094,'','315e9605d599adce4df92ae1fbe0c658');
INSERT INTO `drupal_shoutbox` VALUES (39,158,'maria.urbanek','kim jest beta?','',0,1243519629,1243519629,'','bd2d47c999c052b33109eef623ddcfe4');
INSERT INTO `drupal_shoutbox` VALUES (40,201,'ewelina.siudowska','100 pytań do...:)','',0,1243533135,1243533135,'','3be8558c751e61f8999f3115cc9a8a80');
INSERT INTO `drupal_shoutbox` VALUES (41,228,'julian.dabrowski','kim jest maria.urbanek? ;>','',0,1243588957,1243588957,'','7ba5cb341b8063db73af07ec828be8b5');
INSERT INTO `drupal_shoutbox` VALUES (42,206,'marcin.mikolajczak','beta to jest konto administracyjne, na które czasem wchodzę, żeby trochę popsuć różnych rzeczy ;-)','',0,1245084708,1245084708,'','ee3a24d61a007312a0aaca0832689216');
INSERT INTO `drupal_shoutbox` VALUES (45,206,'marcin.mikolajczak','( macie wreszcie ten zielony! :-P )','',0,1247162731,1247162731,'','e1a941ff4094ff994a92c5e51f92bba3');
INSERT INTO `drupal_shoutbox` VALUES (46,181,'mateusz.matloka','gut dżob','',0,1247489768,1247489768,'','33cc320cc0787e08854eafc00fdf369a');
INSERT INTO `drupal_shoutbox` VALUES (44,206,'marcin.mikolajczak','w wakacyjnym prezencie pociąłem kawałek nowego layoutu, jeśli komuś przeszkadzają niedoróbki to może cofnąć w swoim koncie','',0,1247162657,1247162657,'','e1a941ff4094ff994a92c5e51f92bba3');
INSERT INTO `drupal_shoutbox` VALUES (47,246,'aleksandra.kowalczuk','o, proszę, jakie zielona niespodzianka! :D','',0,1248277722,1248277722,'','03ad79886f3cef4a913e29e8b0c888a1');
INSERT INTO `drupal_shoutbox` VALUES (48,228,'julian.dabrowski','od razu bardziej swojsko :D','',0,1249566109,1249566109,'','77753479b23cd0b22e924a9aa60786e6');
INSERT INTO `drupal_shoutbox` VALUES (50,206,'marcin.mikolajczak','uaktulaniłem dużo modułów Drupala, dajcie znać jeśli coś działa inaczej niż powinno','',0,1251748338,1251748338,'','138e34042ca1c73160e86b2f66a87fc2');
INSERT INTO `drupal_shoutbox` VALUES (51,161,'patrycja.lucka','oo jak tu ładnie :)','',0,1254216240,1254216240,'','0f39f174d39aee6cd311afb10be61e7a');
INSERT INTO `drupal_shoutbox` VALUES (52,134,'aleksandra.dettlaff','fajno :)','',0,1255027757,1255027757,'','c31e758fe4536b9ae2843f35eb90f0c7');
INSERT INTO `drupal_shoutbox` VALUES (53,188,'kamil.puk','Widzieliście nowe plakaty McKinsey w biurze? :D','',0,1256184018,1256184018,'','6ab226bef85d1f87cb4af3f9d6c9e21f');
INSERT INTO `drupal_shoutbox` VALUES (54,214,'anna.sliwinska','są świetne :) jak zawsze z resztą :)','',0,1256667329,1256667329,'','df296038bba42d31a6814132fe00af13');
INSERT INTO `drupal_shoutbox` VALUES (55,246,'aleksandra.kowalczuk','czy można sobie ustawić taką funkcję, aby na miala przychodziły wiadomości o tym, że ktoś dokonał wpisu na forum? ','',0,1260834572,1260834572,'','bb2187bcdf4190ddc2fcbae19ea2b113');
INSERT INTO `drupal_shoutbox` VALUES (56,206,'marcin.mikolajczak','można pomyśleć nad tym i poszukać sposobu jak to zrobić ;) wpiszę na listę','',0,1262898066,1262898066,'','1d5052fa2885cb60f3a4b3c117865a32');
INSERT INTO `drupal_shoutbox` VALUES (57,206,'marcin.mikolajczak','w kwestii pomysłów i zmian zapraszam na forum do działu feedback','',0,1263072217,1263072217,'','1d5052fa2885cb60f3a4b3c117865a32');
INSERT INTO `drupal_shoutbox` VALUES (58,134,'aleksandra.dettlaff','Wiki Cognitis! yeah!','',0,1264546568,1264546568,'','cecfd946d442da2c5bed6c10e85c3d6c');
INSERT INTO `drupal_shoutbox` VALUES (59,206,'marcin.mikolajczak','[url=http://www.cognitis.pl/pl/forum/wazne-ogloszenia/feedback-nowej-strony/zmiany-poprawki-ustawki-techniczne/1608#comment-4672]UWAGA! KONKURS! KLIKNIJ![/url]','',0,1265456551,1265456745,'','43e3df75c3d7e5762b0311f4d7ceaf0b');
INSERT INTO `drupal_shoutbox` VALUES (60,206,'marcin.mikolajczak','istnieje możliwość zrobienia powiadomień forum -> mail, jeśli jest na to zapotrzebowanie ;)','',0,1267105835,1267105835,'','c33679a7edaec7346c59dd09c60b8acf');
INSERT INTO `drupal_shoutbox` VALUES (61,246,'aleksandra.kowalczuk','zgłaszam popyt!','',0,1267118118,1267118118,'','f7f44ad942d6119ba689ded1b7c2dc55');
INSERT INTO `drupal_shoutbox` VALUES (62,181,'mateusz.matloka','A ile za takie cacko, Szefie?','',0,1267177711,1267179639,'','9e46c96cc8c2451e084d3a210e4eec0b');
INSERT INTO `drupal_shoutbox` VALUES (63,206,'marcin.mikolajczak','[url=http://www.cognitis.pl/pl/forum/wazne-ogloszenia/feedback-nowej-strony/zmiany-poprawki-ustawki-techniczne/1608#comment-4712]Done.[/url] Grunt to ciężko wywalczony know-how. Są powiadomienia!','',0,1267703897,1268052562,'','1388f1a2adf260160d9117223fe24204');
INSERT INTO `drupal_shoutbox` VALUES (64,246,'aleksandra.kowalczuk',':D czekam z utęsknieniem na pierwsze efekty ','',0,1269337508,1269337508,'','784b3eb8e9e42ab35e5791bb00c51613');
INSERT INTO `drupal_shoutbox` VALUES (65,181,'mateusz.matloka','Ja już dostałem swoje pierwsze powiadomienie :)','',0,1269524367,1269524367,'','833f57b276e4c7bfe2c1af165453c6bd');
INSERT INTO `drupal_shoutbox` VALUES (66,246,'aleksandra.kowalczuk','tej, to chyba jest odpowiedź tylko dla autora postu, tej nie? ;)','',0,1269536543,1269536543,'','784b3eb8e9e42ab35e5791bb00c51613');
INSERT INTO `drupal_shoutbox` VALUES (67,206,'marcin.mikolajczak','wydaje mi się, że powinno zakładać subskrypcję również przy odpowiadaniu','',0,1269559186,1269559186,'','07269495b2b13ea62892b9c5b77196cc');
INSERT INTO `drupal_shoutbox` VALUES (68,181,'mateusz.matloka','Z tego co zauważyłem - zakłada. Dobre rozwiązanie.','',0,1270963581,1270963581,'','777757a49759582b27894bc04ba86c36');
INSERT INTO `drupal_shoutbox` VALUES (69,246,'aleksandra.kowalczuk','a w którym miejscu co trzeba kliknąć? ','',0,1272317110,1272317110,'','b73acfd64a1c904fefbca959f5e53e28');
INSERT INTO `drupal_shoutbox` VALUES (70,246,'aleksandra.kowalczuk','dziwne... nie mogę dodawać komentarzy w sekcji \"wybory\". czyżbym wyczerpała swój limit? ;)','',0,1272373307,1272373307,'','b73acfd64a1c904fefbca959f5e53e28');
INSERT INTO `drupal_shoutbox` VALUES (71,202,'ada.silakiewicz','wpisałam notkę nie w ten wątek co trzeba - jak się usuwa? bo jestem ślepa..','',0,1272400847,1272400847,'','f42b1a2f307eea102e6a786b854699fc');
INSERT INTO `drupal_shoutbox` VALUES (72,246,'aleksandra.kowalczuk','oooo... kiedy wokół naszego zdjęcia pojawiła się \"mgiełka\"? :)','',0,1272530109,1272530109,'','b73acfd64a1c904fefbca959f5e53e28');
INSERT INTO `drupal_shoutbox` VALUES (73,318,'radoslaw.malek','pozdrawiam wakacyjnie!','',0,1279743416,1279743459,'','3eaccf0489ba5f66bfa21c5400ff76e1');
INSERT INTO `drupal_shoutbox` VALUES (74,298,'wojciech.dudziak','genialna IDEA! - wrzucajcie na shoutboxa swoje pomysły na przyciągnięcie ludzi na forum. shoutobxowa burza mózgów:) ','',0,1281111094,1281111094,'','86e656b98487208f44fe6c9aef84fd27');
INSERT INTO `drupal_shoutbox` VALUES (75,298,'wojciech.dudziak','Pomysł 1 - Wybieramy datę i robimy ustawkę na forum. Kto \"spłodzi\" najwięcej postów wygrywa nagrodę','',0,1281111156,1281111174,'','86e656b98487208f44fe6c9aef84fd27');
INSERT INTO `drupal_shoutbox` VALUES (76,318,'radoslaw.malek','to my mamy forum?','',0,1281129781,1281129781,'','be88eab431d55e1a9c5cc717a1b397b6');
INSERT INTO `drupal_shoutbox` VALUES (77,298,'wojciech.dudziak',':)\r\nW sensie miejsca owszem mamy, w sensie dyskusji i wymiany poglądów - to już nie bardzo\r\n\r\nTak więc odsyłam bezpośrednio do mojego tematu:\r\nhttp://www.cognitis.pl/pl/forum/inne/potrzebna-pomoc/szukam-pokoju-do-wynajecia/1802\r\nSzukam pokoju do wynajęcia','',0,1281435979,1281436093,'','1f7b712de3e7515e7044fcc422e73722');
/*!40000 ALTER TABLE `drupal_shoutbox` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

