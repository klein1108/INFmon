#include "../lib/infmons.h"
extern Personagem jogador;
static Ataque ataqueBasico;
static Ataque ataqueMedio;

//REMOVE
Infmon criaPokemonAliadoAgua(){
    Ataque ataqueForte;
    Infmon aliado;

    strcpy(aliado.nome, "Printf bonzinho");

    strcpy(ataqueForte.nome, "Molhar");
    ataqueForte.dano = 4;
    ataqueForte .tipo = TIPO_AGUA;

    aliado.tipo = TIPO_AGUA;
    aliado.nivel = 3;
    aliado.ataque = aliado.nivel * ATAQUE_DEFESA_DEFAULT;
    aliado.defesa = aliado.nivel * ATAQUE_DEFESA_DEFAULT;
    aliado.xp = 0;
    aliado.VIDA_MAX = (aliado.nivel-1)*20 + 100; //nivel-1*20 + 100;
    aliado.vida = aliado.VIDA_MAX;

    aliado.ataques[0] = ataqueBasico;
    aliado.ataques[1] = ataqueMedio;
    aliado.ataques[2] = ataqueForte;

    aliado.xp = 0;
    aliado.vida = (aliado.nivel-1)*20 + 100; //nivel-1*20 + 100;

    return aliado;
}


//REMOVE
Infmon criaPokemonInimigoFogo(){
    Ataque ataqueForte;
    strcpy(ataqueBasico.nome, "Morder");
    ataqueBasico.dano = 2;
    ataqueBasico.tipo = TIPO_NORMAL;

    strcpy(ataqueMedio.nome, "Chutar");
    ataqueMedio.dano = 3;
    ataqueBasico.tipo = TIPO_NORMAL;

//    strcpy(ataqueForte.nome, "Xingar");
//    ataqueForte.dano = 5;
//    ataqueBasico.tipo = TIPO_FOGO;

    strcpy(ataqueForte.nome, "Foguetar");
    ataqueForte.dano = 4;
    ataqueForte .tipo = TIPO_FOGO;
//    strcpy(ataqueAguaTres.nome, "Gotejar");



    Infmon inimigo;
    strcpy(inimigo.nome, "Scanf bandido");

    inimigo.tipo = TIPO_FOGO;
    inimigo.nivel = 1;
    inimigo.ataque = inimigo.nivel * ATAQUE_DEFESA_DEFAULT;
    inimigo.defesa = inimigo.nivel * ATAQUE_DEFESA_DEFAULT;
    inimigo.xp = 0;
    inimigo.VIDA_MAX = (inimigo.nivel-1)*20 + 100; //nivel-1*20 + 100;
    inimigo.vida = inimigo.VIDA_MAX;

    inimigo.ataques[0] = ataqueBasico;
    inimigo.ataques[1] = ataqueMedio;
    inimigo.ataques[2] = ataqueForte;

    return inimigo;
}

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

    return infmon;
}

//REMOVER E COLOCAR OS DADOS DOS INFMONS DOS ARQUIVOS BINARIOS, PROGRAMA JA ESTA SE ATRAPALHANDO POR CONTA DAS VARIAVEIS GLOBAIS

Infmon criaINFmon(char tipoINFmon){
    Ataque ataqueForte;
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
    inimigo.VIDA_MAX = (inimigo.nivel-1)*20 + 100; //nivel-1*20 + 100;
    inimigo.vida = inimigo.VIDA_MAX;

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


void criaArquivoDeAtaques(){
    FILE *arq;

    //ATAQUES TIPO NORMAL
    Ataque ataqueNormalUm;
    ataqueNormalUm.dano = 2;
    strcpy(ataqueNormalUm.nome, "Morder");

    Ataque ataqueNormalDois;
    ataqueNormalDois.dano = 2;
    strcpy(ataqueNormalDois.nome, "Arranhar");

    Ataque ataqueNormalTres;
    ataqueNormalTres.dano = 2;
    strcpy(ataqueNormalTres.nome, "Cabeçada");

    //ATAQUES TIPO AGUA
    Ataque ataqueAguaUm;
    ataqueAguaUm.dano = 4;
    strcpy(ataqueAguaUm.nome, "Molhar");

    Ataque ataqueAguaDois;
    ataqueAguaDois.dano = 4;
    strcpy(ataqueAguaDois.nome, "Chover");

    Ataque ataqueAguaTres;
    ataqueAguaTres.dano = 4;
    strcpy(ataqueAguaTres.nome, "Gotejar");

    //ATAQUES TIPO FOGO
    Ataque ataqueFogoUm;
    ataqueFogoUm.dano = 4;
    strcpy(ataqueFogoUm.nome, "Queimar");

    Ataque ataqueFogoDois;
    ataqueFogoDois.dano = 4;
    strcpy(ataqueFogoDois.nome, "Assar");

    Ataque ataqueFogoTres;
    ataqueFogoTres.dano = 4;
    strcpy(ataqueFogoTres.nome, "Fumar");

    //ATAQUES TIPO TERRA
    Ataque ataqueTerraUm;
    ataqueTerraUm.dano = 4;
    strcpy(ataqueTerraUm.nome, "Plantar");

    Ataque ataqueTerraDois;
    ataqueTerraDois.dano = 4;
    strcpy(ataqueTerraDois.nome, "Colher");

    Ataque ataqueTerraTres;
    ataqueTerraTres.dano = 4;
    strcpy(ataqueTerraTres.nome, "Florir");

    Ataque ataques[12] = {
        ataqueNormalUm, ataqueNormalDois, ataqueNormalTres,
        ataqueAguaUm, ataqueAguaDois, ataqueAguaTres,
        ataqueFogoUm, ataqueFogoDois, ataqueFogoTres,
        ataqueTerraUm, ataqueTerraDois, ataqueTerraTres
    };

    arq = fopen("ataques.bin", "wb");
    if(arq == NULL){
        printf("\nERRO AO ABRIR ARQUIVO\n");
    } else {
        for(int i = 0; i < 12; i++){
            if(!(fwrite(&ataques[i], sizeof(Ataque), 1, arq))){
                printf("\nERRO AO CRIAR ARQUIVO\n");
            } else {
                printf("\nDADO %d INSERIDO COM SUCESSO!\n", i+1);
            }
        }
        fclose(arq);
    }
}


void adicionaINFmon(char tipo, int indice, int isPrimeiro){
    FILE *arq;
    Infmon infmon[MAX_INFMONS];
    Infmon leuBIN;

    switch(tipo){
        case TIPO_AGUA:
            infmon[indice] = criaINFmon(TIPO_AGUA);
            jogador.infmons[indice] = criaINFmon(TIPO_AGUA);
            if(isPrimeiro){
                infmon[indice].nivel = 1;
                jogador.infmons[indice].nivel = 1;
            }
            break;
        case TIPO_FOGO:
            infmon[indice] = criaINFmon(TIPO_FOGO);
            jogador.infmons[indice] = criaINFmon(TIPO_FOGO);
            if(isPrimeiro){
                infmon[indice].nivel = 1;
                jogador.infmons[indice].nivel = 1;
            }
            break;

        case TIPO_TERRA:
            infmon[indice] = criaINFmon(TIPO_TERRA);
            jogador.infmons[indice] = criaINFmon(TIPO_TERRA);
            if(isPrimeiro){
                infmon[indice].nivel = 1;
                jogador.infmons[indice].nivel = 1;
            }
            break;
    }

//    arq = fopen("userINFmon.bin", "wb+");
//
//    if(arq == NULL){
//        printf("\nERRO AO ABRIR ARQUIVO\n");
//    } else {
//        if(!(fwrite(infmon, sizeof(Infmon), 1, arq))){
//            printf("\nERRO AO CRIAR ARQUIVO\n");
//        }
//        rewind(arq);
//        if(fread(&leuBIN, sizeof(Infmon),1 ,arq) != 1){
//             printf("\nERRO AO LER ARQUIVO\n");
//        } else {
//            printf("NOME INFMON: %s\n", leuBIN.nome);
//        }
//
//    }
//
//    fclose(arq);

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

