/*
╔═══════════════════════════════════════════════════════╦═════════════════╦════════════════╗
║                Archivo: Jugador.h                     ║   Versión 1.0   ║  Licencia GPL  ║
╠═══════════════════════╦══════╦════╦════╦══════════════╩═════════════════╬══════╦════╦════╣
║  Fecha de creación:   ║ 2018 ║ 03 ║ 08 ║   Fecha última modificación:   ║ 2018 ║ 06 ║ 15 ║ 
╠═══════════════════════╩══════╩════╩════╩════════════════════════════════╩══════╩════╩════╣
╠══════════╦═════════════════════════════════╦═════════════════════════════════════════════╣
║          ║ Sara Jazmín Maradiago Calderón  ║ sara.maradiago@correounivalle.edu.co        ║
║ Autores: ╠═════════════════════════════════╬═════════════════════════════════════════════╣
║          ║ Carlos Maurico Tovar Parra      ║ carlos.mauricio.tovar@correounivalle.edu.co ║
╚══════════╩═════════════════════════════════╩═════════════════════════════════════════════╝

╔═════════════════════════════════════════════════════════════════════════════╗
║                              Clase: Jugador                                 ║
╠══════════════════════════════════════╦══════════════════════════════════════╣
║           Responsabilidad            ║            Colaboración              ║
╠══════════════════════════════════════╬══════════════════════════════════════╣
║Se encarga de realizar jugadas,       ║Contiene: DispositivoEntradaSalida    ║
║recibiendo órdenes de                 ║                                      ║
║DispositivoEntradaSalida y enviándolas║                                      ║
║a Tablero                             ║                                      ║
╚══════════════════════════════════════╩══════════════════════════════════════╝
*/

#ifndef Jugador_HH
#define Jugador_HH
#include <string>
#include <cstdlib>
#include "DispositivoEntradaSalida.h"
using namespace std;

class Jugador
{
  private:
  
    DispositivoEntradaSalida *dispositivo;
  
    string nombre;
    
    int puntos=0;
  
  public:
  
    Jugador(DispositivoEntradaSalida *dispositivo);
  
    string recibirNombre();
  
    string dimeTuNombre();
  
    int aumentarPuntos(int cuantos); 
  
    void reiniciarPuntos();
  
    int leerJugada();
};

#endif