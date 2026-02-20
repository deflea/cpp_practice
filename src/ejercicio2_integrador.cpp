//INCLUDES
#include<iostream>
#include<cstring>
#include<cstdio>

//NAMESPACES
/*using namespace std;*/
using std::cout;
using std::cin;
using std::endl;

//DEFINES / CONSTANTES GLOBALES

//ESTRUCTURAS / ENUMS/ TYPEDEFS
struct t_producto{
	int codigo;
	char nombre[30];
	float precio;
};
//DECLARACIONES DE FUNCIONES (prototipos)
void leer_archivo(long &, t_producto ar_lectura[]);
void calcular_tamanio(long &);
void ordenamiento_burbuja(long ,t_producto ar_lectura[]);
void escribir_archivo(long ,t_producto ar_lectura[]);
void mostrar_ordenado();
//FUNCION PRINCIPAL
int main(){
	long tamanio;
	calcular_tamanio(tamanio);
	t_producto ar_lectura[tamanio];
	leer_archivo(tamanio,ar_lectura);
	ordenamiento_burbuja(tamanio,ar_lectura);
	escribir_archivo(tamanio, ar_lectura);
	mostrar_ordenado();
	return 0;
}

//DEFINICIONES
void calcular_tamanio(long &tamanio){
	FILE* infile = fopen("utils/productos.dat","rb");
	fseek(infile, 0, SEEK_END);
	tamanio = ftell(infile)/sizeof(t_producto);
	fclose(infile);
	return;
}
void leer_archivo(long &tamanio,t_producto ar_lectura[]){
	t_producto lectura;
	FILE* infile = fopen("utils/productos.dat","rb");
	for(int i=0;i<tamanio;i++){
		fread(&lectura,sizeof(t_producto),1,infile);
		ar_lectura[i].codigo = lectura.codigo;
		strcpy(ar_lectura[i].nombre, lectura.nombre);
		ar_lectura[i].precio = lectura.precio;
	}
	fclose(infile);
	return;
}
void ordenamiento_burbuja(long tamanio, t_producto ar_lectura[]){
	t_producto auxiliar;
	for(int i= 0;i<tamanio-1;i++){
		for(int j= 0; j < tamanio-1-i; j++){
			if(ar_lectura[j].precio>ar_lectura[j+1].precio){
				auxiliar = ar_lectura[j];
				ar_lectura[j] = ar_lectura[j+1];
				ar_lectura[j+1] = auxiliar;
			}
		}
	}
	return;
}
void escribir_archivo(long tamanio,t_producto ar_lectura[]){
	FILE* outfile = fopen("utils/productos_ordenados.dat","wb");
	for(int i=0;i<tamanio;i++){
		fwrite(&ar_lectura[i],sizeof(t_producto),1,outfile);
	}
	fclose(outfile);
	return;
}
void mostrar_ordenado(){
	t_producto lectura;
	FILE* infile = fopen("utils/productos_ordenados.dat","rb");
	
	fread(&lectura,sizeof(t_producto),1,infile);
	while(!feof(infile)){
		cout << "Codigo: " << lectura.codigo;
		cout << " - Producto: " << lectura.nombre;
		cout << " - Precio: " << lectura.precio << endl;
		fread(&lectura,sizeof(t_producto),1,infile);
	}
	fclose(infile);

	return;
}