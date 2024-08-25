<!-- Write a PHP Script to demonstrate the concept of Introspection for examining object. 
(Using any 3 predefined functions). -->

<?php

class Student{
    public $rollNo, $name;
    function setData(){
        $this->rollNo = 46;
        $this->name = "Yash";
    }
    function display(){
        echo "Roll No : ".$this->rollNo . "<br>";
        echo "Name : ".$this->name;
    }
}

$s1 = new Student();

echo "Class Exits : " . class_exists("Student")  . "<br>";
echo "Class Methods : " ;
print_r (get_class_methods("Student")) . "<br>";
echo "<br>Object Class : " . get_class($s1) . "<br>";

?>