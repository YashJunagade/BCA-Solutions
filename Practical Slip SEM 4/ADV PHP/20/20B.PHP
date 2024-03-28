<!-- Write a PHP script for the following: Design a form to accept a number from the user. 
Perform the operations and show the results. (Use the concept of self processing page.).
1) Fibonacci Series. 
2) To find sum of the digits of that number.  -->

<html>
    <body>
        <form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
            Enter number : <input type="number" name="num"><br><br>
            Choose Operations : 
            <input type="radio" name="op" value="fibo">Find Fibonacci Series
            <input type="radio" name="op" value="sum">Sum of digits<br><br>
            <input type="submit" name="calculate" value="Calculate">
        </form>
    </body>
</html>

<?php

function sum($num){
    $sum = 0; $digit = 0;
    while($num > 0){
        $digit = $num % 10;
        $sum += $digit;
        $num = $num / 10;
    }

    echo "Sum of digits : " .$sum;
}

function fibo($num){
    $a = 0; $b = 1; $c = 0;
    echo "Fibonacci Series : ";
    for($i = 1; $i <= $num; $i++){
        echo $a . " ";
        $c = $a + $b;
        $a = $b;
        $b = $c;
    }
}

if(isset($_POST['calculate'])){
    $num = $_POST['num'];
    $choice = $_POST['op'];

    if($choice == "sum"){
        sum($num);
    }else if($choice == "fibo"){
        fibo($num);
    }
}

?>