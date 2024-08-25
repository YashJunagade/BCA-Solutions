<?php
// Given URL
$url = "http://www.college.com/Science/CS.php";

// Parse the URL and get its components
$urlComponents = parse_url($url);

// Extract the scheme, host, and path
$scheme = isset($urlComponents['scheme']) ? $urlComponents['scheme'] : '';
$host = isset($urlComponents['host']) ? $urlComponents['host'] : '';
$path = isset($urlComponents['path']) ? $urlComponents['path'] : '';

// Set the response header to text/plain
header('Content-Type: text/plain');

// Output the components
echo "Scheme: " . $scheme . "\n";
echo "Host: " . $host . "\n";
echo "Path: " . $path . "\n";
?>
