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

function PrintErrorPage($errorType) {
   PrintHTMLHeader();
   PrintHeader();
?>
   <font color="red" size="6" face="Arial,Helvetica,sans-serif">Error</font>
   <font size="4" face="Arial,Helvetica,sans-serif">
   <p>
   The following error occured while processing your request: "<?php print $errorType ?>."
   </p>
   <p>
   Please press the "Back" button on your web browser, correct any incomplete 
   or incorrect information, and try submitting your request again.
   </p>
   <p>
   If this problem persists, contact <a href="mailto:<?php echo ERROR_EMAIL ?>"><?php echo ERROR_EMAIL ?></a>
    with this error message and the details of your submission. 
   </font>
   </p>
   <p>
   <font size="4" face="Arial,Helvetica,sans-serif">
   <b>Thanks for using <?php echo SITE_NAME ?>!</b>
   </font>
   </p>
<?php
   PrintNavFooter();
   PrintHTMLFooter();
}

function PrintFailedAssertion($file, $line, $code) {
   PrintHTMLHeader();
   PrintHeader();

   // display just just the filename, not the full path
   $file = preg_replace("/.+\/(.*)$/", "$1", $file);
?>
   <font color="red" size="6" face="Arial,Helvetica,sans-serif">Failed Assertion</font>
   <font size="4" face="Arial,Helvetica,sans-serif">
   <p>
   An assertion failed in file <?php print $file ?> 
   on line <?php print $line ?>.
   </p>
   <p>
   You are welcome to attempt your request again, however this type of error
   is typically caused by software and/or server errors which cannot be 
   corrected by users.
   </p>
   <p>
   Please contact <a href="mailto:<?php echo ERROR_EMAIL ?>"><?php echo ERROR_EMAIL ?></a>
   with the details of this assertion message and what you were attempting to
   do at the time.
   </font>
   </p>
   <p>
   <font size="4" face="Arial,Helvetica,sans-serif">
   <b>Thanks for using <?php echo SITE_NAME ?>!</b>
   </font>
   </p>
<?php
   PrintNavFooter();
   PrintHTMLFooter();
}

?>
