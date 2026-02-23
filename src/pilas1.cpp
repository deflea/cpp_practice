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
struct t_dato{
	int codigo;
	char nombre[10];
};
struct t_nodo{
	t_dato dato;
	t_nodo* siguiente;
};
//DECLARACIONES DE FUNCIONES (prototipos)
void push(t_nodo* &, t_dato dato);
t_dato pop(t_nodo* &);
//FUNCION PRINCIPAL
int main(){
	char buffer[10];
	t_dato valor;
	t_nodo* pila = NULL;
	cout << "Ingrese un valor (0 para finalizar la carga): ";
	cin >> valor.codigo;
	while(valor.codigo !=0){
		cout << "Ingrese el nombre: ";
		cin >> buffer;
		strcpy(valor.nombre, buffer);
		push(pila,valor);
		cout << "Ingrese un valor (0 para finalizar la carga): ";
		cin >> valor.codigo;
	}
	
	while(pila!= NULL){
		valor = pop(pila);
		cout << valor.codigo << " - " << valor.nombre<< endl;
	}
	return 0;
}

//DEFINICIONES
void push(t_nodo* &pila, t_dato dato){
	t_nodo* nuevo_nodo = new t_nodo;
	nuevo_nodo->dato = dato;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	return;
}
t_dato pop(t_nodo* &pila){
	t_nodo* aux = pila;
	t_dato valor = aux->dato;
	pila = aux->siguiente;
	delete aux;
	return valor;
}
