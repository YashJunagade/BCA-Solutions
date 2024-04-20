<html>
	<body>
		<form method="post" action="display.php">
			Enter Employee Id : <input type="number" name="id" 
			value="<?php if(isset($_POST['id'])) echo $_POST['id']; ?>"><br><br>
			Enter Employee Name : <input type="text" name="name" 
			value="<?php if(isset($_POST['name'])) echo $_POST['name']; ?>"><br><br>
			Enter Employee Department : <input type="text" name="dept" 
			value="<?php if(isset($_POST['dept'])) echo $_POST['dept']; ?>"><br><br>
			Enter Employee Salary : <input type="number" name="s" 
			value="<?php if(isset($_POST['s'])) echo $_POST['s']; ?>"><br><br>
			<input type="submit" name="submit">
		</form>
	</body>
</html>