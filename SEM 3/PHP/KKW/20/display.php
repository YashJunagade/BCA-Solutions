<?php
    if(isset($_POST['submit'])){
        setcookie('str', $_POST['str']);
        setcookie('fontF', $_POST['fontF']);
        setcookie('fSize', $_POST['fSize']);
        setcookie('fColor', $_POST['fColor']);
        setcookie('bgColor', $_POST['bgC']);

        echo "<h2>You Select :</h2>";
        echo "Font Family :" .$_POST['fontF']. "<br>";
        echo "Font Size :" .$_POST['fSize']. "<br>";
        echo "Font Color :" .$_POST['fColor']. "<br>";
        echo "Background Color :" .$_POST['bgC']. "<br>";
        echo "<a href = 'view.php'> Show Output </a>";
    }
?>