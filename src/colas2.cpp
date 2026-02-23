//INCLUDES
#include<iostream>

//NAMESPACES
/*using namespace std;*/
using std::cout;
using std::cin;
using std::endl;

//DEFINES / CONSTANTES GLOBALES

//ESTRUCTURAS / ENUMS/ TYPEDEFS
struct t_nodo_interno{
	int codigo;
	t_nodo_interno* siguiente;
};
struct t_nodo{
	t_nodo_interno* frente_interno;
	t_nodo_interno* fin_interno;
	t_nodo* siguiente;
};
//DECLARACIONES DE FUNCIONES (prototipos)
void encolar_externo(t_nodo* &, t_nodo* &, t_nodo_interno* &, t_nodo_interno* &);
void desencolar_externo(t_nodo* &, t_nodo* &,t_nodo_interno* &, t_nodo_interno* &);
void encolar_interno(t_nodo_interno* &,t_nodo_interno* &, int);
int desencolar_interno(t_nodo_interno* &,t_nodo_interno* &);
//FUNCION PRINCIPAL
int main(){
	t_nodo* frente_ext = NULL;
	t_nodo* fin_ext = NULL;
	for(int i=0;i<3;i++){
		t_nodo_interno* frente_int = NULL;
		t_nodo_interno* fin_int = NULL;
		cout << "Cargando la cola interna....." <<endl;
		int numero;
		cin>> numero;
		while(numero!=0){
			encolar_interno(frente_int,fin_int, numero);
			cin >> numero;
		}
		encolar_externo(frente_ext,fin_ext,frente_int, fin_int);
	}
	cout << "Mostar estructura....." << endl;
	while(frente_ext!=NULL){
		t_nodo_interno* frente_int;
		t_nodo_interno* fin_int;
		desencolar_externo(frente_ext,fin_ext,frente_int, fin_int);
		cout << "Cola interna..." ;	
		while(frente_int!=NULL){
			cout << desencolar_interno(frente_int,fin_int) << " ";
		}
		cout << endl;
	}
	return 0;
}

//DEFINICIONES
void encolar_interno(t_nodo_interno*& frente_int, t_nodo_interno* &fin_int,int dato){
	t_nodo_interno* nuevo_nodo = new t_nodo_interno;
	nuevo_nodo->codigo = dato;
	nuevo_nodo->siguiente = NULL;
	if(frente_int==NULL){
		frente_int = nuevo_nodo;
	}else{
		fin_int->siguiente = nuevo_nodo;
	}
	fin_int = nuevo_nodo;
	return;
}
int desencolar_interno(t_nodo_interno* &frente_int, t_nodo_interno* &fin_int){
	t_nodo_interno* nodo_aux = frente_int;
	int dato = nodo_aux->codigo;
	frente_int = nodo_aux->siguiente;
	if(frente_int == NULL){
		fin_int = NULL;
	}
	delete nodo_aux;
	return dato;
}
void encolar_externo(t_nodo* &frente_ext, t_nodo* &fin_ext, t_nodo_interno* &frente_int, t_nodo_interno* &fin_int){
	t_nodo* nuevo_nodo = new t_nodo;
	nuevo_nodo->frente_interno = frente_int;
	nuevo_nodo->fin_interno = fin_int;
	nuevo_nodo->siguiente = NULL;

	if(frente_ext==NULL){
		frente_ext = nuevo_nodo;
	}else{
		fin_ext->siguiente = nuevo_nodo;
	}
	fin_ext = nuevo_nodo;
	return;
}
void desencolar_externo(t_nodo* &frente_ext, t_nodo* &fin_ext,t_nodo_interno* &frente_int, t_nodo_interno* &fin_int){
	t_nodo* nodo_aux = frente_ext;
	frente_int = nodo_aux->frente_interno;
	fin_int = nodo_aux->frente_interno;
	frente_ext = nodo_aux->siguiente;

	if(frente_ext == NULL){
		fin_ext = NULL;
	}
	delete nodo_aux;
	return;
}