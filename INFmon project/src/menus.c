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

//------------------------------------------------------------------------------------

int menuPause(int processoAtual){
    int NUM_BOTOES = 5;
    Color corBotoes[5] = {GREEN, BLUE, BLUE, GREEN, RED};
    Rectangle botoes[NUM_BOTOES];

    static const char *labelBotoes[] = {
        "CONTINUAR",
        "CARREGAR JOGO",
        "SALVAR JOGO",
        "VOLTAR AO MENU",
        "SAIR"
    };

    int posMeioX = LARGURA/2;
    int mouseCimaDeBotaoN = -1;

    processoAtual = PROCESSO_PAUSE;

    while (!WindowShouldClose() && processoAtual == PROCESSO_PAUSE) {

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("PAUSE", posMeioX-(5*25), 20, 70, BLACK);

        for(int i=0; i<NUM_BOTOES; i++){
            //condicionais que permitem navegar o menu por teclas
            if(IsKeyPressed(KEY_C)){
                processoAtual = PROCESSO_INICIA_JOGO;
            }
            else if(IsKeyPressed(KEY_L)){
                processoAtual = PROCESSO_CARREGAR_JOGO;
            }
            else if(IsKeyPressed(KEY_S)){
                processoAtual = PROCESSO_SALVAR_JOGO;
            }
            else if(IsKeyPressed(KEY_B)){
                processoAtual = PROCESSO_MENU_INICIAL;
            }
            else if(IsKeyPressed(KEY_Q)){
                processoAtual = PROCESSO_FECHA_JANELA;
            }
            //condicionais que permitem navegar o menu pelo clique do mouse
            if(CheckCollisionPointRec(GetMousePosition(), botoes[i])){
                mouseCimaDeBotaoN = i;

                switch(mouseCimaDeBotaoN){
                    case 0:
                        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                            processoAtual = PROCESSO_INICIA_JOGO;
                        } break;

                    case 1:
                        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                            processoAtual = PROCESSO_CARREGAR_JOGO;
                        } break;

                    case 2:
                        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                            processoAtual = PROCESSO_SALVAR_JOGO;
                        } break;
                    case 3:
                        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                            processoAtual = PROCESSO_MENU_INICIAL;
                        } break;
                    case 4:
                        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                            processoAtual = PROCESSO_FECHA_JANELA;
                        } break;

                }

            }
            if(i<2){
                botoes[i] = criaBotao(600.0f/4.0f, 150.0f, 400.0f, 100.0f, 0, (float)GAP_ENTRE_BOTOES+5, i, 5.0f, WHITE, corBotoes[mouseCimaDeBotaoN], (i == mouseCimaDeBotaoN));
                DrawText(labelBotoes[i], (int)( botoes[i].x + botoes[i].width/2 - MeasureText(labelBotoes[i], 25)/2), (int) botoes[i].y + botoes[i].height/2 - 30/2  , 30, BLACK);
            }
            else if (i<4){
                botoes[i] = criaBotao(600.0f, 150.0f, 400.0f, 100.0f, 0, (float)GAP_ENTRE_BOTOES+5, (i-2), 5.0f, WHITE, corBotoes[mouseCimaDeBotaoN], (i == mouseCimaDeBotaoN));
                DrawText(labelBotoes[i], (int)( botoes[i].x + botoes[i].width/2 - MeasureText(labelBotoes[i], 25)/2), (int) botoes[i].y + botoes[i].height/2 - 30/2  , 30, BLACK);
            }
            else{
                botoes[i] = criaBotao(600.0f/1.6f, 150.0f, 400.0f, 100.0f, 0, (float)GAP_ENTRE_BOTOES+5, (i-2), 5.0f, WHITE, corBotoes[mouseCimaDeBotaoN], (i == mouseCimaDeBotaoN));
                DrawText(labelBotoes[i], (int)( botoes[i].x + botoes[i].width/2 - MeasureText(labelBotoes[i], 25)/2), (int) botoes[i].y + botoes[i].height/2 - 30/2  , 30, BLACK);
            }

        }

        EndDrawing();
    }



    return processoAtual;
}

//------------------------------------------------------------------------------------

int menuEscolheInfmon(int processoAtual){

    int NUM_INFMONS = 3;

    Color corInfmons[3] = {GREEN, BLUE, RED};
    Rectangle infmons[3];

    static const char *nomeInfmons[] = {
        "Folhinha", //grama
        "Gotinha", //agua
        "Chaminha"  //fogo
    };

    int mouseCimaDeBotaoN = -1;

    static const char texto[] = "Escolha seu INFmon inicial";
    int textoLength = strlen(texto);

    char escolhido = ' ';

    processoAtual = PROCESSO_ESCOLHER_INFMON;

    while(!WindowShouldClose() && processoAtual == PROCESSO_ESCOLHER_INFMON){

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText(texto, LARGURA/2-(textoLength*13), 60, 50, BLACK);

        for (int i = 0; i < NUM_INFMONS; i++){

            if(IsKeyPressed(KEY_T)){
                escolhido = 'T';
                //processoAtual = proxima etapa
            }
            else if(IsKeyPressed(KEY_A)){
                escolhido = 'A';
                //processoAtual = proxima etapa
            }
            else if(IsKeyPressed(KEY_F)){
                escolhido = 'F';
                //processoAtual = proxima etapa
            }

            if(CheckCollisionPointRec(GetMousePosition(), infmons[i])){
                mouseCimaDeBotaoN = i;

                switch(mouseCimaDeBotaoN){
                    case 0:
                        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                            escolhido = 'T';
                            //processoAtual = proxima etapa
                        } break;

                    case 1:
                        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                            escolhido = 'A';
                                //processoAtual = proxima etapa
                        } break;

                    case 2:
                        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                            escolhido = 'F';
                                //processoAtual = proxima etapa
                        } break;

                    }

                }

                if(escolhido != ' '){
                    adicionaINFmon(escolhido, 0);
//                    criaArquivoDeAtaques();
//                    leArquivosDeAtaques();

                    processoAtual = PROCESSO_INICIA_JOGO;
                }


                infmons[i] = criaBotao(LARGURA/2 -150, 150.0f, 100.0f, 100.0f, 0, (float)GAP_ENTRE_BOTOES, i, 5.0f, WHITE, corInfmons[mouseCimaDeBotaoN], (i == mouseCimaDeBotaoN));
                DrawText(nomeInfmons[i], LARGURA/2+50, (int) infmons[i].y + infmons[i].height/2 - 30/2  , 30, BLACK);

            }

        EndDrawing();

    }

    return processoAtual;
}

//------------------------------------------------------------------------------------
int menuFimDeJogo(int processoAtual, int situacao){
    static const char titulo[] ={"Fim de Jogo"};
    static const char *mensagem[] ={
        "INFelizmente voce foi derrotado :(",
        "Parebens voce venceu!"
    };
    static const char *labelBotoes[] = {
        "VOLTAR AO MENU",
        "CARREGAR JOGO",
        "SAIR"
    };
    int NUM_BOTOES = 3;
    Rectangle botoes[NUM_BOTOES];
    Color corBotoes[3] = {GREEN, BLUE, RED};
    int titulo_length = strlen(titulo);
    int mensagem_length = strlen(mensagem[situacao]);
    int mouseCimaDeBotaoN = -1;

    processoAtual = PROCESSO_MENU_FINAL;

    while (!WindowShouldClose() && processoAtual == PROCESSO_MENU_FINAL) {
        BeginDrawing();
        ClearBackground(WHITE);

        DrawText(titulo, LARGURA/2 - (titulo_length/2)*30, 40, 60, BLACK);
        DrawText(mensagem[situacao], LARGURA/2 - (mensagem_length/2)*22, 120, 45, BLACK);

        for (int i = 0; i < NUM_BOTOES; i++){


            if(IsKeyPressed(KEY_B))
                processoAtual = PROCESSO_MENU_INICIAL;
            if(IsKeyPressed(KEY_C))
                processoAtual = PROCESSO_CARREGAR_JOGO;
            if(IsKeyPressed(KEY_Q)){
                processoAtual = PROCESSO_FECHA_JANELA;
            }

            if(CheckCollisionPointRec(GetMousePosition(), botoes[i])){
                mouseCimaDeBotaoN = i;

                switch(mouseCimaDeBotaoN){
                    case 0:
                        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                            processoAtual = PROCESSO_MENU_INICIAL;
                        } break;

                    case 1:
                        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                            processoAtual = PROCESSO_CARREGAR_JOGO;
                        } break;

                    case 2:
                        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                            processoAtual = PROCESSO_FECHA_JANELA;
                        } break;

                }

            }

            botoes[i] = criaBotao(LARGURA/2 - 200, 200, 400, 80, 0, (float)GAP_ENTRE_BOTOES, i, 5.0f, WHITE, corBotoes[mouseCimaDeBotaoN], (i == mouseCimaDeBotaoN));
            DrawText(labelBotoes[i], (int)( botoes[i].x + botoes[i].width/2 - MeasureText(labelBotoes[i], 25)/2), (int) botoes[i].y + botoes[i].height/2 - 30/2  , 30, BLACK);
        }

        EndDrawing();
    }

    return processoAtual;
}
//------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------

int menuBatalha(int *processoInternoAtual, int isBoss){
    int isFecharJanela = FALSE;

    int resultadoBatalha = BATALHA_DERROTA;

    int infmonInimigoAtual = MAX_INFMONS;
    int infmonAliadoAtual = MAX_INFMONS;

//    Infmon bossInfmonUm = criaPokemonInimigoFogo();
//    Infmon bossInfmonDois = criaPokemonAliadoAgua();
//    Infmon bossInfmonTres = criaPokemonInimigoFogo();
//
//    Infmon INFmonsInimigos[3] = {
//        bossInfmonUm, bossInfmonDois, bossInfmonTres
//    };
    Infmon INFmonsInimigos[3] = {};
    //CARREGA DADOS DO BOSS
    printf("AQUI\n");
    if(isBoss == PROCESSO_INTERNO_BATALHA_BOSS){
//        //LE ARQUIVO
//
        Personagem boss;
        boss.nInfmons = 2;
        infmonInimigoAtual = boss.nInfmons - 1;
        Infmon bossInfmonUm = criaPokemonInimigoFogo();
        Infmon bossInfmonDois = criaPokemonAliadoAgua();

//        INFmonsInimigos[0] = bossInfmonUm;
//        INFmonsInimigos[1] = bossInfmonDois;
//        INFmonsInimigos[2] = bossInfmonTres;
        Infmon INFmonsInimigosArquivo[2] = {
            bossInfmonUm, bossInfmonDois
        };
//
//        //VEIO DO ARQUIVO
//
        for(int i = 0; i < 2; i++){
            INFmonsInimigos[i] = INFmonsInimigosArquivo[i];
        }
//
    } else {
        INFmonsInimigos[0] = criaINFmonAleatorio(1/*fase*/);
        infmonInimigoAtual = 0;
//        Infmon infmonSelvagem = criaPokemonInimigoFogo();
//        INFmonsInimigos[infmonInimigoAtual] = infmonSelvagem;
//
    }



    //CARREGA DADOS DO PERSONAGEM ATUAL
    Personagem aliado;
    aliado.nInfmons = 1;
    infmonAliadoAtual = aliado.nInfmons - 1;
    Infmon aliadoInfmonUm = criaPokemonAliadoAgua();
    aliado.infmons[infmonAliadoAtual] = aliadoInfmonUm;


    float bordaInferiorAltura = 250.0f;
    float modalLarguraLinha = 4.0;

    int NUM_BOTOES = 4;

    float posX = 0.0f;

    float posY = (ALTURA - bordaInferiorAltura);


    Rectangle botoes[NUM_BOTOES];

    int processoAtualBatalha = PROCESSO_BATALHA_INICIAL;


    float alturaInfmon = 200.0f;
    float larguraInfmon = alturaInfmon;
    float posYInfmon = posY - alturaInfmon - (modalLarguraLinha);
    float posXInfmon = (modalLarguraLinha);
    float posYInimigo = 0;
    float posXInimigo = LARGURA - larguraInfmon - (modalLarguraLinha);

    while (!WindowShouldClose() && !isFecharJanela && (*processoInternoAtual == PROCESSO_INTERNO_BATALHA_BOSS || *processoInternoAtual == PROCESSO_INTERNO_BATALHA_INFMON)){
        BeginDrawing();
        ClearBackground(RAYWHITE);

        Rectangle retanguloBordaInferior = criaRetangulo(posX, posY, LARGURA, bordaInferiorAltura, 0, 0, 1);
        DrawRectangleRec(retanguloBordaInferior, GRAY);
        DrawRectangleLinesEx(retanguloBordaInferior, modalLarguraLinha, BLACK);


        Rectangle nossoINFmon = criaRetangulo(posXInfmon, posYInfmon, larguraInfmon, alturaInfmon, 0, 0, 1);
        DrawRectangleRec(nossoINFmon, BLUE);
        DrawRectangleLinesEx(nossoINFmon, modalLarguraLinha, BLACK);

        criaInterfaceDeVidaINFmon(TRUE, posXInfmon, larguraInfmon, posYInfmon, aliado.infmons[infmonAliadoAtual]);


        Rectangle delesINFmon = criaRetangulo(posXInimigo, posYInimigo, larguraInfmon, alturaInfmon, 0, 0, 1);

        Color tipo = retornaCorDoTipo(INFmonsInimigos[infmonInimigoAtual].tipo);
        DrawRectangleRec(delesINFmon, tipo);
        DrawRectangleLinesEx(delesINFmon, modalLarguraLinha, BLACK);

        criaInterfaceDeVidaINFmon(FALSE, posXInimigo, larguraInfmon, posYInimigo, INFmonsInimigos[infmonInimigoAtual]);


        switch(processoAtualBatalha){
            case PROCESSO_BATALHA_INICIAL:
                    criaInterfaceMenuBatalhaInicial(botoes, &processoAtualBatalha, isBoss);
                break;
            case PROCESSO_BATALHA_ATAQUES:
                    criaInterfaceMenuBatalhaAtaques(botoes, aliado.infmons[infmonAliadoAtual], &INFmonsInimigos[infmonInimigoAtual], posX, posY, &processoAtualBatalha, &infmonInimigoAtual);
                break;

            case PROCESSO_BATALHA_TENTAR_FUGA:
                    resultadoBatalha = BATALHA_FUGA;
                    *processoInternoAtual = PROCESSO_INTERNO_MAPA;
                break;
        }

        EndDrawing();
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   }

    return resultadoBatalha;
}

//------------------------------------------------------------------------------------


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

    DrawText(infmon.nome, posXNomeInfmon, posYNomeInfmon, 20, BLACK);

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
void calculaDano(Ataque ataque, int nivelAtaque, Infmon *infmonAlvo){
    float danoVantagem = ATAQUE_NORMAL;
    if(infmonAlvo->vida - ataque.dano <= 0.0f){
        infmonAlvo->vida = 0.0f;
    } else {
        danoVantagem = verificaSePossuiVantagem(ataque.tipo, infmonAlvo->tipo);
        float danoTotal = ((float)(ataque.dano + nivelAtaque))*danoVantagem;
        infmonAlvo->vida -= danoTotal;
    }
}

float verificaSePossuiVantagem(char tipoAtacante, char tipoAlvo){
    float danoMultiplicador = ATAQUE_NORMAL;

    switch(tipoAtacante){
        case TIPO_AGUA:
            switch(tipoAlvo){
                case TIPO_FOGO:
                    danoMultiplicador = ATAQUE_EFETIVO;
                    break;

                case TIPO_TERRA:
                    danoMultiplicador = ATAQUE_INEFETIVO;
                    break;
                default:
                    danoMultiplicador = ATAQUE_NORMAL;
            }
            break;

        case TIPO_FOGO:
            switch(tipoAlvo){
                case TIPO_TERRA:
                    danoMultiplicador = ATAQUE_EFETIVO;
                    break;

                case TIPO_AGUA:
                    danoMultiplicador = ATAQUE_INEFETIVO;
                    break;
                default:
                    danoMultiplicador = ATAQUE_NORMAL;
            }
            break;

        case TIPO_TERRA:
                    switch(tipoAlvo){
                case TIPO_AGUA:
                    danoMultiplicador = ATAQUE_EFETIVO;
                    break;

                case TIPO_FOGO:
                    danoMultiplicador = ATAQUE_INEFETIVO;
                    break;
                default:
                    danoMultiplicador = ATAQUE_NORMAL;
            }
            break;
    }

    return danoMultiplicador;
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
            printf("ADVERSARIO PERDEU\n");
        }

    }

    for (int i = 0; i < NUM_BOTOES; i++){
        if(CheckCollisionPointRec(GetMousePosition(), botoes[i])){
            mouseCimaDeBotaoN = i;

            switch(mouseCimaDeBotaoN){
                case 0:
                    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                        printf("ATAQUE %s\n", aliado.ataques[i].nome);
                        calculaDano(aliado.ataques[i], aliado.ataque, inimigo);
                        testeTime = GetTime() + (double)3;
                    } break;

                case 1:
                    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                        printf("ATAQUE %s\n", aliado.ataques[i].nome);
                        calculaDano(aliado.ataques[i], aliado.ataque, inimigo);

                    } break;

                case 2:
                    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                        printf("ATAQUE %s\n", aliado.ataques[i].nome);
                        calculaDano(aliado.ataques[i], aliado.ataque, inimigo);
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

void criaInterfaceMenuBatalhaInicial(Rectangle botoes[], int *processoAtualBatalha, int isBoss){
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
                        if(isBoss){
                            printf("\nACAO INVALIDA\n");
                        } else {
                            printf("%s\n", labelBotoesBatalha[i]);
                        }

                    } break;

                case 2:
                    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                        printf("%s\n", labelBotoesBatalha[i]);
                    }

                    break;

                case 3:
                    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                        if(isBoss){
                            printf("ACAO INVALIDA\n");
                        } else {
                            printf("%s\n", labelBotoesBatalha[i]);
                            //TODO: ADICIONAR CHANCE DE FUGA
                            //TODO: ADICIONAR MENSAGENS CASO TENTATIVA DE CERTO/ERRADO
                            *processoAtualBatalha = PROCESSO_BATALHA_TENTAR_FUGA;
                        }

                    }
                    break;
            }

        }

        criaInterface(&botoes[i], labelBotoesBatalha[i], i);
    }

}

