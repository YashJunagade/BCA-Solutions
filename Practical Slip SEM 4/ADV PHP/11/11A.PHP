<!-- Write a PHP program to create class circle having radius data member and two member functions 
find_circumference() and find_area(). Display area and circumference depending on user's preference. -->


<html>
    <body>
        <form method="post">
            Enter Radius : <input type="number" name="r"><br><br>
            Choose : 
            <input type="radio" name="choice" value="area">Find Area()
            <input type="radio" name="choice" value="circumference">FInd Circumference()<br><br>
            <input type="submit" name="calculate">
        </form>
    </body>
</html>

<?php 

class Circle{
    public $radius;
    function __construct($radius){
        $this->radius = $radius;
    }

    function find_area(){
        $area = M_PI * $this->radius * $this->radius;
        echo "Area : $area";
    }

    function find_circumference(){
        $circumference = 2 * M_PI * $this->radius;
        echo "Circumference : $circumference";
    }
}

if(isset($_POST['calculate'])){
    $r = $_POST['r'];
    $circle = new Circle($r);
    $choice = $_POST['choice'];

    if($choice == "area"){
        $circle->find_area();
    }else if($choice == "circumference"){
        $circle->find_circumference();
    }
}
?>