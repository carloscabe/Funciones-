#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

const int TAMANIO = 10;

string nombres[TAMANIO] = {"carlos", "juan", "pedro", "fernanda", "kevin", "manuel", "maria", "eduardo", "pablo", "diana"};
string apellidos[TAMANIO] = {"quispe", "perez", "quiroga", "ochoa", "lopez", "vaca", "montenegro", "soliz", "suarez", "camacho"};
string notas[TAMANIO] = {"15", "71", "36", "97", "90", "37", "59", "89", "79", "88"};
string contrasenas[TAMANIO];

// Función para llenar nombres, apellidos y notas de forma aleatoria sin repeticiones
void llenarAleatoriamente() {
	srand(static_cast<unsigned>(time(0)));
	
	random_shuffle(begin(nombres), end(nombres));
	random_shuffle(begin(apellidos), end(apellidos));
	
	for (int i = 0; i < TAMANIO; ++i) {
		notas[i] = to_string(rand() % 101);
	}
	
	cout << "Nombres y apellidos generados aleatoriamente." << endl;
}

// Función para ofuscar nombres y apellidos para llenar contraseñas
void ofuscarContrasenas() {
	for (int i = 0; i < TAMANIO; ++i) {
		// Concatenar nombres y apellidos y ofuscarlos (por ejemplo, invertir)
		string nombreApellido = nombres[i] + apellidos[i];
		reverse(begin(nombreApellido), end(nombreApellido));
		contrasenas[i] = nombreApellido;
	}
	
	cout << "Se ofuscaron nombres y apellidos para generar ontraseñas." << endl;
}

// Función para calcular la media, el mayor y el menor de las notas
void calcularEstadisticas() {
	double sumaNotas = 0;
	double media;
	int indiceMayor = 0;
	int indiceMenor = 0;
	
	// Convertir las notas a números
	double notasNumeros[TAMANIO];
	for (int i = 0; i < TAMANIO; ++i) {
		notasNumeros[i] = stod(notas[i]);
		sumaNotas += notasNumeros[i];
		
		if (notasNumeros[i] > notasNumeros[indiceMayor]) {
			indiceMayor = i;
		}
		
		if (notasNumeros[i] < notasNumeros[indiceMenor]) {
			indiceMenor = i;
		}
	}
	
	media = sumaNotas / TAMANIO;
	
	// Mostrar tabla con estadísticas
	cout << "Promedio de nota es: " << fixed << setprecision(2) << media << endl;
	cout << "Mayor" << endl;
	cout << setw(20) << left << nombres[indiceMayor] + " " + apellidos[indiceMayor] << setw(10) << left << notas[indiceMayor] << setw(20) << left << contrasenas[indiceMayor] << endl;
	cout << "Menor" << endl;
	cout << setw(20) << left << nombres[indiceMenor] + " " + apellidos[indiceMenor] << setw(10) << left << notas[indiceMenor] << setw(20) << left << contrasenas[indiceMenor] << endl;
}

// Función para mostrar la tabla solo con las columnas "NOMBRE" y "APELLIDO"
void mostrarTablaNombreApellido() {
	cout << setw(20) << left << "NOMBRE" << setw(20) << left << "APELLIDO" << endl;
	cout << setfill('-') << setw(40) << "" << setfill(' ') << endl;
	
	for (int i = 0; i < TAMANIO; ++i) {
		cout << setw(20) << left << nombres[i] << setw(20) << left << apellidos[i] << endl;
	}
}

// Función para mostrar la tabla con los datos, incluyendo la columna "CONTRASEÑA"
void mostrarTablaCompleta() {
	cout << setw(20) << left << "NOMBRE" << setw(20) << left << "APELLIDO" << setw(20) << left << "CONTRASEÑA" << setw(10) << left << "NOTA" << endl;
	cout << setfill('-') << setw(70) << "" << setfill(' ') << endl;
	
	for (int i = 0; i < TAMANIO; ++i) {
		cout << setw(20) << left << nombres[i] << setw(20) << left << apellidos[i] << setw(20) << left << contrasenas[i] << setw(10) << left << notas[i] << endl;
	}
}

// Función para imprimir datos (igual que la opción 2)
void imprimirDatos() {
	cout << setw(20) << left << "NOMBRE" << setw(20) << left << "APELLIDO" << setw(20) << left << "CONTRASEÑA" << setw(10) << left << "NOTA" << endl;
	cout << setfill('-') << setw(70) << "" << setfill(' ') << endl;
	
	for (int i = 0; i < TAMANIO; ++i) {
		cout << setw(20) << left << nombres[i] << setw(20) << left << apellidos[i] << setw(20) << left << contrasenas[i] << setw(10) << left << notas[i] << endl;
	}
}

int main() {
	int opcion;
	
	do {
		cout << "Menu Trabajo Practico 4" << endl;
		cout << "(1) - Llenar nombres, apellidos y notas de forma aleatoria." << endl;
		cout << "(2) - Ofuscar nombres y apellidos para llenar las contrasenas. " << endl;
		cout << "(3) - Sacar la media, el mayor y menor de todas las notas. " << endl;
		cout << "(4) - Imprimir datos." << endl;
		cout << "(0) - Salir." << endl;
		cout << "Ingrese su opción: ";
		cin >> opcion;
		
		switch (opcion) {
			
		case 1:
			system("cls");
			llenarAleatoriamente();
			mostrarTablaNombreApellido();  // Muestra la tabla solo con las columnas "NOMBRE" y "APELLIDO"
			break;
			
		case 2:
			system("cls");
			ofuscarContrasenas();
			mostrarTablaCompleta();  // Muestra la tabla completa con la columna "CONTRASEÑA"
			break;
		case 3:
			system("cls");
			calcularEstadisticas();
			break;
		case 4:
			system("cls");
			imprimirDatos();  // Imprime la tabla con los mismos datos que la opción 2
			break;
		case 0:
			cout << "Saliendo del programa. ¡Hasta luego!" << endl;
			break;
		default:
			cout << "Opción no válida. Intente nuevamente." << endl;
		}
	} while (opcion != 0);
	
	return 0;
}
