<?php
include 'proyectodb.php';

if (isset($_GET['isbn'])){
    $id = $_GET['isbn'];
    $sql = "DELETE FROM libro WHERE isbn = $isbn";

    if($conn->query($sql) === TRUE){
        echo "libro eliminado exitosamente.";
    }else {
        echo "error:" .$sql . "<br>" . $conn->error;
    }
    header("location: index.php");
    exit();
}
?>