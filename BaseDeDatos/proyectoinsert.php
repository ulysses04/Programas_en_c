<?php
include 'proyectodb.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $isbn = $_POST['isbn'];
    $titulo = $_POST['titulo'];
    $autor = $_POST['autor'];
    $editorial = $_POST['editorial'];
    $cantidad = $_POST['cantidad'];
    $id_biblioteca = $_POST['id_biblioteca'];

    $sql = "INSERT INTO libros (isbn, titulo, autor, editorial, cantidad, id_biblioteca) 
            VALUES ('$isbn', '$titulo', '$autor', '$editorial', '$cantidad', '$id_biblioteca')";

    if ($conn->query($sql) === TRUE) {
        echo "Nuevo libro agregado exitosamente.";
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }

    header("Location: index.php");
    exit();
}
?>
