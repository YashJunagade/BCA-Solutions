<?php

	$name = $_GET['name'];
	$age = $_GET['age'];
	$nationality = $_GET['nationality'];
	
	$ans = "";

	if($name == ""){
		$ans .= "Name Cannot be Empty<br>";	
	}else if($name != strtoupper($name)){
		$ans .= "Name Must be in Uppercase<br>";
	}else{
		$ans .= "Correct Name<br>";
	}

	if($age >= 18){
		$ans .= "Correct age you can vote<br>";
	}else if($age == ""){
		$ans .= "Age Cannot be Empty<br>";
	}else{
		$ans .= "Age should not be less than 18 years<br>";
	}

	if(strtolower($nationality) == "india"){
		$ans .= "Correct nationality<br>";
	}else if($nationality == ""){
		$ans .= "Nationality cannot be empty<br>";
	}else{
		$ans .= "Nationality must be india<br>";
	}

	echo $ans;
?>