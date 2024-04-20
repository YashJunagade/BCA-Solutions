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

echo "Class Exists : " . class_exists("Sample") . "<br>";
echo "Method Exists : " . method_exists( "Sample", "showData") . "<br>";
echo "Class : " . get_class($obj) . "<br>";
echo "Methods of Class : ";
print_r(get_class_methods("Sample")) . "<br>";


?>