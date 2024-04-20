<?php

$doc = new DOMDocument();
$doc->formatOutput = true;

$bookstore = $doc->createElement("BookStore");
$doc->appendChild($bookstore);

$book1 = $doc->createElement("PHP");
$t1 = $doc->createElement("Title", "PHP");
$p1 = $doc->createElement("Publication", "Nirali");
$m1 = $doc->createElement("Price", "198");
$book1->appendChild($t1);
$book1->appendChild($p1);
$book1->appendChild($m1);
$bookstore->appendChild($book1);

$book2 = $doc->createElement("PHP");
$t2 = $doc->createElement("Title", "Advance PHP");
$p2 = $doc->createElement("Publication", "Thakur");
$m2 = $doc->createElement("Price", "175");
$book2->appendChild($t2);
$book2->appendChild($p2);
$book2->appendChild($m2);
$bookstore->appendChild($book2);

$book3 = $doc->createElement("PHP");
$t3 = $doc->createElement("Title", "PHP With SQL");
$p3 = $doc->createElement("Publication", "Niral");
$m3 = $doc->createElement("Price", "180");
$book3->appendChild($t3);
$book3->appendChild($p3);
$book3->appendChild($m3);
$bookstore->appendChild($book3);

$book4 = $doc->createElement("PHP");
$t4 = $doc->createElement("Title", "PHP and Framework");
$p4 = $doc->createElement("Publication", "Nirali");
$m4 = $doc->createElement("Price", "170");
$book4->appendChild($t4);
$book4->appendChild($p4);
$book4->appendChild($m4);
$bookstore->appendChild($book4);

$doc->save("book.xml");


if(isset($_POST["submit"])){
	$pub = $_POST['pub'];
	
	$xml = simplexml_load_file("book.xml");
	
	echo "<h3>Book Detail : </h3>";
	foreach($xml->PHP as $book){
		if((string)$book->Publication == $pub){
			echo "Title : " . $book->Title . "<br>" .
				"Publication : " . $book->Publication . "<br>" .
				"Price : " . $book->Price . "<br>";
		}
	}
	echo "<a href='18b.html'>Go Back</a>";
}

?>