<html>
<head>
    <title>Login Check</title>
</head>
<body>
    <h2>Login</h2>
    <form id="loginForm">
        <label for="username">Username:</label>
        <input type="text" id="username" name="username" required><br>
        <label for="password">Password:</label>
        <input type="password" id="password" name="password" required><br>
        <button type="button" onclick="checkLogin()">Login</button>
    </form>
    <div id="result"></div>

    <script>
        function checkLogin() {
            var username = document.getElementById('username').value;
            var password = document.getElementById('password').value;

            var xhr = new XMLHttpRequest();
            xhr.open('POST', '', true);
            xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
            
            xhr.onreadystatechange = function() {
                if (xhr.readyState == 4 && xhr.status == 200) {
                    document.getElementById('result').innerText = xhr.responseText;
                }
            };

            xhr.send('username=' + encodeURIComponent(username) + '&password=' + encodeURIComponent(password));
        }
    </script>

    <?php
    // Database connection
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "user_db";

    $conn = new mysqli($servername, $username, $password, $dbname);

    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        $user = $_POST['username'];
        $pass = $_POST['password'];

        // Check if user exists
        $stmt = $conn->prepare("SELECT * FROM users WHERE username = ? AND password = ?");
        $stmt->bind_param("ss", $user, $pass);
        $stmt->execute();
        $result = $stmt->get_result();

        if ($result->num_rows > 0) {
            echo "Valid credentials!";
        } else {
            echo "Invalid credentials!";
        }
        $stmt->close();
    }

    $conn->close();
    ?>
</body>
</html>
