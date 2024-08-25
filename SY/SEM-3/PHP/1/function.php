

<!-- function.php  -->

<?php 

function strVovels($str){
    $str = strtolower($str);
    $vowels = array('a'=>0, 'e'=>0, 'i'=>0, 'o'=>0, 'u'=>0);
    for($i=0; $i<strlen($str); $i++){
        $char = $str[$i];
        if(array_key_exists($char, $vowels)){
           $vowels[$char]++;
        }
    }
    echo "Occurrences of each vovels :<br>";
    foreach($vowels as $vowel => $count){
        echo "$vowel : $count <br>";
    }
}

function palindrome($str){
    $str = strtolower($str);
    if($str == strrev($str)){
        echo "$str is Palindrome";
    }else{
        echo "$str is not Palindrome";
    }
}


    $str = $_POST['str'];   
    $choice = $_POST['choice'];

    if($choice == 'vowels'){
        strVovels($str);
    }
    else{
        palindrome($str);

}


?>