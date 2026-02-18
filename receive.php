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
$data = ["temp"=>0, "hum"=>0];

if (file_exists("data.json")) {
    $data = json_decode(file_get_contents("data.json"), true);
}

if (isset($_GET["temp"])) $data["temp"] = $_GET["temp"];
if (isset($_GET["hum"]))  $data["hum"]  = $_GET["hum"];

file_put_contents("data.json", json_encode($data));
?>