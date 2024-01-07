<?php
session_start();

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST['name'])) {
        $_SESSION['name'] = $_POST['name'];
        $_SESSION['class'] = $_POST['class'];
        $_SESSION['address'] = $_POST['address'];
    } else {
        $marks = array($_POST['phy'], $_POST['bio'], $_POST['chem'], $_POST['maths'], $_POST['marathi'], $_POST['english']);
        $total = array_sum($marks);
        $percentage = $total / 6;

        echo "Name: " . $_SESSION['name'] . "<br>";
        echo "Class: " . $_SESSION['class'] . "<br>";
        echo "Marks: Phy - " . $marks[0] . ", Bio - " . $marks[1] . ", Chem - " . $marks[2] . ", Maths - " . $marks[3] . ", Marathi - " . $marks[4] . ", English - " . $marks[5] . "<br>";
        echo "Total: " . $total . "<br>";
        echo "Percentage: " . number_format($percentage, 2) . "%";
    }
} else {
?>

<form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
    <label for="name">Name:</label><br>
    <input type="text" id="name" name="name"><br>
    <label for="class">Class:</label><br>
    <input type="text" id="class" name="class"><br>
    <label for="address">Address:</label><br>
    <input type="text" id="address" name="address"><br>
    <input type="submit">
</form>

<?php
}
?>

<?php
if (isset($_SESSION['name'])) {
?>

<form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
    <label for="phy">Phy:</label><br>
    <input type="number" id="phy" name="phy"><br>
    <label for="bio">Bio:</label><br>
    <input type="number" id="bio" name="bio"><br>
    <label for="chem">Chem:</label><br>
    <input type="number" id="chem" name="chem"><br>
    <label for="maths">Maths:</label><br>
    <input type="number" id="maths" name="maths"><br>
    <label for="marathi">Marathi:</label><br>
    <input type="number" id="marathi" name="marathi"><br>
    <label for="english">English:</label><br>
    <input type="number" id="english" name="english"><br>
    <input type="submit">
</form>

<?php
}
?>
