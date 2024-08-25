<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Simple Calculator</title>
</head>
<body>
    <h2>Calculator</h2>
    <form method="post">
        <label for="value1">Value 1:</label>
        <input type="number" id="value1" name="value1" step="any" required>
        <br>
        <label for="value2">Value 2:</label>
        <input type="number" id="value2" name="value2" step="any" required>
        <br>
        <label for="operation">Operation:</label>
        <select id="operation" name="operation" required>
            <option value="add">Add</option>
            <option value="subtract">Subtract</option>
            <option value="multiply">Multiply</option>
            <option value="divide">Divide</option>
        </select>
        <br>
        <button type="submit">Calculate</button>
    </form>

    <div>
        <?php
        class Calculator {
            private $value1;
            private $value2;

            public function __construct($value1, $value2) {
                $this->value1 = $value1;
                $this->value2 = $value2;
            }

            public function add() {
                return $this->value1 + $this->value2;
            }

            public function subtract() {
                return $this->value1 - $this->value2;
            }

            public function multiply() {
                return $this->value1 * $this->value2;
            }

            public function divide() {
                if ($this->value2 == 0) {
                    return "Division by zero is not allowed.";
                }
                return $this->value1 / $this->value2;
            }
        }

        if ($_SERVER['REQUEST_METHOD'] == 'POST') {
            $value1 = $_POST['value1'];
            $value2 = $_POST['value2'];
            $operation = $_POST['operation'];

            $calculator = new Calculator($value1, $value2);

            switch ($operation) {
                case 'add':
                    $result = $calculator->add();
                    echo "Result of addition: $result";
                    break;
                case 'subtract':
                    $result = $calculator->subtract();
                    echo "Result of subtraction: $result";
                    break;
                case 'multiply':
                    $result = $calculator->multiply();
                    echo "Result of multiplication: $result";
                    break;
                case 'divide':
                    $result = $calculator->divide();
                    echo "Result of division: $result";
                    break;
            }
        }
        ?>
    </div>
</body>
</html>
