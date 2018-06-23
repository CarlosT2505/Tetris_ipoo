/*
╔═══════════════════════════════════════════════════════╦═════════════════╦════════════════╗
║                Archivo: Ficha.cpp                     ║   Versión 1.0   ║  Licencia GPL  ║
╠═══════════════════════╦══════╦════╦════╦══════════════╩═════════════════╬══════╦════╦════╣
║  Fecha de creación:   ║ 2018 ║ 02 ║ 28 ║   Fecha última modificación:   ║ 2018 ║ 06 ║ 13 ║ 
╠═══════════════════════╩══════╩════╩════╩════════════════════════════════╩══════╩════╩════╣
╠══════════╦═════════════════════════════════╦═════════════════════════════════════════════╣
║          ║ Sara Jazmín Maradiago Calderón  ║ sara.maradiago@correounivalle.edu.co        ║
║ Autores: ╠═════════════════════════════════╬═════════════════════════════════════════════╣
║          ║ Carlos Maurico Tovar Parra      ║ carlos.mauricio.tovar@correounivalle.edu.co ║
╚══════════╩═════════════════════════════════╩═════════════════════════════════════════════╝
*/

#include "Ficha.h"
#include<iostream>
using namespace std;

Ficha::Ficha(int casillas[4][4])
{
  for(int fila=0; fila<4; fila++)
  {
    for(int columna=0; columna<4; columna++)
    {
      this->casillas[fila][columna] = casillas[fila][columna];
    }
  }
}

Ficha *Ficha::rotarComoReloj()
{
  int fichaRotada[4][4];
  Ficha *laFichaRotada=new Ficha(fichaRotada);
  for(int fila=0; fila<4; fila++)
  {
    for(int columna=0; columna<4; columna++)
    {
      laFichaRotada->casillas[columna][fila] = this->casilla(3-fila, columna); 
    }
  }
  return laFichaRotada;
}

int Ficha::casilla(int fila, int columna)
{
  if(fila < 0 or fila > 3 or columna < 0 or columna > 3)
  {
    return 0;  
  }
  return casillas[fila][columna];
}