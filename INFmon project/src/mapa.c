#include<stdio.h>
#include "raylib.h"
#include "../lib/infmons.h"
#include "../lib/menus.h"

#include "../lib/contants.h"

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

void moveJogador(Personagem *jogador, char mapa[MAX_LINHA][MAX_COLUNA-1], int *processoInternoAtual){

    if(IsKeyPressed(KEY_UP)){
        if(mapa[(jogador->posY)-1][jogador->posX] != 'W'){
            (jogador->posY)--;
        }
    }
    else if(IsKeyPressed(KEY_DOWN)){
        if(mapa[(jogador->posY)+1][jogador->posX] != 'W'){
            (jogador->posY)++;
        }
    }
    else if(IsKeyPressed(KEY_LEFT)){
        if(mapa[jogador->posY][(jogador->posX)-1] != 'W'){
            (jogador->posX)--;
        }
    }
    else if(IsKeyPressed(KEY_RIGHT)){
        if(mapa[jogador->posY][(jogador->posX)+1] != 'W'){
            (jogador->posX)++;
        }
    }

    DrawRectangle(jogador->posX*20, jogador->posY*20, 20, 20, BLUE);

    if(mapa[jogador->posY][jogador->posX] == 'G'){
        //CHANCE DE ENCONTRAR INFMON SELVAGEM
    }
    else if(mapa[jogador->posY][jogador->posX] == 'E'){
        //BATALHA COM INIMIGO
        *processoInternoAtual = PROCESSO_INTERNO_BATALHA;
    }

}

void inicializaMapa(int processoAtual){
    Personagem jogador;
    Personagem inimigo;

    int processoInternoAtual = PROCESSO_INTERNO_MAPA;

    char mapa[MAX_LINHA][MAX_COLUNA];
    char dadoColetado;
    int isPrimeiraVez = 1;
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

        while(!WindowShouldClose() && processoAtual == PROCESSO_INICIA_JOGO){
            BeginDrawing();
            ClearBackground(RAYWHITE);


            switch(processoInternoAtual){
                case PROCESSO_INTERNO_MAPA:

                    if(resultadoBatalha == BATALHA_FUGA){
                        jogador.posX = jogador.posX + 2;
                        resultadoBatalha = NULL;
                    }

                    desenhaMapa(mapa, &isPrimeiraVez, &jogador);
                    moveJogador(&jogador, mapa, &processoInternoAtual);
                    break;

                case PROCESSO_INTERNO_BATALHA:
                    resultadoBatalha = menuBatalha(&processoInternoAtual);
                    break;

            }


            EndDrawing();
        }
    }
}
