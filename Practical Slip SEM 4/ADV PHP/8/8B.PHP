<!-- Write an Ajax script to get player details from XML file when user select player name. 
Create XML file to store details of player (name, country, wickets and runs). -->

<?php

$pname = $_GET['name'];
$xml = simplexml_load_file("cricket.xml");
$result = "";
$flag = false;

foreach($xml->player as $player){
    if($player->name == $pname){
        $result .= "Player Name : " . $player->name . "<br>" . 
        "Player Country : " . $player->country . "<br>" .
        "Player Wickets : " . $player->wickets . "<br>" .
        "Player Runs : " . $player->runs . "<br>";
        $flag = true;
    }
}
if($flag == false){
    $result .= "No player found";
}else{
    echo $result;
}


?>