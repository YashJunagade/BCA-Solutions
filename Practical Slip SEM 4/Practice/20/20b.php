<html>
	<body>
		<h3>Perform Operation</h3>
		<form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">	
			Enter Number : 
			<input type="number" name="num"><br><br>
			Enter Your Choice : 
			<input type="radio" name="choice" value="fibo">Fibonacci Series
			<input type="radio" name="choice" value="sumd">Sum Of Digits<br><br>
			<input type="submit" name="submit" value="Calculate">
		</form>
	</body>
</html>

<?php

function sumOfDigit($num){
	$sum = 0;
	$ldigit;
	$n = $num;
	
	while($num > 0){
		$ldigit = $num % 10;
		$sum += $ldigit ;
		$num /= 10;
	}

	echo "Sum of $n is $sum <br>";
}

function fibo($num){
	$a=0; $b=1; $c=0;
	echo "Fibonacci Series : ";
	for($i=1; $i<$num; $i++){
		echo $a . " ";
		$c = $a + $b;
		$a = $b;
		$b = $c;
	}
}

if(isset($_POST['submit'])){
	$num = $_POST['num'];
	$choice = $_POST['choice'];

	if($choice == "fibo"){
		fibo($num);
	}else if($choice == "sumd"){
		sumOfDigit($num);
	}
}
?>