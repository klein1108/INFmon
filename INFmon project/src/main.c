#include <string.h>

#include "raylib.h"
#include "../lib/charactions.h"
#include "../lib/utils.h"

#define LARGURA 1200
#define ALTURA 600

#define TRUE 1
#define FALSE 0

#define GAP_ENTRE_BOTOES 110

#define NAO_TOCA_BOTAO -1
#define BOTAO_NOVO_JOGO 0
#define BOTAO_CARREGAR_JOGO 1
#define BOTAO_SAIR 2

static const char *labelBotoes[] = {
    "NOVO JOGO",
    "CARREGAR JOGO",
    "SAIR"
};

//void menuInicial(char texto[], int tamanhoFonte, float margin, int alturaModal, int larguraModal, int larguraTela, int alturaTela, int* isAbertaModal);

int main(void){
    int NUM_BOTOES = 3;
    char TITULO[10] = "INFmon";

    Color corBotoes[3] = {GREEN, BLUE, RED};


    int posMeioY = ALTURA/2, posMeioX = LARGURA/2;
    int isFecharJanela = FALSE;
    int isAbertaModal = FALSE;
    InitWindow(LARGURA, ALTURA, TITULO);  //Inicializa janela, com certo tamanho e tıtulo
//
    int currentProcess = 0;
    int tituloLength = strlen(TITULO);
    int mouseCimaDeBotaoN = -1;

    Rectangle botoes[NUM_BOTOES] = {};

    SetTargetFPS(60);   // Ajusta a execucao do jogo para 60 frames por segundo

    char modalTexto[50] = "Tem certeza que deseja criar um novo jogo?";
    int tamanhoFonte = 20;
    float margem = 10.0f;

    int alturaModal = 150;

    while (!WindowShouldClose() && !isFecharJanela){

        BeginDrawing(); //Inicia o ambiente de desenho na tela
        ClearBackground(RAYWHITE);  //Limpa a tela e define cor de fundo

        if(WindowShouldClose()){
            WindowShouldClose();
        }
        DrawText(TITULO, posMeioX-(tituloLength*25), 20, 100, BLACK); //posicao de x é o meio da tela (posMeioX - ([numero de caracteres do titulo]*[tamanho de cada letra]) )


        for (int i = 0; i < NUM_BOTOES; i++){

            botoes[i] = criaBotao(600.0f/2.0f, 150.0f, 600.0f, 100.0f, (float)GAP_ENTRE_BOTOES, i, 5.0f, WHITE, corBotoes[mouseCimaDeBotaoN], (i == mouseCimaDeBotaoN));
            DrawText(labelBotoes[i], (int)( botoes[i].x + botoes[i].width/2 - MeasureText(labelBotoes[i], 25)/2), (int) botoes[i].y + botoes[i].height/2 - 30/2  , 30, BLACK);

            /**
                Explicação: (int) buttons[i].y + buttons[i].height/2 - 30/2 ==> ponto inicial de onde comeca o desenho do retangulo + a altura do retangulo/2
                (indo pra mentade do retangulo) - font do texto/2 (para contar pros dois lados do meio do retangulo)
            **/


            if (CheckCollisionPointRec(GetMousePosition(), botoes[i]) && !isAbertaModal){
                mouseCimaDeBotaoN = i;

                if(i == BOTAO_NOVO_JOGO){
                    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                        isAbertaModal = TRUE;
                    }

                } else if(i == BOTAO_CARREGAR_JOGO){
                    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                        CloseWindow();
                    }
                } else if(i == BOTAO_SAIR){
                    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                        CloseWindow();
                    }

                } else {
                    mouseCimaDeBotaoN = NAO_TOCA_BOTAO;

                }
            }

        }

        if(isAbertaModal){
            abreModalDeConfirmacao(modalTexto, tamanhoFonte, margem, 150, 0, LARGURA, ALTURA, &isAbertaModal);
        }

        EndDrawing();   //Finaliza o ambiente de desenho na tela

    }
    CloseWindow();  //Fecha a janela e o contexto OpenGL
    return 0;
}

/**
FIXME: Verificar por que o ponteiro dentro dessas funcoes nao esta alterando o valor corretamente

void menuInicial(char texto[], int tamanhoFonte, float margin, int alturaModal, int larguraModal, int larguraTela, int alturaTela, int* isAbertaModal){
    if(isAbertaModal){
        abreModalDeConfirmacao(texto, tamanhoFonte, margin, alturaModal, larguraModal, larguraTela, alturaTela, &isAbertaModal);
    }
}

**/





