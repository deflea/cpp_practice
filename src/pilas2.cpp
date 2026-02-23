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
	char dato;
	t_nodo* siguiente;
};
//DECLARACIONES DE FUNCIONES (prototipos)
void push(t_nodo* &, char );
char pop(t_nodo* &);
char peek(t_nodo* );
void es_palindromo(t_nodo*&, char palabra[]);
//FUNCION PRINCIPAL
int main(){
	t_nodo* pila = NULL;
	char palabra[20];
	cout << "Ingrese una palabra: ";
	cin >> palabra;
	es_palindromo(pila,palabra);
	return 0;
}

//DEFINICIONES
void push(t_nodo* &pila, char valor){
	t_nodo* nuevo_nodo = new t_nodo; // creo un nodo auxiliar
	nuevo_nodo->dato = valor; // asigno el valor al nodo
	nuevo_nodo->siguiente = pila;//apunto el nodo a la pila
	pila = nuevo_nodo;//asigno el nuevo nodo a la pila
	return;
}
char pop(t_nodo* &pila){
	t_nodo* nodo_aux = pila; //asigno a un nodo auxiliar la pila
	char valor = nodo_aux->dato; // asigno el tipo de dato de retorno
	pila = nodo_aux->siguiente; // apunto la pila al puntero del nodo_aux
	delete nodo_aux; // elimino el nodo auxiliar
	return valor;
}
char peek(t_nodo* pila){
	if(pila== NULL){
		return -1;
	}
	return pila->dato;
}
void es_palindromo(t_nodo* &pila,char palabra[]){
	int tamanio = strlen(palabra);
	char palabra_aux[tamanio];
	for(int i= 0; i< tamanio;i++){
		push(pila,palabra[i]);
	}
	for(int i=0; i< tamanio; i++){
		palabra_aux[i]= pop(pila);
	}
	if(strcmp(palabra,palabra_aux)==0){
		cout << "Son palindromos: " << palabra << " - " << palabra_aux<< endl;
	}else{
		cout << "No son palindromos: "<< palabra << " - " << palabra_aux << endl;
	}
	return;
}