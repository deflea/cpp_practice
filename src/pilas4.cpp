//INCLUDES
#include<iostream>
#include<cstring>

//NAMESPACES
/*using namespace std;*/
using std::cout;
using std::cin;
using std::endl;

//DEFINES / CONSTANTES GLOBALES

//ESTRUCTURAS / ENUMS/ TYPEDEFS
struct t_nodo{
	char palabra[20];
	t_nodo* siguiente;
};
//DECLARACIONES DE FUNCIONES (prototipos)
void push(t_nodo*&, char palabra[]);
char* pop(t_nodo* &);
//FUNCION PRINCIPAL
int main(){
	t_nodo* pila = NULL;
	char palabra[20];
	for(int i=0;i<3;i++){
		cout << "Ingrese una palabra: ";
		cin >> palabra;
		push(pila,palabra);
	}
	while(pila!=NULL){
		char* palabra = pop(pila);
		cout << palabra << "  ";
		delete[] palabra;
	}
	cout << endl;
	return 0;
}

//DEFINICIONES
void push(t_nodo* &pila, char palabra[20]){
	t_nodo* nuevo_nodo = new t_nodo;
	strcpy(nuevo_nodo->palabra,palabra);
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	return;
}
char* pop(t_nodo* &pila){
	t_nodo* nodo_aux = pila;
	char* palabra = new char[20];
	strcpy(palabra,nodo_aux->palabra);
	pila = nodo_aux->siguiente;
	delete nodo_aux;
	return palabra;
}