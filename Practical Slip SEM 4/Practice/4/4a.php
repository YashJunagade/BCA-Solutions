<?php

class Employee{
	private $mid, $name, $dept, $salary;
	function __construct($id, $n, $d, $s){
		$this->mid = $id;
		$this->name = $n;
		$this->dept = $d;
		$this->salary = $s;
	}
	
	function display(){
		echo "Manager Id : " . $this->mid . "<br>";
		echo "Manager Name : " . $this->name . "<br>";
		echo "Department : " . $this->dept . "<br>";
		echo "Salary : " . $this->salary . "<br>";
	}

	function getSalary(){
		return $this->salary;
	}
}

class Manager extends Employee{
	private $bonus;
	function __construct($id, $n, $d, $s, $b){
		parent::__construct($id, $n, $d, $s);
		$this->bonus = $b;
	}
	
	function totalSalary(){
		return $this->bonus + Employee::getSalary()	;
	}

	function display(){
		Employee::display();
		echo "Bonus : " . $this->bonus . "<br>";
	}
}

$obj1 = new Manager("1", "Yash", "IT", "1000", "100");
$obj2 = new Manager("2", "Tony", "IT", "99999", "99");
$obj3 = new Manager("3", "Master", "IT", "888", "88");

$msObj = $obj1;

if($msObj->totalSalary() < $obj2->totalSalary()){
	$msObj = $obj2;
}

if($msObj->totalSalary() < $obj3->totalSalary()){
	$msObj = $obj3;
}

echo "Manager having maximum Salary : " . "<br>";
$msObj->display();
?>