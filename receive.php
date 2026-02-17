(Pour envoyer des données php de l'esp8266)
(Code pour envoyer (arduino code))

(
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("http://tonsite.com/iot/receive.php?temp=25&hum=60");
    http.GET();
    http.end();
  }
  delay(5000);
}
)



<?php
$data1 = $_GET["data1"];
$data2 = $_GET["data2"];

file_put_contents("data.txt", "$data1,$data2\n", FILE_APPEND);
echo "OK";
?>