/*
╔═══════════════════════════════════════════════════════╦═════════════════╦════════════════╗
║                Archivo: Tablero.cpp                   ║   Versión 1.0   ║  Licencia GPL  ║
╠═══════════════════════╦══════╦════╦════╦══════════════╩═════════════════╬══════╦════╦════╣
║  Fecha de creación:   ║ 2018 ║ 03 ║ 20 ║   Fecha última modificación:   ║ 2018 ║ 06 ║ 15 ║ 
╠═══════════════════════╩══════╩════╩════╩════════════════════════════════╩══════╩════╩════╣
╠══════════╦═════════════════════════════════╦═════════════════════════════════════════════╣
║          ║ Sara Jazmín Maradiago Calderón  ║ sara.maradiago@correounivalle.edu.co        ║
║ Autores: ╠═════════════════════════════════╬═════════════════════════════════════════════╣
║          ║ Carlos Maurico Tovar Parra      ║ carlos.mauricio.tovar@correounivalle.edu.co ║
╚══════════╩═════════════════════════════════╩═════════════════════════════════════════════╝
*/

#include "Tablero.h"

Tablero::Tablero(DispositivoEntradaSalida *entradaSalida, Jugador *jugador, ConstructorDeFichas *constructor, HallDeLaFama *halldelafama)
{
  this->entradaSalida = entradaSalida;
  this->jugador = jugador;
  this->constructor = constructor;
  this->halldelafama = halldelafama;
  this->fichaActual = constructor->generarFicha();
  this->fichaSiguiente = constructor->generarFicha();
  this->fila = 0;
  this->columna = 3;
  imprimirSiguienteFicha();
  finDelJuego=false;
  for(int filas=0; filas<20; filas++)
    for(int columnas=0; columnas<10; columnas++)
      casillas[filas][columnas] = 0;
}

bool Tablero::ponerFicha()
{
 for(int comprobarFila=0; comprobarFila<4; comprobarFila++)
  {
    for(int comprobarColumna=0; comprobarColumna<4; comprobarColumna++)
    {
      if(fichaActual->casilla(comprobarFila,comprobarColumna)!=0)
      {
        if((fila+comprobarFila<0)or(columna+comprobarColumna<0)or(columna+comprobarColumna>=10)or(fila+comprobarFila>=20)or(casillas[fila+comprobarFila][columna+comprobarColumna]!=0))
        {
            return false;  
        }
      }
    }
  }
  for(int filaFicha=0; filaFicha<4; filaFicha++)
  {
    for(int columnaFicha=0; columnaFicha<4; columnaFicha++)
    {
      if(fichaActual->casilla(filaFicha, columnaFicha)!=0)
      {
          casillas[filaFicha+fila][columnaFicha+columna]=fichaActual->casilla(filaFicha, columnaFicha); 
      }
    }
  }
  return true;
}

void Tablero::eliminarFilasCompletas()
{
  int filasEliminadas=0;
  for(int filaTablero=0; filaTablero<20; filaTablero++)
  {
    int casillasLlenas=0;
    for(int columnaTablero=0; columnaTablero<10; columnaTablero++)
    {
      if(casillas[filaTablero][columnaTablero]!=0)
      {
        casillasLlenas++;
      }
    }
    if(casillasLlenas==10)
    {
      filasEliminadas++;
      for(int limpiarArriba=filaTablero; limpiarArriba>=0; limpiarArriba--)
      {
        for(int elementoQueEliminar=0; elementoQueEliminar<10; elementoQueEliminar++)
        {
          casillas[limpiarArriba][elementoQueEliminar] = casillas[limpiarArriba-1][elementoQueEliminar];
          casillas[0][elementoQueEliminar] = 0;
        } 
      }
    }
  }
    entradaSalida->imprimirPuntos(jugador->aumentarPuntos(filasEliminadas));
}

void Tablero::quitarFicha()
{
  for(int comprobarFila=0; comprobarFila<4; comprobarFila++)
  {
    for(int comprobarColumna=0; comprobarColumna<4; comprobarColumna++)
    {
      if(fichaActual->casilla(comprobarFila,comprobarColumna)!=0)
      {
        casillas[fila+comprobarFila][columna+comprobarColumna]=0;
      }
    }
  }
}

void Tablero::moverFichaHaciaAbajo()
{
  quitarFicha();
  fila++;
  if(not ponerFicha())
  {
    fila--;
    ponerFicha();
    if(fila==0)
    {
      finDelJuego=true;
      return; 
    }
    fichaActual=fichaSiguiente;
    fichaSiguiente=constructor->generarFicha();
    fila=0;
    columna=3;
    imprimirSiguienteFicha();
    eliminarFilasCompletas();
  }
  else
  {
    seHaMovidoLaFicha(); 
  }
}

void Tablero::moverFichaHaciaLaIzquierda()
{
  quitarFicha();
  columna--;
  if(not ponerFicha())
  {
    columna++;
    ponerFicha();
  }
  else
    seHaMovidoLaFicha();
}

void Tablero::moverFichaHaciaLaDerecha()
{
  quitarFicha();
  columna++;
  if(not ponerFicha())
  {
    columna--;
    ponerFicha();
  }
  else
    seHaMovidoLaFicha();
}

void Tablero::rotarFicha()
{
  quitarFicha();
  Ficha *fichaTemporal=fichaActual;
  this->fichaActual=fichaActual->rotarComoReloj();
  if(!ponerFicha())
  {
    this->fichaActual=fichaTemporal;
  }
}

void Tablero::jugar()
{
  switch(entradaSalida->leerJugada())
  {
    case 1:
      rotarFicha();
      break;
    case 2:
      moverFichaHaciaAbajo();
      break;
    case 3:
      moverFichaHaciaLaDerecha();
      break;
    case 4:
      moverFichaHaciaLaIzquierda();
      break;
  }
}

void Tablero::enJuego()
{
  while(!finDelJuego)
  {
    jugar();
  }
  halldelafama->nuevoGanador(jugador->dimeTuNombre(), jugador->aumentarPuntos(0));
  entradaSalida->imprimirGanadores(halldelafama->listaDeGanadores());
}

void Tablero::imprimirSiguienteFicha()
{
  for(int fila=0; fila<4; fila++)
  {
    for(int columna=0; columna<4; columna++)
    {
      entradaSalida->imprimirFichaSiguiente(fila, columna, fichaSiguiente->casilla(fila, columna));
    }
  }
}

void Tablero::seHaMovidoLaFicha()
{
  for (int filas =0; filas<20; filas++)
  {
    for (int columnas=0; columnas<10; columnas++)
    {
      entradaSalida->imprimirTablero(filas, columnas, casillas[filas][columnas]); 
    }
  }
}