<html>
<head>
    <title>Temperature Converter</title>
</head>
<body>
    <h2>Fahrenheit to Celsius Converter</h2>
    <form method="post">
        <label for="fahrenheit">Fahrenheit:</label>
        <input type="number" id="fahrenheit" name="fahrenheit" step="any" value="<?php echo isset($_POST['fahrenheit']) ? htmlspecialchars($_POST['fahrenheit']) : ''; ?>" required>
        <button type="submit">Convert</button>
    </form>

    <?php
    if ($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_POST['fahrenheit'])) {
        $fahrenheit = (float)$_POST['fahrenheit'];
        $celsius = ($fahrenheit - 32) * 5 / 9;
        echo "<h3>$fahrenheit °F = " . round($celsius, 2) . " °C</h3>";
    }
    ?>
</body>
</html>
