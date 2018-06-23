/*
  Archivo: Temporizador.cpp
  Autor: Ángel García Baños
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2018-03-08
  Fecha última modificación: 2018-03-08
  Versión: 0.1
  Licencia: GPL
*/


#include "Temporizador.h"


Temporizador::Temporizador(Tablero &tablero, int milisegundos) : tablero(tablero), milisegundos(milisegundos)
{
  hilo = 0;
  repetir = true;
}


Temporizador::~Temporizador()
{
  if(hilo)
  {
    hilo->join();
    delete hilo;
  }
  hilo = 0;
}


void Temporizador::aumentarTiempo()
{
  milisegundos *= 2;
  if(milisegundos > 5000)
    milisegundos = 5000;
}


void Temporizador::disminuirTiempo()
{
  milisegundos /= 2;
  if(milisegundos <= 1)
    milisegundos = 1;
}


void Temporizador::comenzar()   
{
  if(hilo)
  {
    hilo->join();
    delete hilo;
  }
  hilo = new thread(&Temporizador::funcionPeriodica, this);
  repetir = true;
}


void Temporizador::finalizar()
{
  repetir = false;
}


void Temporizador::funcionPeriodica()
{
  while(repetir)
  {
    tablero.moverFichaHaciaAbajo();
    this_thread::sleep_for(chrono::milliseconds(milisegundos));
  }
}