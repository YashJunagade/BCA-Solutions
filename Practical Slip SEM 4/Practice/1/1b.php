<?php

$doc = new DOMDocument();
$doc->formatOutput = true;

$students = $doc->createElement("Students");
$doc->appendChild($students);

$student1 = $doc->createElement("Student");
$r1 = $doc->createElement("RollNo", "46");
$n1 = $doc->createElement("Name", "Yash Junagade");
$a1 = $doc->createElement("Address", "Nashik");
$clg1 = $doc->createElement("College", "KKW");
$c1 = $doc->createElement("Course", "BCA");
$student1->appendChild($r1);
$student1->appendChild($n1);
$student1->appendChild($a1);
$student1->appendChild($clg1);
$student1->appendChild($c1);
$students->appendChild($student1);


$student2 = $doc->createElement("Student");
$r2 = $doc->createElement("RollNo", "36");
$n2 = $doc->createElement("Name", "Tony Stark");
$a2 = $doc->createElement("Address", "New York");
$clg2 = $doc->createElement("College", "KKW");
$c2 = $doc->createElement("Course", "BCA");
$student2->appendChild($r2);
$student2->appendChild($n2);
$student2->appendChild($a2);
$student2->appendChild($clg2);
$student2->appendChild($c2);
$students->appendChild($student2);

$doc->save("student.xml");


if(isset($_POST['course'])){
	$course = $_POST['course'];
	$xml = simplexml_load_file("student.xml");

	echo "<table border=1>";
	echo "<tr><th>RollNo</th>
		<th>Name</th>
		<th>Address</th>
		<th>College</th>
		<th>Course</th></tr>";

	foreach($xml->Student as $student){
		if($course === (string)$student->Course){
			echo "<tr><td>$student->RollNo</td>
			<td>$student->Name</td>
			<td>$student->Address</td>
			<td>$student->College</td>
			<td>$student->Course</td></tr>";
		}
	}
		echo "</table>";
}else{

	echo "<form method='post'>";
	echo "Enter Course : <input type='text' name='course'>";
	echo "<input type='submit'>";
	echo "</form>";
}

?>