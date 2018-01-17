<?php

// $remotexml = file_get_contents("https://wvde.state.wv.us/closings/rss/raleigh");
// $xml = simplexml_load_string($remotexml);
// if ($xml === false) {
//     echo "Failed loading XML: ";
//     foreach(libxml_get_errors() as $error) {
//         echo "<br>", $error->message;
//     }
// } else {
//     print_r($xml);
// }

// $xml->channel->
$remotestring = file_get_contents("https://wvde.state.wv.us/closings/xml/raleigh");
if (strpos($remotestring, 'closed') !== false) {
    echo 'closed';
}else if (strpos($remotestring, 'delay') !== false) {
    echo 'delay';
}else{
    echo "open";
}


?>