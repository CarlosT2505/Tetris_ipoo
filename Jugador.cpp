/*
╔═══════════════════════════════════════════════════════╦═════════════════╦════════════════╗
║                Archivo: Jugador.cpp                   ║   Versión 1.0   ║  Licencia GPL  ║
╠═══════════════════════╦══════╦════╦════╦══════════════╩═════════════════╬══════╦════╦════╣
║  Fecha de creación:   ║ 2018 ║ 05 ║ 12 ║   Fecha última modificación:   ║ 2018 ║ 06 ║ 15 ║ 
╠═══════════════════════╩══════╩════╩════╩════════════════════════════════╩══════╩════╩════╣
╠══════════╦═════════════════════════════════╦═════════════════════════════════════════════╣
║          ║ Sara Jazmín Maradiago Calderón  ║ sara.maradiago@correounivalle.edu.co        ║
║ Autores: ╠═════════════════════════════════╬═════════════════════════════════════════════╣
║          ║ Carlos Maurico Tovar Parra      ║ carlos.mauricio.tovar@correounivalle.edu.co ║
╚══════════╩═════════════════════════════════╩═════════════════════════════════════════════╝
*/

#include "Jugador.h"

Jugador::Jugador(DispositivoEntradaSalida *dispositivo)
{
    this->dispositivo=dispositivo;
}

string Jugador::recibirNombre()
{
    nombre= dispositivo->leerNombre();
    return nombre;
}

string Jugador::dimeTuNombre()
{
    return nombre;
}

int Jugador::aumentarPuntos(int cuantos)
{
    puntos=puntos+cuantos;
    return puntos;
}

void Jugador::reiniciarPuntos()
{
    puntos=0;
}