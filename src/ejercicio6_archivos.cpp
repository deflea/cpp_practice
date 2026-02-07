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
    bool activo;
};
//DECLARACIONES DE FUNCIONES (prototipos)
void cargar_archivo();
void actualizar_archivo();
void mostrar_archivo();
//FUNCION PRINCIPAL
int main(){
	cargar_archivo();
	actualizar_archivo();
	mostrar_archivo();
	return 0;
}

//DEFINICIONES
void cargar_archivo(){
	t_alumno escritura;
	FILE* outfile = fopen("utils/alumnos.dat","wb");
	cout << "La carga termina cuando el legajo ingresado es 0"<< endl;
	cout << "Ingrese el numero de legajo: ";
	cin >> 	escritura.legajo;
	while(escritura.legajo!=0){
		bool flag = true;
		cout << "Ingrese el nombre del alumno: ";
		cin >> escritura.nombre;
		while(flag){
			cout << "El promedio debe ser >= 0 y <=10"<< endl;
			cout << "Ingrese el promedio del alumno: ";
			cin >> escritura.promedio;
			if(escritura.promedio >=0 and escritura.promedio <=10){
				flag = false;
			}
		}
		escritura.activo = true;
		fwrite(&escritura,sizeof(t_alumno),1,outfile);
		cout << "La carga termina cuando el legajo ingresado es 0"<< endl;
		cout << "Ingrese el numero de legajo: ";
		cin >> 	escritura.legajo;
	}
	fclose(outfile);
	cout << "Carga finalizada, archivo generado"<< endl;
	return;
}
void actualizar_archivo(){
	t_alumno escritura;
	int legajo;
	FILE* infile = fopen("utils/alumnos.dat","rb+");
	cout << "Ingrese el numero de legajo: ";
	cin >> 	legajo;
	fread(&escritura,sizeof(t_alumno),1,infile);
	while(!feof(infile)){
		if(escritura.legajo == legajo){
			fseek(infile,-sizeof(t_alumno),SEEK_CUR);
			escritura.activo = false;
			fwrite(&escritura,sizeof(t_alumno),1,infile);
		}
		fread(&escritura,sizeof(t_alumno),1,infile);
	}
	fclose(infile);
	return;
}
void mostrar_archivo(){
	t_alumno lectura;
	FILE* infile = fopen("utils/alumnos.dat","rb");
	fread(&lectura,sizeof(t_alumno),1,infile);
	while(!feof(infile)){
		cout << "Legajo: " << lectura.legajo;
		cout << " - Nombre: " << lectura.nombre;
		cout << " - Promedio: " << lectura.promedio;
		cout << " - Activo: " << lectura.activo << endl;
		fread(&lectura,sizeof(t_alumno),1,infile);
	}
	fclose(infile);
	return;
}