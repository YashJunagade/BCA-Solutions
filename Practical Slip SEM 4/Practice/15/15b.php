<html>
	<head>
		<script type="text/javascript">
			function display(){
				name = f1.cn.value;
				let xhr = new XMLHttpRequest();
			
				xhr.onreadystatechange = function(){
					if(xhr.readyState == 4 && xhr.status == 200){
						document.getElementById("ans").innerHTML = xhr.responseText;
					}
				}
				
				xhr.open("GET", "hint.php?name=" + name, true);
				xhr.send();
			}
		</script>
	</head>
	<body>	
		<h3>Enter City details</h3>
		<form name="f1">
			Enter City : 
			<input type="text" name="cn" onkeyup="display()">
		</form>
		<div id="ans"></div>
	</body>
</html>