<?php

// Abstract class Shape with abstract methods area() and volume()
abstract class Shape {
    // Abstract method for area
    abstract public function area();

    // Abstract method for volume
    abstract public function volume();
}

// Rectangle class derived from Shape
class Rectangle extends Shape {
    private $length;
    private $breadth;

    public function __construct($length, $breadth) {
        $this->length = $length;
        $this->breadth = $breadth;
    }

    // Overriding the area method for rectangle
    public function area() {
        return $this->length * $this->breadth;
    }

    // Overriding the volume method for rectangle (rectangle has no volume)
    public function volume() {
        return 0;
    }
}

// Circle class derived from Shape
class Circle extends Shape {
    private $radius;

    public function __construct($radius) {
        $this->radius = $radius;
    }

    // Overriding the area method for circle
    public function area() {
        return pi() * pow($this->radius, 2);
    }

    // Overriding the volume method for circle (circle has no volume)
    public function volume() {
        return 0;
    }
}

// Cylinder class derived from Shape
class Cylinder extends Shape {
    private $radius;
    private $height;

    public function __construct($radius, $height) {
        $this->radius = $radius;
        $this->height = $height;
    }

    // Overriding the area method for cylinder (surface area)
    public function area() {
        return 2 * pi() * $this->radius * ($this->radius + $this->height);
    }

    // Overriding the volume method for cylinder
    public function volume() {
        return pi() * pow($this->radius, 2) * $this->height;
    }
}

// Example usage
$rectangle = new Rectangle(5, 10);
echo "Rectangle Area: " . $rectangle->area() . "\n";
echo "Rectangle Volume: " . $rectangle->volume() . "\n";

$circle = new Circle(7);
echo "Circle Area: " . $circle->area() . "\n";
echo "Circle Volume: " . $circle->volume() . "\n";

$cylinder = new Cylinder(3, 5);
echo "Cylinder Area: " . $cylinder->area() . "\n";
echo "Cylinder Volume: " . $cylinder->volume() . "\n";

?>
