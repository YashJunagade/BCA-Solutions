<!-- College.xml  -->

<?xml version="1.0" encoding="UTF-8"?>
<CollegeList>
    <College>
        <Cname>Harvard University</Cname>
        <City>Cambridge</City>
        <Rank>1</Rank>
    </College>
    <College>
        <Cname>Stanford University</Cname>
        <City>Stanford</City>
        <Rank>2</Rank>
    </College>
    <College>
        <Cname>Massachusetts Institute of Technology</Cname>
        <City>Cambridge</City>
        <Rank>3</Rank>
    </College>
</CollegeList>

<!-- index.php  -->

<?php
// Load the XML file
$xml = simplexml_load_file('College.xml');

// Check if the file was loaded successfully
if ($xml === false) {
    echo "Failed to load XML file.";
    exit;
}

// Display the XML data
echo "<h1>College Information</h1>";

foreach ($xml->College as $college) {
    echo "<h2>College Name: " . $college->Cname . "</h2>";
    echo "<p>City: " . $college->City . "</p>";
    echo "<p>Rank: " . $college->Rank . "</p>";
    echo "<hr>";
}
?>
