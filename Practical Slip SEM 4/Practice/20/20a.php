<?php

$xml = simplexml_load_file("movies.xml");

echo "<h3>Movies Details</h3>";
foreach($xml->category as $movie){
	echo "Category : " . $movie['type'] . "<br>" .
		"Movie Name : " . $movie->name . "<br>" .
		"Release Year : " . $movie->year . "<br>" . 
		"Actor Name : " . $movie->actor . "<br>";
}
?>