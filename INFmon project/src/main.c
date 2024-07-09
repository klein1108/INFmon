#include <string.h>

#include "raylib.h"

#define LARGURA 1200
#define ALTURA 600

#define TRUE 1
#define FALSE 0

//NAO MUDAR ORDEM
#define PROCESSO_MENU_INICIAL 0
#define PROCESSO_NOVO_JOGO 1
#define PROCESSO_CARREGAR_JOGO 2

static const char *labelBotoes[] = {
    "NOVO JOGO",
    "CARREGAR JOGO",
    "SAIR"
};

static const char TITULO[10] = "INFmon";

int main(void){
    int processoAtual = 0;

    InitWindow(LARGURA, ALTURA, TITULO);                    //Inicializa janela, com certo tamanho e tıtulo
    SetTargetFPS(60);                                       // Ajusta a execucao do jogo para 60 frames por segundo

    processoAtual = menuInicial(processoAtual);\

    switch(processoAtual){
        case PROCESSO_NOVO_JOGO:
            printf("\n\n\t\tFAZER PARTE DE NOVO JOGO\n\n");
            break;

        case PROCESSO_CARREGAR_JOGO:
            printf("\n\n\t\tFAZER PARTE DE CONTINUAR JOGO\n\n");
            break;

    }

    CloseWindow();                                          //Fecha a janela e o contexto OpenGL
    return 0;
}




