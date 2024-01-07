<html>
    <head></head>
    <body>
        <form method="post" action="#">
            Enter Small String :
            <input type="text" name="str1"><br><br>
            Enter Large String :
            <input type="text" name="str2"><br><br>
            Enter string to replace :
            <input type="text" name="str3" ><br><br>
            Choose :
            <input type="radio" name="choice" value="1">Occurrence
            <input type="radio" name="choice" value="2">Replace
            <input type="radio" name="choice" value="3">Split <br><br>
            <input type="submit" name ="submit" value="submit">
        </form>

        <?php 
        
            if(isset($_POST['submit'])){
                $str1 = $_POST['str1'];
                $str2 = $_POST['str2'];
                $str3 = $_POST['str3'];
                $choice = $_POST['choice'];

                switch($choice){
                    case 1 : $first = strpos($str2, $str1);
                    if($first == 0){
                        echo "$str1 string appear at first of $str2 string";
                    }
                    else{
                        echo "String not appear at first";
                    }
                    break;
                    case 2 :
                        str_replace($str1, $str3,  $str2);
                        echo "Replace string : $str1";
                        break;
                    case 3 : 
                       $str = preg_split('/[\s]/', $str2);
                        echo "Words in Large string :<br>";
                        foreach($str as $words)
                        echo "$words <br>";
                        break;
                }
            }
        ?>
    </body>
</html>