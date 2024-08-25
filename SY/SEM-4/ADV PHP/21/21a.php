<?php
// Define the XML structure
$xmlContent = <<<XML
<?xml version="1.0" encoding="UTF-8"?>
<Course>
    <Computer_Science>
        <Student>
            <name>John Doe</name>
            <class>SYBBA(CA)</class>
            <percentage>85.5</percentage>
        </Student>
        <Student>
            <name>Jane Smith</name>
            <class>SYBBA(CA)</class>
            <percentage>90.0</percentage>
        </Student>
        <Student>
            <name>Emily Johnson</name>
            <class>SYBBA(CA)</class>
            <percentage>78.2</percentage>
        </Student>
        <Student>
            <name>Michael Brown</name>
            <class>SYBBA(CA)</class>
            <percentage>82.7</percentage>
        </Student>
        <Student>
            <name>Lisa White</name>
            <class>SYBBA(CA)</class>
            <percentage>88.3</percentage>
        </Student>
    </Computer_Science>
</Course>
XML;

// Path to the XML file
$filePath = 'Course.xml';

// Save the XML content to the file
file_put_contents($filePath, $xmlContent);

echo "XML file 'Course.xml' created successfully.";
?>
