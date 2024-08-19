#ifndef mapa_h
#define mapa_h

#include<stdio.h>
#include "infmons.h"
#include "raylib.h"
#include "menus.h"
#include "contants.h"

int inicializaMapa(int processoAtual, int isPrimeiraVez);
void desenhaMapa(char mapa[MAX_LINHA][MAX_COLUNA-1], int *isPrimeiraVez);
void moveJogador(char mapa[MAX_LINHA][MAX_COLUNA-1], int *processoInternoAtual);
#endif // mapa_h
