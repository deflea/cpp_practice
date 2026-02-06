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
void generar_archivo_apareado();
void mostrar_archivo();
//FUNCION PRINCIPAL
int main(){
	generar_archivo_apareado();
	mostrar_archivo();
	return 0;
}

//DEFINICIONES
void generar_archivo_apareado(){
	t_alumno lectura_1;
	t_alumno lectura_2;
	FILE* infile_1 = fopen("utils/alumnosA.dat","rb");
	FILE* infile_2 = fopen("utils/alumnosB.dat","rb");
	FILE* outfile = fopen("utils/alumnosTotal.dat","wb");

	fread(&lectura_1,sizeof(t_alumno),1,infile_1);
	fread(&lectura_2,sizeof(t_alumno),1,infile_2);
	
	while(!feof(infile_1)&& !feof(infile_2)){
		if(lectura_1.legajo < lectura_2.legajo){
			fwrite(&lectura_1,sizeof(t_alumno),1,outfile);
			fread(&lectura_1,sizeof(t_alumno),1,infile_1);
		}else{
			fwrite(&lectura_2,sizeof(t_alumno),1,outfile);
			fread(&lectura_2,sizeof(t_alumno),1,infile_2);
		}
	}
	while(!feof(infile_1)){
		fwrite(&lectura_1,sizeof(t_alumno),1,outfile);
		fread(&lectura_1,sizeof(t_alumno),1,infile_1);
	}
	while(!feof(infile_2)){
		fwrite(&lectura_2,sizeof(t_alumno),1,outfile);
		fread(&lectura_2,sizeof(t_alumno),1,infile_2);
	}
	
	fclose(infile_1);
	fclose(infile_2);
	fclose(outfile);

	return;
}
void mostrar_archivo(){
	t_alumno lectura;
	FILE* infile = fopen("utils/alumnosTotal.dat","rb");

	fread(&lectura, sizeof(t_alumno),1,infile);
	while(!feof(infile)){
		cout << "Legajo: " << lectura.legajo;
		cout << " - Nombre: " << lectura.nombre;
		cout << " - Promedio: " << lectura.promedio << endl;
		fread(&lectura,sizeof(t_alumno),1,infile);
	}
	return;
}