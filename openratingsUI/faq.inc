
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

function PrintFAQPage($uiHandle) {
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

  <font size="+2">Put any <?php echo SITE_NAME ?> FAQs you might want to; below
   are some ones we've included, which you'll probably want to re-word.</font>

   <ol>

   <li>How do I know the ratings on a professor's page come from students?
   <p>
   Short answer: you don't.
   <p>
   In fact, it's potentially worse than that... you don't even know that someone
   rating a professor, assuming they are a student, which is a huge assumption
   to make, ever took a professor's class.
   <p>
   Polyratings.com does everything in its power to review questionable postings 
   brought to our attention, but a function of Polyratings' privacy guarantee is
   lack of authentication and login. This means that a professor could post 
   positive ratings about themselves to their pages, or negative ratings about 
   other professors (both of which have happened in the past).
   <p>
   We have been looking into ways of curbing this practice, but for now,
   Polyratings users will have to rely on their own judgement in determining
   which ratings to consider to be accurate; if you think about it, that
   requirement is no different than information you get from any other source.
   <p>
   If you believe a rating comes from a questionable source, please 
   <a href="<?php echo COMMENTS_URL ?>">report it</a>.
   <p></li>

   <li>What are your guidelines regarding comments?
   <p>
   The standard by which we judge all comments is a simple one: value.
   <p>
   We do not judge comments based upon the words they contain or the way they
   express their opinion, but if a comment is reported as innapropriate, we look
   to see what value it adds to both Polyratings.com and to Cal Poly students
   in general.
   <p>
   Calling a professor names is not only immature, but does not add value.
   <p>
   Posting anything but a comment (emails, test questions, etc.) about the 
   professor does not add value.
   <p>
   Replying to other comments instead of giving your own opinion on the 
   professor does not add value.
   <p>
   Value to the student community is the gold standard by which we rate 
   comments when problems are brought to our attention... if the comment lacks 
   value, it will be deleted.
   <p></li>

   <li>Why do you let innapropriate comments be posted in the first place?
   <p>
   Polyratings' staff does not have time to read and approve every comment.
   <p>
   As such, we only hear about innapropriate comments <i>after</i> the fact;
   just because a comment appears does not mean that it's been reviewed and
   deemed acceptable.
   <p>
   If you see an innapropriate comment, <a href="<?php echo COMMENTS_URL ?>">report it</a>; over 90% of 
   the comments reported as innapropriate are either removed or moderated to
   remove offending material.
   <p>
   As an aside, the ratings engine does support an "approval process" for
   comments, but as stated earlier, we don't have time to approve every
   comment, so we don't personally use it.
   <p></li>
   <li>How does keyword search work?
   <p>
   We felt it was necessary to answer this question because when offered a
   keyword search, people will invariably enter... shall we say <i>interesting</i>
   search terms. 
   </p><p>
   If, by chance, a professor's name comes up when searched with particularly
   unflattering keywords, we want to deflect the question which will invariably
   be asked: how do you rate professors based upon keywords submitted in 
   searches?
   </p><p>
   The technical answer? We implement keyword searches by querying a full-text 
   index which was created on the database table containing the text of the 
   evaluations.
   This is a built-in feature of the database Polyratings 2 uses; technical
   specifications for the full-text index can be found 
   <a href="http://www.mysql.com/doc/F/u/Fulltext_Search.html">here</a>.
   </p><p>
   If that answer made no sense, here's the shorter version: the database
   has built-in search capabilities to do "natural language"-based searches.
   These searches take the word(s) entered by the user and perform a
   statistical analysis on all of the comments submitted. Comments which
   include all of the words in the given order are rated higher than comments
   which only contain a few words out of the keyword list. This is all done
   by the database's full-text index searching module, and we simply pass
   the keywords as we receive them on to the searching algorithm's engine.
   </p><p>
   So, if you're unhappy that a professor's name pops up when searching on any
   particular term(s), don't complain to us; complain to the Statistics 
   department: they probably invented the algorithm you're unhappy with. 
   </p></li>
   <li>You don't have Professor Z; how do I get you to add them?
   <p>
   Visit the <a href="<?php echo ADDPROF_URL ?>">professor addition</a> station; <b>be
   prepared</b> to rate the professor you're suggesting we add. We do this
   because we want to have an initial evaluation for every professor we add 
   (as we're sure you do).
   </p></li>
   </ol>
</td>
</tr></table>

<p>

<?php 
   PrintHTMLFooter(); 
}
?>
