

<!-- page2.php  -->

<?php
session_start();

if (!isset($_SESSION['page2_total'])) {
    $_SESSION['page2_total'] = 0;
}

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $item_price = $_POST['item_price'];
    $_SESSION['page2_total'] += $item_price;
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Shopping Mall - Page 2</title>
</head>
<body>
    <h1>Shopping Page 2</h1>
    <form method="post">
        <p>Select an item to add to your cart:</p>
        <select name="item_price">
            <option value="60">Item 4 - $60</option>
            <option value="40">Item 5 - $40</option>
            <option value="25">Item 6 - $25</option>
        </select>
        <br><br>
        <input type="submit" value="Add to Cart">
    </form>

    <h2>Page 2 Total: $<?php echo $_SESSION['page2_total']; ?></h2>
    <a href="bill.php">View Bill</a>
</body>
</html>
