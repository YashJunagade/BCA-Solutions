<!-- Write a PHP program to create a simple distance calculator that can accept distance in meters from user. 
Convert it into centimeter or kilometer according to user preference. (use radio buttons and Self Processing form) -->

<html>
    <body>
        <h2>Convert Meter into Centimeter or Kilometer : </h2>
        <form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
        Enter Distance(meter) : 
        <input type="text" name="meter"><br> 
        Convert Into : 
        <input type="radio" name="convert" value="centimeter">Centimeter
        <input type="radio" name="convert" value="kilometer">Kilometer<br> <br> 
        <input type="submit" name="submit" value="Convert">
    </body>

    <?php

        if(isset($_POST['submit'])){
            $meters = $_POST['meter'];
            $convert = $_POST['convert'];

            if($convert == "centimeter"){
                $centimeter = $meters * 100;
                echo "<br><br>$meters is equal to $centimeter <br>";
            }
            if($convert == "kilometer"){
                $kilometer = $meters / 1000;
                echo "<br><br>$meters is equal to $kilometer <br>";
            }
        }
    
    ?>
</html>