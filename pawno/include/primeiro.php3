<html>
<head><title>Aprendendo PHP</title></head>
<body>

<?php
if ($texto != "") 
  echo "Voc� digitou \"$texto\"<br><br>";
?>

<form method=post action="<? echo $PATH_INFO; ?>">
<input type="text" name="texto" value="" size=10>
<br>
<input type="submit" name="sub" value="Enviar!">
</form>

</body>
</html>
