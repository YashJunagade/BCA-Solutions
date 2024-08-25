<?php
// Define the XML structure
$xmlContent = <<<XML
<?xml version="1.0" encoding="UTF-8"?>
<Bookstore>
    <Yoga>
        <Book>
            <Book_Title>Yoga for Beginners</Book_Title>
            <Book_Author>John Doe</Book_Author>
            <Book_Price>20.99</Book_Price>
        </Book>
        <Book>
            <Book_Title>Advanced Yoga Techniques</Book_Title>
            <Book_Author>Jane Smith</Book_Author>
            <Book_Price>25.50</Book_Price>
        </Book>
    </Yoga>
    <Story>
        <Book>
            <Book_Title>The Adventure of Sherlock Holmes</Book_Title>
            <Book_Author>Arthur Conan Doyle</Book_Author>
            <Book_Price>15.75</Book_Price>
        </Book>
        <Book>
            <Book_Title>Harry Potter and the Sorcerer's Stone</Book_Title>
            <Book_Author>J.K. Rowling</Book_Author>
            <Book_Price>19.99</Book_Price>
        </Book>
    </Story>
    <Technical>
        <Book>
            <Book_Title>Introduction to Algorithms</Book_Title>
            <Book_Author>Thomas H. Cormen</Book_Author>
            <Book_Price>45.00</Book_Price>
        </Book>
        <Book>
            <Book_Title>Design Patterns: Elements of Reusable Object-Oriented Software</Book_Title>
            <Book_Author>Erich Gamma</Book_Author>
            <Book_Price>50.00</Book_Price>
        </Book>
    </Technical>
</Bookstore>
XML;

// Path to the XML file
$filePath = 'Bookcategory.xml';

// Save the XML content to the file
file_put_contents($filePath, $xmlContent);

echo "XML file 'Bookcategory.xml' created successfully.";
?>
