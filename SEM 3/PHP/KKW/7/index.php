<html>
    <head></head>
    <body>  
        Choose from the following operation : <br><br>
        1. Display the elements of an array along with the keys.<br>
        2. Display the size of an array<br>
        3. Delete an element from an array from the given index.<br>
        4. Reverse the order of each element’s key-value pair<br>
        5. Traverse the elements in an array in random order   <br><br>
        
        Enter the Number :
        <form action="" method="post">
            <input type="number" name="choice"><br><br>
            Enter Index to Delete :<br>
            <input type="number" name="index"><br><br>
            <input type="submit" name="run" value="run">
        </form>
            <?php
            
            if(isset($_POST['run'])){
                $choice = $_POST['choice'];

                $students = array(
                    "Student1" => "Yash",
                    "Student2" => "Tony",
                    "Student3" => "Master",
                    "Student4" => "chatur"
                );
                
                switch($choice){
                    case 1 :
                        echo "Display the array :<br>";
                        foreach($students as $student => $value){
                            echo "$student : $value <br>";
                        }
                        break;
                    case 2 :
                        echo "Size of associative array is :" . count($students);
                        break;
                    case 3 :
                        if(isset($_POST['index'])){
                            $index = $_POST['index'];
                            unset($students[$index]);
                            echo "index deleted<br>";
                        }
                        break;
                    case 4 :
                        $students = array_flip($students);
                        echo "Array after flipping the key-value element :<br>";
                        foreach($students as $student => $value){
                            echo "$student => $value<br>";
                        }
                        break;
                    case 5 :
                        shuffle($students);
                        print_r($students);
                        break;
                    default :
                    echo "Invalide Choice ";                        
                }
                
            }
        ?>
    </body>
</html>