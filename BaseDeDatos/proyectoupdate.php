<?php
include 'proyectodb.php';

if (isset($_GET['isbn'])) {
    $isbn = $_GET['isbn'];
    $result = $conn->query("SELECT * FROM libros WHERE isbn = $isbn");
    $row = $result->fetch_assoc();
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $titulo = $_POST['titulo'];
    $autor = $_POST['autor'];
    $editorial = $_POST['editorial'];
    $cantidad = $_POST['cantidad'];
    $id_biblioteca = $_POST['id_biblioteca'];

    $sql = "UPDATE libros SET 
            titulo='$titulo', 
            autor='$autor', 
            editorial='$editorial', 
            cantidad='$cantidad', 
            id_biblioteca='$id_biblioteca' 
            WHERE isbn=$isbn";

    if ($conn->query($sql) === TRUE) {
        echo "Libro actualizado exitosamente.";
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }

    header("Location: index.php");
    exit();
}
?>

<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Actualizar Libro</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <h1>Actualizar Libro</h1>
    <form action="update.php?isbn=<?php echo $isbn; ?>" method="POST" id="formUpdate">
        <label for="titulo">Título:</label>
        <input type="text" name="titulo" value="<?php echo $row['titulo']; ?>" required>
        <br>
        <label for="autor">Autor:</label>
        <input type="text" name="autor" value="<?php echo $row['autor']; ?>" required>
        <br>
        <label for="editorial">Editorial:</label>
        <input type="text" name="editorial" value="<?php echo $row['editorial']; ?>" required>
        <br>
        <label for="cantidad">Cantidad:</label>
        <input type="number" name="cantidad" value="<?php echo $row['cantidad']; ?>" required>
        <br>
        <label for="id_biblioteca">Biblioteca:</label>
        <select name="id_biblioteca" required>
            <?php
            $bibliotecas = $conn->query("SELECT id_biblioteca, nombre FROM biblioteca");
            while ($biblio = $bibliotecas->fetch_assoc()) {
                $selected = ($biblio['id_biblioteca'] == $row['id_biblioteca']) ? 'selected' : '';
                echo "<option value='" . $biblio['id_biblioteca'] . "' $selected>" . $biblio['nombre'] . "</option>";
            }
            ?>
        </select>
        <br>
        <input type="submit" value="Actualizar Libro">
    </form>
</body>
</html>
