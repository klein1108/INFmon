#include "raylib.h"
#include <string.h>
#define LARGURA 600
#define ALTURA 600

#define ALTURA_QUADRADO 20
#define LARGURA_QUADRADO 20

#define TRUE 1
#define FALSE 0

int main(void){
    int posX = ALTURA/2, posY = LARGURA/2;
    int isFecharJanela = FALSE;
    InitWindow(LARGURA, ALTURA, "Teclas");  //Inicializa janela, com certo tamanho e tıtulo
    SetTargetFPS(60);   // Ajusta a execucao do jogo para 60 frames por segundo

    while (!WindowShouldClose() && !isFecharJanela){

    if (IsKeyPressed(KEY_RIGHT)){
        posX = posX + LARGURA_QUADRADO;
    }
    if (IsKeyPressed(KEY_LEFT)){
        posX = posX - LARGURA_QUADRADO;
    }
    if (IsKeyPressed(KEY_UP)){
        posY = posY - ALTURA_QUADRADO;
    }
    if (IsKeyPressed(KEY_DOWN)){
        posY = posY + ALTURA_QUADRADO;
    }

    if((posX > (LARGURA - LARGURA_QUADRADO)) ||
       (posX < 0) ||
       (posY > (ALTURA - ALTURA_QUADRADO)) ||
       (posY < 0)){

        isFecharJanela = TRUE;
    }

    BeginDrawing(); //Inicia o ambiente de desenho na tela
    ClearBackground(RAYWHITE);  //Limpa a tela e define cor de fundo
    DrawRectangle(posX, posY, LARGURA_QUADRADO, ALTURA_QUADRADO, GREEN);
    EndDrawing();   //Finaliza o ambiente de desenho na tela
    //----------------------------------------------------------------------------------
    }
    CloseWindow();  //Fecha a janela e o contexto OpenGL
return 0;
}



