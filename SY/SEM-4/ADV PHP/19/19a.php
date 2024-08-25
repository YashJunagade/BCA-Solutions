<!-- stockList.xml  -->

<?xml version="1.0"?>
<stock>
    <fruit>
        <name>Apple</name>
        <quantity>50</quantity>
        <price>1.20</price>
    </fruit>
    <fruit>
        <name>Banana</name>
        <quantity>30</quantity>
        <price>0.80</price>
    </fruit>
    <vegetable>
        <name>Carrot</name>
        <quantity>40</quantity>
        <price>0.90</price>
    </vegetable>
    <vegetable>
        <name>Broccoli</name>
        <quantity>20</quantity>
        <price>1.50</price>
    </vegetable>
</stock>


<html>
<body>
    <h2>Stock List</h2>
    <?php
    $xmlFile = 'stockList.xml';

    // Load XML file
    $xml = simplexml_load_file($xmlFile);

    // Convert XML to array
    $array = json_decode(json_encode($xml), true);

    // Display array
    echo '<pre>';
    print_r($array);
    echo '</pre>';
    ?>
</body>
</html>
