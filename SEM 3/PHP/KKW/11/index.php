<!DOCTYPE html>
<html>
    <body>
        <form action="" method="post">
            <h3>Square:</h3>
            Enter the side of Square:
            <input type="number" name="s"><br>
            <input type="submit" name="submit1" value="Calculate">
            <h3>Rectangle:</h3>
            Enter the width of Rectangle:
            <input type="number" name="w"><br>
            Enter the height of Rectangle:
            <input type="number" name="h"><br>
            <input type="submit" name="submit2" value="Calculate">
            <h3>Circle:</h3>
            Enter the radius of Circle:
            <input type="number" name="r"><br>
            <input type="submit" name="submit3" value="Calculate">
        </form>

        <?php
        interface AreaFun {
            function area($a, $b);
        }

        class Rectangle implements AreaFun {
            function area($w, $h) {
                $area = $w * $h;
                echo "Area Of Rectangle: " . $area . "<br>";
            }
        }

        class Square extends Rectangle {
            function area($s, $s1) {
                $area = $s * $s1;
                echo "Area Of Square: " . $area . "<br>";
            }
        }

        class Circle implements AreaFun {
            function area($r, $r1) {
                $area = 3.14 * $r * $r1;
                echo "Area Of Circle: " . $area . "<br>";
            }
        }
        
        if(isset($_POST['submit1'])){
            $side = $_POST["s"];
            $obj = new Square();
            $obj->area($side, $side);
        }
        if(isset($_POST['submit2'])){
            $w = $_POST['w'];
            $h = $_POST['h'];
            $rect = new rectangle();
            $rect->area($w,$h);
        }
        if(isset($_POST['submit3'])){
            $r = $_POST["r"];
            $cir = new Circle();
            $cir->area($r, $r);
        }
        ?>
    </body>
</html>
