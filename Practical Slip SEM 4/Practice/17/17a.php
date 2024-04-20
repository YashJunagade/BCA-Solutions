<?php

	echo "<table border=1>";
	echo "<tr><th>PHP SELF</th>
		<th>SERVER NAME</th>
		<th>SERVER ADDRESS</th>
		<th>SERVER PORT</th>
		<th>REMOTE ADDRESS</th>
		<th>REMOTE PORT</th></tr>";

	echo "<tr><td>". $_SERVER['PHP_SELF'] . "</td>" .
		"<td>". $_SERVER['SERVER_NAME'] . "</td>" . 
		"<td>". $_SERVER['SERVER_ADDR'] . "</td>" . 
		"<td>". $_SERVER['SERVER_PORT'] . "</td>" .  
		"<td>". $_SERVER['REMOTE_ADDR'] . "</td>" . 
		"<td>". $_SERVER['REMOTE_PORT'] . "</td></tr>";
	echo "</table>"
?>