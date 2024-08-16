#ifndef infmons_h
#define infmons_h


#include "contants.h"
#include<stdio.h>
#include<string.h>

typedef struct {
    char nome[50];
    float dano;
    char tipo;
} Ataque;

typedef struct {
    char nome[100];
    int nivel;
    float vida;
    int VIDA_MAX;
    int ataque;
    int defesa;
    int xp;
    char tipo;
    Ataque ataques[N_ATAQUES];
} Infmon;

typedef struct {
    int nInfmons;
    Infmon infmons[MAX_INFMONS];
    int posX;
    int posY;
} Personagem;

Infmon criaPokemonAliadoAgua();
Infmon criaPokemonInimigoFogo();
Infmon criaPokemonInimigoTerra();
void adicionaINFmon(char escolha);
void criaArquivoDeAtaques();
void leArquivosDeAtaques();
#endif // infmons_h
