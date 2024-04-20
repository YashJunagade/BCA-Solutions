<?php

$xml = simplexml_load_file("book.xml");

echo "<table border=1>";
echo "<tr><th>Book Code</th>
	<th>Book Name</th>
	<th>Author</th>
	<th>Year</th>
	<th>Price</th></tr>";

foreach($xml->book as $book){
	echo "<tr><td>" . $book->code . "</td>" . 
		"<td>" . $book->name . "</td>" .
		"<td>" . $book->author . "</td>" .
		"<td>" . $book->year . "</td>" .
		"<td>" . $book->price . "</td></tr>";
}

echo "</table>";
?>