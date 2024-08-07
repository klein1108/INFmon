#include "contants.h"

typedef struct {
    char nome[50];
    int dano;
    char tipo;
} Ataque;

typedef struct {
    char nome[100];
    int nivel;
    int vida;
    int ataque;
    int defesa;
    int xp;
    char tipo;
    Ataque ataques[N_ATAQUES];
} Infmon;

typedef struct {
    Infmon infmons[MAX_INFMONS];
    int posX;
    int posY;
} Personagem;

Infmon criaPokemonAliadoAgua();
Infmon criaPokemonInimigoFogo();
void adicionaINFmon(char escolha);
//void criaArquivoDeAtaques();
void leArquivosDeAtaques();
