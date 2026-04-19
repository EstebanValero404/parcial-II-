//1.Librerias 
#include <iostream>
#include <string>
#include <ctime>
//2.contantes
const int filas=16;
const int columnas=16;
const int MaxVehiculos=150;
const double TarifaHora=3000.0;
//3. funcion vehiculo - datos de cada vehiculo, placa, hora de entrada, fila, columna, activo o no
struct Vehiculo {
    std::string placa;
    time_t horaEntrada;
    int fila;
    int columna;
    bool activo;//true=está parqueado y false=libre
};
//4.funciones-se implementan en fases anteriores
void inicializarMapa(char mapa[filas][columnas]) {
    // Recorrer toda la matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            // Si la fila es multiplo de 3, o es borde lateral = via
            if (i % 3 == 0 || j == 0) {
                mapa[i][j] = '.';
            } else {
                // lo demas espacio para parquear
                mapa[i][j] = 'P';
            }
        }
    }
    // Entrada arriba izquierda, salida abajo derecha
    mapa[0][0] = 'E';
    mapa[filas - 1][columnas - 1] = 's';
}
void mostrarMapa(char mapa[filas][columnas]) {
     //ver que espacios hay libres
    int libres=0;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(mapa[i][j]=='P'){
                libres=libres+1;
            }
        }
    }
    //mostrar los cupos libres 
    std::cout<<"Espacios disponibles: "<<libres<<"/"<<MaxVehiculos<<std::endl;
    //darle el color a cada espacio
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(mapa[i][j]=='P'){
                // verde para espacios libres
                std::cout<<"\033[32m"<<mapa[i][j]<<"\033[0m"<<' ';
            }else if(mapa[i][j]=='X'){
                // rojo para espacios ocupados
                std::cout<<"\033[31m"<<mapa[i][j]<<"\033[0m"<<' ';
            }else if(mapa[i][j]=='E' || mapa[i][j]=='S'){
                //cian para entrada y salida
                std::cout<<"\033[36m"<<mapa[i][j]<<"\033[0m"<<' ';
            }else{
                //amarillo para las vias
                std::cout<<"\033[33m"<<mapa[i][j]<<"\033[0m" <<' ';
            }
        }
        std::cout<<std::endl;
    }
}
void registrarIngreso(char mapa[filas][columnas],Vehiculo*vehiculos,int*contador){
    //Verificar que no este lleno el parqueadero
    if (*contador>=MaxVehiculos){
        std::cout<<"Parqueadero lleno."<<std::endl;
        return;
    }
    //pedir la placa
    std::string placa;
    std::cout<<"Ingrese la placa del vehiculo: ";
    std::cin>>placa;
    //verificar que pues ya no este dentro del parqueadero el vehiculo 
    for (int i=0;i<*contador;i++){
        if(vehiculos[i].activo && vehiculos[i].placa==placa){
            std::cout<<"Ese vehiculo ya esta en el parqueadero."<<std::endl;
            return;
        }
    }
    //buscar espacio libre osea una "P" libre 
    int filaLibre=-1;
    int columnaLibre=-1;
    for (int i=0;i<filas;i++){
        for (int j=0;j<columnas;j++){
            if (mapa[i][j]=='P'){
                filaLibre=i;
                columnaLibre=j;
                break;
            }
        }
        if(filaLibre!=-1){
            break;
        }
    }
    //si no encontro espacio libre entonces:
    if (filaLibre==-1){
        std::cout<<"No hay espacios disponibles."<<std::endl;
        return;
    }
    //guardar los datos del vehiculo
    vehiculos[*contador].placa=placa;
    vehiculos[*contador].horaEntrada=time(0);//empieza a correr el tiempo aqui 
    vehiculos[*contador].fila=filaLibre;
    vehiculos[*contador].columna=columnaLibre;
    vehiculos[*contador].activo=true;
    //marcar el espacio en el mapa y sumar al contador (se marca con una X)
    mapa[filaLibre][columnaLibre]='X';
    *contador=*contador+1;
    //mostrarle al usuario como quedo el registro
    std::cout<<"Vehiculo "<<placa<<" registrado en ["
         <<filaLibre<<"]["<<columnaLibre<<"]"<<std::endl;
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
        std::cout << "\n===== PARQUEADERO =====" << std::endl;
        std::cout << "1. Ver mapa"              << std::endl;
        std::cout << "2. Registrar ingreso"     << std::endl;
        std::cout << "3. Registrar salida"      << std::endl;
        std::cout << "0. Salir"                 << std::endl;
        std::cout << "Opcion: ";
        std::cin  >> opcion;
          // mostrar el menu 
        switch (opcion) {
            case 1: mostrarMapa(mapa);                            
             break;
            case 2: registrarIngreso(mapa, vehiculos,&contador);   
            break;
        }
    } while (opcion != 0);
    return 0;
}
