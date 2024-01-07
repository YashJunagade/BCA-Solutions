<?php

	if(isset($_POST['submit'])){
		$inames = $_POST['iname'];
		$icodes = $_POST['icode'];
		$rates = $_POST['rate'];
		$units = $_POST['unit'];

		$iname = explode(" ", $inames);
		$icode = explode(" ", $icodes);
		$rate = explode(" ", $rates);
		$unit = explode(" ", $units);

		for($i=0; $i<count($unit); $i++){
			$total[$i] = $unit[$i] * $rate[$i];
		}
	
		echo "<table border='1'>";
		echo "<tr><th>Item Code</th>
			<th>Item Name</th>
			<th>Unit</th>
			<th>Rate</th>
			<th>Total</th></tr>";

		for($i=0; $i<count($icode); $i++){
			echo "<tr><td>$iname[$i]</td>
				<td>$icode[$i]</td>
				<td>$unit[$i]</td>
				<td>$rate[$i]</td>
				<td>$total[$i]</td></tr>";
		}

	}

?>