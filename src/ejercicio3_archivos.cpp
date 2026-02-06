//INCLUDES
#include<iostream>

//NAMESPACES
/*using namespace std;*/
using std::cout;
using std::endl;

//DEFINES / CONSTANTES GLOBALES

//ESTRUCTURAS / ENUMS/ TYPEDEFS
struct t_alumno{
	int legajo;
	char nombre[20];
	float promedio;
};
//DECLARACIONES DE FUNCIONES (prototipos)
void cargar_archivo();
//FUNCION PRINCIPAL
int main(){
	cargar_archivo();
	return 0;
}
//DEFINICIONES
void cargar_archivo(){
	t_alumno lectura;
	float promedio_aux;
	FILE* infile = fopen("utils/alumnos.dat","rb");

	fread(&lectura,sizeof(t_alumno),1,infile);
	while(!feof(infile)){
		promedio_aux = lectura.promedio;
		cout << "Promedio " << promedio_aux << endl;
		while(!feof(infile) and promedio_aux == lectura.promedio){
			cout << lectura.nombre << endl;
			fread(&lectura,sizeof(t_alumno),1,infile);
		}
	} 
	fclose(infile);
	return;
}