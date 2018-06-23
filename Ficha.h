/*
╔═══════════════════════════════════════════════════════╦═════════════════╦════════════════╗
║                Archivo: Ficha.h                       ║   Versión 1.0   ║  Licencia GPL  ║
╠═══════════════════════╦══════╦════╦════╦══════════════╩═════════════════╬══════╦════╦════╣
║  Fecha de creación:   ║ 2018 ║ 02 ║ 28 ║   Fecha última modificación:   ║ 2018 ║ 06 ║ 10 ║ 
╠═══════════════════════╩══════╩════╩════╩════════════════════════════════╩══════╩════╩════╣
╠══════════╦═════════════════════════════════╦═════════════════════════════════════════════╣
║          ║ Sara Jazmín Maradiago Calderón  ║ sara.maradiago@correounivalle.edu.co        ║
║ Autores: ╠═════════════════════════════════╬═════════════════════════════════════════════╣
║          ║ Carlos Maurico Tovar Parra      ║ carlos.mauricio.tovar@correounivalle.edu.co ║
╚══════════╩═════════════════════════════════╩═════════════════════════════════════════════╝

╔═════════════════════════════════════════════════════════════════════════════╗
║                               Clase: Ficha                                  ║
╠══════════════════════════════════════╦══════════════════════════════════════╣
║           Responsabilidad            ║            Colaboración              ║
╠══════════════════════════════════════╬══════════════════════════════════════╣
║Es una de las fichas del juego Tetris,║Ninguna                               ║
║las fichas son tetriminós             ║                                      ║
║representados en matrices 4x4.        ║                                      ║
║Se le puede pedir que rote en el      ║                                      ║
║sentido de las agujas del reloj.      ║                                      ║
╚══════════════════════════════════════╩══════════════════════════════════════╝
*/

#ifndef Ficha_HH
#define Ficha_HH
using namespace std;

class Ficha
{
  private:
  
    int casillas[4][4];
    
  public:
  
    Ficha(int casillas[4][4]);
    
    Ficha *rotarComoReloj();
    
    int casilla(int fila, int columna);
};

#endif