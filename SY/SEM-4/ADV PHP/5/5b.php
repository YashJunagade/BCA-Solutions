<!-- index.html  -->

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Student Details</title>
</head>
<body>
    <h2>Select Standard to View Student Details</h2>
    <select id="standardSelect">
        <option value="">Select Standard</option>
        <option value="9th">9th</option>
        <option value="10th">10th</option>
    </select>

    <h3>Student Details:</h3>
    <div id="studentDetails"></div>

    <script>
        document.getElementById('standardSelect').addEventListener('change', function() {
            var standard = this.value;

            if (standard !== '') {
                var xhr = new XMLHttpRequest();
                xhr.open('POST', 'student.php', true);
                xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');

                xhr.onreadystatechange = function() {
                    if (xhr.readyState == 4 && xhr.status == 200) {
                        document.getElementById('studentDetails').innerHTML = xhr.responseText;
                    }
                };

                xhr.send('standard=' + encodeURIComponent(standard));
            } else {
                document.getElementById('studentDetails').innerHTML = '';
            }
        });
    </script>
</body>
</html>



<!-- student.php -->


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

if (isset($_POST['standard'])) {
    $standard = $_POST['standard'];

    $sql = "SELECT sno, sname, Marks, per FROM student WHERE standard = ?";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("s", $standard);
    $stmt->execute();
    $result = $stmt->get_result();

    if ($result->num_rows > 0) {
        while($row = $result->fetch_assoc()) {
            echo "Student No: " . $row["sno"]. " - Name: " . $row["sname"]. " - Marks: " . $row["Marks"]. " - Percentage: " . $row["per"]. "%<br>";
        }
    } else {
        echo "No students found in " . $standard;
    }

    $stmt->close();
}

$conn->close();
?>
