<!-- index.php  -->

<html>
<head>
    <script>
        function addNumbers() {
            var num1 = document.getElementById('num1').value;
            var num2 = document.getElementById('num2').value;
            
            var xhr = new XMLHttpRequest();
            xhr.open("POST", "add.php", true);
            xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
            
            xhr.onreadystatechange = function() {
                if (xhr.readyState === 4 && xhr.status === 200) {
                    document.getElementById('result').innerText = "Result: " + xhr.responseText;
                }
            };
            
            xhr.send("num1=" + num1 + "&num2=" + num2);
        }
    </script>
</head>
<body>
    <h1>AJAX Addition</h1>
    <form onsubmit="event.preventDefault(); addNumbers();">
        <input type="number" id="num1" placeholder="Enter first number" required>
        <input type="number" id="num2" placeholder="Enter second number" required>
        <button type="submit">Add</button>
    </form>
    <p id="result"></p>
</body>
</html>


<!-- add.php  -->

<?php
if (isset($_POST['num1']) && isset($_POST['num2'])) {
    $num1 = intval($_POST['num1']);
    $num2 = intval($_POST['num2']);
    $sum = $num1 + $num2;
    echo $sum;
} else {
    echo "Invalid input.";
}
?>
