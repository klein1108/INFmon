#include "raylib.h"
#include<stdio.h>

#define PROCESSO_INICIA_JOGO 4
#define MAX_LINHA 30
#define MAX_COLUNA 61

void inicializaMapa(int processoAtual){
    char mapa[MAX_LINHA][MAX_COLUNA] = {};

    FILE *arqMapa = NULL;
    arqMapa = fopen("testFile.txt", "r");

    char dadoColetado;

    if(arqMapa == NULL){
        printf("\n\tARQUIVO INEXISTENTE\n");
    } else {
        for(int i = 0; i < MAX_LINHA; i++){
            for(int j = 0; j < MAX_COLUNA; j++){
                dadoColetado = fgetc(arqMapa);
                if(dadoColetado != '\n'){
                    mapa[i][j] = dadoColetado;
                }
            }
        }
        fclose(arqMapa);

        while(!WindowShouldClose() && processoAtual == PROCESSO_INICIA_JOGO){
            BeginDrawing();
            ClearBackground(RAYWHITE);

            desenhaMapa(mapa);

            EndDrawing();
        }
    }
}

void desenhaMapa(char mapa[MAX_LINHA][MAX_COLUNA]){
    Color corPosMapa = WHITE;

    for(int i = 0; i < MAX_LINHA; i++){
        for(int j = 0; j < MAX_COLUNA -1 ; j++){
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
                    corPosMapa = BLUE;
                break;
                case 'E':
                    corPosMapa = RED;
                break;
            }
            DrawRectangle(j*20, i*20, 20, 20, corPosMapa);
        }
    }
}
