
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
DROP TABLE IF EXISTS `drupal_pm_message`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_pm_message` (
  `mid` int(10) unsigned NOT NULL auto_increment,
  `author` int(10) unsigned NOT NULL,
  `subject` varchar(255) NOT NULL,
  `body` longtext NOT NULL,
  `timestamp` int(10) unsigned NOT NULL,
  `format` smallint(6) NOT NULL default '0',
  PRIMARY KEY  (`mid`)
) ENGINE=MyISAM AUTO_INCREMENT=112 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_pm_message` WRITE;
/*!40000 ALTER TABLE `drupal_pm_message` DISABLE KEYS */;
INSERT INTO `drupal_pm_message` VALUES (65,1,'cos','sdfswfdsfdsf',1161897166,1);
INSERT INTO `drupal_pm_message` VALUES (66,1,'cfdf','cdfdfdf',1161941645,1);
INSERT INTO `drupal_pm_message` VALUES (67,164,'Re: gg','2548495\r\n\r\npozdrawiam\r\ntomek\r\n\r\nP.S. jestem na skype. mozemy za chwil kilka talk',1171534717,1);
INSERT INTO `drupal_pm_message` VALUES (68,150,'Fun Corner','Aloha. \r\nAbsolutnie nie chcialbym sie madrowac, wolalbym zebyscie potraktowali to jako maly feedback. Sprawa tyczy sie scisle najbardziej luznego dzialu jakim jest FunCorner. Wedlug mnie powinno sie pilnowac, aby uzytkownicy przy kazdym smiesznym liknu nie zakladali nowego topica, tylko wrzucali wszystko do jednego tematu typu: nitki, sznurki, linki, kabelki, itp. W przeciwnym razie pewnie zrobi sie 150 tematow, w ktorych kazdy bedzie mial po jednym laczu.  \r\n pozdrawiam',1162255984,1);
INSERT INTO `drupal_pm_message` VALUES (69,139,'Kontakt!','Kiedy mozna sie z Toba spotkac? Moze skype: tristypl ??\r\nChodzi mi o stypendia do Niemiec, Hiszpani i Austri, kierunki techniczne - Informatyka szczegolnie. \r\nPozdrawiam!',1162286735,1);
INSERT INTO `drupal_pm_message` VALUES (70,139,'aplikacja online.','Tak apropo generecji pomysłów...\r\n\r\nA może SAP e-Recruiting? Spróbować dogadać się z BCC, by nas nadzorowali i zrobić w teamie pierwsze poważniejsze wdrożenie systemów. Pierwsza poważna praktyka. Czytałem trochę o tym i ma to wielgaśną funkcjonalność nawet powiem za dużą jeśli chodzi o nas. Jednak! Czy nie była by to dobra szansa na pierwszą współpracę z firmą IT? \r\n Jeśli tak, to trzeba by przygotować już poważny plan - team ds. KZ. \r\n Co o tym myślisz? \r\nPozdrawiam!',1162287045,1);
INSERT INTO `drupal_pm_message` VALUES (71,153,'gg','Cześć :)\r\nWidzę, że jesteś na forum ;) więc przy okazji chciałbym Cię prosić o Twój nr gg w celu usprawnienia komunikacji :)',1171534146,1);
INSERT INTO `drupal_pm_message` VALUES (72,160,'trening','Hej,\r\nja się zgłosiłam. Ale ponieważ tam trzeba było podać dane organizacji i osobę kontaktową to podałam Tomka, bo szczerze mówiąc nie mam pojecia czy napisac Ciebie czy kogo. Orientujesz sie czy ktos od nas sie jeszcze zglasza?\r\nPozdrawiam! :)',1188850672,1);
INSERT INTO `drupal_pm_message` VALUES (73,161,'pytanko','Jestem \"nowa\" na forum...o co chodzi z dniem z życia licealisty???\r\nPOZDRAWIAM',1163882885,1);
INSERT INTO `drupal_pm_message` VALUES (74,151,'Re: pytanko','filmik zrobiony przez małolatów na wzór dnia świra.. było dużo negatywnych wypowiedzi na jego temat, więc usunąłem link. pozdrawiam!',1163928818,1);
INSERT INTO `drupal_pm_message` VALUES (75,135,'STI4','Hej,\r\n\r\nNa pewno mieści się w tym 7 zł za sobotni obiad. Reszta zależy czy przyjedziesz już na śniadanie i czy planujesz zostać na kolację. \r\n\r\nMyślę, że koszt sobotniego pobytu zamykałby sie w 12-15 zł\r\n\r\nPozdrawiam',1172089008,1);
INSERT INTO `drupal_pm_message` VALUES (76,143,'Brand new brand','Ja bym potrzebował :-) Możesz mi podesłać pakiecik? Dzięki!',1173708787,1);
INSERT INTO `drupal_pm_message` VALUES (77,143,'Artykuły do bankowości','Cześć MArysia,\r\n\r\nCoś nie za bardzo jestem aktywny w odniesieniu do Twojego projektu, prawie zapomniałem  że mogę Wam pomóc w pisaniu artykułów. Ja przecież napisałem pracę magisterską na temat M&A, a konkretnie wrogich przejęć, a także opublikowałem artykuł naukowy na ten sam temat. Mogę Ci je przesłać, wydaje mi się że to może Wam pomóc przy pisaniu artykułów. One mogą być dla Was o tyle ciekawe, że odnoszą się do transakcji bardzo świeżych (lata 1999-2005), na których temat nie wydano jeszcze żadnych książek, a na pewno tych książek nie ma w bibliotece AE ;-)\r\n\r\nZ drugiej strony wydaje mi się, że co najmniej jeden artykuł na temat wrogich przejęć powinien się pojawić na naszej stronce ;-) to bardzo ciekawy temat, i dość bliski sedna M&A (moja uwaga: wydaje mi się że bliższy niż kilka tematów które Twój zespół opracowuje). W moich pracach jest też sporo ogólnie o M&A, to może pomóc w zlapaniu ogólnego obrazu, oraz dość bogata bibliografia, do której pomocniczo możecie sprobować sięgnąć.  \r\n\r\nCo Ty na to?\r\n\r\nPozdrawiam,\r\n\r\nMateusz',1173795576,1);
INSERT INTO `drupal_pm_message` VALUES (78,158,'Re: Artykuły do bankowości','Jak najbardziej jestem chętna:) Proszę niniejszym o ich przesłanie.\r\nCzy zgodziłbyś się również na to żeby były opublikowane na naszej stronie?\r\n\r\nRozumiem że jest sporo pracy więc dlatego nie zawsze się myśli w pierwszej kolejności o innych projektach gdy samemu się już własne robi:) \r\n\r\nPozdrawiam\r\n\r\nMaria',1173822756,1);
INSERT INTO `drupal_pm_message` VALUES (79,143,'Re: Artykuły do bankowości','HEj,\r\n\r\nOczywiście że się zgadzam, prześlę Ci w najbliższych dniach. Tyle że raczej nie widzę tego, by to publikować w całości, bo:\r\n\r\n1. Nie mam już do nich praw autorskich, nie mogę nimi dysponować - musialem je przekazać mojej katedrze i wydawnictwu\r\n\r\n2. To za duże i za trudne (napisane są w końcu pismem naukowym, nie popularno - naukowym ;-) )\r\n\r\nProponuję, że ja Ci to prześlę a Ty dasz zespołowi, żeby napisali na tej podstawie parę artykułów osobnych. Wówczas po prostu podpiszemy się jako współautorzy: Mateusz Łakomy i np. Magdalena Marszałek\r\n\r\nMoże być?\r\n\r\nPozdrawiam,\r\n\r\nMateusz\r\n\r\nP.S. Jak będę miał czas, to chętnie przejrzę merytorycznie artykuly, jakie Twój zespół napisał dotychczas, daj mi tylko sygnał kiedy mogłoby to być i do kiedy deadline ;-)',1173874131,1);
INSERT INTO `drupal_pm_message` VALUES (80,171,'A jednak się da:)','Hej!\r\nJak w temacie:)\r\npozdr\r\nNie Aga',1174769389,1);
INSERT INTO `drupal_pm_message` VALUES (81,181,'Re: :)','Bez przesady, tworzyłem go zupełnie spontanicznie :wink:.\r\n\r\nA zresztą jaki by nie był - skuteczność zerowa :neutral:, taka już specyfika nawoływań do ogółu. Wszyscy ludzie na tyle nienormalni, by ciągle gdzieś działać, są zaangażowani w swoje projekty :grin:.\r\n\r\nTymczasem więc wykorzystałem inne techniki zebrania zespołu. Rekrutacja jednak jeszcze otwarta, zaczynamy na poważnie w następnym tygodniu.\r\n\r\nTaką więc mam drobną prośbę, a nuż w czymś pomożesz. Czy mogłabyś mi z Jakości polecić tak jedną, góra dwie osoby, które mogłyby być chętne do zaangażowania się w KWE? Nie chodzi mi tylko i wyłącznie o osoby bardzo proaktywne - takie zwykle same znajdują sobie projekty. \r\n\r\nAle może masz u siebie kogoś, kto jest zdolny i pomysłowy, ale widzisz, że nie za bardzo znajduje swoje miejsce tudzież po prostu nie działa w żadnym projekcie?\r\n\r\nZpewne wiesz, o co mi chodzi. Takie osoby, które warto zatrzymać przed możliwym odpłynięciem z SKND. Zresztą każda kandydatura mile widziana. Zakładam, że wyśmienicie znasz swój zespół :)\r\n\r\nPozdrawiam,\r\nMM',1203111471,1);
INSERT INTO `drupal_pm_message` VALUES (82,134,':)','dostaeś kiedyś już prywatną wiadomość na naszym forum? :) ;p',1175823154,1);
INSERT INTO `drupal_pm_message` VALUES (83,136,'Re: :)','Nie  :D  ta była pierwsza  :D \r\n\r\nDziękuję  :wink:\r\n\r\nKorzystając z okazji przesyłam przedświąteczne pozdrownienia, pachnące wiosną i zieloną trawką :D\r\n\r\nKamil',1175885268,1);
INSERT INTO `drupal_pm_message` VALUES (84,156,'sport','Kamilu, \r\n\r\njeśli na zamówioną salę przychodą 4 osoby, bo inne zespoly mają zebrania, to zanim wydamy kolejne 120 zł wolałabym wiedzieć czy ktoś przyjdzie tym razem ;) Jeszcze nie spotkałam się z sytuacją żeby ktoś przekładał zebranie, bo jest integracja, chociaz miło słyszeć, że komuś zależy...\r\n\r\npozdrawiam,\r\nJ.',1178800897,1);
INSERT INTO `drupal_pm_message` VALUES (85,144,'Re: trening','Nikt inny nie powiadomił mnie, że się wybiera, ale jeżeli ktoś jeszcze napisze mi, że rusza na Słowację, to dam Ci znać :grin:',1189070698,1);
INSERT INTO `drupal_pm_message` VALUES (86,184,'Problemy z przeglądaniem forum','Witam!\r\n\r\nW pośpiechu zarejestrowałem się na forum poprzez szybką rejestrację i nie doszedł do mnie mail aktywujący konto. Czy coś się da z tym zrobić??\r\n\r\nPozdrawiam',1194197185,1);
INSERT INTO `drupal_pm_message` VALUES (87,185,':)','co tam szrajbiesz Prezes?',1195235231,1);
INSERT INTO `drupal_pm_message` VALUES (88,188,'Re: Życzenia!','Serdecznie dziękuję za życzenia - teraz pozostaje mi tylko troche pomóc i dać okazję im się spełnić ;)\r\ndzięki,\r\npzdr,\r\n~k',1203379986,1);
INSERT INTO `drupal_pm_message` VALUES (89,181,'Życzenia!','Wspaniałych pomysłów, niegasnącego zapału, spokoju ducha, radości i piękna dnia codziennego i umiejętności godzenia spraw najważniejszych z tymi bardziej błahymi życzę Tobie w dniu urodzin. :)\r\n\r\nMateusz',1203376253,1);
INSERT INTO `drupal_pm_message` VALUES (90,134,':)','haha :) fajny post zachęcający do udziału w projekcie KWE :mrgreen: ! :)',1201659980,1);
INSERT INTO `drupal_pm_message` VALUES (91,142,'100 lat','Wszystkiego najlepszego :)',1197617984,1);
INSERT INTO `drupal_pm_message` VALUES (92,143,'EuroDesk','Alu, odnośnie info na EuroDesk: gratuluję zamieszczenia, nie wiedziałem że taki serwis istnieje. Mam jednak wrażenie, że informacja o SKND jest trochę zubożona. Czy można dodać dosłownie 2 słowa o zasadach/rozwoju osobowości (oczywiście w bardzo ładny i zgrabny sposób :-) ) Co sądzisz?\r\n\r\nPozdrawiam,\r\n\r\nMateusz',1200593294,1);
INSERT INTO `drupal_pm_message` VALUES (93,142,':)','wszystkiego naj :)',1204675591,1);
INSERT INTO `drupal_pm_message` VALUES (94,197,'mail służbowy','hej\r\nhasło Twojego maila zostalo ustawione na\r\nmichal.durski\r\n\r\nPozdrawiam!',1207731695,1);
INSERT INTO `drupal_pm_message` VALUES (95,134,'Tel','Hej Łukasz, widzę, że często wchodzisz na forum, jednak nie mogę skontaktować się z Tobą telefonicznie? Zmieniłeś numer? Jeśli tak to proszę podaj mi aktualny lub zadzwoń do mnie w wolnej chwili - 663 827 569.\r\n\r\nChciałabym porozmawiać. \r\nPozdrawiam,\r\nOla',1221334035,1);
INSERT INTO `drupal_pm_message` VALUES (96,134,':)','Twoje posty są genialne - bardzo przyjemnie się je czyta. Podajesz istotne informacje w tak lekki sposób.. :)\r\n\r\nPozdrawiam i życzę prawdziwie świątecznych Świąt,\r\nOla',1230077520,1);
INSERT INTO `drupal_pm_message` VALUES (97,228,'Re: :)','Dziękuję Ci Olu, za miłego feedbacka.\r\n\r\nWszystkiego najlepszego w nowym roku :)\r\n\r\nJul',1230820539,1);
INSERT INTO `drupal_pm_message` VALUES (98,246,'joł! ','Chciałam podziekować Tobie, Leszku, za zdjęcia^^. nie spodziewałam się, że dostaniemy je aż tak szybko!^^ Dużo o tym myślałam dzisiaj więc chyba zmotywowałam Ciebie drogą telepatyczną ;P\r\nPozdrowienia!\r\nOla K.',1236642179,1);
INSERT INTO `drupal_pm_message` VALUES (99,145,'joł! ','Sorry, że tak późno odpisuję, ale dopiero teraz zauważyłem message na privie na forum, nigdy nie korzystałem dotychczas z tej formy komunikacji - polecam email:P Cóż...ja zawsze wysyłam szybko...\r\n\r\npozdr',1237588989,1);
INSERT INTO `drupal_pm_message` VALUES (100,151,'Haj!','Jak Ci w Dojczlandzie? ;)',1256157921,1);
INSERT INTO `drupal_pm_message` VALUES (101,151,'Hej!','Widzę, że jesteś na forum, więc się odzywam:)\r\n\r\nJak się na filozofii podoba?',1256157990,1);
INSERT INTO `drupal_pm_message` VALUES (102,269,'Hej!','Witaj! :) \r\nNa filozofii bardzo pozytywnie, troszeczkę mało tam zorganizowani na tym instytucie, ale powoli się wszystko normuje :) Już udało mi się ułożyć plan tak jak chciałam i teraz tylko pozostaje korzystać z przyjemnych zajęć :) \r\nSzczerze mówiąc to właśnie miałam dziś do Ciebie pisać, czy może pojawisz się na STI9? ',1256159340,1);
INSERT INTO `drupal_pm_message` VALUES (103,140,'Haj!','Hej Piotrku!!!\r\n\r\nmiło, że o mnie pamiętałeś :-)\r\n\r\nZasadniczo przebywam w Austrii :p ale z Salzburga do południowej granicy Niemiec jedzie sie pociągiem jakieś.... 12 minut :D\r\n\r\nMiewam się całkiem nieźle: na co dzień zajmuję się ciekawymi rzeczami, działam z świetnymi ludźmi, dużo się uczę, aktywnie spędzam wolny czas - spełniam swoje marzenia! Do tego piękne Alpy dookoła. Jest nie najgorzej :-))\r\n\r\nZ Austriakami idzie się (już) dogadać :-) Posługują się językiem, który często niewiele ma wspólnego z niemieckim :p Ale nauka okolicznego dialektu sprawia wiele frajdy, więc jest ok.\r\n\r\nW ogóle pobyt tutaj to dla mnie czas bogaty w nowe doświadczenia i przemyślenia... Zdecydowanie nie żałuję decyzji o wyjeździe, choć czasem zatęskni się naszą gromadką... :-)\r\n\r\nA co słychać u Ciebie nad Odrą/Wartą? ;-)\r\n\r\nPozdrawiam serdecznie!\r\nAla',1256232820,1);
INSERT INTO `drupal_pm_message` VALUES (104,151,'Haj!','U mnie wszystko w najlepszym porządku - dużo podróżuję:) ostatnio spędziłem 2 tygodnie w Kaliszu w ramach programu stażowego w Lorenz. Generalnie to jestem przypisany do fabryczki w Stanowicach, ale do połowy listopada będę w Poznaniu. Poznaję ciekawych ludzi (przemieszczam się z przedstawicielami handlowymi), a przy okazji spieram się odnośnie granicy pomiędzy manipulacją a stosowaniem technik sprzedażowych;p\r\n\r\nJak będziesz w okolicach Wrocławia albo Poznania to dawaj znać:)\r\n\r\nPozdrowionka!',1256382116,1);
INSERT INTO `drupal_pm_message` VALUES (105,151,'Hej!','Niestety, jak już zapewne zauważyłaś sądząc po porze w jakiej piszę - nie będzie mnie na STI. W poniedziałek mam zamiar zostać magistrem inżynierem i wymaga to niewielkich przygotowań, na które w tygodniu normalnie nie mam czasu:)\r\n\r\nMam nadzieję, że uda nam się spotkać w innych okolicznościach flory i fauny;p\r\n\r\nPozdrowionka!',1256382270,1);
INSERT INTO `drupal_pm_message` VALUES (106,140,'Haj!','Cieszę się, że u Ciebie wszystko OK :-)\r\n\r\nW Polsce będę najszybciej o okolicach około-świątecznych. Na pewno dam znać! :)\r\n\r\nPozdrawiam!',1256489293,1);
INSERT INTO `drupal_pm_message` VALUES (107,167,'wejście do formularza do bazy kontaktów','Hej,\r\nudało mi się wejść na forum, czego nie mogę jednak zrobić przechodząc z linku, który zamieściłeś w swoim mailu o bazie kontaktów. Gdzie na forum mam szukać formularza?\r\n\r\ndziękuję.\r\n\r\npozdrawiam,\r\nBeata',1257287850,1);
INSERT INTO `drupal_pm_message` VALUES (108,322,'cześć','jak tam po powrocie? Może zorganizujemy jakieś małe spotkanie dla kandydatów żeby poznać resztę osób. Pozdrowienia;]',1267489106,1);
INSERT INTO `drupal_pm_message` VALUES (109,318,'jutro','biorę komputer',1286918619,1);
INSERT INTO `drupal_pm_message` VALUES (110,318,'test','hej',1286919526,1);
INSERT INTO `drupal_pm_message` VALUES (111,318,'test','testuję prywatne wiadomości. proszę odezwij się, kiedy ją zauważysz',1287047731,1);
/*!40000 ALTER TABLE `drupal_pm_message` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

