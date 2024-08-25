<!-- index.php  -->

<?php
$c_name = $_POST['c_name'];
$query = "SELECT Student.* FROM Student s
        JOIN Stu_Comp sc ON s.sid  = sc.sid 
        JOIN Competition  c ON c.cno = sc.cno 
        WHERE c.cname = '$c_name' 
        AND sc.rank = 1";

$result = mysqli_query($conn, $query);
while($row = mysqli_fetch_assoc($result)) {
    echo "Student ID: " . $row['Stud_id'] . ", Name: " . $row['name'] . ", Class: " . $row['class'];
}
?>
