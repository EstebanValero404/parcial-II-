//1. Librerias 
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
//2. contantes
const int filas=16;
const int columnas=16;
const int MaxVehiculos=50;
const double TarifaHora=3000.0;
//3. funcion vehiculo - datos de cada vehiculo, placa, hora de entrada, fila, columna, activo o no
struct Vehiculo {
    string placa;
    time_t horaEntrada;
    int fila;
    int columna;
    bool  activo; // true = está parqueado | false = libre
};
//4. funciones - se implementan en fases posteriores
void inicializarMapa(char mapa[filas][columnas]) {
    // fase 2
}

void mostrarMapa(char mapa[filas][columnas]) {
    // fase 2
}

void registrarIngreso(char mapa[filas][columnas], Vehiculo *vehiculos, int *contador) {
    // fase 3
}

void registrarSalida(char mapa[filas][columnas], Vehiculo *vehiculos, int contador) {
    // fase 4
}

double calcularCobro(time_t horaEntrada, time_t horaSalida) {
    // fase 4
    return 0.0;
}
    
//5. el main
int main() {

    // mapa del parqueadero como matriz de caracteres
    char mapa[filas][columnas];

    // arreglo con todos los vehiculos que estan adentro
    Vehiculo vehiculos[MaxVehiculos];

    // cuantos vehiculos hay actualmente en el parqueadero
    int contador = 0;

    // opcion que elige el usuario en el menu
    int opcion;

    // preparar el mapa antes de usarlo
    inicializarMapa(mapa);

    do {
        cout << "\n===== PARQUEADERO =====" << endl;
        cout << "1. Ver mapa"              << endl;
        cout << "2. Registrar ingreso"     << endl;
        cout << "3. Registrar salida"      << endl;
        cout << "0. Salir"                 << endl;
        cout << "Opcion: ";
        cin  >> opcion;

        switch (opcion) {
            case 1: mostrarMapa(mapa);                            break;
            case 2: registrarIngreso(mapa, vehiculos, &contador); break;
            case 3: registrarSalida(mapa, vehiculos, contador);   break;
            case 0: cout << "Hasta luego!" << endl;               break;
            default: cout << "Opcion invalida." << endl;
        }

    } while (opcion != 0);

    return 0;
}
