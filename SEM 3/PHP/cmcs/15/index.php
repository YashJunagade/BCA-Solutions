<!DOCTYPE html>
<html>
<head>
    <title>Grocery List</title>
</head>
<body>
    <h1>Grocery List</h1>
    <form method="post">
        <h2>Select Grocery Items:</h2>
        <input type="checkbox" name="items[]" value="Apple"> Apple - $1.00<br>
        <input type="checkbox" name="items[]" value="Banana"> Banana - $0.50<br>
        <input type="checkbox" name="items[]" value="Milk"> Milk - $2.00<br>
        <input type="checkbox" name="items[]" value="Bread"> Bread - $1.50<br>
        <input type="checkbox" name="items[]" value="Eggs"> Eggs - $2.50<br>
        <input type="checkbox" name="items[]" value="Chicken"> Chicken - $5.00<br>

        <h2>Quantity:</h2>
        <input type="number" name="quantity" value="1" min="1"><br><br>

        <input type="submit" name="calculate" value="Calculate Bill">
    </form>

    <?php
    if (isset($_POST['calculate'])) {
        $selectedItems = $_POST['items'] ?? [];
        $quantity = isset($_POST['quantity']) ? intval($_POST['quantity']) : 1;
        $totalCost = 0;

        $itemPrices = [
            'Apple' => 1.00,
            'Banana' => 0.50,
            'Milk' => 2.00,
            'Bread' => 1.50,
            'Eggs' => 2.50,
            'Chicken' => 5.00,
        ];

        foreach ($selectedItems as $item) {
            if (array_key_exists($item, $itemPrices)) {
                $totalCost += $itemPrices[$item] * $quantity;
            }
        }

        echo "<h2>Bill:</h2>";
        echo "Total Cost: $" . number_format($totalCost, 2);
    }
    ?>

</body>
</html>
