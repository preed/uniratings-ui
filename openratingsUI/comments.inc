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
include_once(UI_ROOT . 'widgets.inc');

function PrintCommentPageHeader() {
   PrintHTMLHeader();
   PrintHeader(HEADER_WITH_SEARCH);
?>
<table width="100%" border="1" cellspacing="0" cellpadding="10" bordercolor="#000000" height="376">

<tr valign="top">
  <td rowspan="4" height="374" width="225" background="<?php echo IMAGES_URL ?>/background.gif">
    <center>
    <br>
    <?php PrintSearchBox(); ?>
    <br>
    <?php PrintDirectEmailBox(); ?>
    <br>
    <?php PrintDisclaimerBox(); ?>
    <br>
    </center>
    <br>
  </td>

  <td border="0" width="100%" rowspan="3" height="166">
<?php
}

function PrintCommentPageFooter() {
?>

</td>
</tr></table>

<p>

<?php 
   PrintHTMLFooter();
}

function PrintCommentSubmittedPage($uiHandle) {
   PrintCommentPageHeader();
   print "<font class=\"title\">Message Sent</font><p>";
   print "<font class=\"mdtxt\">Thanks for your comments; if you included an email address, someone will get back to you as soon as possible.<p>Either way, feedback is what helps " . SITE_NAME . " to become the best professor ratings engine on the Internet, so thanks for taking the time to help us help you!</font>"; 
   PrintCommentPageFooter();
}

function PrintSubmitCommentPage($uiHandle) {
   PrintCommentPageHeader();
?>
   <center><font class="lgbtxt">C o m m e n t s&nbsp; a n d&nbsp; S u g g e s t i o n s&nbsp; F o r m</center>
   <br>
   <center>
   <img src="<?php echo IMAGES_URL ?>/1pix_black.gif" width="70%" height="2" alt="">
   </center>


<TABLE BGCOLOR="#FFFFFF" WIDTH="100%"><TR><TD WIDTH=50>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</TD><TD WIDTH="100%">

<table border=0 cellspacing=8 cellpadding=0>
<form method="post">

<tr valign=middle>
<td><font face="geneva,arial" color="#003366" size=2><b>To:</b></font></td>
<td><font face="geneva,arial" size=2><b>The <?php echo SITE_NAME ?> Team</b></font></td>
</tr>

<tr valign=top>
<td valign="center"><font face="geneva,arial" color="#003366" size=2><b>Regarding:</b></font></td>
<td><font face="geneva,arial" size=2>
<select name="reason">
<option>-- choose one --
<option value="props">Comments - Suggestions<!--Compliments / Complaints-->
<option value="background">General info on <?php echo SITE_NAME ?> 
<option value="tech">Technical Problems
<option value="other">Other

</select>
</font>
</td>
</tr>

<tr valign=top>
<td valign="center"><font face="geneva,arial" color="#003366" size=2><b>From:</b></font></td>
<td><font face="geneva,arial" size=2><input type=text size=30 maxlength=100 name=from value=""><br>
Please enter your email address if you'd like a reply</font></td>
</tr>


<tr valign=middle>

<td><font face="geneva,arial" color="#003366" size=2><b>Subject:</b></font></td>
<td><font face="geneva,arial" size=2><input typ=text size=30 maxlength=100 name=subject value=""></font></td>

</tr>

<tr><td colspan=2><font face="geneva,arial" color="#003366" size=2><b>Enter your comments below:</b></font><br>
<textarea cols=40 rows=20 maxlength=65000 name=comments wrap=HARD></textarea></td>
</tr>

<tr><td colspan="2" align="center"><input type="submit" name="sendcomment" value="Send Mail"></td></tr>
</TABLE>
</FORM>
</TD></TR></TABLE>

<?php
   PrintCommentPageFooter();
}
?>

