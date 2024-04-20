<html>
	<head>
		<script type="text/javascript">
			function display(){
				name = f1.na.value;
				age = f1.age.value;
				nationality = f1.n.value;

				let xhr = new XMLHttpRequest();

				xhr.onreadystatechange = function(){
					if(xhr.readyState == 4 && xhr.status == 200){
						document.getElementById('ans').innerHTML = xhr.responseText;	
					}
				}
				
				xhr.open("GET", "check.php?name=" + name + "&age=" + age + "&nationality=" + nationality, true);
				xhr.send();
			}
		</script>
	</head>
	<body>
		<h2>Enter Voters Details</h2>
		<form name="f1">
			Enter Name :
			<input type="text" name="na" onkeyup="display()"><br><br>
			Enter Age:
			<input type="number" name="age" onkeyup="display()"><br><br>
			Enter Nationality:
			<input type="text" name="n" onkeyup="display()"><br><br>
		</form>
		<div id="ans"></div>
	</body>
</html>