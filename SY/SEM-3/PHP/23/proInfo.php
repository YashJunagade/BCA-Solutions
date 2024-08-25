

<!-- proInfo.php  -->

<?php 
    if(isset($_POST['next'])){
        $name = $_POST["name"];
        $address = $_POST['address'];
        $no = $_POST['no'];
        echo "<h2> Customer Information :</h2>";
        echo "Name :" . $name. "<br>";
        echo "Address :" . $address. "<br>";
        echo "Phone No :" . $no. "<br>";
    }
?>

<html>
    <body>
        <form method="post" action="bill.php">
            <h2>Product Information :</h2>
            Product Name : <input type="text" name="pname"><br>
            Quantity : <input type="number" name="quantity"><br>
            Rate : <input type = "number" name="rate"><br>
            <input type="submit" name="bill" value="Generate Bill">
            <input type="hidden" name="name" value="<?php echo $name; ?>">
            <input type="hidden" name="address" value="<?php echo $address; ?>">
            <input type="hidden" name="no" value="<?php echo $no; ?>">

        </form>
    </body>
</html>