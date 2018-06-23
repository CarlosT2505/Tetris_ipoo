/*
╔═══════════════════════════════════════════════════════╦═════════════════╦════════════════╗
║                Archivo: ConstructorDeFichas.cpp       ║   Versión 1.0   ║  Licencia GPL  ║
╠═══════════════════════╦══════╦════╦════╦══════════════╩═════════════════╬══════╦════╦════╣
║  Fecha de creación:   ║ 2018 ║ 05 ║ 15 ║   Fecha última modificación:   ║ 2018 ║ 06 ║ 03 ║ 
╠═══════════════════════╩══════╩════╩════╩════════════════════════════════╩══════╩════╩════╣
╠══════════╦═════════════════════════════════╦═════════════════════════════════════════════╣
║          ║ Sara Jazmín Maradiago Calderón  ║ sara.maradiago@correounivalle.edu.co        ║
║ Autores: ╠═════════════════════════════════╬═════════════════════════════════════════════╣
║          ║ Carlos Maurico Tovar Parra      ║ carlos.mauricio.tovar@correounivalle.edu.co ║
╚══════════╩═════════════════════════════════╩═════════════════════════════════════════════╝
*/

#include "ConstructorDeFichas.h"
#include <iostream>
using namespace std;

ConstructorDeFichas::ConstructorDeFichas()
{
  
}

Ficha *ConstructorDeFichas::generarFicha()
{
    int estaFicha = (rand()%7);
    Ficha *nuevaFicha = new Ficha(lasFichas[estaFicha]);
    return nuevaFicha;
}