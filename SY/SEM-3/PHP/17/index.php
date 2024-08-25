<!-- index.php  -->

<html>
    <head></head>
    <body>
        <form method="post" action="">
            <h2>Course Registration</h2>
            Student Name :
            <input type="text" name="name" ><br>
            Mobile Number :
            <input type="number" name="number" required pattern ="[0-9]{10}"><br>
            Course Name :
            <input type="text" name="cname"><br>
            <input type="submit" name="regi" value="Register">
        </form>

        <?php
        
        if(isset($_POST['regi'])){
            $name = $_POST['name'];
            $number = $_POST['number'];
            $course = $_POST['cname'];

            if(!preg_match('/^[a-zA-Z\s]+$/', $name)){
                echo "Invalid Name Enter Valid Name ";
            }else{
                $registerNumber = "REG" . rand(1000, 9999);

                echo "<h2>Registration Details </h2>";
                echo "Student Name : ". $name . "<br>";
                echo "Course :" . $course . "<br>";
                echo "Mobile Number :" . $number . "<br>";
                echo "Registration Number :" . $registerNumber;
            }
        }
        
        ?>
    </body>
</html>