//1. Librerias 
#include <iostream>
#include <string>
#include <ctime>
//2. contantes
const int filas=16;
const int columnas=16;
const int MaxVehiculos=50;
const double TarifaHora=3000.0;
//3. funcion vehiculo - datos de cada vehiculo, placa, hora de entrada, fila, columna, activo o no
struct Vehiculo{
    std::string placa;
    time_t horaEntrada;
    int fila;
    int columna;
    bool activo; // true = está parqueado | false = libre
};
//4. funciones - se implementan en fases posteriores
void inicializarMapa(char mapa[filas][columnas]){
    // Recorrer toda la matriz
    for (int i=0;i<filas;i++){
        for (int j=0;j<columnas;j++){
            // Si la fila es multiplo de 3, o es borde lateral = via
            if (i%3==0||j==0||j==columnas-1){
                mapa[i][j]='.';
            }else{
                //lo demas espacio para parquear
                mapa[i][j]='P';
            }
        }
    }
    // Entrada arriba izquierda, salida abajo derecha
    mapa[0][0]='E';
    mapa[filas-1][columnas-1]='S';
}
void mostrarMapa(char mapa[filas][columnas]){
    // recorrer el mapa
    for (int i=0;i<filas;i++) {
        for (int j=0;j<columnas;j++){
            // mostrar el mapa
            std::cout<<mapa[i][j]<<" ";
        }
        std::cout<<"\n";
    }
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
    // preparar el mapa para mostrarlo al usuario
    inicializarMapa(mapa);
    do {
        std::cout<<"\n===== PARQUEADERO ====="<<std::endl;
        std::cout<<"1.Ver mapa"<<std::endl;
        std::cout<<"2.Registrar ingreso"<<std::endl;
        std::cout<<"3.Registrar salida"<<std::endl;
        std::cout<<"0. Salir"<<std::endl;
        std::cout<<"Opcion:";
        std::cin>>opcion;
        //mostrar el menu 
        switch (opcion){
            case 1:mostrarMapa(mapa);
            break;
            case 2:registrarIngreso(mapa,vehiculos,&contador);
            break;
            case 3:registrarSalida(mapa,vehiculos,contador);
            break;
            case 0:std::cout<<"Hasta luego!"<<std::endl;
            break;
            default:std::cout<<"Opcion invalida."<<std::endl;
        }
    } while (opcion!=0);
    return 0;
}
