#include <string.h>
#include <stdio.h>

#include "raylib.h"
#include "../lib/menus.h"
#include "../lib/mapa.h"
#include "../lib/contants.h"

static const char *labelBotoes[] = {
    "NOVO JOGO",
    "CARREGAR JOGO",
    "SAIR"
};


static const char TITULO[10] = "INFmon";

int main(void){
    int processoAtual = 0;
    int infmonInicial = 0; //Isso deve ser usado depois

    InitWindow(LARGURA, ALTURA, TITULO);                    //Inicializa janela, com certo tamanho e tıtulo
    SetTargetFPS(60);                                       // Ajusta a execucao do jogo para 60 frames por segundo

    //verifica integridade de arquivos iniciais

    processoAtual = menuInicial(processoAtual);

    switch(processoAtual){
        case PROCESSO_NOVO_JOGO:
            processoAtual = menuEscolheInfmon(processoAtual, &infmonInicial);
            printf("\n\n\t\tFAZER PARTE DE NOVO JOGO\n\n");
            break;

        case PROCESSO_CARREGAR_JOGO:
//            menuBatalha(processoAtual);
            printf("\n\n\t\tFAZER PARTE DE CONTINUAR JOGO\n\n");
            break;
    }

    if(processoAtual == PROCESSO_INICIA_JOGO){
        inicializaMapa(processoAtual);
    }

    CloseWindow();                                          //Fecha a janela e o contexto OpenGL
    return 0;
}
