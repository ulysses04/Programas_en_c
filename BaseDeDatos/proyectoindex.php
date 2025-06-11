<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);
include 'proyectodb.php';

// Leer datos de la tabla libros para mostrar
$result = $conn->query("SELECT * FROM libros");
?>
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Gestión de Libros - Biblioteca</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <h1>CRUD Libros - Biblioteca</h1>

    <!-- Formulario para insertar libros -->
    <form id="formInsert" action="insert.php" method="POST">
        <h2>Agregar Libro</h2>

        <label for="isbn">ISBN:</label>
        <input type="number" name="isbn" required>
        <br>

        <label for="titulo">Título:</label>
        <input type="text" name="titulo" required>
        <br>

        <label for="autor">Autor:</label>
        <input type="text" name="autor" required>
        <br>

        <label for="editorial">Editorial:</label>
        <input type="text" name="editorial" required>
        <br>

        <label for="cantidad">Cantidad:</label>
        <input type="number" name="cantidad" required>
        <br>

        <label for="id_biblioteca">Biblioteca:</label>
        <select name="id_biblioteca" required>
            <?php
            // Cargar bibliotecas desde la base de datos
            $bibliotecas = $conn->query("SELECT id_biblioteca, nombre FROM biblioteca");
            while ($fila = $bibliotecas->fetch_assoc()) {
                echo "<option value='" . $fila["id_biblioteca"] . "'>" . $fila["nombre"] . "</option>";
            }
            ?>
        </select>
        <br>

        <input type="submit" value="Agregar Libro">
    </form>

    <hr>

    <!-- Mostrar libros -->
    <h2>Lista de Libros</h2>
    <table border="1">
        <tr>
            <th>ISBN</th>
            <th>Título</th>
            <th>Autor</th>
            <th>Editorial</th>
            <th>Cantidad</th>
            <th>ID Biblioteca</th>
            <th>Acciones</th>
        </tr>
        <?php while($row = $result->fetch_assoc()): ?>
        <tr>
            <td><?php echo $row['isbn']; ?></td>
            <td><?php echo $row['titulo']; ?></td>
            <td><?php echo $row['autor']; ?></td>
            <td><?php echo $row['editorial']; ?></td>
            <td><?php echo $row['cantidad']; ?></td>
            <td><?php echo $row['id_biblioteca']; ?></td>
            <td>
                <a href="update.php?isbn=<?php echo $row['isbn']; ?>">Editar</a>
                <a href="delete.php?isbn=<?php echo $row['isbn']; ?>">Eliminar</a>
            </td>
        </tr>
        <?php endwhile; ?>
    </table>

    <script src="script.js"></script>
</body>
</html>
