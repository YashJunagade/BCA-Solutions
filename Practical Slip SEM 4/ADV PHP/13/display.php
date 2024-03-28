<?php

if(isset($_POST['submit'])){

    $id = $_POST['eid'];
    $name = $_POST['ename'];
    $salary = $_POST['esalary'];

    echo "<h1>Details of Employee are : </h1><br>";
    echo "Id : ".$id."<br>";
    echo "Name : ".$name."<br>";
    echo "Salary : ".$salary."<br>";

}

?>