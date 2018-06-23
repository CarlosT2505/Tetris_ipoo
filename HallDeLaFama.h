/*
╔═══════════════════════════════════════════════════════╦═════════════════╦════════════════╗
║                Archivo: HallDeLaFama.h                ║   Versión 1.0   ║  Licencia GPL  ║
╠═══════════════════════╦══════╦════╦════╦══════════════╩═════════════════╬══════╦════╦════╣
║  Fecha de creación:   ║ 2018 ║ 02 ║ 24 ║   Fecha última modificación:   ║ 2018 ║ 05 ║ 18 ║ 
╠═══════════════════════╩══════╩════╩════╩════════════════════════════════╩══════╩════╩════╣
╠══════════╦═════════════════════════════════╦═════════════════════════════════════════════╣
║          ║ Sara Jazmín Maradiago Calderón  ║ sara.maradiago@correounivalle.edu.co        ║
║ Autores: ╠═════════════════════════════════╬═════════════════════════════════════════════╣
║          ║ Carlos Maurico Tovar Parra      ║ carlos.mauricio.tovar@correounivalle.edu.co ║
╚══════════╩═════════════════════════════════╩═════════════════════════════════════════════╝

╔═════════════════════════════════════════════════════════════════════════════╗
║                             Clase: HallDeLaFama                             ║
╠══════════════════════════════════════╦══════════════════════════════════════╣
║           Responsabilidad            ║            Colaboración              ║
╠══════════════════════════════════════╬══════════════════════════════════════╣
║Mantener un archivo en disco con la   ║Posee un archivo, es propietario del  ║
║lista de los 10 mejores ganadores y   ║archivo, de modo que se encarga de    ║
║sus puntajes. Debe crearlo si no      ║cerrarlo en el destructor.            ║
║existe, actualizarlo y salvarlo.      ║                                      ║
║Y debe mantenerlo ordenado de mayor a ║                                      ║
║menor puntajes. Se le puede pedir que ║                                      ║
║retorne la lista de ganadores y       ║                                      ║
║puntajes.                             ║                                      ║
╚══════════════════════════════════════╩══════════════════════════════════════╝
*/

#ifndef HallDeLaFama_HH
#define HallDeLaFama_HH
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class HallDeLaFama
{
  private:
  
    string archivo;
    
    string ganadores[10];
    
    int puntos[10];
    
    int numeroDeGanadores;
    
  public:
  
    HallDeLaFama(string archivo="LosGanadoresDelTetris.txt");
    
    ~HallDeLaFama();
    
    void nuevoGanador(string nombre, int puntaje);

    string listaDeGanadores();
    
    void ordenar();
};

#endif