<?php

class Shape{

}

class Triangle extends Shape{
	
	private $b, $h;
	function __construct($b, $h){
		$this->b = $b;
		$this->h = $h;
	}

	function area(){
		$area = 0.5 * $this->b * $this->h;
		echo "Area Of Triangle : " . $area . "<br>";
	}
}

class Square extends Shape{

	private $s;
	function __construct($s){
		$this->s = $s;
	}
	
	function area(){
		$area = $this->s * $this->s;
		echo "Area of Square : " . $area . "<br>";
	}
}

class Circle extends Shape{

	private $r;
	function __construct($r){
		$this->r = $r;
	}

	function area(){
		$area = M_PI * $this->r * $this->r;
		echo "Area of Circle : " . $area . "<br>";
	}
}


$t = new Triangle(10, 20);
$s = new Square(10);
$c = new Circle(5);


$t->area();
$s->area();
$c->area();
?>