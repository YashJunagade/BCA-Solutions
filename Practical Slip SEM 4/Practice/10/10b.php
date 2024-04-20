<html>
	<body>
		<form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
		Enter Number : 
		<input type="number" name="num"><br><br>
		<input type="submit" name="insert" value="Insert">
		<input type="submit" name="delete" value="Delete">
		<input type="submit" name="display" value="Display"><br><br>	
	</body>
</html>

<?php

	session_start();
	
	if(!isset($_SESSION['stack'])){
		$_SESSION['stack'] = array();
	}

	if(isset($_POST['insert'])){
		if(isset($_POST['num'])){
			array_push($_SESSION['stack'], $_POST['num']);
			echo $_POST['num'] . " is pushed";
		}
	}
		

	if(isset($_POST['delete'])){
		$n = array_pop($_SESSION['stack']);
		echo "$n is poped";
	}

	if(isset($_POST['display'])){
		if(empty($_SESSION['stack'])){
			echo "Stack is empty";	
		}else{
			echo "Stack : ";
			foreach($_SESSION['stack'] as $v){
				echo "$v ";
			}
		}
	}	

?>