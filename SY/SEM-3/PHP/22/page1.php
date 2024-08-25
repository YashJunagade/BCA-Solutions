<!-- page1.php  -->

<?php
session_start();

if (!isset($_SESSION['page1_total'])) {
    $_SESSION['page1_total'] = 0;
}

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $item_price = $_POST['item_price'];
    $_SESSION['page1_total'] += $item_price;
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Shopping Mall - Page 1</title>
</head>
<body>
    <h1>Shopping Page 1</h1>
    <form method="post">
        <p>Select an item to add to your cart:</p>
        <select name="item_price">
            <option value="50">Item 1 - $50</option>
            <option value="30">Item 2 - $30</option>
            <option value="20">Item 3 - $20</option>
        </select>
        <br><br>
        <input type="submit" value="Add to Cart">
    </form>

    <h2>Page 1 Total: $<?php echo $_SESSION['page1_total']; ?></h2>
    <a href="page2.php">Go to Page 2</a>
</body>
</html>
