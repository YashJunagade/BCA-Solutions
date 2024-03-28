<!-- Create a XML file which gives details of movies available in "Venus CD Store" from following
categories
a) Classical b) Action c) Horror
Elements in each category are in the following format
<Category>
<Movie Name>----</Movie Name>
<Release Year>----</Release Year>
<Actor Name>-----</Actor Name>
</Category>
Save the file with name "movies.xml". -->

<?php

$xml = simplexml_load_file("movies.xml");

foreach($xml->category as $category){
    echo "Category : " . $category['code'] . "<br>";
    echo "Movie Name : " . $category->mname . "<br>";
    echo "Release Year : " . $category->ryear . "<br>";
    echo "Actor Name : " . $category->aname . "<br><br>";
}

?>