<html>
    <head></head>
    <body>
        Choose from the Following : <br><br>
        1. Sort the array by values (changing the keys) in ascending, descending order.<br>
        2. Also sort the array by values without changing the keys.<br>
        3. Filter the odd elements from an array.<br>
        4. Merge the given arrays.<br>
        5. Find the Union, intersection& set difference of two arrays.<br><br>

        <form method="post" action="">
            Enter Your Choice :
            <input type="number" name="choice"><br><br>
            <input type="submit" name="Run" value="run">
        </form>

        <?php 
        
            if(isset($_POST['Run'])){
                $choice = $_POST['choice'];

                $array1 = array('a' => 1, 'b' => 4, 'c' => 5, 'd' => 8);
                $array2 = array('e' => 2, 'f' => 5, 'g' => 6, 'h' => 7);
                switch($choice){
                    case 1 :
                        asort($array1);
                        echo "Ascending order of array :";
                        print_r($array1);
                        arsort($array1);
                        echo "<br>Descending order of array :";
                        print_r($array1);
                        break;
                    case 2 :
                        sort($array1);
                        echo "Sorted array without changing the keys :";
                        print_r($array1);
                        break;
                    case 3 :
                        function oddelement($num){
                            return ($num % 2 == 1);
                        }
                        echo "Filterd array :";
                        print_r(array_filter($array1,'oddelement'));
                        break;
                    case 4 :
                        echo "Merged Arrays : ";
                        print_r(array_merge($array1, $array2));
                        break;
                    case 5 :
                        echo "Union of array :";
                        print_r(array_merge($array1, $array2));
                        echo "<br>Intersection of array :";
                        print_r(array_intersect($array1, $array2));
                        echo "<br>Difference of two array :";
                        print_r(array_diff($array1, $array2));
                        break;
                    default :
                    echo "Invalide Choice";                   
                }
            }
        ?>
    </body>
</html>