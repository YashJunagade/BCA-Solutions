<html>
	<body>
		<h3>Check String are matching or not : </h3>
		<form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
		Enter First String : 
		<input type="text" name="str1" value="<?php if(isset($_POST['str1'])) echo $_POST['str1']; ?>"><br><br>
		Enter Second String : 
		<input type="text" name="str2" value="<?php if(isset($_POST['str2'])) echo $_POST['str2']; ?>"><br><br>
		<input type="submit" name="check" value="Check">
	</body>
</html>


<?php

if(isset($_POST['check'])){
	$str1 = $_POST['str1'];
	$str2 = $_POST['str2'];

	if($str1 === $str2){
		echo "<h3>String are Matching</h3>";
	}else{
		echo "<h3>String are not Matching</h3>";
	}
}
?>
