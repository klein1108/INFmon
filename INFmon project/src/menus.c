#include <string.h>

#include "raylib.h"
#include "../lib/utils.h"
#include "../lib/infmons.h"

#include "../lib/contants.h"

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

            //AJUSTE!!!
            botoes[i] = criaBotao(600.0f/2.0f, 150.0f, 600.0f, 100.0f, 0, (float)GAP_ENTRE_BOTOES, i, 5.0f, WHITE, corBotoes[mouseCimaDeBotaoN], (i == mouseCimaDeBotaoN));
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

int menuEscolheInfmon(int processoAtual, int *escolhido){

    int NUM_INFMONS = 3;

    Color corInfmons[3] = {GREEN, BLUE, RED};
    Rectangle infmons[3];

    static const char *nomeInfmons[] = {
        "Nome 1",
        "Nome 2",
        "Nome 3"
    };

    int mouseCimaDeBotaoN = -1;

    static const char texto[40] = "Escolha seu INFmon inicial";
    int textoLength = strlen(texto);

    //TESTE
    char escolhidoTeste = ' ';


    processoAtual = PROCESSO_ESCOLHER_INFMON;

    while(!WindowShouldClose() && processoAtual == PROCESSO_ESCOLHER_INFMON){

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText(texto, LARGURA/2-(textoLength*13), 60, 50, BLACK);

        for (int i = 0; i < NUM_INFMONS; i++){

                if(CheckCollisionPointRec(GetMousePosition(), infmons[i])){
                    mouseCimaDeBotaoN = i;

                    switch(mouseCimaDeBotaoN){
                        case 0:
                            if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){

                                *escolhido = 1;
                                escolhidoTeste = 'F';
                                //processoAtual = proxima etapa
                            } break;

                        case 1:
                            if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                                *escolhido = 2;
                                escolhidoTeste = 'A';
                                //processoAtual = proxima etapa
                            } break;

                        case 2:
                            if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                                *escolhido = 3;
                                escolhidoTeste = 'T';
                                //processoAtual = proxima etapa
                            } break;

                    }

                }

                if(escolhidoTeste != ' '){
                    adicionaINFmon(escolhidoTeste);
                    processoAtual = PROCESSO_INICIA_JOGO;
                }

                printf("ESCOLHIDO: %d", *escolhido);

                //AJUSTE!!!
                infmons[i] = criaBotao(LARGURA/2 -150, 150.0f, 100.0f, 100.0f, 0, (float)GAP_ENTRE_BOTOES, i, 5.0f, WHITE, corInfmons[mouseCimaDeBotaoN], (i == mouseCimaDeBotaoN));
                DrawText(nomeInfmons[i], LARGURA/2+50, (int) infmons[i].y + infmons[i].height/2 - 30/2  , 30, BLACK);

            }

        EndDrawing();

    }

    return processoAtual;
}

int menuBatalha(int *processoInternoAtual){
    int isFecharJanela = FALSE;

    int resultadoBatalha = BATALHA_DERROTA;

    Infmon inimigo = criaPokemonInimigoFogo();
    Infmon aliado = criaPokemonAliadoAgua();
    float bordaInferiorAltura = 250.0f;
    float modalLarguraLinha = 4.0;

    int NUM_BOTOES = 4;

    float width = 100.0f;
        float height = 50.0f;
        float posX = 0.0f;

        float posY = (ALTURA - bordaInferiorAltura);

        float posXButton = ((posX + LARGURA)/NUM_BOTOES);
        float posYButton = (posY + (bordaInferiorAltura/2) - 2*(modalLarguraLinha));
        float gapX = (float)GAP_ENTRE_BOTOES;

        int isAcao = FALSE;
        double testeTime = 0;
        int mouseCimaDeBotaoN = 0;

        Rectangle botoes[NUM_BOTOES];

        int danoTotal = 0;
        printf("Vida inimigo: %d\n", inimigo.vida);

        float alturaInfmon = 200.0f;
        float larguraInfmon = alturaInfmon;
        float posYInfmon = posY - alturaInfmon - (modalLarguraLinha);
        float posXInfmon = (modalLarguraLinha);
        float posYInimigo = 0;
        float posXInimigo = LARGURA - larguraInfmon - (modalLarguraLinha);

        while (!WindowShouldClose() && !isFecharJanela && *processoInternoAtual == PROCESSO_INTERNO_BATALHA){
            BeginDrawing();
            ClearBackground(RAYWHITE);

            Rectangle retanguloBordaInferior = criaRetangulo(posX, posY, LARGURA, bordaInferiorAltura, 0, 0, 1);
            DrawRectangleRec(retanguloBordaInferior, GRAY);
            DrawRectangleLinesEx(retanguloBordaInferior, modalLarguraLinha, BLACK);


            Rectangle nossoINFmon = criaRetangulo(posXInfmon, posYInfmon, larguraInfmon, alturaInfmon, 0, 0, 1);
            DrawRectangleRec(nossoINFmon, BLUE);
            DrawRectangleLinesEx(nossoINFmon, modalLarguraLinha, BLACK);


            Rectangle delesINFmon = criaRetangulo(posXInimigo, posYInimigo, larguraInfmon, alturaInfmon, 0, 0, 1);
            DrawRectangleRec(delesINFmon, RED);
            DrawRectangleLinesEx(delesINFmon, modalLarguraLinha, BLACK);

            for (int i = 0; i < NUM_BOTOES; i++){

                if(CheckCollisionPointRec(GetMousePosition(), botoes[i])){
                    mouseCimaDeBotaoN = i;


                    switch(mouseCimaDeBotaoN){
                        case 0:
                            if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                                printf("ATAQUE %s\n", aliado.ataques[i].nome);
                                testeTime = GetTime() + (double)3;
                                if(inimigo.vida > 0){
                                    isAcao = TRUE;
                                    //calculo Dano
                                    danoTotal = (aliado.ataque * aliado.ataques[i].dano);
                                    inimigo.vida -=danoTotal;
                                    printf("Dano total: %d\n", danoTotal);
                                    printf("Vida inimigo: %d\n", inimigo.vida);
                                }
                            } break;

                        case 1:
                            if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                                printf("ATAQUE %s\n", aliado.ataques[i].nome);

                                if(inimigo.vida > 0){

                                    //calculo Dano
                                    danoTotal = (aliado.ataque * aliado.ataques[i].dano);
                                    inimigo.vida -=danoTotal;
                                    printf("Dano total: %d\n", danoTotal);
                                    printf("Vida inimigo: %d\n", inimigo.vida);
                                }
                            } break;

                        case 2:
                            if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                                printf("ATAQUE %s\n", aliado.ataques[i].nome);

                                if(inimigo.vida > 0){
                                    //calculo Dano
                                    danoTotal = (aliado.ataque * aliado.ataques[i].dano);
                                    inimigo.vida -=danoTotal;
                                    printf("Dano total: %d\n", danoTotal);
                                    printf("Vida inimigo: %d\n", inimigo.vida);
                                }
                            } break;

                        case 3:
                            if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                                resultadoBatalha = BATALHA_FUGA;
                                *processoInternoAtual = PROCESSO_INTERNO_MAPA;

                            }
                            break;
                    }

                }

                if(isAcao && GetTime() < testeTime){
                    DrawText("Ocorreu uma acao realizada pelo jogador muito texto para testar e afins e tals", posX, posY, 24, BLACK);
                    printf("TEMPO = %lf\n", testeTime);


                } else {
                    isAcao = FALSE;
                    criaInterface(&botoes[i], aliado.ataques[i].nome, i);
                }
            }

        EndDrawing();
    }

    return resultadoBatalha;
}
