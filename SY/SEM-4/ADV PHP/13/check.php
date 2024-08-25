<?php

    $name = $_GET['name'];
    $age = $_GET['age'];
    $nationality = $_GET['nationality'];

    $response = '';

    if($name == ""){
        $response .= "Name cannot be empty.<br>";
    }else if ($name != strtoupper($name)) {
        $response .= "Name should be in uppercase.<br>";
    }else{
        $response .= "Correct Name <br>";
    }

    if($age == ""){
        $response .= "Age cannot be empty.<br>";
    }else if ($age < 18) {
        $response .= "Age should be at least 18 years.<br>";
    }else{
        $response .= "Correct Age <br>";
    }

    if($nationality == ""){
        $response .= "Nationality cannot be empty.<br>";
    }else if (strtolower($nationality) != 'indian') {
        $response .= "Nationality should be Indian.<br>";
    }else{
        $response .= "Correct Nationality <br>";
    }

    echo $response ;
?>
