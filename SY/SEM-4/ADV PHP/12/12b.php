<!-- 
      contact.dat 
      
1,John Doe,123 Elm Street,555-1234
2,Jane Smith,456 Oak Avenue,555-5678
3,Bob Johnson,789 Pine Road,555-8765 

-->

<html>
<head>
    <title>Contact Viewer</title>
    <style>
        table { width: 100%; border-collapse: collapse; }
        th, td { border: 1px solid black; padding: 8px; text-align: left; }
    </style>
</head>
<body>
    <h2>Contact List</h2>
    <button onclick="loadContacts()">Print Contacts</button>
    <div id="contactTable"></div>

    <script>
        function loadContacts() {
            var xhr = new XMLHttpRequest();
            xhr.open('GET', 'contact.dat', true);
            xhr.onload = function() {
                if (xhr.status == 200) {
                    var rows = xhr.responseText.trim().split('\n');
                    var table = '<table><tr><th>Sr No</th><th>Name</th><th>Residence</th><th>Mobile</th></tr>';
                    
                    rows.forEach(function(row) {
                        var cells = row.split(',');
                        table += '<tr><td>' + cells[0] + '</td><td>' + cells[1] + '</td><td>' + cells[2] + '</td><td>' + cells[3] + '</td></tr>';
                    });

                    table += '</table>';
                    document.getElementById('contactTable').innerHTML = table;
                }
            };
            xhr.send();
        }
    </script>
</body>
</html>
