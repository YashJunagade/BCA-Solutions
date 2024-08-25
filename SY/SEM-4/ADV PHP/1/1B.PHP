<!-- Write a PHP script to create student.xml file which contains student roll no, name, address, college and course. 
Print students detail of specific course in tabular format after accepting course as input. -->

<?php

$student = [
    ['rollno' => '46', 'name' => 'Yash', 'Address' => 'Nashik', 'College' => 'KKW', 'course' => 'BCA'],
    ['rollno' => '46', 'name' => 'Yash', 'Address' => 'Nashik', 'College' => 'KKW', 'course' => 'BCA'],
    ['rollno' => '46', 'name' => 'Yash', 'Address' => 'Nashik', 'College' => 'KKW', 'course' => 'BCA']
];

$doc = new DOMDocument();
$root = $doc->createElement('students');
$doc->appendChild($root);

foreach($student as $studentData){
    $student = $doc->createElement('student');
    foreach($studentData as $key => $value){
        $element = $doc->createElement($key, $value);
        $student->appendChild($element);
    }
    $root->appendChild($student);  
}

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

    foreach($xml->student as $student){
        if((string)$student->course === (string)$course){
            echo "<tr><td>{$student->rollno}</td>
            <td>{$student->name}</td>
            <td>{$student->Address}</td>
            <td>{$student->College}</td>
            <td>{$student->course}</td></tr>";
        }
    }
    echo "</table>";
}else{
    echo "<form  method='POST'>";
    echo "Enter Course : <input type='text' name='course'>";
    echo "<input type='submit'>";
    echo "</form>";
}

?>
