C++ practice projects
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
