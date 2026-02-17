(Pour lire les données depuis php sur l'esp8266)
(Pour lire (arduino Code))
(
http.begin("http://tonsite.com/iot/get.php");
http.GET();
String cmd = http.getString();
)

<?php
echo "ON"; // ou depuis une base
?>