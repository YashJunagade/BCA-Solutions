<!-- Write a Calculator class that can accept two values, then add, subtract, multiply them or divide them on request.
For example:
$calc = new Calculator(3, 4);
echo $calc->add(); // Displays "7"
echo $calc->multiply(); // Displays "12" -->

<?php

class Calculator{

    private $n1, $n2;
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
    function multiply() {
        return $this->n1 * $this->n2;      
    }
    function divide(){ 
        return $this->n1 / $this->n2;   
    }    
}

$n1 = 10; $n2 = 5; 
$calc = new Calculator($n1, $n2);

echo "Addition : ".$calc->add() . "<br>";
echo "Subtract : ".$calc->sub() . "<br>";
echo "Multiply : ".$calc->multiply() . "<br>";
echo "Divide : ".$calc->divide() . "<br>";
?>