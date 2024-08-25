<!-- books.xml  -->

<?xml version="1.0"?>
<books>
    <book>
        <name>Book One</name>
        <author>Author A</author>
        <year>2001</year>
        <price>29.99</price>
    </book>
    <book>
        <name>Book Two</name>
        <author>Author B</author>
        <year>2005</year>
        <price>19.99</price>
    </book>
    <book>
        <name>Book Three</name>
        <author>Author C</author>
        <year>2010</year>
        <price>39.99</price>
    </book>
    <!-- Add more books as needed -->
</books>


<!-- index.php  -->


<html>
<body>
    <h2>Book Details</h2>
    <label for="bookSelect">Select a book:</label>
    <select id="bookSelect" onchange="getBookDetails()">
        <option value="">--Select a book--</option>
        <option value="Book One">Book One</option>
        <option value="Book Two">Book Two</option>
        <option value="Book Three">Book Three</option>
        <!-- Add more options as needed -->
    </select>

    <div id="bookDetails"></div>

    <script>
        function getBookDetails() {
            var bookName = document.getElementById('bookSelect').value;

            if (bookName === "") {
                document.getElementById('bookDetails').innerHTML = '';
                return;
            }

            var xhr = new XMLHttpRequest();
            xhr.open('GET', '', true); // Use the current PHP file for AJAX request
            xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
            
            xhr.onload = function() {
                if (xhr.status == 200) {
                    var parser = new DOMParser();
                    var xmlDoc = parser.parseFromString(xhr.responseText, "text/xml");
                    var books = xmlDoc.getElementsByTagName('book');
                    var details = '';
                    
                    for (var i = 0; i < books.length; i++) {
                        var name = books[i].getElementsByTagName('name')[0].textContent;
                        if (name === bookName) {
                            var author = books[i].getElementsByTagName('author')[0].textContent;
                            var year = books[i].getElementsByTagName('year')[0].textContent;
                            var price = books[i].getElementsByTagName('price')[0].textContent;
                            details = '<h3>' + name + '</h3><p>Author: ' + author + '<br>Year: ' + year + '<br>Price: $' + price + '</p>';
                            break;
                        }
                    }
                    document.getElementById('bookDetails').innerHTML = details;
                }
            };

            xhr.send('action=getBookDetails');
        }
    </script>

    <?php
    if ($_SERVER['REQUEST_METHOD'] === 'GET' && isset($_GET['action']) && $_GET['action'] === 'getBookDetails') {
        header('Content-Type: application/xml');
        echo file_get_contents('books.xml');
    }
    ?>
</body>
</html>
