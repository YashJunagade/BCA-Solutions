


<!-- login.php  -->

<html>
    <body>
    <?php        
        if(isset($_POST['login'])){
            $user = $_POST['username'];
        
            echo "Welcome, $user";
            echo "<form method='post' action='display.php'>
                Name : <input type='text' name = 'name'><br>
                City : <input type='text' name='city'><br>
                Phone No : <input type='number' name='no'><br>
                <input type='submit' name ='submit' value='submit'>
                </form>";
        }else{
            echo "Invalide Login";
        }
            
    ?>
    </body>
</html>