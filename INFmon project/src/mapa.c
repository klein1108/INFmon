#include "../lib/mapa.h"

void desenhaMapa(char mapa[MAX_LINHA][MAX_COLUNA-1], int *isPrimeiraVez, Personagem *jogador){
    Color corPosMapa = WHITE;

    for(int i = 0; i < MAX_LINHA; i++){
        for(int j = 0; j < MAX_COLUNA; j++){
            switch(mapa[i][j]){
                case 'W':
                    corPosMapa = BLACK;
                break;
                case 'G':
                    corPosMapa = GREEN;
                break;
                case ' ':
                    corPosMapa = WHITE;
                break;
                case 'J':
                    if(*isPrimeiraVez == 1){
                        jogador->posX = j;
                        jogador->posY = i;
                        *isPrimeiraVez = 0;
                    }
                    corPosMapa = WHITE;
                break;
                case 'E':
                    corPosMapa = RED;
                break;
            }
            DrawRectangle(j*20, i*20, 20, 20, corPosMapa);
        }
    }
}

void moveJogador(char mapa[MAX_LINHA][MAX_COLUNA-1], int *processoInternoAtual, Personagem *jogador){

    if(IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)){
        if(mapa[(jogador->posY)-1][jogador->posX] != 'W'){
            if(mapa[(jogador->posY)-1][jogador->posX] == 'G'){
                if(!sorteiaProbabilidade(5)){
                    *processoInternoAtual = PROCESSO_INTERNO_BATALHA_INFMON;
                }
            }
            (jogador->posY)--;
        }
    }
    else if(IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)){
        if(mapa[(jogador->posY)+1][jogador->posX] != 'W'){
            if(mapa[(jogador->posY)+1][jogador->posX] == 'G'){
                if(!sorteiaProbabilidade(5)){
                    *processoInternoAtual = PROCESSO_INTERNO_BATALHA_INFMON;
                }
            }
            (jogador->posY)++;
        }
    }
    else if(IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)){
        if(mapa[jogador->posY][(jogador->posX)-1] != 'W'){
            if(mapa[jogador->posY][(jogador->posX)-1] == 'G'){
                if(!sorteiaProbabilidade(5)){
                    *processoInternoAtual = PROCESSO_INTERNO_BATALHA_INFMON;
                }
            }
            (jogador->posX)--;
        }
    }
    else if(IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)){
        if(mapa[jogador->posY][(jogador->posX)+1] != 'W'){
            if(mapa[jogador->posY][(jogador->posX)+1] == 'G'){
                if(!sorteiaProbabilidade(5)){
                    *processoInternoAtual = PROCESSO_INTERNO_BATALHA_INFMON;
                }
            }
            (jogador->posX)++;
        }
    }

    DrawRectangle(jogador->posX*TAM_PIXEL, jogador->posY*TAM_PIXEL, TAM_PIXEL, TAM_PIXEL, BLUE);

    if(mapa[jogador->posY][jogador->posX] == 'E'){
        //BATALHA COM INIMIGO
        *processoInternoAtual = PROCESSO_INTERNO_BATALHA_BOSS;
    }

}

int inicializaMapa(int processoAtual, int *isPrimeiraVez, Personagem *jogador, int *fase){
    int processoInternoAtual = PROCESSO_INTERNO_MAPA;

    char mapa[MAX_LINHA][MAX_COLUNA];
    char dadoColetado;
    int i, j;
    //PARA FUNCIONAR NO XCODE
    static const char *mapas[] = {
        "./mapas/mapa1.txt",
        "./mapas/mapa2.txt",
        "./mapas/mapa3.txt",
        "./mapas/mapa4.txt",
        "./mapas/mapa5.txt"
    };
    //PARA FUNCIONAR NO CODEBLOKCS
//    static const char *mapas[] = {
//        "./mapas/mapa4.txt",
//        "./mapas/mapa2.txt",
//        "./mapas/mapa3.txt",
//        "./mapas/mapa4.txt",
//        "./mapas/mapa5.txt"
//    };


    FILE *arqMapa = NULL;
    arqMapa = fopen(mapas[*fase-1], "r");

    if(arqMapa == NULL){
        printf("\n\tARQUIVO INEXISTENTE\n");
    } else {
        i=0;
        j=0;
        while(!feof(arqMapa)){
            dadoColetado = fgetc(arqMapa);
            if (dadoColetado != '\n') {
                mapa[i][j] = dadoColetado;
                j++;
                if (j==MAX_COLUNA) {
                    i++;
                    j=0;
                }
            }
        }

        fclose(arqMapa);

        int resultadoBatalha = NULL;
        int isBoss = FALSE;

        while(!WindowShouldClose() && processoAtual == PROCESSO_INICIA_JOGO){
            BeginDrawing();
            ClearBackground(RAYWHITE);

            if(IsKeyPressed(KEY_TAB)){
                processoAtual = menuPause(processoAtual);
            }

            switch(processoInternoAtual){
                case PROCESSO_INTERNO_MAPA:

                    if(resultadoBatalha == BATALHA_FUGA){
                        jogador->posX = jogador->posX + 2;
                        resultadoBatalha = NULL;
                    }
                    desenhaMapa(mapa, isPrimeiraVez, jogador);
                    moveJogador(mapa, &processoInternoAtual, jogador);
                    break;

                case PROCESSO_INTERNO_BATALHA_BOSS:
                    resultadoBatalha = menuBatalha(&processoInternoAtual, TRUE, fase, jogador);
                    //Move char para lado para que nao volte em cima do inimigo e fique preso no menu de batalha

                    if(resultadoBatalha == BATALHA_DERROTA){
                        processoAtual = menuFimDeJogo(processoAtual, FALSE);
                    }
                    else if(resultadoBatalha == BATALHA_VITORIA){
                        if(*fase < NUM_FASES){
                            processoAtual = PROCESSO_PASSOU_FASE;
                        }
                        else{
                            processoAtual = menuFimDeJogo(processoAtual, TRUE);
                        }
                    }
                    break;

                case PROCESSO_INTERNO_BATALHA_INFMON:
                    resultadoBatalha = menuBatalha(&processoInternoAtual, FALSE, fase, jogador);
                    jogador->posX = jogador->posX - 2;
                    //depois que sai da batalha carrega o mapa
                    processoInternoAtual = PROCESSO_INTERNO_MAPA;
                    break;
            }

            EndDrawing();
        }
    }
    return processoAtual;
}
