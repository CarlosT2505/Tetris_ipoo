/*
╔═══════════════════════════════════════════════════════╦═════════════════╦════════════════╗
║                Archivo: ConstructorDeFichas.h         ║   Versión 1.0   ║  Licencia GPL  ║
╠═══════════════════════╦══════╦════╦════╦══════════════╩═════════════════╬══════╦════╦════╣
║  Fecha de creación:   ║ 2018 ║ 05 ║ 15 ║   Fecha última modificación:   ║ 2018 ║ 06 ║ 03 ║ 
╠═══════════════════════╩══════╩════╩════╩════════════════════════════════╩══════╩════╩════╣
╠══════════╦═════════════════════════════════╦═════════════════════════════════════════════╣
║          ║ Sara Jazmín Maradiago Calderón  ║ sara.maradiago@correounivalle.edu.co        ║
║ Autores: ╠═════════════════════════════════╬═════════════════════════════════════════════╣
║          ║ Carlos Maurico Tovar Parra      ║ carlos.mauricio.tovar@correounivalle.edu.co ║
╚══════════╩═════════════════════════════════╩═════════════════════════════════════════════╝

╔═════════════════════════════════════════════════════════════════════════════╗
║                         Clase: ConstructorDeFichas                          ║
╠══════════════════════════════════════╦══════════════════════════════════════╣
║           Responsabilidad            ║            Colaboración              ║
╠══════════════════════════════════════╬══════════════════════════════════════╣
║Genera fichas al azar entre los tipos ║Contiene: Ficha                       ║
║de ficha especìficados:               ║                                      ║
║                                      ║                                      ║
║ 1.Tetriminó O:       2.Tetriminó I:  ║                                      ║
║   0-1-1-0              0-2-0-0       ║                                      ║
║   0-1-1-0              0-2-0-0       ║                                      ║
║   0-0-0-0              0-2-0-0       ║                                      ║
║   1-1-0-0              0-2-0-0       ║                                      ║
║                                      ║                                      ║
║ 3.Tetriminó T:       4.Tetriminó S:  ║                                      ║
║   0-3-0-0              0-4-4-0       ║                                      ║
║   3-3-3-0              4-4-0-0       ║                                      ║
║   0-0-0-0              0-0-0-0       ║                                      ║
║   0-0-0-0              0-0-0-0       ║                                      ║
║                                      ║                                      ║
║ 5.Tetriminó Z:       6.Tetriminó L:  ║                                      ║
║   5-5-0-0              0-6-0-0       ║                                      ║
║   0-5-5-0              0-6-0-0       ║                                      ║
║   0-0-0-0              0-6-6-0       ║                                      ║
║   0-0-0-0              0-0-0-0       ║                                      ║
║                                      ║                                      ║
║ 7.Tetriminó J:                       ║                                      ║
║   0-0-7-0                            ║                                      ║
║   0-0-7-0                            ║                                      ║
║   0-7-7-0                            ║                                      ║
║   0-0-0-0                            ║                                      ║ 
╚══════════════════════════════════════╩══════════════════════════════════════╝
*/

#ifndef ConstructorDeFichas_HH
#define ConstructorDeFichas_HH
#include "Ficha.h"
#include<stdlib.h>
#include <iostream>
using namespace std;

class ConstructorDeFichas
{
  private:
  
    int lasFichas [7][4][4]={
                              {
                                {0,1,1,0},
                                {0,1,1,0},
                                {0,0,0,0},
                                {0,0,0,0}
                              },
                              {
                                {0,2,0,0},
                                {0,2,0,0},
                                {0,2,0,0},
                                {0,2,0,0}
                              },
                              {
                                {0,3,0,0},
                                {3,3,3,0},
                                {0,0,0,0},
                                {0,0,0,0}
                              },
                              {
                                {0,4,4,0},
                                {4,4,0,0},
                                {0,0,0,0},
                                {0,0,0,0}
                              },
                              {
                                {5,5,0,0},
                                {0,5,5,0},
                                {0,0,0,0},
                                {0,0,0,0}
                              },
                              {
                                {0,6,0,0},
                                {0,6,0,0},
                                {0,6,6,0},
                                {0,0,0,0}
                              },
                              {
                                {0,0,7,0},
                                {0,0,7,0},
                                {0,7,7,0},
                                {0,0,0,0}
                              }
                            };
                            
  public:
  
    ConstructorDeFichas();
  
    Ficha *generarFicha();
};

#endif