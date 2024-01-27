#include <iostream> // Biblioteca para entrada/salida estándar (cin, cout)
#include <cctype> // Biblioteca para funciones de manipulación de caracteres (toupper)
using namespace std; // Espacio de nombres estándar para facilitar el uso de cin, cout, etc.

// Declaración de variables globales para almacenar información del nombre completo
string nombreCompleto, nombre, apePat, apeMat;

// Función para separar el nombre completo en partes
void separarNombre()
{
	// Inicialización de variables para las posiciones iniciales y finales
	int pini, pfinal;
	pini = 0;
	
	// Buscar el primer espacio en la cadena
	pfinal = nombreCompleto.find(" ", pini);
	
	// Verificar si se encontró el primer espacio
	if (pfinal != string::npos) {
		cout << "pos: " << pfinal << endl;
		
		// Obtener y formatear el nombre
		nombre = nombreCompleto.substr(pini, pfinal - pini);
		nombre[0] = toupper(nombre[0]);
		
		// Actualizar pini al siguiente caracter después del primer espacio
		pini = pfinal + 1;
		
		// Buscar el segundo espacio
		pfinal = nombreCompleto.find(" ", pini);
		
		// Verificar si se encontró el segundo espacio
		if (pfinal != string::npos) {
			cout << "pos: " << pfinal << endl;
			
			// Obtener y formatear el apellido paterno
			apePat = nombreCompleto.substr(pini, pfinal - pini);
			apePat[0] = toupper(apePat[0]);
			
			// Actualizar pini al siguiente caracter después del segundo espacio
			pini = pfinal + 1;
			
			// Obtener y formatear el apellido materno
			apeMat = nombreCompleto.substr(pini);
			apeMat[0] = toupper(apeMat[0]);
		} else {
			// No se encontró el segundo espacio, el resto es el apellido paterno
			apePat = nombreCompleto.substr(pini);
			apePat[0] = toupper(apePat[0]);
			apeMat = ""; // No hay espacio, por lo que solo hay apellido paterno
		}
	} else {
		// No se encontró el primer espacio, el nombre es la cadena completa
		nombre = nombreCompleto;
		nombre[0] = toupper(nombre[0]);
		apePat = ""; // No hay espacio, por lo que solo hay nombre
		apeMat = ""; // No hay espacio, por lo que solo hay nombre
	}
}

// Función principal del programa
int main()
{
	// Solicitar al usuario que ingrese su nombre completo
	cout << "Ingrese su nombre completo: ";
	getline(cin, nombreCompleto);
	
	// Llamar a la función para separar el nombre completo en partes
	separarNombre();
	
	// Imprimir el nombre y apellidos con la primera letra en mayúscula
	cout << "Nombre: " << nombre << endl;
	cout << "Apellido Paterno: " << apePat << endl;
	cout << "Apellido Materno: " << apeMat << endl;
	
	// Devolver un valor indicando que el programa se ejecutó correctamente
	return 0;
}
