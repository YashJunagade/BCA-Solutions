<!-- index.html  -->

<html>
<head>
    <script>
        function search() {
            var query = document.getElementById('searchInput').value;
            var xhr = new XMLHttpRequest();
            xhr.open("POST", "search.php", true);
            xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
            xhr.onreadystatechange = function() {
                if (xhr.readyState === 4 && xhr.status === 200) {
                    document.getElementById('results').innerHTML = xhr.responseText;
                }
            };
            xhr.send("query=" + encodeURIComponent(query));
        }
    </script>
</head>
<body>
    <h1>Simple Search Engine</h1>
    <input type="text" id="searchInput" placeholder="Enter your search query">
    <button onclick="search()">Search</button>
    <div id="results"></div>
</body>
</html>


<!-- search.php  -->

<?php
// Define an array of sample search items
$items = array(
    "PHP Tutorial",
    "AJAX Programming",
    "Web Development",
    "JavaScript Guide",
    "HTML Basics",
    "CSS Tricks",
    "Database Management",
    "PHP and MySQL",
    "Front-end Technologies",
    "Back-end Programming"
);

// Get the search query from the POST request
$query = isset($_POST['query']) ? $_POST['query'] : '';

// Filter the items based on the query
$results = array_filter($items, function($item) use ($query) {
    return stripos($item, $query) !== false;
});

// Display results
if (!empty($results)) {
    echo "<ul>";
    foreach ($results as $result) {
        echo "<li>" . htmlspecialchars($result) . "</li>";
    }
    echo "</ul>";
} else {
    echo "No results found.";
}
?>
