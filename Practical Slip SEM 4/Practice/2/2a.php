<?php

class Sample{
	private $n;

	function setData(){
		$this->n = 10;
	}

	function showData(){
		echo $this->n;
	}
}

$obj = new Sample;

echo "Declared classes : ";
print_r(get_declared_classes());
echo "<br><br><br>";

echo "Methods of class : ";
print_r(get_class_methods("Sample"));
echo "<br><br><br>";

echo "Class Vars : ";
print_r(get_class_vars("Sample"));
echo "<br><br><br>";

?>	