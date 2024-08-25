<!-- 29.php  -->



<!-- Accept Actor Name And Display Movies  -->

 <?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "MovieDB";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

if (isset($_POST['actor_name'])) {
    $actor_name = $_POST['actor_name'];

    $sql = "SELECT m.movie_name 
            FROM Movie m
            JOIN Movie_Actor ma ON m.movie_no = ma.movie_no
            JOIN Actor a ON ma.actor_no = a.actor_no
            WHERE a.name = ?";
    
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("s", $actor_name);
    $stmt->execute();
    $result = $stmt->get_result();

    if ($result->num_rows > 0) {
        echo "<h2>Movies featuring " . htmlspecialchars($actor_name) . ":</h2><ul>";
        while ($row = $result->fetch_assoc()) {
            echo "<li>" . htmlspecialchars($row['movie_name']) . "</li>";
        }
        echo "</ul>";
    } else {
        echo "<p>No movies found for the actor: " . htmlspecialchars($actor_name) . "</p>";
    }

    $stmt->close();
}

$conn->close();
?>



<!-- Insert New Movies Information -->

<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "MovieDB";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

if (isset($_POST['movie_name']) && isset($_POST['release_year'])) {
    $movie_name = $_POST['movie_name'];
    $release_year = $_POST['release_year'];

    $sql = "INSERT INTO Movie (movie_name, release_year) VALUES (?, ?)";
    
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("si", $movie_name, $release_year);

    if ($stmt->execute()) {
        echo "<p>New movie '" . htmlspecialchars($movie_name) . "' added successfully.</p>";
    } else {
        echo "<p>Error: " . $stmt->error . "</p>";
    }

    $stmt->close();
}

$conn->close();
?>


<!-- Update the release year of movie  -->

<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "MovieDB";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

if (isset($_POST['movie_name']) && isset($_POST['new_release_year'])) {
    $movie_name = $_POST['movie_name'];
    $new_release_year = $_POST['new_release_year'];

    $sql = "UPDATE Movie SET release_year = ? WHERE movie_name = ?";
    
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("is", $new_release_year, $movie_name);

    if ($stmt->execute()) {
        if ($stmt->affected_rows > 0) {
            echo "<p>Release year for '" . htmlspecialchars($movie_name) . "' updated to " . htmlspecialchars($new_release_year) . ".</p>";
        } else {
            echo "<p>No movie found with the name '" . htmlspecialchars($movie_name) . "'</p>";
        }
    } else {
        echo "<p>Error: " . $stmt->error . "</p>";
    }

    $stmt->close();
}

$conn->close();
?>
