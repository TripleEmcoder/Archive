
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
DROP TABLE IF EXISTS `drupal_i18n_variable`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `drupal_i18n_variable` (
  `name` varchar(128) NOT NULL default '',
  `language` varchar(12) NOT NULL default '',
  `value` longtext NOT NULL,
  PRIMARY KEY  (`name`,`language`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `drupal_i18n_variable` WRITE;
/*!40000 ALTER TABLE `drupal_i18n_variable` DISABLE KEYS */;
INSERT INTO `drupal_i18n_variable` VALUES ('site_name','pl','s:23:\"Cognitis (dawniej SKND)\";');
INSERT INTO `drupal_i18n_variable` VALUES ('site_slogan','pl','s:51:\"Stowarzyszenie Przyszłych Doradców i Menedżerów\";');
INSERT INTO `drupal_i18n_variable` VALUES ('site_mission','pl','s:0:\"\";');
INSERT INTO `drupal_i18n_variable` VALUES ('site_footer','pl','s:0:\"\";');
INSERT INTO `drupal_i18n_variable` VALUES ('site_frontpage','pl','s:11:\"aktualnosci\";');
INSERT INTO `drupal_i18n_variable` VALUES ('site_name','en','s:24:\"Cognitis (formerly SKND)\";');
INSERT INTO `drupal_i18n_variable` VALUES ('site_slogan','en','s:46:\"Association of Future Consultants and Managers\";');
INSERT INTO `drupal_i18n_variable` VALUES ('site_mission','en','s:0:\"\";');
INSERT INTO `drupal_i18n_variable` VALUES ('site_footer','en','s:0:\"\";');
INSERT INTO `drupal_i18n_variable` VALUES ('site_frontpage','en','s:4:\"news\";');
INSERT INTO `drupal_i18n_variable` VALUES ('anonymous','en','s:9:\"Anonymous\";');
INSERT INTO `drupal_i18n_variable` VALUES ('anonymous','pl','s:9:\"Anonymous\";');
INSERT INTO `drupal_i18n_variable` VALUES ('date_format_long','pl','s:15:\"l, j. F Y - G:i\";');
INSERT INTO `drupal_i18n_variable` VALUES ('date_format_medium','pl','s:14:\"D, d.m.Y - H:i\";');
INSERT INTO `drupal_i18n_variable` VALUES ('date_format_short','pl','s:11:\"d.m.Y - H:i\";');
INSERT INTO `drupal_i18n_variable` VALUES ('cron_last','pl','i:1287390747;');
INSERT INTO `drupal_i18n_variable` VALUES ('advanced_help_last_cron','pl','a:1:{s:4:\"time\";i:1287390743;}');
INSERT INTO `drupal_i18n_variable` VALUES ('linkchecker_cleanup_links_last','pl','i:1287390744;');
INSERT INTO `drupal_i18n_variable` VALUES ('googleanalytics_last_cache','pl','i:1287390733;');
INSERT INTO `drupal_i18n_variable` VALUES ('conditional_styles_zen','en','s:122:\"<!--[if IE]>\n<link type=\"text/css\" rel=\"stylesheet\" media=\"all\" href=\"/sites/all/themes/zen/zen/ie.css?A\" />\n<![endif]-->\n\";');
INSERT INTO `drupal_i18n_variable` VALUES ('date_format_long','en','s:16:\"l, F j, Y - g:ia\";');
INSERT INTO `drupal_i18n_variable` VALUES ('date_format_medium','en','s:15:\"D, m/d/Y - g:ia\";');
INSERT INTO `drupal_i18n_variable` VALUES ('date_format_short','en','s:12:\"m/d/Y - g:ia\";');
INSERT INTO `drupal_i18n_variable` VALUES ('menu_masks','en','a:31:{i:0;i:127;i:1;i:125;i:2;i:117;i:3;i:63;i:4;i:62;i:5;i:61;i:6;i:60;i:7;i:59;i:8;i:58;i:9;i:56;i:10;i:45;i:11;i:44;i:12;i:31;i:13;i:30;i:14;i:29;i:15;i:24;i:16;i:23;i:17;i:22;i:18;i:21;i:19;i:15;i:20;i:14;i:21;i:12;i:22;i:11;i:23;i:10;i:24;i:7;i:25;i:6;i:26;i:5;i:27;i:4;i:28;i:3;i:29;i:2;i:30;i:1;}');
INSERT INTO `drupal_i18n_variable` VALUES ('css_js_query_string','en','s:20:\"AB3oPRLjcFsh2Exybgun\";');
INSERT INTO `drupal_i18n_variable` VALUES ('conditional_styles_zen','pl','s:122:\"<!--[if IE]>\n<link type=\"text/css\" rel=\"stylesheet\" media=\"all\" href=\"/sites/all/themes/zen/zen/ie.css?t\" />\n<![endif]-->\n\";');
INSERT INTO `drupal_i18n_variable` VALUES ('conditional_styles_zen_cognitis','pl','s:122:\"<!--[if IE]>\n<link type=\"text/css\" rel=\"stylesheet\" media=\"all\" href=\"/sites/all/themes/zen/zen/ie.css?t\" />\n<![endif]-->\n\";');
INSERT INTO `drupal_i18n_variable` VALUES ('me_theme_menu_item_link','pl','s:18:\"zen_menu_item_link\";');
INSERT INTO `drupal_i18n_variable` VALUES ('statistics_day_timestamp','en','i:1287342435;');
INSERT INTO `drupal_i18n_variable` VALUES ('advanced_help_last_cron','en','a:1:{s:4:\"time\";i:1287406127;}');
INSERT INTO `drupal_i18n_variable` VALUES ('node_cron_last','en','s:10:\"1287089036\";');
INSERT INTO `drupal_i18n_variable` VALUES ('statistics_day_timestamp','pl','i:1287390734;');
INSERT INTO `drupal_i18n_variable` VALUES ('css_js_query_string','pl','s:20:\"tDWA3oPRLjcFsh2Exybg\";');
INSERT INTO `drupal_i18n_variable` VALUES ('site_offline','en','s:1:\"0\";');
INSERT INTO `drupal_i18n_variable` VALUES ('conditional_styles_zen_cognitis','en','s:122:\"<!--[if IE]>\n<link type=\"text/css\" rel=\"stylesheet\" media=\"all\" href=\"/sites/all/themes/zen/zen/ie.css?A\" />\n<![endif]-->\n\";');
INSERT INTO `drupal_i18n_variable` VALUES ('xmlsitemap_regenerate_needed','pl','b:0;');
INSERT INTO `drupal_i18n_variable` VALUES ('xmlsitemap_generated_last','pl','i:1287040806;');
INSERT INTO `drupal_i18n_variable` VALUES ('xmlsitemap_engines_submit_last','pl','i:1287040806;');
INSERT INTO `drupal_i18n_variable` VALUES ('cron_last','en','i:1287406132;');
INSERT INTO `drupal_i18n_variable` VALUES ('linkchecker_cleanup_links_last','en','i:1287342443;');
INSERT INTO `drupal_i18n_variable` VALUES ('googleanalytics_last_cache','en','i:1287342435;');
INSERT INTO `drupal_i18n_variable` VALUES ('node_cron_last','pl','s:10:\"1287083532\";');
INSERT INTO `drupal_i18n_variable` VALUES ('mimemail_engine','en','s:9:\"phpmailer\";');
INSERT INTO `drupal_i18n_variable` VALUES ('node_cron_views_scale','pl','d:6.2996094242156983901946565307383707477129064500331878662109375E-5;');
INSERT INTO `drupal_i18n_variable` VALUES ('drupal_http_request_fails','pl','b:0;');
INSERT INTO `drupal_i18n_variable` VALUES ('javascript_parsed','en','a:10:{i:0;s:14:\"misc/jquery.js\";i:1;s:14:\"misc/drupal.js\";i:2;s:48:\"sites/all/modules/lightbox2/js/lightbox_modal.js\";i:3;s:42:\"sites/all/modules/lightbox2/js/lightbox.js\";i:4;s:56:\"sites/all/modules/tableofcontents/jquery.scrollTo-min.js\";i:5;s:59:\"sites/all/modules/tableofcontents/jquery.localscroll-min.js\";i:6;s:52:\"sites/all/modules/tableofcontents/tableofcontents.js\";i:7;s:53:\"sites/all/modules/google_analytics/googleanalytics.js\";s:10:\"refresh:pl\";s:7:\"waiting\";i:8;s:16:\"misc/textarea.js\";}');
INSERT INTO `drupal_i18n_variable` VALUES ('node_cron_views_scale','en','d:6.287331027978623168746274973983645395492203533649444580078125E-5;');
INSERT INTO `drupal_i18n_variable` VALUES ('forum_containers','pl','a:2:{i:3;s:2:\"71\";i:4;s:3:\"222\";}');
INSERT INTO `drupal_i18n_variable` VALUES ('javascript_parsed','pl','a:35:{i:0;s:14:\"misc/jquery.js\";i:1;s:14:\"misc/drupal.js\";i:2;s:48:\"sites/all/modules/lightbox2/js/lightbox_modal.js\";i:3;s:42:\"sites/all/modules/lightbox2/js/lightbox.js\";i:4;s:56:\"sites/all/modules/tableofcontents/jquery.scrollTo-min.js\";i:5;s:59:\"sites/all/modules/tableofcontents/jquery.localscroll-min.js\";i:6;s:52:\"sites/all/modules/tableofcontents/tableofcontents.js\";i:7;s:53:\"sites/all/modules/google_analytics/googleanalytics.js\";i:8;s:91:\"sites/all/modules/views_slideshow/contrib/views_slideshow_thumbnailhover/views_slideshow.js\";i:9;s:60:\"sites/all/modules/views_slideshow/js/jquery.cycle.all.min.js\";i:10;s:17:\"misc/tabledrag.js\";i:11;s:58:\"sites/all/modules/conditional_fields/conditional_fields.js\";i:12;s:62:\"sites/all/modules/date/date_popup/lib/jquery.timeentry.pack.js\";i:13;s:47:\"sites/all/modules/date/date_popup/date_popup.js\";i:14;s:16:\"misc/textarea.js\";i:15;s:19:\"misc/tableheader.js\";i:16;s:47:\"sites/all/modules/l10n_client/jquery.hotkeys.js\";i:17;s:46:\"sites/all/modules/l10n_client/jquery.cookie.js\";i:18;s:44:\"sites/all/modules/l10n_client/l10n_client.js\";i:19;s:19:\"misc/jquery.form.js\";i:20;s:12:\"misc/ahah.js\";i:21;s:16:\"misc/progress.js\";i:22;s:16:\"misc/collapse.js\";i:23;s:42:\"sites/all/modules/admin_menu/admin_menu.js\";i:24;s:28:\"modules/taxonomy/taxonomy.js\";i:25;s:60:\"sites/all/modules/hierarchical_select/hierarchical_select.js\";i:26;s:72:\"sites/all/modules/hierarchical_select/hierarchical_select_formtoarray.js\";i:27;s:66:\"sites/all/modules/hierarchical_select/js/jquery.ui/effects.core.js\";i:28;s:66:\"sites/all/modules/hierarchical_select/js/jquery.ui/effects.drop.js\";i:29;s:47:\"sites/all/modules/privatemsg/privatemsg-list.js\";i:30;s:19:\"misc/tableselect.js\";i:31;s:38:\"sites/all/modules/teleport/teleport.js\";i:32;s:20:\"misc/autocomplete.js\";i:33;s:12:\"misc/form.js\";i:34;s:20:\"modules/user/user.js\";}');
/*!40000 ALTER TABLE `drupal_i18n_variable` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

