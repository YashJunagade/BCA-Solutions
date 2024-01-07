<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = $_POST['name'];
    $consumer_number = $_POST['consumer_number'];
    $units = $_POST['units'];

    $bill = 150; // fixed meter and service charge
    if ($units <= 50) {
        $bill += $units * 3.50;
    } elseif ($units <= 150) {
        $bill += 50 * 3.50 + ($units - 50) * 4.00;
    } elseif ($units <= 250) {
        $bill += 50 * 3.50 + 100 * 4.00 + ($units - 150) * 5.20;
    } else {
        $bill += 50 * 3.50 + 100 * 4.00 + 100 * 5.20 + ($units - 250) * 6.50;
    }

    echo "Customer Name: " . $name . "<br>";
    echo "Consumer Number: " . $consumer_number . "<br>";
    echo "Electricity Bill: Rs." . number_format($bill, 2);
} else {
?>

<form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
    <label for="name">Customer Name:</label><br>
    <input type="text" id="name" name="name"><br>
    <label for="consumer_number">Consumer Number:</label><br>
    <input type="text" id="consumer_number" name="consumer_number"><br>
    <label for="units">Units Consumed:</label><br>
    <input type="number" id="units" name="units"><br>
    <input type="submit">
</form>

<?php
}
?>
