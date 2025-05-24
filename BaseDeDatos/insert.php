<?php
include 'db.php';

if($_SERVER["REQUEST_METHOD"]== "POST"){
    $id_autobus=$_POST['id_autobus'];
    $placa=$_POST['placa'];
    $modelo=$_POST['modelo'];
    $capacidad=$_POST['capacidad'];

    $sql = "INSERT INTO autobus (id_autobus,placa, modelo, capacidad) VALUES ('$id_autobus','$placa','$modelo','$capacidad')";

    if($conn->query($sql) === TRUE){
        echo "Nuevo autobus agregado exitosamente."; 
    }else {
        echo "error:" . $sql . "<br>" . $conn->error;

    }
    header ("location: index.php");
    exit();
}
?>