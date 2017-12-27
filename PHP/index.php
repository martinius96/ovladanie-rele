<!--Autor: Martin Chlebovec alias: martinius96-->
<!--Podpora: https://www.paypal.me/Chlebovec-->
<!--Osobný web: https://arduino.php5.sk-->
<!--Email kontakt: martinius96@gmail.com-->
<!--Facebook kontakt: 100001242570317-->
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
  if(isset($_POST["rele2"])) {
    if(file_get_contents("rele2.txt") === "1") {
      file_put_contents("rele2.txt", 0);
    }
    else { 
      file_put_contents("rele2.txt", 1);
    }
  }
    if(isset($_POST["rele3"])) {
    if(file_get_contents("rele3.txt") === "1") {
      file_put_contents("rele3.txt", 0);
    }
    else { 
      file_put_contents("rele3.txt", 1);
    }
  }
    if(isset($_POST["rele4"])) {
    if(file_get_contents("rele4.txt") === "1") {
      file_put_contents("rele4.txt", 0);
    }
    else { 
      file_put_contents("rele4.txt", 1);
    }
  }
    if(isset($_POST["rele5"])) {
    if(file_get_contents("rele5.txt") === "1") {
      file_put_contents("rele5.txt", 0);
    }
    else { 
      file_put_contents("rele5.txt", 1);
    }
  }
    if(isset($_POST["rele6"])) {
    if(file_get_contents("rele6.txt") === "1") {
      file_put_contents("rele6.txt", 0);
    }
    else { 
      file_put_contents("rele6.txt", 1);
    }
  }
    if(isset($_POST["rele7"])) {
    if(file_get_contents("rele7.txt") === "1") {
      file_put_contents("rele7.txt", 0);
    }
    else { 
      file_put_contents("rele7.txt", 1);
    }
  }
    if(isset($_POST["rele8"])) {
    if(file_get_contents("rele8.txt") === "1") {
      file_put_contents("rele8.txt", 0);
    }
    else { 
      file_put_contents("rele8.txt", 1);
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
    <form method="post" id="rele2f" action="<?php echo $_SERVER['PHP_SELF']; ?>" >
    <input type="hidden" name="rele2" value="yes">

  <fieldset>
		<legend>Akvárium - ohrev</legend>
		<label onClick="document.getElementById('rele2f').submit();">
			<input name="releon" type="checkbox" <?php if(file_get_contents("rele2.txt") === "1") echo "checked"; ?>>
			<div>
				<span class="yes">ZAP</span>                                              
				<span class="no">VYP</span>
			</div>         
    
			<a class="slider"></a>
		</label>	
	</fieldset>
  
   </form>
   <form method="post" id="rele3f" action="<?php echo $_SERVER['PHP_SELF']; ?>" >
    <input type="hidden" name="rele3" value="yes">

  <fieldset>
		<legend>Akvárium - svetlo</legend>
		<label onClick="document.getElementById('rele3f').submit();">
			<input name="releon" type="checkbox" <?php if(file_get_contents("rele3.txt") === "1") echo "checked"; ?>>
			<div>
				<span class="yes">ZAP</span>                                              
				<span class="no">VYP</span>
			</div>         
    
			<a class="slider"></a>
		</label>	
	</fieldset>
  
   </form>
      <form method="post" id="rele4f" action="<?php echo $_SERVER['PHP_SELF']; ?>" >
    <input type="hidden" name="rele4" value="yes">

  <fieldset>
		<legend>El. zámok dverí</legend>
		<label onClick="document.getElementById('rele4f').submit();">
			<input name="releon" type="checkbox" <?php if(file_get_contents("rele4.txt") === "1") echo "checked"; ?>>
			<div>
				<span class="yes">ZAP</span>                                              
				<span class="no">VYP</span>
			</div>         
    
			<a class="slider"></a>
		</label>	
	</fieldset>
  
   </form>
    <form method="post" id="rele5f" action="<?php echo $_SERVER['PHP_SELF']; ?>" >
    <input type="hidden" name="rele5" value="yes">

  <fieldset>
		<legend>Led pásik - garáž</legend>
		<label onClick="document.getElementById('rele5f').submit();">
			<input name="releon" type="checkbox" <?php if(file_get_contents("rele5.txt") === "1") echo "checked"; ?>>
			<div>
				<span class="yes">ZAP</span>                                              
				<span class="no">VYP</span>
			</div>         
    
			<a class="slider"></a>
		</label>	
	</fieldset>
  
   </form>
    <form method="post" id="rele6f" action="<?php echo $_SERVER['PHP_SELF']; ?>" >
    <input type="hidden" name="rele6" value="yes">

  <fieldset>
		<legend>Napájanie - meteostanica</legend>
		<label onClick="document.getElementById('rele6f').submit();">
			<input name="releon" type="checkbox" <?php if(file_get_contents("rele6.txt") === "1") echo "checked"; ?>>
			<div>
				<span class="yes">ZAP</span>                                              
				<span class="no">VYP</span>
			</div>         
    
			<a class="slider"></a>
		</label>	
	</fieldset>
  
   </form>
   <form method="post" id="rele7f" action="<?php echo $_SERVER['PHP_SELF']; ?>" >
    <input type="hidden" name="rele7" value="yes">

  <fieldset>
		<legend>Napájanie 433Mhz prijímač</legend>
		<label onClick="document.getElementById('rele7f').submit();">
			<input name="releon" type="checkbox" <?php if(file_get_contents("rele7.txt") === "1") echo "checked"; ?>>
			<div>
				<span class="yes">ZAP</span>                                              
				<span class="no">VYP</span>
			</div>         
    
			<a class="slider"></a>
		</label>	
	</fieldset>
  
   </form>
   <form method="post" id="rele8f" action="<?php echo $_SERVER['PHP_SELF']; ?>" >
    <input type="hidden" name="rele8" value="yes">

  <fieldset>
		<legend>Žiarovky - lúster</legend>
		<label onClick="document.getElementById('rele8f').submit();">
			<input name="releon" type="checkbox" <?php if(file_get_contents("rele8.txt") === "1") echo "checked"; ?>>
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
