#include "../lib/menus.h"

static const char *labelBotoes[] = {
    "NOVO JOGO",
    "CARREGAR JOGO",
    "SAIR"
};

static const char TITULO[10] = "INFmon";

int menuInicial(int processoAtual){
    int NUM_BOTOES = 3;

    Color corBotoes[3] = {GREEN, BLUE, RED};

//    int posMeioY = ALTURA/2;
    int posMeioX = LARGURA/2;
    int isFecharJanela = FALSE;
    int isAbertaModal = FALSE;

    int tituloLength = strlen(TITULO);
    int mouseCimaDeBotaoN = -1;

    Rectangle botoes[NUM_BOTOES] = {};

    char modalTexto[50] = "Tem certeza que deseja criar um novo jogo?";
    int tamanhoFonte = 20;
    float margem = 10.0f;

//    int alturaModal = 150;

    while (!WindowShouldClose() && !isFecharJanela && processoAtual == PROCESSO_MENU_INICIAL){

        BeginDrawing(); //Inicia o ambiente de desenho na tela
        ClearBackground(RAYWHITE);  //Limpa a tela e define cor de fundo

        DrawText(TITULO, posMeioX-(tituloLength*25), 20, 100, BLACK); //posicao de x é o meio da tela (posMeioX - ([numero de caracteres do titulo]*[tamanho de cada letra]) )


        for (int i = 0; i < NUM_BOTOES; i++){


            if(IsKeyPressed(KEY_N))
                isAbertaModal = TRUE;
            if(IsKeyPressed(KEY_C))
                processoAtual = PROCESSO_CARREGAR_JOGO;
            if(IsKeyPressed(KEY_Q)){
                EndDrawing();
                CloseWindow();
            }

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
//                    criaArquivoDeAtaques();
                    leArquivosDeAtaques();
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

    int inimigoAtual = 2;

    Infmon inimigo1 = criaPokemonInimigoFogo();
    Infmon inimigo2 = criaPokemonAliadoAgua();
    Infmon inimigo3 = criaPokemonInimigoFogo();
    Infmon INFmonsInimigos[3] = {
        inimigo1, inimigo2, inimigo3
    };

//    Infmon inimigo = criaPokemonInimigoFogo();
    Infmon aliado = criaPokemonAliadoAgua();

//    float vidaMaxInimigo = (float)inimigo.vida;
//    float vidaMaxInimigo = (float)INFmonsInimigos[inimigoAtual].vida;
//    float vidaMaxAliado = (float)aliado.vida;

    float bordaInferiorAltura = 250.0f;
    float modalLarguraLinha = 4.0;

    int NUM_BOTOES = 4;

//    float width = 100.0f;
//        float height = 50.0f;
    float posX = 0.0f;

    float posY = (ALTURA - bordaInferiorAltura);

//        float posXButton = ((posX + LARGURA)/NUM_BOTOES);
//        float posYButton = (posY + (bordaInferiorAltura/2) - 2*(modalLarguraLinha));
//        float gapX = (float)GAP_ENTRE_BOTOES;

//        int isAcao = FALSE;
//        double testeTime = 0;
//        int mouseCimaDeBotaoN = 0;

    Rectangle botoes[NUM_BOTOES];

//        int danoTotal = 0;
    int processoAtualBatalha = PROCESSO_BATALHA_INICIAL;

//    printf("ENTROU EM MENU BATALHA()\n Vida inimigo: %d\n", inimigo.vida);

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

        criaInterfaceDeVidaINFmon(TRUE, posXInfmon, larguraInfmon, posYInfmon, aliado);


        Rectangle delesINFmon = criaRetangulo(posXInimigo, posYInimigo, larguraInfmon, alturaInfmon, 0, 0, 1);

        Color tipo = retornaCorDoTipo(INFmonsInimigos[inimigoAtual].tipo);
        DrawRectangleRec(delesINFmon, tipo);
        DrawRectangleLinesEx(delesINFmon, modalLarguraLinha, BLACK);

        criaInterfaceDeVidaINFmon(FALSE, posXInimigo, larguraInfmon, posYInimigo, INFmonsInimigos[inimigoAtual]);


        switch(processoAtualBatalha){
            case PROCESSO_BATALHA_INICIAL:
                    criaInterfaceMenuBatalhaInicial(botoes, &processoAtualBatalha);
                break;
            case PROCESSO_BATALHA_ATAQUES:
                    criaInterfaceMenuBatalhaAtaques(botoes, aliado, &INFmonsInimigos[inimigoAtual], posX, posY, &processoAtualBatalha, &inimigoAtual);
                break;

            case PROCESSO_BATALHA_TENTAR_FUGA:
                    resultadoBatalha = BATALHA_FUGA;
                    *processoInternoAtual = PROCESSO_INTERNO_MAPA;
                    printf("AQUI\n");
                break;
        }

        EndDrawing();
    }

    return resultadoBatalha;
}

//TROCAR LOCAL DE CRIACAO DA FUNCAO
Color retornaCorDoTipo(char tipo){
    Color response;
    switch(tipo){
        case TIPO_AGUA:
            response = BLUE;
            break;
        case TIPO_TERRA:
            response = GREEN;
            break;
        case TIPO_FOGO:
            response = RED;
            break;
        default:
            response = GRAY;
    }
    return response;
}
//MOVER PARA UTILS QUANDO PRONTO:
void criaInterfaceDeVidaINFmon(int isAliado, float posXInfmon, float larguraInfmon, float posYInfmon, Infmon infmon){
    int gapBotaoInfmon = 20;
    int margin = 5;
    float modalLarguraLinha = 4.0f;
    int larguraInterface = 300;
    int alturaInterface = 100;
    float posY = posYInfmon;
    float posX = (float)(posXInfmon + larguraInfmon + gapBotaoInfmon); //se aliado
    if(!isAliado){
        //se inimigo
        posX = (float)(posXInfmon - gapBotaoInfmon - larguraInterface);
    }

    float posXNomeInfmon = posX + margin;
    float posYNomeInfmon = posY + margin;

    Rectangle vidaINFmonCointainer = criaRetangulo(posX, posY, larguraInterface, alturaInterface, 0, 0, 1);
    DrawRectangleRec(vidaINFmonCointainer, WHITE);
    DrawRectangleLinesEx(vidaINFmonCointainer, modalLarguraLinha, BLACK);

    DrawText(infmon.nome, posXNomeInfmon, posYNomeInfmon, 20, BLACK);\

    criaBarraDeVidaINFmon(posXNomeInfmon, posYNomeInfmon + 20, infmon);
}

void criaBarraDeVidaINFmon(float posX, float posY, Infmon infmon){
    float vidaLarguraLinha = 2.0f;
    int alturaRect = 10;
    float larguraTotal = 200.0f;

    float larguraVidaAtual = (float)((larguraTotal / infmon.VIDA_MAX)*(infmon.vida));

    Rectangle danoTomado = criaRetangulo(posX, posY, larguraTotal, alturaRect, 0, 0, 1);
    DrawRectangleRec(danoTomado, RED);

    Rectangle vidaAtual = criaRetangulo(posX, posY, larguraVidaAtual, alturaRect, 0, 0, 1);
    DrawRectangleRec(vidaAtual, GREEN);

    Rectangle vidaContainer = criaRetangulo(posX, posY, larguraTotal, alturaRect, 0, 0, 1);
    DrawRectangleLinesEx(vidaContainer, vidaLarguraLinha, BLACK);
}

//TROCAR LOCAL DE CRIACAO DA FUNCAO
void calculaDano(int dano, Infmon *infmon){
    if(infmon->vida - dano <=0){
        infmon->vida = 0;
    } else {
        infmon->vida -= dano;
    }

}

//TROCAR LOCAL DE CRIACAO DA FUNCAO
void criaInterfaceMenuBatalhaAtaques(Rectangle botoes[], Infmon aliado, Infmon *inimigo, float posXInicioTexto, float posYInicioTexto, int *processoAtualBatalha, int *indexInimigo){
    int NUM_BOTOES = 4;

    int isAcao = FALSE;
    double testeTime = 0;
    int mouseCimaDeBotaoN = 0;

    if(inimigo->vida == 0){
        if(*indexInimigo-1 >=0){
            *indexInimigo= *indexInimigo - 1;
        } else {
            printf("ADVERSARIO PERDEU");
        }

    }

    for (int i = 0; i < NUM_BOTOES; i++){
        if(CheckCollisionPointRec(GetMousePosition(), botoes[i])){
            mouseCimaDeBotaoN = i;

            switch(mouseCimaDeBotaoN){
                case 0:
                    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                        printf("ATAQUE %s\n", aliado.ataques[i].nome);
                        calculaDano(aliado.ataques[i].dano, inimigo);
                        testeTime = GetTime() + (double)3;
                    } break;

                case 1:
                    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                        printf("ATAQUE %s\n", aliado.ataques[i].nome);
                        calculaDano(aliado.ataques[i].dano, inimigo);

                    } break;

                case 2:
                    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                        printf("ATAQUE %s\n", aliado.ataques[i].nome);
                        calculaDano(aliado.ataques[i].dano, inimigo);
                    } break;

                case 3:
                    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                        *processoAtualBatalha = PROCESSO_BATALHA_INICIAL;
                    }
                    break;
            }

        }


        //TODO: MENSAGEM SEGUE ESSA ESTRUTURA, DEVE SER IMPLEMENTADO
        if(isAcao && GetTime() < testeTime){
            DrawText("Ocorreu uma acao realizada pelo jogador muito texto para testar e afins e tals", posXInicioTexto, posYInicioTexto, 24, BLACK);
            printf("TEMPO = %lf\n", testeTime);


        } else {
            isAcao = FALSE;
            if(i == NUM_BOTOES - 1){
                criaInterface(&botoes[i], NULL, i);
            } else {
                criaInterface(&botoes[i], aliado.ataques[i].nome, i);
            }

        }
    }

}

void criaInterfaceMenuBatalhaInicial(Rectangle botoes[], int *processoAtualBatalha){
    static const char *labelBotoesBatalha[] = {
        "Atacar",
        "Captura",
        "Trocar",
        "Fugir",
    };
    int NUM_BOTOES = 4;

    int mouseCimaDeBotaoN = 0;

    for (int i = 0; i < NUM_BOTOES; i++){
        if(CheckCollisionPointRec(GetMousePosition(), botoes[i])){
            mouseCimaDeBotaoN = i;

           switch(mouseCimaDeBotaoN){
                case 0:
                    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                        printf("%s\n", labelBotoesBatalha[i]);
                        *processoAtualBatalha = PROCESSO_BATALHA_ATAQUES;
                    }
                    break;

                case 1:
                    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                        printf("%s\n", labelBotoesBatalha[i]);
                    } break;

                case 2:
                    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                        printf("%s\n", labelBotoesBatalha[i]);
                    }

                    break;

                case 3:
                    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                        printf("%s\n", labelBotoesBatalha[i]);
                        //TODO: ADICIONAR VALIDACAO DE FUGA APENAS PARA BATALHA CONTRA INFMONS
                        //TODO: ADICIONAR CHANCE DE FUGA
                        //TODO: ADICIONAR MENSAGENS CASO TENTATIVA DE CERTO/ERRADO
                        *processoAtualBatalha = PROCESSO_BATALHA_TENTAR_FUGA;
                    }
                    break;
            }

        }

        criaInterface(&botoes[i], labelBotoesBatalha[i], i);
    }

}

