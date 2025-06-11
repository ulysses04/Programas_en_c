create database bibliotecas_oaxaca;

use bibliotecas_oaxaca;

create table biblioteca(
    id_biblioteca INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(50),
    email VARCHAR(50),
    telefono VARCHAR(15),
    calle VARCHAR(50),
    numero INT,
    codigo_postal INT,
    colonia VARCHAR(50)

);

CREATE TABLE libros (
    isbn INT PRIMARY KEY,
    titulo VARCHAR(50),
    autor VARCHAR(50),
    editorial VARCHAR(50),
    cantidad VARCHAR(50),
    id_biblioteca INT,
    FOREIGN KEY (id_biblioteca) REFERENCES biblioteca(id_biblioteca)
);

CREATE TABLE usuarios (
    id_usuario INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(50),
    apellido_paterno VARCHAR(50),
    id_biblioteca INT,
    FOREIGN KEY (id_biblioteca) REFERENCES biblioteca(id_biblioteca),
    isbn INT,
    FOREIGN KEY (isbn) REFERENCES libros(isbn)
);

CREATE TABLE prestamos (
    id_prestamo INT AUTO_INCREMENT PRIMARY KEY,
    fecha_prestamo DATE,
    id_usuario INT,
    FOREIGN KEY (id_usuario) REFERENCES usuarios(id_usuario)
);

INSERT INTO biblioteca (nombre, email, telefono, calle, numero, codigo_postal, colonia) VALUES
('Biblioteca Margarita Maza de juarez', 'mazaj@libros.mx', '9511234567', 'Av.Morelos', 200, 68000, 'Centro'),
('Biblioteca Lic. Benito juarez', 'benij@libros.mx', '9517654321', 'av. Universidad', 10, 68110, 'oaxaca de juarez'),
('Casa de la ciudad biblioteca Andres Henestrosa', 'henand@libros.mx', '9519998888', 'porfirio diaz', 115, 68000, 'centro'),
('Biblioteca de investigacion juan de cordova', 'cordova@libros.mx', '9516667777', 'independencia', 904, 68000, 'centro'),
('BS Biblioteca infantil de oaxaca ', 'oaxinfan@libros.mx', '9514443333', 'jose lopez alavez', 1342, 68040, 'xochimilco'),
('Biblioteca de la casa de la cultura oaxaqueña', 'cultoax@libros.mx', '9513332222', 'Calle gonzalez ortega', 403, 68000, 'centro'),
('Biblioteca publica municipal de oaxaca de juarez', 'munioax@libros.mx', '9511110000', 'Calle independencia', 200, 68000, 'centro'),
('Biblioteca Comunitaria', 'comunidad@libros.mx', '9517778888', 'Calle Pueblo', 22, 55667, 'Comunidad'),
('centro de lectura El rincon de la lectura', 'centrolectura@libros.mx', '9512223333', 'Calle jacarandas', 205, 68050, 'santa lucia del camino'),
('Biblioteca Regional', 'regional@libros.mx', '9518889999', 'Av. Región', 88, 99000, 'Zona Norte');


INSERT INTO libros (isbn, titulo, autor, editorial, cantidad, id_biblioteca) VALUES
(1001, 'El Señor de los Anillos: La Comunidad del Anillo', 'J.R.R. Tolkien', 'Minotauro', '5', 1),
(1002, 'El Señor de los Anillos: Las Dos Torres', 'J.R.R. Tolkien', 'Minotauro', '4', 1),
(1003, 'Harry Potter y la Piedra Filosofal', 'J.K. Rowling', 'Salamandra', '6', 2),
(1004, 'Harry Potter y el Prisionero de Azkaban', 'J.K. Rowling', 'Salamandra', '6', 2),
(1005, 'Los Juegos del Hambre', 'Suzanne Collins', 'RBA Molino', '7', 3),
(1006, 'En Llamas', 'Suzanne Collins', 'RBA Molino', '5', 3),
(1007, 'Cosmos', 'Carl Sagan', 'Planeta', '4', 4),
(1008, 'Astrofísica para gente con prisas', 'Neil deGrasse Tyson', 'Paidós', '8', 5),
(1009, 'Cartas a una joven científica', 'Neil deGrasse Tyson', 'Crítica', '3', 5),
(1010, 'El Hobbit', 'J.R.R. Tolkien', 'Minotauro', '9', 6);

INSERT INTO usuarios (nombre, apellido_paterno,id_biblioteca, isbn) VALUES
('camila', 'reyes', 1, 1001),
('ulysses', 'santiago', 1, 1002),
('luis', 'leon', 2, 1004),
('arturo', 'silva', 3, 1005),
('david', 'bautista', 4, 1006),
('sergio', 'sanchez', 5, 1007),
('gregorio', 'maces', 6, 1008),
('Sofía', 'Díaz', 7, 1009),
('Miguel', 'Torres', 8, 1010),
('alan', 'Cruz', 9, 1003);


INSERT INTO prestamos (fecha_prestamo,id_usuario) VALUES
('2025-06-01', 1),
('2025-06-01', 2),
('2025-06-01', 3),
('2025-06-02', 4),
('2025-06-02', 5),
('2025-06-03', 6),
('2025-06-03', 7),
('2025-06-03', 8),
('2025-06-04', 9),
('2025-06-04', 10);






