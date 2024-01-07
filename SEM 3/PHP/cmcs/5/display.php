<html>
    <head></head>
    <body>

<?php 

if(isset($_POST['gBill'])){
    $itemDetails = $_POST['itemDetails'];

    $item = explode(' ', $itemDetails);

    if(count($item) % 4 == 0){
        echo "<table border='1'>";
        echo "<tr><th>Item Code</th><th>Item Name</th><th>Units sold</th><th>Rate</th><th>Total Amount</th></tr>";
        for($i=0; $i < count($item); $i+=4){
                $code = $item[$i];
                $name = $item[$i+1];
                $unit = $item[$i+2];
                $rate = $item[$i+3];
                $total = $unit * $rate;
                echo "<tr><td>$code</td><td>$name</td><td>$unit</td><td>$rate</td><td>$total</td></tr>";
        }

    }else{
        echo "invalid input";
    }
}

?>

    </body>
</html>
