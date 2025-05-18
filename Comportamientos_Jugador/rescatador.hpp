#ifndef COMPORTAMIENTORESCATADOR_H
#define COMPORTAMIENTORESCATADOR_H

#include <chrono>
#include <time.h>
#include <thread>
#include <queue>
#include <set>
#include <list>

#include "comportamientos/comportamiento.hpp"

struct EstadoR {
  int f;
  int c;
  int brujula;
  bool zapatillas;

  int coste;

  bool operator==(const EstadoR &st) const{
    return f == st.f && c == st.c && brujula == st.brujula and zapatillas == st.zapatillas;
  }
};

struct NodoR{
  EstadoR estado;
  list<Action> secuencia;

  bool operator==(const NodoR &node) const{
    return estado == node.estado;
  }

  bool operator<(const NodoR &node) const{
    if (estado.f < node.estado.f) return true;
    else if (estado.f == node.estado.f and estado.c < node.estado.c) return true;
    else if (estado.f == node.estado.f and estado.c == node.estado.c and estado.brujula < node.estado.brujula) return true;
    else if (estado.f == node.estado.f and estado.c == node.estado.c and estado.brujula == node.estado.brujula and estado.zapatillas < node.estado.zapatillas) return true;
    else return false;
    }
    
};





class ComportamientoRescatador : public Comportamiento
{

public:
  ComportamientoRescatador(unsigned int size = 0) : Comportamiento(size)
  {
    // Inicializar Variables de Estado Niveles 0,1,4

    last_action = IDLE;
    tiene_zapatillas = false;
    giro45izq = 0;

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


    mov = vector<vector<int>>(size*2, vector<int>(size*2));


  }
  ComportamientoRescatador(std::vector<std::vector<unsigned char>> mapaR, std::vector<std::vector<unsigned char>> mapaC) : Comportamiento(mapaR,mapaC)
  {
    // Inicializar Variables de Estado Niveles 2,3
    last_action = IDLE;
    tiene_zapatillas = false;
    hayPlan=false;
    


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



  EstadoR applyR(Action a, const EstadoR &st, const vector<vector<unsigned char>> &terreno, const vector<vector<unsigned char>> &altura);
  void PintaPlan(const list<Action> &plan, bool zap);
  list<Action> Uniforme(const EstadoR &inicio, const EstadoR &final, const vector<vector<unsigned char>> &terreno, const vector<vector<unsigned char>> &altura);
  void VisualizaPlan(const EstadoR &st, const list<Action> &plan);


private:
  // Variables de Estado

  Action last_action;
  bool tiene_zapatillas;
  int giro45izq;


  queue<Action> esquives;



  list<Action> plan;
  bool hayPlan;

  vector<vector<int> > mov;

};

#endif
