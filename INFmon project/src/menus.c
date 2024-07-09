#include "raylib.h"
#include "../lib/utils.h"

#define LARGURA 1200
#define ALTURA 600

#define TRUE 1
#define FALSE 0

#define GAP_ENTRE_BOTOES 110

//NAO MUDAR ORDEM
#define BOTAO_NOVO_JOGO 0
#define BOTAO_CARREGAR_JOGO 1
#define BOTAO_SAIR 2

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

int menuInicial(int processoAtual){
    int NUM_BOTOES = 3;

    Color corBotoes[3] = {GREEN, BLUE, RED};

    int posMeioY = ALTURA/2, posMeioX = LARGURA/2;
    int isFecharJanela = FALSE;
    int isAbertaModal = FALSE;

    int tituloLength = strlen(TITULO);
    int mouseCimaDeBotaoN = -1;

    Rectangle botoes[NUM_BOTOES] = {};

    char modalTexto[50] = "Tem certeza que deseja criar um novo jogo?";
    int tamanhoFonte = 20;
    float margem = 10.0f;

    int alturaModal = 150;

    while (!WindowShouldClose() && !isFecharJanela && processoAtual == PROCESSO_MENU_INICIAL){

        BeginDrawing(); //Inicia o ambiente de desenho na tela
        ClearBackground(RAYWHITE);  //Limpa a tela e define cor de fundo

        DrawText(TITULO, posMeioX-(tituloLength*25), 20, 100, BLACK); //posicao de x é o meio da tela (posMeioX - ([numero de caracteres do titulo]*[tamanho de cada letra]) )


        for (int i = 0; i < NUM_BOTOES; i++){

            if(CheckCollisionPointRec(GetMousePosition(), botoes[i]) && !isAbertaModal){
                mouseCimaDeBotaoN = i;

                switch(mouseCimaDeBotaoN){
                    case BOTAO_NOVO_JOGO:
                        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                            isAbertaModal = TRUE;
                        } break;

                    case BOTAO_CARREGAR_JOGO:
                        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                            processoAtual = PROCESSO_CARREGAR_JOGO;
                        } break;

                    case BOTAO_SAIR:
                        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                            CloseWindow();
                        } break;

                }

            }

            botoes[i] = criaBotao(600.0f/2.0f, 150.0f, 600.0f, 100.0f, (float)GAP_ENTRE_BOTOES, i, 5.0f, WHITE, corBotoes[mouseCimaDeBotaoN], (i == mouseCimaDeBotaoN));
            DrawText(labelBotoes[i], (int)( botoes[i].x + botoes[i].width/2 - MeasureText(labelBotoes[i], 25)/2), (int) botoes[i].y + botoes[i].height/2 - 30/2  , 30, BLACK);

            /**
                Explicação: (int) buttons[i].y + buttons[i].height/2 - 30/2 ==> ponto inicial de onde comeca o desenho do retangulo + a altura do retangulo/2
                (indo pra mentade do retangulo) - font do texto/2 (para contar pros dois lados do meio do retangulo)
            **/

        }

        if(isAbertaModal){
            processoAtual = abreModalDeConfirmacaoMenuInicial(modalTexto, tamanhoFonte, margem, 150, 0, LARGURA, ALTURA, &isAbertaModal);
        }

        EndDrawing();   //Finaliza o ambiente de desenho na tela

    }
    return processoAtual;
}
