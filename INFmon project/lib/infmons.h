#ifndef infmons_h
#define infmons_h


#include "constantes.h"
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
    int xpMax;
    char tipo;
    float totalDanoDado;
    Ataque ataques[N_ATAQUES];
} Infmon;

typedef struct {
    int nInfmons;
    Infmon infmons[MAX_INFMONS];
    int posX;
    int posY;
} Personagem;
//
//Personagem jogador;

typedef struct{
    Personagem jogador;
    int fase;
}Save;

Infmon criaPokemonAliadoAgua();
Infmon criaPokemonInimigoFogo();
//Infmon criaPokemonInimigoTerra();
void adicionaInfmon(Personagem *jogador, Infmon novoInfmon);
Infmon geraInicial(char tipo);
Infmon criaINFmonAleatorio(int fase);
//void criaArquivoDeAtaques();
//void leArquivosDeAtaques();
int salvaJogo(Save jogoAtual);
int carregaJogo(Save *jogoSalvo);


#endif // infmons_h
