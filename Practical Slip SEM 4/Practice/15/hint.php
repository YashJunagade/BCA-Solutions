<?php

	$name = $_GET['name'];
	$hint = "";
	$cities = array("Akola", "Aurangabad", "Nashik", "Pune", "Mumbai", "Nagpur", "New Mumbai", "Thane", "Chattisgad", "Dhule", "Bhusaval");

	if($name !== ""){
		foreach($cities as $city){
			if(stripos($city, $name) !== false){
				$hint .= "$city <br>";
			}
		}
	}else{
		$hint .= "Please enter city name";
	}

	echo ($hint !== "") ? $hint : "No Suggestion";
?>