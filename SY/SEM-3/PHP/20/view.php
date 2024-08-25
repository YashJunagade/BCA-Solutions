

<!-- view.php  -->

<?php
    $str = $_COOKIE['str'];
    $fontF = $_COOKIE['fontF'];
    $fSize = $_COOKIE['fSize'];
    $fColor =  $_COOKIE['fColor'];
    $bgColor =  $_COOKIE['bgColor'];
    echo "<body style ='color : $fColor; background-color : $bgColor; font-family: $fontF; font-size : $fSize;'";
    echo "<h1>$str</h1>";
?>