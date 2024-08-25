<!-- index.php  -->

<htlml>
    <head></head>
    <body>
        <form method="post" action="#">
            Enter the First String :
            <input type="text" name="str1"><br><br>
            Enter the Second String :
            <input type="text" name="str2"><br><br>
            Choose the method to compare string :
            <input type="radio" name="choice" value="operator"> Using ==
            <input type="radio" name="choice" value="function"> Using strcmp function <br><br>
            Enter the Position from you want to reverse the String :
            <input type="number" name="pos"><br><br>
            <input type="submit" name="submit" value="Manipulate">
        </form>

        <?php
    if(isset($_POST['submit'])) {
        $str1 = $_POST['str1'];
        $str2 = $_POST['str2'];
        $pos = $_POST['pos'];
        $choice = $_POST['choice'];

        if ($choice == 'operator') {
            if ($str1 == $str2) {
                echo "$str1 is equal to $str2 <br>";
            } else {
                echo "$str1 is not equal to $str2 <br>";
            }
        } else {
            if (strcmp($str1, $str2) === 0) {
                echo "$str1 is equal to $str2 <br>";
            } else {
                echo "$str1 is not equal to $str2 <br>";
            }
        }

        // Concatenate the two strings
        $appendStr = $str1 . $str2;
        echo "Concatenated String: $appendStr <br>";

        $reverseStr = '';
            for($i=0; $i <= $pos; $i++){
                $reverseStr .= $str1[$i];
            }
            for($i = $pos; $i>=0; $i--)
            $reverseStr .= $str1[$i];

            echo "Reverse String : $reverseStr";
        }

        ?>

    </body>
</html>