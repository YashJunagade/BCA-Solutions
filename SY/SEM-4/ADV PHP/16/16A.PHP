<!--Write a PHP program to accept two string from user and check whether entered strings are matching or not.(use sticky form concept)-->

<html>
    <body>
        <form action="<?php $_SERVER['PHP_SELF']; ?>" method="POST">
        First String : <input type="text" name="str1" value="<?php if(isset($_POST['str1'])) echo $_POST['str1']; ?>"><br>
        Second String : <input type="text" name="str2" value="<?php if(isset($_POST['str2'])) echo $_POST['str2']; ?>"><br><br>
        <input type="submit" name="submit" value="Check">
        </form>
    </body>
</html>


<?php

if(isset($_POST['submit'])){
    $str1 = $_POST['str1'];
    $str2 = $_POST['str2'];

    if($str1 === $str2){
        echo "Strings are matching";
    }else{
        echo "Strings are not matching";
    }
}

?>