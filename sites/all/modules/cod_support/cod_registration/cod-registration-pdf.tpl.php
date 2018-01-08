<?php
// $Id: page.tpl.php,v 1.1.2.5 2010/04/08 07:02:59 sociotech Exp $
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<head>
  <title><?php print $head_title; ?></title>

  <style>
@page { margin: 0in 0in 0in 0in;}

#container {
  position: absolute;
  background: transparent;
  top: 0;
  left: 0;
  width: 1050px;
  height: 1050px;
  z-index: 0;
}

div.first-name {
  color: #000000;
  width: 1070px;
  text-align: center;
  margin-top: 0px;
  font-size: 20pt;
  height: 180px;
  font-weight: bold;
  font-family: 'Helvetica';
}

div.last-name {
  color: #000000;
  width: 1070px;
  text-align: center;
  font-size: 18pt;
  font-family: 'Helvetica';
  height: 190px;
}

div.company1 {
  color: #000000;
  width: 1070px;
  text-align: center;
  font-size: 10pt;
  font-weight: lighter;
  font-family: 'Helvetica';
  width: 1000px;
  height: 200px;
}

div.barcode {
  margin-top: 0px;
  text-align: center;
}

p.center_tag {
    margin-top:50px;
    margin-left:50px;
}
</style>
</head>
<body>
  <div id="container">
    <div class="first-name">
      <?php print $content['username']['first']; ?>
    </div>
    <div class="last-name">
      <?php print $content['username']['last']; ?>
    </div>
    <div class="company1">
      <span><?php print $content['company']; ?></span>
    </div>
    <div class="barcode">
      <?php print $content['qr_code']; ?>
    </div>
  </div>
</body>
</html>
