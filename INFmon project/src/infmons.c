#include<stdio.h>
#include<string.h>
#include "../lib/infmons.h"

static Ataque ataqueBasico;
static Ataque ataqueMedio;
static Ataque ataqueForte;

//REMOVE
Infmon criaPokemonAliadoAgua(){
    Infmon aliado;

    strcpy(aliado.nome, "Printf bonzinho");

    aliado.tipo = TIPO_AGUA;
    aliado.nivel = 3;
    aliado.ataque = aliado.nivel * ATAQUE_DEFESA_DEFAULT;
    aliado.defesa = aliado.nivel * ATAQUE_DEFESA_DEFAULT;
    aliado.xp = 0;
    aliado.vida = (aliado.nivel-1)*20 + 100; //nivel-1*20 + 100;

    aliado.ataques[0] = ataqueBasico;
    aliado.ataques[1] = ataqueMedio;
    aliado.ataques[2] = ataqueForte;

    aliado.xp = 0;
    aliado.vida = (aliado.nivel-1)*20 + 100; //nivel-1*20 + 100;

    return aliado;
}


//REMOVE
Infmon criaPokemonInimigoFogo(){
    strcpy(ataqueBasico.nome, "Morder");
    ataqueBasico.dano = 2;

    strcpy(ataqueMedio.nome, "Chutar");
    ataqueMedio.dano = 3;

    strcpy(ataqueForte.nome, "Xingar");
    ataqueForte.dano = 5;


    Infmon inimigo;
    strcpy(inimigo.nome, "Scanf bandido");

    inimigo.tipo = TIPO_FOGO;
    inimigo.nivel = 1;
    inimigo.ataque = inimigo.nivel * ATAQUE_DEFESA_DEFAULT;
    inimigo.defesa = inimigo.nivel * ATAQUE_DEFESA_DEFAULT;
    inimigo.xp = 0;
    inimigo.vida = (inimigo.nivel-1)*20 + 100; //nivel-1*20 + 100;

    inimigo.ataques[0] = ataqueBasico;
    inimigo.ataques[1] = ataqueMedio;
    inimigo.ataques[2] = ataqueForte;

    return inimigo;
}

Infmon criaINFmon(char tipoINFmon){
    strcpy(ataqueBasico.nome, "Morder");
    ataqueBasico.dano = 2;

    strcpy(ataqueMedio.nome, "Chutar");
    ataqueMedio.dano = 3;

    strcpy(ataqueForte.nome, "Xingar");
    ataqueForte.dano = 5;


    Infmon inimigo;
    strcpy(inimigo.nome, "Scanf bandido");

    inimigo.tipo = tipoINFmon;
    inimigo.nivel = 1;
    inimigo.ataque = inimigo.nivel * ATAQUE_DEFESA_DEFAULT;
    inimigo.defesa = inimigo.nivel * ATAQUE_DEFESA_DEFAULT;
    inimigo.xp = 0;
    inimigo.vida = (inimigo.nivel-1)*20 + 100; //nivel-1*20 + 100;

    inimigo.ataques[0] = ataqueBasico;
    inimigo.ataques[1] = ataqueMedio;
    inimigo.ataques[2] = ataqueForte;

    return inimigo;
}





void adicionaINFmon(char escolha){
    FILE *arq;
    Infmon infmon[MAX_INFMONS];
    Infmon leuBIN;

    switch(escolha){
        case TIPO_AGUA:
            infmon[0] = criaINFmon(TIPO_AGUA);
            break;
        case TIPO_FOGO:
            infmon[0] = criaINFmon(TIPO_FOGO);
            break;

        case TIPO_TERRA:
            infmon[0] = criaINFmon(TIPO_TERRA);
            break;
    }

    arq = fopen("userINFmon.bin", "wb+");

    if(arq == NULL){
        printf("\nERRO AO ABRIR ARQUIVO\n");
    } else {
        if(!(fwrite(infmon, sizeof(Infmon), 1, arq))){
            printf("\nERRO AO CRIAR ARQUIVO\n");
        }
        rewind(arq);
        if(fread(&leuBIN, sizeof(Infmon),1 ,arq) != 1){
             printf("\nERRO AO LER ARQUIVO\n");
        } else {
            printf("NOME INFMON: %s\n", leuBIN.nome);
        }

    }

    fclose(arq);

}



