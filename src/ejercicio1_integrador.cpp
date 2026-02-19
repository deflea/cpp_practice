//INCLUDES
#include <cstdio>
#include<iostream>
#include<cstring>

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
t_producto buscar_producto(int codigo,t_producto ar_lectura[], long &tamanio);
void escribir_archivo();
void leer_archivo(long &, t_producto ar_lectura[]);
long calcular_tamanio(long &);
//FUNCION PRINCIPAL
int main(){
	long tamanio;
	t_producto resultado;
	int codigo;

	escribir_archivo();
	calcular_tamanio(tamanio);
	t_producto ar_lectura[tamanio];
	leer_archivo(tamanio,ar_lectura);
	cout << "Ingrese el codigo de producto a buscar: ";
	cin >> codigo;
	resultado = buscar_producto(codigo,ar_lectura,tamanio);
	if(resultado.codigo == 0){
		cout << "El producto no se encuentra en la lista" << endl;;
	}else{
		cout << "Codigo buscado: " << resultado.codigo << endl;
		cout << "Producto: " << resultado.nombre << endl;
		cout << "Precio: " << resultado.precio << endl;
	}
	
	return 0;
}

//DEFINICIONES
void escribir_archivo(){
	t_producto escritura;
	FILE* outfile = fopen("utils/productos.dat","wb");
	cout << "La carga de productos finaliza cuando el codigo ingresado es 0"<< endl;
	cout << "Ingrese el codigo del producto: ";
	cin >> escritura.codigo;
	while(escritura.codigo>0){
		cout << "Ingrese el nombre del producto: ";
		cin >> escritura.nombre;
		cout << "Ingrese el precio del producto: ";
		cin >> escritura.precio;
		fwrite(&escritura,sizeof(t_producto),1,outfile);
		cout << "La carga de productos finaliza cuando el codigo ingresado es 0"<< endl;
		cout << "Ingrese el codigo del producto: ";
		cin >> escritura.codigo;
	}
	fclose(outfile);
	return;
}
long calcular_tamanio(long &tamanio){
	FILE* infile=fopen("utils/productos.dat","rb");
	fseek(infile,0,SEEK_END);
	tamanio = ftell(infile)/sizeof(t_producto);
	fclose(infile);
	return tamanio;
}
void leer_archivo(long &tamanio,t_producto ar_lectura[]){
	FILE* infile=fopen("utils/productos.dat","rb");

	
	t_producto lectura;
	for(int i=0;i<tamanio;i++){
		fread(&lectura,sizeof(t_producto),1,infile);
		ar_lectura[i].codigo = lectura.codigo;
		strcpy(ar_lectura[i].nombre,lectura.nombre);
		ar_lectura[i].precio = lectura.precio;
	}
	fclose(infile);
	return;
}
t_producto buscar_producto(int codigo,t_producto ar_lectura[], long &tamanio){
	t_producto producto;
	producto.codigo = 0;
	for(int i=0; i<tamanio;i++){
		if(ar_lectura[i].codigo==codigo){
			producto.codigo = ar_lectura[i].codigo;
			strcpy(producto.nombre,ar_lectura[i].nombre);
			producto.precio = ar_lectura[i].precio;
			break;
		}
	}
	return producto;
}