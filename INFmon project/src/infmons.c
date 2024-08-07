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
    ataqueBasico.tipo = TIPO_NORMAL;

    strcpy(ataqueMedio.nome, "Chutar");
    ataqueMedio.dano = 3;
    ataqueBasico.tipo = TIPO_NORMAL;

    strcpy(ataqueForte.nome, "Xingar de Fogo");
    ataqueForte.dano = 5;
    ataqueBasico.tipo = TIPO_FOGO;



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
    ataqueBasico.dano = TIPO_NORMAL;

    strcpy(ataqueMedio.nome, "Chutar");
    ataqueMedio.dano = 3;
    ataqueMedio.tipo = TIPO_NORMAL;

    strcpy(ataqueForte.nome, "Xingar");
    ataqueForte.dano = 5;
    ataqueForte.tipo = tipoINFmon;


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


void leArquivosDeAtaques(){
    FILE *arq;
    arq = fopen("ataques.bin", "rb");
    Ataque ataques[12] = {};

    if(arq == NULL){
        printf("\nERRO AO ABRIR ARQUIVO\n");
    } else {
        for(int i = 0; i < 12; i++){
            if(fread(&ataques[i], sizeof(Ataque),1 ,arq) != 1){
                printf("\nERRO AO LER ARQUIVO\n");
            } else {
                printf("NOME ATAQUE: %s\n", ataques[i].nome);
            }

        }

        fclose(arq);
    }

}


//void criaArquivoDeAtaques(){
//    FILE *arq;
//
//    //ATAQUES TIPO NORMAL
//    Ataque ataqueNormalUm;
//    ataqueNormalUm.dano = 2;
//    strcpy(ataqueNormalUm.nome, "Morder");
//
//    Ataque ataqueNormalDois;
//    ataqueNormalDois.dano = 2;
//    strcpy(ataqueNormalDois.nome, "Arranhar");
//
//    Ataque ataqueNormalTres;
//    ataqueNormalTres.dano = 2;
//    strcpy(ataqueNormalTres.nome, "Cabeçada");
//
//    //ATAQUES TIPO AGUA
//    Ataque ataqueAguaUm;
//    ataqueAguaUm.dano = 4;
//    strcpy(ataqueAguaUm.nome, "Molhar");
//
//    Ataque ataqueAguaDois;
//    ataqueAguaDois.dano = 4;
//    strcpy(ataqueAguaDois.nome, "Chover");
//
//    Ataque ataqueAguaTres;
//    ataqueAguaTres.dano = 4;
//    strcpy(ataqueAguaTres.nome, "Gotejar");
//
//    //ATAQUES TIPO FOGO
//    Ataque ataqueFogoUm;
//    ataqueFogoUm.dano = 4;
//    strcpy(ataqueFogoUm.nome, "Queimar");
//
//    Ataque ataqueFogoDois;
//    ataqueFogoDois.dano = 4;
//    strcpy(ataqueFogoDois.nome, "Assar");
//
//    Ataque ataqueFogoTres;
//    ataqueFogoTres.dano = 4;
//    strcpy(ataqueFogoTres.nome, "Fumar");
//
//    //ATAQUES TIPO TERRA
//    Ataque ataqueTerraUm;
//    ataqueTerraUm.dano = 4;
//    strcpy(ataqueTerraUm.nome, "Plantar");
//
//    Ataque ataqueTerraDois;
//    ataqueTerraDois.dano = 4;
//    strcpy(ataqueTerraDois.nome, "Colher");
//
//    Ataque ataqueTerraTres;
//    ataqueTerraTres.dano = 4;
//    strcpy(ataqueTerraTres.nome, "Florir");
//
//    Ataque ataques[12] = {
//        ataqueNormalUm, ataqueNormalDois, ataqueNormalTres,
//        ataqueAguaUm, ataqueAguaDois, ataqueAguaTres,
//        ataqueFogoUm, ataqueFogoDois, ataqueFogoTres,
//        ataqueTerraUm, ataqueTerraDois, ataqueTerraTres
//    };
//
//    arq = fopen("ataques.bin", "wb");
//    if(arq == NULL){
//        printf("\nERRO AO ABRIR ARQUIVO\n");
//    } else {
//        for(int i = 0; i < 12; i++){
//            if(!(fwrite(&ataques[i], sizeof(Ataque), 1, arq))){
//                printf("\nERRO AO CRIAR ARQUIVO\n");
//            } else {
//                printf("\nDADO %d INSERIDO COM SUCESSO!\n", i+1);
//            }
//        }
//        fclose(arq);
//    }
//}


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



