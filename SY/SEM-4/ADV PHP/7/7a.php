<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Unit Conversion</title>
</head>
<body>
    <h2>Unit Conversion: Grams to Kilograms and Kilograms to Grams</h2>
    <?php
    // Define the interface
    interface Converter {
        public function gmtokg($grams);
        public function kgtogm($kilograms);
    }

    // Implement the interface in a class
    class Convert implements Converter {
        
        // Convert grams to kilograms
        public function gmtokg($grams) {
            // Ensure grams is a positive number
            if ($grams < 0) {
                throw new InvalidArgumentException("Grams must be a non-negative number.");
            }
            return $grams / 1000;
        }
        
        // Convert kilograms to grams
        public function kgtogm($kilograms) {
            // Ensure kilograms is a positive number
            if ($kilograms < 0) {
                throw new InvalidArgumentException("Kilograms must be a non-negative number.");
            }
            return $kilograms * 1000;
        }
    }

    // Create an instance of the Convert class
    $converter = new Convert();

    // Example conversions
    try {
        $grams = 1500;
        $kilograms = 1.5;
        
        $convertedKg = $converter->gmtokg($grams);
        $convertedGm = $converter->kgtogm($kilograms);
        
        echo "<p>$grams grams is equal to $convertedKg kilograms.</p>";
        echo "<p>$kilograms kilograms is equal to $convertedGm grams.</p>";
    } catch (Exception $e) {
        echo '<p>Error: ' . $e->getMessage() . '</p>';
    }
    ?>
</body>
</html>
