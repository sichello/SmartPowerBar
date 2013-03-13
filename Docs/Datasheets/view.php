<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" dir="ltr" lang="en" xml:lang="en">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<link rel="stylesheet" type="text/css" href="https://urcourses.uregina.ca/theme/standard/styles.php?forceconfig=engg" />
<link rel="stylesheet" type="text/css" href="https://urcourses.uregina.ca/theme/engg/styles.php?forceconfig=engg" />

<!--[if IE 7]>
    <link rel="stylesheet" type="text/css" href="https://urcourses.uregina.ca/theme/standard/styles_ie7.css" />
<![endif]-->
<!--[if IE 6]>
    <link rel="stylesheet" type="text/css" href="https://urcourses.uregina.ca/theme/standard/styles_ie6.css" />
<![endif]-->


    <meta name="keywords" content="moodle, ENEL 387: Dragon12 Plus Schematics " />
    <title>ENEL 387: Dragon12 Plus Schematics</title>
    <link rel="shortcut icon" href="https://urcourses.uregina.ca/theme/engg/favicon.ico" />
    <script type="text/javascript" src="https://urcourses.uregina.ca/lib/speller/spellChecker.js"></script>
<!--[if lte IE 7]>
  <style type="text/css" media="screen, tv, projection">
    body { behavior: url(https://urcourses.uregina.ca/lib/csshover3.htc); } /* hover:anything support */
  </style>
<![endif]-->

<script type="text/javascript" src="https://urcourses.uregina.ca/lib/javascript-static.js"></script>
<script type="text/javascript" src="https://urcourses.uregina.ca/lib/javascript-mod.php"></script>
<script type="text/javascript" src="https://urcourses.uregina.ca/lib/overlib/overlib.js"></script>
<script type="text/javascript" src="https://urcourses.uregina.ca/lib/overlib/overlib_cssstyle.js"></script>
<script type="text/javascript" src="https://urcourses.uregina.ca/lib/cookies.js"></script>
<script type="text/javascript" src="https://urcourses.uregina.ca/lib/ufo.js"></script>
<script type="text/javascript" src="https://urcourses.uregina.ca/lib/dropdown.js"></script>  


<!--[if lt IE 7]>
<script defer type="text/javascript" src="https://urcourses.uregina.ca/custom/js/pngfix.js"></script>
<![endif]-->
    

<script type="text/javascript" defer="defer">
//<![CDATA[
setTimeout('fix_column_widths()', 20);
//]]>
</script>
<script type="text/javascript">
//<![CDATA[
function openpopup(url, name, options, fullscreen) {
    var fullurl = "https://urcourses.uregina.ca" + url;
    var windowobj = window.open(fullurl, name, options);
    if (!windowobj) {
        return true;
    }
    if (fullscreen) {
        windowobj.moveTo(0, 0);
        windowobj.resizeTo(screen.availWidth, screen.availHeight);
    }
    windowobj.focus();
    return false;
}

function uncheckall() {
  void(d=document);
  void(el=d.getElementsByTagName('INPUT'));
  for(i=0;i<el.length;i++) {
    void(el[i].checked=0);
  }
}

function checkall() {
  void(d=document);
  void(el=d.getElementsByTagName('INPUT'));
  for(i=0;i<el.length;i++) {
    void(el[i].checked=1);
  }
}

function inserttext(text) {
  text = ' ' + text + ' ';
  if ( opener.document.forms['theform'].message.createTextRange && opener.document.forms['theform'].message.caretPos) {
    var caretPos = opener.document.forms['theform'].message.caretPos;
    caretPos.text = caretPos.text.charAt(caretPos.text.length - 1) == ' ' ? text + ' ' : text;
  } else {
    opener.document.forms['theform'].message.value  += text;
  }
  opener.document.forms['theform'].message.focus();
}

function getElementsByClassName(oElm, strTagName, oClassNames){
	var arrElements = (strTagName == "*" && oElm.all)? oElm.all : oElm.getElementsByTagName(strTagName);
	var arrReturnElements = new Array();
	var arrRegExpClassNames = new Array();
	if(typeof oClassNames == "object"){
		for(var i=0; i<oClassNames.length; i++){
			arrRegExpClassNames.push(new RegExp("(^|\\s)" + oClassNames[i].replace(/\-/g, "\\-") + "(\\s|$)"));
		}
	}
	else{
		arrRegExpClassNames.push(new RegExp("(^|\\s)" + oClassNames.replace(/\-/g, "\\-") + "(\\s|$)"));
	}
	var oElement;
	var bMatchesAll;
	for(var j=0; j<arrElements.length; j++){
		oElement = arrElements[j];
		bMatchesAll = true;
		for(var k=0; k<arrRegExpClassNames.length; k++){
			if(!arrRegExpClassNames[k].test(oElement.className)){
				bMatchesAll = false;
				break;
			}
		}
		if(bMatchesAll){
			arrReturnElements.push(oElement);
		}
	}
	return (arrReturnElements)
}
//]]>
</script>
</head>

<body  class="mod-resource course-655 dir-ltr lang-en_utf8" id="mod-resource-view">
	
	<script type="text/javascript" src="/custom/js/awstats_misc_tracker.js"></script>
	<noscript><p><img src="/custom/js/awstats_misc_tracker.js?nojs=y" alt="" height="0" width="0" style="display: none" /></p></noscript>
	
<div id="page">

    <div id="header" class=" clearfix">
<div class="headermenu"><div class="navigation">
<ul><li><form action="https://urcourses.uregina.ca/mod/resource/view.php"  onclick="this.target='_top';"><fieldset class="invisiblefieldset"><input type="hidden" name="id" value="24471" /><button type="submit" title="Previous activity"><span class="arrow ">&#x25C4;</span><span class="accesshide " >&nbsp;Previous activity</span></button></fieldset></form></li><li><form action="https://urcourses.uregina.ca/course/jumpto.php" method="get"  id="navmenupopup" class="popupform"><div><select id="navmenupopup_jump" name="jump" onchange="self.location=document.getElementById('navmenupopup').jump.options[document.getElementById('navmenupopup').jump.selectedIndex].value;">
   <option value="https://urcourses.uregina.ca/mod/mail/view.php?id=24457" style="background-image: url(https://urcourses.uregina.ca/mod/mail/icon.gif);">Course E-mail</option>
   <optgroup label="Class information
">   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=133218" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Syllabus, Slides and Examples</option>
   <option value="https://urcourses.uregina.ca/mod/assignment/view.php?id=133222" style="background-image: url(https://urcourses.uregina.ca/mod/assignment/icon.gif);">Requirement Specification (due January 20th)</option>
   <option value="https://urcourses.uregina.ca/mod/assignment/view.php?id=135314" style="background-image: url(https://urcourses.uregina.ca/mod/assignment/icon.gif);">Functional Specification (due February 3rd)</option>
   <option value="https://urcourses.uregina.ca/mod/assignment/view.php?id=137088" style="background-image: url(https://urcourses.uregina.ca/mod/assignment/icon.gif);">Detailed Design Specification (due March 10th)</option>
   <option value="https://urcourses.uregina.ca/mod/assignment/view.php?id=143760" style="background-image: url(https://urcourses.uregina.ca/mod/assignment/icon.gif);">Critique of Two Fourth Year Projects (Due April 7th)</option>
   <option value="https://urcourses.uregina.ca/mod/assignment/view.php?id=143761" style="background-image: url(https://urcourses.uregina.ca/mod/assignment/icon.gif);">Final Project Documentation (Due April 7th)</option>
   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=143158" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Project Day General Information</option>
   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=143160" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Project Day Volunteer Duties</option>
   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=143161" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Project Day Volunteer Form</option>
   </optgroup>   <optgroup label="Lab Information">   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=82636" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Lab Schedule 2011</option>
   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=138523" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Information on Lab Exam #1 </option>
   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=143067" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Information on Lab Exam #2</option>
   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=143068" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Previous example of Lab Exam #2</option>
   <option value="https://urcourses.uregina.ca/mod/assignment/view.php?id=140566" style="background-image: url(https://urcourses.uregina.ca/mod/assignment/icon.gif);">Lab Exam 2 - .asm file upload</option>
   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=24469" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Dave's ENEL 387 Web Page</option>
   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=24471" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Dragon12 Plus User's Guide</option>
   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=24472" selected="selected" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Jump to...</option>
   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=140830" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Freescale 9S12DP512 Datasheets</option>
   </optgroup>   <optgroup label="Old Exams">   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=24465" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Midterm 06</option>
   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=24466" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Midterm 04</option>
   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=24467" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Midterm 03</option>
   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=24468" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Midterm 01</option>
   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=100377" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Final 2009</option>
   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=100378" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Final 2008</option>
   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=100379" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Final 2007</option>
   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=100381" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Final 2006</option>
   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=100382" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Final 2005</option>
   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=100383" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Final 2004</option>
   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=100384" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Final 2003</option>
   </optgroup>   <optgroup label="Old Lectures">   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=24474" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Design Documents</option>
   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=24477" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Func_Spec</option>
   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=24478" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Grounding</option>
   <option value="https://urcourses.uregina.ca/mod/resource/view.php?id=24479" style="background-image: url(https://urcourses.uregina.ca/mod/resource/icon.gif);">Chpt 1</option>
    </optgroup></select><input type="hidden" name="sesskey" value="c2ayzLywm9" /><div id="noscriptnavmenupopup" style="display: inline;"><input type="submit" value="Go" /></div><script type="text/javascript">
//<![CDATA[
document.getElementById("noscriptnavmenupopup").style.display = "none";
//]]>
</script></div></form></li><li><form action="https://urcourses.uregina.ca/mod/resource/view.php"   onclick="this.target='_top';"><fieldset class="invisiblefieldset"><input type="hidden" name="id" value="140830" /><button type="submit" title="Next activity"><span class="accesshide " >Next activity&nbsp;</span><span class="arrow ">&#x25BA;</span></button></fieldset></form></li></ul>
</div></div>
<div class="class_fullname">ENEL 387: Microcomputer Systems Design</div>

    </div>    <div class="navbar clearfix">
        <div class="breadcrumb"><h2 class="accesshide " >You are here</h2> <ul>
<li class="first"><a  onclick="this.target='_top'" href="https://urcourses.uregina.ca/">URCourses</a></li><li> <span class="accesshide " >/&nbsp;</span><span class="arrow sep">&#x25BA;</span> <a  onclick="this.target='_top'" href="https://urcourses.uregina.ca/course/view.php?id=655">ENEL 387</a></li><li> <span class="accesshide " >/&nbsp;</span><span class="arrow sep">&#x25BA;</span> Dragon12 Plus Schematics</li></ul></div>
        <div class="navbutton">&nbsp;</div>
    </div>
    <!-- END OF HEADER -->
    <div id="content">
<script type="text/javascript">
<!--
openpopup('/mod/resource/view.php?inpopup=true&id=24472','resource16766','resizable=1,scrollbars=1,directories=1,location=1,menubar=1,toolbar=1,status=1,width=800,height=600');

-->
</script><div class="popupnotice">This resource should appear in a popup window.<br />If it didn't, click here: <a href="https://urcourses.uregina.ca/mod/resource/view.php?inpopup=true&amp;id=24472" onclick="this.target='resource16766'; return openpopup('/mod/resource/view.php?inpopup=true&amp;id=24472', 'resource16766','resizable=1,scrollbars=1,directories=1,location=1,menubar=1,toolbar=1,status=1,width=800,height=600');">Dragon12 Plus Schematics</a></div></div><div id="footer"><p class="helplink"></p><hr /><div class="logininfo">You are logged in as <a  href="https://urcourses.uregina.ca/user/view.php?id=3360&amp;course=655">Lee Sichello</a>  (<a  href="https://urcourses.uregina.ca/login/logout.php?sesskey=c2ayzLywm9">Logout</a>)</div><div class="homelink"><a  href="https://urcourses.uregina.ca/course/view.php?id=655">ENEL 387</a></div></div>
</div>
</body>
</html>
