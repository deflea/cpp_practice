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
void insertar_inicio(t_nodo* &, int);
void insertar_final(t_nodo* &, int);
void insertar_ordenado(t_nodo* &, int);
void mostrar_lista(t_nodo* &);
void eliminar_nodo(t_nodo* &,int);
//FUNCION PRINCIPAL
int main(){
	t_nodo* lista = NULL;
	insertar_final(lista, 10);
	insertar_final(lista, 20);
	insertar_inicio(lista, 9);
	insertar_ordenado(lista, 15);
	insertar_ordenado(lista,14);
	mostrar_lista(lista);
	return 0;
}

//DEFINICIONES
void insertar_inicio(t_nodo* &lista, int dato){
	t_nodo* nuevo_nodo = new t_nodo;
	nuevo_nodo->dato = dato;
	nuevo_nodo->siguiente = lista;
	lista = nuevo_nodo;
	return;
}
void insertar_final(t_nodo* &lista, int dato){
	t_nodo* nuevo_nodo = new t_nodo;
	nuevo_nodo->dato = dato;
	nuevo_nodo->siguiente = NULL;
	if(lista== NULL){
		lista = nuevo_nodo;
	}else{
		t_nodo* auxiliar = lista;
		while(auxiliar->siguiente!= NULL){
			auxiliar = auxiliar->siguiente;
		}
		auxiliar->siguiente = nuevo_nodo;
	}
	return;
}
void insertar_ordenado(t_nodo* &lista,int dato){
	t_nodo* nuevo_nodo = new t_nodo;
	nuevo_nodo->dato = dato;
	if(lista==NULL || dato < lista->dato){
		nuevo_nodo->siguiente = lista;
		lista = nuevo_nodo;
	}else{
		t_nodo* auxiliar = lista;
		while(auxiliar->siguiente!= NULL && auxiliar->siguiente->dato< dato){
			auxiliar = auxiliar->siguiente;
		}
		nuevo_nodo->siguiente = auxiliar->siguiente;
		auxiliar->siguiente = nuevo_nodo;
	}
}
void mostrar_lista(t_nodo* &lista){
	t_nodo* auxiliar = lista;
	while(auxiliar!=NULL){
		cout << auxiliar->dato << " ";
		auxiliar = auxiliar->siguiente;
	}
	cout << endl;
	return;
}
t_nodo* buscar_nodo(t_nodo* &lista, int valor){
	t_nodo* auxiliar = lista;
	while(auxiliar != NULL && auxiliar->dato !=valor){
		auxiliar = auxiliar->siguiente;
	}
	return auxiliar;
}
void eliminar_nodo(t_nodo* &lista, int valor){
	if (lista == NULL){
		return;
	}
	if(lista-> dato == valor){
		t_nodo* auxiliar = lista;
		lista = lista->siguiente;
		delete auxiliar;
	}else{
		t_nodo* auxiliar = lista;
		while(auxiliar->siguiente != NULL && auxiliar->siguiente->dato != valor){
			auxiliar = auxiliar->siguiente;
		}
		if(auxiliar->siguiente!= NULL){
			t_nodo* borrar = auxiliar->siguiente;
			auxiliar->siguiente = borrar->siguiente;
			delete borrar;
		}
	}

}