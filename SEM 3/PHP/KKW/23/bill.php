<?php 
    if(isset($_POST['bill'])){
        echo "<h2> Customer Information :</h2>";
        echo "Name : " . $_POST['name']. "<br>";
        echo "Address : " . $_POST['address']. "<br>";
        echo "Phone No : " . $_POST['no']. "<br>";
        
        echo "<h2> Customer Information :</h2>";
        echo "Product Name : " . $_POST['pname']. "<br>";
        echo "Quantity : " . $_POST['quantity']. "<br>";
        echo "Rate : " . $_POST['rate']. "<br>";
        echo "Total Bill : " . $_POST['quantity'] * $_POST['rate'] . "<br>";
    }
?>