<html>
<head></head>
<body>
    <h1>Email Validation</h1>
    <form action="" method="post">
        Enter your email address: 
        <input type="text" name="email"><br>
        <input type="submit" name="check" value="Check">
    </form>

    <?php
    if(isset($_POST['check'])){
        $email = $_POST['email'];

        if (preg_match('^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$^', $email)) {
            echo "Valid Email Address";
        } else {
            echo "Invalid Email Address";
        }
    }
    ?>
</body>
</html>
    