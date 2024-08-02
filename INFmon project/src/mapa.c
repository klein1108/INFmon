#include "raylib.h"
#include<stdio.h>

#define PROCESSO_INICIA_JOGO 4

char mapa[30][60] = {};

void inicializaMapa(int processoAtual){
    FILE *arqMapa;
    arqMapa = fopen("./mapas/mapa3.txt", "r");

    while(!WindowShouldClose() && processoAtual == PROCESSO_INICIA_JOGO){
        int linha,coluna;
        char dadoColetado;
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if(arqMapa == NULL){
            printf("\n\tARQUIVO INEXISTENTE\n");
        } else {
            linha = 0;
            coluna = 0;

            while(!feof(arqMapa)){
                dadoColetado = fgetc(arqMapa);
//                printf("DADO COLETADO = %c\n",dadoColetado);

                if(dadoColetado == '\n'){
                    printf("\n");
//                    linha = 0;
//                    coluna++;
                } else {
                    printf("%c", dadoColetado);
//                    mapa[linha][coluna] = dadoColetado;
                }
            }
        }

        DrawText("TESTEEEEEEEE", 10, 10, 50, BLACK);
        EndDrawing();
    }

}
