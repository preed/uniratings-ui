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
include_once(PHP_ROOT . 'DBInterfaceLib.php'); // needed for PrintFullResults()
include_once(UI_ROOT . 'eval.inc'); // needed for PrintFullResults()

function PrintSearchPageBox($uiHandle) {
?>

<form method="post">

<center>

<table width="75%" border="0" cellspacing="2" cellpadding="10">
  <tr>
    <th colspan="2" bgcolor="#1f9bdb">Search Method</th>
    <th bgcolor="#003366"><font color="#ffffff">Search Criteria</font></th>
    <th bgcolor="#1f9bdb">Search Output</th>
  </tr>

<td bgcolor="#1f9bdb" align="center" valign="center">Professor<br>Name</td>

<td bgcolor="#1f9bdb" align="center" valign="center">
<input type="radio" name="type" value="ProfName" checked>
</td>

<td rowspan="2" bgcolor="#003366" valign="center" align="left">
<font color="#ffffff" size="3">
<b>Enter search terms:</b><br><input type="text" name="terms" size="50">
</font>
<br>
<font color="#ffffff" size="2">
For <b>professor name search</b>, input the first and/or last name.
<br>
i.e. "John", "Goodteach", or "John Goodteach", but <b>not</b> "Goodteach, John".
<br>
For <b>keyword search</b>, input one or more keywords to search evaluations on.
</font>
</td>

<td rowspan="4" bgcolor="#1f9bdb" align="center" valign="center">
Sort&nbsp;Results:&nbsp;<br>
<select name="sort">
<option value="name">by Name</option>
<option value="date">by Date</option>
<option value="rating">by Rating</option>
</select>
<p>
Output Format:<br>
<select name="format">
<option value="short">Short</option>
<option value="long" selected>Normal</option>
<option value="full">Full</option>
</select>
<p>
<input type="submit" value="Start Search">
</td>
</tr>

<tr>
<td bgcolor="#1f9bdb" align="center" valign="center">Keyword</td>
<td bgcolor="#1f9bdb" align="center" valign="center">
<input type="radio" name="type" value="Keyword">
</td>
</tr>

<tr>
<td bgcolor="#1f9bdb" align="center" valign="center">Course</td>
<td bgcolor="#1f9bdb" align="center" valign="center">
<input type="radio" name="type" value="Class">
</td>
<td bgcolor="#003366" align="center" valign="center">
<select name="abbrev">
<?php
   foreach ($uiHandle->GetValue('courseAbbrevs') as $abbrev)
      print "<option value=\"$abbrev\">$abbrev</option>\n";
?>
</select>
<input type="text" name="number" size="3" maxlength="3">
</td>
</tr>

<tr>
<td bgcolor="#1f9bdb" align="center" valign="center">Department</td>
<td bgcolor="#1f9bdb" align="center" valign="center">
<input type="radio" name="type" value="Dept">
</td>
<td bgcolor="#003366" align="center" valign="center">
<select name="deptid">
<?php
   foreach ($uiHandle->GetValue('deptInfo') as $dept) {
      $did = $dept['deptid'];
      $dname = $dept['name'];
      print "<option value=\"$did\">$dname</option>\n";
   }
?>
</select>
</td>
</tr>

</table>

</form>

</center>
<?php
}


function PrintSearchPage($uiHandle) {
   PrintHTMLHeader();
   PrintHeader();

   PrintSearchPageBox($uiHandle);

   PrintNavFooter();
   PrintHTMLFooter();
}

function PrintNoSearchResults($uiHandle) {
   PrintHTMLHeader();
   PrintHeader();

   print "<font size=\"5\" face=\"Arial, Helvetica, sans-serif\">That search 
    returned no results; please try another search:</font>\n";
   print "<p>\n";
   PrintSearchPageBox($uiHandle);

   PrintNavFooter();
   PrintHTMLFooter();
}

function PrintSearchResults($uiHandle) {
   PrintHTMLHeader();
   PrintHeader();

   $format = $uiHandle->GetValue('searchFormat');
   $type = $uiHandle->GetValue('searchType');
   $results = $uiHandle->GetValue('searchResults');

   if ("short" == $format)
      PrintShortResults($uiHandle, $type, $results); 
   else if ("full" == $format)
      PrintFullResults($uiHandle, $type, $results); 
   else 
      PrintLongResults($uiHandle, $type, $results); // "long" is the default

   PrintNavFooter();
   PrintHTMLFooter();
}


function PrintShortResults($uih, $searchType, $results) {
   print "<font class=\"title\">Search Results</font>\n";
   print "<p><ul>\n";

   assert(isValidSearchType($searchType));
   assert(!is_null($results) && count($results) > 0);

   foreach ($results as $res) {
      $pid = $res['profid'];
      $profInfo = GetProfessorInfo($pid);
      $plname = $profInfo['lname'];
      $pfname = $profInfo['fname'];
      $deptabbrev = $profInfo['deptabbrev'];

      print "<li><a class=\"mdtxt\" href=\"". EVALID_URL . 
       "$pid\">$plname, $pfname ($deptabbrev)</a></li>\n";
   }

   print "</ul>\n"; 
}

function PrintLongResults($uih, $searchType, $results) {
   assert(isValidSearchType($searchType));
   assert(!is_null($results) && count($results) > 0);

   $dbHandle = GetCachedDBConnection();
?>
   <font class="title">Search Results</font>

   <center>
   <table border="0" width="80%" cellpadding="3" cellspacing="0">
   <tr>
     <td align="left" valign="bottom" class="lgtxt">Name</td>
     <td align="center" valign="bottom" class="lgtxt">Department</td>
     <td align="center" valign="bottom" class="lgtxt">Overall<br>Rating</td>
     <td align="center" valign="bottom" class="lgtxt">Number<br>of<br>Evals</td>
<?php
   if ($searchType == "Keyword") {
     print "      <td align=\"center\" valign=\"bottom\" class=\"lgtxt\">Last Rating<br>Submitted</td>\n";
      print "     <td align=\"right\" valign=\"bottom\" class=\"lgtxt\">Keyword<br>Score</td>\n";
   }
   else {
     print "      <td align=\"right\" valign=\"bottom\" class=\"lgtxt\">Last Rating<br>Submitted</td>\n";
   }

   $color = true;

   foreach ($results as $res) {
      $id = $res['profid'];

      if ("Keyword" == $searchType)
         $score = $res['score'];

      $profInfo = GetProfessorInfo($id);
   
      // If professor is deleted/pending/retired/etc.; this is a double
      // check, since searches also check this.
      if (null == $profInfo)
         continue;

      $pname = $profInfo['lname'] . ", " . $profInfo['fname'];
      $pdept = $profInfo['deptname'];
      $pevals = $profInfo['evalcount'];
      $plastrating = ($profInfo['lastrating'] <= 0) ? "N/A" : 
       date("M j, Y", $profInfo['lastrating']);

      $prating = ($profInfo['rating'] < 0) ? "N/A" : $profInfo['rating'];

      $colorStr = ($color) ? " bgcolor=\"#1f9bdb\"" : "";
      $navStr = ($color) ? "class=\"nav2\"" : "class=\"blknav\"";
      $color = !$color;
?>
   <tr>
      <?php print "<td $colorStr><a $navStr href=\"" . EVALID_URL . "$id\">$pname</a></td>\n"; ?>
      <td <?php print $colorStr ?> align="center"><?php print $pdept ?></td>
      <td <?php print $colorStr ?> align="center"><?php print $prating ?></td>
      <td <?php print $colorStr ?> align="center"><?php print $pevals ?></td>
<?php
      if ($searchType == "Keyword") {
         assert(!is_null($score));
         print "<td $colorStr align=\"center\">$plastrating</td>\n";
         print "<td $colorStr align=\"right\">$score</td>\n";
      }
      else {
         print "<td $colorStr align=\"right\">$plastrating</td>\n";
      }

      print "</tr>";
   }
   
   print "</table>\n</center>\n<p>\n"; 
}

function PrintFullResults($uih, $searchType, $results) {
   assert(isValidSearchType($searchType));
   assert(!is_null($results) && count($results) > 0);

   print "<center>";

   foreach ($results as $res) { 
      $id = $res['profid'];

      $uih->PutValue('profInfo', GetProfessorInfo($id));
      $uih->PutValue('profStats', GetProfessorStats($id));
      $uih->PutValue('profEvals', GetProfessorEvals($id));

      PrintEvalProfDetailHeader($uih);
      PrintEvals($uih);
   }

   print "</center>\n<p>\n";
}

?>
