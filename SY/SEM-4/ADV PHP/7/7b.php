<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Project Student List</title>
    <style>
        body {
            font-family: Arial, sans-serif;
        }
        form {
            margin-bottom: 20px;
        }
        #studentList {
            margin-top: 20px;
        }
    </style>
</head>
<body>
    <h2>Find Students by Project Title</h2>
    <form id="projectForm">
        <label for="projectTitle">Project Title:</label>
        <input type="text" id="projectTitle" name="projectTitle" required>
        <button type="submit">Search</button>
    </form>

    <h3>Student List:</h3>
    <div id="studentList"></div>

    <script>
        document.getElementById('projectForm').addEventListener('submit', function(event) {
            event.preventDefault(); // Prevent the form from submitting normally

            var projectTitle = document.getElementById('projectTitle').value;

            var xhr = new XMLHttpRequest();
            xhr.open('POST', '', true);
            xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');

            xhr.onreadystatechange = function() {
                if (xhr.readyState == 4 && xhr.status == 200) {
                    document.getElementById('studentList').innerHTML = xhr.responseText;
                }
            };

            xhr.send('projectTitle=' + encodeURIComponent(projectTitle));
        });
    </script>

    <?php
    if ($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_POST['projectTitle'])) {
        $servername = "localhost";
        $username = "root";  // Replace with your database username
        $password = "";      // Replace with your database password
        $dbname = "your_database_name"; // Replace with your database name

        // Create connection
        $conn = new mysqli($servername, $username, $password, $dbname);

        // Check connection
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }

        $projectTitle = $_POST['projectTitle'];

        // Prepare the SQL query
        $sql = "SELECT Student.Name, Student.Class 
                FROM Student 
                INNER JOIN Project ON Student.P_Group_No = Project.P_Group_No 
                WHERE Project.Project_Title = ?";

        $stmt = $conn->prepare($sql);
        $stmt->bind_param("s", $projectTitle);
        $stmt->execute();
        $result = $stmt->get_result();

        if ($result->num_rows > 0) {
            echo "<ul>";
            while ($row = $result->fetch_assoc()) {
                echo "<li>Name: " . htmlspecialchars($row['Name']) . ", Class: " . htmlspecialchars($row['Class']) . "</li>";
            }
            echo "</ul>";
        } else {
            echo "No students found for the project titled '" . htmlspecialchars($projectTitle) . "'";
        }

        $stmt->close();
        $conn->close();
    }
    ?>
</body>
</html>
