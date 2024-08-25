<!-- index.php  -->

<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "EmployeeDB";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Get the emp_no from the request
$emp_no = $_GET['emp_no'];

// Fetch employee details
$sql_emp = "SELECT e.emp_name, e.address, e.phone, e.salary, d.dept_name, d.location 
            FROM Emp e
            JOIN Emp_Dept ed ON e.emp_no = ed.emp_no
            JOIN Dept d ON ed.dept_no = d.dept_no
            WHERE e.emp_no = $emp_no";
$result_emp = $conn->query($sql_emp);

if ($result_emp->num_rows > 0) {
    // Fetch salary details
    $sql_salary = "SELECT Basic, HR, TA, DA FROM Salary WHERE emp_no = $emp_no";
    $result_salary = $conn->query($sql_salary);

    if ($result_salary->num_rows > 0) {
        // Output employee details
        $row_emp = $result_emp->fetch_assoc();
        echo "<h1>Salary Statement for Employee No: " . $emp_no . "</h1>";
        echo "<p>Name: " . $row_emp['emp_name'] . "</p>";
        echo "<p>Address: " . $row_emp['address'] . "</p>";
        echo "<p>Phone: " . $row_emp['phone'] . "</p>";
        echo "<p>Department: " . $row_emp['dept_name'] . " (" . $row_emp['location'] . ")</p>";
        echo "<hr>";

        // Output salary details
        $row_salary = $result_salary->fetch_assoc();
        echo "<h2>Salary Breakdown</h2>";
        echo "<p>Basic: $" . $row_salary['Basic'] . "</p>";
        echo "<p>HR: $" . $row_salary['HR'] . "</p>";
        echo "<p>TA: $" . $row_salary['TA'] . "</p>";
        echo "<p>DA: $" . $row_salary['DA'] . "</p>";
        
        // Calculate total salary
        $total_salary = $row_salary['Basic'] + $row_salary['HR'] + $row_salary['TA'] + $row_salary['DA'];
        echo "<h3>Total Salary: $" . $total_salary . "</h3>";
    } else {
        echo "<p>No salary details found for employee no: " . $emp_no . "</p>";
    }
} else {
    echo "<p>No employee found with employee no: " . $emp_no . "</p>";
}

$conn->close();
?>
