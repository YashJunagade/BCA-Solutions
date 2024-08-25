<!-- index.php  -->

<?php
// Initialize session and variables
session_start();
$username = "";
$password = "";
$error = "";
$attempt = 0;

// Check if the form is submitted
if (isset($_POST["submit"])) {
  // Get the input values
  $username = $_POST["username"];
  $password = $_POST["password"];

  // Validate the username and password
  if ($username == "admin" && $password == "admin") {
        header("Location:display.php");
  } else {
    // Incorrect credentials, increment the attempt counter
    $attempt = $_SESSION["attempt"] ?? 0;
    $attempt++;
    $_SESSION["attempt"] = $attempt;

    // Check if the user has exceeded the maximum attempts
    if ($attempt >= 3) {
      // Display error message and exit
      echo "<p style='color:red'>You have entered wrong username or password 3 times. Access denied.</p>";
      exit();
    } else {
      // Display error message and remaining attempts
      $error = "Wrong username or password. You have " . (3 - $attempt) . " attempts left.";
    }
  }
}
?>

<!DOCTYPE html>
<html>
<head>
  <title>Login Form</title>
</head>
<body>
  <h1>Login Form</h1>
  <form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
    <label for="username">Username:</label>
    <input type="text" id="username" name="username" value="<?php echo $username; ?>"><br>
    <label for="password">Password:</label>
    <input type="password" id="password" name="password" value="<?php echo $password; ?>"><br>
    <input type="submit" name="submit" value="Login">
  </form>
  <p style="color:red"><?php echo $error; ?></p>
</body>
</html>
