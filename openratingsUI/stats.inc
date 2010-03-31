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

function PrintStatsPage($uih) {
   PrintHTMLHeader();
   PrintHeader();

   $pinfo = $uih->GetValue('profInfo');
   $pstats = $uih->GetValue('profStats');
?>

<center>

<table border="0" cellpadding="2" cellspacing="2" width="80%">
<tr><td>
A detailed statistical analysis of the ratings submitted for this professor 
follows. 
<p>
This analysis is provided in order to give a more in-depth look at the data
sitting in <?php echo SITE_NAME ?>'s databases. It's not meant to confuse
you or "muddy the waters" with lots of statistical data.
<p>
In case it's been awhile since you took that Statistics class 
(or maybe you've never had to take one, <i>lucky!</i>), we recommend you
look at this <a class="blknav" 
href="<?php echo STATSTERMS_URL ?>" onClick="NewWindow=window.open('<?php echo STATSTERMS_URL ?>','TermsWindow','toolbar=0,location=0,status=0,menubar=0,scrollbars=1,resizable=1,width=600,height=500'); return false;">
statistical terms and concepts</a> key that's
been provided to explain what all these numbers mean.
<p>
It also gives some helpful hints for interpreting the data for yourself.
</td></tr>
</table>
<p>
<table border="0" cellpadding="10" cellspacing="0" width="65%">
<tr>
<td colspan="2" align="center">
<b>
<font size="4">Statistical Analysis for</font>
<font size="5"><?php print $pinfo['fname'] . " " . $pinfo['lname'] ?></font>
<br>
<font size="4"><?php print $pinfo['deptname'] ?> Department at
<?php print $pinfo['campusname'] ?></font>
</b>
<hr size="2" width="100%">
</td>
</tr>
</table>
<table width="75%" border="0" cellpadding="2" cellspacing="1">
<tr><td rowspan="6" valign="top"><b><u>Overall Statistics</u></b>
<br>
Students were asked "Overall, how would you rate this professor?"
<p>
Includes the total number of evaluations this entire analysis was based upon, as
well as center and spread representations for this specific question only.
</td>
<td rowspan="6" bgcolor="#1f9bdb" width="5">&nbsp;</td>
<td width="35%" align="right"><b>Total Evaluations Reporting:</b></td><td width="15%"><?php print $pstats['evalcount'] ?> </td></tr>
<tr><td align="right"><b>Mean:</b></td><td><?php print $pstats['q3avg']; ?></td></tr>
<tr><td align="right"><b>Median:</b></td><td><?php print $pstats['q3median']; ?></td></tr>
<tr><td align="right"><b>Mode:</b></td><td><?php print $pstats['q3mode']; ?></td></tr>
<tr><td align="right"><b>Standard Deviation:</b></td><td><?php print $pstats['q3sd']; ?></td></tr>
</table>

<p>
<table width="75%" border="0" cellpadding="2" cellspacing="1">
<tr><td rowspan="5" valign="top"><b><u>Ability to Present Material</u></b>
<br>
Students were asked to "Grade this instructor's ability to present the course 
material clearly."
<p>
Analysis includes various representations of center and of spread.
</td>
<td rowspan="6" bgcolor="#1f9bdb" width="5">&nbsp;</td>
<td width="35%" align="right"><b>Mean:</b></td><td width="15%"><?php print $pstats['q1avg']; ?></td></tr>
<tr><td align="right"><b>Median:</b></td><td><?php print $pstats['q1median']; ?></td></tr>
<tr><td align="right"><b>Mode:</b></td><td><?php print $pstats['q1mode']; ?></td></tr>
<tr><td align="right"><b>Standard Deviation:</b></td><td><?php print $pstats['q1sd']; ?></td></tr>
</table>
<p>
<table width="75%" border="0" cellpadding="2" cellspacing="1">
<tr><td rowspan="5"><b><u>Ability to Understand Student Difficulties</u></b>
<br>
Students were asked to "Grade this instructor's ability to recognize
and clarify student difficulties."
<p>
Analysis includes various representations of center and of spread.
</td>
<td rowspan="6" bgcolor="#1f9bdb" width="5">&nbsp;</td>
<td width="35%" align="right"><b>Mean:</b></td><td width="15%"><?php print $pstats['q2avg']; ?></td></tr>
<tr><td align="right"><b>Median:</b></td><td><?php print $pstats['q2median']; ?></td></tr>
<tr><td align="right"><b>Mode:</b></td><td><?php print $pstats['q2mode']; ?></td></tr>
<tr><td align="right"><b>Standard Deviation:</b></td><td><?php print $pstats['q2sd']; ?></td></tr>
</table>
<hr width="65%" size="2">
<table width="75%" border="0" cellpadding="2" cellspacing="1">
<tr>
<td colspan="4">
<center><b>Ratings by Reported Grade</b></center>
<p>
The following table gives a statistical breakdown of the <b>average</b> of the 
responses given to various questions, separated by the grade reportedly
received by the respondents.
<p>
Grades not reported by respondents are omitted, and those who did not
want to share their grade are reported with a grade of 'N/A'.
<p>
The grades received are reported by the students rating this professor and
are not verified by <?php echo SITE_NAME ?>.
<p>
&nbsp;
</td>
</tr>
<?php 
   foreach ($GLOBALS['orStudentGrades'] as $grade) {
      if (0 == $pstats['grade'.$grade.'count'])
         continue;

      print "<tr><td rowspan=\"4\" valign=\"center\" align=\"right\"><b><u>Students 
       Receiving a Grade of '" . $GLOBALS['oruiGradeStrings']["$grade"] . 
       "'</u></b></td>\n";
      print "<td width=\"5\" rowspan=\"4\" bgcolor=\"#1f9bdb\">&nbsp;</td>\n";
      print "<td width=\"35%\" align=\"right\"><b>Reporting Evaluations:</b></td><td width=\"15%\">" . 
       $pstats['grade'.$grade.'count'] . "</td></tr>\n";

      print "<td align=\"right\"><b>Overall Grade:</b></td><td>" . 
       $pstats['q3'.$grade.'avg'] .  "</td></tr>\n";
      print "<tr><td align=\"right\"><b>Presents Material Clearly:</b></td><td>"        . $pstats['q1'.$grade.'avg'] . "</td></tr>\n";
      print "<tr><td align=\"right\"><b>Recognizes Student Difficulties:</b></td><td>" 
       . $pstats['q2'.$grade.'avg'] . "</td></tr>";

      print "<tr><td colspan=\"4\">&nbsp;</td></tr>\n";
   }
?>
   </table>
   <hr width="65%" size="2">
   <table width="75%" border="0" cellpadding="2" cellspacing="1">
   <tr>
   <td colspan="4">
   <center><b>Ratings by Class Standing</b></center>
   <p>
   The following table gives a statistical breakdown of the <b>average</b> of 
   the responses given to various questions, separated by the class standing
   reported by the respondents.
   <p>
   Standings not reported by respondents are omitted.
   <p>
   Class standings are reported by the students rating this professor and
   are not verified by <?php echo SITE_NAME ?>.
   <p>
   &nbsp;
</td>
</tr>
<?php
   foreach ($GLOBALS['orClassStandings'] as $year) {
      if (0 == $pstats['year'.$year.'count'])
         continue;

      print "<tr><td rowspan=\"4\" valign=\"center\" align=\"right\"><b><u>Students 
       With a '" . $GLOBALS['oruiClassStandingStrings']["$year"]. 
       "' Standing</u></b></td>\n";
      print "<td width=\"5\" rowspan=\"4\" bgcolor=\"#1f9bdb\">&nbsp;</td>\n";
      print "<td width=\"35%\" align=\"right\"><b>Reporting Evaluations:</b></td><td width=\"15%\">" . 
       $pstats['year'.$year.'count'] . "</td></tr>\n";

      print "<td align=\"right\"><b>Overall Grade:</b></td><td>" . 
       $pstats['q3'.$year.'avg'] .  "</td></tr>\n";
      print "<tr><td align=\"right\"><b>Presents Material Clearly:</b></td><td>"
      . $pstats['q1'.$year.'avg'] . "</td></tr>\n";
      print "<tr><td align=\"right\"><b>Recognizes Student Difficulties:</b></td><td>" 
       . $pstats['q2'.$year.'avg'] . "</td></tr>";

      print "<tr><td colspan=\"4\">&nbsp;</td></tr>\n";
   }
?>
</table>

</center>
<p>
<?php 
   PrintNavFooter();
   PrintHTMLFooter(); 
}

function PrintInvalidStatsPage($uiHandle) {
   PrintHTMLHeader();
   PrintHeader();
?>
<font class="lgtxt"><b>We're Sorry!</b></font>
<p>
<font class="mdtxt">
A statistical analysis is unavailable for the professor you've selected.
<p>
This is <b>most commonly</b> due to the professor not having enough 
evaluations to make any statistical analysis meaningful, so it's not
performed because the analysis could be misleading.
<p>
However, other causes could include:
<ul>
<li>That professor doesn't exist
<li>That professor exists, but is currently hidden, awaiting approval
<li>There was a software error
</ul>
<p>
If you feel you've gotten this message in error, please 
email <a href="mailto:<?php echo ERROR_EMAIL .  "\">". ERROR_EMAIL ?></a> 
and describe the problem.
 <p>
<?php 
   PrintNavFooter();
   PrintHTMLFooter(); 
}
?>
