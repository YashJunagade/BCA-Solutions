<?php

	if(isset($_GET['name'])){
		$name = $_GET['name'];
		$ans = "";
		$flag = false;
		$xml = simplexml_load_file("cricket.xml");
		
		foreach($xml->cricket as $cricket){
			if($cricket->name == $name){
				$ans .= "Name : " . $cricket->name . "<br>" . 
					"Country : " . $cricket->country . "<br>" .
					"Runs : " . $cricket->runs . "<br>";
				$flag = true;
			}
		}
		
		if($flag == false){
			$ans .= "Player Not Found";
		}else{
			echo $ans;
		}
	}

?>