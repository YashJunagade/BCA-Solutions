<html>
    <body>

<?php

if(isset($_POST['convert'])){
    $dist = $_POST['dist'];
    $unit = $_POST['unit'];

    if($unit === 'kilo'){
        $mile = $dist / 1.609;
        echo "$dist kilometer is equal to the $mile miles. <br><br>";
    }else{
        $kilo = $dist * 1.609;
        echo "$dist mile is equal to the $kilo kilometers. <br><br>";
    }
    
}
?>
<a href="distance.html">Go back</a>
    </body>
</html>