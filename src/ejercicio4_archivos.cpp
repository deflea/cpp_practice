//INCLUDES
#include<iostream>

//NAMESPACES
/*using namespace std;*/
using std::cout;
using std::cin;
using std::endl;

//DEFINES / CONSTANTES GLOBALES

//ESTRUCTURAS / ENUMS/ TYPEDEFS
struct t_alumno{
	int legajo;
	char nombre[20];
	float promedio;
};
//DECLARACIONES DE FUNCIONES (prototipos)
bool leer_archivo(int &);
void imprimir_alumno(t_alumno &);
//FUNCION PRINCIPAL
int main(){
	int legajo;
	cout << "Ingrese el legajo a buscar en alumnos.dat: ";
	cin >> legajo;
	if(!leer_archivo(legajo)){
		cout << "Legajo no encontrado"<< endl;
	}
	return 0;
}

//DEFINICIONES
bool leer_archivo(int &legajo){
	t_alumno lectura;
	FILE* infile = fopen("utils/alumnos.dat","rb");
	fread(&lectura,sizeof(t_alumno),1,infile);
	while(!feof(infile)){
		if(legajo == lectura.legajo){
			fclose(infile);
			imprimir_alumno(lectura);
			return true;
		}
		fread(&lectura,sizeof(t_alumno),1,infile);
	}
	fclose(infile);
	return false;
}
void imprimir_alumno(t_alumno &lectura){
	cout << "Nombre: " << lectura.nombre<<endl;
	cout << "Promedio: " << lectura.promedio<< endl;
	return;
}