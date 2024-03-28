<!-- Write a script to solve following questions (Use "Student.xml" file)
i) Create a DOM Document object and load this XML file.
ii) Get the output of this Document to the browser.
iii) Save this [. XML] document in another format i.e. in [.doc]
Write a XML Script to print the names of the student present in "Student.xml" file. -->

<?php

$doc = new DOMDocument();
$doc->load("student.xml");

echo $doc->saveXML();
echo "<br>";

$doc->save("student.doc");

$xml = simplexml_load_file("student.xml");
foreach($xml->student as $student){
    echo "Student Name : " . $student->name . "<br>";
}

?>