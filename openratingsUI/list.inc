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

function PrintListPage($uiHandle) {

   $pCount = $uiHandle->GetValue('pendingCount');

   PrintHTMLHeader();
   PrintHeader();
?>

<font class="title">Evaluated Professor List</font>
<p>
<font class="lgtxt">
As of <?php print date("g:i:s a, l, F j, Y"); ?>, <?php echo SITE_NAME ?> 
contains a total of <b><?php print $uiHandle->GetValue('evalCount') ?> 
evaluations</b> on <b><?php print $uiHandle->GetValue('profCount') ?> 
professors</b>.  There <?php print (($pCount == 1) ? "is" : "are") . " 
currently <b>" .  $pCount . " <i>new</i> professor" . 
(($pCount == 1) ? "" : "s"); ?> </b> awaiting approval.

</font>

<p>
<center>

<table border="0" cellpadding="0" cellspacing="0" width="40%">
<tr>
<td align="center"><b>Professor</b></td>
<td align="center"><b>Department</b></td>
<td align="center"><b>Number of Evaluations</b></td>
</tr>

<?php
   $color = true;

   foreach ($uiHandle->GetValue('profList') as $prof) {
      print "<tr>\n";

      $colorStr = ($color) ? "bgcolor=\"#1f9bdb\"" : "";
      $navStr = ($color) ? "class=\"nav2\"" : "class=\"blknav\"";
      print "<td $colorStr align=\"center\">\n";
      $color = !$color;

      $pid = $prof['profid'];
      $plname = $prof['lname'];
      $pfname = $prof['fname'];
      $pevals = $prof['evalcount'];
      $pdept = $prof['dept'];

      print "&nbsp;<a $navStr href=\"" . EVALID_URL . "$pid\">$plname, $pfname</a></td>";
      print "<td $colorStr align=\"center\">&nbsp;$pdept</td>";
      print "<td $colorStr align=\"center\">&nbsp;$pevals</td>\n";
      print "</tr>";
   }
?>

</table>
</center>

<p>
<?php 
   PrintHTMLFooter(); 
}
?>
