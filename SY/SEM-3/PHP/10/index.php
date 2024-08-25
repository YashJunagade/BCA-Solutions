<!DOCTYPE html>
<html>
    <body>
        <form method="post" action="">
            Choose from the following : <br><br>
            1] to build a master table <br>
            2] to sort all entries <br>
            3] to search an entry <br>
            4] Display salary <br><br>
            Enter your choice :<br>
            <input type="number" name="choice"><br><br>
            Enter Name To Search :<br>
            <input type="text" name="sName"><br><br>
            <input type="submit" name="submit" value="run">
        </form>

        <?php 
        class Employee {
            public $code, $name, $designation;

            function __construct($c, $n, $d) {
                $this->code = $c;
                $this->name = $n;
                $this->designation = $d;
            }
            function getName(){
                return $this->name;
            }
        }

        class EmpAcc extends Employee {
            public $ano, $jdate;

            function __construct($c, $n, $d, $no, $jdate) {
                parent::__construct($c, $n, $d);
                $this->ano = $no;
                $this->jdate = $jdate;
            }
        }

        class EmpSal extends EmpAcc {
            public $bPay, $earn, $deduct, $total;

            function __construct($c, $n, $d, $no, $jdate, $bPay, $earn, $deduct) {
                parent::__construct($c, $n, $d, $no, $jdate);
                $this->bPay = $bPay;
                $this->earn = $earn;
                $this->deduct = $deduct;
                $this->total = $this->bPay + $this->earn - $this->deduct;
            }
        }

        // Create some sample employees
        $emp = array(
            new EmpSal('100', 'Loka', 'Manager', '12345', '2023-01-15', 50000, 7000, 3000),
            new EmpSal('101', 'Myra', 'Engineer', '23451', '2023-02-10', 45000, 6000, 2500)
        );

        function table($emp){
            echo "<table border='1'>";
            echo "<tr><th>Code</th><th>Name</th><th>Designation</th><th>Account No</th><th>Join Date</th><th>Basic Pay</th><th>Earning</th><th>Deduction</th></tr>";
            foreach ($emp as $employee) {
                echo "<tr>";
                echo "<td>".$employee->code."</td>";
                echo "<td>".$employee->name."</td>";
                echo "<td>".$employee->designation."</td>";
                echo "<td>".$employee->ano."</td>";
                echo "<td>".$employee->jdate."</td>";
                echo "<td>".$employee->bPay."</td>";
                echo "<td>".$employee->earn."</td>";
                echo "<td>".$employee->deduct."</td>";
                echo "</tr>";
            }
            echo "</table>";
        }

        function sortCode($a, $b){
            return strcmp($a->code, $b->code);
        }

        if (isset($_POST['submit'])) {
            $choice = $_POST['choice'];

            switch ($choice) {
                case 1:
                    table($emp);
                    break;
                case 2:
                    usort($emp, "sortCode");
                    table($emp);
                    break;
                case 3:
                    if(isset($_POST['sName'])){
                        $ename = $_POST['sName'];
                        $found = false;
                        foreach ($emp as $employee) {
                            $temp = $employee->getName();
                            if ($temp === $ename) {
                                echo "$temp is found in records";
                                $found = true;
                                break;
                            }
                        }
                        if (!$found) {
                            echo "$ename not found in records";
                        }
                    }
                    break;
                case 4:
                    foreach($emp as $employee){
                        echo "Employee Name : $employee->name" . "<br>";
                        echo "Employee salary : $employee->total" . "<br>";
                    }
                    break;
                default:
                    echo "Invalid choice";
            }
        }
        ?>
    </body>
</html>
