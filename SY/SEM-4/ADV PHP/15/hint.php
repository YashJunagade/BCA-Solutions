<?php

$cities = array(
    "Mumbai", "Pune", "Nagpur", "Nashik", "Aurangabad", "Solapur", "Amravati", "Kolhapur", "Jalgoan", "Akola", "Shegoan", "Satara");

$hint = "";
$cname = $_GET['cname'];

if ($cname !== "") {
    foreach ($cities as $city) {
        if (stripos($city, $cname) !== false) {
            $hint .= $city . "<br>";
        }
    }
}

echo $hint !== "" ? $hint : "No suggestions";

?>
