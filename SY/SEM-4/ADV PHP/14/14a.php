<html>
<head>
    <title>Reverse String</title>
</head>
<body>
    <h2>Reverse String</h2>
    <form method="post">
        <label for="inputString">Enter a string:</label>
        <input type="text" id="inputString" name="inputString" value="<?php echo isset($_POST['inputString']) ? htmlspecialchars($_POST['inputString']) : ''; ?>" required>
        <button type="submit">Reverse</button>
    </form>

    <?php
    if ($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_POST['inputString'])) {
        $inputString = $_POST['inputString'];
        $reversedString = strrev($inputString);
        echo "<h3>Reversed String: " . htmlspecialchars($reversedString) . "</h3>";
    }
    ?>
</body>
</html>
