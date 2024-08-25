<!-- Write a PHP script to generate an XML in the following format.
<?xml version = "1.0"?>
<Book Store>
    <Books>
        <PHP>
        <title>Programming PHP</title>
        <publication>O'RELLY</publication>
        <price>800</price>
        </PHP>
        <PHP>
        <title>Beginners PHP</title>
        <publication>WROX</publication>
        <price>900</price>
        </PHP>
    </Books>
</Book Store>
Add more than 5 books details. Display details of book by selecting the publication of book from user. -->

<?php

$doc = new DOMDocument();
$doc->formatOutput = true;

$bookStore = $doc->createElement("bookstore");
$doc->appendChild($bookStore);

$b1 = $doc->createElement("php");
$t1 = $doc->createElement("title", "t1");
$p1 = $doc->createElement("publication", "p1");
$price1 = $doc->createElement("price", "800");
$b1->appendChild($t1);
$b1->appendChild($p1);
$b1->appendChild($price1);
$bookStore->appendChild($b1);

$b2 = $doc->createElement("php");
$t2 = $doc->createElement("title", "t2");
$p2 = $doc->createElement("publication", "p2");
$price2 = $doc->createElement("price", "800");
$b2->appendChild($t2);
$b2->appendChild($p2);
$b2->appendChild($price2);
$bookStore->appendChild($b2);

$b3 = $doc->createElement("php");
$t3 = $doc->createElement("title", "t3");
$p3 = $doc->createElement("publication", "p1");
$price3 = $doc->createElement("price", "800");
$b3->appendChild($t3);
$b3->appendChild($p3);
$b3->appendChild($price3);
$bookStore->appendChild($b3);

$b4 = $doc->createElement("php");
$t4 = $doc->createElement("title", "t4");
$p4 = $doc->createElement("publication", "p2");
$price4 = $doc->createElement("price", "800");
$b4->appendChild($t4);
$b4->appendChild($p4);
$b4->appendChild($price4);
$bookStore->appendChild($b4);

$b5 = $doc->createElement("php");
$t5 = $doc->createElement("title", "t5");
$p5 = $doc->createElement("publication", "p1");
$price5 = $doc->createElement("price", "800");
$b5->appendChild($t5);
$b5->appendChild($p5);
$b5->appendChild($price5);
$bookStore->appendChild($b5);

$doc->save("book.xml");

if(isset($_POST['submit'])){
    $pub = $_POST['pub'];
    $xml = simplexml_load_file("book.xml");

    foreach($xml->php as $book){
        if((string)$book->publication == $pub){
            echo "<h2>Book Details:</h2>";
            echo "Title: " . $book->title . "<br>";
            echo "Publication: " . $book->publication . "<br>";
            echo "Price: $" . $book->price . "<br>";
            echo "<br>";
        }
    }
}

?>