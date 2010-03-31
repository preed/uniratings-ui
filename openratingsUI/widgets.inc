<?php
/*
 * The contents of this file are subject to the Jabber Open Source License 
 * Version 1.0 (the "License").  You may not copy or use this file, in either 
 * source code or executable form, except in compliance with the License.  You 
 * may obtain a copy of the License at http://www.jabber.com/license/ or at 
 * http://www.opensource.org/.
 * 
 * Read the LICENSE file included with the source distribution for more
 * information.
 *
 * Software distributed under the License is distributed on an "AS IS" basis, 
 * WITHOUT WARRANTY OF ANY KIND, either express or implied.  See the License 
 * for the specific language governing rights and limitations under the 
 * License.
 *
 * Copyrights:
 *
 * Portions created by or assigned to Polyratings.com are Copyright (c) 
 * 1999-2002 Polyratings.com.  All Rights Reserved.  Contact information for 
 * Polyratings.com, is available at http://www.polyratings.com/.
 *
 * Portions Copyright (c) 1999-2002 Forrest Lanning
 *                        2001-2002 J. Paul Reed
 *
 * Contributor(s):
 *
 */

include_once('UIConstants.php'); 
include_once(PHP_ROOT . 'bullets.php');

// Needed for PrintCourseAbbreviations()
include_once(PHP_ROOT . 'DBInterfaceLib.php');

function PrintHTMLHeader($title = null) {
   if (null == $title)
      $titleStr = SITE_NAME;
   else
      $titleStr = SITE_NAME . ": $title";

?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">

<html>

<head>
   <title><?php print "$titleStr" ?></title>
   <link href="<?php echo CSS_URL ?>" rel="stylesheet" type="text/css">
</head>
   
<body bgcolor="white" text="black">

<?php
}

define('HEADER_WITH_SEARCH', true);
define('HEADER_WITHOUT_SEARCH', false);

function PrintHeader($withSearch = HEADER_WITHOUT_SEARCH) {

if ($withSearch)
   print "<form method=\"post\" action=\"" . SEARCH_URL . "\">";

?>
<table width="100%" height="97" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td valign="top" background="<?php echo IMAGES_URL ?>/logo_sq_front.gif" width="90" rowspan="3" height="97" alt="OpenRatings">
      <img src="<?php echo IMAGES_URL ?>/trans.gif" width="90" height="97" alt="">
    </td>
 
    <td class="nav" width="25">
          <img src="<?php echo IMAGES_URL ?>/1pix_trans.gif" width="20" height="1" alt="">
    </td>

    <td align="right" width="100%" height="24" colspan="2" class="nav" nowrap>
     <?php PrintNavHeaderLinks(); ?>
	</td>
        
	<td bgcolor="#ffffff">
          <img src="<?php echo IMAGES_URL ?>/1pix_trans.gif" width="2" height="1" alt="">
        </td>
	<td class="nav">
          <img src="<?php echo IMAGES_URL ?>/1pix_trans.gif" width="10" height="1" alt="">
        </td>
	<td bgcolor="#ffffff">
          <img src="<?php echo IMAGES_URL ?>/1pix_trans.gif" width="2" height="1" alt="">
        </td>
	<td class="nav">
          <img src="<?php echo IMAGES_URL ?>/1pix_trans.gif" width="5" height="1" alt="">
        </td>
	<td bgcolor="#ffffff">
          <img src="<?php echo IMAGES_URL ?>/1pix_trans.gif" width="2" height="1" alt="">
        </td>
	<td class="nav">
          <img src="<?php echo IMAGES_URL ?>/1pix_trans.gif" width="2" height="1" alt="">
        </td>
	<td bgcolor="#ffffff">
          <img src="<?php echo IMAGES_URL ?>/1pix_trans.gif" width="2" height="1" alt="">
        </td>
	<td class="nav">
          <img src="<?php echo IMAGES_URL ?>/1pix_trans.gif" width="1" height="1" alt="">
   </td>
 </tr>
 <tr>
   <td bgcolor="#ffffff" valign="middle" colspan="11">
     <img src="<?php echo IMAGES_URL ?>/title.gif" width="264" height="37" alt="">
   </td>
 </tr>
 <tr>
   <td background="<?php echo IMAGES_URL ?>/1pix_green.gif" width="25">
          <img src="<?php echo IMAGES_URL ?>/1pix_trans.gif" width="20" height="15" alt="">
   </td>
      <td background="<?php echo IMAGES_URL ?>/1pix_green.gif" valign="center" align="left">
<?php
      if ($withSearch) {
?>
      <font size="2" color="#ffffff">Professor name:</font>
      <input type="hidden" name="type" value="ProfName">
      <input type="hidden" name="sort" value="name">
      <input type="hidden" name="format" value="long">
      <input type="text" size="20" maxlength="100" name="terms">
      <input type="image" src="<?php echo IMAGES_URL ?>/search2.gif" valign="center" width="20" height="16" border="0" value="Find Professor Evaluations">
<?php
      }
      else {
         print "&nbsp;\n";
      }
?>
        </td>
        <td background="<?php echo IMAGES_URL ?>/1pix_green.gif" align="right">
         &nbsp; 
        </td>
	<td bgcolor="#ffffff">
          <img src="<?php echo IMAGES_URL ?>/1pix_trans.gif" width="2" height="1" alt="">
        </td>
	<td background="<?php echo IMAGES_URL ?>/1pix_green.gif">
          <img src="<?php echo IMAGES_URL ?>/1pix_trans.gif" width="10" height="1" alt="">
        </td>
	<td bgcolor="#ffffff">
          <img src="<?php echo IMAGES_URL ?>/1pix_trans.gif" width="2" height="1" alt="">
        </td>
	<td background="<?php echo IMAGES_URL ?>/1pix_green.gif">
          <img src="<?php echo IMAGES_URL ?>/1pix_trans.gif" width="5" height="1" alt="">
        </td>
	<td bgcolor="#ffffff">
          <img src="<?php echo IMAGES_URL ?>/1pix_trans.gif" width="2" height="1" alt="">
        </td>
	<td background="<?php echo IMAGES_URL ?>/1pix_green.gif">
          <img src="<?php echo IMAGES_URL ?>/1pix_trans.gif" width="2" height="1" alt="">
        </td>
	<td bgcolor="#ffffff">
	  <img src="<?php echo IMAGES_URL ?>/1pix_trans.gif" width="2" height="1" alt="">
        </td>
	<td background="<?php echo IMAGES_URL ?>/1pix_green.gif">
          <img src="<?php echo IMAGES_URL ?>/1pix_trans.gif" width="1" height="1" alt="">
        </td>
      </tr>
    </table>
    <?php if ($withSearch) print "</form>" ?>
<p>
<?php
}

function PrintBulletTable($bulletsArr) {
   assert(count($bulletsArr) > 0);
?>

   <table width="100%" cellspacing="0" cellpadding="2" border="0">

<?php foreach ($bulletsArr as $bullet) { ?>
      <tr>
      <td valign="top" align="left">
      <img src="<?php echo IMAGES_URL ?>/dartgreen.gif" width="4" height="8" alt="->">
      </td>
      <td valign="top" class="ftmdtxt" valign="left"><?php print $bullet ?><br>
      </td>
      </tr>
<?php 
   }

   print "</table>\n";
}

function PrintSearchBox() {
?>
<table width="175" border="1" cellspacing="0" cellpadding="3" bordercolor="#000000">
  <tr>
    <th class="flgtxt" background="<?php echo IMAGES_URL ?>/1pix_green.gif">Quick Search</th>
  </tr>
  <tr>
    <td class="ftmdtxt" background="<?php echo IMAGES_URL ?>/1pix_blue.gif" align="left">
      <form method="post" action="<?php echo SEARCH_URL ?>">
      Keyword:
      <input type="hidden" name="type" value="Keyword">
      <input type="hidden" name="sort" value="name">
      <input type="hidden" name="format" value="long">
      <input type="text" size="10" maxlength="100" name="terms">
      <br>
      <input type="image" src="<?php echo IMAGES_URL ?>/search.gif" border="0" 
        value="Find Professor Evaluations">
      </form>
      
      <form method="post" action="<?php print SEARCH_URL ?>">
      Course:<br>
      <input type="hidden" name="type" value="Class">
      <input type="hidden" name="sort" value="name">
      <input type="hidden" name="format" value="long">
      <select name="abbrev">
      <?php PrintCourseAbbrevs(); ?>
      </select>
      <input type="text" name="number" size="3" maxlength="3"><br>
      <input type="image" src="<?php echo IMAGES_URL ?>/search.gif" border="0" value="Find Evaluations by Class">
      </form>
      <a href="<?php echo SEARCH_URL ?>" class=link>Advanced Search</a>
    </td>
  </tr>
</table>
<?php

}

function PrintInfoBox() {
?>
<table width="175" border="1" cellspacing="0" cellpadding="3" bordercolor="#000000">
  <tr>
    <th class="flgtxt" background="<?php echo IMAGES_URL ?>/1pix_green.gif">Information</th>
  </tr>
  <tr>
    <td class="ftmdtxt" background="<?php echo IMAGES_URL ?>/1pix_blue.gif" align="left">
      <?php PrintBulletTable($GLOBALS['infoBullets']); ?>
    </td>
  </tr>
</table>
<?php
}

function PrintDisclaimerBox() {
?>
<table width="175" border="1" cellspacing="0" cellpadding="3" bordercolor="#000000">
  <tr>
    <th class="flgtxt" background="<?php echo IMAGES_URL ?>/1pix_green.gif">The Fine Print</th>
  </tr>
  <tr>
    <td class="ftmdtxt" background="<?php echo IMAGES_URL ?>/1pix_blue.gif" align="left">
      <br>
      <?php PrintBulletTable($GLOBALS['finePrintDisclaimers']); ?>
    </td>
  </tr>
</table>
<?php
}

function PrintDirectEmailBox() {
?>
<table width="175" border=1 cellspacing=0 cellpadding=3 bordercolor="#000000">
  <tr>
    <th class=flgtxt background="<?php echo IMAGES_URL ?>/1pix_green.gif">E-mail Us Directly</th>
  </tr>
  <tr>
    <td class=ftmdtxt background="<?php echo IMAGES_URL ?>/1pix_blue.gif" align="left"><br>
      <?php PrintBulletTable($GLOBALS['emailBoxAddrs']); ?>
    </td>
  </tr>
</table>
<?php
}

function PrintMediaBox() {
?>
<table width="175" border="1" cellspacing="0" cellpadding="3" bordercolor="#000000">
  <tr>
    <th class="flgtxt" background="<?php echo IMAGES_URL ?>/1pix_green.gif">Polyratings' Press</th>
  </tr>
  <tr>
    
    <td class="ftmdtxt"  background="<?php echo IMAGES_URL ?>/1pix_trans.gif" bgcolor="#003366" align="left">
    This is a media box where we put links to articles about the original
    <a class="nav" href="http://www.polyratings.com/">Polyratings.com</a>; 
    we've removed this from the <?php echo SITE_NAME ?> design, but you could 
    theoretically re-add it and put just about anything you want here.
    </td>
  </tr>
</table>
<?php
}

function PrintNavHeaderLinks() {
   $links = array(INDEX_URL, SEARCH_URL, LIST_URL, ENTEREVAL_URL, 
    ABOUT_URL, COMMENTS_URL);

   $linkText = array("Home", "Professor Search", "Professor List", 
    "Evaluate a Professor", "About Us", "Contact Us");

   assert(count($links) == count($linkText));

   $thisURL = SITE_URL . getenv('REQUEST_URI');
   $thisURL = preg_replace('/\?.*$/', '', $thisURL);

   for ($ndx = 0; $ndx < count($links); $ndx++) {
      if ($thisURL == $links[$ndx])
         print "<font color=\"#1f9bdb\">$linkText[$ndx]</font>";
      else
	      print "<a href=\"$links[$ndx]\" class=\"nav\">$linkText[$ndx]</a>";

      print " &nbsp; &nbsp; &nbsp;\n";
   }
}

function PrintNavFooter() {
?>
<p>
<table width="100%" border="0" cellspacing="0" cellpadding="0">
<tr>
<td class="nav" width="21">
  <img src="<?php echo IMAGES_URL ?>/trans.gif" width="10" height="1" alt="">
</td>

<th width="100%" height="24" align="left" class="nav" nowrap>
<a href="<?php echo INDEX_URL ?>" class="nav">Home</a>&nbsp; &nbsp; &nbsp;
<a href="javascript:window.history.go(-1);" class="nav">Go Back</a> &nbsp; &nbsp; &nbsp; 
<a href="<?php echo LIST_URL ?>" class="nav">Professor List</a> &nbsp; &nbsp; &nbsp; 
<a href="<?php echo SEARCH_URL ?>" class="nav">Professor Search</a></th>
</tr>
</table>
<?php
}

function PrintHTMLFooter() {
?>
<table width="100%" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td align="center" valign="top" class="smtxt">
      <?php echo SITE_NAME ?>, Version <?php echo PR2_VERSION ?> &copy; 
      copyright 1998-2002 <a class="blknav" 
      href="<?php echo OPENRATINGS_URL ?>">OpenRatings</a> All rights reserved.
    </td>
  </tr>
</table>

</body>
</html>

<?php
}

function PrintCourseAbbrevs($highlighted = null) {
   $abbreviations = GetCourseAbbreviations();

   foreach ($abbreviations as $abbrev) {
      if ($abbrev == $highlighted)
         print "<option value=\"$abbrev\" selected>$abbrev</option>\n";
      else
         print "<option value=\"$abbrev\">$abbrev</option>\n";
   }
}

?>
