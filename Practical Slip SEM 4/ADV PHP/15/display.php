<?php
    if (isset($_POST['select'])) {
        $arr = $_POST['arr'];
        echo "<h3>Subjects selected are :</h3>";
        foreach ($arr as $a) {
            echo "$a, ";
        }
    } else {
        echo "<p>No subjects selected.</p>";
    }
    echo "<p><a href='15A.php'>Go Back</a></p>";
?>
