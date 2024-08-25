<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Movie Actor Database</title>
</head>
<body>
    <h2>Movie Actor Database</h2>

    <!-- Form for database operations -->
    <form id="dbForm" method="post">
        <input type="radio" id="accept" name="operation" value="accept" required>
        <label for="accept">Accept</label><br>
        <input type="radio" id="insert" name="operation" value="insert">
        <label for="insert">Insert</label><br>
        <input type="radio" id="update" name="operation" value="update">
        <label for="update">Update</label><br><br>

        <label for="actorName">Actor Name:</label>
        <input type="text" id="actorName" name="actorName" required><br><br>

        <button type="submit">Submit</button>
    </form>

    <div id="movieList"></div>

    <script>
        document.getElementById('dbForm').addEventListener('submit', function(event) {
            event.preventDefault(); // Prevent form from submitting normally

            var operation = document.querySelector('input[name="operation"]:checked').value;
            var actorName = document.getElementById('actorName').value;

            var xhr = new XMLHttpRequest();
            xhr.open('POST', '', true);
            xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');

            xhr.onreadystatechange = function() {
                if (xhr.readyState == 4 && xhr.status == 200) {
                    document.getElementById('movieList').innerHTML = xhr.responseText;
                }
            };

            xhr.send('operation=' + encodeURIComponent(operation) + '&actorName=' + encodeURIComponent(actorName));
        });
    </script>

    <?php
    // Database connection
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "movie_db";

    $conn = new mysqli($servername, $username, $password, $dbname);

    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        $operation = $_POST['operation'];
        $actorName = $_POST['actorName'];

        if ($operation === 'accept') {
            // Query to get movies for the actor
            $sql = "SELECT Movie.movie_name FROM Movie 
                    INNER JOIN ActorMovie ON Movie.movie_no = ActorMovie.movie_no 
                    INNER JOIN Actor ON Actor.actor_no = ActorMovie.actor_no 
                    WHERE Actor.name = ?";
            $stmt = $conn->prepare($sql);
            $stmt->bind_param("s", $actorName);
            $stmt->execute();
            $result = $stmt->get_result();

            if ($result->num_rows > 0) {
                echo "<h3>Movies with $actorName:</h3><ul>";
                while ($row = $result->fetch_assoc()) {
                    echo "<li>" . htmlspecialchars($row['movie_name']) . "</li>";
                }
                echo "</ul>";
            } else {
                echo "No movies found for actor $actorName.";
            }
            $stmt->close();
        }
        // Implement insert and update logic as needed here
    }

    $conn->close();
    ?>
</body>
</html>
