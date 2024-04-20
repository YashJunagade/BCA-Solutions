<html>
	<body>
		<form method="post" action="">
			Enter Radius : 
			<input type="number" name="r"><br><br>
			<input type="radio" name="choice" value="area">Find Area()<br>
			<input type="radio" name="choice" value="cirumference">Find Circumference()<br><br>
			<input type="submit" value="Calculate" name="cal"> 
		</form>
	</body>
</html>

<?php

if(isset($_POST['cal'])){
	if(isset($_POST['r'])){
		class Circle{
			private $r;
			function __construct($r){
				$this->r = $r;
			}

			function area(){
				$area = M_PI * $this->r * $this->r;
				echo "Area : ". $area . "<br>";
			}

			function circumference(){
				$cir = 2 * M_PI * $this->r;
				echo "Circumference : " . $cir . "<br>";
			}			
		}
		
		$radius = $_POST['r'];
		$c = new Circle($radius);
		
		if($_POST['choice'] == "area"){
			$c->area();
		}else{
			$c->circumference();
		}
	}
}
 

?>