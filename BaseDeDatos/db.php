<?php
$servername = "localhost";  
$username = "root";        //usuario de la base de datos
$password = "12345";   //contraseña de la base de datos
$dbname = "zaachila_yoo"; //nombre de la base de datos

//crear la conexion
$conn= new mysqli($servername, $username, $password, $dbname); 

//berificar la conexion
if ($conn->connect_error){
    die("Connection failed: ".$conn->connect_error);
}
?>