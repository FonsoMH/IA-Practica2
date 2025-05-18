#ifndef COMPORTAMIENTOAUXILIAR_H
#define COMPORTAMIENTOAUXILIAR_H

#include <chrono>
#include <time.h>
#include <thread>
#include <list>
#include <set>

#include "comportamientos/comportamiento.hpp"
struct EstadoA {
  int f;
  int c;
  int brujula;
  bool zapatillas;

  bool operator==(const EstadoA &st) const{
    return f == st.f && c == st.c && brujula == st.brujula and zapatillas == st.zapatillas;
  }
};

struct NodoA{
  EstadoA estado;
  list<Action> secuencia;

  bool operator==(const NodoA &node) const{
    return estado == node.estado;
  }

  bool operator<(const NodoA &node) const{
    if (estado.f < node.estado.f) return true;
    else if (estado.f == node.estado.f and estado.c < node.estado.c) return true;
    else if (estado.f == node.estado.f and estado.c == node.estado.c and estado.brujula < node.estado.brujula) return true;
    else if (estado.f == node.estado.f and estado.c == node.estado.c and estado.brujula == node.estado.brujula and estado.zapatillas < node.estado.zapatillas) return true;
    else return false;
    }
    
};


class ComportamientoAuxiliar : public Comportamiento
{

public:

  ComportamientoAuxiliar(unsigned int size = 0) : Comportamiento(size)
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
  ComportamientoAuxiliar(std::vector<std::vector<unsigned char>> mapaR, std::vector<std::vector<unsigned char>> mapaC) : Comportamiento(mapaR,mapaC)
  {
    // Inicializar Variables de Estado Niveles 2,3
    hayPlan = false;

    




  }
  ComportamientoAuxiliar(const ComportamientoAuxiliar &comport) : Comportamiento(comport) {}
  ~ComportamientoAuxiliar() {}

  Action think(Sensores sensores);

  int interact(Action accion, int valor);

  Action ComportamientoAuxiliarNivel_0(Sensores sensores);
  Action ComportamientoAuxiliarNivel_1(Sensores sensores);
  Action ComportamientoAuxiliarNivel_2(Sensores sensores);
  Action ComportamientoAuxiliarNivel_3(Sensores sensores);
  Action ComportamientoAuxiliarNivel_4(Sensores sensores);

  Action ComportamientoAuxiliarNivel_E(Sensores sensores);

  list<Action> AnchuraAuxiliar(const EstadoA &inicio, const EstadoA &final, const vector<vector<unsigned char>> &terreno, const vector<vector<unsigned char>> &altura);
  list<Action> AnchuraAuxiliar_V2(const EstadoA &inicio, const EstadoA &final, const vector<vector<unsigned char>> &terreno, const vector<vector<unsigned char>> &altura);

  void VisualizaPlan(const EstadoA &st, const list<Action> &plan);
  EstadoA NextCasillaAuxiliar(const EstadoA &st);
  void PintaPlan(const list<Action> &plan, bool zap);

private:
  // Definir Variables de Estado

  Action last_action;
  bool tiene_zapatillas;
  int giro45izq;

  
  
  list<Action> plan;
  bool hayPlan;

  vector<vector<int> > mov;

};

#endif
