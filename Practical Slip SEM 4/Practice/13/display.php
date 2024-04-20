<?php

	if(isset($_POST['submit'])){
		$id = $_POST['id'];
		$name = $_POST['name'];
		$dept = $_POST['dept'];
		$salary = $_POST['s'];

		echo "	<h1>Employee Details </h1>
			<h2>Employee Id : $id <br>
			Employee Name : $name <br>
			Department : $dept <br>
			Salary : $salary <br>
			</h2>";
	}
?>