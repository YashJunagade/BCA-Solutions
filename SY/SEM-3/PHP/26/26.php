<!-- index.php  -->


<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "HospitalDB";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Get the hospital name from the request
$hosp_name = $_GET['hosp_name'];

// Fetch hospital and doctor details
$sql = "SELECT d.doc_name, d.address, d.city, d.area 
        FROM Doctor d
        JOIN Doctor_Hospital dh ON d.doc_no = dh.doc_no
        JOIN Hospital h ON dh.hosp_no = h.hosp_no
        WHERE h.hosp_name = ?";

$stmt = $conn->prepare($sql);
$stmt->bind_param("s", $hosp_name);
$stmt->execute();
$result = $stmt->get_result();

if ($result->num_rows > 0) {
    echo "<h1>Doctors Working/Visiting at " . htmlspecialchars($hosp_name) . "</h1>";
    echo "<table border='1'>
            <tr>
                <th>Doctor Name</th>
                <th>Address</th>
                <th>City</th>
                <th>Area</th>
            </tr>";
    
    // Output each doctor's information
    while ($row = $result->fetch_assoc()) {
        echo "<tr>
                <td>" . htmlspecialchars($row['doc_name']) . "</td>
                <td>" . htmlspecialchars($row['address']) . "</td>
                <td>" . htmlspecialchars($row['city']) . "</td>
                <td>" . htmlspecialchars($row['area']) . "</td>
              </tr>";
    }
    echo "</table>";
} else {
    echo "<p>No doctors found for the hospital: " . htmlspecialchars($hosp_name) . "</p>";
}

$stmt->close();
$conn->close();
?>
