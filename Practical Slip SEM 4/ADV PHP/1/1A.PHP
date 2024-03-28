<!-- Write a PHP script to create a simple calculator that can accept two numbers and perform operations like 
add, subtract, multiplication. (Use the concept of Class) -->

<?php

class Calculator{
    public $n1, $n2;

    function __construct($n1, $n2){
        $this->n1 = $n1;
        $this->n2 = $n2;
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

$n1 = 10; $n2 = 5;
$obj = new Calculator($n1, $n2);

echo "Addition : " . $obj->add() . "<br>";
echo "Subtraction : " . $obj->sub() . "<br>";
echo "Multiplication : ". $obj->mul() . "<br>";
echo "Divide : " . $obj->div() . "<br>";

?>