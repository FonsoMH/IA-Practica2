#include "../Comportamientos_Jugador/rescatador.hpp"
#include "motorlib/util.h"
#include <iostream>
#include <queue>
#include <set>
#include <list>
#include <queue>

Action ComportamientoRescatador::think(Sensores sensores)
{
	Action accion = IDLE;

	switch (sensores.nivel)
	{
	case 0:
		accion = ComportamientoRescatadorNivel_0 (sensores);
		break;
	case 1:
		accion = ComportamientoRescatadorNivel_1 (sensores);
		break;
	case 2:
		accion = ComportamientoRescatadorNivel_2 (sensores);
		break;
	case 3:
		// accion = ComportamientoRescatadorNivel_3 (sensores);
		break;
	case 4:
		// accion = ComportamientoRescatadorNivel_4 (sensores);
		break;
	}

	return accion;
}

int ComportamientoRescatador::interact(Action accion, int valor)
{
	return 0;
}

void MOV_INTRANS(Sensores sensores, vector<vector<int> > &mov){
	switch (sensores.rumbo) {
        case norte:
            if(sensores.superficie[1] != 'D' && sensores.superficie[1] != 'X' && sensores.superficie[1] != 'C' ) {
                mov[sensores.posF - 1][sensores.posC - 1] = 5000;
            }
            if(sensores.superficie[2] != 'D' && sensores.superficie[1] != 'X' && sensores.superficie[2] != 'C' ) {
                mov[sensores.posF - 1][sensores.posC] = 5000;
            }
            if(sensores.superficie[3] != 'D' && sensores.superficie[1] != 'X' && sensores.superficie[3] != 'C' ) {
                mov[sensores.posF - 1][sensores.posC + 1] = 5000;
            }
            break;
        case sur:
            if(sensores.superficie[1] != 'D' && sensores.superficie[1] != 'X' && sensores.superficie[1] != 'C' ) {
                mov[sensores.posF + 1][sensores.posC + 1] = 5000;
            }
            if(sensores.superficie[2] != 'D' && sensores.superficie[1] != 'X' && sensores.superficie[2] != 'C' ) {
                mov[sensores.posF + 1][sensores.posC] = 5000;
            }
            if(sensores.superficie[3] != 'D' && sensores.superficie[1] != 'X' && sensores.superficie[3] != 'C' ) {
                mov[sensores.posF + 1][sensores.posC - 1] = 5000;
            }
            break;
        case este:
            if(sensores.superficie[1] != 'D' && sensores.superficie[1] != 'X' && sensores.superficie[1] != 'C' ) {
                mov[sensores.posF - 1][sensores.posC + 1] = 5000;
            }
            if(sensores.superficie[2] != 'D' && sensores.superficie[1] != 'X' && sensores.superficie[2] != 'C') {
                mov[sensores.posF][sensores.posC + 1] = 5000;
            }
            if(sensores.superficie[3] != 'D' && sensores.superficie[1] != 'X' && sensores.superficie[3] != 'C' ) {
                mov[sensores.posF + 1][sensores.posC + 1] = 5000;
            }
            break;
        case oeste:
            if(sensores.superficie[1] != 'D' && sensores.superficie[1] != 'X' && sensores.superficie[1] != 'C' ) {
                mov[sensores.posF + 1][sensores.posC - 1] = 5000;
            }
            if(sensores.superficie[2] != 'D' && sensores.superficie[1] != 'X' && sensores.superficie[2] != 'C' ) {
                mov[sensores.posF][sensores.posC - 1] = 5000;
            }
            if(sensores.superficie[3] != 'D' && sensores.superficie[1] != 'X' && sensores.superficie[3] != 'C' ) {
                mov[sensores.posF - 1][sensores.posC - 1] = 5000;
            }
            break;
        case noreste:
            if(sensores.superficie[1] != 'D' && sensores.superficie[1] != 'X' && sensores.superficie[1] != 'C' ) {
                mov[sensores.posF - 1][sensores.posC] = 5000;
            }
            if(sensores.superficie[2] != 'D' && sensores.superficie[1] != 'X' && sensores.superficie[2] != 'C' ) {
                mov[sensores.posF - 1][sensores.posC + 1] = 5000;
            }
            if(sensores.superficie[3] != 'D' && sensores.superficie[1] != 'X' && sensores.superficie[3] != 'C' ) {
                mov[sensores.posF][sensores.posC + 1] = 5000;
            }
            break;
        case noroeste:
            if(sensores.superficie[1] != 'D' && sensores.superficie[1] != 'X' && sensores.superficie[1] != 'C' ) {
                mov[sensores.posF][sensores.posC - 1] = 5000;
            }
            if(sensores.superficie[2] != 'D' && sensores.superficie[1] != 'X' && sensores.superficie[2] != 'C' ) {
                mov[sensores.posF - 1][sensores.posC - 1] = 5000;
            }
            if(sensores.superficie[3] != 'D' && sensores.superficie[1] != 'X' && sensores.superficie[3] != 'C' ) {
                mov[sensores.posF - 1][sensores.posC] = 5000;
            }
            break;
        case sureste:
            if(sensores.superficie[1] != 'D' && sensores.superficie[1] != 'X' && sensores.superficie[1] != 'C' ) {
                mov[sensores.posF][sensores.posC + 1] = 5000;
            }
            if(sensores.superficie[2] != 'D' && sensores.superficie[1] != 'X' && sensores.superficie[2] != 'C' ) {
                mov[sensores.posF + 1][sensores.posC + 1] = 5000;
            }
            if(sensores.superficie[3] != 'D' && sensores.superficie[1] != 'X' && sensores.superficie[3] != 'C' ) {
                mov[sensores.posF + 1][sensores.posC] = 5000;
            }
            break;
        case suroeste:
            if(sensores.superficie[1] != 'D' && sensores.superficie[1] != 'X' && sensores.superficie[1] != 'C' ) {
                mov[sensores.posF + 1][sensores.posC] = 5000;
            }
            if(sensores.superficie[2] != 'D' && sensores.superficie[1] != 'X' && sensores.superficie[2] != 'C' ) {
                mov[sensores.posF + 1][sensores.posC - 1] = 5000;
            }
            if(sensores.superficie[3] != 'D' && sensores.superficie[1] != 'X' && sensores.superficie[3] != 'C' ) {
                mov[sensores.posF][sensores.posC - 1] = 5000; 
            }
            break;
    }
}


void PonerMuros_Precip_EnMov(Sensores sensores, vector<vector<int> > &mov){
	switch (sensores.rumbo) {
        case norte:
            if(sensores.superficie[1] == 'P' || sensores.superficie[1] == 'M' || sensores.superficie[1] == 'B' ) {
                mov[sensores.posF - 1][sensores.posC - 1] = 5000;
            }
            if(sensores.superficie[2] == 'P' || sensores.superficie[1] == 'M' || sensores.superficie[2] == 'B' ) {
                mov[sensores.posF - 1][sensores.posC] = 5000;
            }
            if(sensores.superficie[3] == 'P' || sensores.superficie[1] == 'M' || sensores.superficie[3] == 'B' ) {
                mov[sensores.posF - 1][sensores.posC + 1] = 5000;
            }
            break;
        case sur:
            if(sensores.superficie[1] == 'P' || sensores.superficie[1] == 'M' || sensores.superficie[1] == 'B' ) {
                mov[sensores.posF + 1][sensores.posC + 1] = 5000;
            }
            if(sensores.superficie[2] == 'P' || sensores.superficie[1] == 'M' || sensores.superficie[2] == 'B' ) {
                mov[sensores.posF + 1][sensores.posC] = 5000;
            }
            if(sensores.superficie[3] == 'P' || sensores.superficie[1] == 'M' || sensores.superficie[3] == 'B' ) {
                mov[sensores.posF + 1][sensores.posC - 1] = 5000;
            }
            break;
        case este:
            if(sensores.superficie[1] == 'P' || sensores.superficie[1] == 'M' || sensores.superficie[1] == 'B' ) {
                mov[sensores.posF - 1][sensores.posC + 1] = 5000;
            }
            if(sensores.superficie[2] == 'P' || sensores.superficie[1] == 'M' || sensores.superficie[2] == 'B') {
                mov[sensores.posF][sensores.posC + 1] = 5000;
            }
            if(sensores.superficie[3] == 'P' || sensores.superficie[1] == 'M' || sensores.superficie[3] == 'B' ) {
                mov[sensores.posF + 1][sensores.posC + 1] = 5000;
            }
            break;
        case oeste:
            if(sensores.superficie[1] == 'P' || sensores.superficie[1] == 'M' || sensores.superficie[1] == 'B' ) {
                mov[sensores.posF + 1][sensores.posC - 1] = 5000;
            }
            if(sensores.superficie[2] == 'P' || sensores.superficie[1] == 'M' || sensores.superficie[2] == 'B' ) {
                mov[sensores.posF][sensores.posC - 1] = 5000;
            }
            if(sensores.superficie[3] == 'P' || sensores.superficie[1] == 'M' || sensores.superficie[3] == 'B' ) {
                mov[sensores.posF - 1][sensores.posC - 1] = 5000;
            }
            break;
        case noreste:
            if(sensores.superficie[1] == 'P' || sensores.superficie[1] == 'M' || sensores.superficie[1] == 'B' ) {
                mov[sensores.posF - 1][sensores.posC] = 5000;
            }
            if(sensores.superficie[2] == 'P' || sensores.superficie[1] == 'M' || sensores.superficie[2] == 'B' ) {
                mov[sensores.posF - 1][sensores.posC + 1] = 5000;
            }
            if(sensores.superficie[3] == 'P' || sensores.superficie[1] == 'M' || sensores.superficie[3] == 'B' ) {
                mov[sensores.posF][sensores.posC + 1] = 5000;
            }
            break;
        case noroeste:
            if(sensores.superficie[1] == 'P' || sensores.superficie[1] == 'M' || sensores.superficie[1] == 'B' ) {
                mov[sensores.posF][sensores.posC - 1] = 5000;
            }
            if(sensores.superficie[2] == 'P' || sensores.superficie[1] == 'M' || sensores.superficie[2] == 'B' ) {
                mov[sensores.posF - 1][sensores.posC - 1] = 5000;
            }
            if(sensores.superficie[3] == 'P' || sensores.superficie[1] == 'M' || sensores.superficie[3] == 'B' ) {
                mov[sensores.posF - 1][sensores.posC] = 5000;
            }
            break;
        case sureste:
            if(sensores.superficie[1] == 'P' || sensores.superficie[1] == 'M' || sensores.superficie[1] == 'B' ) {
                mov[sensores.posF][sensores.posC + 1] = 5000;
            }
            if(sensores.superficie[2] == 'P' || sensores.superficie[1] == 'M' || sensores.superficie[2] == 'B' ) {
                mov[sensores.posF + 1][sensores.posC + 1] = 5000;
            }
            if(sensores.superficie[3] == 'P' || sensores.superficie[1] == 'M' || sensores.superficie[3] == 'B' ) {
                mov[sensores.posF + 1][sensores.posC] = 5000;
            }
            break;
        case suroeste:
            if(sensores.superficie[1] == 'P' || sensores.superficie[1] == 'M' || sensores.superficie[1] == 'B' ) {
                mov[sensores.posF + 1][sensores.posC] = 5000;
            }
            if(sensores.superficie[2] == 'P' || sensores.superficie[1] == 'M' || sensores.superficie[2] == 'B' ) {
                mov[sensores.posF + 1][sensores.posC - 1] = 5000;
            }
            if(sensores.superficie[3] == 'P' || sensores.superficie[1] == 'M' || sensores.superficie[3] == 'B' ) {
                mov[sensores.posF][sensores.posC - 1] = 5000; 
            }
            break;
    }
}



int VeoCasillaInteresanteR(char i, char c, char d, bool zap){
	if(c=='X') return 2;
	else if	(i == 'X')  return 1;
	else if (d=='X')  return 3;
	else if(!zap){
		if( c=='D') return 2;
		else if(i =='D') return 1;
		else if( d=='D') return 3;
	}
	if (c == 'C') return 2;
	else if (i == 'C') return 1;
	else if (d == 'C') return 3;
	else return 0;
}

int VeoCasillaInteresanteRLVL1(char i, char c, char d, bool zap){
	if(!zap){
		if( c=='D') return 2;
		else if(i =='D') return 1;
		else if( d=='D') return 3;
	}
	if (c == 'C') return 2;
	else if (i == 'C') return 1;
	else if (d == 'C') return 3;
	if(c != 'P' || c != 'M') return 2;
	else if(d != 'P' || d != 'M') return 3;
	else if(i != 'P' || i != 'M') return 1;

	else return 0;
}

char ViablePorAlturaR(char casilla, int dif, bool zap){
	if(abs(dif)<=1 or (zap and abs(dif)<=2))
	return casilla;
	else	
	return 'P';
}

bool transitable_lvl0(unsigned char casilla , int dif, bool zap, unsigned char casilla_ag){
	if( (abs(dif)<=1 or (zap and abs(dif)<=2) ) && ((casilla=='C' || casilla=='D' || casilla=='X') && casilla_ag=='_') ){
		cout<<"SI ES TRANSITABLE"<<endl;
		return true;
	}
	else {
		cout<<"NO ES TRANSITABLE"<<endl; 
		return false;
	}
}

bool transitable_lvl1(unsigned char casilla , int dif, bool zap, unsigned char casilla_ag){
	if( (abs(dif)<=1 or (zap and abs(dif)<=2) ) && ((casilla !='M' || casilla !='P' || casilla !='B') && casilla_ag=='_') ){
		cout<<"SI ES TRANSITABLE"<<endl;
		return true;
	}
	else {
		cout<<"NO ES TRANSITABLE"<<endl; 
		return false;
	}
}


queue<Action> evitar_choque(Sensores sensores, bool zapas){
	cout<<"Entro aqui!!!"<<endl;
	queue<Action> acciones;
	cout<<"PRIMERO CASILLA 3: "<<endl;
	if(transitable_lvl0(sensores.superficie[3], sensores.cota[3]-sensores.cota[0],zapas, sensores.agentes[3])){
		acciones.push(TURN_SR);
		acciones.push(WALK);
		acciones.push(TURN_L);
		acciones.push(TURN_L);
		acciones.push(WALK);
		acciones.push(TURN_SR);
	}
	else if(transitable_lvl0(sensores.superficie[1], sensores.cota[1]-sensores.cota[0], zapas, sensores.agentes[1])){
		cout<<"AHORA CASILLA 1: "<<endl;
		acciones.push(TURN_L);
		acciones.push(TURN_SR);
		acciones.push(WALK);
		acciones.push(TURN_SR);
		acciones.push(TURN_SR);
		acciones.push(TURN_SR);
		acciones.push(WALK);
		acciones.push(TURN_L);
	
	}else{
		cout<<"NO VEO TRANSITABLES. GIRO IZQ"<<endl;
		acciones.push(TURN_L);
	}
	return acciones;
}


void SituarSensorEnMapaR(vector<vector<unsigned char> > &m, vector<vector<unsigned char> > &a, Sensores sensores){

	m[sensores.posF][sensores.posC] = sensores.superficie[0];
	a[sensores.posF][sensores.posC] = sensores.cota[0];


	
	int pos=1;
	switch (sensores.rumbo)
	{
		// En 90 grados
	case norte:
		m[sensores.posF-1][sensores.posC-1] = sensores.superficie[1];
		m[sensores.posF-1][sensores.posC] = sensores.superficie[2];
		m[sensores.posF-1][sensores.posC+1] = sensores.superficie[3];
		m[sensores.posF-2][sensores.posC-2] = sensores.superficie[4];
		m[sensores.posF-2][sensores.posC-1] = sensores.superficie[5];
		m[sensores.posF-2][sensores.posC] = sensores.superficie[6];
		m[sensores.posF-2][sensores.posC+1] = sensores.superficie[7];
		m[sensores.posF-2][sensores.posC+2] = sensores.superficie[8];
		m[sensores.posF-3][sensores.posC-3] = sensores.superficie[9];
		m[sensores.posF-3][sensores.posC-2] = sensores.superficie[10];
		m[sensores.posF-3][sensores.posC-1] = sensores.superficie[11];
		m[sensores.posF-3][sensores.posC] = sensores.superficie[12];
		m[sensores.posF-3][sensores.posC+1] = sensores.superficie[13];
		m[sensores.posF-3][sensores.posC+2] = sensores.superficie[14];
		m[sensores.posF-3][sensores.posC+3] = sensores.superficie[15];

		a[sensores.posF-1][sensores.posC-1] = sensores.cota[1];
		a[sensores.posF-1][sensores.posC] = sensores.cota[2];
		a[sensores.posF-1][sensores.posC+1] = sensores.cota[3];
		a[sensores.posF-2][sensores.posC-2] = sensores.cota[4];
		a[sensores.posF-2][sensores.posC-1] = sensores.cota[5];
		a[sensores.posF-2][sensores.posC] = sensores.cota[6];
		a[sensores.posF-2][sensores.posC+1] = sensores.cota[7];
		a[sensores.posF-2][sensores.posC+2] = sensores.cota[8];
		a[sensores.posF-3][sensores.posC-3] = sensores.cota[9];
		a[sensores.posF-3][sensores.posC-2] = sensores.cota[10];
		a[sensores.posF-3][sensores.posC-1] = sensores.cota[11];
		a[sensores.posF-3][sensores.posC] = sensores.cota[12];
		a[sensores.posF-3][sensores.posC+1] = sensores.cota[13];
		a[sensores.posF-3][sensores.posC+2] = sensores.cota[14];
		a[sensores.posF-3][sensores.posC+3] = sensores.cota[15];
		break;
	
	case sur:
		m[sensores.posF+1][sensores.posC+1] = sensores.superficie[1];
		m[sensores.posF+1][sensores.posC] = sensores.superficie[2];
		m[sensores.posF+1][sensores.posC-1] = sensores.superficie[3];
		m[sensores.posF+2][sensores.posC+2] = sensores.superficie[4];
		m[sensores.posF+2][sensores.posC+1] = sensores.superficie[5];
		m[sensores.posF+2][sensores.posC] = sensores.superficie[6];
		m[sensores.posF+2][sensores.posC-1] = sensores.superficie[7];
		m[sensores.posF+2][sensores.posC-2] = sensores.superficie[8];
		m[sensores.posF+3][sensores.posC+3] = sensores.superficie[9];
		m[sensores.posF+3][sensores.posC+2] = sensores.superficie[10];
		m[sensores.posF+3][sensores.posC+1] = sensores.superficie[11];
		m[sensores.posF+3][sensores.posC] = sensores.superficie[12];
		m[sensores.posF+3][sensores.posC-1] = sensores.superficie[13];
		m[sensores.posF+3][sensores.posC-2] = sensores.superficie[14];
		m[sensores.posF+3][sensores.posC-3] = sensores.superficie[15];

		a[sensores.posF+1][sensores.posC+1] = sensores.cota[1];
		a[sensores.posF+1][sensores.posC] = sensores.cota[2];
		a[sensores.posF+1][sensores.posC-1] = sensores.cota[3];
		a[sensores.posF+2][sensores.posC+2] = sensores.cota[4];
		a[sensores.posF+2][sensores.posC+1] = sensores.cota[5];
		a[sensores.posF+2][sensores.posC] = sensores.cota[6];
		a[sensores.posF+2][sensores.posC-1] = sensores.cota[7];
		a[sensores.posF+2][sensores.posC-2] = sensores.cota[8];
		a[sensores.posF+3][sensores.posC+3] = sensores.cota[9];
		a[sensores.posF+3][sensores.posC+2] = sensores.cota[10];
		a[sensores.posF+3][sensores.posC+1] = sensores.cota[11];
		a[sensores.posF+3][sensores.posC] = sensores.cota[12];
		a[sensores.posF+3][sensores.posC-1] = sensores.cota[13];
		a[sensores.posF+3][sensores.posC-2] = sensores.cota[14];
		a[sensores.posF+3][sensores.posC-3] = sensores.cota[15];
		break;

	case este:
		m[sensores.posF-1][sensores.posC+1] = sensores.superficie[1];
		m[sensores.posF][sensores.posC+1] = sensores.superficie[2];
		m[sensores.posF+1][sensores.posC+1] = sensores.superficie[3];
		m[sensores.posF-2][sensores.posC+2] = sensores.superficie[4];
		m[sensores.posF-1][sensores.posC+2] = sensores.superficie[5];
		m[sensores.posF][sensores.posC+2] = sensores.superficie[6];
		m[sensores.posF+1][sensores.posC+2] = sensores.superficie[7];
		m[sensores.posF+2][sensores.posC+2] = sensores.superficie[8];
		m[sensores.posF-3][sensores.posC+3] = sensores.superficie[9];
		m[sensores.posF-2][sensores.posC+3] = sensores.superficie[10];
		m[sensores.posF-1][sensores.posC+3] = sensores.superficie[11];
		m[sensores.posF][sensores.posC+3] = sensores.superficie[12];
		m[sensores.posF+1][sensores.posC+3] = sensores.superficie[13];
		m[sensores.posF+2][sensores.posC+3] = sensores.superficie[14];
		m[sensores.posF+3][sensores.posC+3] = sensores.superficie[15];

		a[sensores.posF-1][sensores.posC+1] = sensores.cota[1];
		a[sensores.posF][sensores.posC+1] = sensores.cota[2];
		a[sensores.posF+1][sensores.posC+1] = sensores.cota[3];
		a[sensores.posF-2][sensores.posC+2] = sensores.cota[4];
		a[sensores.posF-1][sensores.posC+2] = sensores.cota[5];
		a[sensores.posF][sensores.posC+2] = sensores.cota[6];
		a[sensores.posF+1][sensores.posC+2] = sensores.cota[7];
		a[sensores.posF+2][sensores.posC+2] = sensores.cota[8];
		a[sensores.posF-3][sensores.posC+3] = sensores.cota[9];
		a[sensores.posF-2][sensores.posC+3] = sensores.cota[10];
		a[sensores.posF-1][sensores.posC+3] = sensores.cota[11];
		a[sensores.posF][sensores.posC+3] = sensores.cota[12];
		a[sensores.posF+1][sensores.posC+3] = sensores.cota[13];
		a[sensores.posF+2][sensores.posC+3] = sensores.cota[14];
		a[sensores.posF+3][sensores.posC+3] = sensores.cota[15];
		break;

	case oeste:
		m[sensores.posF+1][sensores.posC-1] = sensores.superficie[1];
		m[sensores.posF][sensores.posC-1] = sensores.superficie[2];
		m[sensores.posF-1][sensores.posC-1] = sensores.superficie[3];
		m[sensores.posF+2][sensores.posC-2] = sensores.superficie[4];
		m[sensores.posF+1][sensores.posC-2] = sensores.superficie[5];
		m[sensores.posF][sensores.posC-2] = sensores.superficie[6];
		m[sensores.posF-1][sensores.posC-2] = sensores.superficie[7];
		m[sensores.posF-2][sensores.posC-2] = sensores.superficie[8];
		m[sensores.posF+3][sensores.posC-3] = sensores.superficie[9];
		m[sensores.posF+2][sensores.posC-3] = sensores.superficie[10];
		m[sensores.posF+1][sensores.posC-3] = sensores.superficie[11];
		m[sensores.posF][sensores.posC-3] = sensores.superficie[12];
		m[sensores.posF-1][sensores.posC-3] = sensores.superficie[13];
		m[sensores.posF-2][sensores.posC-3] = sensores.superficie[14];
		m[sensores.posF-3][sensores.posC-3] = sensores.superficie[15];

		a[sensores.posF+1][sensores.posC-1] = sensores.cota[1];
		a[sensores.posF][sensores.posC-1] = sensores.cota[2];
		a[sensores.posF-1][sensores.posC-1] = sensores.cota[3];
		a[sensores.posF+2][sensores.posC-2] = sensores.cota[4];
		a[sensores.posF+1][sensores.posC-2] = sensores.cota[5];
		a[sensores.posF][sensores.posC-2] = sensores.cota[6];
		a[sensores.posF-1][sensores.posC-2] = sensores.cota[7];
		a[sensores.posF-2][sensores.posC-2] = sensores.cota[8];
		a[sensores.posF+3][sensores.posC-3] = sensores.cota[9];
		a[sensores.posF+2][sensores.posC-3] = sensores.cota[10];
		a[sensores.posF+1][sensores.posC-3] = sensores.cota[11];
		a[sensores.posF][sensores.posC-3] = sensores.cota[12];
		a[sensores.posF-1][sensores.posC-3] = sensores.cota[13];
		a[sensores.posF-2][sensores.posC-3] = sensores.cota[14];
		a[sensores.posF-3][sensores.posC-3] = sensores.cota[15];
		break;

	// En 45 grados

	case noreste:
		m[sensores.posF-1][sensores.posC] = sensores.superficie[1];
		m[sensores.posF-1][sensores.posC+1] = sensores.superficie[2];
		m[sensores.posF][sensores.posC+1] = sensores.superficie[3];
		m[sensores.posF-2][sensores.posC] = sensores.superficie[4];
		m[sensores.posF-2][sensores.posC+1] = sensores.superficie[5];
		m[sensores.posF-2][sensores.posC+2] = sensores.superficie[6];
		m[sensores.posF-1][sensores.posC+2] = sensores.superficie[7];
		m[sensores.posF][sensores.posC+2] = sensores.superficie[8];
		m[sensores.posF-3][sensores.posC] = sensores.superficie[9];
		m[sensores.posF-3][sensores.posC+1] = sensores.superficie[10];
		m[sensores.posF-3][sensores.posC+2] = sensores.superficie[11];
		m[sensores.posF-3][sensores.posC+3] = sensores.superficie[12];
		m[sensores.posF-2][sensores.posC+3] = sensores.superficie[13];
		m[sensores.posF-1][sensores.posC+3] = sensores.superficie[14];
		m[sensores.posF][sensores.posC+3] = sensores.superficie[15];

		a[sensores.posF-1][sensores.posC] = sensores.cota[1];
		a[sensores.posF-1][sensores.posC+1] = sensores.cota[2];
		a[sensores.posF][sensores.posC+1] = sensores.cota[3];
		a[sensores.posF-2][sensores.posC] = sensores.cota[4];
		a[sensores.posF-2][sensores.posC+1] = sensores.cota[5];
		a[sensores.posF-2][sensores.posC+2] = sensores.cota[6];
		a[sensores.posF-1][sensores.posC+2] = sensores.cota[7];
		a[sensores.posF][sensores.posC+2] = sensores.cota[8];
		a[sensores.posF-3][sensores.posC] = sensores.cota[9];
		a[sensores.posF-3][sensores.posC+1] = sensores.cota[10];
		a[sensores.posF-3][sensores.posC+2] = sensores.cota[11];
		a[sensores.posF-3][sensores.posC+3] = sensores.cota[12];
		a[sensores.posF-2][sensores.posC+3] = sensores.cota[13];
		a[sensores.posF-1][sensores.posC+3] = sensores.cota[14];
		a[sensores.posF][sensores.posC+3] = sensores.cota[15];
		break;

	case noroeste:
		m[sensores.posF][sensores.posC-1] = sensores.superficie[1];
		m[sensores.posF-1][sensores.posC-1] = sensores.superficie[2];
		m[sensores.posF-1][sensores.posC] = sensores.superficie[3];
		m[sensores.posF][sensores.posC-2] = sensores.superficie[4];
		m[sensores.posF-1][sensores.posC-2] = sensores.superficie[5];
		m[sensores.posF-2][sensores.posC-2] = sensores.superficie[6];
		m[sensores.posF-2][sensores.posC-1] = sensores.superficie[7];
		m[sensores.posF-2][sensores.posC] = sensores.superficie[8];
		m[sensores.posF][sensores.posC-3] = sensores.superficie[9];
		m[sensores.posF-1][sensores.posC-3] = sensores.superficie[10];
		m[sensores.posF-2][sensores.posC-3] = sensores.superficie[11];
		m[sensores.posF-3][sensores.posC-3] = sensores.superficie[12];
		m[sensores.posF-3][sensores.posC-2] = sensores.superficie[13];
		m[sensores.posF-3][sensores.posC-1] = sensores.superficie[14];
		m[sensores.posF-3][sensores.posC] = sensores.superficie[15];

		a[sensores.posF][sensores.posC-1] = sensores.cota[1];
		a[sensores.posF-1][sensores.posC-1] = sensores.cota[2];
		a[sensores.posF-1][sensores.posC] = sensores.cota[3];
		a[sensores.posF][sensores.posC-2] = sensores.cota[4];
		a[sensores.posF-1][sensores.posC-2] = sensores.cota[5];
		a[sensores.posF-2][sensores.posC-2] = sensores.cota[6];
		a[sensores.posF-2][sensores.posC-1] = sensores.cota[7];
		a[sensores.posF-2][sensores.posC] = sensores.cota[8];
		a[sensores.posF][sensores.posC-3] = sensores.cota[9];
		a[sensores.posF-1][sensores.posC-3] = sensores.cota[10];
		a[sensores.posF-2][sensores.posC-3] = sensores.cota[11];
		a[sensores.posF-3][sensores.posC-3] = sensores.cota[12];
		a[sensores.posF-3][sensores.posC-2] = sensores.cota[13];
		a[sensores.posF-3][sensores.posC-1] = sensores.cota[14];
		a[sensores.posF-3][sensores.posC] = sensores.cota[15];
		break;

	case sureste:
		m[sensores.posF][sensores.posC+1] = sensores.superficie[1];
		m[sensores.posF+1][sensores.posC+1] = sensores.superficie[2];
		m[sensores.posF+1][sensores.posC] = sensores.superficie[3];
		m[sensores.posF][sensores.posC+2] = sensores.superficie[4];
		m[sensores.posF+1][sensores.posC+2] = sensores.superficie[5];
		m[sensores.posF+2][sensores.posC+2] = sensores.superficie[6];
		m[sensores.posF+2][sensores.posC+1] = sensores.superficie[7];
		m[sensores.posF+2][sensores.posC] = sensores.superficie[8];
		m[sensores.posF][sensores.posC+3] = sensores.superficie[9];
		m[sensores.posF+1][sensores.posC+3] = sensores.superficie[10];
		m[sensores.posF+2][sensores.posC+3] = sensores.superficie[11];
		m[sensores.posF+3][sensores.posC+3] = sensores.superficie[12];
		m[sensores.posF+3][sensores.posC+2] = sensores.superficie[13];
		m[sensores.posF+3][sensores.posC+1] = sensores.superficie[14];
		m[sensores.posF+3][sensores.posC] = sensores.superficie[15];

		a[sensores.posF][sensores.posC+1] = sensores.cota[1];
		a[sensores.posF+1][sensores.posC+1] = sensores.cota[2];
		a[sensores.posF+1][sensores.posC] = sensores.cota[3];
		a[sensores.posF][sensores.posC+2] = sensores.cota[4];
		a[sensores.posF+1][sensores.posC+2] = sensores.cota[5];
		a[sensores.posF+2][sensores.posC+2] = sensores.cota[6];
		a[sensores.posF+2][sensores.posC+1] = sensores.cota[7];
		a[sensores.posF+2][sensores.posC] = sensores.cota[8];
		a[sensores.posF][sensores.posC+3] = sensores.cota[9];
		a[sensores.posF+1][sensores.posC+3] = sensores.cota[10];
		a[sensores.posF+2][sensores.posC+3] = sensores.cota[11];
		a[sensores.posF+3][sensores.posC+3] = sensores.cota[12];
		a[sensores.posF+3][sensores.posC+2] = sensores.cota[13];
		a[sensores.posF+3][sensores.posC+1] = sensores.cota[14];
		a[sensores.posF+3][sensores.posC] = sensores.cota[15];
		break;

	case suroeste:
		m[sensores.posF+1][sensores.posC] = sensores.superficie[1];
		m[sensores.posF+1][sensores.posC-1] = sensores.superficie[2];
		m[sensores.posF][sensores.posC-1] = sensores.superficie[3];
		m[sensores.posF+2][sensores.posC] = sensores.superficie[4];
		m[sensores.posF+2][sensores.posC-1] = sensores.superficie[5];
		m[sensores.posF+2][sensores.posC-2] = sensores.superficie[6];
		m[sensores.posF+1][sensores.posC-2] = sensores.superficie[7];
		m[sensores.posF][sensores.posC-2] = sensores.superficie[8];
		m[sensores.posF+3][sensores.posC] = sensores.superficie[9];
		m[sensores.posF+3][sensores.posC-1] = sensores.superficie[10];
		m[sensores.posF+3][sensores.posC-2] = sensores.superficie[11];
		m[sensores.posF+3][sensores.posC-3] = sensores.superficie[12];
		m[sensores.posF+2][sensores.posC-3] = sensores.superficie[13];
		m[sensores.posF+1][sensores.posC-3] = sensores.superficie[14];
		m[sensores.posF][sensores.posC-3] = sensores.superficie[15];

		a[sensores.posF+1][sensores.posC] = sensores.cota[1];
		a[sensores.posF+1][sensores.posC-1] = sensores.cota[2];
		a[sensores.posF][sensores.posC-1] = sensores.cota[3];
		a[sensores.posF+2][sensores.posC] = sensores.cota[4];
		a[sensores.posF+2][sensores.posC-1] = sensores.cota[5];
		a[sensores.posF+2][sensores.posC-2] = sensores.cota[6];
		a[sensores.posF+1][sensores.posC-2] = sensores.cota[7];
		a[sensores.posF][sensores.posC-2] = sensores.cota[8];
		a[sensores.posF+3][sensores.posC] = sensores.cota[9];
		a[sensores.posF+3][sensores.posC-1] = sensores.cota[10];
		a[sensores.posF+3][sensores.posC-2] = sensores.cota[11];
		a[sensores.posF+3][sensores.posC-3] = sensores.cota[12];
		a[sensores.posF+2][sensores.posC-3] = sensores.cota[13];
		a[sensores.posF+1][sensores.posC-3] = sensores.cota[14];
		a[sensores.posF][sensores.posC-3] = sensores.cota[15];

		break;
	}


}


Action ComportamientoRescatador::ComportamientoRescatadorNivel_0(Sensores sensores)
{
	// El comportamiento de seguir un camino hasta encontrar un puesto base.

	Action accion;
	//actualizar variables estado

	SituarSensorEnMapaR(mapaResultado, mapaCotas,sensores);

	if(sensores.superficie[0] == 'D') tiene_zapatillas=true;

	
	if( (sensores.agentes[12] == 'a' || sensores.agentes[6] == 'a' || sensores.agentes[2] == 'a' ) && esquives.empty()){
		esquives=evitar_choque(sensores, tiene_zapatillas);
	}

	MOV_INTRANS(sensores, mov);

	
	//definir nuevo comportamiento
	if(sensores.superficie[0] == 'X'){
		accion = IDLE;
	}

	//realizar la esquiva
	else if(!esquives.empty()){
		accion=esquives.front();
		esquives.pop();
	}

	else if(giro45izq != 0){
		accion=TURN_SR;
		giro45izq--;
	}


	switch (sensores.rumbo)
	{
	case norte:
		if( (mov[sensores.posF-1][sensores.posC] <= mov[sensores.posF][sensores.posC-1] &&
			mov[sensores.posF-1][sensores.posC] <= mov[sensores.posF-1][sensores.posC+1] ) && (transitable_lvl0(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2] ) ))  {

				accion=WALK;
		}else if(mov[sensores.posF-1][sensores.posC+1] <= mov[sensores.posF][sensores.posC-1]){
				accion=TURN_SR;
		}else {
				accion=TURN_L;
			}

		break;
	
	case sur:
		if( ( mov[sensores.posF+1][sensores.posC] <= mov[sensores.posF][sensores.posC+1] && 
			mov[sensores.posF+1][sensores.posC] <= mov[sensores.posF+1][sensores.posC-1]  ) && (transitable_lvl0(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2]) ) ){

				accion=WALK;
		}else if(mov[sensores.posF+1][sensores.posC-1] <= mov[sensores.posF][sensores.posC+1]){
				accion=TURN_SR;
		}else {
				accion=TURN_L;
		}

		break;

	case este:
		if( (mov[sensores.posF][sensores.posC+1] <= mov[sensores.posF-1][sensores.posC] && 
			mov[sensores.posF][sensores.posC+1] <= mov[sensores.posF+1][sensores.posC+1] ) && (transitable_lvl0(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2]) ) ){

				accion=WALK;
		}else if(mov[sensores.posF+1][sensores.posC+1] <= mov[sensores.posF-1][sensores.posC]){
				accion=TURN_SR;
		}else {
				accion=TURN_L;
		}

		break;

	case oeste:
		if( (mov[sensores.posF][sensores.posC-1] <= mov[sensores.posF+1][sensores.posC] && 
			mov[sensores.posF][sensores.posC-1] <= mov[sensores.posF-1][sensores.posC-1] ) && (transitable_lvl0(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2]) ) ){

				accion=WALK;
		}else if(mov[sensores.posF-1][sensores.posC-1] <= mov[sensores.posF+1][sensores.posC]){
				accion=TURN_SR;
		}else {
				accion=TURN_L;
		}

		break;


	case noreste:
		if( (mov[sensores.posF-1][sensores.posC+1] <= mov[sensores.posF-1][sensores.posC-1] && 
			mov[sensores.posF-1][sensores.posC+1] <= mov[sensores.posF][sensores.posC+1]) && (transitable_lvl0(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2]) ) ){

				accion=WALK;
		}else if(mov[sensores.posF][sensores.posC+1] <= mov[sensores.posF-1][sensores.posC-1]){
				accion=TURN_SR;
		}else {
				accion=TURN_L;
		}

		break;


	case noroeste:
		if( (mov[sensores.posF-1][sensores.posC-1] <= mov[sensores.posF+1][sensores.posC-1] && 
			mov[sensores.posF-1][sensores.posC-1] <= mov[sensores.posF][sensores.posC-1] ) && transitable_lvl0(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2]) ){

				accion=WALK;
		}else if(mov[sensores.posF][sensores.posC-1] <= mov[sensores.posF+1][sensores.posC-1]){
				accion=TURN_SR;
		}else {
				accion=TURN_L;
		}
		break;


	case sureste:
		if( (mov[sensores.posF+1][sensores.posC+1] <= mov[sensores.posF-1][sensores.posC+1] && 
			mov[sensores.posF+1][sensores.posC+1] <= mov[sensores.posF+1][sensores.posC] ) && transitable_lvl0(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2])){

				accion=WALK;
		}else if(mov[sensores.posF+1][sensores.posC] <= mov[sensores.posF-1][sensores.posC+1]){
				accion=TURN_SR;
		}else {
				accion=TURN_L;
		}

		break;

	case suroeste:
		if( (mov[sensores.posF+1][sensores.posC-1] <= mov[sensores.posF+1][sensores.posC+1] && 
			mov[sensores.posF+1][sensores.posC-1] <= mov[sensores.posF][sensores.posC-1])
			 && transitable_lvl0(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2])  ){

				accion=WALK;
		}else if(mov[sensores.posF][sensores.posC-1] <= mov[sensores.posF+1][sensores.posC+1]){
				accion=TURN_SR;
		}else {
				accion=TURN_L;
		}

		break;

	}
	



	mov[sensores.posF][sensores.posC]++;
	cout<<"SOY RESCATADOR: EN MI CASILLA HAY: " << mov[sensores.posF][sensores.posC]<<endl;
	cout<<"SOY RESCATADOR: RODEANDOME TENGO: " << mov[sensores.posF-1][sensores.posC-1] << " " << mov[sensores.posF-1][sensores.posC] << " " << mov[sensores.posF-1][sensores.posC+1] << " " << mov[sensores.posF][sensores.posC+1] << " " << mov[sensores.posF+1][sensores.posC+1] << " " << mov[sensores.posF+1][sensores.posC] << " " << mov[sensores.posF+1][sensores.posC-1] << " " << mov[sensores.posF][sensores.posC-1]<<endl;

 
	//devolver accion
	last_action=accion;

	return accion;
}

Action ComportamientoRescatador::ComportamientoRescatadorNivel_1(Sensores sensores)
{
	// El comportamiento de seguir un camino hasta encontrar un puesto base.

	Action accion;
	//actualizar variables estado

	SituarSensorEnMapaR(mapaResultado, mapaCotas,sensores);

	if(sensores.superficie[0] == 'D') tiene_zapatillas=true;

	
	if( (sensores.agentes[12] == 'a' || sensores.agentes[6] == 'a' || sensores.agentes[2] == 'a' ) && esquives.empty()){
		esquives=evitar_choque(sensores, tiene_zapatillas);
	}

	PonerMuros_Precip_EnMov(sensores, mov);

	

	//realizar la esquiva
	if(!esquives.empty()){
		accion=esquives.front();
		esquives.pop();
	}

	else if(giro45izq != 0){
		accion=TURN_SR;
		giro45izq--;
	}


	switch (sensores.rumbo)
	{
	case norte:
		if( (mov[sensores.posF-1][sensores.posC] <= mov[sensores.posF][sensores.posC-1] &&
			mov[sensores.posF-1][sensores.posC] <= mov[sensores.posF-1][sensores.posC+1] ) && (transitable_lvl1(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2] ) ))  {

				accion=WALK;
		}else if(mov[sensores.posF-1][sensores.posC+1] <= mov[sensores.posF][sensores.posC-1]){
				accion=TURN_SR;
		}else {
				accion=TURN_L;
			}

		break;
	
	case sur:
		if( ( mov[sensores.posF+1][sensores.posC] <= mov[sensores.posF][sensores.posC+1] && 
			mov[sensores.posF+1][sensores.posC] <= mov[sensores.posF+1][sensores.posC-1]  ) && (transitable_lvl1(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2]) ) ){

				accion=WALK;
		}else if(mov[sensores.posF+1][sensores.posC-1] <= mov[sensores.posF][sensores.posC+1]){
				accion=TURN_SR;
		}else {
				accion=TURN_L;
		}

		break;

	case este:
		if( (mov[sensores.posF][sensores.posC+1] <= mov[sensores.posF-1][sensores.posC] && 
			mov[sensores.posF][sensores.posC+1] <= mov[sensores.posF+1][sensores.posC+1] ) && (transitable_lvl1(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2]) ) ){

				accion=WALK;
		}else if(mov[sensores.posF+1][sensores.posC+1] <= mov[sensores.posF-1][sensores.posC]){
				accion=TURN_SR;
		}else {
				accion=TURN_L;
		}

		break;

	case oeste:
		if( (mov[sensores.posF][sensores.posC-1] <= mov[sensores.posF+1][sensores.posC] && 
			mov[sensores.posF][sensores.posC-1] <= mov[sensores.posF-1][sensores.posC-1] ) && (transitable_lvl1(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2]) ) ){

				accion=WALK;
		}else if(mov[sensores.posF-1][sensores.posC-1] <= mov[sensores.posF+1][sensores.posC]){
				accion=TURN_SR;
		}else {
				accion=TURN_L;
		}

		break;


	case noreste:
		if( (mov[sensores.posF-1][sensores.posC+1] <= mov[sensores.posF-1][sensores.posC-1] && 
			mov[sensores.posF-1][sensores.posC+1] <= mov[sensores.posF][sensores.posC+1]) && (transitable_lvl1(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2]) ) ){

				accion=WALK;
		}else if(mov[sensores.posF][sensores.posC+1] <= mov[sensores.posF-1][sensores.posC-1]){
				accion=TURN_SR;
		}else {
				accion=TURN_L;
		}

		break;


	case noroeste:
		if( (mov[sensores.posF-1][sensores.posC-1] <= mov[sensores.posF+1][sensores.posC-1] && 
			mov[sensores.posF-1][sensores.posC-1] <= mov[sensores.posF][sensores.posC-1] ) && transitable_lvl1(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2]) ){

				accion=WALK;
		}else if(mov[sensores.posF][sensores.posC-1] <= mov[sensores.posF+1][sensores.posC-1]){
				accion=TURN_SR;
		}else {
				accion=TURN_L;
		}
		break;


	case sureste:
		if( (mov[sensores.posF+1][sensores.posC+1] <= mov[sensores.posF-1][sensores.posC+1] && 
			mov[sensores.posF+1][sensores.posC+1] <= mov[sensores.posF+1][sensores.posC] ) && transitable_lvl1(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2])){

				accion=WALK;
		}else if(mov[sensores.posF+1][sensores.posC] <= mov[sensores.posF-1][sensores.posC+1]){
				accion=TURN_SR;
		}else {
				accion=TURN_L;
		}

		break;

	case suroeste:
		if( (mov[sensores.posF+1][sensores.posC-1] <= mov[sensores.posF+1][sensores.posC+1] && 
			mov[sensores.posF+1][sensores.posC-1] <= mov[sensores.posF][sensores.posC-1])
			 && transitable_lvl1(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2])  ){

				accion=WALK;
		}else if(mov[sensores.posF][sensores.posC-1] <= mov[sensores.posF+1][sensores.posC+1]){
				accion=TURN_SR;
		}else {
				accion=TURN_L;
		}

		break;

	}
	



	mov[sensores.posF][sensores.posC]++;
//	cout<<"SOY RESCATADOR: EN MI CASILLA HAY: " << mov[sensores.posF][sensores.posC]<<endl;
//	cout<<"SOY RESCATADOR: RODEANDOME TENGO: " << mov[sensores.posF-1][sensores.posC-1] << " " << mov[sensores.posF-1][sensores.posC] << " " << mov[sensores.posF-1][sensores.posC+1] << " " << mov[sensores.posF][sensores.posC+1] << " " << mov[sensores.posF+1][sensores.posC+1] << " " << mov[sensores.posF+1][sensores.posC] << " " << mov[sensores.posF+1][sensores.posC-1] << " " << mov[sensores.posF][sensores.posC-1]<<endl;

 
	//devolver accion
	last_action=accion;

	return accion;

}

Action ComportamientoRescatador::ComportamientoRescatadorNivel_2(Sensores sensores)
{
	Action accion = IDLE;
    if (!hayPlan){
		// Invocar al método de búsqueda
		EstadoR inicio, fin;
		inicio.f = sensores.posF;
		inicio.c = sensores.posC;
		inicio.brujula = sensores.rumbo;
		inicio.zapatillas = tiene_zapatillas;
		fin.f = sensores.destinoF;
		fin.c = sensores.destinoC;
		plan = Uniforme(inicio, fin, mapaResultado, mapaCotas);
		VisualizaPlan(inicio,plan);
		hayPlan = plan.size() != 0;
    }
    if (hayPlan and plan.size()>0){
        accion = plan.front();
        plan.pop_front();
    }
    if (plan.size()== 0){
        hayPlan = false;
    }
    return accion;
}

Action ComportamientoRescatador::ComportamientoRescatadorNivel_3(Sensores sensores)
{
}

Action ComportamientoRescatador::ComportamientoRescatadorNivel_4(Sensores sensores)
{
}




struct comparar_priorityqueueNR
{
	bool operator()(const NodoR &a, const NodoR &b){
		return a.estado.coste > b.estado.coste;
	}
};

void AnularMatrizR(vector<vector<unsigned char>> &m){
	for (int i = 0; i < m[0].size(); i++){
		for (int j = 0; j < m.size(); j++){
			m[i][j] = 0;
		}
	}
}	

void ComportamientoRescatador::VisualizaPlan(const EstadoR &st, const list<Action> &plan){
AnularMatrizR(mapaConPlan);
EstadoR cst = st;
auto it = plan.begin();
while (it != plan.end()){
	switch (*it){
		case RUN:
			switch (cst.brujula){
				case 0:
					cst.f--;
					break;
				case 1:
					cst.f--;
					cst.c++;
					break;
				case 2:
					cst.c++;
					break;
				case 3:
					cst.f++;
					cst.c++;
					break;
				case 4:
					cst.f++;
					break;
				case 5:
					cst.f++;
					cst.c--;
					break;
				case 6:
					cst.c--;
					break;
				case 7:
					cst.f--;
					cst.c--;
					break;
			}
			mapaConPlan[cst.f][cst.c] = 3;
			break;
		case WALK:
			switch (cst.brujula){
				case 0:
					cst.f--;
					break;
				case 1:
					cst.f--;
					cst.c++;
					break;
				case 2:
					cst.c++;
					break;
				case 3:
					cst.f++;
					cst.c++;
					break;
				case 4:
					cst.f++;
					break;
				case 5:
					cst.f++;
					cst.c--;
					break;
				case 6:
					cst.c--;
					break;
				case 7:
					cst.f--;
					cst.c--;
					break;
			}
			mapaConPlan[cst.f][cst.c] = 1;
			break;
		case TURN_SR:
			cst.brujula = (cst.brujula + 1) % 8;
			break;
		case TURN_L:
			cst.brujula = (cst.brujula + 6) % 8;
			break;
	}
	it++;
}
}


EstadoR NextCasillaRescatador(const EstadoR &st){
	EstadoR siguiente = st;
	switch (st.brujula)
	{
		case norte:
		siguiente.f = st.f - 1;
		break;
		case noreste:
		siguiente.f = st.f - 1;
		siguiente.c = st.c + 1;
			break;
		case este:
			siguiente.c = st.c + 1;
			break;
		case sureste:
			siguiente.f = st.f + 1;
			siguiente.c = st.c + 1;
			break;
		case sur:
			siguiente.f = st.f + 1;
			break;
		case suroeste:
			siguiente.f = st.f + 1;
			siguiente.c = st.c - 1;
			break;
		case oeste:
			siguiente.c = st.c - 1;
			break;
		case noroeste:
			siguiente.f = st.f - 1;
			siguiente.c = st.c - 1;
	}
	return siguiente;
}

bool CasillaAccesibleRescatador(const EstadoR &st, const vector<vector<unsigned char>> &terreno, const vector<vector<unsigned char>> &altura){
	EstadoR next = NextCasillaRescatador(st);
	bool check1 = false,  check3 = false;
	check1 = terreno[next.f][next.c] != 'P' && terreno[next.f][next.c] != 'M' && terreno[next.f][next.c] != 'B';
	if(st.zapatillas){
		check3 = abs(altura[next.f][next.c] - altura[st.f][st.c]) <= 2;

	}else{
		check3 = abs(altura[next.f][next.c] - altura[st.f][st.c]) <= 1;

	}
	return check1 && check3;
}

int costeMoverse(const Action &a, const EstadoR &st, const vector<vector<unsigned char> > &terreno, const vector<vector<unsigned char>> &altura){
	int coste;
	EstadoR next = NextCasillaRescatador(st);
	switch (a)
	{
	case WALK:
		switch (terreno[st.f][st.c])
		{
		case 'A':
			coste = 100;
			if(altura[st.f][st.c] > altura[next.f][next.c])
				coste-=10;
			else if(altura[st.f][st.c] < altura[next.f][next.c])
				coste+=10;
			break;
		case 'T':
			coste = 20;
			if(altura[st.f][st.c] > altura[next.f][next.c])
				coste-=5;
			else if(altura[st.f][st.c] < altura[next.f][next.c])
				coste+=5;
			break;
		case 'S':
			coste = 2;
			if(altura[st.f][st.c] > altura[next.f][next.c])
				coste-=1;
			else if(altura[st.f][st.c] < altura[next.f][next.c])
				coste+=1;
			break;
		default:
			coste = 1;
			break;
		}
		break;
	case RUN:
		switch (terreno[st.f][st.c])
		{
		case 'A':
			coste = 150;
			if(altura[st.f][st.c] > altura[next.f][next.c])
				coste-=15;
			else if(altura[st.f][st.c] < altura[next.f][next.c])
				coste+=15;
			break;
		case 'S':
			coste = 3;
			if(altura[st.f][st.c] > altura[next.f][next.c])
				coste-=2;
			else if(altura[st.f][st.c] < altura[next.f][next.c])
				coste+=2;
			break;
		case 'T':
			coste = 35;
			if(altura[st.f][st.c] > altura[next.f][next.c])
				coste-=5;
			else if(altura[st.f][st.c] < altura[next.f][next.c])
				coste+=5;
			break;
		default:
			coste = 1;
			break;
		}
		break;
	case TURN_L:
		switch (terreno[st.f][st.c])
		{
		case 'A':
			coste = 30;
			break;
		case 'S':
			coste = 1;
			break;
		case 'T':
			coste = 5;
			break;
		default:
			coste = 1;
			break;
		}
		break;
	case TURN_SR:
		switch (terreno[st.f][st.c])
		{
		case 'A':
			coste = 16;
			break;
		case 'S':
			coste = 1;
			break;
		case 'T':
			coste = 3;
			break;
		default:
			coste = 1;
			break;
		}
		break;

	default:
		coste = 0;
		break;
	}

	return coste + st.coste;
}


EstadoR ComportamientoRescatador::applyR(Action a, const EstadoR &st, const vector<vector<unsigned char>> &terreno, const vector<vector<unsigned char>> &altura){

	EstadoR st_result = st;
	EstadoR sig_ubicacion, sig_ubicacion2;

	st_result.coste = costeMoverse(a, st, terreno, altura);
	
	switch (a)
	{
		case WALK: // si prox casilla es transitable 
		sig_ubicacion = NextCasillaRescatador(st);
		if (CasillaAccesibleRescatador(sig_ubicacion, terreno , altura) ){
			st_result = sig_ubicacion;
		}

		break;
		case RUN: // si prox 2 casillas son transitables 
		sig_ubicacion = NextCasillaRescatador(st);
		if (CasillaAccesibleRescatador(sig_ubicacion, terreno , altura) ){
			sig_ubicacion2 = NextCasillaRescatador(sig_ubicacion);
			if (CasillaAccesibleRescatador(sig_ubicacion2, terreno , altura) ){
				st_result = sig_ubicacion2;
			}
		}

		break;
		case TURN_L:
			st_result.brujula = (st_result.brujula+6)%8;
			break;
		case TURN_SR:
			st_result.brujula = (st_result.brujula+1)%8;
			break;

	default:
	break;
	}

	return st_result;
}


void ComportamientoRescatador::PintaPlan(const list<Action> &plan, bool zap)
{
auto it = plan.begin();
while (it != plan.end())
{
if (*it == WALK)
{
cout << "W ";
}
else if (*it == RUN)
{
cout << "R ";
}
else if (*it == TURN_SR)
{
cout << "r ";
}
else if (*it == TURN_L)
{
cout << "L ";
}
else if (*it == CALL_ON)
{
cout << "C ";
}
else if (*it == CALL_OFF)
{
cout << "c ";
}
else if (*it == IDLE)
{
cout << "I ";
}
else
{
cout << "-_ ";
}
it++;
}
cout << "( longitud " << plan.size();
if (zap) cout << "[Z]";
cout << ")\n";
}


list<Action> ComportamientoRescatador::Uniforme(const EstadoR &inicio, const EstadoR &final, const vector<vector<unsigned char>> &terreno, const vector<vector<unsigned char>> &altura){

	NodoR current_node;
	priority_queue<NodoR, vector<NodoR>, comparar_priorityqueueNR> frontier;
	set<NodoR> explored;
	list<Action> plan;

	current_node.estado = inicio;
	bool SolutionFound = (current_node.estado.f == final.f && current_node.estado.c == final.c);

	frontier.push(current_node);
	while(!frontier.empty() && !SolutionFound){

		if(terreno[current_node.estado.f][current_node.estado.c] == 'D'){
			current_node.estado.zapatillas = true;
		}

		frontier.pop();
		explored.insert(current_node);
		SolutionFound = (current_node.estado.f == final.f && current_node.estado.c == final.c);

		if (!SolutionFound){
			//Generar hijo WALK
			NodoR child_walk = current_node;
			child_walk.estado = applyR(WALK, current_node.estado, terreno, altura);
			child_walk.secuencia.push_back(WALK);
			if (explored.find(child_walk) == explored.end())
				frontier.push(child_walk);

			//Generar hijo Run
			NodoR child_run = current_node;
			child_run.estado = applyR(RUN, current_node.estado, terreno, altura);
			child_run.secuencia.push_back(RUN);
			if (explored.find(child_run) == explored.end())
				frontier.push(child_run);


			//Generar hijo TURN_L
			NodoR child_turnl = current_node;
			child_turnl.estado = applyR(TURN_L, current_node.estado, terreno, altura);
			child_turnl.secuencia.push_back(TURN_L);
			if (explored.find(child_turnl) == explored.end())
				frontier.push(child_turnl);


			//Generar hijo TURN_SR
			NodoR child_turnsr = current_node;
			child_turnsr.estado = applyR(TURN_SR, current_node.estado, terreno, altura);
			child_turnsr.secuencia.push_back(TURN_SR);
			if (explored.find(child_turnsr) == explored.end())
				frontier.push(child_turnsr);


		}

		if (!SolutionFound && !frontier.empty()){
			current_node = frontier.top();
			while(!frontier.empty() && explored.find(current_node) != explored.end()){
				frontier.pop();
				if (!frontier.empty()){
					current_node = frontier.top();
				}
			}
		}
	}

	if (SolutionFound){
		plan = current_node.secuencia;
		PintaPlan(current_node.secuencia, current_node.estado.zapatillas);
	}

	return plan;
	}


