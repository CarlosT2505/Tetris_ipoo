/*
╔═══════════════════════════════════════════════════════╦═════════════════╦════════════════╗
║                Archivo: HallDeLaFama.cpp              ║   Versión 1.0   ║  Licencia GPL  ║
╠═══════════════════════╦══════╦════╦════╦══════════════╩═════════════════╬══════╦════╦════╣
║  Fecha de creación:   ║ 2018 ║ 03 ║ 09 ║   Fecha última modificación:   ║ 2018 ║ 04 ║ 20 ║ 
╠═══════════════════════╩══════╩════╩════╩════════════════════════════════╩══════╩════╩════╣
╠══════════╦═════════════════════════════════╦═════════════════════════════════════════════╣
║          ║ Sara Jazmín Maradiago Calderón  ║ sara.maradiago@correounivalle.edu.co        ║
║ Autores: ╠═════════════════════════════════╬═════════════════════════════════════════════╣
║          ║ Carlos Maurico Tovar Parra      ║ carlos.mauricio.tovar@correounivalle.edu.co ║
╚══════════╩═════════════════════════════════╩═════════════════════════════════════════════╝
*/

#include <cstdlib>
#include "HallDeLaFama.h"

HallDeLaFama::HallDeLaFama(string archivo)
{
  numeroDeGanadores = 0;
  this->archivo=archivo;
  string laLinea, elNombre;
  int losPuntos;
  ifstream flujoDeEntrada;
  flujoDeEntrada.open(archivo);
  if(not flujoDeEntrada.fail())
  {
    while(not flujoDeEntrada.eof())
    {
      getline(flujoDeEntrada, laLinea);
      int posicionDeCaracter=0;
      for(; posicionDeCaracter<laLinea.length() and laLinea[posicionDeCaracter]!= '\t'; posicionDeCaracter++)
      {
      }
      if(posicionDeCaracter==laLinea.length())
      {
        continue;
      }
      elNombre=laLinea.substr(0, posicionDeCaracter);
      losPuntos=stoi(laLinea.substr(posicionDeCaracter+1, laLinea.length()));
      nuevoGanador(elNombre, losPuntos);
    }
  }
  else
  {
    cout<<endl<<"Se creará un archivo para guardar los records."<<endl;
  }
  flujoDeEntrada.close();
}

HallDeLaFama::~HallDeLaFama()
{
  ofstream flujoDeSalida;
  flujoDeSalida.open(archivo);
  if(not flujoDeSalida.fail())
  {
   flujoDeSalida<<listaDeGanadores(); 
  }
  flujoDeSalida.close();
}

void HallDeLaFama::nuevoGanador(string nombre, int puntaje)
{
  for(int caracter=0; caracter<nombre.length(); caracter++)
  {
    if(nombre[caracter]=='\t')
    {
      nombre[caracter]=' ';
    }
  }
  bool encontrado = false;
  for(int cual=0; cual<numeroDeGanadores; cual++)
  if(ganadores[cual] == nombre)
  {
    if(puntos[cual] < puntaje)
    puntos[cual] = puntaje;
    encontrado = true;
  }
  if(not encontrado)
  {
    if(numeroDeGanadores == 10)
    {
      if(puntos[9] < puntaje)
      {
        puntos[9] = puntaje;
        ganadores[9] = nombre;
      }
    }
    else
    {
      puntos[numeroDeGanadores] = puntaje;
      ganadores[numeroDeGanadores] = nombre;
      numeroDeGanadores++;
    }
  }
  ordenar();
}

void HallDeLaFama::ordenar()
{
  for(int primero=0; primero<numeroDeGanadores-1; primero++)
  {
    for(int despues=primero+1; despues<numeroDeGanadores; despues++)
    {
     if(puntos[primero] < puntos[despues])
      {
        int aux = puntos[primero];
        puntos[primero] = puntos[despues];
        puntos[despues] = aux;

        string nombreAux = ganadores[primero];
        ganadores[primero] = ganadores[despues];
        ganadores[despues] = nombreAux;
      } 
    }
  }
}

string HallDeLaFama::listaDeGanadores()
{
  string resultado = "";
  for(int cual=0; cual<numeroDeGanadores; cual++)
  {
    resultado += ganadores[cual] + "\t" + to_string(puntos[cual]) + "\n"; 
  }
  return resultado;
}