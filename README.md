#C++ practice projects
## Como compilar:
	Compilar multiples archivos con includes propios
	g++ -Iinclude src/template.cpp src/ejemplo.cpp -o main
	
	Compilar multiples archivos
	g++ main.cpp utils.cpp -o main	

	Compilar un único archivo indicando el standard
	g++ -std=c++17 main.cpp -o main

	Compilar con warnings
	g++ -Wall -Wextra main.cpp -o main

	Compilación básica
	g++ main.cpp -o main

## Como compilar utilizando make

	make clean	--> Borra .o, binarios y archivos generados
	make 		--> Solo compila
	make run	--> Compila y ejecuta

## Estructura básica del proyecto

	cpp_practice/
		├── Makefile            # Automatiza la compilación del proyecto
		├── include/            # Headers (.h / .hpp)
		│   └── *.h             # Declaraciones, interfaces
		├── src/                # Código fuente (.cpp)
		│   ├── main.cpp        # Función main()
		│   └── *.cpp           # Implementaciones
		├── lib/                # Librerías (opcional)
		│   ├── *.a             # Librerías estáticas
		│   └── *.so            # Librerías compartidas
		├── output/             # Archivos generados
		│   ├── main            # Ejecutable final
		│   ├── *.o             # Archivos objeto
		│   └── *.d             # Dependencias para make
		├── utils				# Archivos de utilidades
		└── .gitignore          # Archivos a ignorar por git
