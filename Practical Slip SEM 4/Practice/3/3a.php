<?php

class Calculator{
	private $n1, $n2;

	function __construct($a, $b){
		$this->n1 = $a;
		$this->n2 = $b;
	}

	function add(){
		return $this->n1 + $this->n2;
	}

	function sub(){
		return $this->n1 - $this->n2;
	}
	
	function mul(){
		return $this->n1 * $this->n2;
	}

	function div(){
		return $this->n1 / $this->n2;
	}
}

$a = 10; $b = 5;
$obj = new Calculator($a, $b);
echo "Addition : " . $obj->add() . "<br>";
echo "Subtraction : " . $obj->sub() . "<br>";
echo "Multiplication : " . $obj->mul() . "<br>";
echo "Division : " . $obj->div() . "<br>";
?>