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

function PrintCollectEvaluationPage($uiHandle) {
   $pinfo = $uiHandle->GetValue('profInfo');
   $lastname = $pinfo['lname'];
   $firstname = $pinfo['fname'];

   PrintHTMLHeader("Evaluation Form for $lastname, $firstname");
   PrintHeader();

   print "<center>\n";
   PrintCollectEvalTemplate($pinfo);
   print "</center>\n";
}

function PrintEnterEvaluationPage($uiHandle) {
   PrintHTMLHeader();
   PrintHeader();
?>

<font class="title">Professor Selection</font>
<p>
<font class="lgtxt">Select the professor you'd like to rate from the list below

<ul>
<?php
   
   foreach ($uiHandle->GetValue('profList') as $prof) {
      $pid = $prof['profid'];
      $plname = $prof['lname'];
      $pfname = $prof['fname'];
      $pdept = $prof['dept'];
      print "<li><a class=\"blknav\" href=\"" . ENTEREVALID_URL . "$pid\">$plname, $pfname</a> ($pdept)</li>\n";
   }

   print "\n</ul>\n</font>\n";

   PrintNavFooter();
   PrintHTMLFooter();
}

function PrintCollectEvalTemplate($profInfo) {
?>
<form method="post">
<input type="hidden" name="profid" value="<?php print $profInfo['profid'] ?>">

<table border="0" cellpadding="10" cellspacing="0" width="65%">
<tr>
<td colspan="2" align="center">
<b>
<font size="4">Evaluation Form for</font>
<font size="5">
<?php print $profInfo['fname'] . " " . $profInfo['lname'] ?>
</font>
<br>
<font size="4"><?php print $profInfo['deptname'] ?> Department at
<?php print $profInfo['campusname'] ?></font>
</b>
</td>
</tr>

<tr>
<td bgcolor="#1f9bdb">
<font class="lgtxt">
Which class did you take from Professor <?php echo $profInfo['lname'] ?><br>
and what type of class was it?
</font>
</td>
<td bgcolor="#1f9bdb" align="center">
<select name="course">
<?php PrintCourseAbbrevs($profInfo['deptabbrev']); ?>
</select>
<input type="text" name="number" size="3" maxlength="3">
<br>
<select name="coursetype">
<option value="choose">-Course Type-</option>
<option value="lec">Lecture</option> 
<option value="lab">Lab</option> 
<option value="rec">Recitation</option> 
<option value="exp">Experimental</option> 
</select>
</td>
</tr>

<tr>
<td>
<font class="lgtxt">
Why'd you take the class?
</font>
</td>
<td align="center">
<select name="studentcoursetype">
<option value="choose">-Fulfills-</option>
<option value="elective">Elective</option>
<option value="ge">General Ed</option>
<option value="major">Required (major course)</option>
<option value="support">Required (support course)</option>
</select>
</td>
</tr>



<tr>
<td bgcolor="#1f9bdb">
<font class="lgtxt">
What year are you?
</font>
</td>
<td bgcolor="#1f9bdb" align="center">
<select name="studentclass">
<option value="choose">-Your Standing-</option>
<option value="frosh">Freshman</option>
<option value="soph">Sophomore</option>
<option value="junior">Junior</option>
<option value="senior">Senior</option>
<option value="spr-senior">5th/6th Year Senior</option>
<option value="grad">Grad Student</option>
</select>
</td>
</tr>

<tr>
<td>
<font class="lgtxt">
What grade did you get?
</font>
</td>
<td align="center">

<select name="grade">
<option value="na">N/A</option>
<option value="a">A</option>
<option value="b">B</option>
<option value="c">C</option>
<option value="d">D</option>
<option value="f">F</option>
<option value="w">W</option>
<option value="cr">CR</option>
<option value="nc">NC</option>
</select>
</td>
</tr>
<tr>
<td bgcolor="#1f9bdb">
<font class="lgtxt">
Grade this instructor's ability to present the course material clearly.
</font>
</td>
<td bgcolor="#1f9bdb" align="center">
<select name="ques1">
<option value="na">-choose grade-</option>
<option value="4">A (excellent)</option>
<option value="3">B (above average)</option>
<option value="2">C (average)</option>
<option value="1">D (below average)</option>
<option value="0">F (failed)</option>
</select>
</td>
</tr>
<tr>
<td>
<font class="lgtxt">
Grade this instructor's ability to recognize<br> 
and clarify student difficulties. 
</font>
</td>
<td align="center">
<select name="ques2">
<option value="na">-choose grade-</option>
<option value="4">A (excellent)</option>
<option value="3">B (above average)</option>
<option value="2">C (average)</option>
<option value="1">D (below average)</option>
<option value="0">F (failed)</option>
</select>
</td>
</tr>
<tr>
<td bgcolor="#1f9bdb">
<font class="lgtxt">
Finally, give this instructor an overall grade for the quarter.
</font>
</td>
<td bgcolor="#1f9bdb" align="center">
<select name="ques3">
<option value="na">-choose grade-</option>
<option value="4">A (excellent)</option>
<option value="3">B (above average)</option>
<option value="2">C (average)</option>
<option value="1">D (below average)</option>
<option value="0">F (failed)</option>
</select>
</td>
</tr>

<td colspan="2">
<font class="lgtxt">
What else should we know?
</font>
<p>
<font class="mdtxt">
Please be as informative and objective as possible.  This is your opportunity to help other students, <b>not to rip on a professor because they failed you!</b>
Talk about the teacher's grading policies, homework load, tests... you know, stuff you'd wish you'd known before signing up for the class.
<p>
Remember, the most helpful comments are those which contain details on why a professor rocks or sucks, not those filled with expletives and irrelevant information (which are just asking to be deleted anyway).
</font>
<textarea name="comments" rows="10" cols="75" wrap="virtual"></textarea>
<br>
<font size=-2>HTML tags will be scrubbed.</font>
</td>
</tr>
<tr>
<td bgcolor="#1f9bdb" colspan="2" align="center">
<input type="submit" name="submission" value="Submit Evaluation">
</td>
</tr>
</table>
</form>
<?php
}

function PrintEvaluationSubmittedPage($uiHandle) {
   $pinfo = $uiHandle->GetValue('pInfo');
   $plname = $pinfo['lname'];
   $pid = $pinfo['profid'];

   PrintHTMLHeader();
   PrintHeader();
?>

<font class="title">Evaluation Successfully Recorded</font>
<p>
<font class="lgtxt">
Evaluation for Professor <?php print $plname ?> submitted.
<p>
You may view their updated 
<a class="blknav" href="<?php echo EVALID_URL . $pid ?>">evaluations page</a> 
to see your submission.
</font>
<?php
   PrintNavFooter();
   PrintHTMLFooter();
}
?>
