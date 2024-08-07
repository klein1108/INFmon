#include "infmons.h"

void inicializaMapa(int processoAtual);
void desenhaMapa(char mapa[MAX_LINHA][MAX_COLUNA], int *isPrimeiraVez, Personagem *jogador);
void moveJogador(Personagem *jogador, char mapa[MAX_LINHA][MAX_COLUNA], int *processoInternoAtual);
