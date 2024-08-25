
<!-- clear-session.php  -->

<?php
session_start();
session_unset();
session_destroy();
header("Location: page1.php");
exit();
