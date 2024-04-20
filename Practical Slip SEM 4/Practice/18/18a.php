<html>
	<body>
		<form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
			Enter Distance (*in meter) : 
			<input type="number" name="dist" ><br><br>
			Covert Distance into : 
			<input type="radio" name="choice" value="centi">Centimeter
			<input type="radio" name="choice" value="kilo">Kilometer<br><br>
			<input type="submit" name="convert" value="Convert">
		</form>
	</body>
</html>


<?php

	if(isset($_POST['convert'])){
		if(isset($_POST['dist'])){
			$choice = $_POST['choice'];
			$distance = $_POST['dist'];
	
			if($choice === "centi"){
				$centi = $distance * 100;
				echo "$distance Meter is equal $centi Centimeter";
			}else{
				$kilo = $distance / 1000;
				echo "$distance Meter is equal $kilo Kilometer";	
			}
		}else{
			echo "Please Enter Distance";
		}
	}else{
		echo "Please Select convert";
	}
?>