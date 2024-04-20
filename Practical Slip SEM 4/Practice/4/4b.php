<?php

$xml = simplexml_load_file("cricket.xml");

foreach($xml->cricket as $cricket){
	if($cricket->runs > 1200 && $cricket->wickets >= 50){
		echo "Player Name : " . $cricket->player . "<br>";
		echo "Runs : " . $cricket->runs . "<br>";
		echo "Wickets : " . $cricket->wickets . "<br>";
		echo "No Of Not Outs : " . $cricket->noofnotout . "<br>";
	}
}
?>