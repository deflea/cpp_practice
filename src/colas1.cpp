//INCLUDES
#include<iostream>

//NAMESPACES
/*using namespace std;*/
using std::cout;
using std::cin;
using std::endl;

//DEFINES / CONSTANTES GLOBALES

//ESTRUCTURAS / ENUMS/ TYPEDEFS
struct t_nodo{
	int dato;
	t_nodo* siguiente;
};
//DECLARACIONES DE FUNCIONES (prototipos)
void encolar(t_nodo* &, t_nodo* &, int);
int desencolar(t_nodo* &, t_nodo* &);
void peek(t_nodo* &);
//FUNCION PRINCIPAL
int main(){
	t_nodo* frente = NULL;
	t_nodo* fin = NULL;
	peek(frente);
	encolar(frente,fin,10);
	encolar(frente,fin,20);
	encolar(frente,fin,30);
	peek(frente);
	while(frente!=NULL){
		cout << "Desencolando ...";
		int numero = desencolar(frente,fin);
		cout << numero << endl;
	}
	return 0;
}

//DEFINICIONES
void encolar(t_nodo* &frente,t_nodo* &fin, int dato){
	t_nodo* nuevo_nodo = new t_nodo;
	nuevo_nodo->dato = dato;
	nuevo_nodo->siguiente = NULL;
	if(frente == NULL){
		frente = nuevo_nodo;
	}else{
		fin->siguiente = nuevo_nodo;
	}
	fin = nuevo_nodo;
	return;
}
int desencolar(t_nodo*& frente, t_nodo *& fin){
	t_nodo* nodo_aux = frente;
	int dato = nodo_aux->dato;
	frente = nodo_aux->siguiente;
	if(frente == NULL){
		fin = NULL;
	}
	delete nodo_aux;
	return dato;
}
void peek(t_nodo*& frente){
	if(frente == NULL){
		cout << "La cola se encuentra vacia" << endl;
	}else{
		cout << frente->dato << endl;
	}
	return;
}