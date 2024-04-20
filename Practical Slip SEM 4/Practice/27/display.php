<?php

if(isset($_GET['num'])){
	$num = $_GET['num'];
	$ans = "";
	$result = 1;

	for($i=1; $i<=$num; $i++){
		$ans .= $i . " * ";
		$result *= $i;
	}
	$ans = rtrim($ans, " * ");
	echo "Factorial of $num is : " . $ans . " = " . $result . "<br>";
}else{
	echo "Enter number";
}

?>