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

function PrintAddPageHeader() {
   PrintHTMLHeader();
   PrintHeader(HEADER_WITHOUT_SEARCH);
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

   <center><font class="lgbtxt">Add a Professor</center>
   <br>
   <font class="lgtxt">

<?php
}

function PrintAddPageFooter() {
?>
</td>
</tr></table>

<p>

<?php 
   PrintHTMLFooter(); 
}

function PrintAddCollectInfoPage($uiHandle) {
   PrintAddPageHeader();
?>

If you need help while filling out this form, check out 
<a target="_new" href="<?php echo UNIVERSITYDIR_URL ?>"><?php echo SITE_NAME ?>'s 
School's online directory</a>.
<p>
<form method="post">
<b>First</b> name: <input type="text" name="proffname" length="20" maxlength="30">
<p>
<b>Last</b> name: <input type="text" name="proflname" length="30" maxlength="40">
<p>
Department: <select name="profdept">
<?php
   foreach ($uiHandle->GetValue('departments') as $dept) {
      $did = $dept['deptid'];
      $dname = $dept['name'];
      print "<option value=\"$did\">$dname</option>\n";
   }
?>
</select>
<p>
After this page, you <b><i>must</i></b> enter an evaluation for the professor;
we will examine your new professor submission and if the information you
provided is accurate, your evaluation will appear as the first evaluation 
on that professor's page.
<p>
<input type="submit" name="haveProfInfo" value="Continue >>">

</form>

<?php
   PrintAddPageFooter();
}

function PrintAddRepeatInstructionsPage($uiHandle) {
   PrintAddPageHeader();
?>

<b><font size="4">How about you actually read the page this time</font></b>
<p>
Click back and this time, try reading the text we so carefully handcrafted 
for you to actually pay attention to.

<?php
   PrintAddPageFooter();
}

function PrintAddPage($uiHandle) {
   PrintAddPageHeader();
?>

Before starting, you will need the following information about a 
professor to add them to the <?php echo SITE_NAME ?>database:

<ul>
<li>First name (i.e. <i>Joe</i>)
<li>Last name (i.e. <i>Professor</i>)
<li>Department (i.e. <i>Biology</i>)
<li>Comments (You <b>must</b> rate this professor)
</ul>
</font>

<p>

You can get department/college information from 
<a href="<?php echo UNIVERSITYDIR_URL ?>"><?php echo SITE_NAME ?>'s School's directory</a>.
<p>
<b>Make sure</b> you pay attention to the spelling of the professor's name and
their department/college. Additions with incorrect information will <i>not</i>
be included in the database. Additionally, 
<a href="<?php echo ADDPROF_URL ?>?haveinfo=true">you <b>must</b> be 
prepared to rate</a> this professor; the logical corollary to this
statement is only suggest professors to rate that <i>you've taken</i>; 
professor addition requests without initial evaluations don't even cause us
to be notified that an addition request exists. Additionally, garbage ratings 
submitted just to get a professor added will be deleted as well.
<p>
After you enter this information, both the new professor and your comments
about the professor are hidden until approved by the <?php echo SITE_NAME ?> 
staff; so, if you're planning on adding "Professor Superman" or something 
else cute like that, save everyone's time... those entries won't ever see 
the light of day.
<p>
To check if your addition was accepted, look at the 
<a href="<?php echo LIST_URL ?>">professor list</a>, which indicates how 
many new professors are "pending." If there are no new professors pending and 
the professor you submitted is not in the list, the submission wasn't accepted.
<p>
If you're ready to add a professor to our database, select the text above which
talks about whether or not you must rate the professor you want to add.
<p>

<center>
<form method="post">
<input type="submit" name="dimwit" value="Continue >>">
</form>
</center>
<?php
   PrintAddPageFooter();
}
?>


