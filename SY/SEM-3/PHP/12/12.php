

<!-- 12.php  -->

<!DOCTYPE html>
<html>
<body>

<?php
class Account {
    public $acc_no;
    public $acc_name;

    public function __construct($acc_name, $acc_no) {
        $this->acc_name = $acc_name;
        $this->acc_no = $acc_no;
    }

    public function intro() {
        echo "The Account name is {$this->acc_name} and Account No is {$this->acc_no}.";
    }
}

class Saving_acc extends Account {
    public $balance;
    public $min_amount;

    public function __construct($acc_name, $acc_no, $balance, $min_amount) {
        parent::__construct($acc_name, $acc_no);
        $this->balance = $balance;
        $this->min_amount = $min_amount;
    }

    public function intro() {
        echo "<table border='2'>";
        echo "<tr><td>Account Name</td><td>Account No</td><td>Balance</td><td>Min Balance</td></tr>";
        echo "<tr><td>{$this->acc_name}</td>";
        echo "<td>{$this->acc_no}</td>";
        echo "<td>{$this->balance}</td>";
        echo "<td>{$this->min_amount}</td></tr>";
    }
}

class Current_acc extends Account {
    public $balance;
    public $min_amount;

    public function __construct($acc_name, $acc_no, $balance, $min_amount) {
        parent::__construct($acc_name, $acc_no);
        $this->balance = $balance;
        $this->min_amount = $min_amount;
    }

    public function intro() {
        echo "<tr><td>{$this->acc_name}</td>";
        echo "<td>{$this->acc_no}</td>";
        echo "<td>{$this->balance}</td>";
        echo "<td>{$this->min_amount}</td></tr>";
    }
}

echo "</table>";

$saving_acc = new Saving_acc("Ravindra", 1111, 5000, 1000);
$saving_acc->intro();

$current_acc = new Current_acc("Kiran", 2222, 100000, 1000);
$current_acc->intro();

?>

</body>
</html>
