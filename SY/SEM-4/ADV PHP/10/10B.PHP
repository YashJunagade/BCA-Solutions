<!-- Write a PHP script to perform the following stack related operations- insert, delete and display.
(Use concept of self processing form) -->


<html>
<head>
    <title>Stack Operations</title>
</head>
<body>
    <h1>Stack Operations</h1>
    <form method="post" action = "<?php echo $_SERVER['PHP_SELF']; ?>">
        Enter number : <input type="number" name="num"><br><br>
        <input type="submit" name="insert" value="insert">
        <input type="submit" name="delete" value="delete">
        <input type="submit" name="display" value="display">  
    </form>
</body>
</html>
    
<?php
session_start();
if(!isset($_SESSION['stack'])){
    $_SESSION['stack'] = array();
}

function insert($num) {
    array_push($_SESSION['stack'], $num);
}

function delete() {
    array_pop($_SESSION['stack']);
}

function display(){
    if(empty($_SESSION['stack'])){
        echo "Stack is empty.";
    } else {
        echo "Stack : ";
        foreach($_SESSION['stack'] as $value){
            echo $value . " ";
        }
    }
}

if(isset($_POST['insert'])){
    $num = $_POST['num'];
    insert($num);
} else if(isset($_POST['delete'])){
    delete();
} else if(isset($_POST['display'])){
    display();
}
?>
