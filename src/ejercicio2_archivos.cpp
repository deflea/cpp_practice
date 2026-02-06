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
void leer_archivo();
void cargar_archivo(FILE*, t_alumno &);
void mostrar_archivo();
//FUNCION PRINCIPAL
int main(){
	leer_archivo();
	mostrar_archivo();
	return 0;
}

//DEFINICIONES
void leer_archivo(){
	t_alumno lectura;
	FILE* infile = fopen("utils/alumnos.dat","rb");
	FILE* outfile = fopen("utils/promocionados.dat","wb");
	fread(&lectura,sizeof(t_alumno),1,infile);
	while(!feof(infile)){
		if(lectura.promedio>=8){
			cargar_archivo(outfile, lectura);
		}
		fread(&lectura,sizeof(t_alumno),1,infile);
	}
	fclose(outfile);
	fclose(infile);
	return;
}
void cargar_archivo(FILE* outfile, t_alumno &lectura){
	fwrite(&lectura,sizeof(t_alumno),1,outfile);
	return;
}
void mostrar_archivo(){
	t_alumno lectura;
	FILE* infile = fopen("utils/promocionados.dat","rb");
	fread(&lectura,sizeof(t_alumno),1,infile);
	while(!feof(infile)){
		cout << "Legajo: " << lectura.legajo << " - Nombre: " << lectura.nombre << " - Promedio: " << lectura.promedio << endl;
		fread(&lectura,sizeof(t_alumno),1,infile);			
	}
	fclose(infile);
	return;
}