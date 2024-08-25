


<!-- bill.php  -->

<?php
session_start();

$page1_total = isset($_SESSION['page1_total']) ? $_SESSION['page1_total'] : 0;
$page2_total = isset($_SESSION['page2_total']) ? $_SESSION['page2_total'] : 0;
$grand_total = $page1_total + $page2_total;
?>

<!DOCTYPE html>
<html>
<head>
    <title>Shopping Mall - Bill</title>
</head>
<body>
    <h1>Your Bill</h1>
    <p>Page 1 Total: $<?php echo $page1_total; ?></p>
    <p>Page 2 Total: $<?php echo $page2_total; ?></p>
    <h2>Grand Total: $<?php echo $grand_total; ?></h2>

    <a href="page1.php">Back to Page 1</a><br>
    <a href="page2.php">Back to Page 2</a><br>
    <a href="clear_session.php">Clear Cart and Start Over</a>
</body>
</html>
