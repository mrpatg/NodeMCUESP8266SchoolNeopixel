<?php
$remotexml = file_get_contents("https://wvde.state.wv.us/closings/xml/raleigh");
$xml = simplexml_load_string($remotexml);
if ($xml === false) {
    echo "Failed loading XML: ";
    foreach(libxml_get_errors() as $error) {
        echo "<br>", $error->message;
    }
} else {
    //print_r($xml);
}




foreach($xml->announcement AS $announcement){
    $date_effective = $announcement->date_effective;
    //echo $date_effective;
    $date = new DateTime($date_effective);
    $now = new DateTime();

    if($date < $now) {
        if($announcement->status == "1"){
            echo "delay";
        }elseif($announcement->status == "2"){
            echo "delay";
        }elseif($announcement->status == "3"){
            echo "early";
        }elseif($announcement->status == "4"){
            echo "closed";
        }elseif($announcement->status == "5"){
            echo "early";
        }elseif($announcement->status == "6"){
            echo "early";
        }elseif($announcement->status == "7"){
            echo "early";
        }elseif($announcement->status == "8"){
            echo "early";
        }elseif($announcement->status == "9"){
            echo "delay";
        }else{
            echo "open";
        }
    }
}