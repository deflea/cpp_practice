//INCLUDES
#include <cstdio>
#include<iostream>

//NAMESPACES
/*using namespace std;*/
using std::cout;
using std::cin;
using std::endl;

//DEFINES / CONSTANTES GLOBALES

//ESTRUCTURAS / ENUMS/ TYPEDEFS
struct t_venta {
    int codigo;
    int cantidad;
    float precio;
};
//DECLARACIONES DE FUNCIONES (prototipos)
void crear_archivo();
void calcular_tamanio(int &);
void procesar_archivo(int, t_venta ar_ventas[]);
void ordenar_archivo(int, t_venta ar_ventas[]);
void escribir_archivo(int, t_venta ar_ventas[]);
void mostrar_archivo();
//FUNCION PRINCIPAL
int main(){
	int tamanio;
	crear_archivo();
	calcular_tamanio(tamanio);
	t_venta ar_ventas[tamanio];
	procesar_archivo(tamanio,ar_ventas);
	ordenar_archivo(tamanio,ar_ventas);
	escribir_archivo(tamanio,ar_ventas);
	mostrar_archivo();
	return 0;
}

//DEFINICIONES
void crear_archivo(){
	t_venta escritura;
	FILE* outfile = fopen("utils/ventas.dat","wb");
	cout << "La carga finaliza cuando el codigo ingresado es 0"<< endl;
	cout << "Ingrese el codigo del producto: ";
	cin >> escritura.codigo;
	while(escritura.codigo !=0){
		cout << "Ingrese la cantidad: ";
		cin >> escritura.cantidad;
		cout << "Ingrese el precio: ";
		cin >> escritura.precio;
		fwrite(&escritura,sizeof(t_venta),1,outfile);
		cout << "La carga finaliza cuando el codigo ingresado es 0"<< endl;
		cout << "Ingrese el codigo del producto: ";
		cin >> escritura.codigo;
	}
	fclose(outfile);
	return;	
}
void calcular_tamanio(int &tamanio){
	FILE* infile = fopen("utils/ventas.dat","rb");
	fseek(infile, 0, SEEK_END);
	tamanio = ftell(infile)/ sizeof(t_venta);
	fclose(infile);
	return;
}
void procesar_archivo(int tamanio, t_venta ar_ventas[]){
	t_venta lectura;
	FILE* infile = fopen("utils/ventas.dat","rb");
	for(int i = 0; i< tamanio; i++){
		fread(&lectura,sizeof(t_venta),1,infile);
		ar_ventas[i].codigo = lectura.codigo;
		ar_ventas[i].cantidad = lectura.cantidad;
		ar_ventas[i].precio = lectura.precio;
	}
	fclose(infile);
	return;
}
void ordenar_archivo(int tamanio, t_venta ar_ventas[]){
	t_venta auxiliar;
	for(int i=0;i<tamanio-1;i++){
		for(int j= 0; j<tamanio -1 -i; j++){
			if(ar_ventas[j].codigo > ar_ventas[j+1].codigo){
				auxiliar = ar_ventas[j];
				ar_ventas[j] = ar_ventas[j+1];
				ar_ventas[j+1] = auxiliar;
			}
		}
	}
	return;
}
void escribir_archivo(int tamanio, t_venta ar_ventas[]){
	FILE* outfile = fopen("utils/ventas_ordenadas.dat","wb");
	for (int i = 0; i<tamanio; i++){
		fwrite(&ar_ventas[i],sizeof(t_venta),1,outfile);
	}
	fclose(outfile);
	return;
}
void mostrar_archivo(){
	t_venta lectura;
	float total;
	int codigo_actual;
	FILE* infile = fopen("utils/ventas_ordenadas.dat","rb");
	fread(&lectura,sizeof(t_venta),1,infile);
	while(!feof(infile)){
		codigo_actual = lectura.codigo;
		total = 0;
		while(!feof(infile) && codigo_actual == lectura.codigo ){
			total += lectura.cantidad * lectura.precio;
			fread(&lectura, sizeof(t_venta),1,infile);
		}
		cout << "Total producto codigo " << codigo_actual << " es: " << total << endl;
		
	}
	return;
}