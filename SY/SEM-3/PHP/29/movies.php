<!-- movies.php  -->

<?php
$operation = $_POST['operation'];

if ($operation === 'display_movies') {
    include 'display_movies.php';
} elseif ($operation === 'insert_movie') {
    include 'insert_movie.php';
} elseif ($operation === 'update_movie') {
    include 'update_movie.php';
} else {
    echo "Invalid operation selected.";
}
?>
