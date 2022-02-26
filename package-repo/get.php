<?php

# Get query from URL
$query = $_GET['pkg'];

# Search if a file exists in the folder with the name of the package
# And return the path to the file as a JSON object
if (file_exists("./$query")) {
    echo json_encode(array("path" => "./$query"));
} else {
    echo json_encode(array("error" => "Package not found"));
}

?>