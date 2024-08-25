<!-- Create a form to accept Employee detail and display it in next page. (Use sticky form concept). -->

<!DOCTYPE html>
<html>
<head>
    <title>Employee Details Form</title>
</head>
<body>
    <form method="post" action="display.php">
        Enter Employee Id : <input type="text" name="eid" 
        value="<?php if(isset($_POST['eid'])) echo $_POST['eid']; ?>"><br><br>
        Enter Employee Name : <input type="text" name="ename" 
        value="<?php if(isset($_POST['ename'])) echo $_POST['ename']; ?>"><br><br>
        Enter Employee Salary : <input type="text" name="esalary" 
        value="<?php if(isset($_POST['esalary'])) echo $_POST['esalary']; ?>"><br><br>
        <input type="submit" name="submit" value="Submit">
    </form>
</body>
</html>
