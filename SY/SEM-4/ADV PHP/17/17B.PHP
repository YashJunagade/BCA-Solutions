<!-- Write a script to create XMLfile “University.xml”. The elements details of “University.xml” are as follows : 
<univ>
    <uname>..........</uname>
    <city>..........</city>
    <rank>..........</rank>
</univ>

1) Store the details of at least 3 universities. 
2) Link the “University.xm1’ file to css and get well formatted outputas given below.... 
i) Uname : 
    Color: black ; 
    Font-family : copperplate Gothic Light; 
    Font-size : 16 pt Font : Bold; 
ii) City and Rank : 
    Color : Yellow; 
    Font-family : Arial ; 
    Font-size : 12 pt Font : Bold; -->


    <?php
$xml = simplexml_load_file("University.xml");

foreach ($xml->univ as $element) {
    echo "University Name: " . $element->uname . "<br>";
    echo "City: " . $element->city . " | Rank: " . $element->rank . "<br>";
}
?>
