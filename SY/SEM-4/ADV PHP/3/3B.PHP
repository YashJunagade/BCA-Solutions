<!-- Write a script to create "cricket.xml" file with multiple elements as shown below:
<CricketTeam>
<Team country="Australia">
    <player></player>
    <runs></runs>
    <wicket></wicket>
</Team>
</CricketTeam>
Write a script to add multiple elements in "cricket.xml" file of category, country="India" -->

<?php

$xml = simplexml_load_file("cricket.xml");
echo $xml->asXML();
?>