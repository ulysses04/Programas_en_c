create database proyecto_investigacion;

use proyecto_investigacion;

create table programa(
    id_programa INT PRIMARY KEY AUTO_INCREMENT,
    nombre VARCHAR(70)
);

create table profesor(
    dni VARCHAR(15) PRIMARY KEY NOT NULL,
    nombre VARCHAR(70),
    apellido VARCHAR(70),
    titulacion VARCHAR(70),
    anios_experiencia INT,
    CHECK(anios_experiencia>=0)


);

create table departamento(
    id_departamento INT PRIMARY KEY AUTO_INCREMENT,
    nombre VARCHAR(70),
    campus VARCHAR(70),
    telefono VARCHAR(15),
    dni VARCHAR(15),
    FOREIGN KEY (dni) REFERENCES profesor(dni)
);

create table grupo(
    id_grupo INT PRIMARY KEY AUTO_INCREMENT,
    nombre VARCHAR(70),
    id_departamento INT,
    FOREIGN KEY (id_departamento) REFERENCES departamento(id_departamento),
    dni VARCHAR(15),
    FOREIGN KEY (dni) REFERENCES profesor(dni)
);


Create table proyecto (
    id_proyecto INT PRIMARY KEY AUTO_INCREMENT,
    nombre VARCHAR(70),
    fecha_inicio DATE,
    fecha_fin DATE,
    presupuesto DECIMAL(10,2),
    CHECK(presupuesto>=0),
    id_grupo INT,
    FOREIGN KEY (id_grupo) REFERENCES grupo(id_grupo)
);

create table financiamiento(
    cantidad_aportada DECIMAL(10,2),
    CHECK(cantidad_aportada>=0),
    id_proyecto INT,
    FOREIGN KEY (id_proyecto) REFERENCES proyecto(id_proyecto),
    id_programa INT,
    FOREIGN KEY (id_programa) REFERENCES programa(id_programa)

);

create table participa(
    dni VARCHAR(15),
    FOREIGN KEY (dni) REFERENCES profesor(dni),
    id_proyecto INT,
    FOREIGN KEY (id_proyecto) REFERENCES proyecto(id_proyecto),
    fecha_incorporacion DATE,
    fecha_salida DATE
    );