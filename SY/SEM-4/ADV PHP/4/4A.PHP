<!-- Define a class Employee having private members id, name, department, salary. Define parameterized constructors. 
Create a subclass called "Manager" with private member bonus. 
Create 3 objects of the Manager class and display the details of the manager having the maximum total salary (salary + bonus). -->

<?php

class Employee{
    private $mid, $mname, $dept, $salary;
    function __construct($id, $name, $dept, $salary){
        $this->mid = $id;
        $this->mname = $name;
        $this->dept = $dept;
        $this->salary = $salary;
    }

    function displayEmp(){
        echo "Manager ID: $this->mid <br>";
        echo "Manager Name: $this->mname <br>";
        echo "Manager Department: $this->dept <br>";
        echo "Manager Salary: $this->salary <br>";
    }

    function getSalary(){
        return $this->salary;
    }
}

class Manager extends Employee{
    private $bonus;
    function __construct($id, $name, $dept, $salary, $bonus){
        parent::__construct($id, $name, $dept, $salary);
        $this->bonus = $bonus;
    }

    function display(){
        parent::displayEmp();
        $total = parent::getSalary() + $this->bonus;
        echo "Manager Bonus: $this->bonus <br>";
        echo "Manager Total Salary: $total <br>";
    }

    function total(){
        $total = parent::getSalary() + $this->bonus;
        return $total;
    }
}

$obj1 = new Manager(1, "Yash", "CSE", 10000, 5000);
$obj2 = new Manager(2, "Deva", "CSE", 12000, 6000);
$obj3 = new Manager(3, "Sharper", "CSE", 15000, 7000);

echo "Details of managers : ". "<br>";
$obj1->display();
$obj2->display();
$obj3->display();

$maxSalaryManager = $obj1;

if($obj2->total() > $maxSalaryManager->total()){
    $maxSalaryManager = $obj2;
}
if($obj3->total() > $maxSalaryManager->total()){
    $maxSalaryManager = $obj3;
}

echo "Details of manager with maximum total salary : ". "<br>";
$maxSalaryManager->display();

?>