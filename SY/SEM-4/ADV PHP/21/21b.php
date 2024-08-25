<!-- student.php  -->

<?php
// Interface for defining student actions
interface StudentInterface {
    public function acceptStudentInfo();
    public function displayStudentInfo();
}

// Student class
class Student implements StudentInterface {
    protected $rollNo;
    protected $name;
    protected $prnNumber;

    public function __construct($rollNo, $name, $prnNumber) {
        $this->rollNo = $rollNo;
        $this->name = $name;
        $this->prnNumber = $prnNumber;
    }

    public function acceptStudentInfo() {
        // Collect student information from form submission
        $this->rollNo = $_POST['rollNo'] ?? '';
        $this->name = $_POST['name'] ?? '';
        $this->prnNumber = $_POST['prnNumber'] ?? '';
    }

    public function displayStudentInfo() {
        echo "Roll No: {$this->rollNo}<br>";
        echo "Name: {$this->name}<br>";
        echo "PRN Number: {$this->prnNumber}<br>";
    }
}

// Marks class extending Student
class Marks extends Student {
    protected $m_php;
    protected $m_os;
    protected $m_cpp;
    protected $m_networking;

    public function __construct($rollNo, $name, $prnNumber, $m_php, $m_os, $m_cpp, $m_networking) {
        parent::__construct($rollNo, $name, $prnNumber);
        $this->m_php = $m_php;
        $this->m_os = $m_os;
        $this->m_cpp = $m_cpp;
        $this->m_networking = $m_networking;
    }

    public function acceptStudentInfo() {
        parent::acceptStudentInfo();
        $this->m_php = $_POST['m_php'] ?? 0;
        $this->m_os = $_POST['m_os'] ?? 0;
        $this->m_cpp = $_POST['m_cpp'] ?? 0;
        $this->m_networking = $_POST['m_networking'] ?? 0;
    }

    public function displayStudentInfo() {
        parent::displayStudentInfo();
        echo "PHP Marks: {$this->m_php}<br>";
        echo "OS Marks: {$this->m_os}<br>";
        echo "C++ Marks: {$this->m_cpp}<br>";
        echo "Networking Marks: {$this->m_networking}<br>";
    }
}

// Result class extending Marks
class Result extends Marks {
    private $totalMarks;
    private $percentage;
    private $grade;

    public function __construct($rollNo, $name, $prnNumber, $m_php, $m_os, $m_cpp, $m_networking) {
        parent::__construct($rollNo, $name, $prnNumber, $m_php, $m_os, $m_cpp, $m_networking);
        $this->calculateResult();
    }

    private function calculateResult() {
        $this->totalMarks = $this->m_php + $this->m_os + $this->m_cpp + $this->m_networking;
        $this->percentage = ($this->totalMarks / 400) * 100;
        $this->grade = $this->getGrade();
    }

    private function getGrade() {
        if ($this->percentage >= 90) return 'A';
        if ($this->percentage >= 75) return 'B';
        if ($this->percentage >= 50) return 'C';
        return 'D';
    }

    public function displayStudentInfo() {
        parent::displayStudentInfo();
        echo "Total Marks: {$this->totalMarks}<br>";
        echo "Percentage: {$this->percentage}%<br>";
        echo "Grade: {$this->grade}<br>";
    }
}
?>


<!-- index.php  -->

<html>
<body>
    <h2>Student Result System</h2>

    <?php
    require 'Student.php';

    $action = $_POST['action'] ?? '';

    if ($action === 'accept') {
        // Create an instance of Result class
        $result = new Result(
            $_POST['rollNo'],
            $_POST['name'],
            $_POST['prnNumber'],
            $_POST['m_php'],
            $_POST['m_os'],
            $_POST['m_cpp'],
            $_POST['m_networking']
        );
    }
    ?>

    <form method="post">
        <input type="hidden" name="action" value="accept">
        <label for="rollNo">Roll No:</label>
        <input type="text" id="rollNo" name="rollNo" required><br>

        <label for="name">Name:</label>
        <input type="text" id="name" name="name" required><br>

        <label for="prnNumber">PRN Number:</label>
        <input type="text" id="prnNumber" name="prnNumber" required><br>

        <label for="m_php">PHP Marks:</label>
        <input type="number" id="m_php" name="m_php" required><br>

        <label for="m_os">OS Marks:</label>
        <input type="number" id="m_os" name="m_os" required><br>

        <label for="m_cpp">C++ Marks:</label>
        <input type="number" id="m_cpp" name="m_cpp" required><br>

        <label for="m_networking">Networking Marks:</label>
        <input type="number" id="m_networking" name="m_networking" required><br>

        <button type="submit">Submit</button>
    </form>

    <?php
    if ($action === 'accept') {
        echo "<h3>Student Information and Result:</h3>";
        $result->displayStudentInfo();
    }
    ?>
</body>
</html>
