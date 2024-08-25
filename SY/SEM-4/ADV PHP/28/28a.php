<!-- index.html  -->

<html>
<head>
    <script>
        function getGames() {
            var xhr = new XMLHttpRequest();
            xhr.open("GET", "games.php", true);
            xhr.onreadystatechange = function() {
                if (xhr.readyState === 4 && xhr.status === 200) {
                    document.getElementById('gamesList').innerHTML = xhr.responseText;
                }
            };
            xhr.send();
        }
    </script>
</head>
<body>
    <h1>Game List</h1>
    <button onclick="getGames()">OK</button>
    <div id="gamesList"></div>
</body>
</html>


<!-- games.php  -->
<?php
// Define an array of games
$games = array(
    "Chess",
    "Football",
    "Basketball",
    "Tennis",
    "Volleyball"
);

// Generate HTML for the list of games
echo "<ul>";
foreach ($games as $game) {
    echo "<li>$game</li>";
}
echo "</ul>";
?>
