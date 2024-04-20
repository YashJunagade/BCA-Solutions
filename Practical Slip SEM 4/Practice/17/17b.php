<?php

$xml = simplexml_load_file("University.xml");

foreach($xml->univ as $univ){
	echo "University Name : " . $univ->uname . "<br>";
	echo "City : " . $univ->city . "<br>";
	echo "Rank : " . $univ->rank . "<br>";
}
?>