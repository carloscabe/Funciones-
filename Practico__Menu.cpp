#include <iostream>   // Librería para entrada y salida estándar
#include <string>     // Librería para el manejo de cadenas de texto
#include <cctype>     // Librería para funciones relacionadas con caracteres (toupper)
#include <cstdlib>    // Librería para funciones del sistema (system)

using namespace std;  // Espacio de nombres estándar de C++, que incluye las funciones y objetos fundamentales

// Función para realizar la suma de una cadena de números ingresada por el usuario
void sumaCadena() {
	system("clear || cls");  // Limpia la pantalla en sistemas Unix/Linux o Windows
	string cadena;
	cout << "Ingrese la cadena con números a sumar: ";
	cin.ignore();  // Ignora cualquier carácter residual en el búfer de entrada
	getline(cin, cadena);
	
	// Variable para almacenar la cadena original
	string cadenaOriginal = cadena;
	
	int suma = 0;
	size_t pos = 0;
	while ((pos = cadena.find('+')) != string::npos) {
		try {
			// Verifica que la cadena antes del operador sea un número
			int numero = stoi(cadena.substr(0, pos));
			// Suma los números y actualiza la cadena para continuar con la siguiente parte
			suma += numero;
			cadena.erase(0, pos + 1);
		} catch (invalid_argument& e) {
			cerr << "Error: Formato de número no válido." << endl;
			return;
		} catch (out_of_range& e) {
			cerr << "Error: Número fuera de rango." << endl;
			return;
		}
	}
	
	try {
		// Verifica que la última parte de la cadena sea un número
		int ultimoNumero = stoi(cadena);
		// Suma el último número en la cadena
		suma += ultimoNumero;
		
		// Verifica que la cadena original solo contenga números y el operador de suma
		for (char c : cadenaOriginal) {
			if (!isdigit(c) && c != '+') {
				cerr << "Error: La cadena debe contener suma.\n";
				return;
			}
		}
		
		// Muestra la cadena original y el resultado de la suma
		cout << "Resultado de la suma para la cadena \"" << cadenaOriginal << "\" = " << suma << endl;
	} catch (invalid_argument& e) {
		cerr << "Error: Formato de número no válido." << endl;
	} catch (out_of_range& e) {
		cerr << "Error: Número fuera de rango." << endl;
	}
}

// Función para invertir e imprimir el nombre completo ingresado por el usuario
void nombreCompleto() {
	system("clear || cls");  // Limpia la pantalla en sistemas Unix/Linux o Windows
	string nombre;
	cout << "Ingrese el nombre completo: ";
	cin.ignore();  // Ignora cualquier carácter residual en el búfer de entrada
	getline(cin, nombre);
	
	size_t posApMat = nombre.find_last_of(' ');
	size_t posApPat = nombre.find_last_of(' ', posApMat - 1);
	
	string apellidoMaterno = nombre.substr(posApMat + 1);
	string apellidoPaterno = nombre.substr(posApPat + 1, posApMat - posApPat - 1);
	string nombres = nombre.substr(0, posApPat);
	
	// Imprime el nombre completo invertido
	cout << "Nombre completo invertido: " << apellidoMaterno << " " << apellidoPaterno << " " << nombres << endl;
}

// Función para ofuscar la cadena ingresada por el usuario, reemplazando ciertos caracteres
void ofuscarCadena() {
	system("clear || cls");  // Limpia la pantalla en sistemas Unix/Linux o Windows
	string cadena;
	cout << "Ingrese la cadena a ofuscar: ";
	cin.ignore();  // Ignora cualquier carácter residual en el búfer de entrada
	getline(cin, cadena);
	
	for (char& c : cadena) {
		switch (toupper(c)) {
		case 'A':
			c = '4';
			break;
		case 'E':
			c = '3';
			break;
		case 'I':
			c = '1';
			break;
		case 'O':
			c = '0';
			break;
		case 'S':
			c = '5';
			break;
		case 'T':
			c = '7';
			break;
		}
	}
	
	// Muestra la cadena ofuscada
	cout << "Cadena ofuscada: " << cadena << endl;
}

int main() {
	char opcion;
	bool salir = false;
	
	do {
		system("clear || cls");  // Limpia la pantalla en sistemas Unix/Linux o Windows
		
		cout << "MENU PRINCIPAL" << endl;
		cout << "1. Operación suma de una cadena." << endl;
		cout << "2. String Nombre completo." << endl;
		cout << "3. String ofuscar." << endl;
		cout << "s/S. Salir" << endl;
		
		cout << "Seleccione una opción: ";
		cin >> opcion;
		
		switch (opcion) {
		case '1':
			sumaCadena();
			break;
		case '2':
			nombreCompleto();
			break;
		case '3':
			ofuscarCadena();
			break;
		case 's':
		case 'S':
			cout << "Saliendo del programa.\n";
			salir = true;
			break;
		default:
			cout << "Opción no válida. Intente de nuevo.\n";
		}
		
		// Esperar a que el usuario presione Enter antes de continuar
		if (!salir) {
			cout << "Presione Enter para continuar...";
			cin.ignore();  // Ignora cualquier carácter residual en el búfer de entrada
			cin.get();
		}
		
	} while (!salir);
	
	return 0;
}
