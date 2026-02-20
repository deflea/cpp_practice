# 📘 PRÁCTICA INTEGRADORA COMPLETA  
## Archivos – Arreglos – Cadenas – Ordenamiento – Búsqueda  
### (Sin punteros dinámicos, sin STL, estilo UTN)

---

# 📌 CONDICIONES GENERALES

- Lenguaje: C o C++ procedural.
- Usar:
  - `struct`
  - arreglos estáticos
  - `char[]` para cadenas
  - archivos (`FILE*`) binarios y de texto
  - funciones
  - búsqueda secuencial y binaria
  - ordenamiento (burbuja o selección)
  - corte de control
  - apareo
- NO usar:
  - `new`, `malloc`
  - `vector`, `string`
  - estructuras dinámicas

---

# 🔹 EJERCICIOS – PARTE A (ARCHIVOS)

---

## 🟦 EJERCICIO A1 – Alta y listado de alumnos

Estructura:

    struct Alumno {
        int legajo;
        char nombre[30];
        float promedio;
    };

Consignas:

1. Crear archivo binario `alumnos.dat`.
2. Cargar alumnos por teclado (fin con legajo = 0).
3. Guardar cada alumno en el archivo.
4. Mostrar el contenido completo del archivo.

---

## 🟦 EJERCICIO A2 – Filtro de archivo

A partir de `alumnos.dat`:

1. Generar archivo `promocionados.dat`.
2. Guardar solo alumnos con promedio ≥ 8.
3. Mostrar el archivo generado.
4. No modificar el archivo original.

---

## 🟦 EJERCICIO A3 – Corte de control

Suposición: `alumnos.dat` está ordenado por promedio.

Mostrar:

    Promedio: 6.5
      Juan
      Ana
    Promedio: 8.0
      Pedro

Requisitos:

- Usar técnica de corte de control.
- No cargar todo el archivo en un arreglo.

---

## 🟦 EJERCICIO A4 – Búsqueda en archivo

1. Pedir un legajo por teclado.
2. Buscarlo en `alumnos.dat`.
3. Mostrar nombre y promedio.
4. Si no existe, informar.

(Búsqueda secuencial directa sobre archivo)

---

## 🟦 EJERCICIO A5 – Apareo de archivos

Archivos:

- `alumnosA.dat` (ordenado por legajo)
- `alumnosB.dat` (ordenado por legajo)

Consignas:

1. Generar `alumnosTotal.dat`.
2. Mantener orden por legajo.
3. No duplicar legajos.

---

## 🟦 EJERCICIO A6 – Actualización lógica

Modificar estructura:

    struct Alumno {
        int legajo;
        char nombre[30];
        float promedio;
        bool activo;
    };

Consignas:

1. Pedir un legajo.
2. Marcar `activo = false`.
3. No eliminar físicamente el registro.
4. Mostrar archivo indicando activos/inactivos.

(Usar `fseek` + `fwrite`)

---

## 🟦 EJERCICIO A7 – Estadísticas desde archivo

Desde `alumnos.dat` calcular:

- Promedio general.
- Cantidad aprobados (≥ 6).
- Cantidad desaprobados.

Mostrar resultados.

---

## 🟦 EJERCICIO A8 – Archivo de texto

1. Crear archivo `alumnos.txt` con formato:

    legajo;nombre;promedio

2. Leer el archivo.
3. Mostrar los datos formateados en columnas.

(Usar `fprintf` y `fscanf`)

---

# 🔹 EJERCICIOS – PARTE B (INTEGRADORES COMPLETOS)

---

## 🟩 EJERCICIO B1 – Archivo + arreglo + búsqueda

Estructura:

    struct Producto {
        int codigo;
        char descripcion[30];
        float precio;
    };

Consignas:

1. Cargar `productos.dat`.
2. Leer el archivo en un arreglo.
3. Pedir un código por teclado.
4. Buscar el producto en el arreglo.
5. Mostrar datos o mensaje de error.

(Búsqueda secuencial)

---

## 🟩 EJERCICIO B2 – Ordenamiento + archivo

A partir del ejercicio B1:

1. Ordenar el arreglo por precio ascendente.
2. Generar `productos_ordenados.dat`.
3. Mostrar el archivo ordenado.

(Usar burbuja o selección)

---

## 🟩 EJERCICIO B3 – Cadenas + archivo de texto

Archivo `personas.txt`:

    DNI;Apellido;Nombre

Consignas:

1. Leer archivo.
2. Guardar datos en arreglos.
3. Mostrar personas cuyo apellido empiece con una letra ingresada.
4. Comparar cadenas correctamente.

(Usar funciones de manejo de cadenas)

---

## 🟩 EJERCICIO B4 – Corte de control en ventas

Archivo `ventas.dat` ordenado por codigoProducto.

    struct Venta {
        int codigoProducto;
        int cantidad;
        float importe;
    };

Consignas:

1. Leer el archivo.
2. Calcular total vendido por cada producto.
3. Mostrar totales usando corte de control.

---

## 🟩 EJERCICIO B5 – Apareo de clientes

Archivos:

- `clientesA.dat`
- `clientesB.dat`

Ordenados por DNI.

    struct Cliente {
        int dni;
        char nombre[30];
    };

Consignas:

1. Generar `clientesTotal.dat`.
2. Mantener orden.
3. No duplicar clientes.

---

## 🟩 EJERCICIO B6 – Búsqueda binaria

1. Leer `productos.dat`.
2. Cargar en arreglo.
3. Ordenar por código.
4. Implementar búsqueda binaria.
5. Mostrar resultado.

Explicar por qué es válida la búsqueda binaria.

---

## 🟩 EJERCICIO B7 – Actualización de archivo

    struct Empleado {
        int legajo;
        char nombre[30];
        float sueldo;
    };

Consignas:

1. Buscar empleado por legajo.
2. Aumentar sueldo un 10%.
3. Actualizar registro en archivo.
4. Mostrar archivo completo.

---

## 🟩 EJERCICIO B8 – Integrador tipo final

1. Cargar `alumnos.dat`.
2. Leerlo en un arreglo.
3. Ordenar por promedio descendente.
4. Buscar alumno por legajo.
5. Generar `aprobados.dat` (promedio ≥ 6).
6. Mostrar ambos archivos.

---

# 🎯 OBJETIVO

Si resolvés correctamente todos estos ejercicios, dominás:

- Archivos binarios y de texto
- Arreglos y estructuras
- Cadenas de caracteres
- Ordenamiento clásico
- Búsqueda secuencial y binaria
- Corte de control
- Apareo
- Actualización lógica

Nivel equivalente a parcial/final.
