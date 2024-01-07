<html>
    <body>
        <form method="post" action="">
            Enter teacher Name : 
            <input type="text" name="tname"><br><br>
            <input type="submit" name="submit" value="Run">
        </form>
    </body>
    <?php
    if(isset($_POST['submit'])){
        $conn = mysqli_connect('localhost', 'root', '', 'school') or die("Connection was unsuccessful");

        $tname = $_POST['tname']; // teacher name 
        $sql = "SELECT s.Sname, st.subject FROM student s, teacher t, stud_tea st WHERE s.SNo = st.Sno AND t.Tno = st.Tno AND t.Tname = '$tname'";
        $result = mysqli_query($conn, $sql) or die("Query was unsuccessful");

        if(mysqli_num_rows($result) > 0){
            echo "<table border='1'>";
            echo "<tr><th>Student Name</th><th>Subject Name</th></tr>";

            while($row = mysqli_fetch_assoc($result)){
                echo "<tr><td>" . $row['Sname'] . "</td><td>" . $row['subject'] . "</td></tr>";
            }
            echo "</table>";
        }
        else{
            echo "No records found.";
        }
        mysqli_close($conn);
    }
    ?>
</html>
