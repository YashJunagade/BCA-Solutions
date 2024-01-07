<html>
    <head></head>
    <body>
        <form method="post" action="">
            Enter the Large String :
            <input type="text" name="str1"><br><br>
            Enter the Small String :
            <input type="text" name="str2"><br><br>
            Enter String to Replace :
            <input type="text" name="str3" ><br><br>
            <input type="submit" name="submit" value="submit">
        </form>

        <?php 
        
        if(isset($_POST['submit'])){
            $str1 = $_POST['str1'];
            $str2 = $_POST['str2'];
            $str3 = $_POST['str3'];

            $first = strpos($str1, $str2);
            $last = strrpos($str1, $str2);
            $total = substr_count($str1, $str2);
            $replace = str_replace($str2, $str3, $str1);

            echo "first occurrences of string : $first <br>";
            echo "Last occurrences of string : $last <br>";
            echo "replace string : $replace";
        }

        ?>
    </body>
</html>