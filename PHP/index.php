<!--Autor: Martin Chlebovec alias: martinius96-->
<!--Podpora: https://www.paypal.me/Chlebovec-->
<!--Osobný web: https://arduino.php5.sk-->
<!--Email kontakt: martinius96@gmail.com-->
<!--Facebook ID kontakt: 100001242570317-->
<!--Používajte v súhade s licenciou!-->  
<!DOCTYPE html>
<html>  
<head>
  <link rel="stylesheet" href="style.css">
  </head>
  <body>
  <div style="padding:0 16px;">
  <?php
  if(isset($_POST["rele1"])) {
    if(file_get_contents("rele1.txt") === "1") {
      file_put_contents("rele1.txt", 0);
    }
    else { 
      file_put_contents("rele1.txt", 1);
    }
  }
   ?>
   <form method="post" id="rele1f" action="<?php echo $_SERVER['PHP_SELF']; ?>" >
   <input type="hidden" name="rele1" value="yes">
	<h1>Ovládanie relé v domácnosti</h1>
  <fieldset>
		<legend>Obývačka - prepäťovka</legend>
		<label onClick="document.getElementById('rele1f').submit();">
			<input name="releon" type="checkbox" <?php if(file_get_contents("rele1.txt") === "1") echo "checked"; ?>>
			<div>
				<span class="yes">ZAP</span>                                              
				<span class="no">VYP</span>
			</div>         
    
			<a class="slider"></a>
		</label>	
	</fieldset>
  
   </form>
  
   
    </div>

</body>
</html>
