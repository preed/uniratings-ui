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

function PrintProfDoodads($ui) {
   $themes = $GLOBALS['oruiDoodadThemes'];
   $stats = $ui->GetValue('profStats');

   // If invalid theme or prof's rating is 'n/a'
   if (! array_key_exists(PROF_DOODAD_THEME, $themes) || ($stats['q3avg'] < 0))
      return;

   // This is here because instead of being a -1 like it should be, it's 'n/a';
   // we should file a bug on this 'cause it's fucking stupid.
   if (!preg_match("/^\d\.\d+$/", $stats['q3avg']))
      return;

   $profInt = floor($stats['q3avg']);
   $profMantissa = $stats['q3avg'] - $profInt;
   $grafxPrinted = 0;

   for ($prCount = 0; $prCount < $profInt; $prCount++) {
      print "<img src=\"" . $themes[PROF_DOODAD_THEME]['full'] . "\">\n";
      $grafxPrinted++;
   }

   if ($profMantissa >= HALFWAY_GPA) {
      print "<img src=\"" . $themes[PROF_DOODAD_THEME]['half'] . "\">\n";
      $grafxPrinted++;
   }

   while ($grafxPrinted < MAX_GPA) {
      print "<img src=\"" . $themes[PROF_DOODAD_THEME]['empty'] . "\">\n";
      $grafxPrinted++;
   }
}

function PrintProfNoEvalsPage($uiHandle) {
    $pInfo = $uiHandle->GetValue('profInfo');
 
    PrintHTMLHeader($pInfo['lname'] . ", " . $pInfo['fname']);
    PrintEvalHeader($uiHandle);
?>
   <table border=\"0\" width=\"90%\" class=\"text\" cellpadding=\"0\" cellspacing=\"3\">
   <tr><td>
   <center>
   <font class="title">This professor hasn't been evaluated yet!</font>
   <p>
   <font class="lgtxt">If you've taken one of their classes, head on over to 
   this <a class="blknav" href="<?php echo ENTEREVALID_URL . $pInfo['profid'] ?>">
   professor's evaluation page</a><br>and be the first student to let 
   the world know what they're in for!</font>
   </center>
   </td>
   </tr>
   </table>
<?php
    PrintNavFooter();
    PrintHTMLFooter();
}

function PrintProfEvalPage($uiHandle) {
   $pInfo = $uiHandle->GetValue('profInfo');

   PrintHTMLHeader($pInfo['lname'] . ", " . $pInfo['fname']);
   PrintEvalHeader($uiHandle);

   print "<center>\n";
   PrintEvals($uiHandle);
   print "</center>\n";

   PrintNavFooter();
   PrintHTMLFooter();
}

function PrintEvalHeader($uih) {
   $profInfo = $uih->GetValue('profInfo');
   $profStats = $uih->GetValue('profStats');
?>

<table width="100%" border="0" cellspacing="0" cellpadding="0">
<tr>
<td width="90" height="115" valign="top">
<img border="0" src="<?php echo IMAGES_URL ?>/logo_sq.gif" width="90" height="115">
</td>
<td valign="top">

<table width="100%"  border="0" cellspacing="0" cellpadding="2">
  <tr>
    <td class="nav" width="21">
      <img src="<?php echo IMAGES_URL ?>/trans.gif" width="20" height="1" alt="">
    </td>
    <td width="100%" height="24" align="right" class="nav" nowrap>
    <?php PrintNavHeaderLinks(); ?>
    </td>
  </tr>
  <tr>
    <td bgcolor="#ffffff" width="21">
      <img src="<?php echo IMAGES_URL ?>/trans.gif" width="20" height="1" alt="">
    </td>
    <td bgcolor="#ffffff" colspan="1">
      <font class="title" color="#000000">
<?php 
   print $profInfo['lname'] . ", " . $profInfo['fname'] . "&nbsp;"; 
   PrintProfDoodads($uih); 
?>
      </font>
    </td>
  </tr>
  <tr>
    <td bgcolor="#1f9bdb" width="21">
      <img src="<?php echo IMAGES_URL ?>/trans.gif" width="20" height="1" alt="">
    </td>
    <td bgcolor="#1f9bdb" align="left">
      <table border="0" cellpadding="0" cellspacing="0" width="100%">
      <tr>
      <td width="50%">
        <font class="lgtxt">Cumulative GPA: <?php print $profStats['q3avg'] . "/4.00 with " . $profStats['evalcount'] . 
        ($profStats['evalcount'] == 1 ? " evaluation" : " evaluations") ?></font><br>
        <font class="mdtxt">Presents Material Clearly: <?php print $profStats['q1avg'] ?></font><br>
        <font class="mdtxt">Recognizes Student Difficulties: <?php print $profStats['q2avg'] ?></font><br>
      </td>
      <td width="50%" align="right">
        <font class="lgtxt">
        <a class="evallink" href="<?php print SEARCH_URL . "?type=Dept&deptid=" . $profInfo['deptid'] . "\">" . $profInfo['deptname'] . " Department</a>, " . $profInfo['campusname'] ?><br>
        </font>

        <font class="mdtxt">
        <a class="evallink" href="<?php print PROFSTATSID_URL . $profInfo['profid'] ?>">Full Statistical Analysis</a><br>
        </font>

        <font class="mdtxt">
        <a class="evallink" href="<?php print ENTEREVALID_URL . $profInfo['profid'] ?>">Evaluate This Professor</a><br>
        </font>
      </td>
    </tr>
  </table>

  </td>
</tr>
<tr>
    <td bgcolor="#ffffff" width="21">
      <img src="<?php echo IMAGES_URL ?>/trans.gif" width="20" height="1" alt="">
    </td>
    <td bgcolor="#ffffff" align="left">
      &nbsp; 
    </td>
  </tr>
</table>

  </td>
</tr>
</table>

<?php
}

function PrintEvalProfDetailHeader($uih) {
   $pinfo = $uih->GetValue('profInfo');
   $pstats = $uih->GetValue('profStats');
   assert(isset($pinfo['profid']));

   // should be there, but turned off because some older profs will
   // have all these settings null because of the import.
   //assert(isset($pstats['evalcount']));
?>
  <table border="0" width="90%">
    <td bgcolor="#ffffff" colspan="1">
      <font class="title" color="#000000">
<?php 
   print $pinfo['lname'] . ", " . $pinfo['fname'] . "&nbsp;"; 
   PrintProfDoodads($uih);
?>
      </font>
    </td>
  </tr>
  <tr>
    <td bgcolor="#1f9bdb" align="left">
      <table border="0" cellpadding="0" cellspacing="0" width="100%">
      <tr>
      <td width="50%">
        <font class="lgtxt">Cumulative GPA: <?php print $pstats['q3avg'] . 
        " with " . $pstats['evalcount'] .
        ($profStats['evalcount'] == 1 ? " evaluation" : " evaluations") ?></font><br>
        <font class="mdtxt">Helps students: <?php print $pstats['q1avg'] ?></font><br>
        <font class="mdtxt">Knows Subject: <?php print $pstats['q2avg']?></font><br>
      </td>
      <td width="50%" align="right">
        <font class="lgtxt">
        <a class="evallink" href="<?php print SEARCH_URL . "?type=Dept&deptid=" . $pinfo['deptid'] . "\">" . $pinfo['deptname'] . " Department</a>, " . $pinfo['campusname'] ?><br>
        </font>

        <font class="mdtxt">
        <a class="evallink" href="<?php print PROFSTATSID_URL . $pinfo['profid'] ?>">Full Statistical Analysis</a><br>
        </font>

        <font class="mdtxt">
        <a class="evallink" href="<?php print ENTEREVALID_URL . $pinfo['profid'] ?>">Evaluate This Professor</a><br>
        </font>
      </td>
    </tr>
  </table>
</td>
</tr>
</table>
<?php
}

function PrintEvals($uih) {
   $studentClassArr = $GLOBALS['oruiClassStandingStrings'];
   $studentGradeArr = $GLOBALS['oruiGradeStrings'];
   $courseTypeArr = $GLOBALS['oruiCourseTypeStrings'];

   print "<table border=\"0\" width=\"90%\" class=\"text\" cellpadding=\"0\" cellspacing=\"3\">\n";

   $evaluations = $uih->GetValue('profEvals');

   foreach ($evaluations as $eval) {
      $classAbbrev = $eval['abbrev'];
      $classNumber = $eval['number'];
      $studentClass = $studentClassArr[$eval['studentclass']];
      $courseType = $courseTypeArr[$eval['coursetype']];
      $studentGrade = $studentGradeArr[$eval['grade']];
      $comment = $eval['comment'];
      $evalDate = date("g:i a, M j, Y", $eval['created']);
      $commentId = $eval['commentid'];
      $status = $eval['status'];

      if (is_null($studentClass))
         $studentClass = "N/A";

      if (is_null($courseType))
         $courseType = "N/A";

      if (is_null($studentGrade))
         $courseType = "N/A";
?> 
   <tr>
   <td width="20%" valign="top" align="right">
   <!-- commentid: <?php print $commentId ?>-->
   <b><a class="evallink" href="<?php print SEARCH_URL . "?type=Class&abbrev=" . $classAbbrev . "&number=" . $classNumber . "\">" . "$classAbbrev $classNumber"; ?></a></b><br>
   <?php print $studentClass ?><br>
   Grade Earned: <b><?php print $studentGrade ?></b><br>
   <?php print $courseType ?><br>
   <?php print $evalDate ?><br>
<?php
   if ($status == "moderated") {
      print "<b>Moderated</b> Comment<br>\n";
   }
?>
   </td>
   <td bgcolor="#1f9bdb" width="1%">&nbsp;</td>
   <td valign="top" width="79%" align="left">
   <?php print $comment ?>
   </td>
   </tr>
   <tr><td bgcolor="#ffffff" colspan="3">&nbsp;</td></tr>

<?php
   }

   print "</table>";

}

function PrintInvalidEval() {
   PrintHTMLHeader();
   PrintHeader();
?>

<font class="lgtxt">
You have requested an invalid professor evaluation; this could be because:
<ul>
<li>That professor doesn't exist
<li>That professor exists, but is currently hidden, awaiting approval
<li>There was a software error
</ul>
<p>
Please select another professor ID to lookup; if you feel you've gotten this
message in error, please email <a href="mailto:<?php echo ERROR_EMAIL .
"\">". ERROR_EMAIL ?></a> and describe the problem.
<p>
<form method="get">
Enter a professor ID to lookup: <input type="text" name="profid">
<input type="submit" value="Get Prof Info">
</form>
</font>

<?php
   PrintNavFooter();
   PrintHTMLFooter();
}

?>
