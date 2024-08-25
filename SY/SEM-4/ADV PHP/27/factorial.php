<?php
if(isset($_GET['n'])){
    $num = (int)$_GET['n'];
    $result = "";
    $ans = 1;
    for($i = 1; $i <= $num; $i++){
        $result .= $i . " * ";
        $ans *= $i;
    }

    if($result == ""){
        echo "Wrong Input";
    }else{
        echo rtrim($result, " * ") . " = " . $ans;
    }
}
?>
