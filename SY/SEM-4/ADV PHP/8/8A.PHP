<!-- Write a PHP Script to create class Shape and its sub-class Triangle, Square, Circle and 
display area of selected shape (use concept of inheritance). -->

<?php

class Shape{
}

class Triangle extends Shape{
    private $b, $h;

    function __construct($base, $height){
        $this->b = $base;
        $this->h = $height;
    }

    function area(){
        $area = 0.5*$this->b*$this->h;
        echo "Area of triangle = $area";
        echo "<br>";
    }
}

class Square extends Shape{
    private $s;
    
    function __construct($side){
        $this->s = $side;
    }
    
    function area(){
        $area = $this->s * $this->s;
        echo "Area of square = $area";
        echo "<br>";
    }
    
}

class Circle extends Shape{
    private $r;

    function __construct($radius){
        $this->r = $radius;
    }
    
    function area(){
        $area = M_PI * $this->r * $this->r;
        echo "Area of circle = $area";
        echo "<br>";
    }
}

$t = new Triangle(10, 20);
$s = new Square(10);
$c = new Circle(5);

$t->area();
$s->area();
$c->area();

?>