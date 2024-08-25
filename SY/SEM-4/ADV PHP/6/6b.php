<!-- Create table your according  -->

<!-- index.html  -->

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Employee Details</title>
</head>
<body>
    <h2>Select Employee to View Details</h2>
    <select id="employeeSelect">
        <option value="">Select Employee</option>
        <option value="Yash Junagade">Yash Junagade</option>
        <option value="Tony">Tony</option>
        <option value="Myra">Myra</option>
    </select>

    <h3>Employee Details:</h3>
    <div id="employeeDetails"></div>

    <script>
        document.getElementById('employeeSelect').addEventListener('change', function() {
            var ename = this.value;

            if (ename !== '') {
                var xhr = new XMLHttpRequest();
                xhr.open('POST', 'employee.php', true);
                xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');

                xhr.onreadystatechange = function() {
                    if (xhr.readyState == 4 && xhr.status == 200) {
                        document.getElementById('employeeDetails').innerHTML = xhr.responseText;
                    }
                };

                xhr.send('ename=' + encodeURIComponent(ename));
            } else {
                document.getElementById('employeeDetails').innerHTML = '';
            }
        });
    </script>
</body>
</html>


<!-- employee.php  -->

<?php
$servername = "localhost";
$username = "root";  // replace with your database username
$password = "";      // replace with your database password
$dbname = "your_database_name"; // replace with your database name

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

if (isset($_POST['ename'])) {
    $ename = $_POST['ename'];

    $sql = "SELECT eno, designation, salary FROM EMP WHERE ename = ?";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("s", $ename);
    $stmt->execute();
    $result = $stmt->get_result();

    if ($result->num_rows > 0) {
        while($row = $result->fetch_assoc()) {
            echo "Employee No: " . $row["eno"]. "<br>";
            echo "Name: " . htmlspecialchars($ename) . "<br>";
            echo "Designation: " . $row["designation"]. "<br>";
            echo "Salary: $" . $row["salary"]. "<br>";
        }
    } else {
        echo "No employee found with the name " . htmlspecialchars($ename);
    }

    $stmt->close();
}

$conn->close();
?>
