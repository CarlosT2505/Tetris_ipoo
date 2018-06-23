/*
╔═══════════════════════════════════════════════════════╦═════════════════╦════════════════╗
║                Archivo: Tablero.h                     ║   Versión 1.0   ║  Licencia GPL  ║
╠═══════════════════════╦══════╦════╦════╦══════════════╩═════════════════╬══════╦════╦════╣
║  Fecha de creación:   ║ 2018 ║ 02 ║ 24 ║   Fecha última modificación:   ║ 2018 ║ 06 ║ 15 ║ 
╠═══════════════════════╩══════╩════╩════╩════════════════════════════════╩══════╩════╩════╣
╠══════════╦═════════════════════════════════╦═════════════════════════════════════════════╣
║          ║ Sara Jazmín Maradiago Calderón  ║ sara.maradiago@correounivalle.edu.co        ║
║ Autores: ╠═════════════════════════════════╬═════════════════════════════════════════════╣
║          ║ Carlos Maurico Tovar Parra      ║ carlos.mauricio.tovar@correounivalle.edu.co ║
╚══════════╩═════════════════════════════════╩═════════════════════════════════════════════╝
╔═════════════════════════════════════════════════════════════════════════════╗
║                                Clase: Tablero                               ║
╠══════════════════════════════════════╦══════════════════════════════════════╣
║           Responsabilidad            ║            Colaboración              ║
╠══════════════════════════════════════╬══════════════════════════════════════╣
║Es donde se relacionan todas las      ║Contiene: Ficha                       ║
║clases que intervienen en el          ║Contiene: Jugador                     ║
║funcionamiento del juego.             ║Contiene: DispositivoEntradaSalida    ║
║                                      ║Contiene: ConstructorDeFichas         ║
║                                      ║Contiene: HallDeLaFama                ║
╚══════════════════════════════════════╩══════════════════════════════════════╝
*/

#ifndef Tablero_HH
#define Tablero_HH
#include "Ficha.h"
#include "DispositivoEntradaSalida.h"
#include "Jugador.h"
#include "ConstructorDeFichas.h"
#include "HallDeLaFama.h"
#include <iostream>
using namespace std;


class Tablero
{
  private:
    int casillas[20][10];
    
    DispositivoEntradaSalida *entradaSalida;
    
    Jugador *jugador;
    
    ConstructorDeFichas *constructor;
    
    bool finDelJuego;
    
    HallDeLaFama *halldelafama;
    
    Ficha *fichaActual;
    
    Ficha *fichaSiguiente;
    
    int fila;
    
    int columna;
    
  public:
    Tablero(DispositivoEntradaSalida *entradaSalida, Jugador *jugador, ConstructorDeFichas *constructor, HallDeLaFama *halldelafama);
    
    bool ponerFicha();
    
    void eliminarFilasCompletas();
    
    void quitarFicha();
    
    void moverFichaHaciaAbajo();
    
    void moverFichaHaciaLaIzquierda();
    
    void moverFichaHaciaLaDerecha();
    
    void rotarFicha();
    
    void jugar();
    
    void enJuego();
    
    void imprimirSiguienteFicha();
    
  protected:
    void seHaMovidoLaFicha();
    
};

#endif