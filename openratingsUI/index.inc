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

function PrintIntroContent() {
?>
<p class="mdtxt">
Welcome to <b><?php echo SITE_NAME ?></b>!
</p>

<p class="mdtxt">

This is the default installation text; you'll probably want to customize
it for your school, and tell your users a little bit about who you are,
why you started this site, and what it can do for them.

</p>
<p class="mdtxt">

Of course, if you'd like an example, you can always head on over to
<a class="blknav" href="http://www.polyratings.com/">Polyratings.com</a>, the 
OpenRatings installation for <a class="blknav" 
href="http://www.calpoly.edu/">Cal Poly, SLO</a>, to see what we wrote here.

</p>
<p class="mdtxt">

We also use this space to explain our <a class="blknav" 
href="<?php echo FAQ_URL ?>">FAQ page</a>, and point people there.

</p>
<p class="mdtxt">

Also, if you'd like to keep a link back to the 
<a class="blknav" href="<?php echo OPENRATINGS_URL ?>">OpenRatings</a> home, 
that'd be spiffy!

</p>

<?php
}

function PrintMainLinks() {
?>

<table width="100%" border="0" cellspacing="0" cellpadding="4">
<tr valign=top>
<td>&nbsp;</td>
<td width="50%" class="smtxt">

<a href="<?php print SEARCH_URL ?>" class="bb">Professors</a><br>
Tired of getting classes with lousy professors? Well there is something you can do about it. Evaluate your past professors and let the world know what they're in for.<br><br>

<a href="<?php print LIST_URL ?>" class="bb">The Evaluated</a><br>
An up to the second list of all evaulated professors. <br><br>

<a href="<?php print ADDPROF_URL ?>" class="bb">Add a Prof</a><br>
Don't see your (not so) favorite professors? Sign 'em up! <br><br>

</td>
<td width="50%" class="smtxt">

<a href="<?php print ABOUT_URL ?>" class="bb">About Us</a><br>
  Who we are, how we started <?php echo SITE_NAME ?>.<br><br>

<a href="<?php print COMMENTS_URL ?>" class="bb">Contact Us</a><br>
  Send us your comments and suggestions...<br><br>

</td>
</tr>
</table>

<?php
}

function PrintIndexPage($uiHandle) {
   PrintHTMLHeader();
   PrintHeader(HEADER_WITH_SEARCH);
?>
<table width="100%" border="1" cellspacing="0" cellpadding="10" bordercolor="#000000" height="376">

<tr valign="top">
  <td rowspan="4" height="374" width="225" background="<?php echo IMAGES_URL ?>/background.gif">
    <center>
    <br>
    <?php PrintInfoBox(); ?>
    <br>
    <?php PrintSearchBox(); ?>
    <br>
    <?php PrintDisclaimerBox(); ?>
    <br>
    </center>
    <br>
  </td>

  <td border="0" width="100%" rowspan="3" height="166">

   <center><font class="lgbtxt">W e l c o m e&nbsp; t o&nbsp; M y O p e n R a t i n g s S i t e</center>
   <br>
   <center>
   <img src="<?php echo IMAGES_URL ?>/1pix_black.gif" width="70%" height="2" alt="">
   </center>

   <table width="100%" border="0" cellspacing="0" cellpadding="4">
   <tr valign="top">
     <td>&nbsp;</td>
     <td class="mdtxt">
       <img src="<?php echo IMAGES_URL ?>/1pix_trans.gif" width="20" height="1" alt="">

<?php PrintIntroContent(); ?>

<br>

</td>
</tr>
</table>

<center>
<img src="<?php echo IMAGES_URL ?>/1pix_black.gif" width="80%" height="2" alt="--">
</center>
<br>

<?php PrintMainLinks(); ?>

</td>
</tr></table>

<p>

<?php 
   PrintHTMLFooter(); 
}
?>
