

<?php
$data = ["VarServo1"=>0, "VarServo2"=>0, "UIDactif"=>""];

if (file_exists("data.json")) {
    $data = json_decode(file_get_contents("data.json"), true);
}

if (isset($_GET["VarServo1"])) $data["VarServo1"] = $_GET["VarServo1"];
if (isset($_GET["VarServo2"]))  $data["VarServo2"]  = $_GET["VarServo2"];
if (isset($_GET["UIDactif"]))  $data["UIDactif"]  = $_GET["UIDactif"];

file_put_contents("data.json", json_encode($data));
?>