<?php

	$name = $_GET['name'];
	$ans = "";
	
	if($name === ""){
		$ans .= "Enter Username";
	}else if(strlen($name) < 3){
		$ans .= "Username is too short";
	}else{
		$ans .= "Valid username";
	}
	
	echo $ans;

?>