// first create a SQL Table and then Use the Php Code

<!-- index.php  -->

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Movie Details by Actor</title>
    <script>
        function getMoviesByActor() {
            var actorName = document.getElementById("actor").value;
            var xhr = new XMLHttpRequest();
            xhr.open("GET", "movies.php?actor=" + encodeURIComponent(actorName), true);
            xhr.onreadystatechange = function() {
                if (xhr.readyState == 4 && xhr.status == 200) {
                    document.getElementById("result").innerHTML = xhr.responseText;
                }
            };
            xhr.send();
        }
    </script>
</head>
<body>
    <h1>Find Movies by Actor</h1>
    <select id="actor">
        <option value="Leonardo DiCaprio">Leonardo DiCaprio</option>
        <option value="Christian Bale">Christian Bale</option>
        <option value="Matthew McConaughey">Matthew McConaughey</option>
    </select>
    <button onclick="getMoviesByActor()">Get Movies</button>
    <div id="result"></div>
</body>
</html>


<!-- movies.php  -->

<?php
// Database connection
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "your_database_name"; // Replace with your database name

$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Get actor name from query string
$actorName = $conn->real_escape_string($_GET['actor']);

// SQL query to get movies by actor
$sql = "SELECT MOVIE.mname, MOVIE.release_yr 
        FROM MOVIE
        JOIN MOVIE_ACTOR ON MOVIE.mno = MOVIE_ACTOR.mno
        JOIN ACTOR ON ACTOR.ano = MOVIE_ACTOR.ano
        WHERE ACTOR.aname = '$actorName'";

$result = $conn->query($sql);

if ($result->num_rows > 0) {
    // Output data of each row
    echo "<table border='1'><tr><th>Movie Name</th><th>Release Year</th></tr>";
    while($row = $result->fetch_assoc()) {
        echo "<tr><td>" . $row["mname"]. "</td><td>" . $row["release_yr"]. "</td></tr>";
    }
    echo "</table>";
} else {
    echo "0 results";
}

$conn->close();
?>
