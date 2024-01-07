<?php
$servername = "localhost";
$username = "username";
$password = "password";
$dbname = "myDB";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$p_name = $_POST['p_name'];

$sql = "SELECT e.* FROM employee e 
        JOIN project_employee pe ON e.eno = pe.eno 
        JOIN project p ON pe.pno = p.pno 
        WHERE p.p_name = '$p_name'";

$result = $conn->query($sql);

if ($result->num_rows > 0) {
    // output data of each row
    while($row = $result->fetch_assoc()) {
        echo "eno: " . $row["eno"]. ", Name: " . $row["e_name"]. ", Qualification: " . $row["qualification"]. "<br>";
    }
} else {
    echo "0 results";
}
$conn->close();
?>
