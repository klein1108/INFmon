#include "../lib/mapa.h"

void desenhaMapa(char mapa[MAX_LINHA][MAX_COLUNA-1], int *isPrimeiraVez, Personagem *jogador, int *fase){
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

    DrawRectangle(jogador->posX*20, jogador->posY*20, 20, 20, BLUE);

    if(mapa[jogador->posY][jogador->posX] == 'E'){
        //BATALHA COM INIMIGO
        *processoInternoAtual = PROCESSO_INTERNO_BATALHA_BOSS;
    }

}

int inicializaMapa(int processoAtual, int isPrimeiraVez, Personagem *jogador, int *fase){
    int processoInternoAtual = PROCESSO_INTERNO_MAPA;

    char mapa[MAX_LINHA][MAX_COLUNA];
    char dadoColetado;
    int i, j;

    FILE *arqMapa = NULL;
    arqMapa = fopen("./mapas/mapa4.txt", "r");

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

//        for(int i = 0; i < MAX_LINHA; i++){
//            for(int j = 0; j < MAX_COLUNA; j++){
//                printf("%c", mapa[i][j]);
//            }
//        }

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
                    desenhaMapa(mapa, &isPrimeiraVez, jogador, fase);
                    moveJogador(mapa, &processoInternoAtual, jogador);
                    break;

                case PROCESSO_INTERNO_BATALHA_BOSS:
                    resultadoBatalha = menuBatalha(&processoInternoAtual, TRUE, fase, jogador);
                    //Move char para lado para que nao volte em cima do inimigo e fique preso no menu de batalha
                    jogador->posX = jogador->posX + 2;
                    //depois que sai da batalha carrega o mapa
                    processoInternoAtual = PROCESSO_INTERNO_MAPA;
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
