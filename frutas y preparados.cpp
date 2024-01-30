#include <iostream>
#include <string>//cadena
using namespace std;

string frutas[]={"manzana", "banana", "naranja", "fresa", "kiwi", "mango", "pera", "melon", "papaya", "uva"};
string preparados[]={"jugo", "ensalada", "frape", "tarta", "helado", "mermelada", "batido", "asado", "coctel", "crudo"};
string fruta[5];
string preparado[5];

string generarFruta()
{
	return frutas[rand()%10];
}	
string generarPreparado()
{
	return preparados[rand()%10];
}
void generar(){
	for(int i=0;i<5;i++)
	{
		fruta[i]=generarFruta();
		preparado[i]=generarPreparado();
	}
}
void imprimir()
{
	cout<<"menu de productos"<<endl;
	for(int i=0;i<5;i++)
		cout<<preparado[i]<<" de "<<fruta[i]<<endl;
}
	
int main(int argc, char *argv[]) {
	generar();
	imprimir();
	return 0;
}
	

