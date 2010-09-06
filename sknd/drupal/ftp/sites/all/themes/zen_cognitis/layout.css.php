<?php
header('Content-Type: text/css');
$page_width = 980;
$left_sidebar_width = 200;
$right_sidebar_width = 150;
$content_margin = 15;
?>
/* $Id: layout-fixed.css,v 1.5.2.3 2009/02/13 19:20:19 johnalbin Exp $ */

/*
 * LAYOUT STYLES
 *
 * Define CSS classes to create a table-free, 3-column, 2-column, or single
 * column layout depending on whether blocks are enabled in the left or right
 * columns.
 *
 * This layout is based on the Zen Columns layout method.
 *   http://drupal.org/node/201428
 *
 * Only CSS that affects the layout (positioning) of major elements should be
 * listed here.  Such as:
 *   display, position, float, clear, width, height, min-width, min-height
 *   margin, border, padding, overflow
 */


/** body **/
  body
  {
    margin: 0;
  }

  #page
  {
    margin-left: auto;
    margin-right: auto;
    width: <?php print($page_width); ?>px;
  }

/** header **/
  #header
  {
  }

  #secondary-links
  {
    float: right;
    clear: right;
    padding: <?php print($content_margin); ?>px;
  }

  #search-box
  {
    width: 200px;
    margin-right: -200px; /* Negative value of #search-box's width. */
    float: left;
  }

/** navbar **/
  #navbar
  {
  }

  #primary-links li
  {
    float: left;
  }

/** main (container for everything else) **/
  #main
  {
    position: relative;
  }

  #main > *
  {
    margin-top: <?php print($content_margin); ?>px;
    margin-bottom: <?php print($content_margin); ?>px;
  }

/** content & sidebars **/
  #content
  {
     float: left;
     overflow-x: auto;
     overflow-y: hidden;
  }

  .no-sidebars #content
  {
    margin-left: <?php print($content_margin); ?>px;
    margin-right: <?php print($content_margin); ?>px;
  }

  .sidebar-left #content
  {
    width: <?php print($page_width - $left_sidebar_width - 3 * $content_margin); ?>px;
    margin-left: <?php print($left_sidebar_width + 2 * $content_margin); ?>px;
    margin-right: <?php print(- $page_width - $left_sidebar_width - 2 * $content_margin); ?>px;
  }

  .sidebar-right #content
  {
    width: <?php print($page_width - $right_sidebar_width - 3 * $content_margin); ?>px;
    margin-left: <?php print($content_margin); ?>px;
    margin-right: <?php print(- $right_sidebar_width - 2 * $content_margin); ?>px;
  }

  .two-sidebars #content
  {
    width: <?php print($page_width - $left_sidebar_width - $right_sidebar_width - 4 * $content_margin); ?>px;
    margin-left: <?php print($left_sidebar_width + 2 * $content_margin); ?>px;
    margin-right: <?php print(- $page_width - $right_sidebar_width - 2 * $content_margin); ?>px;
  }

  #sidebar-left
  {
    float: left;
    width: <?php print($left_sidebar_width); ?>px;
    margin-left: <?php print($content_margin); ?>px;
  }

  #sidebar-right
  {
    float: right;
    width: <?php print($right_sidebar_width); ?>px;
    margin-right: <?php print($content_margin); ?>px;
  }

  div.block
  {
    margin-bottom:  <?php print($content_margin); ?>px;
  }

/** footer **/
  #footer
  {
    margin-left: <?php print($content_margin); ?>px;
    margin-right: <?php print($content_margin); ?>px;
  }

  #footer-links
  {
    padding: <?php print($content_margin); ?>px;
  }

/** Prevent overflowing content **/
  #header,
  #sidebar-left,
  #sidebar-right,
  #footer
  {
    overflow: visible;
  }

  #navbar
  {
    overflow: hidden; /* May need to be removed if using a dynamic drop-down menu */
  }

  /* If a div.clear-block doesn't have any content after it and its bottom edge
     touches the bottom of the viewport, Firefox and Safari will mistakenly
     place several pixels worth of space between the bottom of the div and the
     bottom of the viewport. Uncomment this CSS property to fix this.
     Note: with some over-large content, this property might cause scrollbars
     to appear on the #page div.
  */
  /*
  #page
  {
    overflow-y: hidden;
  }
  */
