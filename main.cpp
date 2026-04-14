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
//4. funciones
    //4.1 se llenan en la fase 2 bro (cuando se pongan este comentario eliminar)


//5. el main
int main(){



    return 0;
}
