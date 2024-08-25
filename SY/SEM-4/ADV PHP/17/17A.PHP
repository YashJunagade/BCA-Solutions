<!-- Write a PHP Script to display Server information in table format (Use $_SERVER). -->


<html>
    <body>
        <table border="1">
            <tr>
                <th>PHP SELF</th>
                <th>SERVER NAME</th>
                <th>SERVER ADDRESS</th>
                <th>SERVER PORT</th>
                <th>REMOTE ADDRESS</th>
                <th>REMOTE PORT</th>
            </tr>
            <?php
        
        echo "<tr>";
        echo "<td>" . $_SERVER['PHP_SELF'] . "</td>";
        echo "<td>" . $_SERVER['SERVER_NAME'] . "</td>";
        echo "<td>" . $_SERVER['SERVER_ADDR'] . "</td>";
        echo "<td>" . $_SERVER['SERVER_PORT'] . "</td>";
        echo "<td>" . $_SERVER['REMOTE_ADDR'] . "</td>";
        echo "<td>" . $_SERVER['REMOTE_PORT'] . "</td>";
        echo "</tr>";
        
        // echo "</table>";
        ?>
        </table>
    </body>
</html>