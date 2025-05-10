#ifndef COMPORTAMIENTORESCATADOR_H
#define COMPORTAMIENTORESCATADOR_H

#include <chrono>
#include <time.h>
#include <thread>
#include <queue>  

#include "comportamientos/comportamiento.hpp"

class ComportamientoRescatador : public Comportamiento
{

public:
  ComportamientoRescatador(unsigned int size = 0) : Comportamiento(size)
  {
    // Inicializar Variables de Estado Niveles 0,1,4

    last_action = IDLE;
    tiene_zapatillas = false;
    giro45izq = 0;

    esquivando=0;



    //pongo precipicios
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < size; ++j) {
            mapaResultado[i][j] = 'P';
        }
    }
    
    for (int i = size - 3; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            mapaResultado[i][j] = 'P';
        }
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 3; ++j) {
            mapaResultado[i][j] = 'P';
        }
    }
    for (int i = 0; i < size; ++i) {
        for (int j = size - 3; j < size; ++j) {
              mapaResultado[i][j] = 'P';
          }
    }



  }
  ComportamientoRescatador(std::vector<std::vector<unsigned char>> mapaR, std::vector<std::vector<unsigned char>> mapaC) : Comportamiento(mapaR,mapaC)
  {
    // Inicializar Variables de Estado Niveles 2,3
  }
  ComportamientoRescatador(const ComportamientoRescatador &comport) : Comportamiento(comport) {}
  ~ComportamientoRescatador() {}

  Action think(Sensores sensores);

  int interact(Action accion, int valor);

  Action ComportamientoRescatadorNivel_0(Sensores sensores);
  Action ComportamientoRescatadorNivel_1(Sensores sensores);
  Action ComportamientoRescatadorNivel_2(Sensores sensores);
  Action ComportamientoRescatadorNivel_3(Sensores sensores);
  Action ComportamientoRescatadorNivel_4(Sensores sensores);

private:
  // Variables de Estado

  Action last_action;
  bool tiene_zapatillas;
  int giro45izq;
  int esquivando;

  queue<Action> esquives;
  vector<vector<int> > mov;


};

#endif
