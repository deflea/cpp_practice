//INCLUDES
#include<cstddef>
#include<iostream>
#include<cstring>

//NAMESPACES
/*using namespace std;*/
using std::cout;
using std::cin;
using std::endl;
using std::string;

//DEFINES / CONSTANTES GLOBALES

//ESTRUCTURAS / ENUMS/ TYPEDEFS
struct t_lectura{
	char tipo[11];
	int monto;
};
//DECLARACIONES DE FUNCIONES (prototipos)
void read_file();
void write_file();
//FUNCION PRINCIPAL
int main(){
	write_file();
	read_file();
	cout << "Hello, world!!" << endl;
	return 0;
}

//DEFINICIONES
void write_file(){
	FILE* outfile = fopen("utils/file.dat","wb");
	t_lectura escritura;
	for(size_t i = 0;i<2;i++){
		cout << "Ingrese el tipo (manual/automatico): ";
		cin >> escritura.tipo;
		cout << "Ingrese el monto: ";
		cin >> escritura.monto;
		fwrite(&escritura,sizeof(t_lectura),1,outfile);
	}
	fclose(outfile);
	return;
}
void read_file(){
	FILE* infile =fopen("utils/file.dat","rb");
	t_lectura lectura;
	fread(&lectura,sizeof(t_lectura),1,infile);
	while(!feof(infile)){
		cout << "Tipo: " << lectura.tipo << " Monto: " << lectura.monto << endl;
		fread(&lectura,sizeof(t_lectura),1,infile);
	}
	fclose(infile);
	return;
}