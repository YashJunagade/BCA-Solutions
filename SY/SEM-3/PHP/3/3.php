<!-- 3.php  -->

<?php
// Get the numbers and the selected operation from the form
$number1 = $_POST['number1'];
$number2 = $_POST['number2'];
$operation = $_POST['operation'];

// Function to perform the calculation based on the operation
function calculate($number1, $number2, $operation) {
    switch ($operation) {
        case 'add':
            return $number1 + $number2;
        case 'subtract':
            return $number1 - $number2;
        case 'multiply':
            return $number1 * $number2;
        case 'divide':
            if ($number2 != 0) {
                return $number1 / $number2;
            } else {
                return "Error: Division by zero!";
            }
        default:
            return "Invalid operation selected.";
    }
}

// Call the function and store the result
$result = calculate($number1, $number2, $operation);

// Display the result
echo "<h2>Result: $result</h2>";
?>
