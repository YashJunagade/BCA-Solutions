<html>
	<body>
		<h3>Select Your Subjects : </h3>
		<form method="post">
			<input type="checkbox" name="arr[]" value="CPP" 
			<?php if(isset($_POST['arr']) && in_array('CPP', $_POST['arr'])) echo "checked"; ?>>CPP <br>
			<input type="checkbox" name="arr[]" value="Operating System" 
			<?php if(isset($_POST['arr']) && in_array('Operating System', $_POST['arr'])) echo "checked"; ?> >Operating System <br>
			<input type="checkbox" name="arr[]" value="Adv PHP" 
			<?php if(isset($_POST['arr']) && in_array('Adv PHP', $_POST['arr'])) echo "checked"; ?> >Adv PHP <br>
			<input type="checkbox" name="arr[]" value="Networking"
			<?php if(isset($_POST['arr']) && in_array('Networking' ,$_POST['arr'])) echo "checked"; ?>>Networking <br><br>
			<input type="submit" name="submit">
		</form>
	</body>
</html>


<?php

	if(isset($_POST['submit'])){
		if(isset($_POST['arr'])){
			$arr = $_POST['arr'];
				
			echo "<h3>You selected : </h3>";
			foreach($arr as $val){
				echo $val . "<br>";
			}
		}
	}
?>