<?php

$doc = new DOMDocument();
$doc->formatOutput = true;

$cricketTeam = $doc->createElement("CricketTeam");
$doc->appendChild($cricketTeam);

$teamA = $doc->createElement("Team");
$teamA->setAttribute("Country", "India");
$p1 = $doc->createElement("Player", "Virat Kohli");
$r1 = $doc->createElement("Runs", "100");
$w1 = $doc->createElement("Wicket", "2");
$teamA->appendChild($p1);
$teamA->appendChild($r1);
$teamA->appendChild($w1);
$cricketTeam->appendChild($teamA);


$teamB = $doc->createElement("Team");
$teamB->setAttribute("Country", "India");
$p2 = $doc->createElement("Player", "MS Dhoni");
$r2 = $doc->createElement("Runs", "99");
$w2 = $doc->createElement("Wicket", "4");
$teamB->appendChild($p2);
$teamB->appendChild($r2);
$teamB->appendChild($w2);
$cricketTeam->appendChild($teamB);


$teamC = $doc->createElement("Team");
$teamC->setAttribute("Country", "India");
$p3 = $doc->createElement("Player", "Rohit Sharma");
$r3 = $doc->createElement("Runs", "98");
$w3 = $doc->createElement("Wickets", "3");
$teamC->appendChild($p3);
$teamC->appendChild($r3);
$teamC->appendChild($w3);
$cricketTeam->appendChild($teamC);

$doc->save("Cricket.xml");
?>