<html>
<head></head>
<body>  
    <form method="post" action="">
        Enter the Radius of Cylinder:
        <input type="number" name="r"><br><br>
        Enter the Height of Cylinder:
        <input type="number" name="h"><br><br>
        <input type="submit" name="submit" value="run">
    </form>
    
<?php
if(isset($_POST['submit'])){
    $r = $_POST['r'];
    $h = $_POST['h'];

    define('PI', 3.14);

    interface cal{
        function area($r, $h);
        function vol($r, $h);
    }

    class cylinder{
        function area($r, $h){
            $area = 2 * PI * $r * ($r + $h);
            echo "Area of cylinder is: $area <br>";
        }
        function vol($r, $h){
            $vol = PI * $r * $r * $h;
            echo "Volume of cylinder is: $vol";
        }
    }

    $c = new cylinder;
    $c->area($r, $h);
    $c->vol($r, $h);
}
?>
</body>
</html>
