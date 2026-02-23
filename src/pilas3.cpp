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
	int valor;
	t_dato* siguiente;
};
struct t_nodo{
	t_dato* dato;
	t_nodo* siguiente;
};
//DECLARACIONES DE FUNCIONES (prototipos)
void push_externo(t_nodo* &, t_dato* &);
t_dato* pop_externo(t_nodo* &);
void push_interno(t_dato* &, int );
int pop_interno(t_dato* &);
//FUNCION PRINCIPAL
int main(){
	t_nodo* pila_principal = NULL;
	for(int i=0;i<3;i++){
		cout << "Cargando pila interna: " << i+1 << endl;
		t_dato* pila_interna = NULL;
		int numero;
		cout << "Ingrese un numero (0 para terminar): ";
		cin >> numero;
		while(numero!=0){
			push_interno(pila_interna, numero);
			cout << "Ingrese un numero (0 para terminar): ";
			cin >> numero;
		}
		push_externo(pila_principal, pila_interna);
	}
	cout << "Visualizar estructura"<< endl;
	while(pila_principal!=NULL){
		t_dato* pila_interna = pop_externo(pila_principal);
		cout << "Pila interna: " << endl;
		while(pila_interna!=NULL){
			cout << pop_interno(pila_interna) << " ";
		}
		cout << endl;
	}
	
	return 0;
}
//DEFINICIONES
void push_externo(t_nodo* &pila_principal, t_dato* &pila_interna){
	t_nodo* nuevo_nodo = new t_nodo;
	nuevo_nodo->dato = pila_interna;
	nuevo_nodo->siguiente = pila_principal;
	pila_principal = nuevo_nodo;
	return;
}
t_dato* pop_externo(t_nodo* &pila_principal){
	t_nodo* nodo_aux = pila_principal;
	t_dato* pila_interna = nodo_aux->dato;
	pila_principal = nodo_aux->siguiente;
	delete nodo_aux;
	return pila_interna;
}
void push_interno(t_dato* &pila_interna, int valor){
	t_dato* nuevo_nodo = new t_dato;
	nuevo_nodo->valor = valor;
	nuevo_nodo->siguiente = pila_interna;
	pila_interna = nuevo_nodo;
	return;
}
int pop_interno(t_dato*& pila_interna){
	t_dato* nodo_aux = pila_interna;
	int valor = nodo_aux->valor;
	pila_interna = nodo_aux->siguiente;
	delete nodo_aux;
	return valor;
}