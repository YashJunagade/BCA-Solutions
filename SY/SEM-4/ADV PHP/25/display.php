<?php 

$conn = mysqli_connect("localhost", "root", "", "test") or die("Connection failed");
if(isset($_POST['submit']) && $_POST['option'] == "create"){
    $sql = "CREATE TABLE TEACHER(TID INT(10), TNAME VARCHAR(20), ADDRESS VARCHAR(20), SUBJECT VARCHAR(20))";
    if(mysqli_query($conn, $sql)){
        echo "table Created Successfully";
    }else{
        echo "Failed to create table : ".mysqli_error($conn);
    }
}

if(isset($_POST['submit']) && $_POST['option'] == "insert"){
    $sql = "INSERT INTO TEACHER VALUES(1, 'Yash', 'Nashik', 'BCA')";
    if(mysqli_query($conn, $sql)){
        echo "Record inserted successfully";
    }else{
        echo "Failed to insert record : ".mysqli_error($conn);
    }
}

if(isset($_POST['submit']) && $_POST['option'] == "update"){
    $sql = "UPDATE TEACHER SET TNAME = 'Yash' WHERE TID = 1";
    if(mysqli_query($conn, $sql)){
        echo "Record updated successfully";
    }else{
        echo "Failed to update record : ".mysqli_error($conn);
    }
}

if(isset($_POST['submit']) && $_POST['option'] == "display"){
    $sql = "SELECT * FROM TEACHER";
    $result = mysqli_query($conn, $sql) or die("Query Failed");

    echo "Displaying All Data From Teacher Table : <br>";
    if(mysqli_num_rows($result) > 0){
        while($row = mysqli_fetch_assoc($result)){
            echo "TID : ".$row['TID'].", TNAME : ".$row['TNAME'].", ADDRESS : ".$row['ADDRESS'].", SUBJECT : ".$row['SUBJECT']."<br>";
        }
    }else{
        echo "No records found";
    }
}

?>