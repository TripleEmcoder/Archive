<?php
// $Id: xmlsitemap_engines.api.php,v 1.1.2.1 2009/05/23 18:38:55 davereid Exp $

/**
 * @file
 * Documentation for xmlsitemap_engines API.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Alter the list of sitemap engines.
 */
function hook_xmlsitemap_engines_alter(&$engines) {
  $engines['kitten_engine'] = array(
    'name' => t('Kitten Search'),
    'url' => 'http://kittens.com/ping?sitemap=[sitemap]',
  );
}

/**
 * @} End of "addtogroup hooks".
 */
