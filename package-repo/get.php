<?php

# Get query from URL
$query = $_GET['pkg'];

# Search if a file contains $query if so, return the file
$files = glob('*');
foreach ($files as $file) {
    if (strpos($file, $query) !== false) {
        echo $file;
        exit;
    }
}

?>