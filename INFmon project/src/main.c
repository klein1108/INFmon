//#include <string.h>
//#include <stdio.h>

#include "raylib.h"
#include "../lib/menus.h"
#include "../lib/mapa.h"
//#include "../lib/contants.h"
#include "../lib/infmons.h"


Personagem jogador;


static const char TITULO[10] = "INFmon";

int main(){
    Save jogoAtual;
    Save jogoSalvo;

    Personagem jogador;

    int fase = 1;
    int isPrimeiraVez = 1;

    int processoAtual = 0;


    InitWindow(LARGURA, ALTURA, TITULO);                    //Inicializa janela, com certo tamanho e tıtulo
    SetTargetFPS(60);                                       // Ajusta a execucao do jogo para 60 frames por segundo

    processoAtual = menuInicial(processoAtual);

    while(!WindowShouldClose() && processoAtual != PROCESSO_FECHA_JANELA){
        switch(processoAtual){
            case PROCESSO_MENU_INICIAL:
                isPrimeiraVez = 1;
                processoAtual = menuInicial(processoAtual);
                break;
            case PROCESSO_NOVO_JOGO:
                jogador.nInfmons = 0;
                processoAtual = menuEscolheInfmon(processoAtual, &jogador);
                break;
            case PROCESSO_CARREGAR_JOGO:
                isPrimeiraVez = 0;
                carregaJogo(&jogoSalvo);
                jogador = jogoSalvo.jogador;
                fase = jogoSalvo.fase;
                processoAtual = PROCESSO_INICIA_JOGO;
                break;
            case PROCESSO_SALVAR_JOGO:
                isPrimeiraVez = 0;
                jogoAtual.jogador = jogador;
                jogoAtual.fase = fase;
                salvaJogo(jogoAtual);
                processoAtual = PROCESSO_INICIA_JOGO;
                break;
        }

        if(processoAtual == PROCESSO_INICIA_JOGO){
            processoAtual = inicializaMapa(processoAtual, isPrimeiraVez, &jogador, &fase);
        }
    }
    CloseWindow();                                          //Fecha a janela e o contexto OpenGL
    return 0;
}
