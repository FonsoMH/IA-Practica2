#include "../Comportamientos_Jugador/auxiliar.hpp"
#include <iostream>
#include "motorlib/util.h"
#include <list>
#include <set>

Action ComportamientoAuxiliar::think(Sensores sensores)
{
    Action accion = IDLE;

    switch (sensores.nivel)
    {
    case 0:
        accion = ComportamientoAuxiliarNivel_0(sensores);
        break;
    case 1:
        accion = ComportamientoAuxiliarNivel_1(sensores);
        break;
    case 2:
        // accion = ComportamientoAuxiliarNivel_2(sensores);
        break;
    case 3:
        // accion = ComportamientoAuxiliarNivel_3(sensores);
        accion = ComportamientoAuxiliarNivel_E(sensores);
        break;
    case 4:
        // accion = ComportamientoAuxiliarNivel_4(sensores);
        break;
    }

    return accion;
}

int ComportamientoAuxiliar::interact(Action accion, int valor)
{
    return 0;
}

int VeoCasillaInteresanteA(char i, char c, char d) {
    if (c == 'X') return 2;
    else if (i == 'X') return 1;
    else if (d == 'X') return 3;
    else if (c == 'D') return 2;
    else if (i == 'D') return 1;
    else if (d == 'D') return 3;
    else if (c == 'C') return 2;
    else if (i == 'C') return 1;
    else if (d == 'C') return 3;
    else return 0;
}

int VeoCasillaInteresanteALVL1(char i, char c, char d, bool zap){
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

char ViablePorAlturaA(char casilla, int dif) {
    if (abs(dif) <= 1)
        return casilla;
    else
        return 'P';
}

bool transitable_lvl0A(unsigned char casilla , int dif, bool zap, unsigned char casilla_ag){
	if( (abs(dif)<=1) && ((casilla=='C' || casilla=='D' || casilla=='X') && casilla_ag=='_') ){
		cout<<"SI ES TRANSITABLE"<<endl;
		return true;
	}
	else {
		cout<<"NO ES TRANSITABLE"<<endl; 
		return false;
	}
}

bool transitable_lvl1A(unsigned char casilla , int dif, bool zap, unsigned char casilla_ag){
	if(!zap){
		if( (abs(dif)<=1) && ((casilla!='P' && casilla!='M' && casilla !='B') && casilla_ag=='_') ){
			return true;
		}
		else {
			return false;
		}
	}else{
		if( (abs(dif)<=1) && ((casilla!='P' && casilla !='M') && casilla_ag=='_') ){
			return true;
		}
		else {
			return false;
		}
	}
}



void MOV_INTRANS_A(Sensores sensores, vector<vector<int> > &mov){
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



void PonerMuros_Precip_EnMovA_LVL0(Sensores sensores, vector<vector<int> > &mov){
	switch (sensores.rumbo) {
        case norte:
            if(sensores.superficie[1] == 'P' || sensores.superficie[1] == 'M'  ) {
                mov[sensores.posF - 1][sensores.posC - 1] = 5000;
            }
            if(sensores.superficie[2] == 'P' || sensores.superficie[1] == 'M'  ) {
                mov[sensores.posF - 1][sensores.posC] = 5000;
            }
            if(sensores.superficie[3] == 'P' || sensores.superficie[1] == 'M'  ) {
                mov[sensores.posF - 1][sensores.posC + 1] = 5000;
            }
            break;
        case sur:
            if(sensores.superficie[1] == 'P' || sensores.superficie[1] == 'M'  ) {
                mov[sensores.posF + 1][sensores.posC + 1] = 5000;
            }
            if(sensores.superficie[2] == 'P' || sensores.superficie[1] == 'M'  ) {
                mov[sensores.posF + 1][sensores.posC] = 5000;
            }
            if(sensores.superficie[3] == 'P' || sensores.superficie[1] == 'M'  ) {
                mov[sensores.posF + 1][sensores.posC - 1] = 5000;
            }
            break;
        case este:
            if(sensores.superficie[1] == 'P' || sensores.superficie[1] == 'M'  ) {
                mov[sensores.posF - 1][sensores.posC + 1] = 5000;
            }
            if(sensores.superficie[2] == 'P' || sensores.superficie[1] == 'M') {
                mov[sensores.posF][sensores.posC + 1] = 5000;
            }
            if(sensores.superficie[3] == 'P' || sensores.superficie[1] == 'M'  ) {
                mov[sensores.posF + 1][sensores.posC + 1] = 5000;
            }
            break;
        case oeste:
            if(sensores.superficie[1] == 'P' || sensores.superficie[1] == 'M'  ) {
                mov[sensores.posF + 1][sensores.posC - 1] = 5000;
            }
            if(sensores.superficie[2] == 'P' || sensores.superficie[1] == 'M' ) {
                mov[sensores.posF][sensores.posC - 1] = 5000;
            }
            if(sensores.superficie[3] == 'P' || sensores.superficie[1] == 'M'  ) {
                mov[sensores.posF - 1][sensores.posC - 1] = 5000;
            }
            break;
        case noreste:
            if(sensores.superficie[1] == 'P' || sensores.superficie[1] == 'M'  ) {
                mov[sensores.posF - 1][sensores.posC] = 5000;
            }
            if(sensores.superficie[2] == 'P' || sensores.superficie[1] == 'M'  ) {
                mov[sensores.posF - 1][sensores.posC + 1] = 5000;
            }
            if(sensores.superficie[3] == 'P' || sensores.superficie[1] == 'M'  ) {
                mov[sensores.posF][sensores.posC + 1] = 5000;
            }
            break;
        case noroeste:
            if(sensores.superficie[1] == 'P' || sensores.superficie[1] == 'M'  ) {
                mov[sensores.posF][sensores.posC - 1] = 5000;
            }
            if(sensores.superficie[2] == 'P' || sensores.superficie[1] == 'M'  ) {
                mov[sensores.posF - 1][sensores.posC - 1] = 5000;
            }
            if(sensores.superficie[3] == 'P' || sensores.superficie[1] == 'M') {
                mov[sensores.posF - 1][sensores.posC] = 5000;
            }
            break;
        case sureste:
            if(sensores.superficie[1] == 'P' || sensores.superficie[1] == 'M'  ) {
                mov[sensores.posF][sensores.posC + 1] = 5000;
            }
            if(sensores.superficie[2] == 'P' || sensores.superficie[1] == 'M'  ) {
                mov[sensores.posF + 1][sensores.posC + 1] = 5000;
            }
            if(sensores.superficie[3] == 'P' || sensores.superficie[1] == 'M' ) {
                mov[sensores.posF + 1][sensores.posC] = 5000;
            }
            break;
        case suroeste:
            if(sensores.superficie[1] == 'P' || sensores.superficie[1] == 'M'  ) {
                mov[sensores.posF + 1][sensores.posC] = 5000;
            }
            if(sensores.superficie[2] == 'P' || sensores.superficie[1] == 'M' ) {
                mov[sensores.posF + 1][sensores.posC - 1] = 5000;
            }
            if(sensores.superficie[3] == 'P' || sensores.superficie[1] == 'M' ) {
                mov[sensores.posF][sensores.posC - 1] = 5000; 
            }
            break;
    }
}



void SituarSensorEnMapaA(vector<vector<unsigned char> > &m, vector<vector<unsigned char> > &a, Sensores sensores){

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




Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_0(Sensores sensores)
{
    Action accion;

    // Actualizar variables de estado
    if (sensores.superficie[0] == 'D') tiene_zapatillas = true;
    SituarSensorEnMapaA(mapaResultado, mapaCotas, sensores);
	MOV_INTRANS_A(sensores, mov);
	
	
    // Definir nuevo comportamiento
    if (sensores.superficie[0] == 'X') {
        accion = IDLE;
    }
    else if (giro45izq != 0) {
        accion = TURN_SR;
        giro45izq--;
    }
    else {
        
		switch (sensores.rumbo)
		{
		case norte:
			if( (mov[sensores.posF-1][sensores.posC] <= mov[sensores.posF][sensores.posC-1] &&
				mov[sensores.posF-1][sensores.posC] <= mov[sensores.posF-1][sensores.posC+1] ) && (transitable_lvl0A(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2] ) ))  {
	
					accion=WALK;
			}else if(mov[sensores.posF-1][sensores.posC+1] <= mov[sensores.posF][sensores.posC-1]){
					accion=TURN_SR;
			}else {
					accion=TURN_SR;
					giro45izq =5;
				}
	
			break;
		
		case sur:
			if( ( mov[sensores.posF+1][sensores.posC] <= mov[sensores.posF][sensores.posC+1] && 
				mov[sensores.posF+1][sensores.posC] <= mov[sensores.posF+1][sensores.posC-1]  ) && (transitable_lvl0A(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2]) ) ){
	
					accion=WALK;
			}else if(mov[sensores.posF+1][sensores.posC-1] <= mov[sensores.posF][sensores.posC+1]){
					accion=TURN_SR;
			}else {
				accion=TURN_SR;
				giro45izq =5;
			}
	
			break;
	
		case este:
			if( (mov[sensores.posF][sensores.posC+1] <= mov[sensores.posF-1][sensores.posC] && 
				mov[sensores.posF][sensores.posC+1] <= mov[sensores.posF+1][sensores.posC+1] ) && (transitable_lvl0A(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2]) ) ){
	
					accion=WALK;
			}else if(mov[sensores.posF+1][sensores.posC+1] <= mov[sensores.posF-1][sensores.posC]){
					accion=TURN_SR;
			}else {
				accion=TURN_SR;
				giro45izq =5;
			}
	
			break;
	
		case oeste:
			if( (mov[sensores.posF][sensores.posC-1] <= mov[sensores.posF+1][sensores.posC] && 
				mov[sensores.posF][sensores.posC-1] <= mov[sensores.posF-1][sensores.posC-1] ) && (transitable_lvl0A(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2]) ) ){
	
					accion=WALK;
			}else if(mov[sensores.posF-1][sensores.posC-1] <= mov[sensores.posF+1][sensores.posC]){
					accion=TURN_SR;
			}else {
				accion=TURN_SR;
				giro45izq =5;
			}
	
			break;
	
	
		case noreste:
			if( (mov[sensores.posF-1][sensores.posC+1] <= mov[sensores.posF-1][sensores.posC-1] && 
				mov[sensores.posF-1][sensores.posC+1] <= mov[sensores.posF][sensores.posC+1]) && (transitable_lvl0A(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2]) ) ){
	
					accion=WALK;
			}else if(mov[sensores.posF][sensores.posC+1] <= mov[sensores.posF-1][sensores.posC-1]){
					accion=TURN_SR;
			}else {
				accion=TURN_SR;
				giro45izq =5;
			}
	
			break;
	
	
		case noroeste:
			if( (mov[sensores.posF-1][sensores.posC-1] <= mov[sensores.posF+1][sensores.posC-1] && 
				mov[sensores.posF-1][sensores.posC-1] <= mov[sensores.posF][sensores.posC-1] ) && transitable_lvl0A(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2]) ){
	
					accion=WALK;
			}else if(mov[sensores.posF][sensores.posC-1] <= mov[sensores.posF+1][sensores.posC-1]){
					accion=TURN_SR;
			}else {
				accion=TURN_SR;
				giro45izq =5;
			}
			break;
	
	
		case sureste:
			if( (mov[sensores.posF+1][sensores.posC+1] <= mov[sensores.posF-1][sensores.posC+1] && 
				mov[sensores.posF+1][sensores.posC+1] <= mov[sensores.posF+1][sensores.posC] ) && transitable_lvl0A(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2])){
	
					accion=WALK;
			}else if(mov[sensores.posF+1][sensores.posC] <= mov[sensores.posF-1][sensores.posC+1]){
					accion=TURN_SR;
			}else {
				accion=TURN_SR;
				giro45izq =5;
			}
	
			break;
	
		case suroeste:
			if( (mov[sensores.posF+1][sensores.posC-1] <= mov[sensores.posF+1][sensores.posC+1] && 
				mov[sensores.posF+1][sensores.posC-1] <= mov[sensores.posF][sensores.posC-1])
				 && transitable_lvl0A(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2])  ){
	
					accion=WALK;
			}else if(mov[sensores.posF][sensores.posC-1] <= mov[sensores.posF+1][sensores.posC+1]){
					accion=TURN_SR;
			}else {
				    accion=TURN_SR;
					giro45izq =5;
			}
	
			break;
	
		}

    }	

	
    // Devolver acción
	mov[sensores.posF][sensores.posC]++;
//	cout<<"SOY AUXILIAR: EN MI CASILLA HAY: " << mov[sensores.posF][sensores.posC]<<endl;
//	cout<<"SOY AUXILIAR: RODEANDOME TENGO: " << mov[sensores.posF-1][sensores.posC-1] << " " << mov[sensores.posF-1][sensores.posC] << " " << mov[sensores.posF-1][sensores.posC+1] << " " << mov[sensores.posF][sensores.posC+1] << " " << mov[sensores.posF+1][sensores.posC+1] << " " << mov[sensores.posF+1][sensores.posC] << " " << mov[sensores.posF+1][sensores.posC-1] << " " << mov[sensores.posF][sensores.posC-1]<<endl;
    last_action = accion;
    return accion;
}


Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_1(Sensores sensores)
{
    Action accion;

    // Actualizar variables de estado
    if (sensores.superficie[0] == 'D') tiene_zapatillas = true;
    SituarSensorEnMapaA(mapaResultado, mapaCotas, sensores);
	PonerMuros_Precip_EnMovA_LVL0(sensores, mov);
	
	
    // Definir nuevo comportamiento
    if (sensores.superficie[0] == 'X') {
        accion = IDLE;
    }
    else if (giro45izq != 0) {
        accion = TURN_SR;
        giro45izq--;
		cout<<"ESTOY GIRANDO IZQ"<<endl;
    }
    else {
        
		switch (sensores.rumbo)
		{
		case norte:
			if( (mov[sensores.posF-1][sensores.posC] <= mov[sensores.posF][sensores.posC-1] &&
				mov[sensores.posF-1][sensores.posC] <= mov[sensores.posF-1][sensores.posC+1] ) && (transitable_lvl1A(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2] ) ))  {
	
					accion=WALK;
			}else if(mov[sensores.posF-1][sensores.posC+1] <= mov[sensores.posF][sensores.posC-1]){
					accion=TURN_SR;
			}else {
					accion=TURN_SR;
					giro45izq =5;
				}
	
			break;
		
		case sur:
			if( ( mov[sensores.posF+1][sensores.posC] <= mov[sensores.posF][sensores.posC+1] && 
				mov[sensores.posF+1][sensores.posC] <= mov[sensores.posF+1][sensores.posC-1]  ) && (transitable_lvl1A(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2]) ) ){
	
					accion=WALK;
			}else if(mov[sensores.posF+1][sensores.posC-1] <= mov[sensores.posF][sensores.posC+1]){
					accion=TURN_SR;
			}else {
				accion=TURN_SR;
				giro45izq =5;
			}
	
			break;
	
		case este:
			if( (mov[sensores.posF][sensores.posC+1] <= mov[sensores.posF-1][sensores.posC] && 
				mov[sensores.posF][sensores.posC+1] <= mov[sensores.posF+1][sensores.posC+1] ) && (transitable_lvl1A(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2]) ) ){
	
					accion=WALK;
			}else if(mov[sensores.posF+1][sensores.posC+1] <= mov[sensores.posF-1][sensores.posC]){
					accion=TURN_SR;
			}else {
				accion=TURN_SR;
				giro45izq =5;
			}
	
			break;
	
		case oeste:
			if( (mov[sensores.posF][sensores.posC-1] <= mov[sensores.posF+1][sensores.posC] && 
				mov[sensores.posF][sensores.posC-1] <= mov[sensores.posF-1][sensores.posC-1] ) && (transitable_lvl1A(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2]) ) ){
	
					accion=WALK;
			}else if(mov[sensores.posF-1][sensores.posC-1] <= mov[sensores.posF+1][sensores.posC]){
					accion=TURN_SR;
			}else {
				accion=TURN_SR;
				giro45izq =5;
			}
	
			break;
	
	
		case noreste:
			if( (mov[sensores.posF-1][sensores.posC+1] <= mov[sensores.posF-1][sensores.posC-1] && 
				mov[sensores.posF-1][sensores.posC+1] <= mov[sensores.posF][sensores.posC+1]) && (transitable_lvl1A(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2]) ) ){
	
					accion=WALK;
			}else if(mov[sensores.posF][sensores.posC+1] <= mov[sensores.posF-1][sensores.posC-1]){
					accion=TURN_SR;
			}else {
				accion=TURN_SR;
				giro45izq =5;
			}
	
			break;
	
	
		case noroeste:
			if( (mov[sensores.posF-1][sensores.posC-1] <= mov[sensores.posF+1][sensores.posC-1] && 
				mov[sensores.posF-1][sensores.posC-1] <= mov[sensores.posF][sensores.posC-1] ) && transitable_lvl1A(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2]) ){
	
					accion=WALK;
			}else if(mov[sensores.posF][sensores.posC-1] <= mov[sensores.posF+1][sensores.posC-1]){
					accion=TURN_SR;
			}else {
				accion=TURN_SR;
				giro45izq =5;
			}
			break;
	
	
		case sureste:
			if( (mov[sensores.posF+1][sensores.posC+1] <= mov[sensores.posF-1][sensores.posC+1] && 
				mov[sensores.posF+1][sensores.posC+1] <= mov[sensores.posF+1][sensores.posC] ) && transitable_lvl1A(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2])){
	
					accion=WALK;
			}else if(mov[sensores.posF+1][sensores.posC] <= mov[sensores.posF-1][sensores.posC+1]){
					accion=TURN_SR;
			}else {
				accion=TURN_SR;
				giro45izq =5;
			}
	
			break;
	
		case suroeste:
			if( (mov[sensores.posF+1][sensores.posC-1] <= mov[sensores.posF+1][sensores.posC+1] && 
				mov[sensores.posF+1][sensores.posC-1] <= mov[sensores.posF][sensores.posC-1])
				 && transitable_lvl1A(sensores.superficie[2],sensores.cota[2]-sensores.cota[0], tiene_zapatillas, sensores.agentes[2])  ){
	
					accion=WALK;
			}else if(mov[sensores.posF][sensores.posC-1] <= mov[sensores.posF+1][sensores.posC+1]){
					accion=TURN_SR;
			}else {
				    accion=TURN_SR;
					giro45izq =5;
			}
	
			break;
	
		}

    }	

	
    // Devolver acción
	mov[sensores.posF][sensores.posC]++;
	cout<<"SOY AUXILIAR: EN MI CASILLA HAY: " << mov[sensores.posF][sensores.posC]<<endl;
	cout<<"SOY AUXILIAR: RODEANDOME TENGO: " << mov[sensores.posF-1][sensores.posC-1] << " " << mov[sensores.posF-1][sensores.posC] << " " << mov[sensores.posF-1][sensores.posC+1] << " " << mov[sensores.posF][sensores.posC+1] << " " << mov[sensores.posF+1][sensores.posC+1] << " " << mov[sensores.posF+1][sensores.posC] << " " << mov[sensores.posF+1][sensores.posC-1] << " " << mov[sensores.posF][sensores.posC-1]<<endl;
    last_action = accion;
    return accion;
}


Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_2(Sensores sensores)
{
	return IDLE;
}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_3(Sensores sensores)
{
	return IDLE;
}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_4(Sensores sensores)
{
	return IDLE;
}


void AnularMatrizA(vector<vector<unsigned char>> &a){
	for (int i = 0; i < a[0].size(); i++){
		for (int j = 0; j < a.size(); j++){
			a[i][j] = 0;
		}
	}
}

void ComportamientoAuxiliar::VisualizaPlan(const EstadoA &st, const list<Action> &plan){
	AnularMatrizA(mapaConPlan);
	EstadoA cst = st;

	auto it = plan.begin();
	while (it != plan.end())
	{
		switch (*it)
		{
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
				mapaConPlan[cst.f][cst.c] = 2;
				break;
			case TURN_SR:
				cst.brujula = (cst.brujula + 1) % 8;
				break;
			}
			it++;
	}
}

EstadoA NextCasillaAuxiliar(const EstadoA &st){
	EstadoA siguiente = st;
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

bool CasillaAccesibleAuxiliar(const EstadoA &st, const vector<vector<unsigned char>> &terreno, const vector<vector<unsigned char>> &altura){
	EstadoA next = NextCasillaAuxiliar(st);
	bool check1 = false, check2 = false, check3 = false;
	check1 = terreno[next.f][next.c] != 'P' and terreno[next.f][next.c] != 'M';
	check2 = terreno[next.f][next.c] != 'B' or (terreno[next.f][next.c] == 'B' and st.zapatillas);
	check3 = abs(altura[next.f][next.c] - altura[st.f][st.c]) <= 1;
	return check1 and check2 and check3;
}


EstadoA applyA(Action accion, const EstadoA & st, const vector<vector<unsigned char>> &terreno, const vector<vector<unsigned char>> &altura){

	EstadoA next = st;
	switch(accion){
		case WALK:
		if (CasillaAccesibleAuxiliar(st,terreno,altura)){
				next = NextCasillaAuxiliar(st);
			}
		break;
		case TURN_SR:
			next.brujula = (next.brujula+1)%8;
			break;
	}
	return next;
}

bool Find (const NodoA & st, const list<NodoA> &lista){
	auto it = lista.begin();
	while (it != lista.end() and !((*it) == st)){
		it++;
	}
	return (it != lista.end());
}

void ComportamientoAuxiliar::PintaPlan(const list<Action> &plan, bool zap){
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


list<Action> ComportamientoAuxiliar::AnchuraAuxiliar(const EstadoA &inicio, const EstadoA &final, const vector<vector<unsigned char>> &terreno, const vector<vector<unsigned char>> &altura){
    NodoA current_node;
    list<NodoA> frontier;
    list<NodoA> explored;
    list<Action> path;

	current_node.estado = inicio;
	frontier.push_back(current_node);
	bool SolutionFound = (current_node.estado.f == final.f && current_node.estado.c == final.c);
	while(!SolutionFound && !frontier.empty()){
		frontier.pop_front();
		explored.push_back(current_node);

		//compruebo zapas
		if(terreno[current_node.estado.f][current_node.estado.c]=='D'){
			current_node.estado.zapatillas=true;
		}

		//Generar hijo walk
		NodoA child_WALK = current_node;
		child_WALK.estado = applyA(WALK, current_node.estado, terreno, altura);
		if(child_WALK.estado.f == final.f && child_WALK.estado.c == final.c){
			//el hijo generado es solucion
			child_WALK.secuencia.push_back(WALK);
			current_node=child_WALK;
			SolutionFound=true;
		}

		else if(!Find(child_WALK,frontier) && !Find(child_WALK, explored)){
			//se mete a frontier despues de añadir a secuencia la accion
			child_WALK.secuencia.push_back(WALK);
			frontier.push_back(child_WALK);
		}

		//generar hijo de aplicar TURN_SR
		if(!SolutionFound){
			NodoA child_TURN_SR = current_node;
			child_TURN_SR.estado = applyA(TURN_SR, current_node.estado, terreno, altura);
			if(!Find(child_TURN_SR, frontier) && !Find(child_TURN_SR, explored)){
				child_TURN_SR.secuencia.push_back(TURN_SR);
				frontier.push_back(child_TURN_SR);
			}
		}

		if(!SolutionFound && !frontier.empty()){
			current_node = frontier.front();
			SolutionFound = (current_node.estado.f == final.f && current_node.estado.c == final.c);
		}

	}

	if (SolutionFound) path = current_node.secuencia;

	return path;
    
}

list<Action> ComportamientoAuxiliar::AnchuraAuxiliar_V2(const EstadoA &inicio, const EstadoA &final, const vector<vector<unsigned char>> &terreno, const vector<vector<unsigned char>> &altura){
	NodoA current_node;
	list<NodoA> frontier;
	set<NodoA> explored;
	list<Action> path;

	current_node.estado = inicio;
	frontier.push_back(current_node);
	bool SolutionFound = (current_node.estado.f == final.f && current_node.estado.c == final.c);
	while(!SolutionFound && !frontier.empty()){
		frontier.pop_front();
		explored.insert(current_node);
		//compruebo si hay zapas
		if(terreno[current_node.estado.f][current_node.estado.c] == 'D'){
			current_node.estado.zapatillas = true;
		}
		//Generar hijo WALK
		NodoA child_WALK = current_node;
		child_WALK.estado = applyA(WALK, current_node.estado, terreno, altura);
		if(child_WALK.estado.f == final.f && child_WALK.estado.c == final.c){
			//hijo es sol
			child_WALK.secuencia.push_back(WALK);
			current_node = child_WALK;
			SolutionFound = true;
		}
		else if(explored.find(child_WALK) == explored.end()){
			child_WALK.secuencia.push_back(WALK);
			frontier.push_back(child_WALK);
		}

		if(!SolutionFound){
			NodoA child_TURN_SR = current_node;
			child_TURN_SR.estado = applyA(TURN_SR, current_node.estado, terreno, altura);
			if(explored.find(child_TURN_SR) == explored.end()){
				child_TURN_SR.secuencia.push_back(TURN_SR);
				frontier.push_back(child_TURN_SR);
			}
		}

		if(!SolutionFound && !frontier.empty()){
			current_node = frontier.front();
			while(explored.find(current_node)!=explored.end() && !frontier.empty()){
				frontier.pop_front();
				current_node=frontier.front();
			}
		}

	}

	if (SolutionFound) path = current_node.secuencia;

	return path;
}

list<Action> AvanzaASaltosDeCaballo(){
    list<Action> secuencia;
    secuencia.push_back(WALK);
    secuencia.push_back(WALK);
    secuencia.push_back(TURN_SR);
    secuencia.push_back(TURN_SR);
    secuencia.push_back(WALK);
    return secuencia;
}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_E(Sensores sensores)
{
    Action accion = IDLE;
    if (!hayPlan){
		// Invocar al método de búsqueda
		EstadoA inicio, fin;
		inicio.f = sensores.posF;
		inicio.c = sensores.posC;
		inicio.brujula = sensores.rumbo;
		inicio.zapatillas = tiene_zapatillas;
		fin.f = sensores.destinoF;
		fin.c = sensores.destinoC;
		plan = AnchuraAuxiliar_V2(inicio, fin, mapaResultado, mapaCotas);
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
