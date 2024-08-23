#include "../lib/infmons.h"
static Ataque ataqueBasico;
static Ataque ataqueMedio;

Infmon criaINFmonAleatorio(int fase){
    Ataque ataqueForte;
    Infmon infmon;
    int tipo = sorteiaProbabilidade(3);

    switch (tipo) {
        case 0:
            infmon.tipo = 'A';
            strcpy(infmon.nome, "Gotinha");
            strcpy(ataqueForte.nome, "Gotejar");
            ataqueForte.dano = 4;
            ataqueForte.tipo = TIPO_AGUA;
            break;
        case 1:
            infmon.tipo = 'T';
            strcpy(infmon.nome, "Folhinha");
            strcpy(ataqueForte.nome, "Florir");
            ataqueForte.dano = 4;
            ataqueForte.tipo = TIPO_TERRA;
            break;
        case 2:
            infmon.tipo = 'F';
            strcpy(infmon.nome, "Chaminha");
            strcpy(ataqueForte.nome, "Queimar");
            ataqueForte.dano = 4;
            ataqueForte.tipo = TIPO_FOGO;
            break;
    }
    strcpy(ataqueBasico.nome, "Morder");
    ataqueBasico.dano = 2;
    ataqueBasico.tipo = TIPO_NORMAL;

    strcpy(ataqueMedio.nome, "Chutar");
    ataqueMedio.dano = 3;
    ataqueBasico.tipo = TIPO_NORMAL;

    infmon.nivel = fase*(sorteiaProbabilidade(4)+1);
    infmon.VIDA_MAX = (infmon.nivel-1)*20 + 100;
    infmon.vida = infmon.VIDA_MAX;
    infmon.xp = 0;
    infmon.ataque = infmon.nivel + ATAQUE_DEFESA_DEFAULT;
    infmon.defesa = infmon.nivel + ATAQUE_DEFESA_DEFAULT;
    infmon.ataques[0] = ataqueBasico;
    infmon.ataques[1] = ataqueMedio;
    infmon.ataques[2] = ataqueForte;
    infmon.totalDanoDado = 0;
    infmon.xpMax = infmon.nivel*MIN_XP;

    return infmon;
}

void adicionaInfmon(Personagem *jogador, Infmon novoInfmon){
    novoInfmon.vida = novoInfmon.VIDA_MAX;
    jogador->infmons[jogador->nInfmons] = novoInfmon;
    jogador->nInfmons++;
}

Infmon geraInicial(char tipo){
    Infmon inicial;
    Ataque ataqueForte;

    switch (tipo) {
        case 'A':
            inicial.tipo = 'A';
            strcpy(inicial.nome, "Gotinha");
            strcpy(ataqueForte.nome, "Gotejar");
            ataqueForte.dano = 4;
            ataqueForte.tipo = TIPO_AGUA;
            break;
        case 'T':
            inicial.tipo = 'T';
            strcpy(inicial.nome, "Folhinha");
            strcpy(ataqueForte.nome, "Florir");
            ataqueForte.dano = 4;
            ataqueForte.tipo = TIPO_TERRA;
            break;
        case 'F':
            inicial.tipo = 'F';
            strcpy(inicial.nome, "Chaminha");
            strcpy(ataqueForte.nome, "Queimar");
            ataqueForte.dano = 4;
            ataqueForte.tipo = TIPO_FOGO;
            break;
    }
    strcpy(ataqueBasico.nome, "Morder");
    ataqueBasico.dano = 2;
    ataqueBasico.tipo = TIPO_NORMAL;

    strcpy(ataqueMedio.nome, "Chutar");
    ataqueMedio.dano = 3;
    ataqueBasico.tipo = TIPO_NORMAL;

    inicial.nivel = 1;
    inicial.VIDA_MAX = 100;
    inicial.vida = inicial.VIDA_MAX;
    inicial.xp = 0;
    inicial.ataque = inicial.nivel + ATAQUE_DEFESA_DEFAULT;
    inicial.defesa = inicial.nivel + ATAQUE_DEFESA_DEFAULT;
    inicial.ataques[0] = ataqueBasico;
    inicial.ataques[1] = ataqueMedio;
    inicial.ataques[2] = ataqueForte;
    inicial.xpMax = inicial.nivel*MIN_XP;

    return inicial;
}


int salvaJogo(Save jogoAtual){
    int salvou = 0;
    FILE *arqBin;

    arqBin = fopen("save.bin", "wb");
    if(arqBin == NULL){
        salvou = 0;
    }
    else{
        fwrite(&jogoAtual, sizeof(Save), 1, arqBin);
        if(ferror(arqBin)){
            salvou = 0;
        }
        else{
            salvou = 1;
        }
        fclose(arqBin);
    }
    return salvou;
}

int carregaJogo(Save *jogoSalvo){
    int carregou = 0;
    FILE *arqBin;

    arqBin = fopen("save.bin", "rb");
    if(arqBin == NULL){
        carregou = 0;
    }
    else{
        fread(jogoSalvo, sizeof(Save), 1, arqBin);
        if(ferror(arqBin)){
            carregou = 0;
        }
        else{
            carregou = 1;
        }
        fclose(arqBin);
    }
    return carregou;
}
