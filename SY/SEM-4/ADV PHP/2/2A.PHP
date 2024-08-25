<!-- Write a PHP script to demonstrate the introspection for examining classes and objects. 
(use function get_declared_classes().get_class_methods() and get_class_vars()). -->

<?php

class Sample{
    public $n;

    function set(){
        $this->n = 10;
    }
    public function show(){
        echo $this->n;
    }
}

$obj = new Sample;

print_r (get_declared_classes());
echo "<br>";
print_r (get_class_methods("Sample"));
echo "<br>";
print_r (get_class_vars("Sample"));
?>