//INCLUDES
#include<iostream>

//NAMESPACES
/*using namespace std;*/
using std::cout;
using std::cin;
using std::endl;

//DEFINES / CONSTANTES GLOBALES

//ESTRUCTURAS / ENUMS/ TYPEDEFS

//DECLARACIONES DE FUNCIONES (prototipos)

//FUNCION PRINCIPAL
int main(){
	int ar[10];
	int n = sizeof(ar)/sizeof(ar[0]);
	cout << "Longitud de ar: " << n << endl;
	int valor = 1;
	cout << "&valor: " << &valor << " valor en memoria" << endl;
	cout << "valor: " << valor << " valor asignado" << endl;

	int* pvalor;
	pvalor = &valor;
	cout << "&pvalor: " << &pvalor << " valor en memoria de pvalor"<< endl;
	cout << "pvalor: " << pvalor << " valor de memoria al que apunta el puntero pvalor" <<endl;
	cout << "*pvalor: " << *pvalor << " valor contenido en la direccion de memoria a la que apunta el puntero pvalor" << endl;

	cout << "&pvalor + 1: " << &pvalor + 1<< endl;
	cout << "&pvalor + sizeof(int): " << &pvalor + sizeof(int) << endl;
	cout << "*pvalor +1: " << *pvalor +1 << endl;
	cout << " pvalor +1: " << pvalor +1 << endl;
	cout << " valor: " << valor << endl;
	 
	return 0;
}

//DEFINICIONES
