//INCLUDES
#include<iostream>
#include<cstdio>
#include<cstring>
//NAMESPACES
/*using namespace std;*/
using std::cout;
using std::cin;
using std::endl;

//DEFINES / CONSTANTES GLOBALES

//ESTRUCTURAS / ENUMS/ TYPEDEFS
struct t_persona{
	int dni;
	char apellido[20];
	char nombre[20];
};
//DECLARACIONES DE FUNCIONES (prototipos)
void procesar_archivo(int, t_persona ar_personas[]);
void calcular_tamanio(int &);
void mostrar_personas(char ,int , t_persona ar_personas[]);
//FUNCION PRINCIPAL
int main(){
	int tamanio = 0;
	char letra;
	calcular_tamanio(tamanio);
	t_persona ar_personas[tamanio];
	procesar_archivo(tamanio,ar_personas);
	cout << "Ingrese una letra para buscar existencia de apellidos que comiencen con esa letra: ";
	cin >> letra; 
	mostrar_personas(letra, tamanio,ar_personas);

	return 0;
}

//DEFINICIONES
void calcular_tamanio(int &tamanio){
	FILE* infile = fopen("utils/personas.txt","r");
	char linea[100];
	while(fgets(linea, sizeof(linea), infile)!= NULL){
		tamanio++;
	}
	fclose(infile);
	return;
}
void procesar_archivo(int tamanio,t_persona ar_personas[]){
	t_persona lectura;
	FILE* infile = fopen("utils/personas.txt","r");
	char linea[100];
	for(int i=0;i<tamanio;i++){
		fgets(linea,sizeof(linea),infile);
		sscanf(linea,"%d;%19[^;];%19s",
			&ar_personas[i].dni,
			ar_personas[i].apellido,
			ar_personas[i].nombre);
	}
	fclose(infile);
	return;
}
void mostrar_personas(char letra,int tamanio, t_persona ar_personas[]){
	for(int i=0;i<tamanio;i++){
		if(letra == ar_personas[i].apellido[0]){
			cout << "DNI: " << ar_personas[i].dni;
			cout << " - Apellido: " << ar_personas[i].apellido;
			cout << " - Nombre: " << ar_personas[i].nombre << endl;
		}
	}
	return;
}