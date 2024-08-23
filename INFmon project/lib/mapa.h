#ifndef mapa_h
#define mapa_h

#include<stdio.h>
#include "infmons.h"
#include "raylib.h"
#include "menus.h"
#include "constantes.h"

int inicializaMapa(int processoAtual, int *isPrimeiraVez, Personagem *jogador, int *fase);
void desenhaMapa(char mapa[MAX_LINHA][MAX_COLUNA-1], int *isPrimeiraVez, Personagem *jogador);
void moveJogador(char mapa[MAX_LINHA][MAX_COLUNA-1], int *processoInternoAtual, Personagem *jogador);
#endif // mapa_h
