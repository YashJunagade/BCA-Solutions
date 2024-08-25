<!-- Write a script to create "vehicle.xml" file with multiple elements as given below
<Vehicle>
    <Type = Two Wheeler>
        <Vehicler Name> </Vehicle Name >
        <Company >------ </Company>
        <Color>--------</Color>
        <Average>------</Average>
    </Type>
</Vehicle>
Also add Type = "Four Wheeler" and its elements -->

<?php

$doc = new DOMDocument();
$doc->formatOutput = true;

$root = $doc->createElement('Vehicle');
$doc->appendChild($root);

$twoWheeler = $doc->createElement('type');
$twoWheeler->setAttribute('value', 'Two Wheeler');

$v1 = $doc->createElement("vname", "activa 6g");
$c1 = $doc->createElement("company", "hyundai");
$col1 = $doc->createElement("color", "black");
$avg1 = $doc->createElement("average", "50");
$twoWheeler->appendChild($v1);
$twoWheeler->appendChild($c1);
$twoWheeler->appendChild($col1);
$twoWheeler->appendChild($avg1);

$root->appendChild($twoWheeler);

$fourWheeler = $doc->createElement("type");
$fourWheeler->setAttribute("value", "four wheeler");

$v2 = $doc->createElement("vname", "swift");
$c2 = $doc->createElement("company", "maruti");
$col2 = $doc->createElement("color", "white");
$avg2 = $doc->createElement("average", "35");
$fourWheeler->appendChild($v2);
$fourWheeler->appendChild($c2);
$fourWheeler->appendChild($col2);
$fourWheeler->appendChild($avg2);

$root->appendChild($fourWheeler);

$doc->save("vehicle.xml");

$xml = simplexml_load_file("vehicle.xml");
foreach($xml->type as $element){
    echo "Type : " . $element['value'] . "<br>";
    echo "Vehicle Name : " . $element->vname . "<br>";
    echo "Company : " . $element->company . "<br>";
    echo "Color : " . $element->color . "<br>";
    echo "Average Milege : " . $element->average . "<br><br>";
}

?>