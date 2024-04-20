<?php

$doc = new DOMDocument();
$doc->load("student.xml");

echo $doc->saveXML();
echo "<br>";

$doc->save("student.doc");

$xml = simplexml_load_file("student.xml");
echo "Students Name : " . "<br>";
foreach($xml->Student as $student){
	echo $student->Name . "<br>";
}
?>