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
 * Portions Copyright (c) 2001-2002 J. Paul Reed
 *
 * Contributor(s): 
 *
 */

// User Interface Constants 

include_once('php/Constants.php');

define('IMAGES_URL', SITEUI_URL . 'images');
define('CSS_URL', SITEUI_URL . 'style.css');
define('STATSTERMS_URL', SITEUI_URL . 'stats-terms.html');

// Version Info
define('OR_UI_VERSION', '1.3.1');
define('OR_UI_RELEASE_TAG', 'OPENRATINGSUI-1_3_1-RELEASE');

define('PROF_DOODAD_THEME', 'goldstars');
define('MAX_GPA', 4);
define('HALFWAY_GPA', 0.5);

$GLOBALS['oruiDoodadThemes'] = array('goldstars' => 
                      array('full' => IMAGES_URL . '/gold_star_full.gif',
                            'half' => IMAGES_URL . '/gold_star_half.gif',
                            'empty' => IMAGES_URL . '/gold_star_empty.gif'),

                      'maroonstars' => 
                      array('full' => IMAGES_URL . '/maroon_star_full.gif',
                            'half' => IMAGES_URL . '/maroon_star_half.gif',
                            'empty' => IMAGES_URL . '/maroon_star_full.gif'),

                      'diplomas' => 
                      array('full' => IMAGES_URL . '/diploma.gif',
                            'half' => IMAGES_URL . '/diploma_half.gif',
                            'empty' => IMAGES_URL . '/diploma_empty.gif'),
                     );
$GLOBALS['oruiGradeStrings'] = array('a' => 'A',
                                     'b' => 'B',
                                     'c' => 'C',
                                     'd' => 'D',
                                     'f' => 'F',
                                     'w' => 'Withdrawn',
                                     'cr' => 'Credit',
                                     'nc' => 'No Credit',
                                     'na' => 'N/A');


$GLOBALS['oruiClassStandingStrings'] = array('frosh'    => 'Freshman',
                                             'soph'     => 'Sophomore',
                                             'junior'   => 'Junior',
                                             'senior'   => 'Senior',
                                             'spr-senior' => '5th Year Senior',
                                             'grad'     => 'Graduate Student');


$GLOBALS['oruiCourseTypeStrings'] =  array('elective' => 'Elective',
                                           'ge'       => 'General Ed',
                                           'major'    => 'Required (Major)',
                                           'support'  => 'Required (Support)');
?>
