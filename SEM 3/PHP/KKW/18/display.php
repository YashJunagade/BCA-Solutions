<?php
session_start();

if (isset($_POST['submit'])) {
    $name = $_POST["name"];
    $city = $_POST['city'];
    $no = $_POST['no'];
    
    // Store the submitted data in session variables
    $_SESSION['name'] = $name;
    $_SESSION['city'] = $city;
    $_SESSION['no'] = $no;
}

// Set a session timeout
$session_timeout = 10; 
$current_time = time();

if (isset($_SESSION['timeout']) && $current_time > $_SESSION['timeout']) {
    // Session has expired, unset session variables
    session_unset();
    session_destroy();
    echo "Session expired. Please submit the form again.";
} else {
    // Extend the session timeout
    $_SESSION['timeout'] = $current_time + $session_timeout;
    
    echo "<h2>User Details:</h2>";
    echo "Name: " . $_SESSION['name'] . "<br>";
    echo "City: " . $_SESSION['city'] . "<br>";
    echo "Phone No: " . $_SESSION['no'];
}
?>
