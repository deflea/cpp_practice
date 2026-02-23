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
struct t_cliente{
	int codigo;
	char nombre_completo[20];
};
//ESTRUCTURAS / ENUMS/ TYPEDEFS

//DECLARACIONES DE FUNCIONES (prototipos)
void mostrar_archivo();
void aparear_archivos();

//FUNCION PRINCIPAL
int main(){
	aparear_archivos();
	mostrar_archivo();
	return 0;
}

//DEFINICIONES
void aparear_archivos(){
	int codigoA, codigoB;
	FILE* infileA = fopen("utils/clientesA.txt","r");
	FILE* infileB = fopen("utils/clientesB.txt","r");
	FILE* outfile = fopen("utils/clientesAB.txt","w");

	char lineaA[30];
	char lineaB[30];
	char lineaAB[30];
	bool okA = fgets(lineaA,sizeof(lineaA),infileA); 
	bool okB = fgets(lineaB,sizeof(lineaB),infileB);
	while(okA && okB){
		sscanf(lineaA,"%d",&codigoA);
		sscanf(lineaB, "%d", &codigoB);
		if(codigoA < codigoB ){
			fputs(lineaA,outfile);
			okA = fgets(lineaA,sizeof(lineaA),infileA);
		}else{
			fputs(lineaB,outfile);
			okB = fgets(lineaB,sizeof(lineaB),infileB);
		}
	}
	while(fgets(lineaA,sizeof(lineaA),infileA)!=NULL){
		fputs(lineaA,outfile);
	}
	while(fgets(lineaB,sizeof(lineaB),infileB)!= NULL){
		fputs(lineaB,outfile);
	}
	fclose(infileA);
	fclose(infileB);
	fclose(outfile);
	return;
}
void mostrar_archivo(){
	FILE* infile = fopen("utils/clientesAB.txt","r");
	char linea[30];
	while(fgets(linea,sizeof(linea),infile)!= NULL){
		cout << linea;
	}
	cout << endl;
	fclose(infile);
	return;
}