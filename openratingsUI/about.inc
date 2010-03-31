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

function PrintAboutPage($uiHandle) {
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

<table bgcolor="#FFFFFF" width="100%">
<tr>
<td>
<img src="<?php echo IMAGES_URL ?>/trans.gif" width="10" height="1">
</td>
<td width="100%">

<center>
<p class="lgtxt"><nobr>O u r&nbsp; B e g i n n i n g s</nobr></p>
</center>

<p class="mdtxt">
<img src="<?php echo IMAGES_URL ?>/trans.gif" width="20" height="1">
You might want to talk about why you set up <?php echo SITE_NAME ?>, and what 
you want to accomplish; maybe who you are, and why you think student/university
communication like this is important.
</p>

<p class="mdtxt">
<img src="<?php echo IMAGES_URL ?>/trans.gif" width="20" height="1">
As always, you can take a look at 
<a href="http://www.polyratings.com/">Polyratings.com</a> to see what we put 
on our About page.
</p>

<center>
<p class="lgtxt"><nobr>A b o u t&nbsp; O p e n R a t i n g s</nobr></p>
</center>

<!--quote table--->
<table width="170" border="0" cellspacing="0" cellpadding="1" align="RIGHT">
<tr><td colspan="2" height="1" valign="top">&nbsp;</td></tr>
<tr>
<td valign="top" align="right"><img src="<?php echo IMAGES_URL ?>/quotes_left.gif" width="29" height="20" alt="" border="0"></td>
<td bgcolor="#ffffff">
<font size="2" color="#003366" face="geneva,arial">
<!---PULLQUOTE HERE------>
Want to know which professor 'seems a few French fries short of a happy meal?'
&nbsp;&nbsp;Well, there's an Internet Web site for you.
<br>
<font size="1" color="#000000"><b>
<!---CREDIT HERE------>
<img src="<?php echo IMAGES_URL ?>/quotes_right.gif" width=29 height=21 alt="" border="0" align="right" valign="bottom">
&#151;Los Angeles Times Article about the first OpenRatings site, Polyratings.com
</b></font></font>
</td></tr>
<tr><td colspan=2 height=1>&nbsp;</td></tr></table>
<!--end quote table-->

<p>
<blockquote>
<font class="mdtxt">
Most people think of the Internet as a mind-boggling network of computers and 
technology. But the truth is, it's an unprecedented network of people, more 
specifically, students. Thousands of students just like you, who have already 
been where you want to go, or are following a path that you've already 
taken.
</font>
</blockquote>
</p>

<p class="mdtxt">
<img src="<?php echo IMAGES_URL ?>/trans.gif" width="20" height="1">
Those words that appeared on a website in 1999, at the beginning of it all. 
Two students in a dorm at California Polytechnic State University, San Luis
Obispo were trying to figure out which professor they wanted to take that 
quarter. And, like most students, they wanted professors that wanted to be in 
the class room... professors that genuinely cared about their students and 
wanted to teach them.
</p>

<p class="mdtxt">
<img src="<?php echo IMAGES_URL ?>/trans.gif" width="20" height="1">
They of course, asked their friends, but none of their friends had taken the
classes they needed to take. So an idea was born: why not use the Internet
to facilitiate the communcation between students about the quality of an
institution's professors?
</p>

<p class="mdtxt">
<img src="<?php echo IMAGES_URL ?>/trans.gif" width="20" height="1">
The first version was perl/CGI driven, and used flat files for storing professor
evaluations. Today, the Polyratings.com professor evaluation engine, given to
the open source community as the OpenRatings professor evaluations engine,
supports a fully database-driven architecture, with a (mostly) plugable user
interface and advanced searching and sorting techniques... in short, just about
everything you'd ever need to build your own professor evaluations site.
</p>

<p class="mdtxt">
<img src="<?php echo IMAGES_URL ?>/trans.gif" width="20" height="1">
Building and implementing such software at Cal Poly has proven very 
interesting. As you might imagine, the university has not always taken kindly 
to our OpenRatings installation at Polyratings.com. In fact, the 
Vice-president of Technology at Cal Poly has tried to shutdown the site and 
demand content be removed on a number of occasions, while misrepresenting his
position to the media when they came around asking questions (details on
Polyratings.com if you'd like to see the dramatic story).
</p>

<p class="mdtxt">
<img src="<?php echo IMAGES_URL ?>/trans.gif" width="20" height="1">
It was these kind of games, coupled with the fact that we felt it that the
code was mature enough and it was time to share this awesome communications
system with others that prompted us to release the code as open source.
</p>

<p class="mdtxt">
<img src="<?php echo IMAGES_URL ?>/trans.gif" width="20" height="1">
If you can believe it, Cal Poly's overreaching intellectual property policy
would claim that Cal Poly, not the original Polyratings.com team, owns the
copyright to the source code that you're viewing. In order to ensure that
any attempt to play this trump could would be effectively useless, we wanted 
to release the code to everyone... so every student, high schooler through 
graduate, can setup their own OpenRatings site, and hopefully positively 
impact their campus the way we've impacted ours.
</p>

<p class="mdtxt">
<img src="<?php echo IMAGES_URL ?>/trans.gif" width="20" height="1">
OpenRatings is a unique open source project in that not only are we offering
freedom in terms of free speech (the source code) and free beer (as in no
exchange of money), but free speech as in... free speech. The open source
model is helping to protect the rights of over 16,000 students who've posted
over some 7,000 evaluations, and that's just at Cal Poly. Open source is
defending not only the freedom of the collegiate programmers of the world,
but the free speech rights of every student on every campus in America that
wants to let other students know what they're in for.
</p>

<p class="mdtxt">
<img src="<?php echo IMAGES_URL ?>/trans.gif" width="20" height="1">
The OpenRatings team recognizes that the power of the Internet lies in the 
students who populate it. If you can imagine a room full of people helping 
you make decisions on who to take for a class or what professor will be 
most helpful with your senior project, then you can imagine a place like 
OpenRatings. With a little help from us, all <i>you</i> need to do is start 
the revolution at <i>your</i> school... 
</p>

</td></tr></table>

</td>
</tr></table>

<p>

<?php 
   PrintHTMLFooter(); 
}   
?>
