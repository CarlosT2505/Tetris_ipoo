/*
╔═══════════════════════════════════════════════════════╦═════════════════╦════════════════╗
║                  Archivo: Main.cpp                    ║   Versión 1.0   ║  Licencia GPL  ║
╠═══════════════════════╦══════╦════╦════╦══════════════╩═════════════════╬══════╦════╦════╣
║  Fecha de creación:   ║ 2018 ║ 03 ║ 20 ║   Fecha última modificación:   ║ 2018 ║ 06 ║ 15 ║ 
╠═══════════════════════╩══════╩════╩════╩════════════════════════════════╩══════╩════╩════╣
╠══════════╦═════════════════════════════════╦═════════════════════════════════════════════╣
║          ║ Sara Jazmín Maradiago Calderón  ║ sara.maradiago@correounivalle.edu.co        ║
║ Autores: ╠═════════════════════════════════╬═════════════════════════════════════════════╣
║          ║ Carlos Maurico Tovar Parra      ║ carlos.mauricio.tovar@correounivalle.edu.co ║
╚══════════╩═════════════════════════════════╩═════════════════════════════════════════════╝
*/

#include "DispositivoEntradaSalida.h"
#include "DispositivoTerminal.h"
#include "ConstructorDeFichas.h"
#include "Tablero.h"
#include "Jugador.h"
#include "Ficha.h"
#include "HallDeLaFama.h"
#include "Temporizador.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
  while(true)
  {
    srand((unsigned)time(0));
    DispositivoEntradaSalida *elJuego = new DispositivoTerminal;
    Jugador *elJugador = new Jugador(elJuego);
    ConstructorDeFichas *elConstructor= new ConstructorDeFichas;
    HallDeLaFama *elHall = new HallDeLaFama("LosGanadoresDelTetris.txt");
    Tablero elTablero(elJuego, elJugador, elConstructor, elHall);
    Temporizador elTic(elTablero, 600);
    string elNombre= elJugador->recibirNombre();
    elTic.comenzar();
    elTablero.enJuego();
    elTic.finalizar();
    if(not elJuego->leerSiVolverAJugar())
    {
      delete elJuego;
      elJuego=0;
      delete elJugador;
      elJugador=0;
      delete elConstructor;
      elConstructor=0;
      delete elHall;
      elHall=0;
      break;
    }
    delete elJuego;
    elJuego=0;
    delete elJugador;
    elJugador=0;
    delete elConstructor;
    elConstructor=0;
    delete elHall;
    elHall=0;
  }
  return 0;
}