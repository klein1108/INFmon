#ifndef mapa_h
#define mapa_h

#include<stdio.h>
#include "infmons.h"
#include "raylib.h"
#include "menus.h"
#include "contants.h"

void inicializaMapa(int processoAtual);
void desenhaMapa(char mapa[MAX_LINHA][MAX_COLUNA-1], int *isPrimeiraVez, Personagem *jogador);
void moveJogador(Personagem *jogador, char mapa[MAX_LINHA][MAX_COLUNA-1], int *processoInternoAtual, char sla);
#endif // mapa_h
