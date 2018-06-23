/*
  Archivo: Temporizador.h
  Autor: Ángel García Baños
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2018-02-28
  Fecha última modificación: 2018-03-08
  Versión: 0.1
  Licencia: GPL
*/

/*
  Clase: Temporizador
  Responsabilidad: contiene un hilo que periódicamente (cada 1 seg. u otro tiempo programable) da la orden al Tablero para que baje la Ficha actual. Se puede cambiar ese tiempo.
  Colaboración: 
    - Contiene un hilo (es propietario de él)
    - Conoce el Tablero (no es propietario de él).
*/

#ifndef Temporizador_HH
#define Temporizador_HH

#include "Tablero.h"
#include <thread>
#include <chrono>
using namespace std;


class Temporizador
{
  private:
    Tablero &tablero;
    int milisegundos;
    thread *hilo;
    bool repetir;

  public:
    Temporizador(Tablero &tablero, int milisegundos);
    ~Temporizador();
    void aumentarTiempo();
    void disminuirTiempo();
    void comenzar();
    void finalizar();
    
  protected:
    void funcionPeriodica();
};

#endif