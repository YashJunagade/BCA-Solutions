<?php
$name = $_GET['name'];

$result = "";

if ($name == "") {
    $result = "Enter Username";
} else if (strlen($name) < 3) {
    $result = "Username is too short";
} else {
    $result = "Valid Username";
}

echo $result;
?>
