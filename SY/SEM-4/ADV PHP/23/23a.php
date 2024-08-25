<!-- sports.xml  -->

<?xml version="1.0" encoding="UTF-8"?>
<Sports>
    <Sport name="Football">
        <Player position="Forward">Lionel Messi</Player>
        <Player position="Midfielder">Kevin De Bruyne</Player>
    </Sport>
    <Sport name="Basketball">
        <Player position="Guard">Stephen Curry</Player>
        <Player position="Forward">LeBron James</Player>
    </Sport>
    <Sport name="Tennis">
        <Player position="Singles">Roger Federer</Player>
        <Player position="Doubles">Serena Williams</Player>
    </Sport>
</Sports>


<!-- index.php  -->

<?php
// Load the XML file into a SimpleXMLElement object
$xml = simplexml_load_file('Sports.xml');

// Check if the file was loaded successfully
if ($xml === false) {
    echo "Failed to load XML file.";
    exit;
}

// Display the XML attributes and elements
echo "<h1>Sports Data</h1>";

// Iterate over each Sport element
foreach ($xml->Sport as $sport) {
    echo "<h2>Sport: " . $sport['name'] . "</h2>"; // Display the attribute 'name' of the Sport element
    
    // Iterate over each Player element within the current Sport
    foreach ($sport->Player as $player) {
        echo "<p>Player: " . $player . " - Position: " . $player['position'] . "</p>"; // Display the player name and position attribute
    }
}
?>
