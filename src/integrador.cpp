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
struct t_dato_combinado{
	int codigo;
	char nombre[10];
	int cantidad;
	float precio;
};

//DECLARACIONES DE FUNCIONES (prototipos)
void generar_archivo();
//FUNCION PRINCIPAL
int main(){
	cout << "Hello world!!" << endl;
	return 0;
}

//DEFINICIONES
void generar_archivo(){
	FILE* outfile = fopen("utils/codigo_combinado.dat","wb");
	
	int codigo, cantidad;
	float precio;
	char nombre[10];
	t_dato_combinado escritura;

	cout << "Ingrese el código del producto: ";
	cin >> codigo;
	while(codigo!=0){
		cout << "Ingrese el nombre del producto: ";
		cin >> nombre;
		cout << "Ingrese la cantidad: ";
		cin >> cantidad;
		cout << "Ingrese el precio unitario: ";
		cin >> precio;

		escritura.codigo = codigo;
		escritura.cantidad = cantidad;
		escritura.precio = precio;
		strcpy(escritura.nombre, nombre);


		fwrite(&escritura,sizeof(t_dato_combinado),1,outfile);
		cout << "Ingrese el código del producto: ";
		cin >> codigo;
	}
	fclose(outfile);
	return;

}
void calcular_tamanio(int &tamanio){
	FILE* infile = fopen("utils/codigo_combinado.dat","rb");
	fseek(infile,0,SEEK_END);
	tamanio = ftell(infile)/sizeof(t_dato_combinado);
	return;
}
void genera_archivo_ordenado_burbuja(int tamanio){
	FILE* infile = fopen("utils/codigo_combinado.dat","rb");
	FILE* outfile = fopen("utils/archivo_ordenado.dat","wb");
	t_dato_combinado lectura;
	t_dato_combinado escritura;
	t_dato_combinado ar_lectura[tamanio];

	for(int i = 0; i< tamanio; i++){
		fread(&lectura,sizeof(t_dato_combinado),1,infile);
		ar_lectura[i] = lectura;
	}

	for(int i= 0; i< tamanio-1;i++){
		for(int j=0; j<tamanio-1-i;j++){
			if(ar_lectura[j].codigo>ar_lectura[j+1].codigo){
				lectura = ar_lectura[j];
				ar_lectura[j] = ar_lectura[j+1];
				ar_lectura[j+1] = lectura;
			}
		}
	}
	for(int i=0; i<tamanio;i++){
		fwrite(&ar_lectura[i], sizeof(t_dato_combinado),1,outfile);
	}
	fclose(infile);
	fclose(outfile);

	return;
}
