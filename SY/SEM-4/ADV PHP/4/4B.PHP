<!-- Create an xml file which should comprise the following:
<cricket>
<player>Sachin Tendulkar</player>
<runs>2000</runs>
<wickets>100</wickets>
<noofnotout>20</noofnotout>
</cricket>
For at least 5 players.
Write a PHP script to display the details of players who have scored more than 1200 runs and at least 50 wickets. -->

<?php

$xml = simplexml_load_file("cricket.xml");

foreach($xml->cricket as $cricket) {
    if($cricket->runs > 1200 && $cricket->wickets > 50) {
        echo "Player: ".$cricket->player."<br>";
        echo "Runs: ".$cricket->runs."<br>";
        echo "Wickets: ".$cricket->wickets."<br>";
        echo "No Of Wickets: " . $cricket->noofnotout . "<br><br>";
    }
}


?>