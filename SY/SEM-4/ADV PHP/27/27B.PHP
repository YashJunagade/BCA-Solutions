<!-- Write a PHP script to read book.XML and print book details in tabular format using simple XML
(Content of book.XML are book_code, book_name,author, year price). -->

<?php

$xml = simplexml_load_file("book.xml");

echo "<table border = 1>
    <tr>
    <th>Book Code</th>
    <th>Book Name</th>
    <th>Author</th>
    <th>Year</th>
    <th>Price</th>
    </tr>";

    foreach($xml->book as $book){
        echo "<tr><td> " . $book->code . 
            "</td><td>" . $book->name . 
            "</td><td>" . $book->author . 
            "</td><td>" . $book->year . 
            "</td><td>" . $book->price . 
            "</td></tr>";
    }
    echo "</table>"; 
?>