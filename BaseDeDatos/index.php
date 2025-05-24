<?php
include 'db.php';
 
// Leer datos de la tabla autobus para mostrar
$result = $conn->query("SELECT * FROM autobus");
 
?>
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Gestión de Autobuses - Zaachila Yoo</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <h1>CRUD Autobuses - Zaachila Yoo</h1>
 
    <!-- Formulario para insertar o actualizar autobuses -->
    <form id="formInsert" action="insert.php" method="POST">
        <h2>Agregar Autobús</h2>
        
        <label for="id_autobus">id_autobus:</label>
        <input type="number" name="id_autobus" required>
        <br>


        <label for="placa">placa:</label>
        <input type="text" name="placa" required>
        <br>
        <label for="modelo">modelo:</label>
        <input type="text" name="modelo" required>
        <br>
        <label for="capacidad">capacidad:</label>
        <input type="number" name="capacidad" required>
        <br>
        <input type="submit" value="Agregar Autobús">
    </form>
 
    <hr>
 
    <!-- Mostrar autobuses -->
    <h2>Lista de Autobuses</h2>
    <table border="1">
        <tr>
            <th>ID</th>
            <th>Placa</th>
            <th>Modelo</th>
            <th>Capacidad</th>
            <th>Acciones</th>
        </tr>
        <?php while($row = $result->fetch_assoc()): ?>
        <tr>
            <td><?php echo $row['id_autobus']; ?></td>
            <td><?php echo $row['placa']; ?></td>
            <td><?php echo $row['modelo']; ?></td>
            <td><?php echo $row['capacidad']; ?></td>
            <td>
                <!-- Botón para editar -->
                <a href="update.php?id=<?php echo $row['id_autobus']; ?>">Editar</a>
                <!-- Botón para eliminar -->
                <a href="delete.php?id=<?php echo $row['id_autobus']; ?>">Eliminar</a>
            </td>
        </tr>
        <?php endwhile; ?>
    </table>
 
    <script src="script.js"></script>
</body>
</html>