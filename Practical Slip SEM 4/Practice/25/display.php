<?php

if(isset($_POST['submit'])){
	$conn = mysqli_connect("localhost", "root", "", "test") or die("failed to connect");

	if($_POST['choice'] == "create"){
		$sql = "CREATE TABLE TEACHER(TID INT(4), TNAME VARCHAR(50), ADDRESS VARCHAR(50), SUBJECT VARCHAR(50))";
		
		if(mysqli_query($conn, $sql)){
			echo "Table Created Successfully" ;
			echo "<br><br><button><a href='25b.html'>Go Back</a></button>";
		}else{
			echo "Failed to create table " . mysqli_error($conn);
		}
	}


	if($_POST['choice'] == "insert"){
		$sql = "INSERT INTO TEACHER VALUES(1, 'YASH', 'NASHIK', 'COMPUTER')";
		
		if(mysqli_query($conn, $sql)){
			echo "Values inserted Successfully";
			echo "<br><br><button><a href='25b.html'>Go Back</a></button>";
		}else{
			echo "Failed to insert values " . mysqli_error($conn);
		}
	}

	if($_POST['choice'] == "update"){
		$sql = "UPDATE TEACHER SET TNAME ='YASH JUNAGADE' WHERE TID = 1";

		if(mysqli_query($conn, $sql)){
			echo "Values updated successfully";
			echo "<br><br><button><a href='25b.html'>Go Back</a></button>";
		}else{
			echo "Failed to update values " . mysqli_error($conn);
		}
	}

	if($_POST['choice'] == "display"){
		$sql = "SELECT * FROM TEACHER";
		$result = mysqli_query($conn, $sql) or die("Failed to display");
		
		echo "Displaying Details of teacher details : <br>";
		if(mysqli_num_rows($result)){
			while($row = mysqli_fetch_assoc($result)){
				echo "Teacher Id : " . $row['TID'] . "<br>" . 
					"Teacher Name : " . $row['TNAME'] . "<br>" .
					"Address : " . $row['ADDRESS'] . "<br>" .
					"Subject : " . $row['SUBJECT'] . "<br>";
 			}
		}else{
			echo "No data found";
		}
			echo "<br><br><button><a href='25b.html'>Go Back</a></button>";
	}
}

?>