<?php
// Interface with method for calculating area
interface Shape {
    public function cal_area();
}

// Class Square implementing the Shape interface
class Square implements Shape {
    private $side;

    public function __construct($side) {
        $this->side = $side;
    }

    public function cal_area() {
        return $this->side * $this->side;
    }
}

// Class Rectangle derived from Square and implementing the Shape interface
class Rectangle extends Square {
    private $width;

    public function __construct($length, $width) {
        parent::__construct($length);
        $this->width = $width;
    }

    public function cal_area() {
        // Use side as length here
        $length = $this->side;
        return $length * $this->width;
    }
}

// Class Triangle implementing the Shape interface
class Triangle implements Shape {
    private $base;
    private $height;

    public function __construct($base, $height) {
        $this->base = $base;
        $this->height = $height;
    }

    public function cal_area() {
        return 0.5 * $this->base * $this->height;
    }
}

// Function to create and display the area of different shapes
function displayArea() {
    // Create a Square
    $square = new Square(5);
    echo "Area of Square: " . $square->cal_area() . " sq units<br>";

    // Create a Rectangle
    $rectangle = new Rectangle(5, 10);
    echo "Area of Rectangle: " . $rectangle->cal_area() . " sq units<br>";

    // Create a Triangle
    $triangle = new Triangle(6, 8);
    echo "Area of Triangle: " . $triangle->cal_area() . " sq units<br>";
}

// Display areas of the shapes
displayArea();
?>
